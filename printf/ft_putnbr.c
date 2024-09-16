/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:46:10 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/16 18:43:17 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_put(int n, int sign, int *len)
{
	if (n <= -10 || n >= 10)
	{
		ft_put(n / 10, sign, len);
		ft_putchar(((sign * n) % 10) + '0');
		len++;
	}
	else
	{
		if (sign == -1)
		{
			ft_putchar('-');
			len++;
		}
		ft_putchar(((sign * n) % 10) + '0');
		len++;
	}
}

int	ft_putnbr(int n)
{
	int	sign;
	int	len;

	sign = 1;
	len = 0;
	if (n < 0)
		sign = -1;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else
	{
		ft_put(n, sign, &len);
		return (len);
	}
}
