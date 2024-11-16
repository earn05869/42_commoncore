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
	int			current_pos;
	
	line = NULL;
	data = new_data(&remain, fd);
	if (!data || extract_remain(&data, &remain, fd, &line))
		return (line);
	found = 0;
	while (!found)
	{
		found = read_line(&data, &remain, fd);
		if (found == -1)
			return (NULL);
	}
	current_pos = combine_line(&remain, &data, &line);
	if (current_pos == -1)
		return (NULL);
	if (current_pos >= 0)
	{
		remain[fd] = new_remain(&remain, &data, current_pos , fd);
		if (!remain[fd])
		{
			free(line);
			free_mode(remain, data, 'a');
			return (NULL);
		}
	}
	return (line);
}

int	read_line(t_gnl **data, char ***remain, int fd)
{
	char	*buf;
	int		write_index;
	int		byte_read;

	buf = (char *)malloc(SIZE << 2);
	if (!buf)
		return (free_mode((*remain), (**data), 'a'), -1);
	write_index = 0;
	byte_read = 1;
	while (write_index + BUFFER_SIZE + 1 < (SIZE << 2) || byte_read == 0)
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
	buf[write_index] = '\0';
	(*data)->lst[((*data)->index)] = ft_realloc(buf, SIZE << 2 , write_index + 1);
	if (!(*data)->lst[((*data)->index)++])
		return (free_mode((*remain), (*data), 'a'), -1);
	(*data)->len += write_index;
	if (byte_read == 0)
		return (1)
	return (ft_strlen_chr((*data)->lst[((*data)->index) - 1], '\n', (*data)->pos_nl));
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

int	combine_line(char ***remain, t_gnl **data, char **line, int fd)
{
	int	i;
	int	j;
	int	len;
	char	*str;

	i = 0;
	len = 0;
	str = (char *)malloc((*data)->pos_nl + 1);
	if (!str)
		return (free_mode(remain, data, 'a'), -1);
	while (i <= (*data)->index && len < (*data)->posnl)
	{
		j = 0;
		while ((*data)->lst[i][j] && len < (*data)->posnl)
			str[len++] = (*data)->lst[i][j++];
		i++;
	}
	str[len] = '\0';
	*line = str;
	if (i < (*data)->index || (*data)->lst[i][++j])
	{
		(*data)->index = i;
		return (j);
	}
	return (-2);
}

char	*new_remain(char ***remain, t_gnl **data, int start, int fd)
{
	char	*new;
	int		len;
	char	*word;
	
	len = 0;
	if ((*remain)[fd] && !ft_strlen_chr(((*remain)[fd]) + start , '\0', &len))
		len = (*data)->len - (*data)->pos_nl;
	new = (char *)malloc(len + 1);
	if (!new)
		return (free_mode((*remain), (*data), 'a'), NULL);
	if ((*remain)[fd])
	{
		ft_memcpy(new, (*remain)[fd] + start, len);
		free((*remain)[fd]);
	}
	else
	{
		len = 0;
		while ((*data)->lst[(*data)->index])
		{
			(*data)->len = 0;
			word = (*data)->lst[(*data)->index++];
			ft_strlen_chr(word + start , '\0', &((*data)->len));
			ft_memcpy(new + len, word + start, (*data)->len);
			len += (*data)->len;
			start = 0;
		}
	}
	new[len] = '\0';
	return (new);
}