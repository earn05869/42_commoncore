/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:59:39 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/11 21:00:32 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*test_path(char *path, char *cmd, int *i)
{
	char	*current_path;
	char	*full_path;
	int		j;

	j = 0;
	while (path[*i + j] && path[*i + j] != ':')
		j++;
	current_path = malloc(j + 1);
	if (!current_path)
		return (NULL);
	ft_strlcpy(current_path, path + *i, j + 1);
	full_path = ft_strjoin(current_path, "/");
	free(current_path);
	if (!full_path)
		return (NULL);
	current_path = ft_strjoin(full_path, cmd);
	free(full_path);
	if (!current_path)
		return (NULL);
	if (access(current_path, X_OK) == 0)
		return (current_path);
	free(current_path);
	*i += j + (path[*i] == ':');
	return (NULL);
}

int	unset_path(t_pipex *d)
{
	char	*cmd;

	cmd = d->cmd[0];
	if (cmd && (cmd[0] == '/'
			|| (cmd[0] == '.' && cmd[1] == '/')))
	{
		if (execve(cmd, d->cmd, d->envp) == -1)
			exit_error(cmd, 2, d);
		return (1);
	}
	return (0);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path;
	char	*cmd_path;
	int		i;

	i = -1;
	if (!cmd)
		return (NULL);
	path = NULL;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
	}
	if (!envp[i])
		return (NULL);
	path = envp[i] + 5;
	i = 0;
	while (path[i])
	{
		cmd_path = test_path(path, cmd, &i);
		if (cmd_path)
			return (cmd_path);
	}
	return (NULL);
}

void	free_args_and_path(char **args, char *path)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			if (args[i])
				free(args[i++]);
		}
		free(args);
	}
	if (path)
		free(path);
}
