/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_b_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:41:10 by lauriago          #+#    #+#             */
/*   Updated: 2024/10/29 21:22:38 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	return (abs_path);
}

char *make_relative(char *arg, t_msh *msh)
{
    char *new_path;

    new_path = NULL;
    if (arg[0] == '.' && arg[1] == '\0')
        new_path = ft_strdup(".");
    else if (arg[0] == '.' && arg[1] == '.'
		&& (arg[2] == '\0' || arg[2] == '/'))
        new_path = ft_strdup("..");
    else if (arg[0] == '.' && arg[1] == '/')
        new_path = built_abspath(arg + 2, msh->env->pwd);
    else
        new_path = built_abspath(arg, msh->env->pwd);
    
    return new_path;
}

void handle_cd_path(t_msh *msh)
{
    char *new_path;
    char *home_expanded;

    new_path = NULL;
    if (varenv_man(msh, "cd", msh->tkns[1].cmd) != 0)
        return;

    // el caso de cd -
    if (msh->tkns[1].cmd[0] == '-' && msh->tkns[1].cmd[1] == '\0')
    {
        if (!msh->env->old_pwd)
        {
            ft_fd_printf(2, "cd: OLDPWD not set\n");
            return;
        }
        new_path = ft_strdup(msh->env->old_pwd);
        printf("%s\n", msh->env->old_pwd);
    }
    // expansión de ~
    else if (msh->tkns[1].cmd[0] == '~')
    {
        if (!msh->env->home)
        {
            ft_fd_printf(2, "cd: HOME not set\n");
            return;
        }
        // Si es solo ~ o ~/algo
        if (msh->tkns[1].cmd[1] == '\0' || msh->tkns[1].cmd[1] == '/')
        {
            home_expanded = ft_strjoin(msh->env->home, msh->tkns[1].cmd + 1);
            new_path = ft_strdup(home_expanded);
            free(home_expanded);
        }
    }
    // rutas absolutas
    else if (msh->tkns[1].cmd[0] == '/')
        new_path = ft_strdup(msh->tkns[1].cmd);
    // rutas relativas
    else
        new_path = make_relative(msh->tkns[1].cmd, msh);

    if (!new_path)
    {
        ft_fd_printf(2, "cd: memory allocation error\n");
        return;
    }

    // Intentar cambiar al directorio
    if (chdir(new_path) == -1)
    {
        if (errno == EACCES)
            ft_fd_printf(2, "cd: %s: Permission denied\n", msh->tkns[1].cmd);
        else if (errno == ENOTDIR)
            ft_fd_printf(2, "cd: %s: Not a directory\n", msh->tkns[1].cmd);
        else
            ft_fd_printf(2, "cd: %s: No such file or directory\n", msh->tkns[1].cmd);
    }
    else
    {
        // Actualizar PWD y OLDPWD solo si el cambio fue exitoso
        char *temp = msh->env->pwd;
        msh->env->old_pwd = temp;
        msh->env->pwd = getcwd(NULL, 0);
        if (!msh->env->pwd)
        {
            ft_fd_printf(2, "cd: error getting current directory\n");
            msh->env->pwd = temp;
            msh->env->old_pwd = NULL;
        }
        env_pos(msh);
    }

    free(new_path);
}

void	ft_cd(t_msh *msh, int num_cmd)
{
	if (num_cmd > 2)
		ft_fd_printf(2, "bash: %s: too many arguments\n", msh->tkns->cmd);
	else if (num_cmd == 1)
		chdir(msh->env->home);
	else if (num_cmd == 2)
		handle_cd_path(msh);
}
