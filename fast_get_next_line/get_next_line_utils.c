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
	data = (t_gnl *)malloc(sizeof(t_gnl));
	lst = (char **)malloc(SIZE * sizeof(char *));
	if (!data || !lst)
	{
		free_mode(*remain, data, a);
		return (NULL);
	}
	data->index = 0;
	data->len = 0;
	return (data);
}

int	extract_remain(t_gnl **data, char ***remain, int fd, char **line)
{
	char	*tmp;
	char	*str;
	int		len;
	int		found;
	int		remain_len;
	
	remain_len = 0;
	len = 0;
	tmp = (*remain)[fd];
	if (!tmp)
		return (0);
	found = ft_strlen_chr(tmp, '\n', &len);
	str = (char *)malloc(len + 1);
	if (!str)
	{
		free_mode((*remain), (*data), 'a');
		return (1);
	}
	ft_memcpy(line, str, len);
	str[len] = '\0';
	if (found)
	{
		*line = str;
		new_remain(remain, tmp + len, fd);
		free_mode((*remain), (*data), 'd');
		return (1);
	}
	(*data)->len += len;
	(*data)->lst[((*data)->index)++] = str;
	return (0);
}

void	free_mode(char **remain , t_gnl *data, char mode)
{
	int	i;

	i = -1;
	if (remain && (mode == 'a' || mode == 'r'))
	{
		while (++i < SIZE)
			if (remain[i])
				free(remain[i]);
		free(remain);
	}
	if (mode == 'a' || mode == 'd')
	{
		if (data->line )
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
}

int	ft_strlen_chr(const char *str , char c, int *len)
{
	if (!str)
		return (0);
	*len = 0;
	while (str[*len])
	{
		if (c != 0 && str[*len] == c)
			return (1);
		(*len)++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (!src && !dst)
		return (dst);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	while (n-- > 0)
		*tmp_dst++ = *tmp_src++;
	return (dst);
}