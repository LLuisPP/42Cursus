/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:09:34 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/26 15:30:37 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (str[l] != 0)
		l++;
	dest = (char *)malloc(l + 1);
	if (dest == ((char *) 0))
		return (0);
	while (str[i])
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
//	char *res_ft_strdup = ft_strdup(argv[1]);
	char *resultado_strdup = strdup(argv[1]);
//	printf("ft_strdup:%s \n", res_ft_strdup);
	printf("strdup:%s", resultado_strdup);
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: duplica un string en una posicion de memoria reservada
 * de antemano para duplicarlo sobre dicha memoria. 
 * INPUT: un string.
 * MAKE: reserva una cantidad de memoria igual a la longuitud del string
 * original + 1, posicion que se reserva para poner el '\0' final.
 * OUTPUT: devuelve un string identico al primero pero ubicado en una
 * posicion de memoria determinada por el malloc definido.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
