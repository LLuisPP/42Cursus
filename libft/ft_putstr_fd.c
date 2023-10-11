/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 06:39:22 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/11 15:44:17 by lprieto-         ###   ########.fr       */
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
