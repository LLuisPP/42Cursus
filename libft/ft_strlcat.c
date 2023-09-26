/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:31:00 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/26 15:36:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	j;
	size_t	s;

	d = 0;
	j = 0;
	s = 0;
	while (dst[d] != '\0')
		d++;
	while (src[s] != '\0')
		s++;
	if (dstsize == 0)
		return (s);
	while ((d + j) < (dstsize - 1) && src[j] != '\0')
	{
		dst[d + j] = src[j];
		j++;
	}
	dst[d + j] = '\0';
	if (d < dstsize)
		return (s + d);
	return (s + dstsize);
}

/*void print_mem(void *p, size_t n)
{
	size_t i;
	char *p_char;
	i = 0;
	p_char = (char *) p;
	while (i < n)
	{
		printf("|%c|", p_char[i]);
		i++;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
//argv[1]: dst ft
//argv[2]: dst std
//argv[3]: src both
//argv[4]: dstsize
//argv[5]: len strlcpy
//print_mem(argv[1], atoi(argv[4]));
//print_mem(argv[2], atoi(argv[4]));
	printf("strlcat:%zu \n", strlcat(argv[1], argv[2], atoi(argv[3])));
//	printf("ft_strlcat:%lu \n", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
//ft_strlcat(argv[1], argv[2], atoi(argv[3]));
//strlcat(argv[1], argv[2], atoi(argv[3]));
print_mem(argv[1], atoi(argv[3]));
print_mem(argv[1], atoi(argv[3]));

//print_mem(argv[1], sizeof((char *)argv[2]));
//	ft_strlcpy(argv[1], argv[2], atoi(argv[3]));
//	printf("ft_strlcat:%zu \n", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
//	printf("strlcpy:%zu", strlcpy(argv[1], argv[2], atoi(argv[3])));
//print_mem(argv[1], sizeof(argv[1]));
//print_mem(argv[1], sizeof(argv[2]));
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
