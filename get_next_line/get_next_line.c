/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:42:01 by supanuso          #+#    #+#             */
/*   Updated: 2024/10/06 20:42:20 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	remain_lst(t_list **list, int pos_nl)
{
	t_list	*last;
	char	*remainder;
	int		i;
	int		remaining_bytes;

	last = ft_lstlast(*list);
	remaining_bytes = last->byte_read - (pos_nl + 1);
	if (remaining_bytes <= 0)
	{
		ft_lstclear(list, free);
		return ;
	}
	remainder = (char *)malloc(remaining_bytes + 1);
	if (!remainder)
	{
		ft_lstclear(list, free);
		return ;
	}
	i = -1;
	while (++i < remaining_bytes)
		remainder[i] = last->content[pos_nl + 1 + i];
	remainder[i] = '\0';
	ft_lstclear(list, free);
	*list = ft_lstnew(remainder, remaining_bytes);
	free(remainder);
}

static char	*extract_line(t_list *list, int pos_nl)
{
	char	*str;
	int		i;
	int		j;
	t_list	*current;

	if (!list)
		return (NULL);
	str = (char *)malloc(ft_lstsize_to_len(list, pos_nl) + 1);
	if (!str)
		return (NULL);
	j = 0;
	current = list;
	while (current->next)
	{
		i = -1;
		while (++i < current->byte_read)
			str[j++] = current->content[i];
		current = current->next;
	}
	i = -1;
	while (++i <= pos_nl)
		str[j++] = current->content[i];
	str[j] = '\0';
	return (str);
}

static int	found_nl(char *str, int byte_read, int remain)
{
	int	i;

	if (!str || byte_read <= 0)
		return (-1);
	i = 0;
	while (i < byte_read)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (byte_read < BUFFER_SIZE && remain != 1)
		return (i);
	return (-2);
}

static int	process_buffer(t_list **list, int fd)
{
	int		byte_read;
	char	*buf;
	t_list	*new;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	byte_read = read(fd, buf, BUFFER_SIZE);
	if (byte_read <= 0)
	{
		free(buf);
		if (byte_read == 0 && ft_lstlast(*list))
			return (ft_lstlast(*list)->byte_read - 1);
		return (-1);
	}
	buf[byte_read] = '\0';
	new = ft_lstnew(buf, byte_read);
	free(buf);
	if (!new)
		return (-1);
	ft_lstadd_back(list, new);
	return (found_nl(new->content, new->byte_read, 0));
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	int				pos_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pos_nl = -2;
	if (list)
		pos_nl = found_nl(ft_lstlast(list)->content,
				ft_lstlast(list)->byte_read, 1);
	if (pos_nl == -1)
		return (NULL);
	while (pos_nl == -2)
	{
		pos_nl = process_buffer(&list, fd);
		if (!list || pos_nl == -1)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
	}
	next_line = extract_line(list, pos_nl);
	remain_lst(&list, pos_nl);
	return (next_line);
}
