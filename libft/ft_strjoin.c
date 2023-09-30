/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:58:20 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/29 07:08:21 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	int		i;
	char	*str;

	x = 0;
	y = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[x] != '\0')
		x++;
	while (s2[y] != '\0')
		y++;
	str = (char *)malloc(sizeof(*s1) * (x + y + 1));
	if (!str)
		return (NULL);
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