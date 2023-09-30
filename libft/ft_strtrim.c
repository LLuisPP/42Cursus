/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 06:33:40 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/30 13:03:30 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		start;
	int		end;
	int		s;
	char	*ret;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	while (set[j] != '\0')
		j++;
	s = j;
	while (s1[i] != '\0')
	{                    
		if (s1[i] != set[j])
		{
			while (j >= 0)
			{
				if (s1[i] == set[j])
				{
					end = i;
					break ;
				}
				j--;
			}
		}
		j = s;
		i++;
	}
	while (s1[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s1[i] != set[j])
		{
			while (j >= s)
			{
				if (s1[i] == set[j])
				{
					start = i;
					break ;
				}
			}
			j--;
		}
		j = s;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * (200));
	if (!ret)
		return ((char *) 0);
	i = 0;
	while (i <= end - start)
	{
		ret[i] = s1[start];
		i++;
		start++;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	ft_strtrim(argv[1], argv[2]);
	printf("ft_strtim: %s \n", ft_strtrim(argv[1], argv[2]));
	return (0);
}
