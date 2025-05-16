/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:37:26 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/16 16:04:17 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_set(char *str, t_fractol *f)
{
	if (!strncmp(str, "M", 2) || !strncmp(str, "Mandelbrot", 8))
		f->set = MANDELBROT;
	else if (!strncmp(str, "J", 2) || !strncmp(str, "Julia", 6))
		f->set = JULIA;
	else if (!strncmp(str, "X", 2) || !strncmp(str, "Mandelbox", 9))
		f->set = MANDELBOX;
	else
		display_help(f);
}

static void	set_for_julia(int argc, char **argv, t_fractol *f)
{
	int	error;

	error = 0;
	if (f->set != JULIA || argc == 2)
		return ;
	if (argc == 3)
		display_help(f);
	if (!ft_strchr(argv[2], '.'))
		display_help(f);
	if (!ft_strchr(argv[3], '.'))
		display_help(f);
	f->kr = ft_atof(argv[2], &error);
	f->ki = ft_atof(argv[3], &error);
	if (error)
		display_help(f);
	if (f->kr < -2.0 || f->kr > 2.0)
		display_help(f);
	if (f->ki < -2.0 || f->ki > 2.0)
		display_help(f);
}

static void	set_color(int argc, char **argv, t_fractol *f)
{
	if (f->set == JULIA && argc == 5)
		f->color = ft_atoi_hexcode(argv[4]);
	else if (f->set != JULIA && argc == 3)
		f->color = ft_atoi_hexcode(argv[2]);
	else if (argc == 2 || (f->set == JULIA && argc == 4))
		f->color = 0xed7a91;
	else
		display_help(f);
	if (f->color < 0)
		display_help(f);
}

void	handle_arg(int argc, char **argv, t_fractol *f)
{
	get_set(argv[1], f);
	if (f->set != JULIA && argc > 3)
		display_help(f);
	else if (f->set == JULIA && argc > 5)
		display_help(f);
	set_for_julia(argc, argv, f);
	set_color(argc, argv, f);
}
