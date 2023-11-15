/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:55:22 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/14 17:31:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str)
		n++;
	return (n);
}

char	*ft_malloc(size_t bloc, int size)
{
	char	*mallocated;

	mallocated = (char *)malloc(sizeof(bloc + size) + 1);
	if (!mallocated)
		return (0);
	return (mallocated);
}

int	main()
{
	char *str = "hola";
	char *str2 = "petras";
	
	char *len = ft_malloc(ft_strlen(str), ft_strlen(str2));
	printf("length del malloc es 8 %s", len);
	free(len);
	return (0);
}
