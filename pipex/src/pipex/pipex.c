/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:37:07 by supanuso          #+#    #+#             */
/*   Updated: 2025/02/27 17:50:56 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/pipex.h"

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
	if (i == 0)
	{
		if (d->in_fd != -1)
			redirect_io(d->in_fd, d->fd[0][1], d);
	}
	else if (i == d->n_cmds - 1)
	{
		if (d->out_fd != -1)
			redirect_io(d->fd[i - 1][0], d->out_fd, d);
	}
	else
		redirect_io(d->fd[i - 1][0], d->fd[i][1], d);
	close_fds(d);
	if (d->cmd == NULL || d->cmd_path == NULL)
		exit_error("Incorrect or unexisted command", 1, d);
	if (execve(d->cmd_path, d->cmd, d->envp) == -1)
		exit_error(d->cmd[0], 1, d);
}

static int	parent(t_pipex *d)
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	close_fds(d);
	exit_code = 1;
	while (1)
	{
		wpid = wait(&status);
		if (wpid <= 0)
			break ;
		if (wpid == d->pid[d->n_cmds - 1])
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
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
	t_pipex	d;

	d = init_data(ac, heredoc, av, env);
	i = 0;
	while (i < d.n_cmds)
	{
		d.cmd = ft_split(av[i + 2 + heredoc], ' ');
		if (!d.cmd)
			exit_error("malloc", 0, &d);
		d.cmd_path = get_cmd_path(d.cmd[0], d.envp);
		if (!d.cmd_path)
			exit_error("cmd", 0, &d);
		d.pid[i] = fork();
		if (d.pid[i] == -1)
			exit_error("fork", 1, &d);
		else if (d.pid[i] == 0)
			child(&d, i);
		free_args_and_path(d.cmd, d.cmd_path);
		i++;
	}
	exit_code = parent(&d);
	return (exit_code);
}

int	main(int ac, char **av, char **envp)
{
	int	exitcode;

	if (ac < 5)
	{
		if (ac >= 2 && !ft_strncmp("here_doc", av[1], 9))
			exit_error("Usage: ./pipex here_doc LIMITER cmd1 ... cmdn file2.",
				1, NULL);
		exit_error("Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2.",
			1, NULL);
	}
	else if (ac < 6 && !ft_strncmp("here_doc", av[1], 9))
		exit_error("Usage: ./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.",
			1, NULL);
	if (!envp || envp[0][0] == '\0')
		exit_error("Unexpected error.", 1, NULL);
	if (strcmp(av[1], "here_doc") == 0)
	{
		exitcode = pipex(ac, av, envp, 1);
		unlink(".heredoc.tmp");
	}
	else
		exitcode = pipex(ac, av, envp, 0);
	return (exitcode);
}
