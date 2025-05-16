/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidchind <jidchind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:37:07 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/13 15:05:22 by jidchind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_heredoc(t_pipex *d, char **av, int stdin_fd, int tmp_fd)
{
	char	*line;
	char	*nl_ptr;

	if (tmp_fd == -1 || stdin_fd == -1)
		exit_error("heredoc", 1, d);
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		line = get_next_line(stdin_fd);
		if (!line)
			break ;
		nl_ptr = ft_strchr(line, '\n');
		*nl_ptr = '\0';
		if (ft_strlen(line) == ft_strlen(av[2])
			&& !ft_strncmp(line, av[2], ft_strlen(av[2])))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, tmp_fd);
		ft_putstr_fd("\n", tmp_fd);
		free(line);
	}
	close(stdin_fd);
	close(tmp_fd);
}

static void	child(t_pipex *d, int i)
{
	if (i == 0 && d->in_fd != -1)
		redirect_io(d->in_fd, d->fd[0][1], d);
	else if (i == d->n_cmds - 1 && d->out_fd != -1)
		redirect_io(d->fd[i - 1][0], d->out_fd, d);
	else
		redirect_io(d->fd[i - 1][0], d->fd[i][1], d);
	close_fds(d);
	if (d->cmd == NULL || d->cmd_path == NULL)
	{
		if (unset_path(d))
			return ;
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(d->cmd[0], 2);
		free_data(d, 0);
		if (i == d->n_cmds - 1)
			exit(127);
		exit(0);
	}
	if (execve(d->cmd_path, d->cmd, d->envp) == -1)
		exit_error(d->cmd[i], 0, d);
}

static int	parent(t_pipex *d, pid_t last_pid)
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	exit_code = 1;
	close_fds(d);
	wpid = wait(&status);
	while (wpid > 0)
	{
		if (wpid == last_pid && WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
		wpid = wait(&status);
	}
	if (d->out_fd == -1)
		exit_code = 1;
	free_data(d, 1);
	return (exit_code);
}

static int	pipex(int ac, char **av, char **env, int heredoc)
{
	int		i;
	int		exit_code;
	pid_t	last_pid;
	t_pipex	d;

	d = init_data(ac, heredoc, av, env);
	i = -1;
	while (++i < d.n_cmds)
	{
		if ((d.in_fd == -1 && i == 0) || (d.out_fd == -1 && i == d.n_cmds - 1))
			continue ;
		d.cmd = ft_split(av[i + 2 + heredoc], ' ');
		if (!d.cmd)
			exit_error("malloc", 1, &d);
		d.cmd_path = get_cmd_path(d.cmd[0], d.envp);
		d.pid[i] = fork();
		if (d.pid[i] == -1)
			exit_error("fork", 1, &d);
		else if (d.pid[i] == 0)
			child(&d, i);
		last_pid = d.pid[i];
		free_args_and_path(d.cmd, d.cmd_path);
	}
	exit_code = parent(&d, last_pid);
	return (exit_code);
}

int	main(int ac, char **av, char **envp)
{
	int	exitcode;

	if (ac < 5)
	{
		if (ac >= 2 && !ft_strncmp("here_doc", av[1], 9))
			return (log_msg
				("Usage: ./pipex here_doc LIMITER cmd1 ... cmdn file2."));
		return (log_msg("Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2."));
	}
	else if (ac < 6 && !ft_strncmp("here_doc", av[1], 9))
		return (log_msg
			("Usage: ./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2."));
	if (!envp || envp[0][0] == '\0')
		return (log_msg("Unexpected error."));
	if (strcmp(av[1], "here_doc") == 0)
	{
		exitcode = pipex(ac, av, envp, 1);
		unlink(".heredoc.tmp");
	}
	else
		exitcode = pipex(ac, av, envp, 0);
	return (exitcode);
}
