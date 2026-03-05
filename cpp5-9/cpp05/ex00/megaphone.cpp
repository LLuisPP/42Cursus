/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:27:21 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/14 08:51:03 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>

int main(int argc, char **argv)
{
	const	std::ctype<char>&
	ct = std::use_facet<std::ctype<char> >(std::locale());
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		for(int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << ct.toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
