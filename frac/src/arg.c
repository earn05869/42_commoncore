/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:11:51 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/30 17:20:48 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	skip_space_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *str, int *error)
{
	int		i;
	double	nb;
	int		sign;
	double	div;

	nb = 0;
	div = 0.1;
	sign = 1;
	i = skip_space_sign(str, &sign);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		*error = 1;
	return (nb * sign);
}

static int	skip_hex_space_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	if (str[i] == '+')
		i++;
	return (i);
}

static int	ft_ishexdigit(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}

int	ft_atoi_hexcode(char *str)
{
	int	i;
	int	nb;
	int	count;

	nb = 0;
	count = 0;
	i = skip_hex_space_sign(str);
	while (str[i] && ft_ishexdigit(str[i]))
	{
		if (ft_isdigit(str[i]))
			nb = (nb * 16) + (str[i] - '0');
		else
			nb = (nb * 16) + (ft_toupper(str[i]) - 'A' + 10);
		i++;
		count++;
	}
	if (count == 6 && !str[i])
		return (nb);
	return (-1);
}
