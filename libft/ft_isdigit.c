/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:02:27 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/20 12:16:16 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("ft_isdigit:%d \n", ft_isdigit(atoi(argv[1])));
	printf("isdigit:%d", isdigit(atoi(argv[1])));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: la funcion comprueba que el caracter que recibe sea un num
 * empleando un int como parametro de entrada.
 * INPUT: integuer c
 * MAKE: comprueba que esta dentro del rango de chars alfabeticos
 * OUTPUT: si es un char numerico retorna 1 y si no, retorna 0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
