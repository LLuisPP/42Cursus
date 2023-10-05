/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:08:05 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/02 09:11:29 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize == 0)
		return (i);
	while (src[j] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
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
print_mem(argv[1], atoi(argv[3]));
print_mem(argv[1], atoi(argv[3]));
ft_strlcpy(argv[1], argv[2], atoi(argv[3]));
strlcpy(argv[1], argv[2], atoi(argv[3]));
print_mem(argv[1], atoi(argv[3]));
print_mem(argv[2], atoi(argv[3]));

//print_mem(argv[1], sizeof((char *)argv[2]));
//	ft_strlcpy(argv[1], argv[2], atoi(argv[3]));
//	printf("ft_strlcpy:%zu \n", ft_strlcpy(argv[1], argv[2], atoi(argv[3])));
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
