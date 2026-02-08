/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:14:52 by lprieto-          #+#    #+#             */
/*   Updated: 2026/02/02 17:49:39 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include "Channel.hpp"

class Server {

	private:
		/* core */
		int			_socket_fd;				/* file descriptor that identifies the fd of the ircserver */
		bool		_server_up;				/* server status up true, down false */
		int			_port; 					/* active port */
		std::string	_ip_address; 			/* string containing the server's IP address */
		int			_connection_nbr;		/* active connection count */
		std::vector<pollfd> _pfds;			/* continuous blocks vector for poll */
		std::map<int, std::string> _buffers;
		static bool _signal;				/* flag for shutdown signal */

		/* data */
		std::string							_password;			/* Password to access the server */
		std::map< int, Client >				_client_list_fd;	/* List of users connected with their _fd as key */
		std::map< std::string , Client* >	_client_list_name;	/* List of pointers to users connected with their user_name as the key*/
		std::map< std::string, Channel >	_channel_list;		/* list of active channels */
		
		/* Getters */
		std::string	getPassword();                          /* Returns the private _password variable */
		Channel&	getChannel(std::string channel_name);   /* Returns the channel matching the given name key */
		int			getSocketFd();                          /* Returns the private _socket_fd variable */
		Client*		getClientNick(std::string nick_name);	/* Returns the client pointer matching the nickname key */
		
		/* setters */
		e_rpl		addNewChannel(std::string name, Client* client);

		/* parse */
		void		replySorting(e_rpl rpl, Client* client, std::string channel, std::string extra);	/* Will sort the corresponding rpl Macro and call asnwer in the client */

		e_rpl       parsePassword(std::vector<std::string> cmd_line, Client* client);
		e_rpl       parseUserName(std::vector<std::string> cmd_line, Client* client);
		e_rpl       parseNickName(std::vector<std::string> cmd_line, Client* client, std::string *extra);

		e_rpl       parseCommand(std::string cmd_line, Client* client, std::string *channel, std::string *extra);

		e_rpl       parsePrivmsg(std::vector<std::string> cmd_line, Client* client, std::string *extra);
		e_rpl       parseJoin(std::vector<std::string> cmd_line, Client* client, std::string *channel, std::string *extra);
		e_rpl       parseInvite(std::vector<std::string> cmd_line, Client* client, std::string *channel, std::string *extra);
		e_rpl       parseKick(std::vector<std::string> cmd_line, Client* client, std::string *channel, std::string *extra);
		e_rpl       parseTopic(std::vector<std::string> cmd_line, Client* client, std::string *channel, std::string *extra);
		e_rpl       parseMode(std::vector<std::string> cmd_line, Client* client, std::string *channel, std::string *extra);
		e_rpl 		parseWho(std::vector<std::string> cmd_line, Client* client, std::string *channel, std::string *extra);
		e_rpl       parsePart(std::vector<std::string> cmd_line, Client* client, std::string *channel, std::string *extra);
		e_rpl       parseQuit(std::vector<std::string> cmd_line, Client* client);


	public:
		/* Canonical */
		Server();
		~Server();
		Server(const Server& copy);
		Server& operator=(const Server& copy);

		Server(std::string port, std::string password); /* default passwordless constructor */
		
		/* signal */
		static void signalHandler(int signum);			/* signal handler */

		/* core */
		int		createSocketFd();		/* Create and save the socket file (connection) */
		bool	bindSocket();			/* Performs the binding of the port/ip to the socket */
		bool	listenSocket();			/* performs listen, listens on the specified port */
		void	initPoll();
		void	runLoop();
		int		acceptSocket();			/* accepts connection (or not) and returns a new fd (client) */
		void	handleNewConnection();
		void	handleClientRead(size_t i);
		void    disconnectClient(size_t i, std::string msg = "");

		/* Authentication parsing */
		e_rpl       parseAuthentication(std::string client_line, Client* client, std::string *extra);   /* Validates password, nick, and username via sub-parsers and triggers replySorting */

		/* Communication Init */
		void        parseInit(std::string client_line, Client* client);             /* Identifies and calls the appropriate parse method to trigger execution and replySorting */

		
};

// COLORS
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define WHITE   "\033[1;37m"
#define RESET   "\033[0m"

#endif
