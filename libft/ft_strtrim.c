/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 06:33:40 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/03 12:12:39 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	fend(char const *s1, char const *set)
{
	int	f;

	f = 0;
	while (s1[f] != '\0')
		f++;
	while (s1[f] != '\0' && f > 0)
	{
		printf("1");
		while (*set != '\0')
		{
			printf("2");
			if (s1[f] == *set)
			{
				f--;
				printf("3");
			}
			else
				printf("4");
				return (f);
			set++;
		}
		f--;
	}
	return (f);
}

int static	fstart(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && *set != '\0')
	{
		printf("A"
		while (*set != '\0')
		{
			if (s1[i] == *set)
				i++;
			else
				return (i);
			set++;
		}
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		c;
	int		i;
	int		f;
	char	*ret;

	c = 0;
	f = fend(s1, set);
	printf("F %d:", f);
	i = fstart(s1, set);
	printf("I %d:", i);
	if (!s1 || !set)
		return (0);
	ret = (char *)malloc(sizeof(char) * (f - i) + 1);
	if (!ret)
		return (NULL);
	while (i <= f)
	{
		ret[c] = s1[i];
		c++;
		i++;
	}
	ret[c] = '\0';
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("ft_strtim array output: %s \n", ft_strtrim(argv[1], argv[2]));
	return (0);
}
