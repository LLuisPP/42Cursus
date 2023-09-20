/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:49:36 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/20 13:01:55 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("ft_isalnum:%d \n", ft_isalnum(atoi(argv[1])));
	printf("isalnum:%d", isalnum(atoi(argv[1])));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: la funcion convierte determina si el caracter que recibe
 * como parametro de entrada es alfabetico o numerico.
 * INPUT: integuer c
 * MAKE: comprueba que esta dentro del rango de chars alfabeticos minusula
 * alfabeticos mayuscula o numeros (ver man ascii)
 * OUTPUT: si es un char alfabetico minuscula, mayuscula o numero retorna
 * 1, si se sale de dicho rango retorna 0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
