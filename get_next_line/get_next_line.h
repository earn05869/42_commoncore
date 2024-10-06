/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:41:58 by supanuso          #+#    #+#             */
/*   Updated: 2024/10/06 12:31:18 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	int				byte_read;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*ft_lstnew(char *content, int byte_read);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize_to_len(t_list *lst, int pos_nl);
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif
