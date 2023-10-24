/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:16:13 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/24 11:31:23 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
    int count;
 
    count = 0;
    
    if (n < 0 && ++count)
    {
        if(ft_putchar('-') != 1)
            return (-1);
        n = -n;
    }
    if (n > 9)
    {
        count += ft_putnbr(n / 10);
        if (count == -1)
            return (-1);
        n = n % 10;
    }
    if (n <= 9)
    {
        if(ft_putchar(n + '0') == -1)
            return (-1);
        count++;
    }
    return (count);
}