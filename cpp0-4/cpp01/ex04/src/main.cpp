/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:33:11 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/23 09:21:40 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

//Color macros
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"


void	replace(std::ifstream *infile, std::ofstream *outfile, std::string str1, std::string str2)
{
	std::string		line;
	
	while (std::getline(*infile, line))
	{
		for (int i = 0, j; line[i]; i++)
		{
			j = 0;
			while (str1[j])
			{
				if (line[i + j] != str1[j])
					break;
				j++;
			}
			if (j == (int) str1.length() && j)
			{
				*outfile << str2;
				i += j - 1;
			}
			else
				*outfile << line[i];
		}
		*outfile << '\n';
	}
	
}

int	main(int argc, char **argv)
{
	std::string	filename;

	if (argc != 4) {
		std::cerr << BOLD << YELLOW << "Syntax: " << argv[0] << " <text_file> <word_find> <word_replace>" << RESET << std::endl;
		return (1);
	}
	filename = (std::string) argv[1] + ".replace";
	std::ifstream	infile(argv[1]);
	if (!infile.is_open()) {
		std::cout << RED << "Error: Can't open " << BOLD << argv[1] << RESET << RED << " file" << std::endl;
		return (1);
	}
	std::ofstream	outfile(filename.c_str());
	if (!infile.is_open()) {
		std::cout << RED << "Error: Can't open " << argv[1] << ".replace " << " file" << std::endl;
		return (1);
	}
	replace(&infile, &outfile, argv[2], argv[3]);
	infile.close();
	outfile.close();
	std::cout << GREEN << "Output file created, try: ";
	std::cout << BOLD << "cat <fileneme.replace>";
	std::cout <<  RESET << GREEN << " to compare" << std::endl;
	return (0);
}
