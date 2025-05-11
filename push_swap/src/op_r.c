/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:55:56 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:55:56 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int print)
{
	int	i;
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->arr[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->arr[i] = stack_a->arr[i + 1];
		i++;
	}
	stack_a->arr[i] = temp;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack_b, int print)
{
	int	i;
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->arr[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->arr[i] = stack_b->arr[i + 1];
		i++;
	}
	stack_b->arr[i] = temp;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}
