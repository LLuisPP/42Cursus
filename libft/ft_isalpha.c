/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:19:30 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/20 12:24:44 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("ft_isalpha:%d \n", ft_isalpha(atoi(argv[1])));
	printf("ft_isalpha:%d", isalpha(atoi(argv[1])));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * DESCRIPCION: la funcion comprueba que el caracter que recibe se aun char
 * empleando un int como parametro de entrada.
 * INPUT: integuer c
 * MAKE: comprueba que esta dentro del rango de chars alfabeticos
 * OUTPUT: si es un char alfabetico retorna 1 y si no, retorna 0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
