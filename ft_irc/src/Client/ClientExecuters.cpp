/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientExecuters.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:15:43 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/01 15:00:24 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

/* Sends a message (RPL response) to the client socket */
bool	Client::answer(std::string rpl) {
	
	if (get_monitoring(0, 0))
		logOutput(_fd, rpl);
	if (send(_fd, rpl.c_str(), rpl.size(), 0) < 0)
		return (false);
	return (true);
}