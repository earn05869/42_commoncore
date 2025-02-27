/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:42:04 by supanuso          #+#    #+#             */
/*   Updated: 2025/02/27 17:43:40 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*my_lstnew(char *content, int bread)
{
	t_list	*new;
	char	*str;
	int		i;

	if (!content || bread < 0)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	str = (char *)malloc(bread + 1);
	if (!str || !new)
	{
		free(new);
		return (NULL);
	}
	i = 0;
	while (i < bread)
	{
		str[i] = content[i];
		i++;
	}
	str[bread] = '\0';
	new->content = str;
	new->bread = bread;
	new->next = NULL;
	return (new);
}

t_list	*my_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	my_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = my_lstlast(*lst);
		last->next = new;
	}
}

int	my_lstsize_to_len(t_list *lst, int nlp)
{
	t_list	*tmp;
	int		len;

	tmp = lst;
	len = 0;
	while (tmp->next)
	{
		len += tmp->bread;
		tmp = tmp->next;
	}
	if (tmp->content)
		len += nlp + 1;
	return (len);
}

void	my_lstclear(t_list **lst, void (*del)(void *))
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
