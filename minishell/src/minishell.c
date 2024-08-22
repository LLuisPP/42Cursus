/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:25:04 by lprieto-          #+#    #+#             */
/*   Updated: 2024/08/22 17:02:24 by lprieto-         ###   ########.fr       */
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
		{
			return (ft_strdup(name));
		}
	}
    return (NULL);
}

char **command_completion(const char *text, int start, int end)
{
    char **matches = NULL;

    if (start != 0 && end > start)
	{
        matches = rl_completion_matches(text, file_generator);
    }
	else
	{
        matches = rl_completion_matches(text, command_generator);
    }

    return (matches);
}

char	*file_generator(const char *text, int state)
{
    static DIR *dir;
    static struct dirent *entry;
    int len;
	
	len = ft_strlen(text);

    if (!state) {
        dir = opendir(".");
    }

    if (dir) {
        while ((entry = readdir(dir))) {
            if (ft_strncmp(entry->d_name, text, len) == 0)
			{
                return (ft_strdup(entry->d_name));
            }
        }
        closedir (dir);
        dir = NULL;
    }

    return (NULL);
}


int main(int argc, char **argv, char **env)
{
	char *input;
	t_hist	hist;

	(void)argc;
	(void)argv;
	(void)env;
	ft_bzero(&hist, sizeof(t_hist));
	while(1)
	{
		rl_attempted_completion_function = command_completion;
		input = readline("\033[1;96m 👽 Space 🛸 shell $\e[0m> ");
		if (input == NULL)
		{
			break;
		}

        if (*input)
		{
            add_history(input);
        }
	//	execve("/bin/ls", argv, NULL);

		(void)input;

        free(input);
    }

    return (0);
}
