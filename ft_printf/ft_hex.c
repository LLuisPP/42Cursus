/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:07:06 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/24 11:37:23 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hex(unsigned long hnbr, char str)
{
    int     count;
    char    *base;
    
    count = 0;
    if(str == 'x' || str == 'p')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    if(hnbr >= 16)
    {
        count += ft_hex(hnbr / 16, str);
        if(count == -1)
            return (-1);
    }
    if((ft_putchar(base[hnbr % 16]) == -1))
        return (-1);
    count++;
    return (count);
}