/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:29:54 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/22 13:51:15 by lprieto-         ###   ########.fr       */
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
	if (str[i] == (unsigned char) c)
		return ((char *) &str[i]);
	return (0);
}

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
    new_str[x] = '\0';
    free(str);
    printf("%s", new_str);
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
printf("VALOR STRNEW LINE>%s", str);
	i = 0;
	while ((str && str[i] != '\n') || (str[i] != '\0'))
		i++;
	new_str = ft_malloc(i + 1, 0);

	i = 0;
	j = 0;
	while (str[i] != '\n')
		new_str[j++] = str[i++];
	new_str[j + 1] = '\0';
printf("VALOR NEW_STRNEW LINE>%s", new_str);
	return (new_str);
}
