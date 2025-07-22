/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:03:14 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/12 20:47:27 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	in_map_bounds(float px, float py, t_cub *game)
{
	int	x;
	int	y;

	x = px / BLK;
	y = py / BLK;
	if (y < 0 || !game->map[y])
		return (false);
	if (x < 0 || x >= (int)ft_strlen(game->map[y]))
		return (false);
	return (true);
}

void	move_player_rotate(t_cub *game)
{
	if (game->player.left_rotate)
		game->player.angle -= 0.06;
	if (game->player.right_rotate)
		game->player.angle += 0.06;
	if (game->player.angle > 2 * PHI)
		game->player.angle = 0;
	if (game->player.angle < 0)
		game->player.angle = 2 * PHI;
}

void	move_player_direction(t_cub *game, float cos_a, float sin_a)
{
	if (game->player.key_up)
		move_forward(game, cos_a, sin_a);
	if (game->player.key_down)
		move_backward(game, cos_a, sin_a);
	if (game->player.key_left)
		strafe_left(game, cos_a, sin_a);
	if (game->player.key_right)
		strafe_right(game, cos_a, sin_a);
}

void	move_player(t_cub *game)
{
	float	cos_angle;
	float	sin_angle;

	move_player_rotate(game);
	cos_angle = cos(game->player.angle);
	sin_angle = sin(game->player.angle);
	move_player_direction(game, cos_angle, sin_angle);
}
