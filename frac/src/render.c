/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:37:42 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/16 16:32:20 by supanuso         ###   ########.fr       */
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

static void	set_pixel(t_fractol *f, int x, int y, int color)
{
	int			offset;
	uint32_t	pixel_color;
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;

	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = color & 0xFF;
	pixel_color = (255 << 24) | (red << 16) | (green << 8) | blue;
	offset = (x + y * WIDTH);
	((uint32_t *)f->img->pixels)[offset] = pixel_color;
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		n_iter;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		pi = f->max_i - (f->max_i - f->min_i) * (double)y / HEIGHT;
		while (++x < WIDTH)
		{
			pr = f->min_r + (f->max_r - f->min_r) * (double)x / WIDTH;
			n_iter = cal_fractol(f, pr, pi);
			set_pixel(f, x, y, f->palette[n_iter]);
		}
	}
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	ft_memcpy(f->tmp_buf, f->img->pixels, WIDTH * HEIGHT * 4);
}
