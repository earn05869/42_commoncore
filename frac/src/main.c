/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:30:47 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/16 16:34:07 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	err_exit(char *msg, t_fractol *f)
{
	perror(msg);
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx)
		mlx_terminate(f->mlx);
	if (f->palette)
		free(f->palette);
	if (f->tmp_buf)
		free(f->tmp_buf);
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char **argv)
{
	t_fractol	f;

	set_f(&f);
	if (argc < 2)
		display_help(&f);
	handle_arg(argc, argv, &f);
	init(&f);
	render(&f);
	mlx_key_hook(f.mlx, &key_hook, &f);
	mlx_scroll_hook(f.mlx, &mouse_hook, &f);
	mlx_close_hook(f.mlx, &close_window, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}
