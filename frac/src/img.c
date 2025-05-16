/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:15:54 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/13 18:01:24 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reinit_img(t_fractol *f)
{
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (!f->palette)
	{
		f->palette = ft_calloc(MAX_ITER + 1, sizeof(int));
		if (!f->palette)
			err_exit("Error: palette alloc", f);
	}
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		err_exit("Error: image alloc", f);
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		err_exit("Error: image_to_window", f);
	if (!f->tmp_buf)
	{
		f->tmp_buf = ft_calloc(WIDTH * HEIGHT, sizeof(uint32_t));
		if (!f->tmp_buf)
			err_exit("Error: tmp_buf alloc", f);
	}
}
