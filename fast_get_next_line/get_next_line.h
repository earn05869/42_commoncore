/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:13:35 by supanuso          #+#    #+#             */
/*   Updated: 2024/11/15 18:39:50 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
# endif

#define SIZE 1024

typedef struct s_gnl
{
	char		**lst;
	int			index;
	int			pos_nl;
	int			len;
}	t_gnl;

#endif