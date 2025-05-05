/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:39:21 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/02 23:44:01 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fill_black(unsigned char *rgba)
{
	rgba[0] = 0;
	rgba[1] = 0;
	rgba[2] = 0;
	rgba[3] = 255;
}

static void	set_ptrs(t_fractol *f, t_ip *a)
{
	a->p00 = f->tmp_buf + (a->y0 * WIDTH + a->x0) * CHANNELS;
	a->p10 = f->tmp_buf + (a->y0 * WIDTH + a->x1) * CHANNELS;
	a->p01 = f->tmp_buf + (a->y1 * WIDTH + a->x0) * CHANNELS;
	a->p11 = f->tmp_buf + (a->y1 * WIDTH + a->x1) * CHANNELS;
}

static void	blend_rgba(t_ip *a, unsigned char *rgba)
{
	int		i;
	double	blend;

	i = 0;
	while (i < CHANNELS - 1)
	{
		blend = (1 - a->dx) * (1 - a->dy) * a->p00[i]
			+ a->dx * (1 - a->dy) * a->p10[i]
			+ (1 - a->dx) * a->dy * a->p01[i]
			+ a->dx * a->dy * a->p11[i];
		if (blend < 0)
			blend = 0;
		if (blend > 255)
			blend = 255;
		rgba[i] = (unsigned char)(blend + 0.5);
		i++;
	}
	rgba[3] = 255;
}

static void	interpolate(t_fractol *f, t_zoom *z, int xy[2], unsigned char *rgba)
{
	t_ip	a;
	double	xp;
	double	yp;

	xp = (xy[0] * z->factor_inv) + z->offset_x;
	yp = (xy[1] * z->factor_inv) + z->offset_y;
	if (xp < 0 || xp >= WIDTH - 1 || yp < 0 || yp >= HEIGHT - 1)
	{
		fill_black(rgba);
		return ;
	}
	a.x0 = (int)xp;
	a.y0 = (int)yp;
	a.x1 = a.x0 + 1;
	a.y1 = a.y0 + 1;
	if (a.x1 >= WIDTH)
		a.x1 = WIDTH - 1;
	if (a.y1 >= HEIGHT)
		a.y1 = HEIGHT - 1;
	a.dx = xp - a.x0;
	a.dy = yp - a.y0;
	set_ptrs(f, &a);
	blend_rgba(&a, rgba);
}

void	fill_newbuf(t_fractol *f, t_zoom *z, unsigned char *new_buf)
{
	int				x;
	int				y;
	unsigned char	*rgba;
	size_t			idx;

	y = 0;
	rgba = malloc(CHANNELS * sizeof(unsigned char));
	if (!rgba)
		err_exit("Error: malloc", f);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			interpolate(f, z, (int [2]){x, y}, rgba);
			idx = ((size_t)y * WIDTH + x) * CHANNELS;
			new_buf[idx] = rgba[0];
			new_buf[idx + 1] = rgba[1];
			new_buf[idx + 2] = rgba[2];
			new_buf[idx + 3] = 255;
			x++;
		}
		y++;
	}
	free(rgba);
}
