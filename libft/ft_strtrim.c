/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 06:33:40 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/05 10:02:26 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	fend(char const *s1, char const *set)
{
	int	f;

	f = 0;
	while (s1[f] != '\0')
		f++;
	printf("%d:", f);
	while (f > 0 && s1[f] != '\0')
	{
		printf("1 \n");
		while (*set != '\0')
		{
			printf("2\n");
			if (s1[f] == *set)
			{
				f--;
				printf("resto f\n");
			}
			else
			{
				printf("4\n");
				return (f);
			}
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
		printf("A\n");
		while (*set != '\0')
		{
			printf("B\n");
			if (s1[i] != *set)
				return (i);
			set++;
		}
		i++;
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
	printf("F: %d\n", f);
	i = fstart(s1, set);
	printf("I: %d\n", i);
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
