/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:15:04 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/13 17:48:56 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_julia_color(void)
{
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	ft_putendl_fd("Usage example:\t", 1);
	ft_putendl_fd("\t\t./fractol Julia\n\t\t./fractol Julia 0.285 0.01", 1);
	ft_putendl_fd(
		"\n+===============  Color Display  ====================+", 1);
	ft_putendl_fd("Pick a display color by providing a hexadecimal code.", 1);
	ft_putendl_fd("The hex color code must be formatted as RRGGBB:", 1);
	ft_putendl_fd("\tWhite:\tFFFFFF\t\tBlack:\t000000", 1);
	ft_putendl_fd("\tRed:\tFF0000\t\tGreen:\t00FF00", 1);
	ft_putendl_fd("\tBlue:\t0000FF\t\tYellow:\tFFFF00", 1);
	ft_putendl_fd("Other interesting colors:", 1);
	ft_putendl_fd("\tPurple:\t9933FF\t\tOrange:\tCC6600", 1);
	ft_putendl_fd("\tPink:\tFF3399\t\tTurquoise: 00FF80\t", 1);
	ft_putstr_fd("Usage example:\t", 1);
	ft_putendl_fd("./fractol <type> <color>", 1);
	ft_putendl_fd("\t\t./fractol Mandelbrot 0066FF", 1);
	ft_putendl_fd("\nFor Julia, you can only specify colors after", 1);
	ft_putendl_fd("the starting values.", 1);
	ft_putstr_fd("Usage example:\t", 1);
	ft_putendl_fd("./fractol Julia 0.285 0.01 CC6600", 1);
}

void	display_help(t_fractol *f)
{
	ft_putendl_fd(
		"\n+===================  Help Menu  ====================+\n", 1);
	ft_putendl_fd("+===============  Available Fractals  ===============+", 1);
	ft_putendl_fd("Which fractal would you like to view?", 1);
	ft_putendl_fd("\tMandelbrot", 1);
	ft_putendl_fd("\tJulia", 1);
	ft_putendl_fd("\tBurning Ship", 1);
	ft_putendl_fd("\tTricorn", 1);
	ft_putendl_fd("\tMandelbox", 1);
	ft_putendl_fd(
		"Usage example:\t./fractol <type>\n\t\t./fractol Mandelbrot", 1);
	display_julia_color();
	if (f->mlx)
		free(f->mlx);
	if (f->img)
		free(f->img);
	if (f->palette)
		free(f->palette);
	exit(EXIT_FAILURE);
}
