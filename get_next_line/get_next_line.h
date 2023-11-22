/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:45:43 by lprieto-          #+#    #+#             */
/*   Updated: 2023/11/22 11:58:46 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

size_t	ft_strlen(char *str);
char	*ft_malloc(size_t len1, int len2);
char	*ft_read(int fd, char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *str, char *buffer);
char	*ft_read_line(char *str);
char	*ft_new_line(char *str);

#endif
