/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:03:14 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/14 18:47:27 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_pixels_to_buffer(t_cub *game, int *buffer, t_img *tmp)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->txtinf.tex_height)
	{
		x = 0;
		while (x < game->txtinf.tex_width)
		{
			buffer[y * game->txtinf.tex_width + x]
				= ((int *)tmp->data)[y * (tmp->size_line / 4) + x];
			x++;
		}
		y++;
	}
}

static int	*xpm_to_pixels(t_cub *game, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		endian;

	tmp.image = mlx_xpm_file_to_image(game->mlx, path,
			&game->txtinf.tex_width, &game->txtinf.tex_height);
	if (!tmp.image)
		exit(err_msg(path, "Failed to load XPM file. Is it valid?", 1));
	tmp.data = mlx_get_data_addr(tmp.image, &tmp.bpp,
			&tmp.size_line, &endian);
	if (!tmp.data)
		exit(err_msg(path, "Failed to get texture data address.", 1));
	buffer = ft_calloc(game->txtinf.tex_width * game->txtinf.tex_height,
			sizeof(int));
	if (!buffer)
		exit(err_msg(NULL, ERR_MALLOC, 1));
	copy_pixels_to_buffer(game, buffer, &tmp);
	mlx_destroy_image(game->mlx, tmp.image);
	return (buffer);
}

void	init_textures(t_cub *game)
{
	game->textures = ft_calloc(5, sizeof(int *));
	if (!game->textures)
		exit(err_msg(NULL, ERR_MALLOC, 1));
	game->textures[NORTH] = xpm_to_pixels(game, game->txtinf.north);
	game->textures[SOUTH] = xpm_to_pixels(game, game->txtinf.south);
	game->textures[EAST] = xpm_to_pixels(game, game->txtinf.east);
	game->textures[WEST] = xpm_to_pixels(game, game->txtinf.west);
}
