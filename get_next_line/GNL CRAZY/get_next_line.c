/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:12:48 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/22 22:37:50 by lprieto-         ###   ########.fr       */
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
/* ************************************************************************** */
char	*ft_malloc(size_t len1, int len2)
{
	char	*mallocated;
	size_t	len;

	len = len1 + len2;
	mallocated = (char *)malloc(sizeof(char) * (len + 1));
	if (!mallocated)
		return (NULL);
	mallocated[len] = '\0';
	mallocated[0] = 'a';
	return (mallocated);
}

char	*ft_read(int fd, char *str)
{
	char		*buffer;
	size_t		nb_read;
	
	nb_read = 1;

	buffer = ft_malloc(BUFFER_SIZE, 0);
		
	while (nb_read > 0 && !ft_strchr(str, '\n'))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		printf("ABSOLUTE BUFFER READ ---> %zu\n", nb_read);
		if (nb_read > 0)
		{

			buffer[nb_read] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	printf("BUFFER READ ---> %s\n", buffer);
free(buffer);
	if (nb_read < 0)
		return(NULL);
	return(str);
}

char	*get_next_line(int fd)
{
	static char	*TotalBuffer;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	// str = 0;
	TotalBuffer = ft_read(fd, TotalBuffer);
	// printf("TotalBuffer   G N L ---> %s\n", TotalBuffer);
	line = ft_new_line(TotalBuffer);

	printf("L I N E   G N L ---> %s\n", line);

	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

fd = open("punkmanifesto.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	count = 1;
	fd = open("punkmanifesto.txt", O_RDONLY);
	line = get_next_line(fd);
	
	while (line != NULL)
	{
		printf("LINE [%d] - %s\n", count, line);
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
