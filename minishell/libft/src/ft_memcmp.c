/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:49:58 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/22 12:13:06 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*spos1;
	unsigned char	*spos2;

	spos1 = (unsigned char *) s1;
	spos2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((i < n) && (spos1[i] - spos2[i] == 0))
		i++;
	if (i == n)
		return (spos1[i -1] - spos2[i - 1]);
	return (spos1[i] - spos2[i]);
}

/*int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	printf("ft_memcmp:%d \n", ft_memcmp(argv[1], argv[2], atoi(argv[3])));
	printf("memcmp:%d", memcmp(argv[1], argv[2], atoi(argv[3])));
//	printf("memcmp:%d", memcmp(NULL, NULL, 0));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: copara byte a byte dos strings asumiendo que ambos tienen
 *  n bytes de longitud.
 * INPUT: string 1, string 2 y un entero que indica el tamano a comparar.
 * MAKE: recorre las posiciones de ambos strings y resta los chars (valor) 
 * contenido mientras este sea cero. Si la resta nos da != 0 entonces ha
 * encontrado un valor diferente entre ellos.
 * OUTPUT: devuelve la diferencia de valor entre chars cuando encuentra
 * diferencia. Es decir, >0 o <0.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
