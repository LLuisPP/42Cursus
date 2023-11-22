/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:29:54 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/22 22:35:30 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if(!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *) &str[i]);
		i++;
	}
	printf("StrChr -------> F >\n");

	return (NULL);
}
/* ************************************************************************** */
char    *ft_strjoin(char *str, char *buffer)
{
    int        x;
    int        y;
    char    *new_str;

    x = 0;
    y = 0;
    if (!str)
    {
        str = ft_malloc(1, 0);
        str[0] = '\0';
    }
    new_str = ft_malloc(ft_strlen(str), ft_strlen(buffer));
    while (str[x] != '\0')
      {
        new_str[x] = str [x];
      	x++;
      }
    while (buffer[y] != '\0')
        new_str[x++] = buffer[y++];

	printf("StrJoin -------> F >\n");

    return (new_str);
}
/* ************************************************************************** */
char	*ft_read_line(char *str)
{
	size_t	i;
	char	*new_str;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\0')
			break ;
	}
	new_str = ft_malloc(i, 0);
	i = -1;
	while (str[++i] != '\0' && str[i] != '\n')
		new_str[i] = str[i];
	if (str[i] == '\n')
		new_str[i++] = '\n';
	// new_str[i] = '\0';
	return (new_str);
}

char	*ft_new_line(char *TotalBuffer)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	while ((TotalBuffer && TotalBuffer[i] != '\n') && (TotalBuffer[i] != '\0'))
		i++;
	new_str = ft_malloc(i + 1, 0);
	
	i++;

	j = 0;
	while (TotalBuffer && TotalBuffer[i] != '\n' && TotalBuffer[i] != '\0')
		new_str[j++] = TotalBuffer[i++];

	return (new_str);
}