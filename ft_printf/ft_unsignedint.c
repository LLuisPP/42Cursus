/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 07:13:04 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/24 07:29:17 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

unsigned int    ft_unsignedint(unsigned int n)
{
    int let;

    let = 0;
    if (n > 9)
    {
        let = ft_unsignedint(n / 10);
        if (let == -1)
            return (-1);
        n = n % 10;
    }
    if (n <= 9)
    {
        if (ft_putchar((n + '0')) == -1)
            return (-1);
        let++;
    }
    return (let);
}