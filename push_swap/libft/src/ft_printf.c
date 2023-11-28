/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:28:39 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/26 09:49:56 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[j] && i != -1)
	{
		if (str[j] == '%')
		{
			i = ft_pholder(str, args, i, ++j);
		}
		else
			i += ft_putchar(str[j]);
		j++;
	}
	va_end(args);
	return (i);
}

/*int main()
{
	char *octet;
	
	octet = 0;
	ft_printf(NULL);
	ft_printf("Esto es un string pasada por argumento: %s\n",octet);
	ft_printf("Esto es un string pasada por argumento: %d\n", octet);
	//printf("Esto es un string pasada por argumento: %d\n", *octet);
	ft_printf("Esto es un string pasada por argumento: %p\n", octet);
	printf("Esto es un string pasada por argumento: %p\n", octet);
	ft_printf("Esto es un string pasada por argumento: %x\n", octet);
	printf("Esto es un string pasada por argumento: %x\n", *octet);
	ft_printf("Esto es la direccion del string pasada por argumento: %p\n", octet);
	printf("Esto es la direccion del string pasada por argumento: %p\n", octet);
}*/

// int	main()
// {
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
// 	ft_printf("MYOWNED --> char: %c\n", 'a');
// 	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  \n");
// 	printf("ORIGINAL --> char: %c\n", 'a');
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
// 	ft_printf("MYOWNED --> str: %s, "hola");
// 	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  \n");
// 	printf("ORIGINAL --> str: %s, "hola");
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
// 	ft_printf("MYOWNED --> ptr %p, 0x1345204);
// 	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  \n");
// 	printf("ORIGINAL --> ptr %p, 0x1345204);
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
// 	ft_printf("MYOWNED --> digit: %d, -3407);
// 	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  \n");
// 	printf("ORIGINAL --> digit: %d, -3407);
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
// 	ft_printf("MYOWNED --> int: %i, 204);
// 	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  \n");
// 	printf("ORIGINAL --> int: %i, 204);
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
// 	ft_printf("MYOWNED --> uint: %u 24233);
// 	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  \n");
// 	printf("ORIGINAL --> uint: %u, 242330);
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
// 	ft_printf("MYOWNED --> hex: %x\n" 2423333);
// 	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  \n");
// 	printf("ORIGINAL --> hex: %x\n", 2423333);
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
// 	ft_printf("MYOWNED --> HEX: %X\n", 2423333);
// 	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  \n");
// 	printf("ORIGINAL -->  HEX: %X\n", 2423333, 0);
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
// 	ft_printf("MYOWNED --> PERC: %%\n", %);
// 	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  \n");
// 	printf("ORIGINAL --> PERC: %%\n", %);
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");
// 	return (0);
// }
