/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:12:48 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/23 21:39:09 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *buffer)
{
	char	*new_buffer;
	int		nb_read;
	
	new_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nb_read = 1;
	if (!new_buffer)
		return (free(buffer), buffer = NULL, NULL);
	while (nb_read > 0 && !ft_strchr(buffer, '\n'))
	{
		nb_read = read(fd, new_buffer, BUFFER_SIZE);
		if (nb_read > 0)
		{
			new_buffer[nb_read] = '\0';
			buffer = ft_strjoin(buffer, new_buffer);
		}
	}
	free(new_buffer);
	if (nb_read < 0)
		return (free(buffer), buffer = NULL, NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = ft_read_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_new_line(buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		count;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	line = get_next_line(fd);
// 	count = 0;
// 	if(line)
// 		free(line);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("LINE [%d] - %s\n", count, line);
// 		free(line);
// 		count++;
// 	}
// 	close(fd);
// 	return (0);
// }

// int	main(void)
// {
// 	int		fd;
// 	int		count;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	line = get_next_line(fd);
// 	count = 0;
// 	while (line)
// 	{
// 		printf("LINE [%d] - %s", count, line);
// 		count++;
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	count = 1;
	line = get_next_line(fd);

	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("LINE [%d] - %s\n", count, line);
		count++;
		free(line);
	}
	close(fd);
	return (0);
}