/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:55:18 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/02 11:14:56 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *) src;
	d = (unsigned char *) dst;
	if ((n > 0) && (dst == NULL && src == NULL))
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	char *resultado_ft_memcpy = ft_memcpy(argv[1], argv[2], atoi(argv[3]));
	char *resultado_memcpy = memcpy(argv[1], argv[2], atoi(argv[3]));
	printf("ft_memcpy:%s \n", resultado_ft_memcpy);
	printf("memcpy:%s", resultado_memcpy);
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: copia n bytes del array source en el array destino. Si se
 * superponen, el comportamiento esta undefined.
 * INPUT: string destino, string origen y un entero que indica el no de bytes.
 * MAKE: recorre el array de destino, escribiendo en cada posicion los bytes
 * que estan contenidos en destino.
 * OUTPUT: devuelve el array de destino modificado o no segun los inputs.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
