/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:35:38 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/13 14:34:01 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format(const char *format, va_list arg)
{
	if (*format == 'c')
		return (ft_putchar_fd((char)va_arg(arg, int), 1));
	else if (*format == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	// else if (*format == 'p')
	// 	return (ft_putptr_fd(va_arg(arg, unsigned long long), 1));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	// else if (*format == 'u')
	// 	return (ft_putunsign_fd(va_arg(arg, unsigned int), 1));
	// else if (*format == 'x')
	// 	return (ft_putbigbase_fd(va_arg(arg, int), 1));
	// else if (*format == 'X')
	// 	return (ft_putlowbase_fd(va_arg(arg, int), 1));
	else if (*format == '%')
		return (ft_putchar_fd('%', 1));
}

int	ft_printf(const char *format, ...)
{
	va_list arg;
	int		len;

	len = 0;
	va_start(arg, format);

	printf("%d", va_arg(arg, int));
	printf("%d", va_arg(arg, int));
	while (*format)
	{
		if (*format == '%')
			len += ft_format(++format, arg);
		else
		{
			ft_putchar_fd(format, 1);
			len++;
		}
		format++;
	}
	va_end(arg);
	return (len);
}

int main(int argc, char const *argv[])
{
	ft_printf("%c", 'o');
	return 0;
}
