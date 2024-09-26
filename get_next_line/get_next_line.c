/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:42:01 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/26 15:57:34 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	remain_lst(t_list **list, int pos_nl)
{
	t_list	*last;
	char	*remainder;
	int		i;
	int		j;

	i = pos_nl + 1;\
	j = 0;
	last = ft_lstlast(*list);
	while (last->content[j])
		j++;
	remainder = (char *)malloc((j - i + 1) * sizeof(char));
	if (!remainder)
		return ;
	j = 0;
	while (last->content[i])
		remainder[j++] = last->content[i++];
	remainder[j] = '\0';
	ft_lstclear(list, free);
	*list = ft_lstnew(remainder);
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
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n' || buf[i + 1] == '\0')
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
		ft_lstadd_back(list, ft_lstnew(buf));
		printf("lst :%s\n", (*list)->content);
		free(buf);
	}
	return (pos_nl);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	int				pos_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pos_nl = create_list(&list, fd);
	if (pos_nl == -1 || !list)
	{
		ft_lstclear(&list, free);
		return (NULL);
	}
	next_line = get_line(list, pos_nl);
	printf("%s", next_line);
	exit(0);
	remain_lst(&list, pos_nl);
	return (next_line);
}
