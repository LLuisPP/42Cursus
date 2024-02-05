/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:26:41 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/05 08:52:09 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	while (l >= 0)
	{
		if (s[l] == (unsigned char) c)
		{
			return ((char *) &s[l]);
		}
		l--;
	}
	return ((char *) 0);
}

/*int main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("ft_strrchr:%s \n", ft_strrchr(argv[1], atoi(argv[2])));
	printf("strrchr:%s", strrchr(argv[1], atoi(argv[2])));
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: la funcion busca la ultima ocurrencia del caracter que
 *  recibe como parametro de entrada dentro del string.
 * INPUT: integuer c
 * MAKE: recorre el arrai de entrada y comprueba la ultima ocurrencia de
 * el caracter introducido.
 * OUTPUT: si aparece el caracter de entrada en el string de entrada,
 * retorna el puntero a la posicion de dicha ocurrencia.
 * Si por el contrario no aparece, retorna NULL
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
