/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 07:18:09 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/19 08:56:55 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	if (n == 0)
		return ((char *) 0);
	while (i < n - 1)
	{
		if (str[i] == (unsigned char) c)
		{
			return (&str[i]);
		}
		i++;
	}
	if (str[i] == (unsigned char) c)
	{
		return (&str[i]);
	}
	return ((char *) 0);
}
