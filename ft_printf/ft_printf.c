/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:28:39 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/24 11:31:24 by lprieto-         ###   ########.fr       */
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
// int	main()
// {
// 	// int mine;
// 	// int pro;

// 	// mine = ft_printf("mine%s", "");
// 	// pro = printf("orig%s", "");

// 	// printf("m%d / p%d", mine, pro);
// 	ft_printf("MY --> hola mon! char: %c, str: %s, digit: %d, int: %i, uint: %u hex: %x\n", 'a', "hola", -3407, 204, 24233, 0);
// 	ft_printf(" ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱  ⟱ \n");
// 	printf("OG --> hola mon! char: %c, str: %s, digit: %d, int: %i, uint: %u hex: %x\n", 'a', "hola", -3407, 204, 24233, 0);
// 	ft_printf("> -  -  -  -  -  -  -  -  -  -  -  -  -  -  - <\n");

// 	return (0);
// }


/*	ft_printf("MY -->hola mon! c: %c, s: %s, p: %p, d: %d, i: %i, u: %u,
 *	x: %x, X: %X, %: %%", "7", "hola", 0.25, 10, 0.30, '61', '41', "%"  \n); */
