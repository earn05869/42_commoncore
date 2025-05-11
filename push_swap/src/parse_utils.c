/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:57:10 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:57:10 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_lst(t_list **list_a, char **str)
{
	ft_lstclear(list_a);
	if (str)
	{
		while (*str)
		{
			free(*str);
			str++;
		}
		free(str);
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	find_invalid(char *arg, t_list **list_a, char **str)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == ' ' || arg[i] == '+'
			|| arg[i] == '-')
			i++;
		else
			err_lst(list_a, str);
	}
	return (0);
}

int	find_double(int content, t_list *list_a)
{
	t_list	*temp;

	temp = list_a;
	while (temp)
	{
		if (content == temp->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}
