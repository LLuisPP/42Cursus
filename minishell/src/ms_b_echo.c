/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:21:27 by lauriago          #+#    #+#             */
/*   Updated: 2024/11/06 17:17:38 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Imprime los argumentos de echo, opción -n para suprimir el \n final */
// Hay que gestionar variable de entorno 
static int	is_n_flag(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (FALSE);
	if (str[i] != '-')
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
	while (msh->tkns[curr_i].cmd)
	{
		if (is_n_flag(msh->tkns[curr_i].cmd) == FALSE)
			break ;
		n_flag = TRUE;
		curr_i++;
	}
	*i = curr_i;
	return (n_flag);
}

static void	print_arg(char *arg, int has_next)
{
	if (!arg)
		return ;
	ft_putstr_fd(arg, 1);
	if (has_next)
		ft_putchar_fd(' ', 1);
}

void	ft_echo(t_msh *msh, int num_cmd)
{
	int	i;
	int	n_flag;
	int	has_next;

	i = 0;
	if (num_cmd <= 1)
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	n_flag = check_n_flags(msh, &i);
	while (msh->tkns[i].cmd)
	{
		has_next = FALSE;
		if (msh->tkns[i + 1].cmd)
			has_next = TRUE;
		if (varenv_man(msh, "echo", msh->tkns[i].cmd) != FALSE)
			break ;
		print_arg(msh->tkns[i].cmd, has_next);
		i++;
	}
	if (n_flag == FALSE)
		ft_putchar_fd('\n', 1);
}
