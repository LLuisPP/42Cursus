/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:49:27 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/24 19:23:56 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* inicia la asignacion de memoria para env en relacion al envs (del sistema) */
int init_envi(t_env **env, char **envs)
{
  size_t  env_count;
  *env = malloc(sizeof(t_env));
  if (!*env)
    return (-1);
  ft_memset(*env, 0, sizeof(t_env));
  (*env)->pwd = malloc(PATH_MAX);
  if (!(*env)->pwd)
    return (-1);
  env_count = env_var_count(envs) + 1;
  (*env)->names = malloc(sizeof(char *) * env_count);
  if (!(*env)->names)
    return (-1);
  (*env)->values = malloc(sizeof(char *) * env_count);
  if (!(*env)->values)
    return (-1);
  return (0);  
}

/* inicia la asignacion de memoria  para tok */
int init_tok(t_tok **tok)
{
  *tok = malloc(sizeof(t_tok));
  if (!*tok)
    return (-1);
  ft_memset(*tok, 0, sizeof(t_tok));
  return (0);
}

/* inicia la asignacion de memoria  para mpip */
int init_mpip(t_exe **mpip)
{
  *mpip = malloc(sizeof(t_exe));
  if (!*mpip)
    return (-1);
  ft_memset(*mpip, 0, sizeof(t_exe));
  return (0);
}

/* inicia las estructuras por separado y las enlaza a la estructura principal msh */
int init_structs(t_env **env, char **envs, t_msh *msh, t_exe **mpip, t_tok **tok)
{
if (init_envi(env, envs))
    return (ft_fd_printf(2, "%s", E_ENVGET) * -1);
 
  if (init_tok(tok))
  {
    free(*env);
    return (ft_fd_printf(2, "%s", E_TOKMEM) * -1);
  }
  if (init_mpip(mpip))
  {
    free(*env);
    free(*tok);
    return (ft_fd_printf(2, "%s", E_PIPMEM) * -1);
  }
  msh->env = *env;
  msh->tkns = *tok;
  msh->mpip = *mpip;
  return (0);
}






























/** En un monobloque de asignacion **/


// /* inicia las estructuras del .h (no borrar) No trabajo en ella */
// int init_structs(t_env **env, char **envs, t_msh *msh, t_exe **mpip, t_tok **tok)
// {
//   *env = malloc(sizeof(t_env));
//   if (!*env)
//     return (-1);
//   ft_memset(*env, 0, sizeof(t_env));
//   (*env)->pwd = malloc(PATH_MAX);
//   if (!(*env)->pwd)
//     return (-1);
//   size_t env_count = env_var_count(envs) + 1;
//   (*env)->names = malloc(sizeof(char *) * env_count);
//   (*env)->values = malloc(sizeof(char *) * env_count);
//   if (!(*env)->names || !(*env)->values)
//     return (-1);
//   // ft_memset(*env, 0, sizeof(t_env));
//   *mpip = malloc(sizeof(t_exe));
//   if (!*mpip)
//     return (-1);
//   ft_memset(*mpip, 0, sizeof(t_exe));
//   *tok = malloc(sizeof(t_tok));
//   if (!*tok)
//     return (-1);
//   ft_memset(*tok, 0, sizeof(t_tok));
//   msh->env = *env;
//   msh->tkns = *tok;
//   return (0);
// }
