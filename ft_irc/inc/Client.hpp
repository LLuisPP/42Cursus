/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:15:47 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/01 09:56:48 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "Irc.hpp"

enum StatusLevel
{
	NOT_AUTHENTICATED,	// 0: Just connected
	CAP_NEGOTIATED,		// 1: CAP negotiated with HexChat)
	PASS_OK,			// 2: Correct PASS sent (valid)
	NICK_OK,			// 3: Correct NICK sent (valid)
	NICK_AGAIN,			// 4: (Optional) nick alredy in use, must try another
	USER_OK,			// 5: Correct USER sent (valid)
	AUTHENTICATED		// 6: Registration complete, you chan chat now
};

class Client
{
	private:
		int			_fd;
		std::string	_user_name;
		std::string	_nickname;
		std::string	_realname; /* Variable required to save the 4th parameter of the USER command */	
		StatusLevel	_state; /* Current status of the client */

	public:
		/* Canonical */
		Client();
		~Client();
		Client(const Client* copy);
		Client& operator=(const Client& copy);
		Client(int _fd);

		/* getters */
		int			getFd() const;
		std::string	getNickname() const;
		std::string	getUserName() const;
		std::string	getRealName() const;
		StatusLevel	getState() const;

		/* Setters */
		void		setNickname(std::string nick);
		void		setUserName(std::string user);
		void		setRealName(std::string real);
		void		setState(StatusLevel state);
		void		setFd(int fd); // setter from fd to avoid leaks with new
		
		/* Executers */
		bool answer(std::string rpl);	// sends to client the reply message (rpl)
};

#endif
