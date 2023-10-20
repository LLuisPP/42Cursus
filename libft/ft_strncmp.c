/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:17:05 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/12 07:18:24 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && *s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		i++;
		s1++;
		s2++;
	}
	return (((unsigned char) *s1 - (unsigned char) *s2));
}

/*int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	printf("ft_strncmp:%d \n", ft_strncmp(argv[1], argv[2], atoi(argv[3])));
	printf("strncmp:%d", strncmp(argv[1], argv[2], atoi(argv[3])));
	return(0);
}*/

/* ************************************************************************** *
 *								FT_STRNCMP
 *
 * DESCRIPCION:	se utiliza para comparar dos cadenas de caracteres hasta un
 * número determinado de caracteres o hasta que se encuentre un carácter nulo
 * en alguna de las cadenas
 *
 * INPUT:	const char *s1, const char *s2, size_t n
 *
 * MAKE:	comprueba caracteres por pares, en valor, de los strings hasta
 * encontrar la diferencia
 *
 * OUTPUT:	la diferencia de valor entre caracteres una vez que encuentre un
 * par que sean diferentes. Si es 0 la cantidad a comprar devuelve null
 *
 * ***************************************************************************/
