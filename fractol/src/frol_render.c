/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frol_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:16:02 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/17 12:12:12 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_f *f, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		dst = f->addr + (y * f->l_len + x * (f->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	picker(double re, double im, t_f *f)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (f->name[len])
		len++;
	f->name[len] = '\0';
	if (!ft_strncmp(f->name, "Mandelbrot", 10))
		i = mandelbrot(re, im, f);
	else if (!ft_strncmp(f->name, "Julia", 5))
		i = julia(re, im, f);
	else if (!ft_strncmp(f->name, "Tricorn", 7))
		i = tricorn(re, im, f);
	else
		err_end("No match name");
	return (i);
}

int	render(t_f *f)
{
	double	re;
	double	im;
	int		i;
	int		x;
	int		y;

	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			re = f->min_re + (double)x * (f->max_re - (f->min_re)) / WIDTH;
			im = f->max_im + (double)y * (f->min_im - f->max_im) / HEIGHT;
			if (f->name != 0)
			{
				i = picker(re, im, f);
				if (i < f->max_iter)
					my_mlx_pixel_put(f, x, y, (i * f->color));
				else
					my_mlx_pixel_put(f, x, y, 0x000000);
			}
		}
	}
	mlx_put_image_to_window (f->mlx_ptr, f->win_ptr, f->img, 0, 0);
	return (0);
}
