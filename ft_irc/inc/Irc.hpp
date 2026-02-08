/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprieto- <lprieto-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:35:24 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/01 18:55:54 by lprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_HPP
# define IRC_HPP

#include <string>              /* std::string */
#include <cstring>             /* C string utilities (memset, strcmp, etc.) */

#include <iostream>            /* std::cout, std::cerr */
#include <sstream>             /* std::stringstream for parsing */
#include <exception>           /* std::exception base class */

#include <vector>              /* dynamic array container */
#include <map>                 /* associative container (key-value) */

#include <cstdlib>             /* general utilities (atoi, exit, etc.) */
#include <csignal>             /* signal handling (signal, sigaction) */

#include <unistd.h>            /* POSIX API: close(), read(), write() */
#include <fcntl.h>             /* file descriptor control (O_NONBLOCK, fcntl) */
#include <sys/types.h>         /* fundamental system data types */
#include <sys/socket.h>        /* socket API: socket, bind, listen, accept, send, recv */

#include <netinet/in.h>        /* sockaddr_in, IP protocols */
#include <arpa/inet.h>         /* IP address conversion (inet_ntoa, htons, etc.) */

#include <poll.h>              /* I/O multiplexing with poll() */


/* *********************** Utils ********************************************** */
std::string					itoa(int i);
std::vector<std::string>	splitCommand(std::string input);
bool						parseNameProtocol();	// will parse any name or password with a stablished protocol
void						logInput(int fd, std::string msg);
void						logOutput(int fd, std::string msg);
bool						get_monitoring(bool modify, bool status);

/* ANSWERS (RPL) */
#define WELCOME				" :Welcome to the FT_IRC Network, "
#define YOURHOST			" :Your host is ft_irc, running version 1.0\r\n"
#define CREATED				" :This server was created today\r\n"
#define MYINFO				" :ft_irc 1.0 i o\r\n"
#define TOPIC				" :"
#define INVITING			" :"
#define NOTOPIC				" :No topic is set"
#define ENDOFWHO 			" :End of /WHO list"
#define NAMREPLY			" ="
#define ENDOFNAMES			" :End of /NAMES list"
#define WHOREPLY 			" "

/* ERRORS (ERR) => (400-599) */
#define NOSUCHNICK			" :No such nick/channel\r\n"
#define NOSUCHCHANNEL		" :No such channel\r\n"
#define CANNOTSENDTOCHAN	" :Cannot send to channel\r\n"
#define NORECIPIENT			" :No recipient given\r\n"
#define NOTEXTTOSEND		" :No text to send\r\n"
#define UNKNOWNCOMMAND		" :Unknown command\r\n"
#define NONICKNAMEGIVEN		" :No nickname given\r\n"
#define ERRONEUSNICKNAME	" :Erroneous nickname\r\n"
#define NICKNAMEINUSE       " :Nickname is already in use\r\n"
#define USERNOTINCHANNEL    " :They aren't on that channel\r\n"
#define NOTONCHANNEL		" :You're not on that channel\r\n"
#define USERONCHANNEL		" :is already on channel\r\n"
#define NOTREGISTERED		" :You have not registered\r\n"
#define NEEDMOREPARAMS		" :Not enough parameters\r\n"
#define ALREADYREGISTRED	" :Unauthorized command (already registered)\r\n"
#define PASSWDMISMATCH		" :Password incorrect\r\n"
#define CHANNELISFULL		" :Cannot join channel (+l)\r\n"
#define UNKNOWNMODE			" :is unknown mode char to me\r\n"
#define INVITEONLYCHAN		" :Cannot join channel (+i)\r\n"
#define BADCHANNELKEY		" :Cannot join channel (+k)\r\n"
#define CHANOPRIVSNEEDED	" :You're not channel operator\r\n"
#define UMODEUNKNOWNFLAG	" :Unknown MODE flag\r\n"


/* REPLY ENUMERATION */

enum	e_rpl
{
	/* --- Successfull (001-399) --- */
	RPL_WELCOME = 001,
	RPL_YOURHOST = 002,
	RPL_CREATED = 003,
	RPL_MYINFO = 004,
	RPL_ENDOFWHO = 315,
	RPL_CHANNELMODEIS = 324,
	RPL_NOTOPIC = 331,
	RPL_TOPIC = 332,
	RPL_INVITING = 341,
	RPL_WHOREPLY = 352,
	RPL_NAMREPLY = 353,
	RPL_ENDOFNAMES = 366,
	
	/* --- Errors (400-599) --- */
	ERR_NOSUCHNICK = 401,
	ERR_NOSUCHCHANNEL = 403,
	ERR_CANNOTSENDTOCHAN = 404,
	ERR_NORECIPIENT = 411,
	ERR_NOTEXTTOSEND = 412,
	ERR_UNKNOWNCOMMAND = 421,
	ERR_NONICKNAMEGIVEN = 431,
	ERR_ERRONEUSNICKNAME = 432,
	ERR_NICKNAMEINUSE = 433,
	ERR_USERNOTINCHANNEL = 441,
	ERR_NOTONCHANNEL = 442,
	ERR_USERONCHANNEL = 443,
	ERR_NOTREGISTERED = 451,
	ERR_NEEDMOREPARAMS = 461,
	ERR_ALREADYREGISTRED = 462,
	ERR_PASSWDMISMATCH = 464,
	ERR_CHANNELISFULL = 471,
	ERR_UNKNOWNMODE = 472,
	ERR_INVITEONLYCHAN = 473,
	ERR_BADCHANNELKEY = 475,
	ERR_CHANOPRIVSNEEDED = 482,
	ERR_UMODEUNKNOWNFLAG = 501,
	
	/* --- Internal Control --- */
	EXIT = 0,
	ERROR = -1,
	ERROR_LASTOPERATOR=-2,	// to avoid losing control of a channel
	BROADCAST=-3	// for spreadMsg when calling replysorting
};

#endif
