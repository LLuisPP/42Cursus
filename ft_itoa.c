/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:09:05 by lprieto-          #+#    #+#             */
/*   Updated: 2023/09/29 17:19:42 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_itoa(int n)
{
	int	sign = (n < 0) ? -1 : 1;
	int	size = 1;
	int	temp = n;

	while (temp /= 10)
	size++;
	char	*str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
	return (NULL);
	str[size] = '\0';
	if (sign == -1)
	str[0] = '-';
	while (size--)
	{
		str[size] = (n % 10) * sign + '0';
		n /= 10;
	}
	return (str);
}

int	main()
{
	int		num = 1928;
	char	*str = ft_itoa(num);

	if (str == NULL)
	{
	printf("Error al reservar memoria con malloc.\n");
	return (1);
	}
	printf("El número %d convertido a cadena es: %s\n", num, str);
	free(str);
	return (0);
}
