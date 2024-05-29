/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:01:02 by lprieto-          #+#    #+#             */
/*   Updated: 2024/05/27 11:32:02 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*void print_mem(void *p, size_t n)
{
	size_t i;
	char *p_char;
	i = 0;
	p_char = (char *) p;
	while (i < n)
	{
		printf("|%d|", p_char[i]);	
		i++;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	char *ft_bzeroSTR;
	char *bzeroSTR;
	
	ft_bzeroSTR = argv[2];
	bzeroSTR = argv[1];
	printf("ANTES (string de entrada): %s %c", argv[1],'\n');
//	printf("poisciones de memoria del string completo: %c", '\n');
	print_mem(bzeroSTR, (size_t)sizeof(argv[2]));*/

/*	printf("String mem Pos before:%p %c", argv[1],'\n');
	ft_bzero(bzeroSTR, atoi(argv[2]));
	bzero(bzeroSTR, atoi(argv[2]));
	print_mem(bzeroSTR, (size_t)sizeof(argv[2]));
	printf("poisciones de memoria del string borradas: %c", '\n');
	print_mem(bzeroSTR, atoi(argv[2]));
	printf("String mem Pos after:%p %c", 
 	ft_bzero(bzeroSTR, atoi(argv[2])),'\n');
	printf("DESPUES (lleno de zeros): %s<---nada por que cuando
   	encuentra null printf para %c", argv[1],'\n');
	return(0);
}*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DESCRIPCION: escribe ceros dentro del string que recibe como parametro de
 * entrada hasta el entero que tambien recibe.
 * INPUT: puntero sin tipo (string) y un integuer c
 * MAKE: llena el string con tantos ceros como le hayamos indicado en el int
 * OUTPUT: la funcion en si misma no retorna nada, pero se puede ver los cambios
 * que hace en el string original si lo dibujamos.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
