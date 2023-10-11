/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fs.d                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 06:45:42 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/11 15:44:30 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

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
	read(0, &tmp, 10);
	fd = open("archivo.txt", O_WRONLY);
	write(fd, tmp, 10);
	//ft_putchar_fd(tmp, fd);
	ft_putchar_fd('6', fd);
	return (0);
}*/
