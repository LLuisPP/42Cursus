/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:25:57 by lgracia-          #+#    #+#             */
/*   Updated: 2026/02/01 21:19:47 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include "Client.hpp"
#include <limits>

#define MAX_CHANNEL std::numeric_limits<size_t>::max()

class Channel
{
	private:
		std::string	_channel_name;
		std::map<std::string, Client*>	_user_list;
		std::map<std::string, Client*>	_operator_list;
		std::map<std::string, Client*>	_invite_list;
		size_t		_limit_n_users;
		std::string _key;
		bool		_mode_i;
		bool		_mode_t;
		bool		_mode_k;
		bool		_mode_l;
		std::string	_topic;
		void		operatorsLeft();

	public:
		/*Canonical*/
		Channel();
		~Channel();
		Channel(const Channel& copy);
		Channel& operator=(const Channel& copy);
		
		Channel(std::string name, Client* client);

		/*getters*/
		std::string	getName();
		std::map<std::string, Client*>	&getUserList();
		std::string getNamesList();
		size_t		getLimitNUsers();
		std::string getKey();
		bool		getMode(char mode_flag);
		std::string getModesString();
		std::string	getTopic();
		bool		isInChannelUserList(std::string nick_name);
		bool		isInChannelOperatorList(std::string nick_name);
		bool		isInChannelInviteList(std::string nick_name);
		size_t		getNumOperators();

		/*setters*/
		short		setMode(char mode_flag, bool set);
		std::string	setKey(std::string new_key);
		size_t		setLimitNUsers(size_t n);
		void		setTopic(std::string new_topic);

		/*executers*/
		e_rpl		addUser(Client* client);
		void		deleteUser(Client*	client);
		void		addUserOperator(Client* client);
		void		deleteUserOperator(Client* client);
		void		addUserInvite(Client* client);
		void		deleteUserInvite(Client* client);
		void		spreadMsg(std::string msg);
		bool		usersLeft();
};

#endif
