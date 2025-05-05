/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:43:19 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 19:43:19 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

# define CHUNK 6

typedef struct s_stack
{
	int	*arr;
	int	size;
}	t_stack;

typedef struct s_bm
{
	int	nra;
	int	nrb;
	int	nrra;
	int	nrrb;
	int	nrr;
	int	nrrr;
	int	total;
}	t_bm;

typedef struct s_pre
{
	int	*lis;
	int	*limit;
	int	lis_size;
	int	limit_size;
}	t_pre;

void	err_lst(t_list **list_a, char **str);
void	err_stack(t_stack *stack_a, t_stack *stack_b);
void	big_err(t_stack *stack_a, t_stack *stack_b, t_pre *pre, t_bm *bm);
void	clear_stack(t_stack *stack_a, t_stack *stack_b);

void	ft_list(char *arg, t_list **list_a, char **str);
int		find_invalid(char *arg, t_list **list_a, char **str);
int		find_double(int content, t_list *list_a);
t_stack	*ft_parse(int argc, char **argv);
t_stack	*init_stack_b(t_stack *stack_a, t_stack *stack_b);

void	pa(t_stack *stack_a, t_stack *stack_b, int print);
void	pb(t_stack *stack_a, t_stack *stack_b, int print);
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);

int		is_sorted(t_stack *stack_a);
int		is_rev_sorted(t_stack *stack_a);
int		is_in_lis(int *lis, int lis_size, int value);
int		find_min(t_stack *stack_a);
int		find_max(t_stack *stack_a);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);
void	pre_sort(t_stack *stack_a, t_stack *stack_b);
void	push_back(t_stack *stack_a, t_stack *stack_b);
void	find_lis(int *arr, int n, t_pre *pre);
int		*find_limit(t_stack *a, t_pre *pre, int q);
void	init_bm(t_bm *bm);
void	calculate_bm(t_stack *stack_a, t_stack *stack_b, t_bm *bm);
void	apply_bm(t_stack *stack_a, t_stack *stack_b, t_bm *bm);
void	push_bychunk(t_stack *a, t_stack *b, t_pre *p);

void	print_stack(t_stack *stack, char *name);

#endif