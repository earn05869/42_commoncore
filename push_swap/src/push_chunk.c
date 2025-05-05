/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:49:31 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/03 17:30:52 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_range(int val, int low, int high)
{
	return (val >= low && val <= high);
}

static void	push_rest(t_stack *a, t_stack *b, t_pre *p)
{
	int	size;

	size = a->size;
	while (size--)
	{
		if (is_in_lis(p->lis, p->lis_size, a->arr[0]))
			ra(a, 1);
		else
			pb(a, b, 1);
	}
}

void	push_bychunk(t_stack *a, t_stack *b, t_pre *p)
{
	int	i;
	int	low;
	int	size;

	i = p->limit_size;
	while (i >= 2)
	{
		low = p->limit[i - 2];
		size = a->size;
		while (size--)
		{
			if (is_in_lis(p->lis, p->lis_size, a->arr[0]))
				ra(a, 1);
			else if (in_range(a->arr[0], low, p->limit[i - 1]))
			{
				pb(a, b, 1);
				if (b->arr[0] > p->limit[i - 1])
					rb(b, 1);
			}
			else
				ra(a, 1);
		}
		i -= 2;
	}
	push_rest(a, b, p);
}
