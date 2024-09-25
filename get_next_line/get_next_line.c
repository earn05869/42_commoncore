/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:42:01 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/26 01:46:44 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	remain_lst(t_list **list, int pos_nl)
{
	t_list	*last;
	t_list	*new_list;
	char	*remainder;
	int		i;
	int		j;

	last = ft_lstlast(*list);
	if (!last)
		return ;
	remainder = malloc(BUFFER_SIZE - pos_nl + 1);
	if (!remainder)
		return ;
	i = pos_nl + 1;
	j = 0;
	while (last->content[i])
		remainder[j++] = last->content[i++];
	remainder[j] = '\0';
	free(last->content);
	last->content = remainder;
}

char	*get_line(t_list *list, int pos_nl)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	str = (char *)malloc(((ft_lstsize(list) - 1) * BUFFER_SIZE) + pos_nl + 1);
	if (!str)
		return (NULL);
	while (list)
	{
		i = 0;
		while (list->content[i] && list->content[i] != '\n')
		{
			str[j++] = list->content[i++];
		}
		if (list->content[i] == '\n')
		{
			str[j++] = '\n';
			str[j] = '\0';
			return (str);
		}
		list = list->next;
	}
	str[j] = '\0';
	return (str);
}

int	found_nl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int	create_list(t_list **list, int fd)
{
	int		byte_read;
	char	*buf;
	t_list	*new;
	int		pos_nl;

	pos_nl = 0;
	while (pos_nl == 0)
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (-1);
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read <= 0)
		{
			free(buf);
			return (byte_read);
		}
		buf[byte_read] = '\0';
		pos_nl = found_nl(buf);
		new = ft_lstnew(buf);
		ft_lstadd_back(list, new);
	}
	return (pos_nl);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;
	int				pos_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pos_nl = create_list(&list, fd);
	if (pos_nl == -1 || !list)
		return (NULL);
	next_line = get_line(list, pos_nl);
	remain_lst(&list, pos_nl);
	return (next_line);
}
