/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:08:05 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/24 11:33:21 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (src[i] != '\0')
	i++;
	while (src[k] != '\0')
	{
		if (k == dstsize)
			break;
		dst[k] = src[k];
		k++;
	}
	while (dst[k] != '\0')
	{
		dst[k] = '\0';
		k++;
	}
	return (i);	
}

/*int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	printf("ft_strlcpy:%zu \n", ft_strlcpy(argv[1], argv[2], atoi(argv[3])));
	printf("strlcpy:%zu", strlcpy(argv[1], argv[2], atoi(argv[3])));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: copia n bytes del array source en el array destino. Si se
 * superponen.
 * INPUT: string destino, string origen y un entero que indica el no de bytes.
 * MAKE: recorre el array de destino, escribiendo en cada posicion los bytes
 * que estan contenidos en destino.
 * OUTPUT: devuelve el array de destino modificado o no segun los inputs.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
