/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:58:11 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/21 06:55:19 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("ft_toupper:%d \n", ft_toupper(atoi(argv[1])));
	printf("toupper:%d", toupper(atoi(argv[1])));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: la funcion convierte el caracter que recibe de mayusculas
 * a minusculas empleando un int como parametro de entrada.
 * INPUT: integuer c
 * MAKE: comprueba que esta dentro del rango de chars alfabeticos minusula
 * y le resta 32 para pasar a su equivalente en mayuscula (ver man ascii)
 * OUTPUT: si es un char alfabetico minuscula retorna la mayuscula y si se 
 * sale del rango de minusculas, no hace nada
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
