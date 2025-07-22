/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:10:02 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/12 07:07:59 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
void print_char(unsigned int index, char *c)
{
    printf("Carácter en el índice %d: %c\n", index, *c);
}
int main()
{
    char str[] = "Hola, mundo!";
    ft_striteri(str, print_char);
    return 0;
}*/

/* ************************************************************************** *
 *								FT_STRITERI
 *
 * DESCRIPCION:	se utiliza para aplicar una función a cada carácter de una
 * cadena, pasando el índice de cada carácter como argumento adicional
 *
 * INPUT:	char *s, void (*f)(unsigned int, char *)
 *
 * MAKE:	recorre el arrays de origen y aplica a cada caracter la funcion
 * pasada como parametro (en el ejemplo resultará en la impresión de cada
 * carácter de la cadena junto con su índice
 *
 * OUTPUT:	no devuelve nada ya que es una funcion void
 *
 * ***************************************************************************/
