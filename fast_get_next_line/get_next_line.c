/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:14:48 by supanuso          #+#    #+#             */
/*   Updated: 2024/11/15 18:40:06 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_gnl		*data;
	static char	**remain;
	
	data = new_data(&remain, fd);
	if (!data)
		return (NULL);
	if (extract_remain(&data, &remain, fd))
		return (data->line);
	read_line(&data, fd);
	combine_line(&data);
	
	if (read)
	return (data->line);
}