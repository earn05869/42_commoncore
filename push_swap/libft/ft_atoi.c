/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:17:29 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 21:53:41 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str, int *error)
{
	long long	i;
	long long	sign;
	long long	num;

	i = 0;
	sign = -1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		num = (num * 10) - (str[i++] - '0');
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
	{
		*error = 1;
		return (0);
	}
	return ((int)num);
}
