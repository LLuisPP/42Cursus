/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:28:07 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/12 13:12:53 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_spawn_angle(char dir)
{
	if (dir == 'N')
		return (3 * PHI / 2);
	if (dir == 'S')
		return (PHI / 2);
	if (dir == 'E')
		return (0);
	if (dir == 'W')
		return (PHI);
	return (-1);
}

void	find_player_start(t_cub *game)
{
	int		y;
	int		x;
	float	angle;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			angle = get_spawn_angle(game->map[y][x]);
			if (angle != -1)
			{
				game->player.x = x;
				game->player.y = y;
				game->player.angle = angle;
				return ;
			}
			x++;
		}
		y++;
	}
	ft_putstr_fd("Error\nPlayer start position not found.\n", 2);
	exit(1);
}

void	init_player(t_player *player)
{
	player->x = player->x * BLK + BLK / 2;
	player->y = player->y * BLK + BLK / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

int	key_press(int keycode, t_cub *game)
{
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == D)
		game->player.key_right = true;
	if (keycode == LEFT)
		game->player.left_rotate = true;
	if (keycode == RIGHT)
		game->player.right_rotate = true;
	if (keycode == ESC)
		close_window(game);
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}
