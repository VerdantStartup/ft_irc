/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:58:39 by ahammout          #+#    #+#             */
/*   Updated: 2023/10/15 14:23:25 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExecuteCommands.hpp"

// void ExecuteCommands::invite(ServerReactor &_server, Message &Message, int clientSocket) {
//     if (Message.getParams().size() < 2)
//         throw ServerException(ERR_NEEDMOREPARAMS(Message.getCommand()));

//     vector<string> params = Message.getParams();
//     string channelName = params[1];
//     ChannelData& channel = _server.getChannelManager().getChannelByName(channelName);

//     if (!_server.doesChannelExist(params[1]))
//         throw ServerException(ERR_NOSUCHCHANNEL(channelName));

//     if (!channel.isCLient(clientSocket))
//         throw ServerException(ERR_NOTONCHANNEL(channelName));

//     if (!channel.isOperator(clientSocket))
//         throw ServerException(ERR_CHANOPRIVSNEEDED(channelName));

// 		if (_server.getClientManager().MatchNickName(channel.getClientSockets(), params[0]) != -1)
// 				throw ServerException(ERR_USERONCHANNEL(params[0], channelName));

//     int targetFD = _server.getClientManager().getClientSocketByNick(params[0]);
//     if (targetFD == -1)
//         throw ServerException(ERR_NOSUCHNICKCHANNEL(params[0], channelName));

//     channel.addGuest(params[0]);
//     _server.sendMsg_FixLater(targetFD, _server.createInfoMsg(_server.getClientDataFast(clientSocket), Message.getCommand(), params));
// 		_server.sendNumericReply_FixLater(clientSocket, RPL_INVITING(_server.getClientDataFast(clientSocket).getNickname(), channelName, params[0]));
// }


void     ExecuteCommands::invite(ServerReactor &_server, Message &Message, int clientSocket){

    if (Message.getParams().size() < 2) {
        _server.sendNumericReply_FixLater(clientSocket, ERR_NEEDMOREPARAMS(Message.getCommand()));
        return ;
    }
		vector<string>	params = Message.getParams();
    string					channelName = params[1];
		ChannelData&		channel = _server.getChannelManager().getChannelByName(channelName);
		
    if (!_server.doesChannelExist(params[1])) {
        _server.sendNumericReply_FixLater(clientSocket, ERR_NOSUCHCHANNEL(channelName));
        return ;
    }
    if (!channel.isCLient(clientSocket)) {
        _server.sendNumericReply_FixLater(clientSocket, ERR_NOTONCHANNEL(channelName));
        return ;
    }
    if (!channel.isOperator(clientSocket)) {
        _server.sendNumericReply_FixLater(clientSocket, ERR_CHANOPRIVSNEEDED(channelName));
        return ;
    }
		if (_server.getClientManager().MatchNickName(channel.getClientSockets(), params[0]) != -1) { 
				_server.sendNumericReply_FixLater(clientSocket, ERR_USERONCHANNEL(params[0], channelName));
        return ;
		}
		int targetFD = _server.getClientManager().getClientSocketByNick(params[0]);
		if (targetFD == -1) {
				_server.sendNumericReply_FixLater(clientSocket, ERR_NOSUCHNICKCHANNEL(params[0], channelName));
				return ;
		}
		channel.addGuest(params[0]);
		_server.sendMsg_FixLater(targetFD, _server.createInfoMsg(_server.getClientDataFast(clientSocket), Message.getCommand(), params));
		_server.sendNumericReply_FixLater(clientSocket, RPL_INVITING(_server.getClientDataFast(clientSocket).getNickname(), channelName, params[0]));
}
