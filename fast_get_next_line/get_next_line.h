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
#include <stdint.h>
#include <stddef.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
# endif

#define SIZE 512

typedef struct s_gnl
{
	char	**lst;
	int		index;
	int		pos_nl;
	int		len;
}	t_gnl;

t_gnl	*new_data(char ***remain, int fd);
int		extract_remain(t_gnl **data, char ***remain, int fd, char **line);
void	free_mode(char **remain , t_gnl *data, char mode);
int		ft_strlen_chr(const char *str , char c, int *len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*new_remain(char ***remain, t_gnl **data, int start, int fd);

#endif