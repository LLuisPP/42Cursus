/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:36:42 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/24 13:21:57 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;
	size_t	comp;

	i = 0;
	nlen = 0;
	comp = 0;
	if (*needle == 0)
		return ((char *) haystack);
	while (*needle != '\0')
		nlen++;
	if (nlen == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && i < len)
	{
		
		while (haystack[comp + i] != '\0' && needle[comp + i] != '\0' 
			&& haystack[comp + i] == needle[comp + i])
		comp++;
		if (comp == len)
			return ((char *)(haystack + i));
		i++;
		comp = 0;
	}
	return (NULL);	
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	printf("ft_strnsrt:%s \n", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
	printf("strnstr:%s", strnstr(argv[1], argv[2], atoi(argv[3])));
	return(0);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: copia n bytes del array source en el array destino. Si se
 * superponen.
 * INPUT: string destino, string origen y un entero que indica el no de bytes.
 * MAKE: recorre el array de destino, escribiendo en cada posicion los bytes
 * que estan contenidos en destino.
 * OUTPUT: devuelve el array de destino modificado o no segun los inputs.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
