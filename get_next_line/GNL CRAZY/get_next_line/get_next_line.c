/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:07:43 by feaguila          #+#    #+#             */
/*   Updated: 2023/11/23 12:32:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_malloc(size_t len1, size_t len2)
{
	char	*mallocated;
	size_t	len;

	if (SIZE_MAX - len1 < len2)
		return (NULL);
	len = len1 + len2;
	mallocated = (char *)malloc(sizeof(char) * (len + 1));
	if (!mallocated)
		return (NULL);
	mallocated[len] = '\0';
	return (mallocated);
}

static char	*ft_read_str(int fd, char *buffer)
{
	char	*newbuffer;
	int		nb_read;

	newbuffer = ft_malloc(BUFFER_SIZE, 0);
	nb_read = 1;
	if (!newbuffer)
		return (free(buffer), buffer = NULL, NULL);
	while (nb_read > 0 && !ft_get_strchr(buffer, '\n'))
	{
		nb_read = read(fd, newbuffer, BUFFER_SIZE);
		if (nb_read > 0)
		{
			newbuffer[nb_read] = '\0';
			buffer = ft_get_strjoin(buffer, newbuffer);
		}
	}
	if (nb_read < 0)
		return (free(newbuffer), free(buffer), buffer = NULL, NULL);
	return (free(newbuffer), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_read_str(fd, buffer);
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
// 	int		i;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		line = get_next_line(fd);
// 		printf("line [%02d]: %s\n", i, line);
// 		free (line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
