/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:12:48 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/22 13:51:14 by lprieto-         ###   ########.fr       */
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
	{
		free(mallocated);
		return (NULL);
	}
	mallocated[len] = '\0';
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
	str = ft_strjoin(str, buffer);
	printf("READ PRINTF>%s", buffer);
	printf(">>%zu<<", nb_read);
	}
	if (nb_read < 0)
	{
		free(buffer);
		return(NULL);
	}
	printf("VALOR STRJOIN>%s", str);
	free(buffer);
	return(str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = 0;
	str = ft_read(fd, str);
	printf("GETNEXTLI PRINTF>%s", str);
	if (!str)
		return (NULL);

	str = ft_new_line(str);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 1;
	fd = open("punkmanifesto.txt", O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0)
		return (0);
	while (line != NULL)
	{
		printf("LINE %d - %s", count, line);
		free(line);
		count++;
	}
	close(fd);
	return (0);
}
