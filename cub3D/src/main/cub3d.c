/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:42:31 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/17 21:57:34 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_filename(char *filename)
{
	int	len;

	if (!filename)
		return (1);
	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (ft_strcmp(&filename[len - 4], ".cub") != 0)
		return (1);
	return (0);
}

void	init_game(t_cub *game, char *map_file)
{
	parse_map(map_file, game);
	find_player_start(game);
	init_player(&game->player);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D-True_North");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_line, &game->endian);
	init_textures(game);
}

int	main(int argc, char **argv)
{
	t_cub	game;
	char	*map_path;

	if (argc != 2)
		return (err_msg(NULL, ERR_INVALID_ARGS, 1));
	if (check_filename(argv[1]) != 0)
		return (err_msg(NULL, ERR_FILE_NOT_CUB, 1));
	ft_bzero(&game, sizeof(t_cub));
	map_path = ft_strjoin("src/map/", argv[1]);
	if (!map_path)
		return (err_msg(NULL, ERR_MALLOC, 1));
	init_game(&game, map_path);
	free(map_path);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L >> 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game.player);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	free_all_resources(&game);
	return (0);
}
