/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:48:25 by lprieto-          #+#    #+#             */
/*   Updated: 2024/09/02 11:15:56 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mfill(int len, int n, int i, int signo)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	i = len--;
	if (signo == -1)
		str[0] = '-';
	while (n != 0)
	{
		str[len--] = n % 10 * signo + '0';
		n = n / 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		signo;
	int		i;
	int		len;
	char	*str;

	if (n > 2147483647 || n < -2147483647)
		return (NULL);
	signo = 1;
	i = n;
	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		signo = -1;
		len++;
	}
	while (i != 0)
	{
		i = i / 10;
		len++;
	}
	str = mfill(len, n, i, signo);
	return (str);
}

/*int	main(int argc, char **argv)
{
	if (argc != 2)
	   return (0);
	printf("str: %s\n", ft_itoa(atoi(argv[1])));
	return (0);
}*/
