/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:42:04 by supanuso          #+#    #+#             */
/*   Updated: 2024/10/06 13:45:56 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content, int byte_read)
{
	t_list	*new;
	char	*str;
	int		i;

	if (!content || byte_read < 0)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	str = (char *)malloc(byte_read + 1);
	if (!str || !new)
	{
		free(new);
		return (NULL);
	}
	i = 0;
	while (i < byte_read)
	{
		str[i] = content[i];
		i++;
	}
	str[byte_read] = '\0';
	new->content = str;
	new->byte_read = byte_read;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

int	ft_lstsize_to_len(t_list *lst, int pos_nl)
{
	t_list	*tmp;
	int		len;

	tmp = lst;
	len = 0;
	while (tmp->next)
	{
		len += tmp->byte_read;
		tmp = tmp->next;
	}
	if (tmp->content)
		len += pos_nl + 1;
	return (len);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->content && del)
			(*del)((*lst)->content);
		free (*lst);
		*lst = tmp;
	}
}
