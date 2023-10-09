/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:48:25 by lprieto-          #+#    #+#             */
/*   Updated: 2023/10/09 13:44:02 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa(int n)
{
	int		signo;
	int		i;
	int		len;
	char	*str;

	signo = 0;
	i = n;
	len = 0;
	if (n == 0)
	{
		len = 1;
	}
	if (n < 0)
	{
		n = -n;
		signo++;
		len++;
	}
	while (i != 0)
	{
		i = i / 10;
		len++;
	printf("str: %d\n", len);
	}
	printf("str: %d\n", len);

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return(str);
	}
	i = len;
	len = len - 1;
	if (signo == 1)
		str[0] = '-';
	while (n != 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	str[i] = '\0';
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	   return (0);
	printf("str: %s\n", ft_itoa(atoi(argv[1])));
	return (0);
}
