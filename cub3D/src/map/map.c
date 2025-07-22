/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:07:11 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/12 18:18:06 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(int x, int y, int size, t_cub *game)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(x + i, y, MAPCOL, game);
		put_pixel(x, y + i, MAPCOL, game);
		put_pixel(x + size, y + i, MAPCOL, game);
		put_pixel(x + i, y + size, MAPCOL, game);
		i++;
	}
}
