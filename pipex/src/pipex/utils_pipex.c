/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:48:33 by supanuso          #+#    #+#             */
/*   Updated: 2025/02/27 15:42:49 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"
#include "../../includes/libft.h"

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
	perror(msg);
	free_data(d, 0);
	exit(exitcode);
}

void	redirect_io(int input, int output, t_pipex *d)
{
	if (dup2(input, STDIN_FILENO) == -1)
	{
		exit_error("dup2", 1, d);
	}
	if (dup2(output, STDOUT_FILENO) == -1)
	{
		exit_error("dup2", 1, d);
	}
}

void	close_fds(t_pipex *d)
{
	int	i;

	if (d->in_fd != 1)
		close(d->in_fd);
	if (d->out_fd != -1)
		close(d->out_fd);
	i = 0;
	while (i < d->n_pipes)
	{
		if (d->fd[i][0] != -1)
			close(d->fd[i][0]);
		if (d->fd[i][1] != -1)
			close(d->fd[i][1]);
		i++;
	}
}

// int	wait_for_child(t_pipex *d)
// {
// 	pid_t	wpid;
// 	int		status;
// 	int		exit_code;
// 	int		i;

// 	exit_code = 1;
// 	i = -1;
// 	while (++i < d->n_cmds)
// 	{
// 		wpid = waitpid(d->pid[i], &status, 0);
// 		if (wpid == -1)
// 		{
// 			perror("waitpid");
// 			exit_code = 1;
// 		}
// 		else if (wpid == d->pid[d->n_cmds - 1])
// 		{
// 			if (WIFEXITED(status))
// 				exit_code = WEXITSTATUS(status);
// 		}
// 	}
// 	return (exit_code);
// }
