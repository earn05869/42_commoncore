/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:55:56 by supanuso          #+#    #+#             */
/*   Updated: 2025/02/05 14:36:22 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str && len == 0)
		return (NULL);
	if (!(*sub))
		return ((char *)str);
	while (str[i] && i < len)
	{
		while (str[i + j] == sub[j] && str[i + j] && i + j < len)
		{
			j++;
			if (sub[j] == '\0')
				return ((char *)str + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
