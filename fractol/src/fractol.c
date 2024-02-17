/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:09 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/17 20:36:25 by lprieto-         ###   ########.fr       */
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

int	p_key(int key, t_f *f)
{
	if (key == 53)
		exit (exit_click() * 0);
	if (key == 8)
		f->color = f->color * 3;
	if (key == 9)
		f->color = f->color * -3;
	if (key == 38)
		f->m_x = f->m_x - 0.02;
	if (key == 40)
		f->m_x = f->m_x + 0.02;
	return (render(f));
}

int	mouse(int key, int x, int y, t_f *f)
{
	if (key == 4)
	{
		ft_printf("Oo. zoom Out: %d - %d\n", x, y);
		zoom(f, 1.4);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
	}
	if (key == 5)
	{
		ft_printf(".oO zoom In: %d - %d\n", x, y);
		zoom(f, 0.7);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
	}
	return (render(f));
}

int	main(int argc, char **argv)
{
	t_f		*f = NULL;

	if (argc == 1)
		err_end("\n!! [Error][fr]: nothing to display\n");
	else
		f = fr_match(argv[1]);	
	if (argc == 4 && ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0)
	{
		if (arg_is_int(argc, argv) != 1)
			err_end("\n[Error][ju]: Invalid or incomplete syntax\n");
		f->m_x = atof(argv[3]);
		f->m_y = atof(argv[2]);
	}
	else if (argc != 2)
		err_end("\n!! [Error][n]: invalid number of arguments\n");
	init_fractal(f);
	if (ft_strncmp(argv[1], f->name, 11) != 0)
		err_end("\n!! [Error][bsc]: invalid fractal name\n");
	f->name = (argv[1]);
	print_display(f);
	render(f);
	mlx_hook (f->win_ptr, 17, 1L << 0, exit_click, f);
	mlx_key_hook(f->win_ptr, p_key, f);
	mlx_mouse_hook(f->win_ptr, mouse, f);
	mlx_loop(f->mlx_ptr);
	return (0);
}
