/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:30:47 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/02 22:07:38 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	err_exit(char *msg, t_fractol *f)
{
	perror(msg);
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
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2)
		display_help(&f);
	set_f(&f);
	handle_arg(argc, argv, &f);
	init(&f);
	render(&f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
