/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:34:40 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/30 09:14:05 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_putstr(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (ft_putstr("(null)"));
// 	while (s[i] != '\0')
// 	{
// 		if (ft_putchar(s[i]) == -1)
// 			return (-1);
// 		i++;
// 	}
// 	return (i);
// }

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
