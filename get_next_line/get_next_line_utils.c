/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:29:54 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/22 11:52:02 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if(!str)
		return (free(str), str = NULL, NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == (unsigned char) c)
		return ((char *) &str[i]);
	return (0);
}

char	*ft_strjoin(char *str, char *buffer)
{
	int		x;
	int		y;
	char	*new_str;

	x = 0;
	y = 0;
	if (!str)
	{
		str = ft_malloc(1, 0);
		if (!str)
			return (free(str), str = NULL, NULL);
		str[0] = '\0';
	}
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	new_str = ft_malloc(ft_strlen(str), ft_strlen(buffer));
	if (!new_str)
		return (free(str), str = NULL, NULL);
	while (str[++x] != '\0')
		new_str[x] = str [x];
	while (buffer[y] != '\0')
		new_str[++x] = buffer[y++];
	free(str);
	new_str[x] = '\0';
	return (new_str);
}

char	*ft_read_line(char *str)
{
	size_t	i;
	char	*new_str;

	if (!str[0])
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\0')
			break ;
	}
	new_str = ft_malloc(i, 0);
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i] != '\0' && str[i] != '\n')
		new_str[i] = str[i];
	if (str[i] == '\n')
		new_str[i++] = '\n';
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_new_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), str = NULL, NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (free(str), str = NULL, NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	return (free(str), str = NULL, new_str);
}
