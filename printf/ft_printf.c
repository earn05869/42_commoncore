/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:31:13 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/26 14:38:55 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format(const char *format, va_list arg)
{
	if (*format == 'c')
		return (ft_putchar((unsigned char)va_arg(arg, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (*format == 'p')
		return (ft_putptr_base(va_arg(arg, void *), "0123456789abcdef"));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (*format == 'u')
		return (ft_putnbr_base(va_arg(arg, unsigned int), "0123456789"));
	else if (*format == 'x')
		return (ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (*format == 'X')
		return (ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else if (*format == '%')
		return (ft_putchar('%'));
	else
	{
		return (write(1, "%", 1) + ft_putchar(*format));
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_format(++format, arg);
		}
		else
			len += ft_putchar((char)*format);
		format++;
	}
	va_end(arg);
	return (len);
}
