/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:30:13 by mwilsch           #+#    #+#             */
/*   Updated: 2023/09/17 14:59:26 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

/**
 * @brief Class to handle client-level operations
 * 
 * @param _clientSocket The client socket
 * @param _mode mode is set to 0 per RFC 2812
 * @param _isRegistered An array of booleans to know if the client is registered
 * @param _realname The realname of the client
 * @param _nickname The nickname of the client
 * @param _username The username of the client
 * @param _unused Set to '*' per RFC 2812
 * @param _userType The type of user (USER, SERVER_OP, CHANNEL_OP)
 * 
 */
class ClientData {
	private:
		int									_clientSocket;
		int									_mode;
		string								_realname;
		string								_nickname;
		string								_username;
		string								_unused;
		bool								_registration;
	public:
		/*			CLASS DEFAULT FUNCTIONS			*/
		
		ClientData( void );
		ClientData( int clientSocket, unsigned int clientsNumber);
		~ClientData();

		/*			MEMBER FUNCTIONS			*/

		

		/*			GETTERS			*/

		int									getClientSocket( void ) const { return _clientSocket; };
		
		int		getMode();
		string	getRealname();
		string	getNickname();
		string	getUsername();
		string 	getUnused();
		bool	getRegistration();


		/*			SETTERS			 */

		void	setmode(int mode);
		void	setRealname(string realname);
		void	setNickname(string nickname);
		void	setUsername(string username);
		void	setUnused(string unused);
		void	setRegistration( bool b);

};

/**
 * @brief Class to handle client-level operations
 * 
 * @param _usedNicknames A set of used nicknames
 * @param _activeClientsBySocket A map of active clients by socket
 * 
 */
class ClientManager {
	private:
		set <string>						_usedNicknames;
		map <int, ClientData>				_ClientsBySocket;
	public:
		/*			CLASS DEFAULT FUNCTIONS			*/
		
		ClientManager( void );
		~ClientManager();

		/*			MEMBER FUNCTIONS			*/
		
		void								addClient( int clientSocket);
		void								removeClient( int clientSocket );

		/*			GETTERS			*/

		ClientData&							getClientData( int clientSocket );
		map<int, ClientData>&				getClientBySocket();
};