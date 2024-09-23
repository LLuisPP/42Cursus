/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:27 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/23 23:56:50 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* inicia las estructuras del .h (no borrar) No trabajo en ella */
int init_structs(t_env **env, char **envs, t_msh *msh, t_pip **mpip)
{
  *env = malloc(sizeof(struct s_env));
  if (!*env)
    return (-1);
  ft_memset(*env, 0, sizeof(struct s_env));
  (*env)->pwd = malloc(PATH_MAX);
  if (!(*env)->pwd)
    return (-1);
  (*env)->names = malloc(sizeof(char *) * env_var_count(envs) + 1);
  (*env)->values = malloc(sizeof(char *) * env_var_count(envs) + 1);
  if (!(*env)->names || !(*env)->values)
    return (-1);
  *mpip = malloc(sizeof(struct s_pip));
  if (!*mpip)
    return (-1);
  ft_memset(*mpip, 0, sizeof(struct s_pip));
  msh->tkns = malloc(sizeof(struct s_tok));
  if (!msh->tkns)
    return (-1);
  ft_memset(msh->tkns, 0, sizeof(struct s_tok));
  msh->env = *env;
  
  return (0);
}


/** REFACTORIZANDO (DA FALLOS DE SEGFAULT) NO USAR AUN **/

// /* inicia las estructuras del .h (no borrar) No trabajo en ella */
// int mem_alloc(t_env **env, char **envs, t_msh *msh, t_pip **mpip)
// {
//   *env = malloc(sizeof(struct s_env));
//   if (!*env)
//     return (-1);
//   (*env)->pwd = malloc(PATH_MAX);
//   if (!(*env)->pwd)
//     return (-1);
//   (*env)->names = malloc(sizeof(char *) * env_var_count(envs));
//   (*env)->values = malloc(sizeof(char *) * env_var_count(envs));
//   if (!(*env)->names || !(*env)->values)
//     return (-1);
//   *mpip = malloc(sizeof(struct s_pip));
//   if (!*mpip)
//     return (-1);
//   msh->tkns = malloc(sizeof(struct s_tok));
//   if (!msh->tkns)
//     return (-1);
//   return (0);
// }

// int zero_mem_set(t_env **env, t_msh *msh, t_pip **mpip)
// {
//   ft_memset(*env, 0, sizeof(struct s_env));
//   ft_memset(*mpip, 0, sizeof(struct s_pip));
//   ft_memset(msh->tkns, 0, sizeof(struct s_tok));
//   return (0);
// }

// int init_structs(t_env **env, char **envs, t_msh *msh, t_pip **mpip)
// {
//   mem_alloc(env, envs, msh, mpip);
//   zero_mem_set(env, msh, mpip);
//   return (0);
// }