/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:29:54 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/14 17:38:55 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	len;

	if(!str)
		return (0);

	while (str[len] != '\0')
		len++;
	return (len);
}
