/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:34:31 by flperez-          #+#    #+#             */
/*   Updated: 2025/07/12 21:08:46 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	find_biggest_len(char **file, int i)
{
	size_t	biggest_len;
	size_t	current_len;

	biggest_len = 0;
	while (file[i])
	{
		current_len = ft_strlen(file[i]);
		if (current_len > 0 && file[i][current_len - 1] == '\n')
			current_len--;
		if (current_len > biggest_len)
			biggest_len = current_len;
		i++;
	}
	return (biggest_len);
}

int	allocate_map_rows(t_cub *game, int height)
{
	game->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!game->map)
		return (err_msg(NULL, ERR_MALLOC, 1));
	return (0);
}

int	fill_map_row(char *dest, char *src, int width)
{
	int	j;

	j = 0;
	while (j < width && src[j] && src[j] != '\n')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < width)
		dest[j++] = ' ';
	dest[width] = '\0';
	return (0);
}

int	create_map(t_cub *game, char **file, int start_index)
{
	int	height;
	int	width;
	int	i;

	height = 0;
	while (file[start_index + height])
		height++;
	width = find_biggest_len(file, start_index);
	if (allocate_map_rows(game, height))
		return (1);
	i = 0;
	while (i < height)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (width + 1));
		if (!game->map[i])
			return (err_msg(NULL, ERR_MALLOC, 1));
		fill_map_row(game->map[i], file[start_index + i], width);
		i++;
	}
	game->map[i] = NULL;
	return (0);
}
