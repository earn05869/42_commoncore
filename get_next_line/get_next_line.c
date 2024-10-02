/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:42:01 by supanuso          #+#    #+#             */
/*   Updated: 2024/10/02 17:43:05 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	remain_lst(t_list **list, int pos_nl)
{
	t_list	*last;
	char	*remainder;
	int		i;
	int		j;

	last = ft_lstlast(*list);
	i = pos_nl + 1;
	j = 0;
	while (last->content[i + j])
		j++;
	if (!j || i == BUFFER_SIZE)
	{
		ft_lstclear(list, free);
		return ;
	}
	remainder = (char *)malloc(j + 1);
	if (!remainder)
		return ;
	j = 0;
	while (last->content[i])
		remainder[j++] = last->content[i++];
	remainder[j] = '\0';
	ft_lstclear(list, free);
	*list = ft_lstnew(remainder);
	free(remainder);
}

char	*get_line(t_list *list, int pos_nl)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	j = 0;
	len = (ft_lstsize(list) - 1) * BUFFER_SIZE + pos_nl + 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (list)
	{
		i = 0;
		while (list->content[i] && j < len)
		{
			str[j++] = list->content[i++];
		}
		if (j >= len || !list->next)
			break ;
		list = list->next;
	}
	str[j] = '\0';
	return (str);
}

int	found_nl(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n' || buf[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int	create_list(t_list **list, int fd)
{
	int		byte_read;
	char	buf[BUFFER_SIZE + 1];
	int		pos_nl;
	t_list	*new;

	while (1)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read <= 0)
			return (-1);
		buf[byte_read] = '\0';
		new = ft_lstnew(buf);
		if (!new)
			return (-1);
		ft_lstadd_back(list, new);
		pos_nl = found_nl(buf);
		if (pos_nl != -1)
			return (pos_nl);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	int				pos_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (list)
	{
		pos_nl = found_nl(ft_lstlast(list)->content);
		if (pos_nl != -1)
		{
			next_line = get_line(list, pos_nl);
			remain_lst(&list, pos_nl);
			return (next_line);
		}
	}
	pos_nl = create_list(&list, fd);
	if (pos_nl <= -1)
	{
		ft_lstclear(&list, free);
		return (NULL);
	}
	next_line = get_line(list, pos_nl);
	remain_lst(&list, pos_nl);
	return (next_line);
}
