/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:57:24 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:57:24 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_lis(int *lis, int lis_size, int value)
{
	int	i;

	i = 0;
	while (i < lis_size)
	{
		if (lis[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	pre_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_pre	*pre;
	int		q;

	if (is_sorted(stack_a))
		return ;
	pre = (t_pre *)malloc(sizeof(t_pre));
	if (!pre)
		err_stack(stack_a, stack_b);
	pre->limit = NULL;
	pre->lis = NULL;
	find_lis(stack_a->arr, stack_a->size, pre);
	if (!pre->lis)
		big_err(stack_a, stack_b, pre, NULL);
	q = (stack_a->size - pre->lis_size) / 250 + 2;
	pre->limit = find_limit(stack_a, pre, q);
	if (!pre->limit)
		big_err(stack_a, stack_b, pre, NULL);
	push_bychunk(stack_a, stack_b, pre);
	free(pre->lis);
	free(pre->limit);
	free(pre);
}

void	apply_bm(t_stack *stack_a, t_stack *stack_b, t_bm *bm)
{
	while (bm->nrrr--)
		rrr(stack_a, stack_b);
	while (bm->nrr--)
		rr(stack_a, stack_b);
	while (bm->nrb--)
		rb(stack_b, 1);
	while (bm->nrrb--)
		rrb(stack_b, 1);
	while (bm->nra--)
		ra(stack_a, 1);
	while (bm->nrra--)
		rra(stack_a, 1);
	pa(stack_a, stack_b, 1);
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	t_bm	*bm;

	bm = (t_bm *)malloc(sizeof(t_bm));
	if (!bm)
		err_stack(stack_a, stack_b);
	init_bm(bm);
	while (stack_b->size > 0)
	{
		calculate_bm(stack_a, stack_b, bm);
		apply_bm(stack_a, stack_b, bm);
		bm->total = INT_MAX;
	}
	free(bm);
}
