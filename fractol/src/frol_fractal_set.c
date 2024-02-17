/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frol_fractal_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:27:45 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/17 09:46:02 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double zx, double zy, t_f *f)
{
	int		i;
	double	tmp;

	i = -1;
	tmp = 0;
	while (zx * zx + zy * zy <= 4.0 && ++i < f->max_iter)
	{
		tmp = 2 * zx * zy + f->m_y;
		zx = zx * zx - zy * zy + f->m_x;
		zy = tmp;
	}
	return (i);
}

int	mandelbrot(double cr, double ci, t_f *f)
{
	int		i;
	double	zx;
	double	zy;
	double	tmp;

	i = -1;
	zx = 0;
	zy = 0;
	tmp = 0;
	while (zx * zx + zy * zy <= 60.0 && ++i < f->max_iter)
	{
		tmp = zx * zx - zy * zy + cr;
		zy = 2 * zx * zy + ci;
		zx = tmp;
	}
	return (i);
}

int	tricorn(double cr, double ci, t_f *f)
{
	int		i;
	double	zx;
	double	zy;
	double	tmp;

	zx = cr;
	zy = ci;
	i = -1;
	while (zx * zx + zy * zy < 4.0 && ++i < f->max_iter)
	{
		tmp = -2 * zx * zy + ci;
		zx = zx * zx - zy * zy + cr;
		zy = tmp;
		i++;
	}
	return (i);
}
