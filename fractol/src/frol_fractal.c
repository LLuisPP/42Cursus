/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frol_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:14:54 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/13 09:07:22 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_f	*get_fractals(void)
{
	static t_f	array[5];

	ft_bzero(array, sizeof(t_f));
	array[0].name = "Mandelbrot";
	array[1].name = "Julia";
	array[2].name = "Tricorn";
	array[3].name = "Burningship";
	array[4].name = NULL;
	return (array);
}

t_f	*fr_match(char *str)
{
	t_f	*f;
	int	i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}

void	init_fractal(t_f *f)
{
	f->prm.addr = NULL;
	f->prm.l_len = 0;
	f->prm.bpp = 0;
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	f->img = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->prm.addr = mlx_get_data_addr(f->img, &f->prm.bpp, &f->prm.l_len,
			&f->prm.end);
	f->prm.max_iter = 150;
	f->prm.min_re = -2.0;
	f->prm.max_re = 2.0;
	f->prm.min_im = -2.0;
	f->prm.max_im = f->prm.min_re + (f->prm.max_re - (f->prm.min_re))
		* WIDTH / HEIGHT;
}
