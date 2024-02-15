/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 07:48:26 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/15 08:20:24 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void rev_print_bits(unsigned char octet)
{
	int	i = -1;
	unsigned char 	bit;

	while (i++ < 7)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

char reverse_bit_char(unsigned char c)
{
	int i = -1;
	unsigned char new = 0;
	while (i++ < 7)
	{
		new |= c & (1 >> i);
	}
	return (new);
}

char bit_char(unsigned char c)
{
	int i = 8;
	unsigned char new = 0;
	while (i-- >= 0)
	{
		new |= c & (1 << i);
	}
	return (new);
}

int	main()
{
	print_bits(bit_char(4));
	return (0);
}
