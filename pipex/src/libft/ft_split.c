/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:13:17 by supanuso          #+#    #+#             */
/*   Updated: 2025/02/05 14:36:22 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_free_split(char **set_str)
{
	size_t	i;

	if (!set_str)
		return ;
	i = 0;
	while (set_str[i])
	{
		free(set_str[i]);
		i++;
	}
	free(set_str);
}

size_t	ft_countsub(const char *s, char c)
{
	size_t	i;
	size_t	sub;

	i = 0;
	sub = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			sub++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (sub);
}

size_t	*ft_setpos(const char *s, char c, size_t sub)
{
	size_t	*pos;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	pos = (size_t *)malloc(sub * 2 * sizeof(size_t));
	if (!pos)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			pos[j++] = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		pos[j++] = i;
	}
	return (pos);
}

char	**ft_setsub(const char *s, size_t *pos, size_t sub)
{
	size_t	j;
	size_t	k;
	char	**set_str;

	set_str = (char **)malloc((sub + 1) * sizeof(char *));
	if (!set_str)
		return (NULL);
	j = 0;
	while (j < sub)
	{
		set_str[j] = (char *)malloc((pos[2 * j + 1] - pos[2 * j] + 1));
		if (!set_str[j])
		{
			while (j > 0)
				free(set_str[--j]);
			free(set_str);
			return (NULL);
		}
		k = 0;
		while (pos[2 * j] < pos[2 * j + 1])
			set_str[j][k++] = s[pos[2 * j]++];
		set_str[j++][k] = '\0';
	}
	set_str[j] = NULL;
	return (set_str);
}

char	**ft_split(char const *s, char c)
{
	size_t	sub;
	size_t	*pos;
	char	**set_str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0)
	{
		set_str = (char **)ft_calloc(1, sizeof(char *));
		if (!set_str)
			return (NULL);
		return (set_str);
	}
	sub = ft_countsub(s, c);
	pos = ft_setpos(s, c, sub);
	if (!pos)
		return (NULL);
	set_str = ft_setsub(s, pos, sub);
	free (pos);
	return (set_str);
}
