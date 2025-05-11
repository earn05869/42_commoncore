/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:05:48 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/07 16:20:09 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toberemoved(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	*str;

	j = ft_strlen(s1);
	if (j == 0)
		return (ft_strdup(""));
	i = 0;
	j -= 1;
	while (s1[i] != '\0' && ft_toberemoved(s1[i], set))
		i++;
	while (j > i && ft_toberemoved(s1[j], set))
		j--;
	str = (char *)malloc((j - i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	count = 0;
	while (i <= j)
		str[count++] = s1[i++];
	str[count] = '\0';
	return (str);
}
