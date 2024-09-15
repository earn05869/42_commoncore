/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:46:10 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/13 14:24:50 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr(int n, int sign, int fd, int len)
{
	if (n <= -10 || n >= 10)
	{
		ft_putnbr(n / 10, sign, fd, len);
		ft_putchar_fd(((sign * n) % 10) + '0', fd);
		len++;
	}
	else
	{
		if (sign == -1 && len++)
			ft_putchar_fd('-', fd);
		ft_putchar_fd(((sign * n) % 10) + '0', fd);
		len++;
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	int	sign;
	int	len;

	if (fd < 0)
		return (0);
	sign = 1;
	len = 0;
	if (n < 0)
		sign = -1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	else
	{
		return (ft_putnbr(n, sign, fd, len));
	}
}
