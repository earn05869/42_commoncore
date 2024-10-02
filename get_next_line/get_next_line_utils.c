/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:42:04 by supanuso          #+#    #+#             */
/*   Updated: 2024/10/02 14:49:44 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new;
	char	*str;
	int		len;

	len = 0;
	while (content[len])
		len++;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (!str)
	{
		free(new);
		return (NULL);
	}
	str[len] = '\0';
	while (--len >= 0)
		str[len] = content[len];
	new->content = str;
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

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*del)((*lst)->content);
		free (*lst);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}
