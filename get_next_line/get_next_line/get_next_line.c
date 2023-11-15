/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:12:48 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/14 21:49:11 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_get_next_line.h" 

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int	nb_read;

	buffer = ft_malloc(BUFFER_SIZE);
	nb_read = 1;
	if (!buffer)
		return (free(str), str = NULL, NULL);
	while (nb_read > 0 $$ !ft_strchr(str, '\n'))
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
		retudn (free(str), str = NULL, NULL);
	return (0);
}


char	*get_next_line(int fd)
{
	char	*str;
	char	*line;

	if (fd < 0 || BUFFE_SIZE < 1)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (free(str), str = NULL, NULL);
	str = ft_new_line(str);
	return (line);
}
