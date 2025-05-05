/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:57:38 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:57:38 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (!is_sorted(stack_a))
		sa(stack_a, 1);
}

void	sort_three(t_stack *stack_a)
{
	int	*arr;

	arr = stack_a->arr;
	if (is_sorted(stack_a))
		return ;
	else if (is_rev_sorted(stack_a))
	{
		ra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (arr[0] > arr[1] && arr[0] > arr[2])
		ra(stack_a, 1);
	else if (arr[1] > arr[0] && arr[0] > arr[2])
		rra(stack_a, 1);
	else if (arr[1] > arr[2] && arr[1] > arr[0])
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else
		sa(stack_a, 1);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	len;

	if (is_sorted(stack_a))
		return ;
	min = find_min(stack_a);
	len = stack_a->size;
	while (stack_a->arr[0] != min && stack_a->arr[len - 1] != min)
		ra(stack_a, 1);
	if (stack_a->arr[0] != min)
		rra(stack_a, 1);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	len;

	if (is_sorted(stack_a))
		return ;
	min = find_min(stack_a);
	len = stack_a->size;
	while (stack_a->arr[0] != min && stack_a->arr[len - 1] != min
		&& stack_a->arr[len - 2] != min)
		ra(stack_a, 1);
	if (stack_a->arr[len - 1] == min)
		rra(stack_a, 1);
	if (stack_a->arr[len - 2] == min)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	i;

	i = 0;
	min = find_min(stack_a);
	pre_sort(stack_a, stack_b);
	push_back(stack_a, stack_b);
	while (i < stack_a->size && stack_a->arr[i] != min)
		i++;
	if (i < stack_a->size / 2)
		while (i-- > 0)
			ra(stack_a, 1);
	else
		while (i++ < stack_a->size)
			rra(stack_a, 1);
	return ;
}
