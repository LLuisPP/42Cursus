/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:45:27 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/21 19:18:31 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Comprueba cada token y su siguiente para operador (en construccion) */
int lexer(char **tokens)
{
    int i;

    i = 0;
    while (tokens[i])
    {
        if (ft_strcmp(tokens[i], "|") == 0)
        {
            if (i == 0 || tokens[i + 1] == NULL)
            {
                perror("syntax error with | operator\n");
                return (-1);
            }
        }
        i++;
    }
    return (0);
}