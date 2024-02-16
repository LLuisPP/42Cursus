/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/16 09:11:59 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_f *f, double zoom)
{
	double	cen_re;
	double	cen_im;

	cen_re = f->prm.min_re - f->prm.max_re;
	cen_im = f->prm.max_im - f->prm.min_im;
	f->prm.max_re = f->prm.max_re + (cen_re - zoom * cen_re) / 2.29;
	f->prm.min_re = f->prm.max_re + zoom * cen_re;
	f->prm.min_im = f->prm.min_im + (cen_im - zoom * cen_im) / 2.9;
	f->prm.max_im = f->prm.min_im + zoom * cen_im;
}

int	p_key(int key, t_f *f)
{
	(void)f;
	// ft_printf("key %d pressed\n", key);
	if (key == 53)
		exit (exit_click() * 0);

	if (key == 69)
	{
		write(1, "↑↑↑ .oO zoom In\n", 23);
	}
	if (key == 78)
	{
		write(1, "↓↓↓ Oo. zoom Out\n", 24);
	}
	return (0);
}


int	mouse(int key, int x, int y, t_f *f)
{
	// ft_printf("key %d pressed\n", key);
	// ft_printf("x: %d\n", x);
	// ft_printf("y: %d\n", y);
	if (key == 4)
	{
		ft_printf("Oo. zoom Out\n", key);
		zoom(f, 1.4);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
	}
	if (key == 5)
	{
		ft_printf(".oO zoom In\n", key);
		zoom(f, 0.7);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
	}
	return (render(f, x, y));
}

int	main(int argc, char **argv)
{
	t_f		*f;
	void	*param;

	if (argc != 2)
		err_end("[Error]: invalid number of arguments");
	f = fr_match(argv[1]);
	init_fractal(f);
	if (f->name == NULL)
		err_end("[Error]: invalid fractal name");
	f->name = (argv[1]);
	ft_printf("Este es el nombre que le entra: %s\n", argv[1]);
	ft_printf("Este el que tiene: %s\n", f->name);
	render(f, -2, 2);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img, 0, 0);
	mlx_hook (f->win_ptr, 17, 1L << 0, exit_click, f);
	mlx_key_hook(f->win_ptr, p_key, &param);
	mlx_mouse_hook(f->win_ptr, mouse, f);
	mlx_loop(f->mlx_ptr);
	return (0);
}
