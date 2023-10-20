/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:28:36 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/12 07:11:17 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	nulo;

	if (fd > 0)
	{
		i = 0;
		nulo = '\n';
		if (!s)
			return ;
		while (s[i] != '\0')
			i++;
		write(fd, s, i);
		write(fd, &nulo, 1);
	}
}

/*int	main()
{
	int	fd;
	char *test;

	test = "ol";
	fd = open("archivo.txt", O_WRONLY);
	printf("%d", fd);
	ft_putendl_fd(&test[1], fd);
	return (0);
}

#include <fcntl.h>
#include <stdio.h>

*/
/* ************************************************************************** *
 *								FT_PUTENDL_FD
 *
 * DESCRIPCION:	se utiliza para escribir una cadena de caracteres seguida de
 * un salto de línea en un archivo o en un descriptor de archivo específico
 *
 * INPUT:	char *s, int fd
 *
 * MAKE:	recorre el array de origen enviando cada caracter a un write en
 * un bucle hasta la posicion indicada en donde introduce un salto de linea
 *
 * OUTPUT:	no devuelve nada por que el output de esta funcion tiene salida
 * por el file descriptor. Se puede comprobar la funcionalidad si se define
 * el fd como un archivo donde escribir para luego visualizar el contenido
 * del mismo
 *
 * ***************************************************************************/
