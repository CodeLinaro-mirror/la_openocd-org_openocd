/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef ClientCallback_H
#define ClientCallback_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "ClientCallback_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ClientCallbackIf {
 public:
  virtual ~ClientCallbackIf() {}
  virtual void onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description) = 0;
  virtual void onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo) = 0;
  virtual void onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo) = 0;
  virtual void onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode) = 0;
  virtual void onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo) = 0;
  virtual void onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo) = 0;
  virtual void onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState) = 0;
  virtual void onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus) = 0;
  virtual void onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus) = 0;
  virtual void onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus) = 0;
  virtual void onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason) = 0;
  virtual void onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid) = 0;
  virtual void onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid) = 0;
  virtual void onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId) = 0;
  virtual void onDataQueueUpdated(const std::string& queueName, const int32_t queueSize) = 0;
  virtual void onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished) = 0;
  virtual void onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle) = 0;
  virtual void onServiceEnded(const std::string& serviceName, const int64_t deviceHandle) = 0;
  virtual void onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription) = 0;
  virtual void onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription) = 0;
  virtual void onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription) = 0;
  virtual void onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState) = 0;
  virtual void onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo) = 0;
  virtual void onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo) = 0;
};

class ClientCallbackIfFactory {
 public:
  typedef ClientCallbackIf Handler;

  virtual ~ClientCallbackIfFactory() {}

  virtual ClientCallbackIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ClientCallbackIf* /* handler */) = 0;
};

class ClientCallbackIfSingletonFactory : virtual public ClientCallbackIfFactory {
 public:
  ClientCallbackIfSingletonFactory(const ::std::shared_ptr<ClientCallbackIf>& iface) : iface_(iface) {}
  virtual ~ClientCallbackIfSingletonFactory() {}

  virtual ClientCallbackIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ClientCallbackIf* /* handler */) {}

 protected:
  ::std::shared_ptr<ClientCallbackIf> iface_;
};

class ClientCallbackNull : virtual public ClientCallbackIf {
 public:
  virtual ~ClientCallbackNull() {}
  void onMessage(const MessageLevel::type /* level */, const std::string& /* location */, const std::string& /* title */, const std::string& /* description */) {
    return;
  }
  void onDeviceConnected(const  ::Uts::DeviceInfo& /* deviceInfo */) {
    return;
  }
  void onDeviceDisconnected(const  ::Uts::DeviceInfo& /* deviceInfo */) {
    return;
  }
  void onDeviceModeChange(const int64_t /* deviceHandle */, const  ::Uts::DeviceMode::type /* newMode */) {
    return;
  }
  void onProtocolAdded(const  ::Uts::DeviceInfo& /* deviceInfo */, const  ::Uts::ProtocolInfo& /* protocolInfo */) {
    return;
  }
  void onProtocolRemoved(const  ::Uts::DeviceInfo& /* deviceInfo */, const  ::Uts::ProtocolInfo& /* protocolInfo */) {
    return;
  }
  void onProtocolStateChange(const int64_t /* protocolHandle */, const  ::Uts::ProtocolState::type /* newState */) {
    return;
  }
  void onProtocolFlowControlStatusChange(const int64_t /* protocolHandle */, const  ::Uts::Direction::type /* dir */, const  ::Uts::FlowControlStatus::type /* newStatus */) {
    return;
  }
  void onProtocolLockStatusChange(const int64_t /* protocolHandle */, const  ::Uts::LockStatus& /* newStatus */) {
    return;
  }
  void onProtocolMbnDownloadStatusChange(const int64_t /* protocolHandle */, const  ::Uts::MbnDownloadStatus& /* newStatus */) {
    return;
  }
  void onClientCloseRequest(const  ::Uts::ClientCloseReason& /* closeReason */) {
    return;
  }
  void onMissingQShrinkHashFile(const int64_t /* protocolHandle */, const std::string& /* missingFileGuid */) {
    return;
  }
  void onLogSessionMissingQShrinkHashFile(const std::string& /* logSessionInstance */, const int64_t /* protocolHandle */, const std::string& /* missingFileGuid */) {
    return;
  }
  void onAsyncResponse(const int64_t /* protocolHandle */, const int64_t /* transactionId */) {
    return;
  }
  void onDataQueueUpdated(const std::string& /* queueName */, const int32_t /* queueSize */) {
    return;
  }
  void onDataViewUpdated(const std::string& /* viewName */, const int32_t /* viewSize */, const bool /* finished */) {
    return;
  }
  void onServiceAvailable(const std::string& /* serviceName */, const int64_t /* deviceHandle */) {
    return;
  }
  void onServiceEnded(const std::string& /* serviceName */, const int64_t /* deviceHandle */) {
    return;
  }
  void onServiceEvent(const std::string& /* serviceName */, const int64_t /* eventId */, const std::string& /* eventDescription */) {
    return;
  }
  void onImageManagementServiceEvent(const std::string& /* serviceName */, const int64_t /* deviceHandle */, const int64_t /* protocolHandle */, const int64_t /* eventId */, const std::string& /* eventDescription */) {
    return;
  }
  void onDeviceConfigServiceEvent(const std::string& /* serviceName */, const int64_t /* deviceHandle */, const int64_t /* protocolHandle */, const int64_t /* eventId */, const std::string& /* eventDescription */) {
    return;
  }
  void onQShrinkStateUpdated(const int64_t /* protocolHandle */, const  ::Uts::QShrink4DownloadState::type /* newState */) {
    return;
  }
  void onDecryptionKeyStatusUpdate(const int64_t /* protocolHandle */, const  ::Uts::KeyInfo& /* keyInfo */) {
    return;
  }
  void onLogSessionDecryptionKeyStatusUpdate(const std::string& /* logSesssionInstance */, const int64_t /* protocolHandle */, const  ::Uts::KeyInfo& /* keyInfo */) {
    return;
  }
};

typedef struct _ClientCallback_onMessage_args__isset {
  _ClientCallback_onMessage_args__isset() : level(false), location(false), title(false), description(false) {}
  bool level :1;
  bool location :1;
  bool title :1;
  bool description :1;
} _ClientCallback_onMessage_args__isset;

class ClientCallback_onMessage_args {
 public:

  ClientCallback_onMessage_args(const ClientCallback_onMessage_args&);
  ClientCallback_onMessage_args& operator=(const ClientCallback_onMessage_args&);
  ClientCallback_onMessage_args() : level((MessageLevel::type)0), location(), title(), description() {
  }

  virtual ~ClientCallback_onMessage_args() noexcept;
  MessageLevel::type level;
  std::string location;
  std::string title;
  std::string description;

  _ClientCallback_onMessage_args__isset __isset;

  void __set_level(const MessageLevel::type val);

  void __set_location(const std::string& val);

  void __set_title(const std::string& val);

  void __set_description(const std::string& val);

  bool operator == (const ClientCallback_onMessage_args & rhs) const
  {
    if (!(level == rhs.level))
      return false;
    if (!(location == rhs.location))
      return false;
    if (!(title == rhs.title))
      return false;
    if (!(description == rhs.description))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onMessage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onMessage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onMessage_pargs {
 public:


  virtual ~ClientCallback_onMessage_pargs() noexcept;
  const MessageLevel::type* level;
  const std::string* location;
  const std::string* title;
  const std::string* description;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onDeviceConnected_args__isset {
  _ClientCallback_onDeviceConnected_args__isset() : deviceInfo(false) {}
  bool deviceInfo :1;
} _ClientCallback_onDeviceConnected_args__isset;

class ClientCallback_onDeviceConnected_args {
 public:

  ClientCallback_onDeviceConnected_args(const ClientCallback_onDeviceConnected_args&);
  ClientCallback_onDeviceConnected_args& operator=(const ClientCallback_onDeviceConnected_args&);
  ClientCallback_onDeviceConnected_args() {
  }

  virtual ~ClientCallback_onDeviceConnected_args() noexcept;
   ::Uts::DeviceInfo deviceInfo;

  _ClientCallback_onDeviceConnected_args__isset __isset;

  void __set_deviceInfo(const  ::Uts::DeviceInfo& val);

  bool operator == (const ClientCallback_onDeviceConnected_args & rhs) const
  {
    if (!(deviceInfo == rhs.deviceInfo))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onDeviceConnected_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onDeviceConnected_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onDeviceConnected_pargs {
 public:


  virtual ~ClientCallback_onDeviceConnected_pargs() noexcept;
  const  ::Uts::DeviceInfo* deviceInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onDeviceDisconnected_args__isset {
  _ClientCallback_onDeviceDisconnected_args__isset() : deviceInfo(false) {}
  bool deviceInfo :1;
} _ClientCallback_onDeviceDisconnected_args__isset;

class ClientCallback_onDeviceDisconnected_args {
 public:

  ClientCallback_onDeviceDisconnected_args(const ClientCallback_onDeviceDisconnected_args&);
  ClientCallback_onDeviceDisconnected_args& operator=(const ClientCallback_onDeviceDisconnected_args&);
  ClientCallback_onDeviceDisconnected_args() {
  }

  virtual ~ClientCallback_onDeviceDisconnected_args() noexcept;
   ::Uts::DeviceInfo deviceInfo;

  _ClientCallback_onDeviceDisconnected_args__isset __isset;

  void __set_deviceInfo(const  ::Uts::DeviceInfo& val);

  bool operator == (const ClientCallback_onDeviceDisconnected_args & rhs) const
  {
    if (!(deviceInfo == rhs.deviceInfo))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onDeviceDisconnected_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onDeviceDisconnected_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onDeviceDisconnected_pargs {
 public:


  virtual ~ClientCallback_onDeviceDisconnected_pargs() noexcept;
  const  ::Uts::DeviceInfo* deviceInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onDeviceModeChange_args__isset {
  _ClientCallback_onDeviceModeChange_args__isset() : deviceHandle(false), newMode(false) {}
  bool deviceHandle :1;
  bool newMode :1;
} _ClientCallback_onDeviceModeChange_args__isset;

class ClientCallback_onDeviceModeChange_args {
 public:

  ClientCallback_onDeviceModeChange_args(const ClientCallback_onDeviceModeChange_args&);
  ClientCallback_onDeviceModeChange_args& operator=(const ClientCallback_onDeviceModeChange_args&);
  ClientCallback_onDeviceModeChange_args() : deviceHandle(0), newMode(( ::Uts::DeviceMode::type)0) {
  }

  virtual ~ClientCallback_onDeviceModeChange_args() noexcept;
  int64_t deviceHandle;
   ::Uts::DeviceMode::type newMode;

  _ClientCallback_onDeviceModeChange_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_newMode(const  ::Uts::DeviceMode::type val);

  bool operator == (const ClientCallback_onDeviceModeChange_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(newMode == rhs.newMode))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onDeviceModeChange_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onDeviceModeChange_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onDeviceModeChange_pargs {
 public:


  virtual ~ClientCallback_onDeviceModeChange_pargs() noexcept;
  const int64_t* deviceHandle;
  const  ::Uts::DeviceMode::type* newMode;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onProtocolAdded_args__isset {
  _ClientCallback_onProtocolAdded_args__isset() : deviceInfo(false), protocolInfo(false) {}
  bool deviceInfo :1;
  bool protocolInfo :1;
} _ClientCallback_onProtocolAdded_args__isset;

class ClientCallback_onProtocolAdded_args {
 public:

  ClientCallback_onProtocolAdded_args(const ClientCallback_onProtocolAdded_args&);
  ClientCallback_onProtocolAdded_args& operator=(const ClientCallback_onProtocolAdded_args&);
  ClientCallback_onProtocolAdded_args() {
  }

  virtual ~ClientCallback_onProtocolAdded_args() noexcept;
   ::Uts::DeviceInfo deviceInfo;
   ::Uts::ProtocolInfo protocolInfo;

  _ClientCallback_onProtocolAdded_args__isset __isset;

  void __set_deviceInfo(const  ::Uts::DeviceInfo& val);

  void __set_protocolInfo(const  ::Uts::ProtocolInfo& val);

  bool operator == (const ClientCallback_onProtocolAdded_args & rhs) const
  {
    if (!(deviceInfo == rhs.deviceInfo))
      return false;
    if (!(protocolInfo == rhs.protocolInfo))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onProtocolAdded_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onProtocolAdded_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onProtocolAdded_pargs {
 public:


  virtual ~ClientCallback_onProtocolAdded_pargs() noexcept;
  const  ::Uts::DeviceInfo* deviceInfo;
  const  ::Uts::ProtocolInfo* protocolInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onProtocolRemoved_args__isset {
  _ClientCallback_onProtocolRemoved_args__isset() : deviceInfo(false), protocolInfo(false) {}
  bool deviceInfo :1;
  bool protocolInfo :1;
} _ClientCallback_onProtocolRemoved_args__isset;

class ClientCallback_onProtocolRemoved_args {
 public:

  ClientCallback_onProtocolRemoved_args(const ClientCallback_onProtocolRemoved_args&);
  ClientCallback_onProtocolRemoved_args& operator=(const ClientCallback_onProtocolRemoved_args&);
  ClientCallback_onProtocolRemoved_args() {
  }

  virtual ~ClientCallback_onProtocolRemoved_args() noexcept;
   ::Uts::DeviceInfo deviceInfo;
   ::Uts::ProtocolInfo protocolInfo;

  _ClientCallback_onProtocolRemoved_args__isset __isset;

  void __set_deviceInfo(const  ::Uts::DeviceInfo& val);

  void __set_protocolInfo(const  ::Uts::ProtocolInfo& val);

  bool operator == (const ClientCallback_onProtocolRemoved_args & rhs) const
  {
    if (!(deviceInfo == rhs.deviceInfo))
      return false;
    if (!(protocolInfo == rhs.protocolInfo))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onProtocolRemoved_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onProtocolRemoved_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onProtocolRemoved_pargs {
 public:


  virtual ~ClientCallback_onProtocolRemoved_pargs() noexcept;
  const  ::Uts::DeviceInfo* deviceInfo;
  const  ::Uts::ProtocolInfo* protocolInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onProtocolStateChange_args__isset {
  _ClientCallback_onProtocolStateChange_args__isset() : protocolHandle(false), newState(false) {}
  bool protocolHandle :1;
  bool newState :1;
} _ClientCallback_onProtocolStateChange_args__isset;

class ClientCallback_onProtocolStateChange_args {
 public:

  ClientCallback_onProtocolStateChange_args(const ClientCallback_onProtocolStateChange_args&);
  ClientCallback_onProtocolStateChange_args& operator=(const ClientCallback_onProtocolStateChange_args&);
  ClientCallback_onProtocolStateChange_args() : protocolHandle(0), newState(( ::Uts::ProtocolState::type)0) {
  }

  virtual ~ClientCallback_onProtocolStateChange_args() noexcept;
  int64_t protocolHandle;
   ::Uts::ProtocolState::type newState;

  _ClientCallback_onProtocolStateChange_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_newState(const  ::Uts::ProtocolState::type val);

  bool operator == (const ClientCallback_onProtocolStateChange_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(newState == rhs.newState))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onProtocolStateChange_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onProtocolStateChange_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onProtocolStateChange_pargs {
 public:


  virtual ~ClientCallback_onProtocolStateChange_pargs() noexcept;
  const int64_t* protocolHandle;
  const  ::Uts::ProtocolState::type* newState;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onProtocolFlowControlStatusChange_args__isset {
  _ClientCallback_onProtocolFlowControlStatusChange_args__isset() : protocolHandle(false), dir(false), newStatus(false) {}
  bool protocolHandle :1;
  bool dir :1;
  bool newStatus :1;
} _ClientCallback_onProtocolFlowControlStatusChange_args__isset;

class ClientCallback_onProtocolFlowControlStatusChange_args {
 public:

  ClientCallback_onProtocolFlowControlStatusChange_args(const ClientCallback_onProtocolFlowControlStatusChange_args&);
  ClientCallback_onProtocolFlowControlStatusChange_args& operator=(const ClientCallback_onProtocolFlowControlStatusChange_args&);
  ClientCallback_onProtocolFlowControlStatusChange_args() : protocolHandle(0), dir(( ::Uts::Direction::type)0), newStatus(( ::Uts::FlowControlStatus::type)0) {
  }

  virtual ~ClientCallback_onProtocolFlowControlStatusChange_args() noexcept;
  int64_t protocolHandle;
   ::Uts::Direction::type dir;
   ::Uts::FlowControlStatus::type newStatus;

  _ClientCallback_onProtocolFlowControlStatusChange_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_dir(const  ::Uts::Direction::type val);

  void __set_newStatus(const  ::Uts::FlowControlStatus::type val);

  bool operator == (const ClientCallback_onProtocolFlowControlStatusChange_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(dir == rhs.dir))
      return false;
    if (!(newStatus == rhs.newStatus))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onProtocolFlowControlStatusChange_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onProtocolFlowControlStatusChange_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onProtocolFlowControlStatusChange_pargs {
 public:


  virtual ~ClientCallback_onProtocolFlowControlStatusChange_pargs() noexcept;
  const int64_t* protocolHandle;
  const  ::Uts::Direction::type* dir;
  const  ::Uts::FlowControlStatus::type* newStatus;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onProtocolLockStatusChange_args__isset {
  _ClientCallback_onProtocolLockStatusChange_args__isset() : protocolHandle(false), newStatus(false) {}
  bool protocolHandle :1;
  bool newStatus :1;
} _ClientCallback_onProtocolLockStatusChange_args__isset;

class ClientCallback_onProtocolLockStatusChange_args {
 public:

  ClientCallback_onProtocolLockStatusChange_args(const ClientCallback_onProtocolLockStatusChange_args&);
  ClientCallback_onProtocolLockStatusChange_args& operator=(const ClientCallback_onProtocolLockStatusChange_args&);
  ClientCallback_onProtocolLockStatusChange_args() : protocolHandle(0) {
  }

  virtual ~ClientCallback_onProtocolLockStatusChange_args() noexcept;
  int64_t protocolHandle;
   ::Uts::LockStatus newStatus;

  _ClientCallback_onProtocolLockStatusChange_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_newStatus(const  ::Uts::LockStatus& val);

  bool operator == (const ClientCallback_onProtocolLockStatusChange_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(newStatus == rhs.newStatus))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onProtocolLockStatusChange_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onProtocolLockStatusChange_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onProtocolLockStatusChange_pargs {
 public:


  virtual ~ClientCallback_onProtocolLockStatusChange_pargs() noexcept;
  const int64_t* protocolHandle;
  const  ::Uts::LockStatus* newStatus;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onProtocolMbnDownloadStatusChange_args__isset {
  _ClientCallback_onProtocolMbnDownloadStatusChange_args__isset() : protocolHandle(false), newStatus(false) {}
  bool protocolHandle :1;
  bool newStatus :1;
} _ClientCallback_onProtocolMbnDownloadStatusChange_args__isset;

class ClientCallback_onProtocolMbnDownloadStatusChange_args {
 public:

  ClientCallback_onProtocolMbnDownloadStatusChange_args(const ClientCallback_onProtocolMbnDownloadStatusChange_args&);
  ClientCallback_onProtocolMbnDownloadStatusChange_args& operator=(const ClientCallback_onProtocolMbnDownloadStatusChange_args&);
  ClientCallback_onProtocolMbnDownloadStatusChange_args() : protocolHandle(0) {
  }

  virtual ~ClientCallback_onProtocolMbnDownloadStatusChange_args() noexcept;
  int64_t protocolHandle;
   ::Uts::MbnDownloadStatus newStatus;

  _ClientCallback_onProtocolMbnDownloadStatusChange_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_newStatus(const  ::Uts::MbnDownloadStatus& val);

  bool operator == (const ClientCallback_onProtocolMbnDownloadStatusChange_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(newStatus == rhs.newStatus))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onProtocolMbnDownloadStatusChange_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onProtocolMbnDownloadStatusChange_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onProtocolMbnDownloadStatusChange_pargs {
 public:


  virtual ~ClientCallback_onProtocolMbnDownloadStatusChange_pargs() noexcept;
  const int64_t* protocolHandle;
  const  ::Uts::MbnDownloadStatus* newStatus;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onClientCloseRequest_args__isset {
  _ClientCallback_onClientCloseRequest_args__isset() : closeReason(false) {}
  bool closeReason :1;
} _ClientCallback_onClientCloseRequest_args__isset;

class ClientCallback_onClientCloseRequest_args {
 public:

  ClientCallback_onClientCloseRequest_args(const ClientCallback_onClientCloseRequest_args&);
  ClientCallback_onClientCloseRequest_args& operator=(const ClientCallback_onClientCloseRequest_args&);
  ClientCallback_onClientCloseRequest_args() {
  }

  virtual ~ClientCallback_onClientCloseRequest_args() noexcept;
   ::Uts::ClientCloseReason closeReason;

  _ClientCallback_onClientCloseRequest_args__isset __isset;

  void __set_closeReason(const  ::Uts::ClientCloseReason& val);

  bool operator == (const ClientCallback_onClientCloseRequest_args & rhs) const
  {
    if (!(closeReason == rhs.closeReason))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onClientCloseRequest_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onClientCloseRequest_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onClientCloseRequest_pargs {
 public:


  virtual ~ClientCallback_onClientCloseRequest_pargs() noexcept;
  const  ::Uts::ClientCloseReason* closeReason;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onMissingQShrinkHashFile_args__isset {
  _ClientCallback_onMissingQShrinkHashFile_args__isset() : protocolHandle(false), missingFileGuid(false) {}
  bool protocolHandle :1;
  bool missingFileGuid :1;
} _ClientCallback_onMissingQShrinkHashFile_args__isset;

class ClientCallback_onMissingQShrinkHashFile_args {
 public:

  ClientCallback_onMissingQShrinkHashFile_args(const ClientCallback_onMissingQShrinkHashFile_args&);
  ClientCallback_onMissingQShrinkHashFile_args& operator=(const ClientCallback_onMissingQShrinkHashFile_args&);
  ClientCallback_onMissingQShrinkHashFile_args() : protocolHandle(0), missingFileGuid() {
  }

  virtual ~ClientCallback_onMissingQShrinkHashFile_args() noexcept;
  int64_t protocolHandle;
  std::string missingFileGuid;

  _ClientCallback_onMissingQShrinkHashFile_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_missingFileGuid(const std::string& val);

  bool operator == (const ClientCallback_onMissingQShrinkHashFile_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(missingFileGuid == rhs.missingFileGuid))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onMissingQShrinkHashFile_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onMissingQShrinkHashFile_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onMissingQShrinkHashFile_pargs {
 public:


  virtual ~ClientCallback_onMissingQShrinkHashFile_pargs() noexcept;
  const int64_t* protocolHandle;
  const std::string* missingFileGuid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onLogSessionMissingQShrinkHashFile_args__isset {
  _ClientCallback_onLogSessionMissingQShrinkHashFile_args__isset() : logSessionInstance(false), protocolHandle(false), missingFileGuid(false) {}
  bool logSessionInstance :1;
  bool protocolHandle :1;
  bool missingFileGuid :1;
} _ClientCallback_onLogSessionMissingQShrinkHashFile_args__isset;

class ClientCallback_onLogSessionMissingQShrinkHashFile_args {
 public:

  ClientCallback_onLogSessionMissingQShrinkHashFile_args(const ClientCallback_onLogSessionMissingQShrinkHashFile_args&);
  ClientCallback_onLogSessionMissingQShrinkHashFile_args& operator=(const ClientCallback_onLogSessionMissingQShrinkHashFile_args&);
  ClientCallback_onLogSessionMissingQShrinkHashFile_args() : logSessionInstance(), protocolHandle(0), missingFileGuid() {
  }

  virtual ~ClientCallback_onLogSessionMissingQShrinkHashFile_args() noexcept;
  std::string logSessionInstance;
  int64_t protocolHandle;
  std::string missingFileGuid;

  _ClientCallback_onLogSessionMissingQShrinkHashFile_args__isset __isset;

  void __set_logSessionInstance(const std::string& val);

  void __set_protocolHandle(const int64_t val);

  void __set_missingFileGuid(const std::string& val);

  bool operator == (const ClientCallback_onLogSessionMissingQShrinkHashFile_args & rhs) const
  {
    if (!(logSessionInstance == rhs.logSessionInstance))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(missingFileGuid == rhs.missingFileGuid))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onLogSessionMissingQShrinkHashFile_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onLogSessionMissingQShrinkHashFile_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onLogSessionMissingQShrinkHashFile_pargs {
 public:


  virtual ~ClientCallback_onLogSessionMissingQShrinkHashFile_pargs() noexcept;
  const std::string* logSessionInstance;
  const int64_t* protocolHandle;
  const std::string* missingFileGuid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onAsyncResponse_args__isset {
  _ClientCallback_onAsyncResponse_args__isset() : protocolHandle(false), transactionId(false) {}
  bool protocolHandle :1;
  bool transactionId :1;
} _ClientCallback_onAsyncResponse_args__isset;

class ClientCallback_onAsyncResponse_args {
 public:

  ClientCallback_onAsyncResponse_args(const ClientCallback_onAsyncResponse_args&);
  ClientCallback_onAsyncResponse_args& operator=(const ClientCallback_onAsyncResponse_args&);
  ClientCallback_onAsyncResponse_args() : protocolHandle(0), transactionId(0) {
  }

  virtual ~ClientCallback_onAsyncResponse_args() noexcept;
  int64_t protocolHandle;
  int64_t transactionId;

  _ClientCallback_onAsyncResponse_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_transactionId(const int64_t val);

  bool operator == (const ClientCallback_onAsyncResponse_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(transactionId == rhs.transactionId))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onAsyncResponse_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onAsyncResponse_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onAsyncResponse_pargs {
 public:


  virtual ~ClientCallback_onAsyncResponse_pargs() noexcept;
  const int64_t* protocolHandle;
  const int64_t* transactionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onDataQueueUpdated_args__isset {
  _ClientCallback_onDataQueueUpdated_args__isset() : queueName(false), queueSize(false) {}
  bool queueName :1;
  bool queueSize :1;
} _ClientCallback_onDataQueueUpdated_args__isset;

class ClientCallback_onDataQueueUpdated_args {
 public:

  ClientCallback_onDataQueueUpdated_args(const ClientCallback_onDataQueueUpdated_args&);
  ClientCallback_onDataQueueUpdated_args& operator=(const ClientCallback_onDataQueueUpdated_args&);
  ClientCallback_onDataQueueUpdated_args() : queueName(), queueSize(0) {
  }

  virtual ~ClientCallback_onDataQueueUpdated_args() noexcept;
  std::string queueName;
  int32_t queueSize;

  _ClientCallback_onDataQueueUpdated_args__isset __isset;

  void __set_queueName(const std::string& val);

  void __set_queueSize(const int32_t val);

  bool operator == (const ClientCallback_onDataQueueUpdated_args & rhs) const
  {
    if (!(queueName == rhs.queueName))
      return false;
    if (!(queueSize == rhs.queueSize))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onDataQueueUpdated_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onDataQueueUpdated_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onDataQueueUpdated_pargs {
 public:


  virtual ~ClientCallback_onDataQueueUpdated_pargs() noexcept;
  const std::string* queueName;
  const int32_t* queueSize;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onDataViewUpdated_args__isset {
  _ClientCallback_onDataViewUpdated_args__isset() : viewName(false), viewSize(false), finished(false) {}
  bool viewName :1;
  bool viewSize :1;
  bool finished :1;
} _ClientCallback_onDataViewUpdated_args__isset;

class ClientCallback_onDataViewUpdated_args {
 public:

  ClientCallback_onDataViewUpdated_args(const ClientCallback_onDataViewUpdated_args&);
  ClientCallback_onDataViewUpdated_args& operator=(const ClientCallback_onDataViewUpdated_args&);
  ClientCallback_onDataViewUpdated_args() : viewName(), viewSize(0), finished(0) {
  }

  virtual ~ClientCallback_onDataViewUpdated_args() noexcept;
  std::string viewName;
  int32_t viewSize;
  bool finished;

  _ClientCallback_onDataViewUpdated_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_viewSize(const int32_t val);

  void __set_finished(const bool val);

  bool operator == (const ClientCallback_onDataViewUpdated_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(viewSize == rhs.viewSize))
      return false;
    if (!(finished == rhs.finished))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onDataViewUpdated_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onDataViewUpdated_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onDataViewUpdated_pargs {
 public:


  virtual ~ClientCallback_onDataViewUpdated_pargs() noexcept;
  const std::string* viewName;
  const int32_t* viewSize;
  const bool* finished;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onServiceAvailable_args__isset {
  _ClientCallback_onServiceAvailable_args__isset() : serviceName(false), deviceHandle(false) {}
  bool serviceName :1;
  bool deviceHandle :1;
} _ClientCallback_onServiceAvailable_args__isset;

class ClientCallback_onServiceAvailable_args {
 public:

  ClientCallback_onServiceAvailable_args(const ClientCallback_onServiceAvailable_args&);
  ClientCallback_onServiceAvailable_args& operator=(const ClientCallback_onServiceAvailable_args&);
  ClientCallback_onServiceAvailable_args() : serviceName(), deviceHandle(0) {
  }

  virtual ~ClientCallback_onServiceAvailable_args() noexcept;
  std::string serviceName;
  int64_t deviceHandle;

  _ClientCallback_onServiceAvailable_args__isset __isset;

  void __set_serviceName(const std::string& val);

  void __set_deviceHandle(const int64_t val);

  bool operator == (const ClientCallback_onServiceAvailable_args & rhs) const
  {
    if (!(serviceName == rhs.serviceName))
      return false;
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onServiceAvailable_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onServiceAvailable_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onServiceAvailable_pargs {
 public:


  virtual ~ClientCallback_onServiceAvailable_pargs() noexcept;
  const std::string* serviceName;
  const int64_t* deviceHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onServiceEnded_args__isset {
  _ClientCallback_onServiceEnded_args__isset() : serviceName(false), deviceHandle(false) {}
  bool serviceName :1;
  bool deviceHandle :1;
} _ClientCallback_onServiceEnded_args__isset;

class ClientCallback_onServiceEnded_args {
 public:

  ClientCallback_onServiceEnded_args(const ClientCallback_onServiceEnded_args&);
  ClientCallback_onServiceEnded_args& operator=(const ClientCallback_onServiceEnded_args&);
  ClientCallback_onServiceEnded_args() : serviceName(), deviceHandle(0) {
  }

  virtual ~ClientCallback_onServiceEnded_args() noexcept;
  std::string serviceName;
  int64_t deviceHandle;

  _ClientCallback_onServiceEnded_args__isset __isset;

  void __set_serviceName(const std::string& val);

  void __set_deviceHandle(const int64_t val);

  bool operator == (const ClientCallback_onServiceEnded_args & rhs) const
  {
    if (!(serviceName == rhs.serviceName))
      return false;
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onServiceEnded_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onServiceEnded_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onServiceEnded_pargs {
 public:


  virtual ~ClientCallback_onServiceEnded_pargs() noexcept;
  const std::string* serviceName;
  const int64_t* deviceHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onServiceEvent_args__isset {
  _ClientCallback_onServiceEvent_args__isset() : serviceName(false), eventId(false), eventDescription(false) {}
  bool serviceName :1;
  bool eventId :1;
  bool eventDescription :1;
} _ClientCallback_onServiceEvent_args__isset;

class ClientCallback_onServiceEvent_args {
 public:

  ClientCallback_onServiceEvent_args(const ClientCallback_onServiceEvent_args&);
  ClientCallback_onServiceEvent_args& operator=(const ClientCallback_onServiceEvent_args&);
  ClientCallback_onServiceEvent_args() : serviceName(), eventId(0), eventDescription() {
  }

  virtual ~ClientCallback_onServiceEvent_args() noexcept;
  std::string serviceName;
  int64_t eventId;
  std::string eventDescription;

  _ClientCallback_onServiceEvent_args__isset __isset;

  void __set_serviceName(const std::string& val);

  void __set_eventId(const int64_t val);

  void __set_eventDescription(const std::string& val);

  bool operator == (const ClientCallback_onServiceEvent_args & rhs) const
  {
    if (!(serviceName == rhs.serviceName))
      return false;
    if (!(eventId == rhs.eventId))
      return false;
    if (!(eventDescription == rhs.eventDescription))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onServiceEvent_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onServiceEvent_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onServiceEvent_pargs {
 public:


  virtual ~ClientCallback_onServiceEvent_pargs() noexcept;
  const std::string* serviceName;
  const int64_t* eventId;
  const std::string* eventDescription;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onImageManagementServiceEvent_args__isset {
  _ClientCallback_onImageManagementServiceEvent_args__isset() : serviceName(false), deviceHandle(false), protocolHandle(false), eventId(false), eventDescription(false) {}
  bool serviceName :1;
  bool deviceHandle :1;
  bool protocolHandle :1;
  bool eventId :1;
  bool eventDescription :1;
} _ClientCallback_onImageManagementServiceEvent_args__isset;

class ClientCallback_onImageManagementServiceEvent_args {
 public:

  ClientCallback_onImageManagementServiceEvent_args(const ClientCallback_onImageManagementServiceEvent_args&);
  ClientCallback_onImageManagementServiceEvent_args& operator=(const ClientCallback_onImageManagementServiceEvent_args&);
  ClientCallback_onImageManagementServiceEvent_args() : serviceName(), deviceHandle(0), protocolHandle(0), eventId(0), eventDescription() {
  }

  virtual ~ClientCallback_onImageManagementServiceEvent_args() noexcept;
  std::string serviceName;
  int64_t deviceHandle;
  int64_t protocolHandle;
  int64_t eventId;
  std::string eventDescription;

  _ClientCallback_onImageManagementServiceEvent_args__isset __isset;

  void __set_serviceName(const std::string& val);

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  void __set_eventId(const int64_t val);

  void __set_eventDescription(const std::string& val);

  bool operator == (const ClientCallback_onImageManagementServiceEvent_args & rhs) const
  {
    if (!(serviceName == rhs.serviceName))
      return false;
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(eventId == rhs.eventId))
      return false;
    if (!(eventDescription == rhs.eventDescription))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onImageManagementServiceEvent_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onImageManagementServiceEvent_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onImageManagementServiceEvent_pargs {
 public:


  virtual ~ClientCallback_onImageManagementServiceEvent_pargs() noexcept;
  const std::string* serviceName;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;
  const int64_t* eventId;
  const std::string* eventDescription;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onDeviceConfigServiceEvent_args__isset {
  _ClientCallback_onDeviceConfigServiceEvent_args__isset() : serviceName(false), deviceHandle(false), protocolHandle(false), eventId(false), eventDescription(false) {}
  bool serviceName :1;
  bool deviceHandle :1;
  bool protocolHandle :1;
  bool eventId :1;
  bool eventDescription :1;
} _ClientCallback_onDeviceConfigServiceEvent_args__isset;

class ClientCallback_onDeviceConfigServiceEvent_args {
 public:

  ClientCallback_onDeviceConfigServiceEvent_args(const ClientCallback_onDeviceConfigServiceEvent_args&);
  ClientCallback_onDeviceConfigServiceEvent_args& operator=(const ClientCallback_onDeviceConfigServiceEvent_args&);
  ClientCallback_onDeviceConfigServiceEvent_args() : serviceName(), deviceHandle(0), protocolHandle(0), eventId(0), eventDescription() {
  }

  virtual ~ClientCallback_onDeviceConfigServiceEvent_args() noexcept;
  std::string serviceName;
  int64_t deviceHandle;
  int64_t protocolHandle;
  int64_t eventId;
  std::string eventDescription;

  _ClientCallback_onDeviceConfigServiceEvent_args__isset __isset;

  void __set_serviceName(const std::string& val);

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  void __set_eventId(const int64_t val);

  void __set_eventDescription(const std::string& val);

  bool operator == (const ClientCallback_onDeviceConfigServiceEvent_args & rhs) const
  {
    if (!(serviceName == rhs.serviceName))
      return false;
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(eventId == rhs.eventId))
      return false;
    if (!(eventDescription == rhs.eventDescription))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onDeviceConfigServiceEvent_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onDeviceConfigServiceEvent_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onDeviceConfigServiceEvent_pargs {
 public:


  virtual ~ClientCallback_onDeviceConfigServiceEvent_pargs() noexcept;
  const std::string* serviceName;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;
  const int64_t* eventId;
  const std::string* eventDescription;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onQShrinkStateUpdated_args__isset {
  _ClientCallback_onQShrinkStateUpdated_args__isset() : protocolHandle(false), newState(false) {}
  bool protocolHandle :1;
  bool newState :1;
} _ClientCallback_onQShrinkStateUpdated_args__isset;

class ClientCallback_onQShrinkStateUpdated_args {
 public:

  ClientCallback_onQShrinkStateUpdated_args(const ClientCallback_onQShrinkStateUpdated_args&);
  ClientCallback_onQShrinkStateUpdated_args& operator=(const ClientCallback_onQShrinkStateUpdated_args&);
  ClientCallback_onQShrinkStateUpdated_args() : protocolHandle(0), newState(( ::Uts::QShrink4DownloadState::type)0) {
  }

  virtual ~ClientCallback_onQShrinkStateUpdated_args() noexcept;
  int64_t protocolHandle;
   ::Uts::QShrink4DownloadState::type newState;

  _ClientCallback_onQShrinkStateUpdated_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_newState(const  ::Uts::QShrink4DownloadState::type val);

  bool operator == (const ClientCallback_onQShrinkStateUpdated_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(newState == rhs.newState))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onQShrinkStateUpdated_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onQShrinkStateUpdated_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onQShrinkStateUpdated_pargs {
 public:


  virtual ~ClientCallback_onQShrinkStateUpdated_pargs() noexcept;
  const int64_t* protocolHandle;
  const  ::Uts::QShrink4DownloadState::type* newState;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onDecryptionKeyStatusUpdate_args__isset {
  _ClientCallback_onDecryptionKeyStatusUpdate_args__isset() : protocolHandle(false), keyInfo(false) {}
  bool protocolHandle :1;
  bool keyInfo :1;
} _ClientCallback_onDecryptionKeyStatusUpdate_args__isset;

class ClientCallback_onDecryptionKeyStatusUpdate_args {
 public:

  ClientCallback_onDecryptionKeyStatusUpdate_args(const ClientCallback_onDecryptionKeyStatusUpdate_args&);
  ClientCallback_onDecryptionKeyStatusUpdate_args& operator=(const ClientCallback_onDecryptionKeyStatusUpdate_args&);
  ClientCallback_onDecryptionKeyStatusUpdate_args() : protocolHandle(0) {
  }

  virtual ~ClientCallback_onDecryptionKeyStatusUpdate_args() noexcept;
  int64_t protocolHandle;
   ::Uts::KeyInfo keyInfo;

  _ClientCallback_onDecryptionKeyStatusUpdate_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_keyInfo(const  ::Uts::KeyInfo& val);

  bool operator == (const ClientCallback_onDecryptionKeyStatusUpdate_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(keyInfo == rhs.keyInfo))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onDecryptionKeyStatusUpdate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onDecryptionKeyStatusUpdate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onDecryptionKeyStatusUpdate_pargs {
 public:


  virtual ~ClientCallback_onDecryptionKeyStatusUpdate_pargs() noexcept;
  const int64_t* protocolHandle;
  const  ::Uts::KeyInfo* keyInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args__isset {
  _ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args__isset() : logSesssionInstance(false), protocolHandle(false), keyInfo(false) {}
  bool logSesssionInstance :1;
  bool protocolHandle :1;
  bool keyInfo :1;
} _ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args__isset;

class ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args {
 public:

  ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args(const ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args&);
  ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args& operator=(const ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args&);
  ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args() : logSesssionInstance(), protocolHandle(0) {
  }

  virtual ~ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args() noexcept;
  std::string logSesssionInstance;
  int64_t protocolHandle;
   ::Uts::KeyInfo keyInfo;

  _ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args__isset __isset;

  void __set_logSesssionInstance(const std::string& val);

  void __set_protocolHandle(const int64_t val);

  void __set_keyInfo(const  ::Uts::KeyInfo& val);

  bool operator == (const ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args & rhs) const
  {
    if (!(logSesssionInstance == rhs.logSesssionInstance))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(keyInfo == rhs.keyInfo))
      return false;
    return true;
  }
  bool operator != (const ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ClientCallback_onLogSessionDecryptionKeyStatusUpdate_pargs {
 public:


  virtual ~ClientCallback_onLogSessionDecryptionKeyStatusUpdate_pargs() noexcept;
  const std::string* logSesssionInstance;
  const int64_t* protocolHandle;
  const  ::Uts::KeyInfo* keyInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

class ClientCallbackClient : virtual public ClientCallbackIf {
 public:
  ClientCallbackClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ClientCallbackClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description);
  void send_onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description);
  void onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo);
  void send_onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo);
  void onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo);
  void send_onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo);
  void onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode);
  void send_onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode);
  void onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
  void send_onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
  void onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
  void send_onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
  void onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState);
  void send_onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState);
  void onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus);
  void send_onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus);
  void onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus);
  void send_onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus);
  void onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus);
  void send_onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus);
  void onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason);
  void send_onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason);
  void onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid);
  void send_onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid);
  void onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid);
  void send_onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid);
  void onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId);
  void send_onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId);
  void onDataQueueUpdated(const std::string& queueName, const int32_t queueSize);
  void send_onDataQueueUpdated(const std::string& queueName, const int32_t queueSize);
  void onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished);
  void send_onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished);
  void onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle);
  void send_onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle);
  void onServiceEnded(const std::string& serviceName, const int64_t deviceHandle);
  void send_onServiceEnded(const std::string& serviceName, const int64_t deviceHandle);
  void onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription);
  void send_onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription);
  void onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
  void send_onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
  void onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
  void send_onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
  void onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState);
  void send_onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState);
  void onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);
  void send_onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);
  void onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);
  void send_onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ClientCallbackProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<ClientCallbackIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ClientCallbackProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_onMessage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onDeviceConnected(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onDeviceDisconnected(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onDeviceModeChange(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onProtocolAdded(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onProtocolRemoved(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onProtocolStateChange(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onProtocolFlowControlStatusChange(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onProtocolLockStatusChange(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onProtocolMbnDownloadStatusChange(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onClientCloseRequest(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onMissingQShrinkHashFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onLogSessionMissingQShrinkHashFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onAsyncResponse(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onDataQueueUpdated(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onDataViewUpdated(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onServiceAvailable(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onServiceEnded(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onServiceEvent(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onImageManagementServiceEvent(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onDeviceConfigServiceEvent(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onQShrinkStateUpdated(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onDecryptionKeyStatusUpdate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_onLogSessionDecryptionKeyStatusUpdate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ClientCallbackProcessor(::std::shared_ptr<ClientCallbackIf> iface) :
    iface_(iface) {
    processMap_["onMessage"] = &ClientCallbackProcessor::process_onMessage;
    processMap_["onDeviceConnected"] = &ClientCallbackProcessor::process_onDeviceConnected;
    processMap_["onDeviceDisconnected"] = &ClientCallbackProcessor::process_onDeviceDisconnected;
    processMap_["onDeviceModeChange"] = &ClientCallbackProcessor::process_onDeviceModeChange;
    processMap_["onProtocolAdded"] = &ClientCallbackProcessor::process_onProtocolAdded;
    processMap_["onProtocolRemoved"] = &ClientCallbackProcessor::process_onProtocolRemoved;
    processMap_["onProtocolStateChange"] = &ClientCallbackProcessor::process_onProtocolStateChange;
    processMap_["onProtocolFlowControlStatusChange"] = &ClientCallbackProcessor::process_onProtocolFlowControlStatusChange;
    processMap_["onProtocolLockStatusChange"] = &ClientCallbackProcessor::process_onProtocolLockStatusChange;
    processMap_["onProtocolMbnDownloadStatusChange"] = &ClientCallbackProcessor::process_onProtocolMbnDownloadStatusChange;
    processMap_["onClientCloseRequest"] = &ClientCallbackProcessor::process_onClientCloseRequest;
    processMap_["onMissingQShrinkHashFile"] = &ClientCallbackProcessor::process_onMissingQShrinkHashFile;
    processMap_["onLogSessionMissingQShrinkHashFile"] = &ClientCallbackProcessor::process_onLogSessionMissingQShrinkHashFile;
    processMap_["onAsyncResponse"] = &ClientCallbackProcessor::process_onAsyncResponse;
    processMap_["onDataQueueUpdated"] = &ClientCallbackProcessor::process_onDataQueueUpdated;
    processMap_["onDataViewUpdated"] = &ClientCallbackProcessor::process_onDataViewUpdated;
    processMap_["onServiceAvailable"] = &ClientCallbackProcessor::process_onServiceAvailable;
    processMap_["onServiceEnded"] = &ClientCallbackProcessor::process_onServiceEnded;
    processMap_["onServiceEvent"] = &ClientCallbackProcessor::process_onServiceEvent;
    processMap_["onImageManagementServiceEvent"] = &ClientCallbackProcessor::process_onImageManagementServiceEvent;
    processMap_["onDeviceConfigServiceEvent"] = &ClientCallbackProcessor::process_onDeviceConfigServiceEvent;
    processMap_["onQShrinkStateUpdated"] = &ClientCallbackProcessor::process_onQShrinkStateUpdated;
    processMap_["onDecryptionKeyStatusUpdate"] = &ClientCallbackProcessor::process_onDecryptionKeyStatusUpdate;
    processMap_["onLogSessionDecryptionKeyStatusUpdate"] = &ClientCallbackProcessor::process_onLogSessionDecryptionKeyStatusUpdate;
  }

  virtual ~ClientCallbackProcessor() {}
};

class ClientCallbackProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ClientCallbackProcessorFactory(const ::std::shared_ptr< ClientCallbackIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< ClientCallbackIfFactory > handlerFactory_;
};

class ClientCallbackMultiface : virtual public ClientCallbackIf {
 public:
  ClientCallbackMultiface(std::vector<std::shared_ptr<ClientCallbackIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ClientCallbackMultiface() {}
 protected:
  std::vector<std::shared_ptr<ClientCallbackIf> > ifaces_;
  ClientCallbackMultiface() {}
  void add(::std::shared_ptr<ClientCallbackIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onMessage(level, location, title, description);
    }
    ifaces_[i]->onMessage(level, location, title, description);
  }

  void onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onDeviceConnected(deviceInfo);
    }
    ifaces_[i]->onDeviceConnected(deviceInfo);
  }

  void onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onDeviceDisconnected(deviceInfo);
    }
    ifaces_[i]->onDeviceDisconnected(deviceInfo);
  }

  void onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onDeviceModeChange(deviceHandle, newMode);
    }
    ifaces_[i]->onDeviceModeChange(deviceHandle, newMode);
  }

  void onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onProtocolAdded(deviceInfo, protocolInfo);
    }
    ifaces_[i]->onProtocolAdded(deviceInfo, protocolInfo);
  }

  void onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onProtocolRemoved(deviceInfo, protocolInfo);
    }
    ifaces_[i]->onProtocolRemoved(deviceInfo, protocolInfo);
  }

  void onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onProtocolStateChange(protocolHandle, newState);
    }
    ifaces_[i]->onProtocolStateChange(protocolHandle, newState);
  }

  void onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onProtocolFlowControlStatusChange(protocolHandle, dir, newStatus);
    }
    ifaces_[i]->onProtocolFlowControlStatusChange(protocolHandle, dir, newStatus);
  }

  void onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onProtocolLockStatusChange(protocolHandle, newStatus);
    }
    ifaces_[i]->onProtocolLockStatusChange(protocolHandle, newStatus);
  }

  void onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onProtocolMbnDownloadStatusChange(protocolHandle, newStatus);
    }
    ifaces_[i]->onProtocolMbnDownloadStatusChange(protocolHandle, newStatus);
  }

  void onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onClientCloseRequest(closeReason);
    }
    ifaces_[i]->onClientCloseRequest(closeReason);
  }

  void onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onMissingQShrinkHashFile(protocolHandle, missingFileGuid);
    }
    ifaces_[i]->onMissingQShrinkHashFile(protocolHandle, missingFileGuid);
  }

  void onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onLogSessionMissingQShrinkHashFile(logSessionInstance, protocolHandle, missingFileGuid);
    }
    ifaces_[i]->onLogSessionMissingQShrinkHashFile(logSessionInstance, protocolHandle, missingFileGuid);
  }

  void onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onAsyncResponse(protocolHandle, transactionId);
    }
    ifaces_[i]->onAsyncResponse(protocolHandle, transactionId);
  }

  void onDataQueueUpdated(const std::string& queueName, const int32_t queueSize) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onDataQueueUpdated(queueName, queueSize);
    }
    ifaces_[i]->onDataQueueUpdated(queueName, queueSize);
  }

  void onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onDataViewUpdated(viewName, viewSize, finished);
    }
    ifaces_[i]->onDataViewUpdated(viewName, viewSize, finished);
  }

  void onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onServiceAvailable(serviceName, deviceHandle);
    }
    ifaces_[i]->onServiceAvailable(serviceName, deviceHandle);
  }

  void onServiceEnded(const std::string& serviceName, const int64_t deviceHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onServiceEnded(serviceName, deviceHandle);
    }
    ifaces_[i]->onServiceEnded(serviceName, deviceHandle);
  }

  void onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onServiceEvent(serviceName, eventId, eventDescription);
    }
    ifaces_[i]->onServiceEvent(serviceName, eventId, eventDescription);
  }

  void onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onImageManagementServiceEvent(serviceName, deviceHandle, protocolHandle, eventId, eventDescription);
    }
    ifaces_[i]->onImageManagementServiceEvent(serviceName, deviceHandle, protocolHandle, eventId, eventDescription);
  }

  void onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onDeviceConfigServiceEvent(serviceName, deviceHandle, protocolHandle, eventId, eventDescription);
    }
    ifaces_[i]->onDeviceConfigServiceEvent(serviceName, deviceHandle, protocolHandle, eventId, eventDescription);
  }

  void onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onQShrinkStateUpdated(protocolHandle, newState);
    }
    ifaces_[i]->onQShrinkStateUpdated(protocolHandle, newState);
  }

  void onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onDecryptionKeyStatusUpdate(protocolHandle, keyInfo);
    }
    ifaces_[i]->onDecryptionKeyStatusUpdate(protocolHandle, keyInfo);
  }

  void onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->onLogSessionDecryptionKeyStatusUpdate(logSesssionInstance, protocolHandle, keyInfo);
    }
    ifaces_[i]->onLogSessionDecryptionKeyStatusUpdate(logSesssionInstance, protocolHandle, keyInfo);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ClientCallbackConcurrentClient : virtual public ClientCallbackIf {
 public:
  ClientCallbackConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  ClientCallbackConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description);
  void send_onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description);
  void onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo);
  void send_onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo);
  void onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo);
  void send_onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo);
  void onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode);
  void send_onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode);
  void onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
  void send_onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
  void onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
  void send_onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
  void onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState);
  void send_onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState);
  void onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus);
  void send_onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus);
  void onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus);
  void send_onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus);
  void onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus);
  void send_onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus);
  void onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason);
  void send_onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason);
  void onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid);
  void send_onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid);
  void onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid);
  void send_onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid);
  void onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId);
  void send_onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId);
  void onDataQueueUpdated(const std::string& queueName, const int32_t queueSize);
  void send_onDataQueueUpdated(const std::string& queueName, const int32_t queueSize);
  void onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished);
  void send_onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished);
  void onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle);
  void send_onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle);
  void onServiceEnded(const std::string& serviceName, const int64_t deviceHandle);
  void send_onServiceEnded(const std::string& serviceName, const int64_t deviceHandle);
  void onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription);
  void send_onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription);
  void onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
  void send_onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
  void onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
  void send_onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
  void onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState);
  void send_onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState);
  void onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);
  void send_onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);
  void onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);
  void send_onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
