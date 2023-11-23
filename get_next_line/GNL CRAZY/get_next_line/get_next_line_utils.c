/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feaguila <feaguila@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:08:30 by feaguila          #+#    #+#             */
/*   Updated: 2023/11/08 12:29:29 by feaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_get_strlen(char *buffer)
{
	size_t	len;

	if (!buffer || buffer < 0)
		return (0);
	len = 0;
	while (buffer[len] != '\0')
		len++;
	return (len);
}

char	*ft_get_strchr(char *buffer, int c)
{
	int	i;

	i = 0;
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == (char)c)
			return ((char *)&buffer[i]);
		i++;
	}
	if (buffer[i] == (unsigned char) c)
		return ((char *)&buffer[i]);
	return (0);
}

char	*ft_get_strjoin(char *buffer, char *newbuffer)
{
	size_t	i;
	size_t	j;
	char	*buffer_join;

	if (!buffer)
	{
		buffer = ft_malloc(1, 0);
		if (!buffer || !newbuffer)
			return (free(buffer), buffer = NULL, NULL);
		buffer[0] = '\0';
	}
	i = ft_get_strlen(buffer);
	j = ft_get_strlen(newbuffer);
	buffer_join = ft_malloc(i, j);
	if (!buffer_join)
		return (free(buffer), buffer = NULL, NULL);
	i = -1;
	j = -1;
	while (buffer[++i] != '\0')
		buffer_join[i] = buffer[i];
	while (newbuffer[++j] != '\0')
		buffer_join[i++] = newbuffer[j];
	// return (buffer_join[i] = '\0', free(buffer), buffer_join);
	return (free(buffer), buffer_join);
}

char	*ft_read_line(char *buffer)
{
	size_t	i;
	char	*newbuffer;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i++] == '\n')
			break ;
	}
	newbuffer = ft_malloc(i, 0);
	if (!newbuffer)
		return (NULL);
	i = -1;
	while (buffer[++i] != '\0' && buffer[i] != '\n')
		newbuffer[i] = buffer[i];
	if (buffer[i] == '\n')
		newbuffer[i++] = '\n';
	// return (newbuffer[i] = '\0', newbuffer);
	return (newbuffer);
}

char	*ft_new_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*newbuffer;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), buffer = NULL, NULL);
	newbuffer = ft_malloc(ft_get_strlen(buffer), 0);
	if (!newbuffer)
		return (free(buffer), buffer = NULL, NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		newbuffer[j++] = buffer[i++];
	return (newbuffer[j] = '\0', free(buffer), buffer = NULL, newbuffer);
	// return (free(buffer), buffer = NULL, newbuffer);
}
