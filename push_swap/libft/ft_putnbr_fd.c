/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:46:10 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/11 21:13:11 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(int n, int sign, int fd)
{
	if (n <= -10 || n >= 10)
	{
		ft_putnbr(n / 10, sign, fd);
		ft_putchar_fd(((sign * n) % 10) + '0', fd);
	}
	else
	{
		if (sign == -1)
			ft_putchar_fd('-', fd);
		ft_putchar_fd(((sign * n) % 10) + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	if (fd < 0)
		return ;
	sign = 1;
	if (n < 0)
		sign = -1;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
		ft_putnbr(n, sign, fd);
}
