/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 06:39:22 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/04 07:24:45 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;

	i = 0;
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

/*int	main(int argc, char **argv)
{
	if (argc !=3)
		return (NULL);
	ft_putstr_fd(argv[1],atoi(argv[2]));
	return (0);
}*/
