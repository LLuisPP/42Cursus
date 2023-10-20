/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 06:45:42 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/12 07:18:49 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
/*int	main()
{
	int	fd;

	fd = open("archivo.txt", O_WRONLY);
	printf("%d", fd);
//	char	tmp[10];


	//read fd = 0 sin abrir antes un archivo,
	//almacena a tmp la cantidad de 10 en este caso
	//read(0, &tmp, 10);
	//fd = open("archivo.txt", O_WRONLY);
	//write(fd, tmp, 10);
	//ft_putchar_fd(tmp, fd);
	ft_putchar_fd('y', fd);
	return (0);
}*/
/* ************************************************************************** *
 *								FT_PUTCHAR_FD
 *
 * DESCRIPCION:	se utiliza para escribir una caracter en un descriptor de
 * archivo específico
 *
 * INPUT:	char c, int fd
 *
 * MAKE:	recorre el array de origen enviando el caracter a un write que
 * escribe dicho valor en el file descriptor
 *
 * OUTPUT:	no devuelve nada por que el output de esta funcion tiene salida
 * por el file descriptor. Se puede comprobar la funcionalidad si se define
 * el fd como un archivo donde escribir para luego visualizar el contenido
 * del mismo
 *
 * ***************************************************************************/
