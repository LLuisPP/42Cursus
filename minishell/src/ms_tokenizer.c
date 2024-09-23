/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:35:57 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/23 23:30:34 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* corta el str de entrada con un separador (CON mallocs) trabajando en ella */
// char	*ft_strtok(char *str, const char *separator)
// {
// 	static char	*ptr = NULL;
// 	char		*token;
// 	size_t		token_len;
// 	char		*res;

// 	if (str != NULL)
// 		ptr = str;	
// 	while (*ptr != '\0' && ft_strchr(separator, *ptr) != NULL)
// 		ptr++;
// 	if (*ptr == '\0')
// 		return (NULL);
// 	token = ptr;
// 	while (*ptr != '\0' && ft_strchr(separator, *ptr) == NULL)
// 		ptr++;
// 	token_len = ptr - token;
// 	if (*ptr != '\0')
// 	{
// 		*ptr = '\0';
// 		ptr++;
// 	}
// 	res = malloc(token_len + 1);
// 	if (!res)
// 		return (NULL);	
// 	ft_strcpy(res, token);
// 	res[token_len] = '\0';
// 	return (res);
// }

/* corta el str de entrada con un separador (no mallocs) trabajando en ella */
char	*ft_strtok(char *str, const char *separator)
{
	static char	*ptr = NULL;
	char		*token;

	if (str != NULL)
		ptr = str;
	while (*ptr != '\0' && ft_strchr(separator, *ptr) != NULL)
		ptr++;
	if (*ptr == '\0')
		return (NULL);
	token = ptr;
	while (*ptr != '\0' && ft_strchr(separator, *ptr) == NULL)
		ptr++;
	if (*ptr != '\0')
	{
		*ptr = '\0';
		ptr++;
	}

	return (token);
}