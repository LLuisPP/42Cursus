/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:49:01 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/21 07:13:30 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
	{
		return (1);
	}
	return (0);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("ft_strchr:%d \n", ft_isprint(atoi(argv[1])));
	printf("strchr:%d", isprint(atoi(argv[1])));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: la funcion busca comprueba que el caracter que
 *  recibe como parametro de entrada sea imprimible.
 * INPUT: integuer c
 * MAKE: comprueba que el caracter de entrada pertenece a los imprimibles
 * OUTPUT: si pertenece a los printables retorna 1 y si no, retorna 0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
