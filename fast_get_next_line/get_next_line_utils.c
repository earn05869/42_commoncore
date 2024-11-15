/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:14:48 by supanuso          #+#    #+#             */
/*   Updated: 2024/11/15 18:40:30 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*new_data(char ***remain, int fd)
{
	t_gnl	*data;
	char	**lst;
	char	*line;

	if (!(*remain))
	{
		*remain =  (char **)malloc(SIZE * sizeof(char *));
		if (!(*remain))
			return (NULL);
	}	
	line = NULL;
	data = (t_gnl *)malloc(sizeof(t_gnl));
	lst = (char **)malloc(SIZE * sizeof(char *));
	if (!data || !lst)
	{
		free_all(*remain, data);
		return (NULL);
	}
	data->pos_end = -1;
	data->len = 0;
	return (data);
}
int	extract_remain(t_gnl **data, char ***remain, int fd)
{
	int		len;
	char	*str;
	int		i;
	
	str = (*remain)[fd]; 
	if (!str)
		return (0);
	len = ft_strlen(str);
	while (str[i] && str[i] != '\n')
	
	
}

void	free_all(char **remain , t_gnl *data)
{
	int	i;

	i = -1;
	if (remain)
	{
		while (++i < SIZE)
			if (remain[i])
				free(remain[i]);
		free(remain);
	}
	if (data->line)
		free(data->line);
	i = -1;
	if (data->lst)
	{
		while (++i < SIZE)
			if (data->lst[i])
				free(data->lst[i]);
		free(data->lst);
	}
	free (data);
}

int ft_strlen(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}