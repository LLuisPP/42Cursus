/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 23:37:25 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/11 23:53:04 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	free_config_resources(t_cub *game)
{
	if (game->txtinf.north)
		free(game->txtinf.north);
	if (game->txtinf.south)
		free(game->txtinf.south);
	if (game->txtinf.east)
		free(game->txtinf.east);
	if (game->txtinf.west)
		free(game->txtinf.west);
	if (game->txtinf.floor)
		free(game->txtinf.floor);
	if (game->txtinf.ceiling)
		free(game->txtinf.ceiling);
}

static void	free_texture_data(t_cub *game)
{
	if (game->textures)
	{
		if (game->textures[NORTH])
			free(game->textures[NORTH]);
		if (game->textures[SOUTH])
			free(game->textures[SOUTH]);
		if (game->textures[EAST])
			free(game->textures[EAST]);
		if (game->textures[WEST])
			free(game->textures[WEST]);
		free(game->textures);
	}
}

void	free_all_resources(t_cub *game)
{
	free_config_resources(game);
	if (game->map)
		free_tab((void **)game->map);
	free_texture_data(game);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
