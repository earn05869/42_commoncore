/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:57:20 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:57:20 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_stack(t_stack *stack_a, t_stack *stack_b)
{
	clear_stack(stack_a, stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	big_err(t_stack *stack_a, t_stack *stack_b, t_pre *pre, t_bm *bm)
{
	if (pre)
	{
		if (pre->lis)
			free(pre->lis);
		if (pre->limit)
			free(pre->limit);
		free(pre);
	}
	if (bm)
		free(bm);
	clear_stack(stack_a, stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	clear_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		if (stack_a->arr)
			free(stack_a->arr);
		free(stack_a);
	}
	if (stack_b)
	{
		if (stack_b->arr)
			free(stack_b->arr);
		free(stack_b);
	}
}
