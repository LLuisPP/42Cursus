/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:45:27 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/23 23:51:33 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Comprueba cada token y su siguiente para operador (incompleta) */
int lexer(char **tokens, t_msh *msh)
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
        if (ft_strcmp(tokens[i], "<<") == 0) // Verifica si el token es el delimitador de heredoc '<<'
        {
            if (tokens[i + 1] == NULL) // Comprueba que el siguiente token sea válido
            {
                perror("syntax error: missing delimiter for heredoc\n");
                return (-1);
            }
            msh->tkns->is_heredoc = 1; // guardamos el delimitador para el heredoc
            msh->tkns->heredoc_delim = ft_strdup(tokens[i + 1]); // Guarda el delimitador
            i++; // Avanza para saltar el delimitador
        }
        i++;
    }
    return (0);
}