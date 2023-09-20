/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 07:18:09 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/20 20:24:53 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	if (n == 0)
		return ((char *) 0);
	while (i < n - 1)
	{
		if (str[i] == (unsigned char) c)
		{
			return (&str[i]);
		}
		i++;
	}
	if (str[i] == (unsigned char) c)
	{
		return (&str[i]);
	}
	return ((char *) 0);
}

/*int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	char *resultado_ft_memchr = ft_memchr(argv[1], atoi(argv[2]), atoi(argv[3]));
	char *resultado_memchr = ft_memchr(argv[1], atoi(argv[2]), atoi(argv[3]));
	printf("ft_memchr:%s \n", resultado_ft_memchr);
	printf("memchr:%s", resultado_memchr);
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: busca la primera aparicion de un char en un bloque de memoria
 * INPUT: un string, un char y un entero que indica el no de posiciones.
 * MAKE: busca la primera aparicion de un char y cuando lo encuentra, devuelve
 * el puntero sin tipo a esa posicion y como consecuencia escribe el resto del
 * string que se analiza hasta la posicion que le hemos indicado con el int.
 * OUTPUT: devuelve un puntero sin tipo apuntando a la posicion siguiente al
 * char que ha encontrado y dibujamos el string que resta hasta la posicion
 * indicada por el integuer que recibe como parametro.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
