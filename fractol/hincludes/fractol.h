/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:13:12 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/19 12:30:04 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

# define HEIGHT	500
# define WIDTH	500

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	double	m_x;
	double	m_y;
	int		end;
	int		max_iter;
	int		color;
	char	*addr;
	int		bpp;
	int		l_len;
	double	cen_re;
	double	cen_im;
	double	max_im;
	double	min_im;
	double	min_re;
	double	max_re;
	int		i;
}	t_f;

int		arg_is_int(int argc, char **argv);
int		frol_range(int argc, char **argv);
int		check_julia(int argc, char **argv, t_f *f);
void	init_fractal(t_f *f);
t_f		*get_fractals(void);
t_f		*fr_match(char *str);
int		p_key(int key, t_f *f);
int		mouse(int key, int x, int y, t_f *f);
int		render(t_f *f);
void	my_mlx_pixel_put(t_f *f, int x, int y, int color);
int		err_end(char *msg);
void	menu_optns(void);
int		exit_click(void);
int		mandelbrot(double cr, double ci, t_f *f);
int		julia(double zx, double zy, t_f *f);
int		tricorn(double cr, double ci, t_f *f);
int		picker(double re, double im, t_f *f);
void    print_display(t_f *f);
void	tricorn_ascii(void);
void	mandelbrot_ascii(void);
void	julia_ascii(void);

#endif
