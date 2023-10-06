/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:57:32 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/06 10:59:50 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned in, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char)malloc(sizeof(char)
}
