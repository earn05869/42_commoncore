/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:56:46 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:56:46 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int print)
{
	int	i;

	if (stack_b->size == 0)
		return ;
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->arr[i] = stack_a->arr[i - 1];
		i--;
	}
	stack_a->arr[0] = stack_b->arr[0];
	stack_a->size++;
	stack_b->size--;
	i = 0;
	while (i < stack_b->size)
	{
		stack_b->arr[i] = stack_b->arr[i + 1];
		i++;
	}
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	int	i;

	if (stack_a->size == 0)
		return ;
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->arr[i] = stack_b->arr[i - 1];
		i--;
	}
	stack_b->arr[0] = stack_a->arr[0];
	stack_b->size++;
	stack_a->size--;
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->arr[i] = stack_a->arr[i + 1];
		i++;
	}
	if (print)
		ft_putstr_fd("pb\n", 1);
}
