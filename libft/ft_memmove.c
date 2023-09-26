/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:08:31 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/25 07:37:48 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char *) src;
	d = (char *) dst;
	i = 0;
	if (d > s)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/*int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	char *res_ft_memmove = ft_memmove(argv[1], argv[2], atoi(argv[3]));
	char *resultado_memmove = memmove(argv[1], argv[2], atoi(argv[3]));
	printf("ft_memmove:%s \n", res_ft_memmove);
	printf("memmove:%s", resultado_memmove);
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: copia tantos bytes como le indiquemos en len, desde el 
 * string src sobre el string dst. Los dos strings deben superponerse.
 * la copia se hace siempre de una forma no destructiva.
 * INPUT: un string de destino (dst), un string de origen (src) y 
 * un entero (len) que seran los bytes a copiar de uno a otro.
 * MAKE: copia tantos bytes de src sobre dst como le hayams indicado en len.
 * OUTPUT: devuelve siempre el array de destino con los bytes de memoria 
 * anadidos.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
