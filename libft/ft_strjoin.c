/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:58:20 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/12 07:07:34 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_string(const char *s1, const char *s2, char *str)
{
	int		y;
	int		i;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
	{
		str[i] = s2[y];
		i++;
		y++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[x] != '\0')
		x++;
	while (s2[y] != '\0')
		y++;
	str = (char *)malloc(sizeof(*s1) * (x + y + 1));
	if (!str)
		return (NULL);
	fill_string(s1, s2, str);
	str[x + y] = '\0';
	return (str);
}

/*int	main(int argc, char **argv)
{
	char	*resultado;

	if (argc != 3)
		return (0);
	resultado = ft_strjoin(argv[1], argv[2]);
	ft_strjoin(argv[1], argv[2]);
	printf("ft_strjoin: %s \n", resultado);
	return (0);
}*/
/* ************************************************************************** *
 *								FT_STRJOIN
 *
 * DESCRIPCION:	se utiliza para combinar dos cadenas en una nueva cadena
 *
 * INPUT:	const char *s1, const char *s2, char *str
 *
 * MAKE:	recorre ambos arrays para obtener las longitudes de ambos, esto
 * se emplea para crear un malloc que contenga a ambos strings consecutivos
 * mas una posicion mas para el '\0'
 *
 * OUTPUT:	devuelve un nuevo array que contiene los dos iniciales mas el '\0'
 * final.
 *
 * ***************************************************************************/
