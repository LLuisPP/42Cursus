/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:08:14 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/20 18:54:24 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("ft_strlen:%zu \n", ft_strlen(argv[1]));
	printf("strlen:%zu", strlen(argv[1]));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: la funcion recorre el array que recibe como parametro de
 *  entrada y genera un contador que nos indica la longitud del mismo.
 * INPUT: string
 * MAKE: recorre el arrai de entrada y almacena la longitud de este.
 * OUTPUT: contador con la logitud el array introducido.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
