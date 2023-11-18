/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:12:48 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/18 12:32:37 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int	nb_read;

	buffer = ft_malloc(BUFFER_SIZE, 0);
	nb_read = 1;
	if (!buffer)
		return (free(str), str = NULL, NULL);
	while (nb_read > 0 && !ft_strchr(str, '\n'))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read > 0)
		{
			buffer[nb_read] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	free(buffer);
	if (nb_read < 0)
		return (free(str), str = NULL, NULL);
	return (str);
}

char *get_next_line(int fd)
{
	char	*str;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = 0;
	str = ft_read(fd, str);
	line = ft_read(fd, str);
	if (!str)
		return (free(str), str = NULL, NULL);
	if (!str)
		return (free(str), str = NULL, NULL);
	str = ft_new_line(str);
	return (line);
}

int main (void)
{
	int		fd;
	char	*line;

	fd = open("punkmanifesto.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
