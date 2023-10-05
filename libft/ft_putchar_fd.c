/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fs.d                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 06:45:42 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/05 08:41:59 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int	main()
{
	int	fd;

	fd = open("archivo.txt", O_WRONLY);
	printf("%d", fd);
	ft_putchar_fd('h', fd);
	return (0);
}

#include <fcntl.h>
#include <stdio.h>
*/
