/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:12:48 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/22 12:19:06 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_malloc(size_t len1, int len2)
{
	char	*mallocated;
	size_t	len;

	len = len1 + len2;
	mallocated = (char *)malloc(sizeof(char) * (len + 1));
	if (!mallocated)
		return (NULL);
	return (mallocated);
}

char	*ft_read(int fd, char *str)
{
	char		*buffer;
	size_t		nb_read;

	buffer = ft_malloc(BUFFER_SIZE, 0);
	nb_read = read(fd, buffer, BUFFER_SIZE);
	printf("%s", buffer);
	if (nb_read < 0)
	{
		free(buffer);
		return(NULL);
	}
	
	buffer[nb_read] = '\0';
		// str = ft_strjoin(str, buffer);
		free(buffer);
		return(str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = 0;
	line = 0;
	str = ft_read(fd, str);
	line = ft_read(fd, line);
	printf("%s", str);
	if (!str)
		return (free(str), str = NULL, NULL);
	if (!line)
		return (free(line), line = NULL, NULL);
//	str = ft_new_line(str);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("punkmanifesto.txt", O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0)
		return (0);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
