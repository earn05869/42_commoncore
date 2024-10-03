/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:42:01 by supanuso          #+#    #+#             */
/*   Updated: 2024/10/04 01:45:45 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	remain_lst(t_list **list, int pos_nl)
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
		return ;
	i = 0;
	while (i < remaining_bytes)
	{
		remainder[i] = last->content[pos_nl + 1 + i];
		i++;
	}
	remainder[i] = '\0';
	ft_lstclear(list, free);
	*list = ft_lstnew(remainder, remaining_bytes);
	free(remainder);
}

char	*get_line(t_list *list, int pos_nl)
{
	char	*str;
	int		i;
	int		j;
	int		len;
	t_list	*current;

	if (!list)
		return (NULL);
	j = 0;
	current = list;
	len = ((ft_lstsize(list) * BUFFER_SIZE) + pos_nl + 1);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (current)
	{
		i = 0;
		while (i < current->byte_read && (current->next || i <= pos_nl))
			str[j++] = current->content[i++];
		current = current->next;
	}
	str[j] = '\0';
	return (str);
}

int	found_nl(char *str, int byte_read)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (i < byte_read)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int	create_list(t_list **list, int fd)
{
	int		byte_read;
	char	*buf;
	int		pos_nl;
	t_list	*new;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	byte_read = read(fd, buf, BUFFER_SIZE);
	if (byte_read <= 0)
	{
		free(buf);
		return (-1);
	}
	buf[byte_read] = '\0';
	new = ft_lstnew(buf, byte_read);
	free(buf);
	if (!new)
		return (-1);
	ft_lstadd_back(list, new);
	pos_nl = found_nl(new->content, new->byte_read);
	return (pos_nl);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	int				pos_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pos_nl = -1;
	if (list)
		pos_nl = found_nl(ft_lstlast(list)->content, ft_lstlast(list)->byte_read);
	while (pos_nl == -1)
	{
		pos_nl = create_list(&list, fd);
		if (!list || !list->content)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
	}
	next_line = get_line(list, pos_nl);
	remain_lst(&list, pos_nl);
	return (next_line);
}
