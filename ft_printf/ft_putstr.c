/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:34:40 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/24 11:31:21 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	// int	len;
	int	i;

	i = 0;
	if (!s)
		return(ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		if(ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}