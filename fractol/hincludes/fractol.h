/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:13:12 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/17 12:14:53 by lprieto-         ###   ########.fr       */
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

# define HEIGHT	900
# define WIDTH	900

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
	unsigned int	max_w;
	unsigned int	max_h;
	double			min_w;
	double			min_h;
	double	cen_re;
	double	cen_im;
	double	max_im;
	double	min_im;
	double	min_re;
	double	max_re;
}	t_f;

void	init_fractal(t_f *f);
t_f		*get_fractals(void);
t_f		*fr_match(char *str);
int		p_key(int key, t_f *f);
int		mouse(int key, int x, int y, t_f *f);
int		render(t_f *f);
void	my_mlx_pixel_put(t_f *f, int x, int y, int color);
int		err_end(char *msg);
int		exit_click(void);
int		mandelbrot(double cr, double ci, t_f *f);
int		julia(double zx, double zy, t_f *f);
int		tricorn(double cr, double ci, t_f *f);
int		picker(double re, double im, t_f *f);

#endif
