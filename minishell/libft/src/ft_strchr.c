/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:06:05 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/12 07:09:27 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *) &s[i]);
	return ((char *) 0);
}

/*int main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("ft_strchr:%s \n", ft_strchr(argv[1], atoi(argv[2])));
	printf("strchr:%s", strchr(argv[1], atoi(argv[2])));
	return(0);
}*/

/* ************************************************************************** *
 *								FT_STRRCHR
 *
 * DESCRIPCION: la funcion busca la ultima ocurrencia del caracter que
 * recibe como parametro de entrada dentro del string
 * 
 * INPUT:	const char *s, int c
 * 
 * MAKE:	recorre el arrai de entrada y comprueba el string 's' hasta hallar
 * la ultima ocurrencia del caracter 'c' introducido
 * 
 * OUTPUT:	si aparece el caracter de entrada en el string de entrada,
 * retorna el puntero a la posicion de dicha ocurrencia.
 * Si por el contrario no aparece, retorna NULL
 * 
 * ***************************************************************************/
