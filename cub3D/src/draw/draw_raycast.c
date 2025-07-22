/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:06:27 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/21 18:58:32 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			ray->texture_idx = EAST;
		else
			ray->texture_idx = WEST;
	}
	else
	{
		if (ray->dir_y > 0)
			ray->texture_idx = SOUTH;
		else
			ray->texture_idx = NORTH;
	}
}

void	draw_textured_column(t_cub *game, t_ray *ray, int x)
{
	int		y;
	float	step;
	float	tex_pos;
	int		tex_y;
	int		color;

	get_texture_index(ray);
	step = 1.0f * (float)game->txtinf.tex_height / ray->height;
	tex_pos = (ray->draw_start - (float)HEIGHT / 2 + ray->height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)tex_pos & (game->txtinf.tex_height - 1);
		tex_pos += step;
		color = game->textures[ray->texture_idx][game->txtinf.tex_height
			* tex_y + ray->tex_x];
		put_pixel(x, y, color, game);
		y++;
	}
}

int	draw_loop(t_cub *game)
{
	int		x;
	t_ray	ray;

	move_player(game);
	clear_image(game);
	draw_floor_and_ceiling(game);
	x = 0;
	while (x < WIDTH)
	{
		init_ray(game, &ray, x);
		calculate_step_and_sidedist(game, &ray);
		perform_dda(game, &ray);
		calculate_projection(game, &ray);
		draw_textured_column(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
