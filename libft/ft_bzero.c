/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:01:02 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/21 12:07:45 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*int main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	char *ft_bzeroSTR;
	char *bzeroSTR;

	ft_bzeroSTR = argv[2];
	bzeroSTR = argv[1];

	printf("ft_bzero:%p \n", ft_bzero(ft_bzeroSTR, atoi(argv[2])));
	printf("bzero:%p", bzero(bzeroSTR, atoi(argv[2])));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: escribe ceros dentro del string que recibe como parametro de
 * entrada hasta el entero que tambien recibe.
 * INPUT: puntero sin tipo (string) y un integuer c
 * MAKE: llena el string con tantos ceros como le hayamos indicado en el int
 * OUTPUT: la funcion en si misma no retorna nada, pero se puede ver los cambios
 * que hace en el string original si lo dibujamos.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
