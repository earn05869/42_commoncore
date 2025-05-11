/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:57:29 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:57:29 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->arr[i] > stack_a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_rev_sorted(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->arr[i] < stack_a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_min(t_stack *stack_a)
{
	int	min;
	int	i;

	i = 1;
	min = stack_a->arr[0];
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] < min)
			min = stack_a->arr[i];
		i++;
	}
	return (min);
}

void	push_little(t_stack *stack_a, t_stack *stack_b, t_pre *pre)
{
	int	i;

	i = stack_a->size;
	while (i--)
	{
		if (is_in_lis(pre->lis, pre->lis_size, stack_a->arr[0]))
			ra(stack_a, 1);
		else
			pb(stack_a, stack_b, 1);
	}
}
