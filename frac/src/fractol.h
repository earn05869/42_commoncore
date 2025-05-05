/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:10:20 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/02 23:31:51 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "key.h"

# define CHANNELS 4
# define ZOOM_FACTOR 1.1
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITER 200

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define TRICORN 4
# define MANDELBOX 5

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*buf;
	unsigned char	*zoom_buf;
	unsigned char	*tmp_buf;
	int				zoom_level;
	int				set;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			kr;
	double			ki;
	double			sx;
	double			rx;
	double			fx;
	int				*palette;
	int				color_pattern;
	int				color;
}	t_fractol;

typedef struct s_ip
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	double			dx;
	double			dy;
	unsigned char	*p00;
	unsigned char	*p10;
	unsigned char	*p01;
	unsigned char	*p11;
}	t_ip;

typedef struct s_zoom
{
	double	factor_inv;
	double	offset_x;
	double	offset_y;
	size_t	buf_size;
}	t_zoom;

void	display_help(t_fractol *f);

void	set_f(t_fractol *f);
void	color_shift(t_fractol *f);
void	init(t_fractol *f);

void	handle_arg(int argc, char **argv, t_fractol *f);

double	ft_atof(char *str, int *error);
int		ft_atoi_hexcode(char *str);

void	reinit_img(t_fractol *f);

void	err_exit(char *msg, t_fractol *f);

void	monocolor(t_fractol *f, int color);
void	multiplecolor(t_fractol *f, int color[4], int n);
int		get_percent_color(int color, double percent);

void	render(t_fractol *f);
void	render_zoom(t_fractol *f);

int		mandelbrot(double pr, double pi);
int		julia(t_fractol *f, double pr, double pi);
int		mandelbox(t_fractol *f, double pr, double pi);

int		close_window(t_fractol *f);
void	fill_newbuf(t_fractol *f, t_zoom *z, unsigned char *new_buf);
void	zoom(t_fractol *f, int pos_x, int pos_y, int in_out);

int		key_hook(int keycode, t_fractol *f);
int		mouse_hook(int button, int x, int y, t_fractol *f);

#endif