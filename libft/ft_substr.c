/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:56:49 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/05 11:47:34 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	if (i <= start)
		len = 0;
	else if ((len + start) >= i)
		len = i - start;
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(int argc, char **argv)
{
	if (argc != 4)
	   return (0);
	char *resultado_ft_substr = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
	printf("ft_substr: %s \n", resultado_ft_substr);
	free(resultado_ft_substr);
	return (0);	
}*/
