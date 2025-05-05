/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:37:42 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/02 23:25:55 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	cal_fractol(t_fractol *f, double pr, double pi)
{
	int	n_iter;

	if (f->set == MANDELBROT)
		n_iter = mandelbrot(pr, pi);
	else if (f->set == JULIA)
		n_iter = julia(f, pr, pi);
	else if (f->set == MANDELBOX)
		n_iter = mandelbox(f, pr, pi);
	else
		return (-1);
	return (n_iter);
}

static void	set_pixel(unsigned char *buf, int x, int y, int color)
{
	int	offset;

	offset = (x * 4) + (y * WIDTH * 4);
	buf[offset] = color & 0xFF;
	buf[offset + 1] = (color >> 8) & 0xFF;
	buf[offset + 2] = (color >> 16) & 0xFF;
	buf[offset + 3] = (color >> 24) & 0xFF;
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		n_iter;

	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		pi = f->max_i - (f->max_i - f->min_i) * (float)y / HEIGHT;
		while (++x < WIDTH)
		{
			pr = f->min_r + (f->max_r - f->min_r) * (float)x / WIDTH;
			n_iter = cal_fractol(f, pr, pi);
			set_pixel(f->buf, x, y, f->palette[n_iter]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	ft_memcpy(f->tmp_buf, f->buf, WIDTH * HEIGHT * 4);
}
