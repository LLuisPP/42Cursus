/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:21:27 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/30 00:38:00 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Imprime los argumentos de echo, opción -n para suprimir el \n final */
// void	ft_echo(t_msh *msh, int num_cmd)
// {
// 	int		i;
// 	int		n_option;

// 	i = 1;
// 	n_option = 0;
// 	if (num_cmd <= 1)
// 		printf("\n");
// 	else if (num_cmd > 1)
// 	{
// 		if (ft_strcmp(msh->tkns[i].cmd, "-n") == 0)
// 		{
// 			n_option = 1;
// 			i++;
// 		}
// 		while (msh->tkns[i].cmd)
// 		{
// 			if (varenv_man(msh, "echo", msh->tkns[i].cmd))
// 				break;
// 			printf("%s", msh->tkns[i].cmd);
// 			if (msh->tkns[i + 1].cmd != NULL)
// 				printf(" ");
// 			i++;
// 		}
// 		if (n_option == 0)
// 			printf("\n");
// 	}
// }
// Hay que gestionar casos con comillas 
			//if (msh->tkns[i].cmd == '\'' || msh->tkns[i].cmd == '\"')
			//	i++;
// Hay que gestionar variable de entorno 
static int	is_n_flag(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] != '-')
		return (0);
	i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	check_n_flags(t_msh *msh, int *i)
{
	int	n_flag;
	int	curr_i;

	n_flag = 0;
	curr_i = 1;
	while (msh->tkns[curr_i].cmd)
	{
		if (!is_n_flag(msh->tkns[curr_i].cmd))
			break ;
		n_flag = 1;
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
		has_next = 0;
		if (msh->tkns[i + 1].cmd)
			has_next = 1;
		if (varenv_man(msh, "echo", msh->tkns[i].cmd) != 0)
			break ;
		print_arg(msh->tkns[i].cmd, has_next);
		i++;
	}
	if (!n_flag)
		ft_putchar_fd('\n', 1);
}
