/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:37:57 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/12 07:10:52 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			if (n < 0)
			{
				ft_putchar_fd('-', fd);
				n = n * -1;
			}
			if (n > 9)
			{
				ft_putnbr_fd(n / 10, fd);
			}
			ft_putchar_fd((n % 10) + '0', fd);
		}
	}
}

/*int	main()
{
	int	fd;

	fd = open("archivo.txt", O_WRONLY);
	printf("%d", fd);
	ft_putnbr_fd(-987441, fd);
	return (0);
}
#include <fcntl.h>
#include <stdio.h>
*/
/* ************************************************************************** *
 *								FT_PUTNBR_FD
 *
 * DESCRIPCION:	se utiliza para imprimir un número entero en un archivo de
 * salida especificado por el descriptor de archivo fd
 *
 * INPUT:	int n, int fd
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
