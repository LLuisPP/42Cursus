/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:12:32 by lprieto-          #+#    #+#             */
/*   Updated: 2024/02/17 10:15:48 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	long	i;
	double	nbr;
	double	isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t'
			|| str[i] == '\n'
			|| str[i] == '\r'
			|| str[i] == '\v'
			|| str[i] == '\f'))
		i++;
	if (str[i] != '0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}

/*int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("%s", ft_atoi(argv[1]))
	return (0);	
}*/