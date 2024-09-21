/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:41:30 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/21 22:07:47 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_structs(t_env *env, t_tok *tok)
{
    if (env)
    {
        free(env->pwd);
        free(env);
    }
    if (tok)
        free(tok);
}