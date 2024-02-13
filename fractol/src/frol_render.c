/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frol_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:16:02 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/13 09:20:10 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_f *f, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		dst = f->prm.addr + (y * f->prm.l_len + x * (f->prm.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	render(t_f *f, int x, int y)
{
	double	re;
	double	im;
	int		i;

	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			re = f->prm.min_re + (double)x
				* (f->prm.max_re - (f->prm.min_re)) / WIDTH;
			im = f->prm.max_im + (double)y
				* (f->prm.min_im - f->prm.max_im) / HEIGHT;
			if (f->name != 0)
			{
				// i = julia(re, im, f);
				i = mandelbrot(re, im, f);
				// i = tricorn(re, im, f);
				// // i = burningship(re, im, f);
				if (i < f->prm.max_iter)
					my_mlx_pixel_put(f, x, y, (i * 0x9e94ef));
				else
					my_mlx_pixel_put(f, x, y, 0x000000);
			}
		}
	}
	mlx_put_image_to_window (f->mlx_ptr, f->win_ptr, f->img, 0, 0);
	return (0);
}
