/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:29:54 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/14 21:43:41 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if(!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_malloc(size_t len1, int len2)
{
	char	*mallocated;

	mallocated = (char *)malloc(sizeof(len1 + len2) + 1);
	if (!mallocated)
		return (0);
	return (mallocated);
}
