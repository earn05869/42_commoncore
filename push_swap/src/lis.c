/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:44:05 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 18:44:05 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

static int	lower_bound(int *arr, int size, int key)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

static void	clear_arrays(int **arrays)
{
	if (arrays)
	{
		if (arrays[0])
			free(arrays[0]);
		if (arrays[1])
			free(arrays[1]);
		if (arrays[2])
			free(arrays[2]);
		free(arrays);
	}
}

static void	init_arrays(int ***arrays, int *arr, int n)
{
	*arrays = (int **)malloc(3 * sizeof(int *));
	if (!*arrays)
		return ;
	(*arrays)[0] = NULL;
	(*arrays)[1] = NULL;
	(*arrays)[2] = NULL;
	(*arrays)[0] = (int *)malloc(n * sizeof(int));
	(*arrays)[1] = (int *)malloc(n * sizeof(int));
	(*arrays)[2] = (int *)malloc(n * sizeof(int));
	if (!(*arrays)[0] || !(*arrays)[1] || !(*arrays)[2])
	{
		clear_arrays(*arrays);
		*arrays = NULL;
		return ;
	}
	(*arrays)[0][0] = arr[0];
	(*arrays)[1][0] = 0;
	(*arrays)[2][0] = -1;
	return ;
}

static void	update_arrays(int **arrays, int *arr, int i, int *len)
{
	int	pos;

	if (arr[i] > arrays[0][*len - 1])
	{
		arrays[2][i] = arrays[1][*len - 1];
		arrays[0][*len] = arr[i];
		arrays[1][*len] = i;
		(*len)++;
	}
	else
	{
		pos = lower_bound(arrays[0], *len, arr[i]);
		arrays[0][pos] = arr[i];
		arrays[1][pos] = i;
		if (pos > 0)
			arrays[2][i] = arrays[1][pos - 1];
		else
			arrays[2][i] = -1;
	}
}

void	find_lis(int *arr, int n, t_pre *pre)
{
	int	**arrays;
	int	i;
	int	len;
	int	pos;

	init_arrays(&arrays, arr, n);
	if (!arrays[0] || !arrays[1] || !arrays[2])
		return ;
	len = 1;
	i = 0;
	while (++i < n)
		update_arrays(arrays, arr, i, &len);
	pre->lis = (int *)malloc(len * sizeof(int));
	if (!pre->lis)
		return ;
	i = len;
	pos = arrays[1][len - 1];
	while (--i >= 0)
	{
		pre->lis[i] = arr[pos];
		pos = arrays[2][pos];
	}
	pre->lis_size = len;
	clear_arrays(arrays);
}
