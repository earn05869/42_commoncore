/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:37:30 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/09 02:04:04 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		n_pipes;
	int		n_cmds;
	int		in_fd;
	int		out_fd;
	int		**fd;
	int		**err_fd;
	char	**envp;
	char	**cmd;
	char	*cmd_path;
	pid_t	*pid;
}	t_pipex;

void	close_fds(t_pipex *d);
int		log_msg(char *str);
void	free_data(t_pipex *d, int end);
void	exit_error(char *msg, int exitcode, t_pipex *d);
void	get_heredoc(t_pipex *d, char **av, int stdin_fd, int tmp_fd);
void	redirect_io(int input, int output, t_pipex *d);
void	free_args_and_path(char **args, char *path);
int		unset_path(t_pipex *d);
int		msg(char *str1, char *str2, char *str3, int erno);
char	*get_cmd_path(char *cmd, char **envp);
t_pipex	init_data(int ac, int heredoc, char **av, char **envp);

#endif