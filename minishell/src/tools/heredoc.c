/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:29:27 by lprieto-          #+#    #+#             */
/*   Updated: 2025/03/06 23:17:07 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*read_until_delimiter(char *delimiter)
{
	char	*line;
	char	*content;
	char	*temp;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		temp = content;
		content = ft_strjoin(content, line);
		free(temp);
		temp = content;
		content = ft_strjoin(content, "\n");
		free(temp);
		free(line);
	}
	return (content);
}

int handle_heredoc(t_msh *msh, char *delimiter)
{
	char *content;
	char *temp_file_path;
	int fd;

	handle_heredoc_signals();
	content = read_until_delimiter(delimiter);
	restore_signals();
	if (!content)
		return (FALSE);
	temp_file_path = "/tmp/heredoc_temp";
	fd = open(temp_file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		free(content);
		return (FALSE);
	}
	if (write(fd, content, ft_strlen(content)) < 0)
	{
		close(fd);
		free(content);
		return (FALSE);
	}
	close(fd);
	free(content);
	msh->heredoc_file = ft_strdup(temp_file_path);
	return (TRUE);
}

int redirect_input_output(t_msh *msh)
{
	// Redirigir la entrada estándar si hay un heredoc
	if (msh->heredoc_file != NULL)
	{
		int fd = open(msh->heredoc_file, O_RDONLY);
		if (fd < 0)
			return (FALSE);
		dup2(fd, STDIN_FILENO); // Redirigir la entrada estándar
		close(fd);
	}

	return (TRUE);
}



void cleanup_heredoc(t_msh *msh)
{
	if (msh->heredoc_file)
	{
		unlink(msh->heredoc_file); // Eliminar el archivo temporal
		free(msh->heredoc_file);    // Liberar la memoria
		msh->heredoc_file = NULL;    // Evitar punteros colgantes
	}
}