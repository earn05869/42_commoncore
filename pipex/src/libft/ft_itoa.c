/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:53:32 by supanuso          #+#    #+#             */
/*   Updated: 2025/02/05 14:36:22 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_intlen(int n, int *sign)
{
	int	len;

	len = 0;
	*sign = 1;
	if (n < 0)
	{
		*sign = -1;
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		i;
	int		sign;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_intlen(n, &sign);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (n != 0)
	{
		result[len - 1 - i] = (sign * (n % 10)) + 48;
		n /= 10;
		i++;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}

// #include <stdio.h>

// int main(void)
// {
// 	int n = -__INT_MAX__ - 1;
// 	printf("%s\n", ft_itoa(n));
// }