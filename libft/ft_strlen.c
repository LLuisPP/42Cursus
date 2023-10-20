/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:08:14 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/12 07:06:04 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("ft_strlen:%zu \n", ft_strlen(argv[1]));
	printf("strlen:%zu", strlen(argv[1]));
	return(0);
}*/

/* ************************************************************************** *
 *								FT_STRLEN
 *
 * DESCRIPCION:	se utiliza para saber la longitud de una cadena de caracteres
 * 
 * INPUT:	const char *s
 * 
 * MAKE:	recorre el string y almacena la longitud de este en un conrador
 * 
 * OUTPUT:	devuelve un contador con la longitud del string
 * 
 * ***************************************************************************/
