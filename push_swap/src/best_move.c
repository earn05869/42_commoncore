/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:56:08 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:56:08 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_next(t_stack *stack_a, int value)
{
	int	i;
	int	next;

	i = 0;
	next = INT_MAX;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] > value && stack_a->arr[i] < next)
			next = stack_a->arr[i];
		i++;
	}
	if (next == INT_MAX)
		next = find_min(stack_a);
	return (next);
}

int	cal_all(int next, t_bm *bm, t_stack *stack_a)
{
	int	s;
	int	total;

	s = 0;
	while (s < stack_a->size && stack_a->arr[s] != next)
		s++;
	if (s <= stack_a->size - s)
		bm->nra = s;
	else
		bm->nrra = stack_a->size - s;
	while (bm->nra && bm->nrb)
	{
		bm->nrr++;
		bm->nra--;
		bm->nrb--;
	}
	while (bm->nrra && bm->nrrb)
	{
		bm->nrrr++;
		bm->nrra--;
		bm->nrrb--;
	}
	total = bm->nra + bm->nrb + bm->nrra + bm->nrrb + bm->nrr + bm->nrrr;
	bm->total = total;
	return (total);
}

void	copy_bm(t_bm *src, t_bm *dst)
{
	dst->nra = src->nra;
	dst->nrb = src->nrb;
	dst->nrra = src->nrra;
	dst->nrrb = src->nrrb;
	dst->nrr = src->nrr;
	dst->nrrr = src->nrrr;
	dst->total = src->total;
}

void	init_bm(t_bm *bm)
{
	bm->nra = 0;
	bm->nrb = 0;
	bm->nrra = 0;
	bm->nrrb = 0;
	bm->nrr = 0;
	bm->nrrr = 0;
	bm->total = INT_MAX;
}

void	calculate_bm(t_stack *stack_a, t_stack *stack_b, t_bm *bm)
{
	int		next;
	int		i;
	t_bm	*temp_bm;

	temp_bm = (t_bm *)malloc(sizeof(t_bm));
	if (!temp_bm)
		big_err(stack_a, stack_b, NULL, bm);
	i = 0;
	while (i < stack_b->size)
	{
		init_bm(temp_bm);
		if (i <= stack_b->size - i)
			temp_bm->nrb = i;
		else
			temp_bm->nrrb = stack_b->size - i;
		next = find_next(stack_a, stack_b->arr[i]);
		if (cal_all(next, temp_bm, stack_a) < bm->total)
			copy_bm(temp_bm, bm);
		if (bm->total == 0 || bm->total == 1)
			break ;
		i++;
	}
	free(temp_bm);
	return ;
}
