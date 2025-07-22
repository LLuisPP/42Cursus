/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:34:56 by flperez-          #+#    #+#             */
/*   Updated: 2025/07/11 11:35:22 by flperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_unclosed(char **map, int i, int j)
{
	if (map[i - 1][j] == ' ' || map[i - 1][j] == '\t'
		|| map[i + 1][j] == ' ' || map[i + 1][j] == '\t'
		|| map[i][j - 1] == ' ' || map[i][j - 1] == '\t'
		|| map[i][j + 1] == ' ' || map[i][j + 1] == '\t')
		return (1);
	return (0);
}

static int	check_map_sides(char **map)
{
	int	i;
	int	j;
	int	height;

	height = 0;
	while (map[height])
		height++;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("0NSEW", map[i][j]))
			{
				if (i == 0 || i == height - 1 || j == 0 || !map[i][j + 1])
					return (1);
				if (is_unclosed(map, i, j))
					return (1);
			}
		}
	}
	return (0);
}

static int	check_map_elements(t_cub *game)
{
	int	i;
	int	j;
	int	player_found;

	i = -1;
	player_found = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (!ft_strchr("01NSEW ", game->map[i][j]))
				return (err_msg(NULL, ERR_INV_CHAR, 1));
			if (ft_strchr("NSEW", game->map[i][j]))
			{
				if (player_found)
					return (err_msg(NULL, ERR_TOO_MANY_PLAYERS, 1));
				player_found = 1;
			}
		}
	}
	if (!player_found)
		return (err_msg(NULL, ERR_NO_PLAYER, 1));
	return (0);
}

static int	check_all_configs_present(t_txtinf *txtinf)
{
	if (!txtinf->north || !txtinf->south || !txtinf->west
		|| !txtinf->east || !txtinf->floor || !txtinf->ceiling)
		return (1);
	return (0);
}

int	check_map_validity(t_cub *game)
{
	if (check_all_configs_present(&game->txtinf))
		return (err_msg(NULL, ERR_MISSING_CONFIG, 1));
	if (!game->map)
		return (err_msg(NULL, ERR_MAP_MISSING, 1));
	if (check_map_elements(game) != 0)
		return (1);
	if (check_map_sides(game->map) != 0)
		return (err_msg(NULL, ERR_MAP_NO_WALLS, 1));
	return (0);
}
