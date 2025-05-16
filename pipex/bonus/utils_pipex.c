/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidchind <jidchind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:48:33 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/13 14:57:49 by jidchind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_data(t_pipex *d, int end)
{
	int	i;

	if (!d)
		return ;
	if (d->fd)
	{
		i = -1;
		while (++i < d->n_pipes)
			if (d->fd[i])
				free(d->fd[i]);
		free(d->fd);
	}
	if (d->pid)
		free(d->pid);
	if (end)
		return ;
	if (d->cmd)
	{
		i = 0;
		while (d->cmd[i])
			free(d->cmd[i++]);
		free(d->cmd);
	}
	if (d->cmd_path)
		free(d->cmd_path);
}

void	exit_error(char *msg, int exitcode, t_pipex *d)
{
	ft_putstr_fd("pipex: ", 2);
	perror(msg);
	free_data(d, 0);
	exit(exitcode);
}

void	redirect_io(int input, int output, t_pipex *d)
{
	if (input != -1)
		if (dup2(input, STDIN_FILENO) == -1)
			exit_error("dup2", 1, d);
	if (output != -1)
		if (dup2(output, STDOUT_FILENO) == -1)
			exit_error("dup2", 1, d);
}

void	close_fds(t_pipex *d)
{
	int	i;

	i = 0;
	while (i < d->n_cmds - 1)
	{
		if (d->fd[i][0] >= 0)
			close(d->fd[i][0]);
		if (d->fd[i][1] >= 0)
			close(d->fd[i][1]);
		i++;
	}
	if (d->in_fd >= 0)
		close(d->in_fd);
	if (d->out_fd >= 0)
		close(d->out_fd);
}

int	log_msg(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}
