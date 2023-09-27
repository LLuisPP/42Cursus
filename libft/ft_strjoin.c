/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:58:20 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/27 13:37:09 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	int 	i;
	char	*str;

	s = 0;
	l = 0;
	while (s1[x] != '\0')
		s++;
	while (s2[y] != '\0')
		l++;
	str = (char *)malloc((sizeof(*s1) + sizeof(*s2)) + 1);
	if (!str)
		return ((char *) 0);
	while (i < (x + y))
	{
		if (i < x)
		{
			str[i] = s1[0];
			i++;
		}
		else if (i < (s + l))
		{
			str[i] = s2[0]
		}
	}
}

/*int	main(int argc, char **argv)
{
	if (argc != 3)
	   return (0);
	ft_strjoin(argv[1], argv[2]);
	char *resultado_ft_strjoin = ft_strjoin(argv[1], atoi(argv[2]), atoi(argv[3]));
	printf("ft_memset:%s \n", resultado_ft_strjoin);
	return (0);
}*/
