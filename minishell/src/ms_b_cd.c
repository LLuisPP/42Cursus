/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegon <leegon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:41:10 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/09 01:27:30 by leegon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	is_varenv(char *input)
{
	int	i;
	char	*varenv;

	i = 0;
	varenv = malloc(sizeof(char) * ft_strlen(input) + 1);
	while (input[i])
	{
		if (input[i] == '$')
			break;
		i++;
	}
	printf("%c\n", input[i]);
	if (input[i] != '\0')
	{
		while (input[i++])
			varenv[i] = input[i];
		printf("%s\n", varenv);
	}
}

/* Converts a relative path to an absolute path */
char	*built_abspath(char *relative_path, char *pwd)
{
	char	*abs_path;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(relative_path) + ft_strlen(pwd) + 2;
	abs_path = malloc(sizeof(char) * len);
	i = -1;
	j = 0;
	if (!abs_path)
		return (NULL);
	while (pwd[++i])
		abs_path[j++] = pwd[i];
	abs_path[j++] = '/';
	i = -1;
	while (relative_path[++i])
		abs_path[j++] = relative_path[i];
	abs_path[j] = '\0';
//	printf("\nabs_path = %s\n", abs_path);
	return (abs_path);
}

char	*make_relative(char *arg, t_msh *msh)
{
	char	*new_path;

	new_path = NULL;
	if (arg[0] == '-')
	{
		new_path = ft_strdup(msh->env->old_pwd);
		printf("%s\n", msh->env->old_pwd);  // Imprimir el directorio anterior
	}
	else if (arg[0] == '.' && (arg[1] == '\0' || arg[1] == '/'))
		new_path = ft_strdup("..");
	else if (arg[0] == '.' && arg[1] == '.' && (arg[2] == '\0' ||
		arg[2] == '/'))
		new_path = ft_strdup("..");
	else
		new_path = built_abspath(msh->tkns[1].cmd, msh->env->pwd);
	return (new_path);
}

/* Verifies the route & acces in case that exists */
void	ft_cd(t_msh *msh, int num_cmd)
{
	char	*new_path;

	new_path = NULL;
	if (num_cmd > 2)
		ft_fd_printf(2, "bash: %s: too many arguments\n", msh->tkns->cmd);
	else if (num_cmd == 1)
		chdir(msh->env->home);
	else if (num_cmd == 2)
	{
		// verify_varenv --> Verificar si se quiere acceder a una variable
		// de entorno y en caso de ser una variable 
		verify_varenv(msh->tkns[1].cmd);
		if (msh->tkns[1].cmd[0] == '/') // Is an absolute path
			new_path = ft_strdup(msh->tkns[1].cmd);
		else
			new_path = make_relative(msh->tkns[1].cmd, msh);
	}
	if (new_path && chdir(new_path) != -1)
	{
		msh->env->old_pwd = msh->env->pwd;
		msh->env->pwd = getcwd(NULL, 0);
		env_pos(msh);
	}
	else
		perror("cd");
	free(new_path);
}
