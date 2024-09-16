/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:15 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/16 18:49:57 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putbase(unsigned int nbr, char *base, unsigned int size, int *len)
{
	if (nbr >= size)
	{
		ft_putbase(nbr / size, base, size, len);
		ft_putchar(base[nbr % size]);
		len++;
	}
	else
	{
		nbr = nbr % size;
		ft_putchar(base[nbr]);
		len++;
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

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	i;
	unsigned int	size;
	int				len;

	i = 0;
	len = 0;
	while (base[i] != '\0' && base[i] != '+' && base[i] != '-')
		i++;
	size = i;
	if (size > 1 && check_same_base(base, size))
		ft_putbase(nbr, base, size, &len);
	exit(0);
	return (len);
}
