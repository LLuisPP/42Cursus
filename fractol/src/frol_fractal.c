/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frol_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:14:54 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/19 11:29:01 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_f	*get_fractals(void)
{
	static t_f	f[4];

	ft_bzero(f, sizeof(t_f));
	f[0].name = "Mandelbrot";
	f[1].name = "Julia";
	f[2].name = "Tricorn";
	f[3].name = NULL;
	return (f);
}

t_f	*fr_match(char *str)
{
	t_f	*f;
	int	i;
	int	j;

	j = ft_strlen(str);
	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strncmp(f[i].name, str, j) == 0)
			return (&f[i]);
		i++;
	}
	err_end("\n!! [Error][nmchk]: invalid fractal name\n");
	return (0);
}

void	init_fractal(t_f *f)
{
	f->addr = NULL;
	f->l_len = 0;
	f->bpp = 0;
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, f->name);
	f->img = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->l_len, &f->end);
	f->max_iter = 150;
	f->color = 0x9e95ef;
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = f->min_re + (f->max_re - (f->min_re)) * WIDTH / HEIGHT;
}
