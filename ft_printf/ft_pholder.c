/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pholder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:40:31 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/24 11:31:14 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pholder(char const *str, va_list args, int i, int j)
{
	if (str[j] == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (str[j] == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (str[j] == 'p')
	{
		if (ft_putstr("0x") == -1)
		return (-1);
		i += 2;
		i += ft_hex(va_arg(args, unsigned long), str[j]);
	}
	else if (str[j] == 'd' || (str[j] == 'i'))
		i += ft_putnbr(va_arg(args, int));
	else if (str[j] == 'u')
		i += ft_unsignedint(va_arg(args, unsigned int));
	else if (str[j] == 'x')
		i += ft_hex(va_arg(args, unsigned int), str[j]);
	else if (str[j] == 'X')
		i += ft_hex(va_arg(args, unsigned int), str[j]);
	else if (str[j] == '%')
		i += ft_putchar('%'); 
	return (i);
}
