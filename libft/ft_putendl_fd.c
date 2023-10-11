/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:28:36 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/11 15:43:11 by lprieto-         ###   ########.fr       */
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
