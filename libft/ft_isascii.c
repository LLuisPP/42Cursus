/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:57:10 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/20 16:27:19 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= ('~' + 1))
	{
		return (1);
	}
	return (0);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("ft_strchr:%d \n", ft_isascii(atoi(argv[1])));
	printf("strchr:%d", isascii(atoi(argv[1])));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: la funcion busca comprueba que el caracter que
 *  recibe como parametro de entrada sea un ascii.
 * INPUT: integuer c
 * MAKE: comprueba que el caracter de entrada pertenece a los ascii
 * OUTPUT: si pertenece a los ascii retorna 1 y si no aparece, retorna NULL
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
