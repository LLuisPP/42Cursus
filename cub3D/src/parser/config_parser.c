/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:34:02 by flperez-          #+#    #+#             */
/*   Updated: 2025/07/11 11:34:16 by flperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	process_config_line(t_cub *game, char *line)
{
	int	ret;

	ret = process_texture_line(game, line);
	if (ret != 2)
		return (ret);
	ret = process_color_line(game, line);
	if (ret != 2)
		return (ret);
	return (err_msg(NULL, ERR_INVALID_LINE, 1));
}

int	get_file_data(t_cub *game, char **file)
{
	int	i;
	int	map_started;

	i = 0;
	map_started = 0;
	while (file[i] && !map_started)
	{
		if (process_line(game, file[i], &map_started) != 0)
			return (1);
		i++;
	}
	if (!map_started)
		return (err_msg(NULL, ERR_MAP_NOT_FOUND, 1));
	return (create_map(game, file, i - 1));
}

int	process_line(t_cub *game, char *line, int *map_started)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n' || line[i] == '#')
		return (0);
	if (line[i] == '1' || line[i] == '0')
	{
		*map_started = 1;
		return (0);
	}
	return (process_config_line(game, &line[i]));
}
