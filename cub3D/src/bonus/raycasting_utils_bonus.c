/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:06:27 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/18 21:40:48 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perform_dda(t_cub *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	calculate_step_and_sidedist(t_cub *game, t_ray *ray)
{
	double	player_grid_x;
	double	player_grid_y;

	player_grid_x = game->player.x / BLK;
	player_grid_y = game->player.y / BLK;
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player_grid_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player_grid_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player_grid_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player_grid_y) * ray->deltadist_y;
	}
}

void	init_ray(t_cub *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	ray->dir_x = cos(game->player.angle) + -sin(game->player.angle) * camera_x;
	ray->dir_y = sin(game->player.angle) + cos(game->player.angle) * camera_x;
	ray->map_x = (int)(game->player.x / BLK);
	ray->map_y = (int)(game->player.y / BLK);
	if (ray->dir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->dir_y);
}

void	calculate_projection(t_cub *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->dist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->dist = ray->sidedist_y - ray->deltadist_y;
	ray->height = (int)((float)HEIGHT / ray->dist);
	ray->draw_start = -ray->height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = game->player.y / BLK + ray->dist * ray->dir_y;
	else
		ray->wall_x = game->player.x / BLK + ray->dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (float)game->txtinf.tex_width);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		ray->tex_x = game->txtinf.tex_width - ray->tex_x - 1;
}
