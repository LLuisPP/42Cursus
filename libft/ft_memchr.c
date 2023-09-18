/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:26:49 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/18 21:32:56 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const	char *str;
	size_t	i;

	i = 0;
	str = (const char *)s;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)(s + 1));
		i++;
	}
	return (0);
}
