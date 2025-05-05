/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:58:47 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/02 23:24:11 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	crop_zoom(t_fractol *f, double p_x, double p_y, double factor)
{
	t_zoom	z;

	if (!f || !f->tmp_buf || WIDTH < 2 || HEIGHT < 2)
		return ;
	if (factor == 1 && p_x == 0 && p_y == 0)
		return ;
	z.buf_size = (size_t)WIDTH * HEIGHT * CHANNELS;
	z.factor_inv = 1.0 / factor;
	z.offset_x = p_x - (WIDTH / 2.0) * z.factor_inv;
	z.offset_y = p_y - (HEIGHT / 2.0) * z.factor_inv;
	fill_newbuf(f, &z, f->buf);
}

static double	get_zoom_from_level(int zoom_level)
{
	double	factor;
	int		i;

	factor = 1.0;
	i = 0;
	if (zoom_level > 0)
	{
		while (i < zoom_level)
		{
			factor *= ZOOM_FACTOR;
			i++;
		}
	}
	else if (zoom_level < 0)
	{
		while (i > zoom_level)
		{
			factor /= ZOOM_FACTOR;
			i--;
		}
	}
	return (factor);
}

static void	reset_zoom_bounds(t_fractol *f, int pos_x, int pos_y, int in_out)
{
	double	re;
	double	im;
	double	range_r;
	double	range_i;
	double	factor;

	if (in_out == 1)
		factor = 1.0 / ZOOM_FACTOR;
	else
		factor = ZOOM_FACTOR;
	re = f->min_r + ((double)pos_x / WIDTH) * (f->max_r - f->min_r);
	im = f->max_i - ((double)pos_y / HEIGHT) * (f->max_i - f->min_i);
	range_r = (f->max_r - f->min_r) * factor;
	range_i = (f->max_i - f->min_i) * factor;
	f->min_r = re - ((double)pos_x / WIDTH) * range_r;
	f->max_r = f->min_r + range_r;
	f->max_i = im + ((double)pos_y / HEIGHT) * range_i;
	f->min_i = f->max_i - range_i;
}

void	zoom(t_fractol *f, int pos_x, int pos_y, int in_out)
{
	double	factor;
	double	x_offset;
	double	y_offset;

	f->zoom_level = f->zoom_level + in_out;
	factor = get_zoom_from_level(f->zoom_level);
	x_offset = pos_x ;
	y_offset = pos_y ;
	reset_zoom_bounds(f, x_offset, y_offset, in_out);
	if (f->zoom_level > 2 || f->zoom_level < 0
		|| pos_x != WIDTH / 2 || pos_y != HEIGHT / 2)
	{
		f->zoom_level = 0;
		render(f);
	}
	else
	{
		mlx_clear_window(f->mlx, f->win);
		crop_zoom(f, WIDTH / 2, HEIGHT / 2, factor);
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	}
}
