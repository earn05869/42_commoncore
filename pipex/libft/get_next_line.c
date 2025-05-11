/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:42:01 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/07 16:20:09 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	r_lst(t_list **list, int nlp)
{
	t_list	*last;
	char	*rder;
	int		i;
	int		ring_bytes;

	last = my_lstlast(*list);
	ring_bytes = last->bread - (nlp + 1);
	if (ring_bytes <= 0)
	{
		my_lstclear(list, free);
		return ;
	}
	rder = (char *)malloc(ring_bytes + 1);
	if (!rder)
	{
		my_lstclear(list, free);
		return ;
	}
	i = -1;
	while (++i < ring_bytes)
		rder[i] = last->content[nlp + 1 + i];
	rder[i] = '\0';
	my_lstclear(list, free);
	*list = my_lstnew(rder, ring_bytes);
	free(rder);
}

static char	*extract_line(t_list *list, int nlp)
{
	char	*str;
	int		i;
	int		j;
	t_list	*current;

	if (!list)
		return (NULL);
	str = (char *)malloc(my_lstsize_to_len(list, nlp) + 1);
	if (!str)
		return (NULL);
	j = 0;
	current = list;
	while (current->next)
	{
		i = -1;
		while (++i < current->bread)
			str[j++] = current->content[i];
		current = current->next;
	}
	i = -1;
	while (++i <= nlp)
		str[j++] = current->content[i];
	str[j] = '\0';
	return (str);
}

static int	found_nl(char *str, int bread, int r)
{
	int	i;

	if (!str || bread <= 0)
		return (-1);
	i = 0;
	while (i < bread)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (bread < BUFFER_SIZE && r != 1)
		return (i);
	return (-2);
}

static int	process_buffer(t_list **list, int fd)
{
	int		bread;
	char	*buf;
	t_list	*new;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bread = read(fd, buf, BUFFER_SIZE);
	if (bread <= 0)
	{
		free(buf);
		if (bread == 0 && my_lstlast(*list))
			return (my_lstlast(*list)->bread - 1);
		return (-1);
	}
	buf[bread] = '\0';
	new = my_lstnew(buf, bread);
	free(buf);
	if (!new)
		return (-1);
	my_lstadd_back(list, new);
	return (found_nl(new->content, new->bread, 0));
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	int				nlp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nlp = -2;
	if (list)
		nlp = found_nl(my_lstlast(list)->content,
				my_lstlast(list)->bread, 1);
	if (nlp == -1)
		return (NULL);
	while (nlp == -2)
	{
		nlp = process_buffer(&list, fd);
		if (!list || nlp == -1)
		{
			my_lstclear(&list, free);
			return (NULL);
		}
	}
	next_line = extract_line(list, nlp);
	r_lst(&list, nlp);
	return (next_line);
}
