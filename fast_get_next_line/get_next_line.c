/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:14:48 by supanuso          #+#    #+#             */
/*   Updated: 2024/11/15 18:40:06 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_gnl		*data;
	static char	**remain;
	char		*line;
	int			found;
	
	line = NULL;
	data = new_data(&remain, fd);
	if (!data)
		return (NULL);
	if (extract_remain(&data, &remain, fd, &line))
		return (line);
	found = read_line(&data, &remain, fd);
	while (!found)
	{
		if (found == -1)
			return (NULL)
		found = read_line(&data, &remain, fd);
	}
	combine_line(&data);
	if (read)
	return (line);
}

int	read_line(t_gnl **data, char ***remain, int fd)
{
	char	*buf;
	int		write_index;
	int		byte_read;
	int		pos_nl;


	buf = (char *)malloc(SIZE);
	if (!buf)
	{
		free_mode((*remain), (**data), 'a');
		return (-1);
	}
	write_index = 0;
	while (write_index + BUFFER_SIZE + 1 < SIZE || byte_read == 0)
	{
		byte_read = read(fd, buf + write_index, BUFFER_SIZE);
		if (byte_read == -1 || (byte_read == 0 && !(*data)->lst[0]))
		{
			free (buf);
			if (byte_read == -1)
				free_mode((*remain), (*data), 'a');
			else
				free_mode((*remain), (*data), 'd');
			return(-1);
		}
		write_index += byte_read;
	}
	(*data)->lst[((*data)->index)++] = ft_realloc(buf, SIZE, write_index + 1);
	(*data)->len += write_index;
	if (byte_read == 0)
		return (1)
	return (ft_strlen_chr((*data)->lst[((*data)->index) - 1]), '\n', (*data)->pos_nl);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return NULL;
	}
	if (ptr == NULL) 
		return malloc(new_size);
	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		return NULL;
	}
	if (new_size > old_size)
		memcpy(new_ptr, ptr, old_size);
	else
		memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return new_ptr;
}