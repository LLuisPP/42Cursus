/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:33:11 by lprieto-          #+#    #+#             */
/*   Updated: 2025/10/22 20:36:26 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "3 arguments required !" << std::endl;
		return (1);
	}
	else
		std::cout << "testing" << std::endl;
	(void*)argv;
	return (0);
}
