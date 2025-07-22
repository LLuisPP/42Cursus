/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:15:02 by flperez-          #+#    #+#             */
/*   Updated: 2025/07/14 11:18:16 by flperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	assign_texture(char **dest, char *src_line)
{
	if (*dest)
		return (err_msg(NULL, ERR_DUP_TEXTURE_ID, 1));
	*dest = ft_strtrim(src_line, " \t\n");
	if (!(*dest))
		exit(err_msg(NULL, ERR_MALLOC, 1));
	return (0);
}

int	process_texture_line(t_cub *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (assign_texture(&game->txtinf.north, line + 3));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (assign_texture(&game->txtinf.south, line + 3));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (assign_texture(&game->txtinf.west, line + 3));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (assign_texture(&game->txtinf.east, line + 3));
	return (2);
}

static int	*get_rgb_from_line(char *value)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		i;
	char	*trimmed_value;

	trimmed_value = ft_strtrim(value, " \t\n");
	if (!trimmed_value)
		exit(err_msg(NULL, ERR_MALLOC, 1));
	rgb_to_convert = ft_split(trimmed_value, ',');
	free(trimmed_value);
	i = 0;
	while (rgb_to_convert && rgb_to_convert[i])
		i++;
	if (i != 3)
		return (NULL);
	rgb = (int *)malloc(sizeof(int) * 3);
	if (!rgb)
		exit(err_msg(NULL, ERR_MALLOC, 1));
	i = -1;
	while (++i < 3)
		rgb[i] = ft_atoi(rgb_to_convert[i]);
	free_tab((void **)rgb_to_convert);
	return (rgb);
}

int	process_color_line(t_cub *game, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (game->txtinf.floor)
			return (err_msg(NULL, ERR_DUP_FLOOR_COLOR, 1));
		game->txtinf.floor = get_rgb_from_line(line + 2);
		if (!game->txtinf.floor)
			return (err_msg(NULL, ERR_COLOR_FLOOR, 1));
		return (0);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (game->txtinf.ceiling)
			return (err_msg(NULL, ERR_DUP_CEILING_COLOR, 1));
		game->txtinf.ceiling = get_rgb_from_line(line + 2);
		if (!game->txtinf.ceiling)
			return (err_msg(NULL, ERR_COLOR_CEILING, 1));
		return (0);
	}
	return (2);
}
