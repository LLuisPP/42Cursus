/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:21:27 by lauriago          #+#    #+#             */
/*   Updated: 2024/09/21 22:35:51 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Calculo num de argumentos para gestionar las 2 posibilidades de echo
int	num_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	*ft_echo(char **argv)
{
	int	i;
	int	n_option;

	i = 1;
	n_option = 0;
	if (num_arg(argv) > 1)
	{
		while (argv[i] && ft_strcmp(argv[i], "-n") == 0)
		{
			n_option = 1;
			i++;
		}
		while (argv[i])
		{
			ft_pts(argv[i]);
			if (argv[i + 1])
				printf(" ");
			i++;
		}
	}
	if (n_option == 0)
		printf("\n");
	return(NULL);
}