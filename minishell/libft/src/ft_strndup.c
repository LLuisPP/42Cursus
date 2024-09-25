/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:46:16 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/25 09:44:42 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*dup;
	size_t	slen;

	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	dup = malloc(len + 1);
	if (dup)
		ft_strlcpy(dup, s, len + 1);
	return (dup);
}
