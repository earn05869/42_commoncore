/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:35:27 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/04 19:30:13 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*str;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len > start)
	{
		if (len > str_len - start)
			len = str_len - start;
		str = (char *)malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s + start, len + 1);
		return (str);
	}
	return (ft_strdup(""));
}
