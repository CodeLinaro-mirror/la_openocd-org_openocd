/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "ServerEventHandler.h"

Event::Event* ServerEventHandler::g_pEvent = nullptr;

ServerEventHandler::ServerEventHandler(apache::thrift::server::TServer* server)
	: m_server(server)
{
}

ServerEventHandler::~ServerEventHandler()
{
}

void ServerEventHandler::preServe()
{

}

void ServerEventHandler::processContext(void* serverContext, std::shared_ptr<::apache::thrift::protocol::TTransport> transport)
{
}

void* ServerEventHandler::createContext(std::shared_ptr<::apache::thrift::protocol::TProtocol> input, std::shared_ptr<::apache::thrift::protocol::TProtocol> output)
{
	return nullptr;
}

void ServerEventHandler::deleteContext(void* serverContext, std::shared_ptr<::apache::thrift::protocol::TProtocol> input, std::shared_ptr<::apache::thrift::protocol::TProtocol> output)
{
	//printf("Client is disconnected ");
	//check client is removed 
	if (!input->getTransport()->isOpen())
	{
		//set event.
		//printf("Client is disconnected ");
		if (ServerEventHandler::g_pEvent != nullptr)
		{
			ServerEventHandler::g_pEvent->signal();
		}
	}
}
