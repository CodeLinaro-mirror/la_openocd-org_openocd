/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#pragma once
#include <thrift/server/TServer.h>
#include "Event.h"
class ServerEventHandler : public apache::thrift::server::TServerEventHandler
{
public:
	static Event::Event* g_pEvent;

	ServerEventHandler(apache::thrift::server::TServer* server);
	virtual ~ServerEventHandler();

	virtual void preServe() override;
	virtual void processContext(void* serverContext, std::shared_ptr<::apache::thrift::protocol::TTransport> transport) override;
	virtual void* createContext(std::shared_ptr<::apache::thrift::protocol::TProtocol> input, std::shared_ptr<::apache::thrift::protocol::TProtocol> output) override;
	virtual void deleteContext(void* serverContext, std::shared_ptr<::apache::thrift::protocol::TProtocol> input, std::shared_ptr<::apache::thrift::protocol::TProtocol> output) override;

private:
	apache::thrift::server::TServer* m_server;
};

