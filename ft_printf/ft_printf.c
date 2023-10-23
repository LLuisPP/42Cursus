/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:28:39 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/23 13:02:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// static void	ft_putstr(char *s)
// {
// 	int	len;
// 	int	i;

// 	i = 0;
// 	if (s)
// 	{
// 		while (s[i] != 0)

// 			i++;
// 		len = i;
// 		i = 0;
// 		while (s[i] != 0)
// 		{
// 			ft_putchar(s[i]);
// 			i++;
// 		}
// 	}
// }

// static int	ft_pholder(char const *str, va_list args, int i, int j)
// {
// 	if (str[j] == 'c')
// 		ft_putchar(va_arg(args, int));
// 	if (str[j] == 's')
// 		ft_putstr(va_arg(args, char *));
// 	// if (str[j] == 'p')
// 	// 	ft_ptr(va_arg(args, char *));
// 	return (i);
// }

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[j])
	{
		if (str[j] == '%')
		{
			ft_pholder(str, args, i, ++j);
			j++;
		}
		else
		{
			i++;
			ft_putchar(str[j]);
			j++;
		}
	}
	va_end(args);
	return (i);
}
/*int	main()
{
	ft_printf("MY -->hola mon! c: %c, s: %s\n", 'a', "hola");
	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱ \n");
	printf("OG -->hola mon! c: %c, s: %s\n", 'a', "hola");

	return (0);
}*/
/*	if (str[j] == 'p')	//puntero
		write (1, 'p', 1);
	if (str[j] == 'd')	//decimal
		write (1, 'd', 1);
	if (str[j] == 'i')	//entero base 10
		write (1, 'i', 1);
	if (str[j] == 'u')	//unsigned decimal
		write (1, 'u', 1);
	if (str[j] == 'x')	// hexadecimal minusculas
		write (1, 'x', 1);
	if (str[j] == 'X')	//hexadecimal MAYUSCULAS
		write (1, 'X', 1);
	if (str[j] == '%')	//simbolo de %
		write (1, '%', 1);*/
/*	ft_printf("MY -->hola mon! c: %c, s: %s, p: %p, d: %d, i: %i, u: %u,
 *	x: %x, X: %X, %: %%", "7", "hola", 0.25, 10, 0.30, '61', '41', "%"  \n); */
