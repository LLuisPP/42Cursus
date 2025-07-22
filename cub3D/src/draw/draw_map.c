/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:06:27 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/12 21:04:59 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_cub *game)
{
	char	**map;
	int		y;
	int		x;

	map = game->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				print_map(x * MBLK, y * MBLK, MBLK, game);
			x++;
		}
		y++;
	}
}

bool	touch(float px, float py, t_cub *game)
{
	int	x;
	int	y;

	x = px / BLK;
	y = py / BLK;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

void	draw_ceiling(t_cub *game)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	color = game->txtinf.hex_ceiling;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, color, game);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_cub *game)
{
	int	y;
	int	x;
	int	color;

	y = HEIGHT / 2;
	color = game->txtinf.hex_floor;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, color, game);
			x++;
		}
		y++;
	}
}

void	draw_floor_and_ceiling(t_cub *game)
{
	draw_ceiling(game);
	draw_floor(game);
}
