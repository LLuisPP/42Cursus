/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:37:32 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/23 17:37:13 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Parsea PATH del env del sistema (modificable) Trabajando en ella*/
char	*parse_path(char **envs)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (envs[i] && !path)
	{
		if (ft_strncmp(envs[i], "PATH=", 5) == 0)
		{
			path = ft_split(&envs[i][5], ';');
			if (!path)
				exit (-1);
		}
		i++;
	}
	if (!path)
		exit (-1);
	return (*path);
}

/* Parsea PWD desde el env del sistema (modificable) Trabajando en ella */
char	*parse_pwd(char **envs)
{
	int		i;
	char	**pwd;

	i = 0;
	pwd = NULL;
	while (envs[i] && !pwd)
	{
		if (ft_strncmp(envs[i], "PWD=", 4) == 0)
		{
			pwd = ft_split(&envs[i][5], ';');
			if (!pwd)
				exit (-1);
		}
		i++;
	}
	if (!pwd)
		exit (-1);
	return (*pwd);
}

/* parsea el input dentro del loop principal y lo guarda en la estructura */
int	parse_input(char *input, t_msh *msh)
{
    char *tkns;
    int i;
	
	i = 0;
    // msh->tkns->cmd = NULL;
    msh->tkns->args = malloc(sizeof(char *) * (MAX_ARGS + 1));
    if (input == NULL || *input == '\0')
        return (0);
    tkns = ft_strtok(input, " \t\n");
    while (tkns != NULL && i < MAX_ARGS)
    {
        msh->tkns->args[i++] = tkns;
        tkns = ft_strtok(NULL, " \t\n");
    }
    msh->tkns->args[i] = NULL;
    if (msh->tkns->args[0])
        msh->tkns->cmd = msh->tkns->args[0];

    return (0);
}