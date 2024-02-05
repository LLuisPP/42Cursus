/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:13:12 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/05 11:26:05 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define  FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

typedef struct  s_s
{
    int         val;
    int         idx;
    struct s_s  *nxt;
    struct s_s  *prv;
}   t_s;

#endif
