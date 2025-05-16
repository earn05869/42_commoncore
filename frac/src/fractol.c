/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:47:42 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/13 19:47:08 by supanuso         ###   ########.fr       */
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
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

int	mandelbox(t_fractol *f, double cr, double ci)
{
	int		n;
	double	vr;
	double	vi;
	double	mag;

	vr = cr;
	vi = ci;
	mag = 0;
	n = 0;
	while (n < MAX_ITER)
	{
		vr = f->fx * box_fold(vr);
		vi = f->fx * box_fold(vi);
		mag = sqrt(vr * vr + vi * vi);
		vr = vr * f->sx * ball_fold(f->rx, mag) + cr;
		vi = vi * f->sx * ball_fold(f->rx, mag) + ci;
		if (sqrt(mag) > 2)
			break ;
		n++;
	}
	return (n);
}
