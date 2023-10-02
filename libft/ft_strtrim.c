/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 06:33:40 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/02 14:00:55 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	fend(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	while (set[j] != 0)
		j++;
	p = j;
	while (s1[i] != 0)
		i++;
	while (i >= 0)
	{
		j = p;
		while (j >= 0)
		{
			if (s1[i] != set[j])
				return (i);
			else
				j--;
		}
		i--;
	}
	return (i);
}

int static	fstart(char const *s1, char const *set)
{
	int	h;
	int	k;
/*	int	p*/

	h = 0;
	k = 0;
/*	while (set[k] != '\0')
		k++;
	p = k;
		printf("K fuera del while: %d \n", k);*/
	while (s1[h] != '\0')
	{
		/*k = p;
		printf("K reiniciado a P: %d \n", k);*/
		while (set[k] != '\0')
		{
			if (s1[h] == set[k])
			h++;
			if (s1[h] != set[k])
					k++;
			}
		return (h);
	}
		printf("en K: %d \n", k);
	return (h);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		c;
	int		i;
	int		f;
	char	*ret;

	c = 0;
	f = fend(s1, set);
	printf("final: %d \n", f);
	i = fstart(s1, set);
	printf("inici: %d \n", i);
	if (!s1 || !set)
		return (0);
	ret = (char *)malloc(sizeof(char) * (f - i) + 1);
	if (!ret)
		return (NULL);
	while (c <= (f - i) + 1)
	{
		ret[c] = s1[i];
		c++;
		i++;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("ft_strtim array output: %s \n", ft_strtrim(argv[1], argv[2]));
	return (0);
}
