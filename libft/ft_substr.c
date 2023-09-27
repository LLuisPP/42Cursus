/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:56:49 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/27 11:49:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;

	str = (char *)malloc(sizeof(*s)*(len + 1));
	if (!str)
		return ((char *) 0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

/*int	main(int argc, char **argv)
{
	if (argc != 4)
	   return (0);
	ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
	char *resultado_ft_substr = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
	printf("ft_memset:%s \n", resultado_ft_substr);
	return (0);	
}*/
