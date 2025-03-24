/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:49:40 by lauriago          #+#    #+#             */
/*   Updated: 2025/02/04 15:49:49 by lauriago         ###   ########.fr       */
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

void	print_echo_argument(t_msh *msh, char *arg, int is_last_arg)
{
	int	i;

	i = 0;
	if (is_quote(arg[0]))
		handle_echo_quotes(msh, arg[0], is_last_arg);
	else if (!is_quote(arg[0]))
	{
		if (echo_has_2_expand(arg))
			ft_expander(arg, msh);
		else
			printf("%s", arg);
	}
	if (i < msh->tkns->token_count)
	{
		i++;
		printf(" ");
	}
}
