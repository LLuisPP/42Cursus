/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pholder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:40:31 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/23 12:40:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pholder(char const *str, va_list args, int i, int j)
{
	if (str[j] == 'c')
		ft_putchar(va_arg(args, int));
	if (str[j] == 's')
		ft_putstr(va_arg(args, char *));
	return (i);
}
