/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:01:16 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/16 16:28:39 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_window(void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx)
		mlx_terminate(f->mlx);
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

static int	key_logic(keys_t key, action_t act, t_fractol *f)
{
	if (key == MLX_KEY_ESCAPE && act == MLX_PRESS)
		close_window(f);
	else if (key == MLX_KEY_SPACE && act == MLX_PRESS)
		color_shift(f);
	else if (key == MLX_KEY_EQUAL && act == MLX_PRESS)
		zoom(f, WIDTH / 2, HEIGHT / 2, 1);
	else if (key == MLX_KEY_MINUS && act == MLX_PRESS)
		zoom(f, WIDTH / 2, HEIGHT / 2, -1);
	else if ((key == MLX_KEY_UP || key == MLX_KEY_W) && act == MLX_PRESS)
		move(f, 0.05, 'U');
	else if ((key == MLX_KEY_DOWN || key == MLX_KEY_S) && act == MLX_PRESS)
		move(f, 0.05, 'D');
	else if ((key == MLX_KEY_LEFT || key == MLX_KEY_A) && act == MLX_PRESS)
		move(f, 0.05, 'L');
	else if ((key == MLX_KEY_RIGHT || key == MLX_KEY_D) && act == MLX_PRESS)
		move(f, 0.05, 'R');
	else
		return (0);
	return (1);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	keys_t		key;
	action_t	act;
	t_fractol	*f;

	f = (t_fractol *)param;
	key = keydata.key;
	act = keydata.action;
	if (!key_logic(key, act, f))
		return ;
	if (key != MLX_KEY_EQUAL && key != MLX_KEY_MINUS)
	{
		f->zoom_level = 0;
		render(f);
	}
}

void	mouse_hook(double xdelta, double ydelta, void *param)
{
	int32_t		x;
	int32_t		y;
	t_fractol	*f;

	f = (t_fractol *)param;
	mlx_get_mouse_pos(f->mlx, &x, &y);
	if (ydelta > 0)
		zoom(f, x, y, 1);
	else if (ydelta < 0)
		zoom(f, x, y, -1);
	(void)xdelta;
}
