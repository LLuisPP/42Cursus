/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:04:31 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/20 15:09:18 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("ft_tolower:%d \n", ft_tolower(atoi(argv[1])));
	printf("tolower:%d", tolower(atoi(argv[1])));
	return(0);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: la funcion convierte el caracter que recibe de mayus a min
 * empleando un int como parametro de entrada.
 * INPUT: integuer c
 * MAKE: comprueba que esta dentro del rango de chars alfabeticos mayuscula
 * y le suma 32 para pasar a su equivalente en minuscula (ver man ascii)
 * OUTPUT: si es un char alfabetico minuscula retorna la mayuscula y si se
 * sale del rango de minusculas, no hace nada
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
