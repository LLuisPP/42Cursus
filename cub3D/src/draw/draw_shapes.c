/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:06:27 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/17 21:40:19 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(int x, int y, int size, t_cub *game)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(x + i, y, PLYCOL, game);
		put_pixel(x, y + i, PLYCOL, game);
		put_pixel(x + size, y + i, PLYCOL, game);
		put_pixel(x + i, y + size, PLYCOL, game);
		i++;
	}
}

void	draw_circle(int x, int y, int radius, t_cub *game)
{
	int	dx;
	int	dy;

	dy = -radius;
	while (dy <= radius)
	{
		dx = -radius;
		while (dx <= radius)
		{
			if (dx * dx + dy * dy <= radius * radius)
				put_pixel(x + dx, y + dy, PLYCOL, game);
			dx++;
		}
		dy++;
	}
}

void	draw_fov_on_minimap(t_cub *game)
{
	float	angle_step;
	float	ray_angle;
	float	ray_x;
	float	ray_y;
	int		i;

	angle_step = FOV_ANGLE / NUM_RAYS_MINIMAP;
	i = 0;
	ray_angle = game->player.angle - (PHI / 6) + ((PHI / 3) / WIDTH) * i;
	while (i < NUM_RAYS_MINIMAP)
	{
		ray_x = game->player.x;
		ray_y = game->player.y;
		while (!touch(ray_x, ray_y, game))
		{
			put_pixel((int)(ray_x / BLK * MBLK),
				(int)(ray_y / BLK * MBLK), VISCOL, game);
			ray_x += cos(ray_angle);
			ray_y += sin(ray_angle);
		}
		ray_angle += angle_step;
		i++;
	}
}
