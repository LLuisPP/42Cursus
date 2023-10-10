/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:15:07 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/10 09:19:16 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	wcount(char	const *s1, char	const set)
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

void	bucle(start, s1)
{
	while (wcount())
		wcount (start)
		fwriteword(start)
}

char	**ft_split(char const *s, char c)
{
	char	*dest;
	int		len;

	if (!s || !c)
		return (NULL);
	len = word_len(argv[1], argv[2]);
	dest = (char *)malloc(sizeof(char) * (len) + 1);
	if (!dest)
		return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("splitted strings %p", ft_split(argv[1], argv[2]));
	return (0);
}
