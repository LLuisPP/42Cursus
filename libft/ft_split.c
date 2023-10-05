/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:15:07 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/04 06:53:36 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_len(char *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
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
