/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:21:27 by lauriago          #+#    #+#             */
/*   Updated: 2025/03/25 20:33:05 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Imprime los argumentos de echo, opción -n para suprimir el \n final */
// Hay que gestionar variable de entorno 
static int	is_n_flag(char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] != '-')
		return (FALSE);
	i++;
	if (!str[i])
		return (FALSE);
	while (str[i])
	{
		if (str[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_n_flags(t_msh *msh, int *i)
{
	int	n_flag;
	int	curr_i;

	n_flag = FALSE;
	curr_i = 1;
	while (msh->tkns->args[curr_i])
	{
		if (!is_n_flag(msh->tkns->args[curr_i]))
			break ;
		n_flag = TRUE;
		curr_i++;
	}
	*i = curr_i;
	return (n_flag);
}

void	ft_echo(t_msh *msh, int num_cmd)
{
	int	i;
	int	n_flag;
	int	is_last_arg;

	i = 1;
	if (num_cmd <= 1)
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	n_flag = check_n_flags(msh, &i);
	while (i < num_cmd && has_redirection(msh->tkns))
	{
		is_last_arg = (num_cmd - 1);
		print_echo_argument(msh, msh->tkns->args[i], i, is_last_arg);
		i++;
	}
	if (n_flag == FALSE)
		printf("\n");
}
