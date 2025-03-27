/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:49:40 by lauriago          #+#    #+#             */
/*   Updated: 2025/03/26 10:04:28 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_has_2_expand(char *str)
{
	return (str && ft_strchr(str, '$') != NULL);
}

void	handle_echo_quotes(t_msh *msh, char k, int i)
{
	if (k == '\'' || k == '\"')
	{
		if (k == '\'')
			handle_single_quotes(msh, i);
		if (k == '\"')
			handle_double_quotes(msh, i);
	}
}

void	print_echo_argument(t_msh *msh, char *arg, int i, int is_last_arg)
{
	if (is_quote(arg[0]))
		handle_echo_quotes(msh, arg[0], i);
	if (!is_quote(arg[0]))
	{
		if (echo_has_2_expand(arg))
			ft_expander(arg, msh);
		else
			ft_putstr(arg);
		if (i != is_last_arg)
			ft_putstr(" ");
	}
}
