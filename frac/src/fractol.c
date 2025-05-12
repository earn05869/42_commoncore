/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:47:42 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/12 21:55:49 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double pr, double pi)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		iter;

	zr = 0.0;
	zi = 0.0;
	zr2 = 0.0;
	zi2 = 0.0;
	iter = 0;
	while (zr2 + zi2 <= 4.0 && iter < MAX_ITER)
	{
		zi = 2.0 * zr * zi + pi;
		zr = zr2 - zi2 + pr;
		zr2 = zr * zr;
		zi2 = zi * zi;
		iter++;
	}
	return (iter);
}

int	julia(t_fractol *f, double pr, double pi)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		iter;

	zr = pr;
	zi = pi;
	zr2 = zr * zr;
	zi2 = zi * zi;
	iter = 0;
	while (zr2 + zi2 <= 4.0 && iter < MAX_ITER)
	{
		zi = 2.0 * zr * zi + f->ki;
		zr = zr2 - zi2 + f->kr;
		zr2 = zr * zr;
		zi2 = zi * zi;
		iter++;
	}
	return (iter);
}

static double	box_fold(double v)
{
	if (v > 1.0)
		v = 2.0 - v;
	else if (v < -1.0)
		v = -2.0 - v;
	return (v);
}

static double	calc_scale(double r, double mag)
{
	double	r_squared;

	r_squared = r * r;
	if (mag < r)
		return (mag / r_squared);
	if (mag < 1.0)
		return (1.0 / (mag * mag));
	return (1.0);
}

int	mandelbox(t_fractol *f, double cr, double ci)
{
	double	vr;
	double	vi;
	double	mag;
	double	scale;
	int		n;

	vr = cr;
	vi = ci;
	n = 0;
	while (n < MAX_ITER)
	{
		vr = f->fx * box_fold(vr);
		vi = f->fx * box_fold(vi);
		mag = vr * vr + vi * vi;
		scale = calc_scale(f->rx, sqrt(mag));
		vr = vr * f->sx * scale + cr;
		vi = vi * f->sx * scale + ci;
		if ((vr * vr + vi * vi) > 100.0)
			break ;
		n++;
	}
	return (n);
}

