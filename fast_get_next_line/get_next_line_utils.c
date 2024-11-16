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
	int		i;

	if (!(*remain))
	{
		*remain =  (char **)malloc(SIZE * sizeof(char *));
		if (!(*remain))
			return (NULL);
		i = -1;
		while(++i < SIZE)
			(*remain)[i] = NULL;
	}
	data = (t_gnl *)malloc(sizeof(t_gnl));
	lst = (char **)malloc(SIZE * sizeof(char *));
	if (!data || !lst)
	{
		free_mode(*remain, data, 'a');
		return (NULL);
	}
	data->index = 0;
	data->pos_nl = 0;
	data->len = 0;
	data->lst = lst;
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
		return (free_mode((*remain), (*data), 'a'), 1);
	ft_memcpy(str, (*remain)[fd], len);
	str[len] = '\0';
	if (found)
	{
		*line = str;
		if (new_remain(remain, data, len, fd))
			return (0);
		free_mode((*remain), (*data), 'd');
		return (1);
	}
	(*data)->len += len;
	(*data)->lst[((*data)->index)++] = str;
	(*data)->pos_nl = len;
	free(tmp);
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
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
		(*len)++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	uint8_t*		d;
	const uint8_t*	s;

	d = (uint8_t*)dst;
	s = (const uint8_t*)src;
	while (n >= 8)
	{
		*(uint64_t*)d = *(const uint64_t*)s;
		d += 8;
		s += 8;
		n -= 8;
	}
	while (n)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}