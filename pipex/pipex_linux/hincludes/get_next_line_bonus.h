/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:45:43 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/24 10:48:05 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_read_fd(int fd, char *buffer);
char	*ft_read_line(char *buffer);
char	*ft_new_line(char *buffer);
char	*ft_strchr(char *buffer, int c);
char	*ft_strjoin(char *buffer, char *new_buffer);

#endif
