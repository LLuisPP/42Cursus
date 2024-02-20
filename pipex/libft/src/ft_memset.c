/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:58:25 by lprieto-          #+#    #+#             */
/*   Updated: 2024/01/23 08:44:53 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *) b;
	while (i < len)
	{
		*p = (unsigned char)c;
		p++;
		i++;
	}
	return (b);
}

/*int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	char *res_ft_memset = ft_memset(argv[1], atoi(argv[2]), atoi(argv[3]));
	char *resultado_memset = memset(argv[1], atoi(argv[2]), atoi(argv[3]));
	printf("ft_memset:%s \n", res_ft_memset);
	printf("memset:%s", resultado_memset);
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: esltablece un bloque de memoria con un valor especifico del
 * numero de posiciones integuer que recibe.
 * INPUT: un string, un char y un entero que indica el no de posiciones.
 * MAKE: reserva un numero de posiciones del string puntero que recibe y lo
 * llena de tantos caracteres como posiciones de memoria le indiquemos con el
 * entero.
 * OUTPUT: devuelve un puntero sin tipo apuntando a la ultima posicion que
 * ha completado con los caracteres que le pasamos.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
