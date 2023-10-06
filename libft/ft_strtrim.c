/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 06:33:40 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/06 12:41:59 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fend(char const *s1, char const *set, int start)
{
	int	f;
	int	k;
	int	b;

	f = 0;
	b = 0;
	while (s1[f] != '\0')
		f++;
	while (f > start && b == 0)
	{
		k = 0;
		while (s1[f] != set[k] && set[k] != '\0')
		{
			b = 1;
			k++;
		}
		if (s1[f] == set[k] || s1[f] == '\0')
		{
			f--;
			b = 0;
		}
	}
	return (f);
}

static	int	fstart(char	const *s1, char	const *set)
{
	int	i;
	int	j;
	int	start;
	int	b;

	b = 0;
	i = 0;
	start = 0;
	while (s1[i] != '\0' && b == 0)
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
		{
			b = 1;
			j++;
		}
		if (s1[i] == set[j])
		{
			start++;
			b = 0;
		}
		i++;
	}
	return (start);
}

char	*fill(int f, int i, char const *s1)
{
	int		c;
	char	*ret;

	c = 0;
	ret = (char *)malloc(sizeof(char) * (f - i) + 2);
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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		f;
	int		p;

	p = 0;
	f = 0;
	if (!s1 || !set)
		return (0);
	while (set[p] != '\0')
		p++;
	if (p == 0)
	{
		i = 0;
		while (s1[f] != '\0')
			f++;
	}
	else
	{
		i = fstart(s1, set);
		f = fend(s1, set, i);
	}
	return (fill(f, i, s1));
}

/*int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("ft_strtim array output:'%s' \n", ft_strtrim(argv[1], argv[2]));
	return (0);
}*/
