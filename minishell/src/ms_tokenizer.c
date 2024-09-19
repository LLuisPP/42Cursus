/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:35:57 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/13 16:01:44 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* corta el str de entrada con un separador (modificable) No trabajo en ella */
char	*ft_strtok(char *str, const char *separator)
{
	char	*ptr;
	char	*start;

	ptr = NULL;
	start = NULL;
	if (str == NULL)
		return (NULL);
	start = ptr;
	while (*ptr != '\0' && ft_strchr(separator, *ptr) == NULL)
		ptr++;
	if (*ptr != '\0')
		*ptr++ = '\0';
	return (start);
}
