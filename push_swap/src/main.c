/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:56:22 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:56:22 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_stack *stack, char *name)
// {
// 	int	i;

// 	if (!stack || stack->size == 0)
// 	{
// 		printf("%s is empty\n", name);
// 		return ;
// 	}
// 	printf("%s: ", name);
// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		printf("%d ", stack->arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = ft_parse(argc, argv);
	stack_b = init_stack_b(stack_a, stack_b);
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else if (stack_a->size > 5)
		sort_large(stack_a, stack_b);
	clear_stack(stack_a, stack_b);
	return (0);
}
