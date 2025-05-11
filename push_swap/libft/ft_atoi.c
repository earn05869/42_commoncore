/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:17:29 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/11 21:13:11 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	emp_plus_minus(const char *str, int *error, long long *count, long long *sign)
{
	int	i;

	i = 0;
	if (!str[0] || ((str[0] == '+' || str[0] == '-') && !str[1]))
	{
		*error = 1;
		return (1);
	}
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = 1;
		i++;
	}
	*count = i;
	return (0);
}

int	ft_atoi(const char *str, int *error)
{
	long long	i;
	long long	sign;
	long long	num;

	i = 0;
	sign = -1;
	num = 0;
	if (emp_plus_minus(str, error, &i, &sign))
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		num = (num * 10) - (str[i++] - '0');
	num *= sign;
	if (num > INT_MAX || num < INT_MIN || ft_strchr(str + i, '+')
		|| ft_strchr(str + i, '-') || i == 0)
	{
		*error = 1;
		return (0);
	}
	return ((int)num);
}
