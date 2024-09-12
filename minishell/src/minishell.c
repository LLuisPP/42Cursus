/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:25:04 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/09 11:32:15 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*command_generator(const char *text, int state)
{
	static int	list_index;
	static int	len;
	char		*name;
	static char *command_list[] = {"cd", "exit", "ls", "mkdir", "rm", "touch",
		"help", "clear", NULL};

	if (!state)
	{
		list_index = 0;
		len = ft_strlen(text);
	}
	while ((name = command_list[list_index++]))
	{
		if (ft_strncmp(name, text, len) == 0)
			return (ft_strdup(name));
	}
    return (NULL);
}

char **command_completion(const char *text, int start, int end)
{
    char **matches = NULL;

    if (start != 0 && end > start)
        matches = rl_completion_matches(text, file_generator);
	else
        matches = rl_completion_matches(text, command_generator);

    return (matches);
}

char	*file_generator(const char *text, int state)
{
    static DIR				*dir;
    static struct dirent	*entry;
    int						len;
	
	len = ft_strlen(text);

    if (!state)
		dir = opendir(".");

    if (dir)
	{
        while ((entry = readdir(dir))) {
            if (ft_strncmp(entry->d_name, text, len) == 0)
                return (ft_strdup(entry->d_name));
        }
        closedir (dir);
        dir = NULL;
    }
    return (NULL);
}
/* Esta funcion es para trocear un path del env (no estoy trabajando en ella, se puede modificar)*/
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

char	*ft_strtok(char *str, const char *separator)
{
	char *ptr = NULL;
	char *start = NULL;
	
	if (str == NULL)
		return (NULL);
	start = ptr;
	while (*ptr != '\0' && ft_strchr(separator, *ptr) == NULL)
		ptr++;
	if (*ptr != '\0')
		*ptr++ = '\0';
	return (start);
}

int	init_structs(t_env *env, t_hist *hist)
{
	ft_bzero(env, sizeof(t_env));
	ft_bzero(hist, sizeof(t_hist));	
	return (0);
}

int main(int argc, char **argv, char **envs)
{
	char *input;
	t_hist	hist;
	t_env	env;
	//char **tokens = NULL;
	char	*pwd;

	if (argc != 1 || argv[1])
	{
		ft_fd_printf(2, "%s", E_EXECARG);
		exit (0);
	}
	init_structs(&env, &hist);
	pwd = parse_pwd(envs);
	printf("pwd: %s\n", pwd);
	while(1)
	{
		rl_attempted_completion_function = command_completion;
		input = readline("\033[1;96m 👽 Space 🛸 shell $\e[0m> ");
		if (input == NULL)
			break;
		//*tokens = ft_strtok(argv[1], " ");
        if (*input)
            add_history(input);
		execve("/bin/ls", argv, NULL);
        free(input);
    }

    return (0);
}
