/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:15:54 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/02 23:30:52 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reinit_img(t_fractol *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;

	if (f->img && f->mlx)
		mlx_destroy_image(f->mlx, f->img);
	if (!f->palette)
	{
		f->palette = ft_calloc(MAX_ITER + 1, sizeof(int));
		if (!f->palette)
			err_exit("Error: Failed to allocate memory for palette", f);
	}
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		err_exit("Error: Failed to create new image", f);
	f->buf = (unsigned char *)mlx_get_data_addr(f->img,
			&pixel_bits, &line_bytes, &endian);
	if (f->tmp_buf)
		return ;
	f->tmp_buf = (unsigned char *)calloc(WIDTH * HEIGHT, 4);
	if (!f->tmp_buf)
		err_exit("Error: Failed to allocate memory", f);
}
