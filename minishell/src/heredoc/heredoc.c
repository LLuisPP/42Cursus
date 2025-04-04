/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:29:27 by lprieto-          #+#    #+#             */
/*   Updated: 2025/04/03 19:58:03 by lprieto-         ###   ########.fr       */
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
		if (!line || ft_strcmp(line, delimiter) == 0)
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

int	handle_heredoc(t_msh *msh, char *delimiter)
{
	char	*content;
	char	*temp_file_path;
	int		fd;

	if (!delimiter)
	{
		ft_fd_printf(2, E_NW);
		msh->last_exit_code = 2;
		return (FALSE);
	}
	temp_file_path = "/tmp/heredoc_temp";
	handle_heredoc_signals();
	content = read_until_delimiter(delimiter);
	restore_signals();
	fd = open(temp_file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0 || write(fd, content, ft_strlen(content)) < 0)
	{
		close(fd);
		return (free(content), FALSE);
	}
	close(fd);
	free(content);
	msh->heredoc_file = ft_strdup(temp_file_path);
	msh->mpip->infile = msh->heredoc_file;
	return (TRUE);
}

int	redirect_input_output(t_msh *msh)
{
	int	fd;

	if (msh->heredoc_file != NULL)
	{
		fd = open(msh->heredoc_file, O_RDONLY);
		if (fd < 0)
		{
			perror("open heredoc");
			return (FALSE);
		}
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			perror("dup2 heredoc -> STDIN");
			close(fd);
			return (FALSE);
		}
		close(fd);
	}
	return (TRUE);
}

void	cleanup_heredoc(t_msh *msh)
{
	if (msh->heredoc_file)
	{
		unlink(msh->heredoc_file);
		free(msh->heredoc_file);
		msh->heredoc_file = NULL;
	}
}
