/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:01:16 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/02 23:32:41 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	if (f->palette)
		free(f->palette);
	if (f->tmp_buf)
		free(f->tmp_buf);
	exit(EXIT_SUCCESS);
}

static void	move(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}

int	key_hook(int key, t_fractol *f)
{
	if (key == ESC)
		close_window(f);
	else if (key == SPACE)
		color_shift(f);
	else if (key == PLUS)
		zoom(f, WIDTH / 2, HEIGHT / 2, 1);
	else if (key == MINUS)
		zoom(f, WIDTH / 2, HEIGHT / 2, -1);
	else if (key == UP || key == W)
		move(f, 0.05, 'U');
	else if (key == DOWN || key == S)
		move(f, 0.05, 'D');
	else if (key == LEFT || key == A)
		move(f, 0.05, 'L');
	else if (key == RIGHT || key == D)
		move(f, 0.05, 'R');
	else
		return (0);
	if (key != PLUS && key != MINUS)
	{
		f->zoom_level = 0;
		render(f);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == MOUSE_WHEEL_UP)
		zoom(f, x, y, 1);
	else if (button == MOUSE_WHEEL_DOWN)
		zoom(f, x, y, -1);
	return (0);
}
