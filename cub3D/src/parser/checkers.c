/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:10:10 by lprieto-          #+#    #+#             */
/*   Updated: 2025/07/12 21:06:22 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_file_lines(const char *map_file)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit(err_msg((char *)map_file, strerror(errno), 1));
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static char	**read_file_content(const char *map_file, int line_count)
{
	int		fd;
	char	*line;
	char	**file_content;
	int		i;

	file_content = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!file_content)
		exit(err_msg(NULL, ERR_MALLOC, 1));
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit(err_msg((char *)map_file, strerror(errno), 1));
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		file_content[i++] = line;
		line = get_next_line(fd);
	}
	file_content[i] = NULL;
	close(fd);
	return (file_content);
}

void	parse_map(char *map_file, t_cub *game)
{
	char	**file_content;
	int		line_count;

	line_count = count_file_lines(map_file);
	file_content = read_file_content(map_file, line_count);
	if (get_file_data(game, file_content) != 0 || check_map_validity(game))
	{
		free_tab((void **)file_content);
		exit(1);
	}
	game->txtinf.hex_floor = rgb_to_hex(game->txtinf.floor);
	game->txtinf.hex_ceiling = rgb_to_hex(game->txtinf.ceiling);
	free_tab((void **)file_content);
}

int	err_msg(char *detail, char *str, int code)
{
	ft_putstr_fd("Error\n", 2);
	if (detail)
	{
		ft_putstr_fd(detail, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (code);
}
