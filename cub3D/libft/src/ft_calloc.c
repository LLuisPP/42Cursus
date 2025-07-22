/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:17:30 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/26 14:31:14 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	rtn = malloc(size * count);
	if (!rtn)
		return (NULL);
	ft_bzero(rtn, size * count);
	return (rtn);
}

/*int main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	char *res_ft_calloc= ft_calloc(argv[1], atoi(argv[2]));
	char *resultado_memset = calloc(argv[1], atoi(argv[2]));
	printf("ft_calloc:%s \n", res_ft_calloc);
	printf("calloc:%s", resultado_calloc);
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
