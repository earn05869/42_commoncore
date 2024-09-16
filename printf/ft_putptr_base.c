/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:46:10 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/16 18:52:21 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putptr(unsigned long long nbr, char *base, unsigned int size, int len)
{
	if (nbr >= size)
	{
		ft_putptr(nbr / size, base, size, len);
		ft_putchar(base[nbr % size]);
		len++;
	}
	else
	{
		nbr = nbr % size;
		ft_putchar(base[nbr]);
		len++;
		return (len);
	}
	return (0);
}

static int	check_same_base(char *base, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	same;

	i = 0;
	while (i < size)
	{
		j = 0;
		same = 0;
		while (j < size)
		{
			if (base[i] == base[j])
				same++;
			j++;
		}
		if (same > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_putptr_base(unsigned long long nbr, char *base)
{
	unsigned int	i;
	unsigned int	size;
	int				len;

	i = 0;
	len = 2;
	write (1, "0x", 2);
	while (base[i] != '\0' && base[i] != '+' && base[i] != '-')
		i++;
	size = i;
	if (size > 1 && check_same_base(base, size))
		len += ft_putptr(nbr, base, size, len);
	return (len);
}
