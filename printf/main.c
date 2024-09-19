/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:40:53 by supanuso          #+#    #+#             */
/*   Updated: 2024/09/19 15:12:51 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main(void)
{
	unsigned int num = 123415;

	printf("len : %d \n",ft_printf("str: %u", num));
	printf("len : %d \n",printf("str: %u", num));
	return (0);
}
