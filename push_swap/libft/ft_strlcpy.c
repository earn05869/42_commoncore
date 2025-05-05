/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:26:40 by supanuso          #+#    #+#             */
/*   Updated: 2025/04/27 21:53:41 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (dstsize > srcsize +1)
		ft_memcpy(dst, src, srcsize +1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize -1);
		dst[dstsize -1] = 0;
	}
	return (srcsize);
}
