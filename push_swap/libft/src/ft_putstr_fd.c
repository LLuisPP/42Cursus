/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 06:39:22 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/12 07:10:25 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;

	i = 0;
	if (fd >= 0)
	{
		while (s[i] != 0)
			i++;
		len = i;
		i = 0;
		while (s[i] != 0)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

/*int	main()
{
	int	fd;

	fd = open("archivo.txt", O_WRONLY);
	printf("%d", fd);
	ft_putstr_fd("hola mon", fd);
	return (0);
}*/
/*
#include <stdio.h>
#include <fcntl.h>
*/
/* ************************************************************************** *
 *								FT_PUTSTR_FD
 *
 * DESCRIPCION:	se utiliza para escribir en un fd (file descriptor) un string
 *
 * INPUT:	char *s, int fd
 *
 * MAKE:	recorre el array de origen enviando cada caracter a un write en
 * un bucle
 *
 * OUTPUT:	no devuelve nada por que el output de esta funcion tiene salida
 * por el file descriptor. Se puede comprobar la funcionalidad si se define
 * el fd como un archivo donde escribir para luego visualizar el contenido
 * del mismo
 *
 * ***************************************************************************/
