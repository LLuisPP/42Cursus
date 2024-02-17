/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/17 12:05:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_f *f, double zoom)
{
	double	cen_re;
	double	cen_im;

	cen_re = f->min_re - f->max_re;
	cen_im = f->max_im - f->min_im;
	f->max_re = f->max_re + (cen_re - zoom * cen_re) / 2.29;
	f->min_re = f->max_re + zoom * cen_re;
	f->min_im = f->min_im + (cen_im - zoom * cen_im) / 2.9;
	f->max_im = f->min_im + zoom * cen_im;
}
// int	zoom(int key, int x, int y, t_f *f)
// {
// 	if (key == 5)
// 	{
// 		f->min_w = x + (f->min_w - x) * 1.1;
// 		f->min_h = y + (f->min_h - y) * 1.1;
// 		f->max_w = x + (f->max_w - x) * 1.1;
// 		f->max_h = y + (f->max_h - y) * 1.1;
// 	}
// 	else if (key == 4)
// 	{
// 		f->min_w = x + (f->min_w - x) * 0.9;
// 		f->min_h = y + (f->min_h - y) * 0.9;
// 		f->max_w = x + (f->max_w - x) * 0.9;
// 		f->max_h = y + (f->max_h - y) * 0.9;
// 	}
// 	render(f);
// 	return (0);
// }

int	p_key(int key, t_f *f)
{
	if (key == 53)
		exit (exit_click() * 0);
	if (key == 69)
	{
		f->color = f->color * 3;
		ft_printf("shifting up color\n");
		f->m_x = f->m_x + 0.02;
	}
	if (key == 78)
	{
		f->color = f->color * -3;
		ft_printf("shifting down color\n");
		f->m_x = f->m_x - 0.02;
	}
	if (key == 4)
	{
		ft_printf("valor de m_x: %d\n", f->m_x);
	}	
	return (render(f));
}

int	mouse(int key, int x, int y, t_f *f)
{
	if (key == 4)
	{
		ft_printf("Oo. zoom Out: %d - %d\n", x, y);
		// f->min_w = x + (f->min_w - x) * 1.1;
		// f->min_h = y + (f->min_h - y) * 1.1;
		// f->max_w = x + (f->max_w - x) * 1.1;
		// f->max_h = y + (f->max_h - y) * 1.1;
		zoom(f, 1.4);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
	}
	if (key == 5)
	{
		ft_printf(".oO zoom In: %d - %d\n", x, y);
		// f->min_w = x + (f->min_w - x) * 0.9;
		// f->min_h = y + (f->min_h - y) * 0.9;
		// f->max_w = x + (f->max_w - x) * 0.9;
		// f->max_h = y + (f->max_h - y) * 0.9;
		zoom(f, 0.7);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
	}
	return (render(f));
}

int	main(int argc, char **argv)
{
	t_f		*f;
	// void	*param;

	f = fr_match(argv[1]);
	if (argc == 4 && ft_strncmp(argv[1], "Julia", 5) == 0)
	{
		f->m_x = atof(argv[3]);
		ft_printf("valor de m_x: %d\n", ft_atof(argv[2]));
		ft_printf("valor de m_x: %d\n", atof(argv[2]));
		f->m_y = atof(argv[2]);
	}
	else if (argc != 2)
		err_end("[Error]: invalid number of arguments");
	init_fractal(f);
	if (f->name == NULL)
		err_end("[Error]: invalid fractal name");
	f->name = (argv[1]);
	ft_printf("Input fractal: %s\n", argv[1]);
	ft_printf("Correct! loading: %s\n", f->name);
	render(f);
	mlx_hook (f->win_ptr, 17, 1L << 0, exit_click, f);
	mlx_key_hook(f->win_ptr, p_key, f);
	mlx_mouse_hook(f->win_ptr, mouse, f);
	mlx_loop(f->mlx_ptr);
	return (0);
}
