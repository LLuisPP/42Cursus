/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:57:32 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/12 07:05:38 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	stringlen(char const	*s)
{
	int	slen;

	slen = 0;
	while (s[slen] != 0)
		slen++;
	return (slen);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (stringlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char	toupper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*str;
	char	*result;

	str = "Hola Mundo!";
	result = ft_strmapi(str, &toupper);
	ft_putstr_fd(result, 1);
	free(result);
	return (0);
}*/
/* ************************************************************************** *
 *								FT_STRMAPI
 *
 * DESCRIPCION:	se utiliza para aplicar una función a cada carácter de una
 * cadena de caracteres y devolver una nueva cadena con los resultados de la
 * aplicación de la función
 *
 * INPUT:	char const *s, char (*f)(unsigned int, char)
 *
 * MAKE:	comprueba caracteres por pares, en valor, de los strings hasta
 * encontrar la diferencia
 *
 * OUTPUT:	devuelve un char * al 'str' guardado que lo modifica en funcion de
 * la funcion aplicada. Si la funcion no tiene exito devuelve null
 *
 * ***************************************************************************/
