/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:58:25 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/18 17:35:39 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	unsigned char *p;

	i = 0;
	p = (unsigned char *) b;
	while (i < len)
	{
		*p = (unsigned char)c;
		i++;
		p++; 
	}
	return (b);
}

