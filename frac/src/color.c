/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:12:04 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/16 16:55:21 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	interpolate(int start, int end, double frac)
{
	int	r;
	int	g;
	int	b;

	r = ((start >> 16) & 0xFF) + (((end >> 16) & 0xFF)
			- ((start >> 16) & 0xFF)) * frac;
	g = ((start >> 8) & 0xFF) + (((end >> 8) & 0xFF)
			- ((start >> 8) & 0xFF)) * frac;
	b = ((start >> 0) & 0xFF) + (((end >> 0) & 0xFF)
			- ((start >> 0) & 0xFF)) * frac;
	return (0xFF << 24 | r << 16 | g << 8 | b);
}

void	monocolor(t_fractol *f, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	i = 0;
	color1 = 0xFF000000;
	color2 = color;
	while (i < MAX_ITER)
	{
		j = 0;
		while (j < MAX_ITER / 2)
		{
			fraction = (double)j / (MAX_ITER / 2);
			f->palette[i + j] = interpolate(color1, color2, fraction);
			j++;
		}
		color1 = color;
		color2 = 0xFFFFFFFF;
		i += j;
	}
	f->palette[MAX_ITER - 1] = 0xFF000000;
}

void	multiplecolor(t_fractol *f, int color[4], int n)
{
	int		i;
	int		j;
	int		x;
	double	fraction;

	i = 0;
	x = 0;
	while (i < MAX_ITER)
	{
		j = 0;
		while ((i + j) < MAX_ITER && j < (MAX_ITER / (n - 1)))
		{
			fraction = (double)j / (MAX_ITER / (n - 1));
			f->palette[i + j] = interpolate(color[x], color[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
	f->palette[MAX_ITER - 1] = 0;
}

int	get_percent_color(int color, double percent)
{
	int	r;
	int	g;
	int	b;
	int	percentage;

	percentage = percent / 100 * 256;
	r = ((color >> 16) & 0xFF) + percentage - 256;
	g = ((color >> 8) & 0xFF) + percentage - 256;
	b = ((color >> 0) & 0xFF) + percentage - 256;
	return (0xFF << 24 | r << 16 | g << 8 | b);
}

void	set_pallette(t_fractol *f, int alt_color)
{
	int	colors[5];

	if (f->color_pattern == 0)
		monocolor(f, alt_color);
	else if (f->color_pattern == 1)
	{
		colors[0] = 0x000000;
		colors[1] = alt_color;
		colors[2] = get_percent_color(alt_color, 50);
		colors[3] = 0xFFFFFF;
		multiplecolor(f, colors, 4);
	}
	else if (f->color_pattern == 2)
	{
		colors[0] = 0x0000FF;
		colors[1] = 0x00FFFF;
		colors[2] = 0xFFFF00;
		colors[3] = 0xFF8000;
		colors[4] = 0xFFFFFF;
		multiplecolor(f, colors, 5);
	}
}
