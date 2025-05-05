/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:57:14 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:57:14 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_listset(char *arg, t_list **list_a)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		err_lst(list_a, NULL);
	i = 0;
	while (split[i])
	{
		ft_list(split[i], list_a, split);
		i++;
	}
	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
}

void	ft_list(char *arg, t_list **list_a, char **str)
{
	t_list	*node;
	int		error;
	int		num;

	error = 0;
	find_invalid(arg, list_a, str);
	if (ft_strchr(arg, ' '))
		ft_listset(arg, list_a);
	else
	{
		num = ft_atoi(arg, &error);
		if (error || find_double(num, *list_a))
			err_lst(list_a, str);
		node = ft_lstnew(num);
		if (!node)
			err_lst(list_a, str);
		ft_lstadd_back(list_a, node);
	}
}

int	*init_stack_a(t_list *list_a, t_stack *stack_a)
{
	int		*arr;
	int		i;
	t_list	*temp;

	i = 0;
	temp = list_a;
	stack_a->size = ft_lstsize(list_a);
	arr = (int *)malloc(sizeof(int) * stack_a->size);
	if (!arr)
		return (NULL);
	while (temp)
	{
		arr[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (arr);
}

t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*stack_a;
	t_list	*list_a;
	int		i;

	list_a = NULL;
	i = 0;
	while (++i < argc)
		ft_list(argv[i], &list_a, NULL);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		err_lst(&list_a, NULL);
	stack_a->arr = init_stack_a(list_a, stack_a);
	if (!stack_a->arr)
	{
		free(stack_a);
		err_lst(&list_a, NULL);
	}
	ft_lstclear(&list_a);
	return (stack_a);
}

t_stack	*init_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_b)
		err_stack(stack_a, NULL);
	stack_b->arr = (int *)malloc(sizeof(int) * stack_a->size);
	if (!stack_b->arr)
	{
		free(stack_b);
		err_stack(stack_a, NULL);
	}
	stack_b->size = 0;
	return (stack_b);
}
