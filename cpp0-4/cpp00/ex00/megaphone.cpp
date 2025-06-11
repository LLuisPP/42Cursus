/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:27:21 by lprieto-          #+#    #+#             */
/*   Updated: 2025/06/11 15:05:36 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        i = -1;
        while (i < argc)
        {
            j = 0;
            while (argc > 1 && argv && argv[++i])
            {
                j = -1;
                while (i > 0 && argv[i][++j])
                {
                    std::cout << (char)std::toupper(argv[i][j]);
                    std::cout << " ";
                }
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }
    return (0);
}
