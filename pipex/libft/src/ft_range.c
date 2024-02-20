/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:12:52 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/23 11:43:09 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* range_value calculates the range of inputs */
int	range_value(int max_v, int min_v)
{
	int	range;

	if (min_v < 0 && max_v >= 0)
		range = max_v - min_v + 1;
	if ((min_v >= 0 && max_v >= 0) || (min_v <= 0 && max_v <= 0))
		range = max_v - min_v + 1;
	return (range);
}
