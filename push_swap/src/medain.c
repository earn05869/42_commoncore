/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:56:35 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:56:35 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

int	*get_quantile(int *arr, int size, int q, t_pre *pre)
{
	int	*result;
	int	i;
	int	pos;

	if (!arr || size < 1 || q < 2)
		return (NULL);
	result = (int *)malloc(sizeof(int) * (q - 1));
	if (!result)
		return (NULL);
	quicksort(arr, 0, size - 1);
	i = 0;
	while (++i < q)
	{
		if (size < q && i <= size)
		{
			result[i - 1] = arr[i - 1];
			continue ;
		}
		pos = (i * size) / q;
		if ((i * size) % q == 0)
			pos--;
		result[i - 1] = arr[pos];
	}
	pre->limit_size = q - 1;
	return (result);
}

int	*find_limit(t_stack *a, t_pre *pre, int q)
{
	int	*copy;
	int	i;
	int	j;
	int	*limits;
	int	size;

	size = a->size - pre->lis_size;
	copy = (int *)malloc(size * sizeof(int));
	if (!copy)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (j < pre->lis_size && a->arr[i + j] == pre->lis[j])
			j++;
		else
		{
			copy[i] = a->arr[i + j];
			i++;
		}
	}
	limits = get_quantile(copy, size, q, pre);
	free(copy);
	return (limits);
}
