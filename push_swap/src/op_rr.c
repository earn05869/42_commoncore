/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:56:58 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:56:58 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack_a, int print)
{
	int	i;
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->arr[stack_a->size - 1];
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->arr[i] = stack_a->arr[i - 1];
		i--;
	}
	stack_a->arr[0] = temp;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack_b, int print)
{
	int	i;
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->arr[stack_b->size - 1];
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->arr[i] = stack_b->arr[i - 1];
		i--;
	}
	stack_b->arr[0] = temp;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
