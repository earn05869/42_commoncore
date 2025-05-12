/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:29:49 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/12 22:00:21 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_f(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->tmp_buf = NULL;
	f->zoom_level = 0;
	f->set = -1;
	f->min_r = -2.0;
	f->max_r = 1.0;
	f->max_i = 1.5;
	f->min_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	f->kr = -0.766667;
	f->ki = -0.090000;
	f->fx = 1.0;
	f->sx = 2.0;
	f->rx = 0.5; 
	f->palette = NULL;
	f->color_pattern = -1;
	f->color = 0xFFFFFF;
}

void	get_complex_plane(t_fractol *f)
{
	if (f->set == MANDELBOX)
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->max_i = (f->max_r - f->min_r) * HEIGHT / WIDTH / 2.0;
		f->min_i = -f->max_i;
	}
	else if (f->set == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->max_i = (f->max_r - f->min_r) * HEIGHT / WIDTH / 2.0;
		f->min_i = -f->max_i;
	}
	else
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->max_i = (f->max_r - f->min_r) * HEIGHT / WIDTH / 2.0;
		f->min_i = -f->max_i;
	}
}

void	color_shift(t_fractol *f)
{
	int	alt_color;

	f->color_pattern = (f->color_pattern + 1) % 3;
	reinit_img(f);
	if (f->color == 0xFFFFFF)
		alt_color = 0x333333;
	else
		alt_color = f->color;
	if (f->color_pattern == 0)
		monocolor(f, alt_color);
	else if (f->color_pattern == 1)
	{
		multiplecolor(f, (int [4]){0x000000, alt_color,
			get_percent_color(f->color, 50), 0xFFFFFF}, 4);
	}
	else if (f->color_pattern == 2)
	{
		multiplecolor(f, (int [5]){
			0x0000FF,
			0x00FF00,
			0xFFFF00,
			0xFF0000,
			0xFFFFFF
		}, 5);
	}
}

void	init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		err_exit("mlx_init", f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
		err_exit("mlx_new_window", f);
	f->sx = 2.0;
	f->rx = 0.5;
	f->fx = 1.0;
	get_complex_plane(f);
	color_shift(f);
}
