/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:17:24 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/09 00:52:01 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	allocate_pipe_memory(t_pipex *d)
{
	int	i;

	d->fd = malloc(sizeof(int *) * d->n_pipes);
	if (!d->fd)
		exit_error("malloc", 1, d);
	i = 0;
	while (i < d->n_pipes)
		d->fd[i++] = NULL;
	i = 0;
	while (i < d->n_pipes)
	{
		d->fd[i] = malloc(sizeof(int) * 2);
		if (!d->fd[i])
		{
			while (i-- > 0)
				free(d->fd[i]);
			free(d->fd);
			exit_error("malloc", 1, d);
		}
		d->fd[i][0] = -1;
		d->fd[i][1] = -1;
		i++;
	}
}

static void	create_pipes(t_pipex *d)
{
	int	i;

	i = 0;
	while (i < d->n_pipes)
	{
		if (pipe(d->fd[i]) < 0)
		{
			while (i-- > 0)
				free(d->fd[i]);
			free(d->fd);
			exit_error("pipe", 1, d);
		}
		i++;
	}
}

static void	safe_init(t_pipex *d)
{
	d->in_fd = -1;
	d->out_fd = -1;
	d->fd = NULL;
	d->cmd = NULL;
	d->cmd_path = NULL;
	d->pid = NULL;
	allocate_pipe_memory(d);
	create_pipes(d);
}

static void	get_fd(t_pipex *d, int ac, char **av, int heredoc)
{
	int	stdin_fd;
	int	tmp_fd;

	if (heredoc == 1)
	{
		tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		stdin_fd = dup(STDIN_FILENO);
		get_heredoc(d, av, stdin_fd, tmp_fd);
		d->in_fd = open(".heredoc.tmp", O_RDONLY);
		if (d->in_fd == -1)
			exit_error("heredoc", 1, d);
	}
	else
	{
		d->in_fd = open(av[1], O_RDONLY);
		if (d->in_fd == -1)
			perror (av[1]);
	}
	if (heredoc == 1)
		d->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		d->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->out_fd == -1)
		perror(av[ac - 1]);
}

t_pipex	init_data(int ac, int heredoc, char **av, char **envp)
{
	t_pipex	d;

	d.n_pipes = ac - 4 - heredoc;
	d.n_cmds = ac - 3 - heredoc;
	d.envp = envp;
	safe_init(&d);
	d.pid = (pid_t *)malloc(sizeof(pid_t) * d.n_cmds);
	if (!d.pid)
		exit_error("malloc", 1, &d);
	get_fd(&d, ac, av, heredoc);
	return (d);
}
