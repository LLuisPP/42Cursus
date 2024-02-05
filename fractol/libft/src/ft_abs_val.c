/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:09:30 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/23 11:40:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* abs_value returns absolute value of an input */
int	abs_value(int value)
{
	int	abs;

	abs = value;
	if (value < 0)
		abs = -value;
	return (abs);
}
