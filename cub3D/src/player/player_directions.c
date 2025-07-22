/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:57:00 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/12 20:36:21 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_cub *game, float cos_a, float sin_a)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x + cos_a * SPEED;
	new_y = game->player.y + sin_a * SPEED;
	if (!touch(new_x, game->player.y, game))
		game->player.x = new_x;
	if (!touch(game->player.x, new_y, game))
		game->player.y = new_y;
}

void	move_backward(t_cub *game, float cos_a, float sin_a)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x - cos_a * SPEED;
	new_y = game->player.y - sin_a * SPEED;
	if (!touch(new_x, game->player.y, game))
		game->player.x = new_x;
	if (!touch(game->player.x, new_y, game))
		game->player.y = new_y;
}

void	strafe_left(t_cub *game, float cos_a, float sin_a)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x + sin_a * SPEED;
	new_y = game->player.y - cos_a * SPEED;
	if (!touch(new_x, game->player.y, game))
		game->player.x = new_x;
	if (!touch(game->player.x, new_y, game))
		game->player.y = new_y;
}

void	strafe_right(t_cub *game, float cos_a, float sin_a)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x - sin_a * SPEED;
	new_y = game->player.y + cos_a * SPEED;
	if (!touch(new_x, game->player.y, game))
		game->player.x = new_x;
	if (!touch(game->player.x, new_y, game))
		game->player.y = new_y;
}
