/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:30:20 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/01 19:20:18 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*long_dst;
	unsigned long	*long_src;
	unsigned char	*byte_dst;
	unsigned char	*byte_src;

	if (!src && !dst)
		return (dst);
	long_dst = (unsigned long *)dst;
	long_src = (unsigned long *)src;

	while (n >= sizeof(unsigned long))
	{
		*long_dst++ = *long_src++;
		n -= sizeof(unsigned long);
	}

	byte_dst = (unsigned char *)long_dst;
	byte_src = (unsigned char *)long_src;

	while (n-- > 0)
		*byte_dst++ = *byte_src++;

	return (dst);
}
