/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:18:19 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/11 14:53:51 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	ch;

	tmp = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n > 0)
	{
		*tmp++ = ch;
		n--;
	}
	return (s);
}
