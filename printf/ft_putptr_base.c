/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:46:10 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/19 18:36:04 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putptr(unsigned long long nbr,
	char *base, unsigned int size, int *len)
{
	if (nbr >= size)
	{
		ft_putptr(nbr / size, base, size, len);
		ft_putchar(base[nbr % size]);
		*len += 1;
	}
	else
	{
		nbr = nbr % size;
		ft_putchar(base[nbr]);
		*len += 1;
	}
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

int	ft_putptr_base(void *ptr, char *base)
{
	unsigned int	i;
	unsigned int	size;
	int				len;

	i = 0;
	len = 2;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	while (base[i] != '\0' && base[i] != '+' && base[i] != '-')
		i++;
	size = i;
	if (size > 1 && check_same_base(base, size))
		ft_putptr((unsigned long long)ptr, base, size, &len);
	return (len);
}
