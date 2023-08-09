/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "ClientCallback.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class ClientCallbackHandler : virtual public ClientCallbackIf {
 public:
  ClientCallbackHandler() {
    // Your initialization goes here
  }

  void onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description) {
    // Your implementation goes here
    printf("onMessage\n");
  }

  void onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo) {
    // Your implementation goes here
    printf("onDeviceConnected\n");
  }

  void onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo) {
    // Your implementation goes here
    printf("onDeviceDisconnected\n");
  }

  void onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode) {
    // Your implementation goes here
    printf("onDeviceModeChange\n");
  }

  void onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo) {
    // Your implementation goes here
    printf("onProtocolAdded\n");
  }

  void onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo) {
    // Your implementation goes here
    printf("onProtocolRemoved\n");
  }

  void onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState) {
    // Your implementation goes here
    printf("onProtocolStateChange\n");
  }

  void onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus) {
    // Your implementation goes here
    printf("onProtocolFlowControlStatusChange\n");
  }

  void onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus) {
    // Your implementation goes here
    printf("onProtocolLockStatusChange\n");
  }

  void onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus) {
    // Your implementation goes here
    printf("onProtocolMbnDownloadStatusChange\n");
  }

  void onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason) {
    // Your implementation goes here
    printf("onClientCloseRequest\n");
  }

  void onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid) {
    // Your implementation goes here
    printf("onMissingQShrinkHashFile\n");
  }

  void onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid) {
    // Your implementation goes here
    printf("onLogSessionMissingQShrinkHashFile\n");
  }

  void onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId) {
    // Your implementation goes here
    printf("onAsyncResponse\n");
  }

  void onDataQueueUpdated(const std::string& queueName, const int32_t queueSize) {
    // Your implementation goes here
    printf("onDataQueueUpdated\n");
  }

  void onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished) {
    // Your implementation goes here
    printf("onDataViewUpdated\n");
  }

  void onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle) {
    // Your implementation goes here
    printf("onServiceAvailable\n");
  }

  void onServiceEnded(const std::string& serviceName, const int64_t deviceHandle) {
    // Your implementation goes here
    printf("onServiceEnded\n");
  }

  void onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription) {
    // Your implementation goes here
    printf("onServiceEvent\n");
  }

  void onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription) {
    // Your implementation goes here
    printf("onImageManagementServiceEvent\n");
  }

  void onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription) {
    // Your implementation goes here
    printf("onDeviceConfigServiceEvent\n");
  }

  void onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState) {
    // Your implementation goes here
    printf("onQShrinkStateUpdated\n");
  }

  void onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo) {
    // Your implementation goes here
    printf("onDecryptionKeyStatusUpdate\n");
  }

  void onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo) {
    // Your implementation goes here
    printf("onLogSessionDecryptionKeyStatusUpdate\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<ClientCallbackHandler> handler(new ClientCallbackHandler());
  ::std::shared_ptr<TProcessor> processor(new ClientCallbackProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

