/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:55:25 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/21 19:58:17 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strcpy(char *dest, const char *src)
{
    char    *orig_ptr;
    
    orig_ptr = dest;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    dest = '\0';
    return (orig_ptr);
}