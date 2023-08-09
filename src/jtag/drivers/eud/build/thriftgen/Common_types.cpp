/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "Common_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {

int _kErrorCodeValues[] = {
  ErrorCode::DEVICE_NO_ERROR,
  ErrorCode::DEVICE_UNKNOWN_ERROR,
  ErrorCode::DEVICE_INVALID_PARAMETERS,
  ErrorCode::DEVICE_PERMISSIONS_ERROR,
  ErrorCode::DEVICE_INVALID_DEVICE_HANDLE,
  ErrorCode::DEVICE_INVALID_PROTOCOL_HANDLE,
  ErrorCode::DEVICE_INVALID_CONNECTION_HANDLE,
  ErrorCode::DEVICE_CONNECTION_LOCKED,
  ErrorCode::DEVICE_DISCONNECTED,
  ErrorCode::DEVICE_PROTOCOL_INVALID,
  ErrorCode::DEVICE_PROTOCOL_DISCONNECTED,
  ErrorCode::DEVICE_PROTOCOL_UNRESPONSIVE,
  ErrorCode::DEVICE_TX_CANCELLED,
  ErrorCode::DEVICE_TIMEOUT,
  ErrorCode::DEVICE_INVALID_PROCESSOR,
  ErrorCode::DEVICE_INVALID_PACKET,
  ErrorCode::DEVICE_RESPONSE_ERROR,
  ErrorCode::DEVICE_INVALID_LOG_SESSION,
  ErrorCode::DEVICE_SERVICE_NOT_INITIALIZED,
  ErrorCode::DEVICE_TCP_PORT_FAILURE,
  ErrorCode::DEVICE_SERVICE_ALREADY_INITIALIZED,
  ErrorCode::DEVICE_LICENSE_ERROR,
  ErrorCode::DEVICE_OTP_PROGRAMED,
  ErrorCode::DEVICE_DECRYPTION_FAILED
};
const char* _kErrorCodeNames[] = {
  "DEVICE_NO_ERROR",
  "DEVICE_UNKNOWN_ERROR",
  "DEVICE_INVALID_PARAMETERS",
  "DEVICE_PERMISSIONS_ERROR",
  "DEVICE_INVALID_DEVICE_HANDLE",
  "DEVICE_INVALID_PROTOCOL_HANDLE",
  "DEVICE_INVALID_CONNECTION_HANDLE",
  "DEVICE_CONNECTION_LOCKED",
  "DEVICE_DISCONNECTED",
  "DEVICE_PROTOCOL_INVALID",
  "DEVICE_PROTOCOL_DISCONNECTED",
  "DEVICE_PROTOCOL_UNRESPONSIVE",
  "DEVICE_TX_CANCELLED",
  "DEVICE_TIMEOUT",
  "DEVICE_INVALID_PROCESSOR",
  "DEVICE_INVALID_PACKET",
  "DEVICE_RESPONSE_ERROR",
  "DEVICE_INVALID_LOG_SESSION",
  "DEVICE_SERVICE_NOT_INITIALIZED",
  "DEVICE_TCP_PORT_FAILURE",
  "DEVICE_SERVICE_ALREADY_INITIALIZED",
  "DEVICE_LICENSE_ERROR",
  "DEVICE_OTP_PROGRAMED",
  "DEVICE_DECRYPTION_FAILED"
};
const std::map<int, const char*> _ErrorCode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(24, _kErrorCodeValues, _kErrorCodeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ErrorCode::type& val) {
  std::map<int, const char*>::const_iterator it = _ErrorCode_VALUES_TO_NAMES.find(val);
  if (it != _ErrorCode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ErrorCode::type& val) {
  std::map<int, const char*>::const_iterator it = _ErrorCode_VALUES_TO_NAMES.find(val);
  if (it != _ErrorCode_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kQutsOperatingModeValues[] = {
  QutsOperatingMode::DEVICE_DISCOVERY,
  QutsOperatingMode::POST_PROCESSING
};
const char* _kQutsOperatingModeNames[] = {
  "DEVICE_DISCOVERY",
  "POST_PROCESSING"
};
const std::map<int, const char*> _QutsOperatingMode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kQutsOperatingModeValues, _kQutsOperatingModeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const QutsOperatingMode::type& val) {
  std::map<int, const char*>::const_iterator it = _QutsOperatingMode_VALUES_TO_NAMES.find(val);
  if (it != _QutsOperatingMode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const QutsOperatingMode::type& val) {
  std::map<int, const char*>::const_iterator it = _QutsOperatingMode_VALUES_TO_NAMES.find(val);
  if (it != _QutsOperatingMode_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kOpenPropValues[] = {
  OpenProp::OPEN_NONE,
  OpenProp::OPEN_READ,
  OpenProp::OPEN_WRITE,
  OpenProp::OPEN_READ_WRITE
};
const char* _kOpenPropNames[] = {
  "OPEN_NONE",
  "OPEN_READ",
  "OPEN_WRITE",
  "OPEN_READ_WRITE"
};
const std::map<int, const char*> _OpenProp_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kOpenPropValues, _kOpenPropNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const OpenProp::type& val) {
  std::map<int, const char*>::const_iterator it = _OpenProp_VALUES_TO_NAMES.find(val);
  if (it != _OpenProp_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const OpenProp::type& val) {
  std::map<int, const char*>::const_iterator it = _OpenProp_VALUES_TO_NAMES.find(val);
  if (it != _OpenProp_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kProtocolTypeValues[] = {
  ProtocolType::PROT_UNKNOWN,
  ProtocolType::PROT_DIAG,
  ProtocolType::PROT_QMI,
  ProtocolType::PROT_ADB,
  ProtocolType::PROT_SAHARA,
  ProtocolType::PROT_FIREHOSE,
  ProtocolType::PROT_QDSS,
  ProtocolType::PROT_ADPL,
  ProtocolType::PROT_FASTBOOT,
  ProtocolType::PROT_NMEA,
  ProtocolType::PROT_DUN,
  ProtocolType::PROT_RMNET,
  ProtocolType::PROT_RNDIS,
  ProtocolType::PROT_MBIM,
  ProtocolType::PROT_PROTOBUF,
  ProtocolType::PROT_TAC,
  ProtocolType::PROT_EPM,
  ProtocolType::PROT_TELNET,
  ProtocolType::PROT_FTP,
  ProtocolType::PROT_EUD,
  ProtocolType::PROT_MAX
};
const char* _kProtocolTypeNames[] = {
  "PROT_UNKNOWN",
  "PROT_DIAG",
  "PROT_QMI",
  "PROT_ADB",
  "PROT_SAHARA",
  "PROT_FIREHOSE",
  "PROT_QDSS",
  "PROT_ADPL",
  "PROT_FASTBOOT",
  "PROT_NMEA",
  "PROT_DUN",
  "PROT_RMNET",
  "PROT_RNDIS",
  "PROT_MBIM",
  "PROT_PROTOBUF",
  "PROT_TAC",
  "PROT_EPM",
  "PROT_TELNET",
  "PROT_FTP",
  "PROT_EUD",
  "PROT_MAX"
};
const std::map<int, const char*> _ProtocolType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(21, _kProtocolTypeValues, _kProtocolTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ProtocolType::type& val) {
  std::map<int, const char*>::const_iterator it = _ProtocolType_VALUES_TO_NAMES.find(val);
  if (it != _ProtocolType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ProtocolType::type& val) {
  std::map<int, const char*>::const_iterator it = _ProtocolType_VALUES_TO_NAMES.find(val);
  if (it != _ProtocolType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kConnectionTypeValues[] = {
  ConnectionType::CONNECT_UNKNOWN,
  ConnectionType::CONNECT_USB,
  ConnectionType::CONNECT_TCP,
  ConnectionType::CONNECT_FILE,
  ConnectionType::CONNECT_ETHERNET,
  ConnectionType::CONNECT_MAX
};
const char* _kConnectionTypeNames[] = {
  "CONNECT_UNKNOWN",
  "CONNECT_USB",
  "CONNECT_TCP",
  "CONNECT_FILE",
  "CONNECT_ETHERNET",
  "CONNECT_MAX"
};
const std::map<int, const char*> _ConnectionType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(6, _kConnectionTypeValues, _kConnectionTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ConnectionType::type& val) {
  std::map<int, const char*>::const_iterator it = _ConnectionType_VALUES_TO_NAMES.find(val);
  if (it != _ConnectionType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ConnectionType::type& val) {
  std::map<int, const char*>::const_iterator it = _ConnectionType_VALUES_TO_NAMES.find(val);
  if (it != _ConnectionType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kProtocolStateValues[] = {
  ProtocolState::STATE_AVAILABLE,
  ProtocolState::STATE_DISCONNECTED,
  ProtocolState::STATE_UNRESPONSIVE,
  ProtocolState::STATE_INITIALIZING
};
const char* _kProtocolStateNames[] = {
  "STATE_AVAILABLE",
  "STATE_DISCONNECTED",
  "STATE_UNRESPONSIVE",
  "STATE_INITIALIZING"
};
const std::map<int, const char*> _ProtocolState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kProtocolStateValues, _kProtocolStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ProtocolState::type& val) {
  std::map<int, const char*>::const_iterator it = _ProtocolState_VALUES_TO_NAMES.find(val);
  if (it != _ProtocolState_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ProtocolState::type& val) {
  std::map<int, const char*>::const_iterator it = _ProtocolState_VALUES_TO_NAMES.find(val);
  if (it != _ProtocolState_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kDirectionValues[] = {
  Direction::DIR_RX,
  Direction::DIR_TX
};
const char* _kDirectionNames[] = {
  "DIR_RX",
  "DIR_TX"
};
const std::map<int, const char*> _Direction_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kDirectionValues, _kDirectionNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const Direction::type& val) {
  std::map<int, const char*>::const_iterator it = _Direction_VALUES_TO_NAMES.find(val);
  if (it != _Direction_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const Direction::type& val) {
  std::map<int, const char*>::const_iterator it = _Direction_VALUES_TO_NAMES.find(val);
  if (it != _Direction_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kFlowControlStatusValues[] = {
  FlowControlStatus::FLOW_CONTROL_OFF,
  FlowControlStatus::FLOW_CONTROL_ON
};
const char* _kFlowControlStatusNames[] = {
  "FLOW_CONTROL_OFF",
  "FLOW_CONTROL_ON"
};
const std::map<int, const char*> _FlowControlStatus_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kFlowControlStatusValues, _kFlowControlStatusNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const FlowControlStatus::type& val) {
  std::map<int, const char*>::const_iterator it = _FlowControlStatus_VALUES_TO_NAMES.find(val);
  if (it != _FlowControlStatus_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const FlowControlStatus::type& val) {
  std::map<int, const char*>::const_iterator it = _FlowControlStatus_VALUES_TO_NAMES.find(val);
  if (it != _FlowControlStatus_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kFlowControlLevelValues[] = {
  FlowControlLevel::FLOW_CONTROL_LOW,
  FlowControlLevel::FLOW_CONTROL_MID,
  FlowControlLevel::FLOW_CONTROL_HIGH,
  FlowControlLevel::FLOW_CONTROL_DNE
};
const char* _kFlowControlLevelNames[] = {
  "FLOW_CONTROL_LOW",
  "FLOW_CONTROL_MID",
  "FLOW_CONTROL_HIGH",
  "FLOW_CONTROL_DNE"
};
const std::map<int, const char*> _FlowControlLevel_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kFlowControlLevelValues, _kFlowControlLevelNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const FlowControlLevel::type& val) {
  std::map<int, const char*>::const_iterator it = _FlowControlLevel_VALUES_TO_NAMES.find(val);
  if (it != _FlowControlLevel_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const FlowControlLevel::type& val) {
  std::map<int, const char*>::const_iterator it = _FlowControlLevel_VALUES_TO_NAMES.find(val);
  if (it != _FlowControlLevel_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kLockStateValues[] = {
  LockState::LOCK_STATE_OFF,
  LockState::LOCK_STATE_ON
};
const char* _kLockStateNames[] = {
  "LOCK_STATE_OFF",
  "LOCK_STATE_ON"
};
const std::map<int, const char*> _LockState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kLockStateValues, _kLockStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const LockState::type& val) {
  std::map<int, const char*>::const_iterator it = _LockState_VALUES_TO_NAMES.find(val);
  if (it != _LockState_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const LockState::type& val) {
  std::map<int, const char*>::const_iterator it = _LockState_VALUES_TO_NAMES.find(val);
  if (it != _LockState_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kMbnDownloadStateValues[] = {
  MbnDownloadState::INVALID,
  MbnDownloadState::RESET,
  MbnDownloadState::REQUEST_SENT,
  MbnDownloadState::WAIT_IMMEDIATE_REPONSE,
  MbnDownloadState::IMMEDIATE_REPONSE_RECIEVED,
  MbnDownloadState::WAIT_DELAYED_RESPONSE,
  MbnDownloadState::DELAYED_RESPONSE_RECEIVED,
  MbnDownloadState::DOWNLOAD_COMPLETED,
  MbnDownloadState::DEVICE_CONFIGURATION_STATUS_CHECK_COMPLETED,
  MbnDownloadState::MBN_FILE_DOWNLOAD_COMPLETED,
  MbnDownloadState::XML_FILE_DOWNLOAD_COMPLETED,
  MbnDownloadState::FILE_REPLAYSTATE,
  MbnDownloadState::ERROR_STATE
};
const char* _kMbnDownloadStateNames[] = {
  "INVALID",
  "RESET",
  "REQUEST_SENT",
  "WAIT_IMMEDIATE_REPONSE",
  "IMMEDIATE_REPONSE_RECIEVED",
  "WAIT_DELAYED_RESPONSE",
  "DELAYED_RESPONSE_RECEIVED",
  "DOWNLOAD_COMPLETED",
  "DEVICE_CONFIGURATION_STATUS_CHECK_COMPLETED",
  "MBN_FILE_DOWNLOAD_COMPLETED",
  "XML_FILE_DOWNLOAD_COMPLETED",
  "FILE_REPLAYSTATE",
  "ERROR_STATE"
};
const std::map<int, const char*> _MbnDownloadState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(13, _kMbnDownloadStateValues, _kMbnDownloadStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const MbnDownloadState::type& val) {
  std::map<int, const char*>::const_iterator it = _MbnDownloadState_VALUES_TO_NAMES.find(val);
  if (it != _MbnDownloadState_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const MbnDownloadState::type& val) {
  std::map<int, const char*>::const_iterator it = _MbnDownloadState_VALUES_TO_NAMES.find(val);
  if (it != _MbnDownloadState_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kDeviceModeValues[] = {
  DeviceMode::DEVICE_MODE_NONE,
  DeviceMode::DEVICE_MODE_SAHARA_DOWNLOAD,
  DeviceMode::DEVICE_MODE_SAHARA_CRASH,
  DeviceMode::DEVICE_MODE_SAHARA_EFS_SYNC
};
const char* _kDeviceModeNames[] = {
  "DEVICE_MODE_NONE",
  "DEVICE_MODE_SAHARA_DOWNLOAD",
  "DEVICE_MODE_SAHARA_CRASH",
  "DEVICE_MODE_SAHARA_EFS_SYNC"
};
const std::map<int, const char*> _DeviceMode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kDeviceModeValues, _kDeviceModeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const DeviceMode::type& val) {
  std::map<int, const char*>::const_iterator it = _DeviceMode_VALUES_TO_NAMES.find(val);
  if (it != _DeviceMode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const DeviceMode::type& val) {
  std::map<int, const char*>::const_iterator it = _DeviceMode_VALUES_TO_NAMES.find(val);
  if (it != _DeviceMode_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kKeyClassValues[] = {
  KeyClass::KEY_NONE,
  KeyClass::KEY_PROPRIETARY
};
const char* _kKeyClassNames[] = {
  "KEY_NONE",
  "KEY_PROPRIETARY"
};
const std::map<int, const char*> _KeyClass_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kKeyClassValues, _kKeyClassNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const KeyClass::type& val) {
  std::map<int, const char*>::const_iterator it = _KeyClass_VALUES_TO_NAMES.find(val);
  if (it != _KeyClass_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const KeyClass::type& val) {
  std::map<int, const char*>::const_iterator it = _KeyClass_VALUES_TO_NAMES.find(val);
  if (it != _KeyClass_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kKeyLoadStatusValues[] = {
  KeyLoadStatus::KEY_LOAD_SUCCESS,
  KeyLoadStatus::KEY_LOAD_NO_SERVER_CONNECTION,
  KeyLoadStatus::KEY_LOAD_ERROR,
  KeyLoadStatus::KEY_LOAD_AUTHENTICATION_ERROR
};
const char* _kKeyLoadStatusNames[] = {
  "KEY_LOAD_SUCCESS",
  "KEY_LOAD_NO_SERVER_CONNECTION",
  "KEY_LOAD_ERROR",
  "KEY_LOAD_AUTHENTICATION_ERROR"
};
const std::map<int, const char*> _KeyLoadStatus_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kKeyLoadStatusValues, _kKeyLoadStatusNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const KeyLoadStatus::type& val) {
  std::map<int, const char*>::const_iterator it = _KeyLoadStatus_VALUES_TO_NAMES.find(val);
  if (it != _KeyLoadStatus_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const KeyLoadStatus::type& val) {
  std::map<int, const char*>::const_iterator it = _KeyLoadStatus_VALUES_TO_NAMES.find(val);
  if (it != _KeyLoadStatus_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kDiagPacketTypeValues[] = {
  DiagPacketType::UNKNOWN_PACKET_TYPE,
  DiagPacketType::LOG_PACKET,
  DiagPacketType::EVENT,
  DiagPacketType::NV_ITEM,
  DiagPacketType::DEBUG_MSG,
  DiagPacketType::REQUEST,
  DiagPacketType::RESPONSE,
  DiagPacketType::SUBSYS_REQUEST,
  DiagPacketType::SUBSYS_RESPONSE,
  DiagPacketType::SUBSYSV2_REQUEST,
  DiagPacketType::SUBSYSV2_IMMEDIATE_RESPONSE,
  DiagPacketType::SUBSYSV2_DELAYED_RESPONSE,
  DiagPacketType::QTRACE,
  DiagPacketType::QSH_METRIC,
  DiagPacketType::QSH_EVENT
};
const char* _kDiagPacketTypeNames[] = {
  "UNKNOWN_PACKET_TYPE",
  "LOG_PACKET",
  "EVENT",
  "NV_ITEM",
  "DEBUG_MSG",
  "REQUEST",
  "RESPONSE",
  "SUBSYS_REQUEST",
  "SUBSYS_RESPONSE",
  "SUBSYSV2_REQUEST",
  "SUBSYSV2_IMMEDIATE_RESPONSE",
  "SUBSYSV2_DELAYED_RESPONSE",
  "QTRACE",
  "QSH_METRIC",
  "QSH_EVENT"
};
const std::map<int, const char*> _DiagPacketType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(15, _kDiagPacketTypeValues, _kDiagPacketTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const DiagPacketType::type& val) {
  std::map<int, const char*>::const_iterator it = _DiagPacketType_VALUES_TO_NAMES.find(val);
  if (it != _DiagPacketType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const DiagPacketType::type& val) {
  std::map<int, const char*>::const_iterator it = _DiagPacketType_VALUES_TO_NAMES.find(val);
  if (it != _DiagPacketType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kDataSourceTypeValues[] = {
  DataSourceType::FILE_DATA,
  DataSourceType::BINARY_MASK_DATA
};
const char* _kDataSourceTypeNames[] = {
  "FILE_DATA",
  "BINARY_MASK_DATA"
};
const std::map<int, const char*> _DataSourceType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kDataSourceTypeValues, _kDataSourceTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const DataSourceType::type& val) {
  std::map<int, const char*>::const_iterator it = _DataSourceType_VALUES_TO_NAMES.find(val);
  if (it != _DataSourceType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const DataSourceType::type& val) {
  std::map<int, const char*>::const_iterator it = _DataSourceType_VALUES_TO_NAMES.find(val);
  if (it != _DataSourceType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kLogMaskFormatValues[] = {
  LogMaskFormat::INVALID,
  LogMaskFormat::CFG_FORMAT,
  LogMaskFormat::CFG2_FORMAT,
  LogMaskFormat::DMC_FORMAT,
  LogMaskFormat::CFG_FORMAT_ENABLE_MULTISIM,
  LogMaskFormat::CFG2_FORMAT_ENABLE_MULTISIM,
  LogMaskFormat::DMC_FORMAT_ENABLE_MULTISIM
};
const char* _kLogMaskFormatNames[] = {
  "INVALID",
  "CFG_FORMAT",
  "CFG2_FORMAT",
  "DMC_FORMAT",
  "CFG_FORMAT_ENABLE_MULTISIM",
  "CFG2_FORMAT_ENABLE_MULTISIM",
  "DMC_FORMAT_ENABLE_MULTISIM"
};
const std::map<int, const char*> _LogMaskFormat_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kLogMaskFormatValues, _kLogMaskFormatNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const LogMaskFormat::type& val) {
  std::map<int, const char*>::const_iterator it = _LogMaskFormat_VALUES_TO_NAMES.find(val);
  if (it != _LogMaskFormat_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const LogMaskFormat::type& val) {
  std::map<int, const char*>::const_iterator it = _LogMaskFormat_VALUES_TO_NAMES.find(val);
  if (it != _LogMaskFormat_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kQShrink4DownloadStateValues[] = {
  QShrink4DownloadState::QSR4_STATE_INIT,
  QShrink4DownloadState::QSR4_STATE_DOWNLOADING,
  QShrink4DownloadState::QSR4_STATE_DOWNLOADED,
  QShrink4DownloadState::QSR4_STATE_LOADED,
  QShrink4DownloadState::QSR4_STATE_FAILED
};
const char* _kQShrink4DownloadStateNames[] = {
  "QSR4_STATE_INIT",
  "QSR4_STATE_DOWNLOADING",
  "QSR4_STATE_DOWNLOADED",
  "QSR4_STATE_LOADED",
  "QSR4_STATE_FAILED"
};
const std::map<int, const char*> _QShrink4DownloadState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kQShrink4DownloadStateValues, _kQShrink4DownloadStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const QShrink4DownloadState::type& val) {
  std::map<int, const char*>::const_iterator it = _QShrink4DownloadState_VALUES_TO_NAMES.find(val);
  if (it != _QShrink4DownloadState_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const QShrink4DownloadState::type& val) {
  std::map<int, const char*>::const_iterator it = _QShrink4DownloadState_VALUES_TO_NAMES.find(val);
  if (it != _QShrink4DownloadState_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kInternalPacketFlagValues[] = {
  InternalPacketFlag::INTERNAL_FLAG_NOT_SET,
  InternalPacketFlag::INTERNAL_PACKET_ONLY,
  InternalPacketFlag::EXTERNAL_PACKET_ONLY
};
const char* _kInternalPacketFlagNames[] = {
  "INTERNAL_FLAG_NOT_SET",
  "INTERNAL_PACKET_ONLY",
  "EXTERNAL_PACKET_ONLY"
};
const std::map<int, const char*> _InternalPacketFlag_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kInternalPacketFlagValues, _kInternalPacketFlagNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const InternalPacketFlag::type& val) {
  std::map<int, const char*>::const_iterator it = _InternalPacketFlag_VALUES_TO_NAMES.find(val);
  if (it != _InternalPacketFlag_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const InternalPacketFlag::type& val) {
  std::map<int, const char*>::const_iterator it = _InternalPacketFlag_VALUES_TO_NAMES.find(val);
  if (it != _InternalPacketFlag_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kDiagReturnFlagsValues[] = {
  DiagReturnFlags::NO_FLAGS_SET,
  DiagReturnFlags::SESSION_INDEX,
  DiagReturnFlags::PROTOCOL_INDEX,
  DiagReturnFlags::RECEIVE_TIME_DATA,
  DiagReturnFlags::RECEIVE_TIME_STRING,
  DiagReturnFlags::PACKET_TYPE,
  DiagReturnFlags::PACKET_ID,
  DiagReturnFlags::PACKET_NAME,
  DiagReturnFlags::BINARY_PAYLOAD,
  DiagReturnFlags::PARSED_TEXT,
  DiagReturnFlags::TIME_STAMP_DATA,
  DiagReturnFlags::TIME_STAMP_STRING,
  DiagReturnFlags::SUBSCRIPTION_ID,
  DiagReturnFlags::PROCESSOR_ID,
  DiagReturnFlags::HW_TIME_STAMP_DATA,
  DiagReturnFlags::HW_TIME_STAMP_STRING,
  DiagReturnFlags::ULOG_SOURCE,
  DiagReturnFlags::MORE_RESPONSES_FLAG,
  DiagReturnFlags::SUMMARY_TEXT,
  DiagReturnFlags::QDSS_CHANNEL_ID,
  DiagReturnFlags::QDSS_MASTER_ID,
  DiagReturnFlags::QDSS_AT_ID,
  DiagReturnFlags::DEFAULT_FORMAT_TEXT,
  DiagReturnFlags::CALL_FRAME_NUMBER,
  DiagReturnFlags::TIME_STAMP_TOD_ADJUSTED_DATA,
  DiagReturnFlags::TIME_STAMP_TOD_ADJUSTED_STRING,
  DiagReturnFlags::PACKET_SIZE,
  DiagReturnFlags::QTRACE_TAG_LIST,
  DiagReturnFlags::MISCELLANEOUS_ID,
  DiagReturnFlags::QUERY_RESULT_PICKLED,
  DiagReturnFlags::FORMAT_STRING_HASH,
  DiagReturnFlags::ENCRYPTION_KEY_INFO
};
const char* _kDiagReturnFlagsNames[] = {
  "NO_FLAGS_SET",
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_TYPE",
  "PACKET_ID",
  "PACKET_NAME",
  "BINARY_PAYLOAD",
  "PARSED_TEXT",
  "TIME_STAMP_DATA",
  "TIME_STAMP_STRING",
  "SUBSCRIPTION_ID",
  "PROCESSOR_ID",
  "HW_TIME_STAMP_DATA",
  "HW_TIME_STAMP_STRING",
  "ULOG_SOURCE",
  "MORE_RESPONSES_FLAG",
  "SUMMARY_TEXT",
  "QDSS_CHANNEL_ID",
  "QDSS_MASTER_ID",
  "QDSS_AT_ID",
  "DEFAULT_FORMAT_TEXT",
  "CALL_FRAME_NUMBER",
  "TIME_STAMP_TOD_ADJUSTED_DATA",
  "TIME_STAMP_TOD_ADJUSTED_STRING",
  "PACKET_SIZE",
  "QTRACE_TAG_LIST",
  "MISCELLANEOUS_ID",
  "QUERY_RESULT_PICKLED",
  "FORMAT_STRING_HASH",
  "ENCRYPTION_KEY_INFO"
};
const std::map<int, const char*> _DiagReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(32, _kDiagReturnFlagsValues, _kDiagReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const DiagReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _DiagReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _DiagReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const DiagReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _DiagReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _DiagReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kDiagReturnFlagsExtValues[] = {
  DiagReturnFlagsExt::NO_USER_PARSING,
  DiagReturnFlagsExt::USER_PARSED_TEXT,
  DiagReturnFlagsExt::USER_PARSED_SUMMARY,
  DiagReturnFlagsExt::EXCEPTION_MESSAGE_TYPE,
  DiagReturnFlagsExt::QUERY_RESULT_PICKLED_AND_JSON
};
const char* _kDiagReturnFlagsExtNames[] = {
  "NO_USER_PARSING",
  "USER_PARSED_TEXT",
  "USER_PARSED_SUMMARY",
  "EXCEPTION_MESSAGE_TYPE",
  "QUERY_RESULT_PICKLED_AND_JSON"
};
const std::map<int, const char*> _DiagReturnFlagsExt_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kDiagReturnFlagsExtValues, _kDiagReturnFlagsExtNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const DiagReturnFlagsExt::type& val) {
  std::map<int, const char*>::const_iterator it = _DiagReturnFlagsExt_VALUES_TO_NAMES.find(val);
  if (it != _DiagReturnFlagsExt_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const DiagReturnFlagsExt::type& val) {
  std::map<int, const char*>::const_iterator it = _DiagReturnFlagsExt_VALUES_TO_NAMES.find(val);
  if (it != _DiagReturnFlagsExt_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kSearchOptionsValues[] = {
  SearchOptions::NO_OPTIONS_SET,
  SearchOptions::USE_REGEX_MATCH,
  SearchOptions::INVERT_SEARCH,
  SearchOptions::CASE_INSENSITIVE
};
const char* _kSearchOptionsNames[] = {
  "NO_OPTIONS_SET",
  "USE_REGEX_MATCH",
  "INVERT_SEARCH",
  "CASE_INSENSITIVE"
};
const std::map<int, const char*> _SearchOptions_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kSearchOptionsValues, _kSearchOptionsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const SearchOptions::type& val) {
  std::map<int, const char*>::const_iterator it = _SearchOptions_VALUES_TO_NAMES.find(val);
  if (it != _SearchOptions_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const SearchOptions::type& val) {
  std::map<int, const char*>::const_iterator it = _SearchOptions_VALUES_TO_NAMES.find(val);
  if (it != _SearchOptions_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kExceptionMessageTypeValues[] = {
  ExceptionMessageType::NOT_SET,
  ExceptionMessageType::UNKNOWN_EXCEPTION_MESSAGE,
  ExceptionMessageType::NOT_ENOUGH_ARGUMENT_COUNT_PROVIDED
};
const char* _kExceptionMessageTypeNames[] = {
  "NOT_SET",
  "UNKNOWN_EXCEPTION_MESSAGE",
  "NOT_ENOUGH_ARGUMENT_COUNT_PROVIDED"
};
const std::map<int, const char*> _ExceptionMessageType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kExceptionMessageTypeValues, _kExceptionMessageTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ExceptionMessageType::type& val) {
  std::map<int, const char*>::const_iterator it = _ExceptionMessageType_VALUES_TO_NAMES.find(val);
  if (it != _ExceptionMessageType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ExceptionMessageType::type& val) {
  std::map<int, const char*>::const_iterator it = _ExceptionMessageType_VALUES_TO_NAMES.find(val);
  if (it != _ExceptionMessageType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kAnnotationReturnFlagsValues[] = {
  AnnotationReturnFlags::NO_FLAGS_SET,
  AnnotationReturnFlags::SESSION_INDEX,
  AnnotationReturnFlags::PROTOCOL_INDEX,
  AnnotationReturnFlags::RECEIVE_TIME_DATA,
  AnnotationReturnFlags::RECEIVE_TIME_STRING,
  AnnotationReturnFlags::MESSAGE_ID,
  AnnotationReturnFlags::PARSED_TEXT
};
const char* _kAnnotationReturnFlagsNames[] = {
  "NO_FLAGS_SET",
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "MESSAGE_ID",
  "PARSED_TEXT"
};
const std::map<int, const char*> _AnnotationReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kAnnotationReturnFlagsValues, _kAnnotationReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const AnnotationReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _AnnotationReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _AnnotationReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const AnnotationReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _AnnotationReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _AnnotationReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kQmiPacketTypeValues[] = {
  QmiPacketType::QMI_REQUEST,
  QmiPacketType::QMI_RESPONSE,
  QmiPacketType::QMI_INDICATION
};
const char* _kQmiPacketTypeNames[] = {
  "QMI_REQUEST",
  "QMI_RESPONSE",
  "QMI_INDICATION"
};
const std::map<int, const char*> _QmiPacketType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kQmiPacketTypeValues, _kQmiPacketTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const QmiPacketType::type& val) {
  std::map<int, const char*>::const_iterator it = _QmiPacketType_VALUES_TO_NAMES.find(val);
  if (it != _QmiPacketType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const QmiPacketType::type& val) {
  std::map<int, const char*>::const_iterator it = _QmiPacketType_VALUES_TO_NAMES.find(val);
  if (it != _QmiPacketType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kQmiReturnFlagsValues[] = {
  QmiReturnFlags::SESSION_INDEX,
  QmiReturnFlags::PROTOCOL_INDEX,
  QmiReturnFlags::RECEIVE_TIME_DATA,
  QmiReturnFlags::RECEIVE_TIME_STRING,
  QmiReturnFlags::PACKET_TYPE,
  QmiReturnFlags::PACKET_NAME,
  QmiReturnFlags::BINARY_PAYLOAD,
  QmiReturnFlags::PARSED_XML,
  QmiReturnFlags::SERVICE_ID,
  QmiReturnFlags::MESSAGE_ID
};
const char* _kQmiReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_TYPE",
  "PACKET_NAME",
  "BINARY_PAYLOAD",
  "PARSED_XML",
  "SERVICE_ID",
  "MESSAGE_ID"
};
const std::map<int, const char*> _QmiReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(10, _kQmiReturnFlagsValues, _kQmiReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const QmiReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _QmiReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _QmiReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const QmiReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _QmiReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _QmiReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kAdbReturnFlagsValues[] = {
  AdbReturnFlags::SESSION_INDEX,
  AdbReturnFlags::PROTOCOL_INDEX,
  AdbReturnFlags::RECEIVE_TIME_DATA,
  AdbReturnFlags::RECEIVE_TIME_STRING,
  AdbReturnFlags::PACKET_TEXT
};
const char* _kAdbReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_TEXT"
};
const std::map<int, const char*> _AdbReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kAdbReturnFlagsValues, _kAdbReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const AdbReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _AdbReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _AdbReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const AdbReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _AdbReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _AdbReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kTelnetReturnFlagsValues[] = {
  TelnetReturnFlags::SESSION_INDEX,
  TelnetReturnFlags::PROTOCOL_INDEX,
  TelnetReturnFlags::RECEIVE_TIME_DATA,
  TelnetReturnFlags::RECEIVE_TIME_STRING,
  TelnetReturnFlags::PACKET_TEXT
};
const char* _kTelnetReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_TEXT"
};
const std::map<int, const char*> _TelnetReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kTelnetReturnFlagsValues, _kTelnetReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const TelnetReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _TelnetReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _TelnetReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const TelnetReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _TelnetReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _TelnetReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kSaharaReturnFlagsValues[] = {
  SaharaReturnFlags::SESSION_INDEX,
  SaharaReturnFlags::PROTOCOL_INDEX,
  SaharaReturnFlags::RECEIVE_TIME_DATA,
  SaharaReturnFlags::RECEIVE_TIME_STRING,
  SaharaReturnFlags::PACKET_ID,
  SaharaReturnFlags::PACKET_NAME,
  SaharaReturnFlags::BINARY_PAYLOAD
};
const char* _kSaharaReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_ID",
  "PACKET_NAME",
  "BINARY_PAYLOAD"
};
const std::map<int, const char*> _SaharaReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kSaharaReturnFlagsValues, _kSaharaReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const SaharaReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _SaharaReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _SaharaReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const SaharaReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _SaharaReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _SaharaReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kFastbootReturnFlagsValues[] = {
  FastbootReturnFlags::SESSION_INDEX,
  FastbootReturnFlags::PROTOCOL_INDEX,
  FastbootReturnFlags::RECEIVE_TIME_DATA,
  FastbootReturnFlags::RECEIVE_TIME_STRING,
  FastbootReturnFlags::PACKET_TEXT
};
const char* _kFastbootReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_TEXT"
};
const std::map<int, const char*> _FastbootReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kFastbootReturnFlagsValues, _kFastbootReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const FastbootReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _FastbootReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _FastbootReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const FastbootReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _FastbootReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _FastbootReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kEudReturnFlagsValues[] = {
  EudReturnFlags::SESSION_INDEX,
  EudReturnFlags::PROTOCOL_INDEX,
  EudReturnFlags::RECEIVE_TIME_DATA,
  EudReturnFlags::RECEIVE_TIME_STRING,
  EudReturnFlags::PACKET_ID,
  EudReturnFlags::PACKET_NAME,
  EudReturnFlags::BINARY_PAYLOAD
};
const char* _kEudReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_ID",
  "PACKET_NAME",
  "BINARY_PAYLOAD"
};
const std::map<int, const char*> _EudReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kEudReturnFlagsValues, _kEudReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const EudReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _EudReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _EudReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const EudReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _EudReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _EudReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kProtoBufPacketTypeValues[] = {
  ProtoBufPacketType::UNKNOWN_PACKET_TYPE,
  ProtoBufPacketType::REQUEST,
  ProtoBufPacketType::RESPONSE
};
const char* _kProtoBufPacketTypeNames[] = {
  "UNKNOWN_PACKET_TYPE",
  "REQUEST",
  "RESPONSE"
};
const std::map<int, const char*> _ProtoBufPacketType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kProtoBufPacketTypeValues, _kProtoBufPacketTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ProtoBufPacketType::type& val) {
  std::map<int, const char*>::const_iterator it = _ProtoBufPacketType_VALUES_TO_NAMES.find(val);
  if (it != _ProtoBufPacketType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ProtoBufPacketType::type& val) {
  std::map<int, const char*>::const_iterator it = _ProtoBufPacketType_VALUES_TO_NAMES.find(val);
  if (it != _ProtoBufPacketType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kProtoBufReturnFlagsValues[] = {
  ProtoBufReturnFlags::SESSION_INDEX,
  ProtoBufReturnFlags::PROTOCOL_INDEX,
  ProtoBufReturnFlags::RECEIVE_TIME_DATA,
  ProtoBufReturnFlags::RECEIVE_TIME_STRING,
  ProtoBufReturnFlags::PACKET_TYPE,
  ProtoBufReturnFlags::PACKET_NAME,
  ProtoBufReturnFlags::BINARY_PAYLOAD,
  ProtoBufReturnFlags::PARSED_TEXT,
  ProtoBufReturnFlags::RPC_ID,
  ProtoBufReturnFlags::QUERY_RESULT_PICKLED,
  ProtoBufReturnFlags::PARSED_TEXT_JSON,
  ProtoBufReturnFlags::QUERY_RESULT_PICKLED_AND_JSON
};
const char* _kProtoBufReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_TYPE",
  "PACKET_NAME",
  "BINARY_PAYLOAD",
  "PARSED_TEXT",
  "RPC_ID",
  "QUERY_RESULT_PICKLED",
  "PARSED_TEXT_JSON",
  "QUERY_RESULT_PICKLED_AND_JSON"
};
const std::map<int, const char*> _ProtoBufReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(12, _kProtoBufReturnFlagsValues, _kProtoBufReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ProtoBufReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _ProtoBufReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _ProtoBufReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ProtoBufReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _ProtoBufReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _ProtoBufReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kAdplReturnFlagsValues[] = {
  AdplReturnFlags::SESSION_INDEX,
  AdplReturnFlags::PROTOCOL_INDEX,
  AdplReturnFlags::RECEIVE_TIME_DATA,
  AdplReturnFlags::RECEIVE_TIME_STRING,
  AdplReturnFlags::PACKET_VERSION,
  AdplReturnFlags::BINARY_PAYLOAD,
  AdplReturnFlags::MODEM_TIMESTAMP,
  AdplReturnFlags::MODEM_TIMESTAMP_STRING,
  AdplReturnFlags::DIAG_BINARY_PAYLOAD
};
const char* _kAdplReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_VERSION",
  "BINARY_PAYLOAD",
  "MODEM_TIMESTAMP",
  "MODEM_TIMESTAMP_STRING",
  "DIAG_BINARY_PAYLOAD"
};
const std::map<int, const char*> _AdplReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(9, _kAdplReturnFlagsValues, _kAdplReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const AdplReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _AdplReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _AdplReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const AdplReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _AdplReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _AdplReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kMbnNvItemDiffResultValues[] = {
  MbnNvItemDiffResult::NV_ITEM_PAYLOAD_MATCHED,
  MbnNvItemDiffResult::NV_ITEM_ONLY_IN_MBN,
  MbnNvItemDiffResult::NV_ITEM_PAYLOAD_MISMATCHED
};
const char* _kMbnNvItemDiffResultNames[] = {
  "NV_ITEM_PAYLOAD_MATCHED",
  "NV_ITEM_ONLY_IN_MBN",
  "NV_ITEM_PAYLOAD_MISMATCHED"
};
const std::map<int, const char*> _MbnNvItemDiffResult_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kMbnNvItemDiffResultValues, _kMbnNvItemDiffResultNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const MbnNvItemDiffResult::type& val) {
  std::map<int, const char*>::const_iterator it = _MbnNvItemDiffResult_VALUES_TO_NAMES.find(val);
  if (it != _MbnNvItemDiffResult_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const MbnNvItemDiffResult::type& val) {
  std::map<int, const char*>::const_iterator it = _MbnNvItemDiffResult_VALUES_TO_NAMES.find(val);
  if (it != _MbnNvItemDiffResult_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kNmeaReturnFlagsValues[] = {
  NmeaReturnFlags::SESSION_INDEX,
  NmeaReturnFlags::PROTOCOL_INDEX,
  NmeaReturnFlags::RECEIVE_TIME_DATA,
  NmeaReturnFlags::RECEIVE_TIME_STRING,
  NmeaReturnFlags::PACKET_ID,
  NmeaReturnFlags::BINARY_PAYLOAD,
  NmeaReturnFlags::PACKET_TEXT
};
const char* _kNmeaReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_ID",
  "BINARY_PAYLOAD",
  "PACKET_TEXT"
};
const std::map<int, const char*> _NmeaReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kNmeaReturnFlagsValues, _kNmeaReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const NmeaReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _NmeaReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _NmeaReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const NmeaReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _NmeaReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _NmeaReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kQdssReturnFlagsValues[] = {
  QdssReturnFlags::SESSION_INDEX,
  QdssReturnFlags::PROTOCOL_INDEX,
  QdssReturnFlags::RECEIVE_TIME_DATA,
  QdssReturnFlags::RECEIVE_TIME_STRING,
  QdssReturnFlags::AT_ID,
  QdssReturnFlags::BINARY_PAYLOAD,
  QdssReturnFlags::HW_TIME_STAMP_DATA,
  QdssReturnFlags::HW_TIME_STAMP_STRING,
  QdssReturnFlags::CHANNEL_ID,
  QdssReturnFlags::MASTER_ID
};
const char* _kQdssReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "AT_ID",
  "BINARY_PAYLOAD",
  "HW_TIME_STAMP_DATA",
  "HW_TIME_STAMP_STRING",
  "CHANNEL_ID",
  "MASTER_ID"
};
const std::map<int, const char*> _QdssReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(10, _kQdssReturnFlagsValues, _kQdssReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const QdssReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _QdssReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _QdssReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const QdssReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _QdssReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _QdssReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kDunReturnFlagsValues[] = {
  DunReturnFlags::SESSION_INDEX,
  DunReturnFlags::PROTOCOL_INDEX,
  DunReturnFlags::RECEIVE_TIME_DATA,
  DunReturnFlags::RECEIVE_TIME_STRING,
  DunReturnFlags::PACKET_ID,
  DunReturnFlags::PACKET_TEXT
};
const char* _kDunReturnFlagsNames[] = {
  "SESSION_INDEX",
  "PROTOCOL_INDEX",
  "RECEIVE_TIME_DATA",
  "RECEIVE_TIME_STRING",
  "PACKET_ID",
  "PACKET_TEXT"
};
const std::map<int, const char*> _DunReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(6, _kDunReturnFlagsValues, _kDunReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const DunReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _DunReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _DunReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const DunReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _DunReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _DunReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kFunctionAreaValues[] = {
  FunctionArea::FUNCTION_AREA_SAHARA_PORT_TRACE,
  FunctionArea::FUNCTION_AREA_FIREHOSE_PORT_TRACE,
  FunctionArea::FUNCTION_AREA_FIREHOSE_LOADER,
  FunctionArea::FUNCTION_AREA_QDSS_DIAG_RAW_TRACE,
  FunctionArea::FUNCTION_AREA_XQCN
};
const char* _kFunctionAreaNames[] = {
  "FUNCTION_AREA_SAHARA_PORT_TRACE",
  "FUNCTION_AREA_FIREHOSE_PORT_TRACE",
  "FUNCTION_AREA_FIREHOSE_LOADER",
  "FUNCTION_AREA_QDSS_DIAG_RAW_TRACE",
  "FUNCTION_AREA_XQCN"
};
const std::map<int, const char*> _FunctionArea_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kFunctionAreaValues, _kFunctionAreaNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const FunctionArea::type& val) {
  std::map<int, const char*>::const_iterator it = _FunctionArea_VALUES_TO_NAMES.find(val);
  if (it != _FunctionArea_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const FunctionArea::type& val) {
  std::map<int, const char*>::const_iterator it = _FunctionArea_VALUES_TO_NAMES.find(val);
  if (it != _FunctionArea_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kLogLevelValues[] = {
  LogLevel::LOG_DEFAULT,
  LogLevel::LOG_DATA,
  LogLevel::LOG_DEBUG,
  LogLevel::LOG_INFO,
  LogLevel::LOG_WARNING,
  LogLevel::LOG_ERROR,
  LogLevel::LOG_EXCEPTION,
  LogLevel::LOG_FATAL,
  LogLevel::LOG_ALL
};
const char* _kLogLevelNames[] = {
  "LOG_DEFAULT",
  "LOG_DATA",
  "LOG_DEBUG",
  "LOG_INFO",
  "LOG_WARNING",
  "LOG_ERROR",
  "LOG_EXCEPTION",
  "LOG_FATAL",
  "LOG_ALL"
};
const std::map<int, const char*> _LogLevel_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(9, _kLogLevelValues, _kLogLevelNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const LogLevel::type& val) {
  std::map<int, const char*>::const_iterator it = _LogLevel_VALUES_TO_NAMES.find(val);
  if (it != _LogLevel_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const LogLevel::type& val) {
  std::map<int, const char*>::const_iterator it = _LogLevel_VALUES_TO_NAMES.find(val);
  if (it != _LogLevel_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kLogFormatValues[] = {
  LogFormat::LOG_CSV,
  LogFormat::LOG_BINARY
};
const char* _kLogFormatNames[] = {
  "LOG_CSV",
  "LOG_BINARY"
};
const std::map<int, const char*> _LogFormat_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kLogFormatValues, _kLogFormatNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const LogFormat::type& val) {
  std::map<int, const char*>::const_iterator it = _LogFormat_VALUES_TO_NAMES.find(val);
  if (it != _LogFormat_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const LogFormat::type& val) {
  std::map<int, const char*>::const_iterator it = _LogFormat_VALUES_TO_NAMES.find(val);
  if (it != _LogFormat_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kLogLayoutValues[] = {
  LogLayout::LOG_DATE,
  LogLayout::LOG_DATEUTC,
  LogLayout::LOG_DATETIME,
  LogLayout::LOG_DATETIMEUTC,
  LogLayout::LOG_TIME,
  LogLayout::LOG_TIMEUTC,
  LogLayout::LOG_TIMEZONE,
  LogLayout::LOG_EPOCH,
  LogLayout::LOG_UPTIME,
  LogLayout::LOG_RUNTIME,
  LogLayout::LOG_SEQUENCE,
  LogLayout::LOG_LOGSEQUENCE,
  LogLayout::LOG_LEVEL,
  LogLayout::LOG_MESSAGE,
  LogLayout::LOG_COMBINED,
  LogLayout::LOG_DATATYPE,
  LogLayout::LOG_DATALEN,
  LogLayout::LOG_DATA,
  LogLayout::LOG_LOGGER,
  LogLayout::LOG_CLASS,
  LogLayout::LOG_NAMESPACE,
  LogLayout::LOG_APPNAME,
  LogLayout::LOG_APPVER,
  LogLayout::LOG_PROCNAME,
  LogLayout::LOG_PID,
  LogLayout::LOG_PROCID,
  LogLayout::LOG_TID,
  LogLayout::LOG_THREADID,
  LogLayout::LOG_THREADNAME,
  LogLayout::LOG_HOSTNAME,
  LogLayout::LOG_USERNAME,
  LogLayout::LOG_CALLERFILE,
  LogLayout::LOG_CALLERPATH,
  LogLayout::LOG_CALLERLINE,
  LogLayout::LOG_CALLERMETHOD,
  LogLayout::LOG_TRACE,
  LogLayout::LOG_EXCEPTION,
  LogLayout::LOG_EXCEPTIONMESSAGE,
  LogLayout::LOG_EXCEPTIONNAME,
  LogLayout::LOG_EXCEPTIONSTACK
};
const char* _kLogLayoutNames[] = {
  "LOG_DATE",
  "LOG_DATEUTC",
  "LOG_DATETIME",
  "LOG_DATETIMEUTC",
  "LOG_TIME",
  "LOG_TIMEUTC",
  "LOG_TIMEZONE",
  "LOG_EPOCH",
  "LOG_UPTIME",
  "LOG_RUNTIME",
  "LOG_SEQUENCE",
  "LOG_LOGSEQUENCE",
  "LOG_LEVEL",
  "LOG_MESSAGE",
  "LOG_COMBINED",
  "LOG_DATATYPE",
  "LOG_DATALEN",
  "LOG_DATA",
  "LOG_LOGGER",
  "LOG_CLASS",
  "LOG_NAMESPACE",
  "LOG_APPNAME",
  "LOG_APPVER",
  "LOG_PROCNAME",
  "LOG_PID",
  "LOG_PROCID",
  "LOG_TID",
  "LOG_THREADID",
  "LOG_THREADNAME",
  "LOG_HOSTNAME",
  "LOG_USERNAME",
  "LOG_CALLERFILE",
  "LOG_CALLERPATH",
  "LOG_CALLERLINE",
  "LOG_CALLERMETHOD",
  "LOG_TRACE",
  "LOG_EXCEPTION",
  "LOG_EXCEPTIONMESSAGE",
  "LOG_EXCEPTIONNAME",
  "LOG_EXCEPTIONSTACK"
};
const std::map<int, const char*> _LogLayout_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(40, _kLogLayoutValues, _kLogLayoutNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const LogLayout::type& val) {
  std::map<int, const char*>::const_iterator it = _LogLayout_VALUES_TO_NAMES.find(val);
  if (it != _LogLayout_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const LogLayout::type& val) {
  std::map<int, const char*>::const_iterator it = _LogLayout_VALUES_TO_NAMES.find(val);
  if (it != _LogLayout_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kQcnItemDiffResultValues[] = {
  QcnItemDiffResult::QCN_ITEM_SAME,
  QcnItemDiffResult::QCN_ITEM_PLUS,
  QcnItemDiffResult::QCN_ITEM_MINUS,
  QcnItemDiffResult::QCN_ITEM_PAYLOAD_MISMATCH
};
const char* _kQcnItemDiffResultNames[] = {
  "QCN_ITEM_SAME",
  "QCN_ITEM_PLUS",
  "QCN_ITEM_MINUS",
  "QCN_ITEM_PAYLOAD_MISMATCH"
};
const std::map<int, const char*> _QcnItemDiffResult_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kQcnItemDiffResultValues, _kQcnItemDiffResultNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const QcnItemDiffResult::type& val) {
  std::map<int, const char*>::const_iterator it = _QcnItemDiffResult_VALUES_TO_NAMES.find(val);
  if (it != _QcnItemDiffResult_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const QcnItemDiffResult::type& val) {
  std::map<int, const char*>::const_iterator it = _QcnItemDiffResult_VALUES_TO_NAMES.find(val);
  if (it != _QcnItemDiffResult_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kCdmaProtocolRevisionValues[] = {
  CdmaProtocolRevision::IS_95A,
  CdmaProtocolRevision::IS_95B,
  CdmaProtocolRevision::IS_2000_Rev_0,
  CdmaProtocolRevision::IS_2000_Rev_A,
  CdmaProtocolRevision::IS_2000_Rev_B,
  CdmaProtocolRevision::IS_2000_Rev_C,
  CdmaProtocolRevision::IS_2000_Rev_C2,
  CdmaProtocolRevision::IS_2000_Rev_D,
  CdmaProtocolRevision::IS_2000_Rev_E
};
const char* _kCdmaProtocolRevisionNames[] = {
  "IS_95A",
  "IS_95B",
  "IS_2000_Rev_0",
  "IS_2000_Rev_A",
  "IS_2000_Rev_B",
  "IS_2000_Rev_C",
  "IS_2000_Rev_C2",
  "IS_2000_Rev_D",
  "IS_2000_Rev_E"
};
const std::map<int, const char*> _CdmaProtocolRevision_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(9, _kCdmaProtocolRevisionValues, _kCdmaProtocolRevisionNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const CdmaProtocolRevision::type& val) {
  std::map<int, const char*>::const_iterator it = _CdmaProtocolRevision_VALUES_TO_NAMES.find(val);
  if (it != _CdmaProtocolRevision_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const CdmaProtocolRevision::type& val) {
  std::map<int, const char*>::const_iterator it = _CdmaProtocolRevision_VALUES_TO_NAMES.find(val);
  if (it != _CdmaProtocolRevision_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kWcdmaProtocolRevisionValues[] = {
  WcdmaProtocolRevision::VB50,
  WcdmaProtocolRevision::VA70,
  WcdmaProtocolRevision::V9B0,
  WcdmaProtocolRevision::VC80,
  WcdmaProtocolRevision::VAB1,
  WcdmaProtocolRevision::V930,
  WcdmaProtocolRevision::V8A0,
  WcdmaProtocolRevision::V860,
  WcdmaProtocolRevision::V7G0,
  WcdmaProtocolRevision::V790,
  WcdmaProtocolRevision::V780,
  WcdmaProtocolRevision::V770,
  WcdmaProtocolRevision::V6F0,
  WcdmaProtocolRevision::V6B0,
  WcdmaProtocolRevision::V6A0,
  WcdmaProtocolRevision::V690,
  WcdmaProtocolRevision::V680,
  WcdmaProtocolRevision::V590,
  WcdmaProtocolRevision::V3I0,
  WcdmaProtocolRevision::V3A0,
  WcdmaProtocolRevision::V370,
  WcdmaProtocolRevision::V350,
  WcdmaProtocolRevision::VC81
};
const char* _kWcdmaProtocolRevisionNames[] = {
  "VB50",
  "VA70",
  "V9B0",
  "VC80",
  "VAB1",
  "V930",
  "V8A0",
  "V860",
  "V7G0",
  "V790",
  "V780",
  "V770",
  "V6F0",
  "V6B0",
  "V6A0",
  "V690",
  "V680",
  "V590",
  "V3I0",
  "V3A0",
  "V370",
  "V350",
  "VC81"
};
const std::map<int, const char*> _WcdmaProtocolRevision_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(23, _kWcdmaProtocolRevisionValues, _kWcdmaProtocolRevisionNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const WcdmaProtocolRevision::type& val) {
  std::map<int, const char*>::const_iterator it = _WcdmaProtocolRevision_VALUES_TO_NAMES.find(val);
  if (it != _WcdmaProtocolRevision_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const WcdmaProtocolRevision::type& val) {
  std::map<int, const char*>::const_iterator it = _WcdmaProtocolRevision_VALUES_TO_NAMES.find(val);
  if (it != _WcdmaProtocolRevision_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kBaudRateValues[] = {
  BaudRate::BAUD_RATE_75,
  BaudRate::BAUD_RATE_110,
  BaudRate::BAUD_RATE_134,
  BaudRate::BAUD_RATE_150,
  BaudRate::BAUD_RATE_300,
  BaudRate::BAUD_RATE_600,
  BaudRate::BAUD_RATE_1200,
  BaudRate::BAUD_RATE_1800,
  BaudRate::BAUD_RATE_2400,
  BaudRate::BAUD_RATE_4800,
  BaudRate::BAUD_RATE_7200,
  BaudRate::BAUD_RATE_9600,
  BaudRate::BAUD_RATE_14400,
  BaudRate::BAUD_RATE_19200,
  BaudRate::BAUD_RATE_38400,
  BaudRate::BAUD_RATE_57600,
  BaudRate::BAUD_RATE_115200,
  BaudRate::BAUD_RATE_128000,
  BaudRate::BAUD_RATE_230400,
  BaudRate::BAUD_RATE_460800,
  BaudRate::BAUD_RATE_921600,
  BaudRate::BAUD_RATE_1200000,
  BaudRate::BAUD_RATE_1843200,
  BaudRate::BAUD_RATE_3000000
};
const char* _kBaudRateNames[] = {
  "BAUD_RATE_75",
  "BAUD_RATE_110",
  "BAUD_RATE_134",
  "BAUD_RATE_150",
  "BAUD_RATE_300",
  "BAUD_RATE_600",
  "BAUD_RATE_1200",
  "BAUD_RATE_1800",
  "BAUD_RATE_2400",
  "BAUD_RATE_4800",
  "BAUD_RATE_7200",
  "BAUD_RATE_9600",
  "BAUD_RATE_14400",
  "BAUD_RATE_19200",
  "BAUD_RATE_38400",
  "BAUD_RATE_57600",
  "BAUD_RATE_115200",
  "BAUD_RATE_128000",
  "BAUD_RATE_230400",
  "BAUD_RATE_460800",
  "BAUD_RATE_921600",
  "BAUD_RATE_1200000",
  "BAUD_RATE_1843200",
  "BAUD_RATE_3000000"
};
const std::map<int, const char*> _BaudRate_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(24, _kBaudRateValues, _kBaudRateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const BaudRate::type& val) {
  std::map<int, const char*>::const_iterator it = _BaudRate_VALUES_TO_NAMES.find(val);
  if (it != _BaudRate_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const BaudRate::type& val) {
  std::map<int, const char*>::const_iterator it = _BaudRate_VALUES_TO_NAMES.find(val);
  if (it != _BaudRate_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kHdlcModeStatusValues[] = {
  HdlcModeStatus::NOT_SET,
  HdlcModeStatus::DISABLE,
  HdlcModeStatus::ENABLE
};
const char* _kHdlcModeStatusNames[] = {
  "NOT_SET",
  "DISABLE",
  "ENABLE"
};
const std::map<int, const char*> _HdlcModeStatus_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kHdlcModeStatusValues, _kHdlcModeStatusNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const HdlcModeStatus::type& val) {
  std::map<int, const char*>::const_iterator it = _HdlcModeStatus_VALUES_TO_NAMES.find(val);
  if (it != _HdlcModeStatus_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const HdlcModeStatus::type& val) {
  std::map<int, const char*>::const_iterator it = _HdlcModeStatus_VALUES_TO_NAMES.find(val);
  if (it != _HdlcModeStatus_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kHdlcModeValues[] = {
  HdlcMode::NON_HDLC_AUTO,
  HdlcMode::HDLC_ONLY
};
const char* _kHdlcModeNames[] = {
  "NON_HDLC_AUTO",
  "HDLC_ONLY"
};
const std::map<int, const char*> _HdlcMode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kHdlcModeValues, _kHdlcModeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const HdlcMode::type& val) {
  std::map<int, const char*>::const_iterator it = _HdlcMode_VALUES_TO_NAMES.find(val);
  if (it != _HdlcMode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const HdlcMode::type& val) {
  std::map<int, const char*>::const_iterator it = _HdlcMode_VALUES_TO_NAMES.find(val);
  if (it != _HdlcMode_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kEudPeripheralTypeValues[] = {
  EudPeripheralType::PERIPHERALTYPE_EUD_NULL,
  EudPeripheralType::PERIPHERALTYPE_EUD_CTL,
  EudPeripheralType::PERIPHERALTYPE_EUD_JTG,
  EudPeripheralType::PERIPHERALTYPE_EUD_SWD,
  EudPeripheralType::PERIPHERALTYPE_EUD_TRC,
  EudPeripheralType::PERIPHERALTYPE_EUD_COM
};
const char* _kEudPeripheralTypeNames[] = {
  "PERIPHERALTYPE_EUD_NULL",
  "PERIPHERALTYPE_EUD_CTL",
  "PERIPHERALTYPE_EUD_JTG",
  "PERIPHERALTYPE_EUD_SWD",
  "PERIPHERALTYPE_EUD_TRC",
  "PERIPHERALTYPE_EUD_COM"
};
const std::map<int, const char*> _EudPeripheralType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(6, _kEudPeripheralTypeValues, _kEudPeripheralTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const EudPeripheralType::type& val) {
  std::map<int, const char*>::const_iterator it = _EudPeripheralType_VALUES_TO_NAMES.find(val);
  if (it != _EudPeripheralType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const EudPeripheralType::type& val) {
  std::map<int, const char*>::const_iterator it = _EudPeripheralType_VALUES_TO_NAMES.find(val);
  if (it != _EudPeripheralType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kXqcnOperationTypeValues[] = {
  XqcnOperationType::XQCN_BACKUP,
  XqcnOperationType::XQCN_RESTORE
};
const char* _kXqcnOperationTypeNames[] = {
  "XQCN_BACKUP",
  "XQCN_RESTORE"
};
const std::map<int, const char*> _XqcnOperationType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kXqcnOperationTypeValues, _kXqcnOperationTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const XqcnOperationType::type& val) {
  std::map<int, const char*>::const_iterator it = _XqcnOperationType_VALUES_TO_NAMES.find(val);
  if (it != _XqcnOperationType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const XqcnOperationType::type& val) {
  std::map<int, const char*>::const_iterator it = _XqcnOperationType_VALUES_TO_NAMES.find(val);
  if (it != _XqcnOperationType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kQmStatusTypeValues[] = {
  QmStatusType::SUCCESS,
  QmStatusType::E_DEVICE_ERROR,
  QmStatusType::E_NOT_SUPPORTED,
  QmStatusType::E_INVALID
};
const char* _kQmStatusTypeNames[] = {
  "SUCCESS",
  "E_DEVICE_ERROR",
  "E_NOT_SUPPORTED",
  "E_INVALID"
};
const std::map<int, const char*> _QmStatusType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kQmStatusTypeValues, _kQmStatusTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const QmStatusType::type& val) {
  std::map<int, const char*>::const_iterator it = _QmStatusType_VALUES_TO_NAMES.find(val);
  if (it != _QmStatusType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const QmStatusType::type& val) {
  std::map<int, const char*>::const_iterator it = _QmStatusType_VALUES_TO_NAMES.find(val);
  if (it != _QmStatusType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kResourcePersistenceTypeValues[] = {
  ResourcePersistenceType::STATIC_RESOURCE_PERSISTENCE,
  ResourcePersistenceType::DYNAMIC_RESOURCE_PERSISTENCE
};
const char* _kResourcePersistenceTypeNames[] = {
  "STATIC_RESOURCE_PERSISTENCE",
  "DYNAMIC_RESOURCE_PERSISTENCE"
};
const std::map<int, const char*> _ResourcePersistenceType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kResourcePersistenceTypeValues, _kResourcePersistenceTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ResourcePersistenceType::type& val) {
  std::map<int, const char*>::const_iterator it = _ResourcePersistenceType_VALUES_TO_NAMES.find(val);
  if (it != _ResourcePersistenceType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ResourcePersistenceType::type& val) {
  std::map<int, const char*>::const_iterator it = _ResourcePersistenceType_VALUES_TO_NAMES.find(val);
  if (it != _ResourcePersistenceType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kSamplingRatesEnumValues[] = {
  SamplingRatesEnum::FULL_RATE,
  SamplingRatesEnum::HALF_RATE,
  SamplingRatesEnum::QUARTER_RATE,
  SamplingRatesEnum::EIGHT_RATE,
  SamplingRatesEnum::SIXTEENTH_RATE
};
const char* _kSamplingRatesEnumNames[] = {
  "FULL_RATE",
  "HALF_RATE",
  "QUARTER_RATE",
  "EIGHT_RATE",
  "SIXTEENTH_RATE"
};
const std::map<int, const char*> _SamplingRatesEnum_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kSamplingRatesEnumValues, _kSamplingRatesEnumNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const SamplingRatesEnum::type& val) {
  std::map<int, const char*>::const_iterator it = _SamplingRatesEnum_VALUES_TO_NAMES.find(val);
  if (it != _SamplingRatesEnum_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const SamplingRatesEnum::type& val) {
  std::map<int, const char*>::const_iterator it = _SamplingRatesEnum_VALUES_TO_NAMES.find(val);
  if (it != _SamplingRatesEnum_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}


ClientInfo::~ClientInfo() noexcept {
}


void ClientInfo::__set_clientName(const std::string& val) {
  this->clientName = val;
}

void ClientInfo::__set_licenseKey(const std::string& val) {
  this->licenseKey = val;
}

void ClientInfo::__set_isAutomation(const bool val) {
  this->isAutomation = val;
__isset.isAutomation = true;
}

void ClientInfo::__set_appName(const std::string& val) {
  this->appName = val;
__isset.appName = true;
}

void ClientInfo::__set_username(const std::string& val) {
  this->username = val;
__isset.username = true;
}

void ClientInfo::__set_qutsOperatingMode(const QutsOperatingMode::type val) {
  this->qutsOperatingMode = val;
__isset.qutsOperatingMode = true;
}
std::ostream& operator<<(std::ostream& out, const ClientInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ClientInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_clientName = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->clientName);
          isset_clientName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->licenseKey);
          this->__isset.licenseKey = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isAutomation);
          this->__isset.isAutomation = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->appName);
          this->__isset.appName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->username);
          this->__isset.username = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->qutsOperatingMode = (QutsOperatingMode::type)ecast0;
          this->__isset.qutsOperatingMode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_clientName)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t ClientInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientInfo");

  xfer += oprot->writeFieldBegin("clientName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->clientName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("licenseKey", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->licenseKey);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.isAutomation) {
    xfer += oprot->writeFieldBegin("isAutomation", ::apache::thrift::protocol::T_BOOL, 3);
    xfer += oprot->writeBool(this->isAutomation);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.appName) {
    xfer += oprot->writeFieldBegin("appName", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->appName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.username) {
    xfer += oprot->writeFieldBegin("username", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->username);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qutsOperatingMode) {
    xfer += oprot->writeFieldBegin("qutsOperatingMode", ::apache::thrift::protocol::T_I32, 6);
    xfer += oprot->writeI32((int32_t)this->qutsOperatingMode);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ClientInfo &a, ClientInfo &b) {
  using ::std::swap;
  swap(a.clientName, b.clientName);
  swap(a.licenseKey, b.licenseKey);
  swap(a.isAutomation, b.isAutomation);
  swap(a.appName, b.appName);
  swap(a.username, b.username);
  swap(a.qutsOperatingMode, b.qutsOperatingMode);
  swap(a.__isset, b.__isset);
}

ClientInfo::ClientInfo(const ClientInfo& other1) {
  clientName = other1.clientName;
  licenseKey = other1.licenseKey;
  isAutomation = other1.isAutomation;
  appName = other1.appName;
  username = other1.username;
  qutsOperatingMode = other1.qutsOperatingMode;
  __isset = other1.__isset;
}
ClientInfo& ClientInfo::operator=(const ClientInfo& other2) {
  clientName = other2.clientName;
  licenseKey = other2.licenseKey;
  isAutomation = other2.isAutomation;
  appName = other2.appName;
  username = other2.username;
  qutsOperatingMode = other2.qutsOperatingMode;
  __isset = other2.__isset;
  return *this;
}
void ClientInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ClientInfo(";
  out << "clientName=" << to_string(clientName);
  out << ", " << "licenseKey=" << to_string(licenseKey);
  out << ", " << "isAutomation="; (__isset.isAutomation ? (out << to_string(isAutomation)) : (out << "<null>"));
  out << ", " << "appName="; (__isset.appName ? (out << to_string(appName)) : (out << "<null>"));
  out << ", " << "username="; (__isset.username ? (out << to_string(username)) : (out << "<null>"));
  out << ", " << "qutsOperatingMode="; (__isset.qutsOperatingMode ? (out << to_string(qutsOperatingMode)) : (out << "<null>"));
  out << ")";
}


ErrorType::~ErrorType() noexcept {
}


void ErrorType::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
}

void ErrorType::__set_errorString(const std::string& val) {
  this->errorString = val;
}
std::ostream& operator<<(std::ostream& out, const ErrorType& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ErrorType::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_errorCode = false;
  bool isset_errorString = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast3;
          xfer += iprot->readI32(ecast3);
          this->errorCode = (ErrorCode::type)ecast3;
          isset_errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->errorString);
          isset_errorString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_errorCode)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_errorString)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t ErrorType::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ErrorType");

  xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->errorCode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("errorString", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->errorString);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ErrorType &a, ErrorType &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.errorString, b.errorString);
}

ErrorType::ErrorType(const ErrorType& other4) {
  errorCode = other4.errorCode;
  errorString = other4.errorString;
}
ErrorType& ErrorType::operator=(const ErrorType& other5) {
  errorCode = other5.errorCode;
  errorString = other5.errorString;
  return *this;
}
void ErrorType::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ErrorType(";
  out << "errorCode=" << to_string(errorCode);
  out << ", " << "errorString=" << to_string(errorString);
  out << ")";
}


AppException::~AppException() noexcept {
}


void AppException::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
}

void AppException::__set_errorString(const std::string& val) {
  this->errorString = val;
}
std::ostream& operator<<(std::ostream& out, const AppException& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t AppException::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_errorCode = false;
  bool isset_errorString = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast6;
          xfer += iprot->readI32(ecast6);
          this->errorCode = (ErrorCode::type)ecast6;
          isset_errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->errorString);
          isset_errorString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_errorCode)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_errorString)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t AppException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AppException");

  xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->errorCode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("errorString", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->errorString);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AppException &a, AppException &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.errorString, b.errorString);
}

AppException::AppException(const AppException& other7) : TException() {
  errorCode = other7.errorCode;
  errorString = other7.errorString;
}
AppException& AppException::operator=(const AppException& other8) {
  errorCode = other8.errorCode;
  errorString = other8.errorString;
  return *this;
}
void AppException::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AppException(";
  out << "errorCode=" << to_string(errorCode);
  out << ", " << "errorString=" << to_string(errorString);
  out << ")";
}

const char* AppException::what() const noexcept {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: AppException";
  }
}


ProtocolUsageIndicator::~ProtocolUsageIndicator() noexcept {
}


void ProtocolUsageIndicator::__set_flowControlStatus(const FlowControlStatus::type val) {
  this->flowControlStatus = val;
}

void ProtocolUsageIndicator::__set_flowControlLevel(const FlowControlLevel::type val) {
  this->flowControlLevel = val;
}

void ProtocolUsageIndicator::__set_ioWatermark(const int32_t val) {
  this->ioWatermark = val;
}

void ProtocolUsageIndicator::__set_functionWatermark(const int32_t val) {
  this->functionWatermark = val;
}
std::ostream& operator<<(std::ostream& out, const ProtocolUsageIndicator& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProtocolUsageIndicator::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast9;
          xfer += iprot->readI32(ecast9);
          this->flowControlStatus = (FlowControlStatus::type)ecast9;
          this->__isset.flowControlStatus = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast10;
          xfer += iprot->readI32(ecast10);
          this->flowControlLevel = (FlowControlLevel::type)ecast10;
          this->__isset.flowControlLevel = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->ioWatermark);
          this->__isset.ioWatermark = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->functionWatermark);
          this->__isset.functionWatermark = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProtocolUsageIndicator::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProtocolUsageIndicator");

  xfer += oprot->writeFieldBegin("flowControlStatus", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flowControlStatus);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("flowControlLevel", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->flowControlLevel);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("ioWatermark", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->ioWatermark);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("functionWatermark", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->functionWatermark);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProtocolUsageIndicator &a, ProtocolUsageIndicator &b) {
  using ::std::swap;
  swap(a.flowControlStatus, b.flowControlStatus);
  swap(a.flowControlLevel, b.flowControlLevel);
  swap(a.ioWatermark, b.ioWatermark);
  swap(a.functionWatermark, b.functionWatermark);
  swap(a.__isset, b.__isset);
}

ProtocolUsageIndicator::ProtocolUsageIndicator(const ProtocolUsageIndicator& other11) {
  flowControlStatus = other11.flowControlStatus;
  flowControlLevel = other11.flowControlLevel;
  ioWatermark = other11.ioWatermark;
  functionWatermark = other11.functionWatermark;
  __isset = other11.__isset;
}
ProtocolUsageIndicator& ProtocolUsageIndicator::operator=(const ProtocolUsageIndicator& other12) {
  flowControlStatus = other12.flowControlStatus;
  flowControlLevel = other12.flowControlLevel;
  ioWatermark = other12.ioWatermark;
  functionWatermark = other12.functionWatermark;
  __isset = other12.__isset;
  return *this;
}
void ProtocolUsageIndicator::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProtocolUsageIndicator(";
  out << "flowControlStatus=" << to_string(flowControlStatus);
  out << ", " << "flowControlLevel=" << to_string(flowControlLevel);
  out << ", " << "ioWatermark=" << to_string(ioWatermark);
  out << ", " << "functionWatermark=" << to_string(functionWatermark);
  out << ")";
}


UsageIndicators::~UsageIndicators() noexcept {
}


void UsageIndicators::__set_isOptimal(const bool val) {
  this->isOptimal = val;
}

void UsageIndicators::__set_indicators(const std::map<int64_t, ProtocolUsageIndicator> & val) {
  this->indicators = val;
}
std::ostream& operator<<(std::ostream& out, const UsageIndicators& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t UsageIndicators::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isOptimal);
          this->__isset.isOptimal = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->indicators.clear();
            uint32_t _size13;
            ::apache::thrift::protocol::TType _ktype14;
            ::apache::thrift::protocol::TType _vtype15;
            xfer += iprot->readMapBegin(_ktype14, _vtype15, _size13);
            uint32_t _i17;
            for (_i17 = 0; _i17 < _size13; ++_i17)
            {
              int64_t _key18;
              xfer += iprot->readI64(_key18);
              ProtocolUsageIndicator& _val19 = this->indicators[_key18];
              xfer += _val19.read(iprot);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.indicators = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t UsageIndicators::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("UsageIndicators");

  xfer += oprot->writeFieldBegin("isOptimal", ::apache::thrift::protocol::T_BOOL, 1);
  xfer += oprot->writeBool(this->isOptimal);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("indicators", ::apache::thrift::protocol::T_MAP, 2);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I64, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->indicators.size()));
    std::map<int64_t, ProtocolUsageIndicator> ::const_iterator _iter20;
    for (_iter20 = this->indicators.begin(); _iter20 != this->indicators.end(); ++_iter20)
    {
      xfer += oprot->writeI64(_iter20->first);
      xfer += _iter20->second.write(oprot);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(UsageIndicators &a, UsageIndicators &b) {
  using ::std::swap;
  swap(a.isOptimal, b.isOptimal);
  swap(a.indicators, b.indicators);
  swap(a.__isset, b.__isset);
}

UsageIndicators::UsageIndicators(const UsageIndicators& other21) {
  isOptimal = other21.isOptimal;
  indicators = other21.indicators;
  __isset = other21.__isset;
}
UsageIndicators& UsageIndicators::operator=(const UsageIndicators& other22) {
  isOptimal = other22.isOptimal;
  indicators = other22.indicators;
  __isset = other22.__isset;
  return *this;
}
void UsageIndicators::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "UsageIndicators(";
  out << "isOptimal=" << to_string(isOptimal);
  out << ", " << "indicators=" << to_string(indicators);
  out << ")";
}


LockStatus::~LockStatus() noexcept {
}


void LockStatus::__set_lockState(const LockState::type val) {
  this->lockState = val;
}

void LockStatus::__set_clientId(const int64_t val) {
  this->clientId = val;
__isset.clientId = true;
}

void LockStatus::__set_reason(const std::string& val) {
  this->reason = val;
__isset.reason = true;
}
std::ostream& operator<<(std::ostream& out, const LockStatus& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t LockStatus::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast23;
          xfer += iprot->readI32(ecast23);
          this->lockState = (LockState::type)ecast23;
          this->__isset.lockState = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->clientId);
          this->__isset.clientId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->reason);
          this->__isset.reason = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t LockStatus::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("LockStatus");

  xfer += oprot->writeFieldBegin("lockState", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->lockState);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.clientId) {
    xfer += oprot->writeFieldBegin("clientId", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->clientId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.reason) {
    xfer += oprot->writeFieldBegin("reason", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->reason);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(LockStatus &a, LockStatus &b) {
  using ::std::swap;
  swap(a.lockState, b.lockState);
  swap(a.clientId, b.clientId);
  swap(a.reason, b.reason);
  swap(a.__isset, b.__isset);
}

LockStatus::LockStatus(const LockStatus& other24) {
  lockState = other24.lockState;
  clientId = other24.clientId;
  reason = other24.reason;
  __isset = other24.__isset;
}
LockStatus& LockStatus::operator=(const LockStatus& other25) {
  lockState = other25.lockState;
  clientId = other25.clientId;
  reason = other25.reason;
  __isset = other25.__isset;
  return *this;
}
void LockStatus::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "LockStatus(";
  out << "lockState=" << to_string(lockState);
  out << ", " << "clientId="; (__isset.clientId ? (out << to_string(clientId)) : (out << "<null>"));
  out << ", " << "reason="; (__isset.reason ? (out << to_string(reason)) : (out << "<null>"));
  out << ")";
}


MbnDownloadStatus::~MbnDownloadStatus() noexcept {
}


void MbnDownloadStatus::__set_downloadState(const MbnDownloadState::type val) {
  this->downloadState = val;
}

void MbnDownloadStatus::__set_indicationToken(const int32_t val) {
  this->indicationToken = val;
__isset.indicationToken = true;
}

void MbnDownloadStatus::__set_configType(const int32_t val) {
  this->configType = val;
__isset.configType = true;
}

void MbnDownloadStatus::__set_subscriptionId(const int32_t val) {
  this->subscriptionId = val;
__isset.subscriptionId = true;
}

void MbnDownloadStatus::__set_activeConfigId(const std::string& val) {
  this->activeConfigId = val;
__isset.activeConfigId = true;
}

void MbnDownloadStatus::__set_pendingConfigId(const std::string& val) {
  this->pendingConfigId = val;
__isset.pendingConfigId = true;
}
std::ostream& operator<<(std::ostream& out, const MbnDownloadStatus& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t MbnDownloadStatus::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast26;
          xfer += iprot->readI32(ecast26);
          this->downloadState = (MbnDownloadState::type)ecast26;
          this->__isset.downloadState = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->indicationToken);
          this->__isset.indicationToken = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->configType);
          this->__isset.configType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->activeConfigId);
          this->__isset.activeConfigId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->pendingConfigId);
          this->__isset.pendingConfigId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MbnDownloadStatus::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MbnDownloadStatus");

  xfer += oprot->writeFieldBegin("downloadState", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->downloadState);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.indicationToken) {
    xfer += oprot->writeFieldBegin("indicationToken", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->indicationToken);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.configType) {
    xfer += oprot->writeFieldBegin("configType", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->configType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.subscriptionId) {
    xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->subscriptionId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.activeConfigId) {
    xfer += oprot->writeFieldBegin("activeConfigId", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->activeConfigId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.pendingConfigId) {
    xfer += oprot->writeFieldBegin("pendingConfigId", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->pendingConfigId);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MbnDownloadStatus &a, MbnDownloadStatus &b) {
  using ::std::swap;
  swap(a.downloadState, b.downloadState);
  swap(a.indicationToken, b.indicationToken);
  swap(a.configType, b.configType);
  swap(a.subscriptionId, b.subscriptionId);
  swap(a.activeConfigId, b.activeConfigId);
  swap(a.pendingConfigId, b.pendingConfigId);
  swap(a.__isset, b.__isset);
}

MbnDownloadStatus::MbnDownloadStatus(const MbnDownloadStatus& other27) {
  downloadState = other27.downloadState;
  indicationToken = other27.indicationToken;
  configType = other27.configType;
  subscriptionId = other27.subscriptionId;
  activeConfigId = other27.activeConfigId;
  pendingConfigId = other27.pendingConfigId;
  __isset = other27.__isset;
}
MbnDownloadStatus& MbnDownloadStatus::operator=(const MbnDownloadStatus& other28) {
  downloadState = other28.downloadState;
  indicationToken = other28.indicationToken;
  configType = other28.configType;
  subscriptionId = other28.subscriptionId;
  activeConfigId = other28.activeConfigId;
  pendingConfigId = other28.pendingConfigId;
  __isset = other28.__isset;
  return *this;
}
void MbnDownloadStatus::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MbnDownloadStatus(";
  out << "downloadState=" << to_string(downloadState);
  out << ", " << "indicationToken="; (__isset.indicationToken ? (out << to_string(indicationToken)) : (out << "<null>"));
  out << ", " << "configType="; (__isset.configType ? (out << to_string(configType)) : (out << "<null>"));
  out << ", " << "subscriptionId="; (__isset.subscriptionId ? (out << to_string(subscriptionId)) : (out << "<null>"));
  out << ", " << "activeConfigId="; (__isset.activeConfigId ? (out << to_string(activeConfigId)) : (out << "<null>"));
  out << ", " << "pendingConfigId="; (__isset.pendingConfigId ? (out << to_string(pendingConfigId)) : (out << "<null>"));
  out << ")";
}


ProtocolInfo::~ProtocolInfo() noexcept {
}


void ProtocolInfo::__set_protocolHandle(const int64_t val) {
  this->protocolHandle = val;
}

void ProtocolInfo::__set_deviceHandle(const int64_t val) {
  this->deviceHandle = val;
}

void ProtocolInfo::__set_description(const std::string& val) {
  this->description = val;
}

void ProtocolInfo::__set_protocolType(const ProtocolType::type val) {
  this->protocolType = val;
}

void ProtocolInfo::__set_connectionType(const ConnectionType::type val) {
  this->connectionType = val;
}

void ProtocolInfo::__set_connectionStatus(const OpenProp::type val) {
  this->connectionStatus = val;
}

void ProtocolInfo::__set_shareStatus(const OpenProp::type val) {
  this->shareStatus = val;
}

void ProtocolInfo::__set_protocolState(const ProtocolState::type val) {
  this->protocolState = val;
}
std::ostream& operator<<(std::ostream& out, const ProtocolInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProtocolInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->deviceHandle);
          this->__isset.deviceHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast29;
          xfer += iprot->readI32(ecast29);
          this->protocolType = (ProtocolType::type)ecast29;
          this->__isset.protocolType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast30;
          xfer += iprot->readI32(ecast30);
          this->connectionType = (ConnectionType::type)ecast30;
          this->__isset.connectionType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast31;
          xfer += iprot->readI32(ecast31);
          this->connectionStatus = (OpenProp::type)ecast31;
          this->__isset.connectionStatus = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast32;
          xfer += iprot->readI32(ecast32);
          this->shareStatus = (OpenProp::type)ecast32;
          this->__isset.shareStatus = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast33;
          xfer += iprot->readI32(ecast33);
          this->protocolState = (ProtocolState::type)ecast33;
          this->__isset.protocolState = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProtocolInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProtocolInfo");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->deviceHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->description);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolType", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32((int32_t)this->protocolType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("connectionType", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32((int32_t)this->connectionType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("connectionStatus", ::apache::thrift::protocol::T_I32, 6);
  xfer += oprot->writeI32((int32_t)this->connectionStatus);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("shareStatus", ::apache::thrift::protocol::T_I32, 7);
  xfer += oprot->writeI32((int32_t)this->shareStatus);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolState", ::apache::thrift::protocol::T_I32, 8);
  xfer += oprot->writeI32((int32_t)this->protocolState);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProtocolInfo &a, ProtocolInfo &b) {
  using ::std::swap;
  swap(a.protocolHandle, b.protocolHandle);
  swap(a.deviceHandle, b.deviceHandle);
  swap(a.description, b.description);
  swap(a.protocolType, b.protocolType);
  swap(a.connectionType, b.connectionType);
  swap(a.connectionStatus, b.connectionStatus);
  swap(a.shareStatus, b.shareStatus);
  swap(a.protocolState, b.protocolState);
  swap(a.__isset, b.__isset);
}

ProtocolInfo::ProtocolInfo(const ProtocolInfo& other34) {
  protocolHandle = other34.protocolHandle;
  deviceHandle = other34.deviceHandle;
  description = other34.description;
  protocolType = other34.protocolType;
  connectionType = other34.connectionType;
  connectionStatus = other34.connectionStatus;
  shareStatus = other34.shareStatus;
  protocolState = other34.protocolState;
  __isset = other34.__isset;
}
ProtocolInfo& ProtocolInfo::operator=(const ProtocolInfo& other35) {
  protocolHandle = other35.protocolHandle;
  deviceHandle = other35.deviceHandle;
  description = other35.description;
  protocolType = other35.protocolType;
  connectionType = other35.connectionType;
  connectionStatus = other35.connectionStatus;
  shareStatus = other35.shareStatus;
  protocolState = other35.protocolState;
  __isset = other35.__isset;
  return *this;
}
void ProtocolInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProtocolInfo(";
  out << "protocolHandle=" << to_string(protocolHandle);
  out << ", " << "deviceHandle=" << to_string(deviceHandle);
  out << ", " << "description=" << to_string(description);
  out << ", " << "protocolType=" << to_string(protocolType);
  out << ", " << "connectionType=" << to_string(connectionType);
  out << ", " << "connectionStatus=" << to_string(connectionStatus);
  out << ", " << "shareStatus=" << to_string(shareStatus);
  out << ", " << "protocolState=" << to_string(protocolState);
  out << ")";
}


DeviceInfo::~DeviceInfo() noexcept {
}


void DeviceInfo::__set_deviceHandle(const int64_t val) {
  this->deviceHandle = val;
}

void DeviceInfo::__set_description(const std::string& val) {
  this->description = val;
}

void DeviceInfo::__set_protocols(const std::vector<ProtocolInfo> & val) {
  this->protocols = val;
}

void DeviceInfo::__set_services(const std::vector<std::string> & val) {
  this->services = val;
}

void DeviceInfo::__set_serialNumber(const std::string& val) {
  this->serialNumber = val;
}

void DeviceInfo::__set_adbSerialNumber(const std::string& val) {
  this->adbSerialNumber = val;
}

void DeviceInfo::__set_location(const std::string& val) {
  this->location = val;
}

void DeviceInfo::__set_vid(const std::string& val) {
  this->vid = val;
}

void DeviceInfo::__set_pid(const std::string& val) {
  this->pid = val;
}

void DeviceInfo::__set_edlChipId(const std::string& val) {
  this->edlChipId = val;
}
std::ostream& operator<<(std::ostream& out, const DeviceInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DeviceInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->deviceHandle);
          this->__isset.deviceHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->protocols.clear();
            uint32_t _size36;
            ::apache::thrift::protocol::TType _etype39;
            xfer += iprot->readListBegin(_etype39, _size36);
            this->protocols.resize(_size36);
            uint32_t _i40;
            for (_i40 = 0; _i40 < _size36; ++_i40)
            {
              xfer += this->protocols[_i40].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.protocols = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->services.clear();
            uint32_t _size41;
            ::apache::thrift::protocol::TType _etype44;
            xfer += iprot->readListBegin(_etype44, _size41);
            this->services.resize(_size41);
            uint32_t _i45;
            for (_i45 = 0; _i45 < _size41; ++_i45)
            {
              xfer += iprot->readString(this->services[_i45]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.services = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->serialNumber);
          this->__isset.serialNumber = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->adbSerialNumber);
          this->__isset.adbSerialNumber = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->location);
          this->__isset.location = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->vid);
          this->__isset.vid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->pid);
          this->__isset.pid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->edlChipId);
          this->__isset.edlChipId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DeviceInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceInfo");

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->deviceHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->description);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocols", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->protocols.size()));
    std::vector<ProtocolInfo> ::const_iterator _iter46;
    for (_iter46 = this->protocols.begin(); _iter46 != this->protocols.end(); ++_iter46)
    {
      xfer += (*_iter46).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("services", ::apache::thrift::protocol::T_LIST, 4);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->services.size()));
    std::vector<std::string> ::const_iterator _iter47;
    for (_iter47 = this->services.begin(); _iter47 != this->services.end(); ++_iter47)
    {
      xfer += oprot->writeString((*_iter47));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("serialNumber", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->serialNumber);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("adbSerialNumber", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->adbSerialNumber);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("location", ::apache::thrift::protocol::T_STRING, 7);
  xfer += oprot->writeString(this->location);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("vid", ::apache::thrift::protocol::T_STRING, 8);
  xfer += oprot->writeString(this->vid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pid", ::apache::thrift::protocol::T_STRING, 9);
  xfer += oprot->writeString(this->pid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("edlChipId", ::apache::thrift::protocol::T_STRING, 10);
  xfer += oprot->writeString(this->edlChipId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DeviceInfo &a, DeviceInfo &b) {
  using ::std::swap;
  swap(a.deviceHandle, b.deviceHandle);
  swap(a.description, b.description);
  swap(a.protocols, b.protocols);
  swap(a.services, b.services);
  swap(a.serialNumber, b.serialNumber);
  swap(a.adbSerialNumber, b.adbSerialNumber);
  swap(a.location, b.location);
  swap(a.vid, b.vid);
  swap(a.pid, b.pid);
  swap(a.edlChipId, b.edlChipId);
  swap(a.__isset, b.__isset);
}

DeviceInfo::DeviceInfo(const DeviceInfo& other48) {
  deviceHandle = other48.deviceHandle;
  description = other48.description;
  protocols = other48.protocols;
  services = other48.services;
  serialNumber = other48.serialNumber;
  adbSerialNumber = other48.adbSerialNumber;
  location = other48.location;
  vid = other48.vid;
  pid = other48.pid;
  edlChipId = other48.edlChipId;
  __isset = other48.__isset;
}
DeviceInfo& DeviceInfo::operator=(const DeviceInfo& other49) {
  deviceHandle = other49.deviceHandle;
  description = other49.description;
  protocols = other49.protocols;
  services = other49.services;
  serialNumber = other49.serialNumber;
  adbSerialNumber = other49.adbSerialNumber;
  location = other49.location;
  vid = other49.vid;
  pid = other49.pid;
  edlChipId = other49.edlChipId;
  __isset = other49.__isset;
  return *this;
}
void DeviceInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DeviceInfo(";
  out << "deviceHandle=" << to_string(deviceHandle);
  out << ", " << "description=" << to_string(description);
  out << ", " << "protocols=" << to_string(protocols);
  out << ", " << "services=" << to_string(services);
  out << ", " << "serialNumber=" << to_string(serialNumber);
  out << ", " << "adbSerialNumber=" << to_string(adbSerialNumber);
  out << ", " << "location=" << to_string(location);
  out << ", " << "vid=" << to_string(vid);
  out << ", " << "pid=" << to_string(pid);
  out << ", " << "edlChipId=" << to_string(edlChipId);
  out << ")";
}


KeyInfo::~KeyInfo() noexcept {
}


void KeyInfo::__set_keyClassification(const KeyClass::type val) {
  this->keyClassification = val;
__isset.keyClassification = true;
}

void KeyInfo::__set_status(const KeyLoadStatus::type val) {
  this->status = val;
__isset.status = true;
}
std::ostream& operator<<(std::ostream& out, const KeyInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t KeyInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast50;
          xfer += iprot->readI32(ecast50);
          this->keyClassification = (KeyClass::type)ecast50;
          this->__isset.keyClassification = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast51;
          xfer += iprot->readI32(ecast51);
          this->status = (KeyLoadStatus::type)ecast51;
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t KeyInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("KeyInfo");

  if (this->__isset.keyClassification) {
    xfer += oprot->writeFieldBegin("keyClassification", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->keyClassification);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.status) {
    xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->status);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(KeyInfo &a, KeyInfo &b) {
  using ::std::swap;
  swap(a.keyClassification, b.keyClassification);
  swap(a.status, b.status);
  swap(a.__isset, b.__isset);
}

KeyInfo::KeyInfo(const KeyInfo& other52) {
  keyClassification = other52.keyClassification;
  status = other52.status;
  __isset = other52.__isset;
}
KeyInfo& KeyInfo::operator=(const KeyInfo& other53) {
  keyClassification = other53.keyClassification;
  status = other53.status;
  __isset = other53.__isset;
  return *this;
}
void KeyInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "KeyInfo(";
  out << "keyClassification="; (__isset.keyClassification ? (out << to_string(keyClassification)) : (out << "<null>"));
  out << ", " << "status="; (__isset.status ? (out << to_string(status)) : (out << "<null>"));
  out << ")";
}


InputLogMask::~InputLogMask() noexcept {
}


void InputLogMask::__set_dataSourceType(const DataSourceType::type val) {
  this->dataSourceType = val;
__isset.dataSourceType = true;
}

void InputLogMask::__set_filename(const std::string& val) {
  this->filename = val;
__isset.filename = true;
}

void InputLogMask::__set_maskFileContent(const std::string& val) {
  this->maskFileContent = val;
__isset.maskFileContent = true;
}

void InputLogMask::__set_format(const LogMaskFormat::type val) {
  this->format = val;
}
std::ostream& operator<<(std::ostream& out, const InputLogMask& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t InputLogMask::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast54;
          xfer += iprot->readI32(ecast54);
          this->dataSourceType = (DataSourceType::type)ecast54;
          this->__isset.dataSourceType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->filename);
          this->__isset.filename = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->maskFileContent);
          this->__isset.maskFileContent = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast55;
          xfer += iprot->readI32(ecast55);
          this->format = (LogMaskFormat::type)ecast55;
          this->__isset.format = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t InputLogMask::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("InputLogMask");

  if (this->__isset.dataSourceType) {
    xfer += oprot->writeFieldBegin("dataSourceType", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->dataSourceType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.filename) {
    xfer += oprot->writeFieldBegin("filename", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->filename);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.maskFileContent) {
    xfer += oprot->writeFieldBegin("maskFileContent", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeBinary(this->maskFileContent);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("format", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32((int32_t)this->format);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(InputLogMask &a, InputLogMask &b) {
  using ::std::swap;
  swap(a.dataSourceType, b.dataSourceType);
  swap(a.filename, b.filename);
  swap(a.maskFileContent, b.maskFileContent);
  swap(a.format, b.format);
  swap(a.__isset, b.__isset);
}

InputLogMask::InputLogMask(const InputLogMask& other56) {
  dataSourceType = other56.dataSourceType;
  filename = other56.filename;
  maskFileContent = other56.maskFileContent;
  format = other56.format;
  __isset = other56.__isset;
}
InputLogMask& InputLogMask::operator=(const InputLogMask& other57) {
  dataSourceType = other57.dataSourceType;
  filename = other57.filename;
  maskFileContent = other57.maskFileContent;
  format = other57.format;
  __isset = other57.__isset;
  return *this;
}
void InputLogMask::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "InputLogMask(";
  out << "dataSourceType="; (__isset.dataSourceType ? (out << to_string(dataSourceType)) : (out << "<null>"));
  out << ", " << "filename="; (__isset.filename ? (out << to_string(filename)) : (out << "<null>"));
  out << ", " << "maskFileContent="; (__isset.maskFileContent ? (out << to_string(maskFileContent)) : (out << "<null>"));
  out << ", " << "format=" << to_string(format);
  out << ")";
}


DiagPacketFilter::~DiagPacketFilter() noexcept {
}


void DiagPacketFilter::__set_idOrNameMask(const std::map<DiagPacketType::type, std::vector<DiagIdFilterItem> > & val) {
  this->idOrNameMask = val;
__isset.idOrNameMask = true;
}

void DiagPacketFilter::__set_subscriptionId(const std::vector<int32_t> & val) {
  this->subscriptionId = val;
__isset.subscriptionId = true;
}

void DiagPacketFilter::__set_logMask(const InputLogMask& val) {
  this->logMask = val;
__isset.logMask = true;
}

void DiagPacketFilter::__set_formatStringFilter(const std::vector<std::string> & val) {
  this->formatStringFilter = val;
__isset.formatStringFilter = true;
}

void DiagPacketFilter::__set_enableMultiSim(const bool val) {
  this->enableMultiSim = val;
__isset.enableMultiSim = true;
}

void DiagPacketFilter::__set_miscellaneousId(const std::vector<int32_t> & val) {
  this->miscellaneousId = val;
__isset.miscellaneousId = true;
}

void DiagPacketFilter::__set_internalPacketEnum(const InternalPacketFlag::type val) {
  this->internalPacketEnum = val;
__isset.internalPacketEnum = true;
}

void DiagPacketFilter::__set_includeAllOtaLogPackets(const bool val) {
  this->includeAllOtaLogPackets = val;
__isset.includeAllOtaLogPackets = true;
}

void DiagPacketFilter::__set_f3FormatStringFilter(const std::map<int32_t, std::vector<std::string> > & val) {
  this->f3FormatStringFilter = val;
__isset.f3FormatStringFilter = true;
}

void DiagPacketFilter::__set_qtraceFormatStringFilter(const std::map<int32_t, std::vector<std::string> > & val) {
  this->qtraceFormatStringFilter = val;
__isset.qtraceFormatStringFilter = true;
}

void DiagPacketFilter::__set_prefixFormatStringFilter(const std::vector<std::string> & val) {
  this->prefixFormatStringFilter = val;
__isset.prefixFormatStringFilter = true;
}

void DiagPacketFilter::__set_excludeQEventsFromQTraceTypeFilter(const bool val) {
  this->excludeQEventsFromQTraceTypeFilter = val;
__isset.excludeQEventsFromQTraceTypeFilter = true;
}
std::ostream& operator<<(std::ostream& out, const DiagPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->idOrNameMask.clear();
            uint32_t _size58;
            ::apache::thrift::protocol::TType _ktype59;
            ::apache::thrift::protocol::TType _vtype60;
            xfer += iprot->readMapBegin(_ktype59, _vtype60, _size58);
            uint32_t _i62;
            for (_i62 = 0; _i62 < _size58; ++_i62)
            {
              DiagPacketType::type _key63;
              int32_t ecast65;
              xfer += iprot->readI32(ecast65);
              _key63 = (DiagPacketType::type)ecast65;
              std::vector<DiagIdFilterItem> & _val64 = this->idOrNameMask[_key63];
              {
                _val64.clear();
                uint32_t _size66;
                ::apache::thrift::protocol::TType _etype69;
                xfer += iprot->readListBegin(_etype69, _size66);
                _val64.resize(_size66);
                uint32_t _i70;
                for (_i70 = 0; _i70 < _size66; ++_i70)
                {
                  xfer += _val64[_i70].read(iprot);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.idOrNameMask = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->subscriptionId.clear();
            uint32_t _size71;
            ::apache::thrift::protocol::TType _etype74;
            xfer += iprot->readListBegin(_etype74, _size71);
            this->subscriptionId.resize(_size71);
            uint32_t _i75;
            for (_i75 = 0; _i75 < _size71; ++_i75)
            {
              xfer += iprot->readI32(this->subscriptionId[_i75]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->logMask.read(iprot);
          this->__isset.logMask = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->formatStringFilter.clear();
            uint32_t _size76;
            ::apache::thrift::protocol::TType _etype79;
            xfer += iprot->readListBegin(_etype79, _size76);
            this->formatStringFilter.resize(_size76);
            uint32_t _i80;
            for (_i80 = 0; _i80 < _size76; ++_i80)
            {
              xfer += iprot->readString(this->formatStringFilter[_i80]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.formatStringFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->enableMultiSim);
          this->__isset.enableMultiSim = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->miscellaneousId.clear();
            uint32_t _size81;
            ::apache::thrift::protocol::TType _etype84;
            xfer += iprot->readListBegin(_etype84, _size81);
            this->miscellaneousId.resize(_size81);
            uint32_t _i85;
            for (_i85 = 0; _i85 < _size81; ++_i85)
            {
              xfer += iprot->readI32(this->miscellaneousId[_i85]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.miscellaneousId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast86;
          xfer += iprot->readI32(ecast86);
          this->internalPacketEnum = (InternalPacketFlag::type)ecast86;
          this->__isset.internalPacketEnum = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->includeAllOtaLogPackets);
          this->__isset.includeAllOtaLogPackets = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->f3FormatStringFilter.clear();
            uint32_t _size87;
            ::apache::thrift::protocol::TType _ktype88;
            ::apache::thrift::protocol::TType _vtype89;
            xfer += iprot->readMapBegin(_ktype88, _vtype89, _size87);
            uint32_t _i91;
            for (_i91 = 0; _i91 < _size87; ++_i91)
            {
              int32_t _key92;
              xfer += iprot->readI32(_key92);
              std::vector<std::string> & _val93 = this->f3FormatStringFilter[_key92];
              {
                _val93.clear();
                uint32_t _size94;
                ::apache::thrift::protocol::TType _etype97;
                xfer += iprot->readListBegin(_etype97, _size94);
                _val93.resize(_size94);
                uint32_t _i98;
                for (_i98 = 0; _i98 < _size94; ++_i98)
                {
                  xfer += iprot->readString(_val93[_i98]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.f3FormatStringFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->qtraceFormatStringFilter.clear();
            uint32_t _size99;
            ::apache::thrift::protocol::TType _ktype100;
            ::apache::thrift::protocol::TType _vtype101;
            xfer += iprot->readMapBegin(_ktype100, _vtype101, _size99);
            uint32_t _i103;
            for (_i103 = 0; _i103 < _size99; ++_i103)
            {
              int32_t _key104;
              xfer += iprot->readI32(_key104);
              std::vector<std::string> & _val105 = this->qtraceFormatStringFilter[_key104];
              {
                _val105.clear();
                uint32_t _size106;
                ::apache::thrift::protocol::TType _etype109;
                xfer += iprot->readListBegin(_etype109, _size106);
                _val105.resize(_size106);
                uint32_t _i110;
                for (_i110 = 0; _i110 < _size106; ++_i110)
                {
                  xfer += iprot->readString(_val105[_i110]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.qtraceFormatStringFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->prefixFormatStringFilter.clear();
            uint32_t _size111;
            ::apache::thrift::protocol::TType _etype114;
            xfer += iprot->readListBegin(_etype114, _size111);
            this->prefixFormatStringFilter.resize(_size111);
            uint32_t _i115;
            for (_i115 = 0; _i115 < _size111; ++_i115)
            {
              xfer += iprot->readString(this->prefixFormatStringFilter[_i115]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.prefixFormatStringFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->excludeQEventsFromQTraceTypeFilter);
          this->__isset.excludeQEventsFromQTraceTypeFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DiagPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagPacketFilter");

  if (this->__isset.idOrNameMask) {
    xfer += oprot->writeFieldBegin("idOrNameMask", ::apache::thrift::protocol::T_MAP, 1);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->idOrNameMask.size()));
      std::map<DiagPacketType::type, std::vector<DiagIdFilterItem> > ::const_iterator _iter116;
      for (_iter116 = this->idOrNameMask.begin(); _iter116 != this->idOrNameMask.end(); ++_iter116)
      {
        xfer += oprot->writeI32((int32_t)_iter116->first);
        {
          xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(_iter116->second.size()));
          std::vector<DiagIdFilterItem> ::const_iterator _iter117;
          for (_iter117 = _iter116->second.begin(); _iter117 != _iter116->second.end(); ++_iter117)
          {
            xfer += (*_iter117).write(oprot);
          }
          xfer += oprot->writeListEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.subscriptionId) {
    xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->subscriptionId.size()));
      std::vector<int32_t> ::const_iterator _iter118;
      for (_iter118 = this->subscriptionId.begin(); _iter118 != this->subscriptionId.end(); ++_iter118)
      {
        xfer += oprot->writeI32((*_iter118));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.logMask) {
    xfer += oprot->writeFieldBegin("logMask", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->logMask.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.formatStringFilter) {
    xfer += oprot->writeFieldBegin("formatStringFilter", ::apache::thrift::protocol::T_LIST, 4);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->formatStringFilter.size()));
      std::vector<std::string> ::const_iterator _iter119;
      for (_iter119 = this->formatStringFilter.begin(); _iter119 != this->formatStringFilter.end(); ++_iter119)
      {
        xfer += oprot->writeString((*_iter119));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.enableMultiSim) {
    xfer += oprot->writeFieldBegin("enableMultiSim", ::apache::thrift::protocol::T_BOOL, 5);
    xfer += oprot->writeBool(this->enableMultiSim);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.miscellaneousId) {
    xfer += oprot->writeFieldBegin("miscellaneousId", ::apache::thrift::protocol::T_LIST, 6);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->miscellaneousId.size()));
      std::vector<int32_t> ::const_iterator _iter120;
      for (_iter120 = this->miscellaneousId.begin(); _iter120 != this->miscellaneousId.end(); ++_iter120)
      {
        xfer += oprot->writeI32((*_iter120));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.internalPacketEnum) {
    xfer += oprot->writeFieldBegin("internalPacketEnum", ::apache::thrift::protocol::T_I32, 7);
    xfer += oprot->writeI32((int32_t)this->internalPacketEnum);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.includeAllOtaLogPackets) {
    xfer += oprot->writeFieldBegin("includeAllOtaLogPackets", ::apache::thrift::protocol::T_BOOL, 8);
    xfer += oprot->writeBool(this->includeAllOtaLogPackets);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.f3FormatStringFilter) {
    xfer += oprot->writeFieldBegin("f3FormatStringFilter", ::apache::thrift::protocol::T_MAP, 9);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->f3FormatStringFilter.size()));
      std::map<int32_t, std::vector<std::string> > ::const_iterator _iter121;
      for (_iter121 = this->f3FormatStringFilter.begin(); _iter121 != this->f3FormatStringFilter.end(); ++_iter121)
      {
        xfer += oprot->writeI32(_iter121->first);
        {
          xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(_iter121->second.size()));
          std::vector<std::string> ::const_iterator _iter122;
          for (_iter122 = _iter121->second.begin(); _iter122 != _iter121->second.end(); ++_iter122)
          {
            xfer += oprot->writeString((*_iter122));
          }
          xfer += oprot->writeListEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qtraceFormatStringFilter) {
    xfer += oprot->writeFieldBegin("qtraceFormatStringFilter", ::apache::thrift::protocol::T_MAP, 10);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->qtraceFormatStringFilter.size()));
      std::map<int32_t, std::vector<std::string> > ::const_iterator _iter123;
      for (_iter123 = this->qtraceFormatStringFilter.begin(); _iter123 != this->qtraceFormatStringFilter.end(); ++_iter123)
      {
        xfer += oprot->writeI32(_iter123->first);
        {
          xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(_iter123->second.size()));
          std::vector<std::string> ::const_iterator _iter124;
          for (_iter124 = _iter123->second.begin(); _iter124 != _iter123->second.end(); ++_iter124)
          {
            xfer += oprot->writeString((*_iter124));
          }
          xfer += oprot->writeListEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.prefixFormatStringFilter) {
    xfer += oprot->writeFieldBegin("prefixFormatStringFilter", ::apache::thrift::protocol::T_LIST, 11);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->prefixFormatStringFilter.size()));
      std::vector<std::string> ::const_iterator _iter125;
      for (_iter125 = this->prefixFormatStringFilter.begin(); _iter125 != this->prefixFormatStringFilter.end(); ++_iter125)
      {
        xfer += oprot->writeString((*_iter125));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.excludeQEventsFromQTraceTypeFilter) {
    xfer += oprot->writeFieldBegin("excludeQEventsFromQTraceTypeFilter", ::apache::thrift::protocol::T_BOOL, 12);
    xfer += oprot->writeBool(this->excludeQEventsFromQTraceTypeFilter);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagPacketFilter &a, DiagPacketFilter &b) {
  using ::std::swap;
  swap(a.idOrNameMask, b.idOrNameMask);
  swap(a.subscriptionId, b.subscriptionId);
  swap(a.logMask, b.logMask);
  swap(a.formatStringFilter, b.formatStringFilter);
  swap(a.enableMultiSim, b.enableMultiSim);
  swap(a.miscellaneousId, b.miscellaneousId);
  swap(a.internalPacketEnum, b.internalPacketEnum);
  swap(a.includeAllOtaLogPackets, b.includeAllOtaLogPackets);
  swap(a.f3FormatStringFilter, b.f3FormatStringFilter);
  swap(a.qtraceFormatStringFilter, b.qtraceFormatStringFilter);
  swap(a.prefixFormatStringFilter, b.prefixFormatStringFilter);
  swap(a.excludeQEventsFromQTraceTypeFilter, b.excludeQEventsFromQTraceTypeFilter);
  swap(a.__isset, b.__isset);
}

DiagPacketFilter::DiagPacketFilter(const DiagPacketFilter& other126) {
  idOrNameMask = other126.idOrNameMask;
  subscriptionId = other126.subscriptionId;
  logMask = other126.logMask;
  formatStringFilter = other126.formatStringFilter;
  enableMultiSim = other126.enableMultiSim;
  miscellaneousId = other126.miscellaneousId;
  internalPacketEnum = other126.internalPacketEnum;
  includeAllOtaLogPackets = other126.includeAllOtaLogPackets;
  f3FormatStringFilter = other126.f3FormatStringFilter;
  qtraceFormatStringFilter = other126.qtraceFormatStringFilter;
  prefixFormatStringFilter = other126.prefixFormatStringFilter;
  excludeQEventsFromQTraceTypeFilter = other126.excludeQEventsFromQTraceTypeFilter;
  __isset = other126.__isset;
}
DiagPacketFilter& DiagPacketFilter::operator=(const DiagPacketFilter& other127) {
  idOrNameMask = other127.idOrNameMask;
  subscriptionId = other127.subscriptionId;
  logMask = other127.logMask;
  formatStringFilter = other127.formatStringFilter;
  enableMultiSim = other127.enableMultiSim;
  miscellaneousId = other127.miscellaneousId;
  internalPacketEnum = other127.internalPacketEnum;
  includeAllOtaLogPackets = other127.includeAllOtaLogPackets;
  f3FormatStringFilter = other127.f3FormatStringFilter;
  qtraceFormatStringFilter = other127.qtraceFormatStringFilter;
  prefixFormatStringFilter = other127.prefixFormatStringFilter;
  excludeQEventsFromQTraceTypeFilter = other127.excludeQEventsFromQTraceTypeFilter;
  __isset = other127.__isset;
  return *this;
}
void DiagPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagPacketFilter(";
  out << "idOrNameMask="; (__isset.idOrNameMask ? (out << to_string(idOrNameMask)) : (out << "<null>"));
  out << ", " << "subscriptionId="; (__isset.subscriptionId ? (out << to_string(subscriptionId)) : (out << "<null>"));
  out << ", " << "logMask="; (__isset.logMask ? (out << to_string(logMask)) : (out << "<null>"));
  out << ", " << "formatStringFilter="; (__isset.formatStringFilter ? (out << to_string(formatStringFilter)) : (out << "<null>"));
  out << ", " << "enableMultiSim="; (__isset.enableMultiSim ? (out << to_string(enableMultiSim)) : (out << "<null>"));
  out << ", " << "miscellaneousId="; (__isset.miscellaneousId ? (out << to_string(miscellaneousId)) : (out << "<null>"));
  out << ", " << "internalPacketEnum="; (__isset.internalPacketEnum ? (out << to_string(internalPacketEnum)) : (out << "<null>"));
  out << ", " << "includeAllOtaLogPackets="; (__isset.includeAllOtaLogPackets ? (out << to_string(includeAllOtaLogPackets)) : (out << "<null>"));
  out << ", " << "f3FormatStringFilter="; (__isset.f3FormatStringFilter ? (out << to_string(f3FormatStringFilter)) : (out << "<null>"));
  out << ", " << "qtraceFormatStringFilter="; (__isset.qtraceFormatStringFilter ? (out << to_string(qtraceFormatStringFilter)) : (out << "<null>"));
  out << ", " << "prefixFormatStringFilter="; (__isset.prefixFormatStringFilter ? (out << to_string(prefixFormatStringFilter)) : (out << "<null>"));
  out << ", " << "excludeQEventsFromQTraceTypeFilter="; (__isset.excludeQEventsFromQTraceTypeFilter ? (out << to_string(excludeQEventsFromQTraceTypeFilter)) : (out << "<null>"));
  out << ")";
}


DiagSearchSettings::~DiagSearchSettings() noexcept {
}


void DiagSearchSettings::__set_searchString(const std::string& val) {
  this->searchString = val;
__isset.searchString = true;
}

void DiagSearchSettings::__set_options(const SearchOptions::type val) {
  this->options = val;
__isset.options = true;
}

void DiagSearchSettings::__set_fields(const DiagReturnFlags::type val) {
  this->fields = val;
__isset.fields = true;
}

void DiagSearchSettings::__set_extfields(const DiagReturnFlagsExt::type val) {
  this->extfields = val;
__isset.extfields = true;
}
std::ostream& operator<<(std::ostream& out, const DiagSearchSettings& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagSearchSettings::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->searchString);
          this->__isset.searchString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast128;
          xfer += iprot->readI32(ecast128);
          this->options = (SearchOptions::type)ecast128;
          this->__isset.options = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast129;
          xfer += iprot->readI32(ecast129);
          this->fields = (DiagReturnFlags::type)ecast129;
          this->__isset.fields = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast130;
          xfer += iprot->readI32(ecast130);
          this->extfields = (DiagReturnFlagsExt::type)ecast130;
          this->__isset.extfields = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DiagSearchSettings::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagSearchSettings");

  if (this->__isset.searchString) {
    xfer += oprot->writeFieldBegin("searchString", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->searchString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.options) {
    xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->options);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.fields) {
    xfer += oprot->writeFieldBegin("fields", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32((int32_t)this->fields);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.extfields) {
    xfer += oprot->writeFieldBegin("extfields", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32((int32_t)this->extfields);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagSearchSettings &a, DiagSearchSettings &b) {
  using ::std::swap;
  swap(a.searchString, b.searchString);
  swap(a.options, b.options);
  swap(a.fields, b.fields);
  swap(a.extfields, b.extfields);
  swap(a.__isset, b.__isset);
}

DiagSearchSettings::DiagSearchSettings(const DiagSearchSettings& other131) {
  searchString = other131.searchString;
  options = other131.options;
  fields = other131.fields;
  extfields = other131.extfields;
  __isset = other131.__isset;
}
DiagSearchSettings& DiagSearchSettings::operator=(const DiagSearchSettings& other132) {
  searchString = other132.searchString;
  options = other132.options;
  fields = other132.fields;
  extfields = other132.extfields;
  __isset = other132.__isset;
  return *this;
}
void DiagSearchSettings::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagSearchSettings(";
  out << "searchString="; (__isset.searchString ? (out << to_string(searchString)) : (out << "<null>"));
  out << ", " << "options="; (__isset.options ? (out << to_string(options)) : (out << "<null>"));
  out << ", " << "fields="; (__isset.fields ? (out << to_string(fields)) : (out << "<null>"));
  out << ", " << "extfields="; (__isset.extfields ? (out << to_string(extfields)) : (out << "<null>"));
  out << ")";
}


DiagIdFilterItem::~DiagIdFilterItem() noexcept {
}


void DiagIdFilterItem::__set_idOrName(const std::string& val) {
  this->idOrName = val;
__isset.idOrName = true;
}

void DiagIdFilterItem::__set_regexFilter(const std::string& val) {
  this->regexFilter = val;
__isset.regexFilter = true;
}

void DiagIdFilterItem::__set_summaryRegexFilter(const std::string& val) {
  this->summaryRegexFilter = val;
__isset.summaryRegexFilter = true;
}

void DiagIdFilterItem::__set_caseInsensitive(const bool val) {
  this->caseInsensitive = val;
__isset.caseInsensitive = true;
}

void DiagIdFilterItem::__set_searchSettings(const DiagSearchSettings& val) {
  this->searchSettings = val;
__isset.searchSettings = true;
}
std::ostream& operator<<(std::ostream& out, const DiagIdFilterItem& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagIdFilterItem::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->idOrName);
          this->__isset.idOrName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->regexFilter);
          this->__isset.regexFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->summaryRegexFilter);
          this->__isset.summaryRegexFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->caseInsensitive);
          this->__isset.caseInsensitive = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->searchSettings.read(iprot);
          this->__isset.searchSettings = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DiagIdFilterItem::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagIdFilterItem");

  if (this->__isset.idOrName) {
    xfer += oprot->writeFieldBegin("idOrName", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->idOrName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.regexFilter) {
    xfer += oprot->writeFieldBegin("regexFilter", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->regexFilter);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.summaryRegexFilter) {
    xfer += oprot->writeFieldBegin("summaryRegexFilter", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->summaryRegexFilter);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.caseInsensitive) {
    xfer += oprot->writeFieldBegin("caseInsensitive", ::apache::thrift::protocol::T_BOOL, 4);
    xfer += oprot->writeBool(this->caseInsensitive);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.searchSettings) {
    xfer += oprot->writeFieldBegin("searchSettings", ::apache::thrift::protocol::T_STRUCT, 5);
    xfer += this->searchSettings.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagIdFilterItem &a, DiagIdFilterItem &b) {
  using ::std::swap;
  swap(a.idOrName, b.idOrName);
  swap(a.regexFilter, b.regexFilter);
  swap(a.summaryRegexFilter, b.summaryRegexFilter);
  swap(a.caseInsensitive, b.caseInsensitive);
  swap(a.searchSettings, b.searchSettings);
  swap(a.__isset, b.__isset);
}

DiagIdFilterItem::DiagIdFilterItem(const DiagIdFilterItem& other133) {
  idOrName = other133.idOrName;
  regexFilter = other133.regexFilter;
  summaryRegexFilter = other133.summaryRegexFilter;
  caseInsensitive = other133.caseInsensitive;
  searchSettings = other133.searchSettings;
  __isset = other133.__isset;
}
DiagIdFilterItem& DiagIdFilterItem::operator=(const DiagIdFilterItem& other134) {
  idOrName = other134.idOrName;
  regexFilter = other134.regexFilter;
  summaryRegexFilter = other134.summaryRegexFilter;
  caseInsensitive = other134.caseInsensitive;
  searchSettings = other134.searchSettings;
  __isset = other134.__isset;
  return *this;
}
void DiagIdFilterItem::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagIdFilterItem(";
  out << "idOrName="; (__isset.idOrName ? (out << to_string(idOrName)) : (out << "<null>"));
  out << ", " << "regexFilter="; (__isset.regexFilter ? (out << to_string(regexFilter)) : (out << "<null>"));
  out << ", " << "summaryRegexFilter="; (__isset.summaryRegexFilter ? (out << to_string(summaryRegexFilter)) : (out << "<null>"));
  out << ", " << "caseInsensitive="; (__isset.caseInsensitive ? (out << to_string(caseInsensitive)) : (out << "<null>"));
  out << ", " << "searchSettings="; (__isset.searchSettings ? (out << to_string(searchSettings)) : (out << "<null>"));
  out << ")";
}


DiagReturns::~DiagReturns() noexcept {
}


void DiagReturns::__set_flags(const DiagReturnFlags::type val) {
  this->flags = val;
__isset.flags = true;
}

void DiagReturns::__set_queries(const std::vector<std::string> & val) {
  this->queries = val;
__isset.queries = true;
}

void DiagReturns::__set_extFlags(const DiagReturnFlagsExt::type val) {
  this->extFlags = val;
__isset.extFlags = true;
}
std::ostream& operator<<(std::ostream& out, const DiagReturns& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagReturns::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast135;
          xfer += iprot->readI32(ecast135);
          this->flags = (DiagReturnFlags::type)ecast135;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->queries.clear();
            uint32_t _size136;
            ::apache::thrift::protocol::TType _etype139;
            xfer += iprot->readListBegin(_etype139, _size136);
            this->queries.resize(_size136);
            uint32_t _i140;
            for (_i140 = 0; _i140 < _size136; ++_i140)
            {
              xfer += iprot->readString(this->queries[_i140]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.queries = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast141;
          xfer += iprot->readI32(ecast141);
          this->extFlags = (DiagReturnFlagsExt::type)ecast141;
          this->__isset.extFlags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DiagReturns::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagReturns");

  if (this->__isset.flags) {
    xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->flags);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.queries) {
    xfer += oprot->writeFieldBegin("queries", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->queries.size()));
      std::vector<std::string> ::const_iterator _iter142;
      for (_iter142 = this->queries.begin(); _iter142 != this->queries.end(); ++_iter142)
      {
        xfer += oprot->writeString((*_iter142));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.extFlags) {
    xfer += oprot->writeFieldBegin("extFlags", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32((int32_t)this->extFlags);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagReturns &a, DiagReturns &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.queries, b.queries);
  swap(a.extFlags, b.extFlags);
  swap(a.__isset, b.__isset);
}

DiagReturns::DiagReturns(const DiagReturns& other143) {
  flags = other143.flags;
  queries = other143.queries;
  extFlags = other143.extFlags;
  __isset = other143.__isset;
}
DiagReturns& DiagReturns::operator=(const DiagReturns& other144) {
  flags = other144.flags;
  queries = other144.queries;
  extFlags = other144.extFlags;
  __isset = other144.__isset;
  return *this;
}
void DiagReturns::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagReturns(";
  out << "flags="; (__isset.flags ? (out << to_string(flags)) : (out << "<null>"));
  out << ", " << "queries="; (__isset.queries ? (out << to_string(queries)) : (out << "<null>"));
  out << ", " << "extFlags="; (__isset.extFlags ? (out << to_string(extFlags)) : (out << "<null>"));
  out << ")";
}


DiagReturnConfig::~DiagReturnConfig() noexcept {
}


void DiagReturnConfig::__set_flags(const DiagReturnFlags::type val) {
  this->flags = val;
}

void DiagReturnConfig::__set_fieldQueries(const std::map<DiagPacketType::type, std::map<std::string, DiagReturns> > & val) {
  this->fieldQueries = val;
__isset.fieldQueries = true;
}

void DiagReturnConfig::__set_diagTimeSorted(const bool val) {
  this->diagTimeSorted = val;
__isset.diagTimeSorted = true;
}

void DiagReturnConfig::__set_formatStringArguments(const std::map<std::string, std::set<int32_t> > & val) {
  this->formatStringArguments = val;
__isset.formatStringArguments = true;
}

void DiagReturnConfig::__set_extFlags(const DiagReturnFlagsExt::type val) {
  this->extFlags = val;
__isset.extFlags = true;
}

void DiagReturnConfig::__set_enumReturnRawValue(const bool val) {
  this->enumReturnRawValue = val;
__isset.enumReturnRawValue = true;
}

void DiagReturnConfig::__set_useFormatForFieldQuery(const bool val) {
  this->useFormatForFieldQuery = val;
__isset.useFormatForFieldQuery = true;
}
std::ostream& operator<<(std::ostream& out, const DiagReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast145;
          xfer += iprot->readI32(ecast145);
          this->flags = (DiagReturnFlags::type)ecast145;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->fieldQueries.clear();
            uint32_t _size146;
            ::apache::thrift::protocol::TType _ktype147;
            ::apache::thrift::protocol::TType _vtype148;
            xfer += iprot->readMapBegin(_ktype147, _vtype148, _size146);
            uint32_t _i150;
            for (_i150 = 0; _i150 < _size146; ++_i150)
            {
              DiagPacketType::type _key151;
              int32_t ecast153;
              xfer += iprot->readI32(ecast153);
              _key151 = (DiagPacketType::type)ecast153;
              std::map<std::string, DiagReturns> & _val152 = this->fieldQueries[_key151];
              {
                _val152.clear();
                uint32_t _size154;
                ::apache::thrift::protocol::TType _ktype155;
                ::apache::thrift::protocol::TType _vtype156;
                xfer += iprot->readMapBegin(_ktype155, _vtype156, _size154);
                uint32_t _i158;
                for (_i158 = 0; _i158 < _size154; ++_i158)
                {
                  std::string _key159;
                  xfer += iprot->readString(_key159);
                  DiagReturns& _val160 = _val152[_key159];
                  xfer += _val160.read(iprot);
                }
                xfer += iprot->readMapEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.fieldQueries = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->diagTimeSorted);
          this->__isset.diagTimeSorted = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->formatStringArguments.clear();
            uint32_t _size161;
            ::apache::thrift::protocol::TType _ktype162;
            ::apache::thrift::protocol::TType _vtype163;
            xfer += iprot->readMapBegin(_ktype162, _vtype163, _size161);
            uint32_t _i165;
            for (_i165 = 0; _i165 < _size161; ++_i165)
            {
              std::string _key166;
              xfer += iprot->readString(_key166);
              std::set<int32_t> & _val167 = this->formatStringArguments[_key166];
              {
                _val167.clear();
                uint32_t _size168;
                ::apache::thrift::protocol::TType _etype171;
                xfer += iprot->readSetBegin(_etype171, _size168);
                uint32_t _i172;
                for (_i172 = 0; _i172 < _size168; ++_i172)
                {
                  int32_t _elem173;
                  xfer += iprot->readI32(_elem173);
                  _val167.insert(_elem173);
                }
                xfer += iprot->readSetEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.formatStringArguments = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast174;
          xfer += iprot->readI32(ecast174);
          this->extFlags = (DiagReturnFlagsExt::type)ecast174;
          this->__isset.extFlags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->enumReturnRawValue);
          this->__isset.enumReturnRawValue = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->useFormatForFieldQuery);
          this->__isset.useFormatForFieldQuery = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DiagReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.fieldQueries) {
    xfer += oprot->writeFieldBegin("fieldQueries", ::apache::thrift::protocol::T_MAP, 2);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_MAP, static_cast<uint32_t>(this->fieldQueries.size()));
      std::map<DiagPacketType::type, std::map<std::string, DiagReturns> > ::const_iterator _iter175;
      for (_iter175 = this->fieldQueries.begin(); _iter175 != this->fieldQueries.end(); ++_iter175)
      {
        xfer += oprot->writeI32((int32_t)_iter175->first);
        {
          xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(_iter175->second.size()));
          std::map<std::string, DiagReturns> ::const_iterator _iter176;
          for (_iter176 = _iter175->second.begin(); _iter176 != _iter175->second.end(); ++_iter176)
          {
            xfer += oprot->writeString(_iter176->first);
            xfer += _iter176->second.write(oprot);
          }
          xfer += oprot->writeMapEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.diagTimeSorted) {
    xfer += oprot->writeFieldBegin("diagTimeSorted", ::apache::thrift::protocol::T_BOOL, 3);
    xfer += oprot->writeBool(this->diagTimeSorted);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.formatStringArguments) {
    xfer += oprot->writeFieldBegin("formatStringArguments", ::apache::thrift::protocol::T_MAP, 4);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_SET, static_cast<uint32_t>(this->formatStringArguments.size()));
      std::map<std::string, std::set<int32_t> > ::const_iterator _iter177;
      for (_iter177 = this->formatStringArguments.begin(); _iter177 != this->formatStringArguments.end(); ++_iter177)
      {
        xfer += oprot->writeString(_iter177->first);
        {
          xfer += oprot->writeSetBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(_iter177->second.size()));
          std::set<int32_t> ::const_iterator _iter178;
          for (_iter178 = _iter177->second.begin(); _iter178 != _iter177->second.end(); ++_iter178)
          {
            xfer += oprot->writeI32((*_iter178));
          }
          xfer += oprot->writeSetEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.extFlags) {
    xfer += oprot->writeFieldBegin("extFlags", ::apache::thrift::protocol::T_I32, 5);
    xfer += oprot->writeI32((int32_t)this->extFlags);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.enumReturnRawValue) {
    xfer += oprot->writeFieldBegin("enumReturnRawValue", ::apache::thrift::protocol::T_BOOL, 6);
    xfer += oprot->writeBool(this->enumReturnRawValue);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.useFormatForFieldQuery) {
    xfer += oprot->writeFieldBegin("useFormatForFieldQuery", ::apache::thrift::protocol::T_BOOL, 7);
    xfer += oprot->writeBool(this->useFormatForFieldQuery);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagReturnConfig &a, DiagReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.fieldQueries, b.fieldQueries);
  swap(a.diagTimeSorted, b.diagTimeSorted);
  swap(a.formatStringArguments, b.formatStringArguments);
  swap(a.extFlags, b.extFlags);
  swap(a.enumReturnRawValue, b.enumReturnRawValue);
  swap(a.useFormatForFieldQuery, b.useFormatForFieldQuery);
  swap(a.__isset, b.__isset);
}

DiagReturnConfig::DiagReturnConfig(const DiagReturnConfig& other179) {
  flags = other179.flags;
  fieldQueries = other179.fieldQueries;
  diagTimeSorted = other179.diagTimeSorted;
  formatStringArguments = other179.formatStringArguments;
  extFlags = other179.extFlags;
  enumReturnRawValue = other179.enumReturnRawValue;
  useFormatForFieldQuery = other179.useFormatForFieldQuery;
  __isset = other179.__isset;
}
DiagReturnConfig& DiagReturnConfig::operator=(const DiagReturnConfig& other180) {
  flags = other180.flags;
  fieldQueries = other180.fieldQueries;
  diagTimeSorted = other180.diagTimeSorted;
  formatStringArguments = other180.formatStringArguments;
  extFlags = other180.extFlags;
  enumReturnRawValue = other180.enumReturnRawValue;
  useFormatForFieldQuery = other180.useFormatForFieldQuery;
  __isset = other180.__isset;
  return *this;
}
void DiagReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ", " << "fieldQueries="; (__isset.fieldQueries ? (out << to_string(fieldQueries)) : (out << "<null>"));
  out << ", " << "diagTimeSorted="; (__isset.diagTimeSorted ? (out << to_string(diagTimeSorted)) : (out << "<null>"));
  out << ", " << "formatStringArguments="; (__isset.formatStringArguments ? (out << to_string(formatStringArguments)) : (out << "<null>"));
  out << ", " << "extFlags="; (__isset.extFlags ? (out << to_string(extFlags)) : (out << "<null>"));
  out << ", " << "enumReturnRawValue="; (__isset.enumReturnRawValue ? (out << to_string(enumReturnRawValue)) : (out << "<null>"));
  out << ", " << "useFormatForFieldQuery="; (__isset.useFormatForFieldQuery ? (out << to_string(useFormatForFieldQuery)) : (out << "<null>"));
  out << ")";
}


DiagPacket::~DiagPacket() noexcept {
}


void DiagPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void DiagPacket::__set_packetType(const DiagPacketType::type val) {
  this->packetType = val;
__isset.packetType = true;
}

void DiagPacket::__set_packetId(const std::string& val) {
  this->packetId = val;
__isset.packetId = true;
}

void DiagPacket::__set_moreResponsesFlag(const bool val) {
  this->moreResponsesFlag = val;
__isset.moreResponsesFlag = true;
}

void DiagPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void DiagPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void DiagPacket::__set_packetName(const std::string& val) {
  this->packetName = val;
__isset.packetName = true;
}

void DiagPacket::__set_timeStampData(const int64_t val) {
  this->timeStampData = val;
__isset.timeStampData = true;
}

void DiagPacket::__set_timeStampString(const std::string& val) {
  this->timeStampString = val;
__isset.timeStampString = true;
}

void DiagPacket::__set_binaryPayload(const std::string& val) {
  this->binaryPayload = val;
__isset.binaryPayload = true;
}

void DiagPacket::__set_parsedText(const std::string& val) {
  this->parsedText = val;
__isset.parsedText = true;
}

void DiagPacket::__set_subscriptionId(const int32_t val) {
  this->subscriptionId = val;
__isset.subscriptionId = true;
}

void DiagPacket::__set_processorId(const int16_t val) {
  this->processorId = val;
__isset.processorId = true;
}

void DiagPacket::__set_hwTimeStampData(const int64_t val) {
  this->hwTimeStampData = val;
__isset.hwTimeStampData = true;
}

void DiagPacket::__set_hwTimeStampString(const std::string& val) {
  this->hwTimeStampString = val;
__isset.hwTimeStampString = true;
}

void DiagPacket::__set_ulogSource(const std::string& val) {
  this->ulogSource = val;
__isset.ulogSource = true;
}

void DiagPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void DiagPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}

void DiagPacket::__set_queryResultJson(const std::string& val) {
  this->queryResultJson = val;
__isset.queryResultJson = true;
}

void DiagPacket::__set_summaryText(const std::string& val) {
  this->summaryText = val;
__isset.summaryText = true;
}

void DiagPacket::__set_transactionId(const int64_t val) {
  this->transactionId = val;
__isset.transactionId = true;
}

void DiagPacket::__set_qdssChannelId(const int16_t val) {
  this->qdssChannelId = val;
__isset.qdssChannelId = true;
}

void DiagPacket::__set_qdssMasterId(const int16_t val) {
  this->qdssMasterId = val;
__isset.qdssMasterId = true;
}

void DiagPacket::__set_qdssAtid(const int8_t val) {
  this->qdssAtid = val;
__isset.qdssAtid = true;
}

void DiagPacket::__set_defaultFormatText(const std::string& val) {
  this->defaultFormatText = val;
__isset.defaultFormatText = true;
}

void DiagPacket::__set_callFrameNumber(const int16_t val) {
  this->callFrameNumber = val;
__isset.callFrameNumber = true;
}

void DiagPacket::__set_timeStampTodAdjustedData(const int64_t val) {
  this->timeStampTodAdjustedData = val;
__isset.timeStampTodAdjustedData = true;
}

void DiagPacket::__set_timeStampTodAdjustedString(const std::string& val) {
  this->timeStampTodAdjustedString = val;
__isset.timeStampTodAdjustedString = true;
}

void DiagPacket::__set_formatStringArguments(const std::vector<std::string> & val) {
  this->formatStringArguments = val;
__isset.formatStringArguments = true;
}

void DiagPacket::__set_packetSize(const int16_t val) {
  this->packetSize = val;
__isset.packetSize = true;
}

void DiagPacket::__set_qtraceTags(const std::vector<std::string> & val) {
  this->qtraceTags = val;
__isset.qtraceTags = true;
}

void DiagPacket::__set_miscellaneousId(const int32_t val) {
  this->miscellaneousId = val;
__isset.miscellaneousId = true;
}

void DiagPacket::__set_queryResultPickled(const std::string& val) {
  this->queryResultPickled = val;
__isset.queryResultPickled = true;
}

void DiagPacket::__set_formatStringHash(const int64_t val) {
  this->formatStringHash = val;
__isset.formatStringHash = true;
}

void DiagPacket::__set_encryptionKeyInfo(const KeyInfo& val) {
  this->encryptionKeyInfo = val;
__isset.encryptionKeyInfo = true;
}

void DiagPacket::__set_exceptionMessageType(const ExceptionMessageType::type val) {
  this->exceptionMessageType = val;
__isset.exceptionMessageType = true;
}
std::ostream& operator<<(std::ostream& out, const DiagPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast181;
          xfer += iprot->readI32(ecast181);
          this->errorCode = (ErrorCode::type)ecast181;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast182;
          xfer += iprot->readI32(ecast182);
          this->packetType = (DiagPacketType::type)ecast182;
          this->__isset.packetType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetId);
          this->__isset.packetId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->moreResponsesFlag);
          this->__isset.moreResponsesFlag = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetName);
          this->__isset.packetName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timeStampData);
          this->__isset.timeStampData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->timeStampString);
          this->__isset.timeStampString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->binaryPayload);
          this->__isset.binaryPayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->parsedText);
          this->__isset.parsedText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->processorId);
          this->__isset.processorId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 14:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->hwTimeStampData);
          this->__isset.hwTimeStampData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 15:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->hwTimeStampString);
          this->__isset.hwTimeStampString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 16:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ulogSource);
          this->__isset.ulogSource = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 17:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 18:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 19:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->queryResultJson);
          this->__isset.queryResultJson = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 20:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->summaryText);
          this->__isset.summaryText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 21:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->transactionId);
          this->__isset.transactionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 22:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->qdssChannelId);
          this->__isset.qdssChannelId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 23:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->qdssMasterId);
          this->__isset.qdssMasterId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 24:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->qdssAtid);
          this->__isset.qdssAtid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 25:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->defaultFormatText);
          this->__isset.defaultFormatText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 26:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->callFrameNumber);
          this->__isset.callFrameNumber = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 27:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timeStampTodAdjustedData);
          this->__isset.timeStampTodAdjustedData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 28:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->timeStampTodAdjustedString);
          this->__isset.timeStampTodAdjustedString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 29:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->formatStringArguments.clear();
            uint32_t _size183;
            ::apache::thrift::protocol::TType _etype186;
            xfer += iprot->readListBegin(_etype186, _size183);
            this->formatStringArguments.resize(_size183);
            uint32_t _i187;
            for (_i187 = 0; _i187 < _size183; ++_i187)
            {
              xfer += iprot->readString(this->formatStringArguments[_i187]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.formatStringArguments = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 30:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->packetSize);
          this->__isset.packetSize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 31:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->qtraceTags.clear();
            uint32_t _size188;
            ::apache::thrift::protocol::TType _etype191;
            xfer += iprot->readListBegin(_etype191, _size188);
            this->qtraceTags.resize(_size188);
            uint32_t _i192;
            for (_i192 = 0; _i192 < _size188; ++_i192)
            {
              xfer += iprot->readString(this->qtraceTags[_i192]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.qtraceTags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 32:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->miscellaneousId);
          this->__isset.miscellaneousId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 33:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->queryResultPickled);
          this->__isset.queryResultPickled = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 34:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->formatStringHash);
          this->__isset.formatStringHash = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 35:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->encryptionKeyInfo.read(iprot);
          this->__isset.encryptionKeyInfo = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 36:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast193;
          xfer += iprot->readI32(ecast193);
          this->exceptionMessageType = (ExceptionMessageType::type)ecast193;
          this->__isset.exceptionMessageType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DiagPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetType) {
    xfer += oprot->writeFieldBegin("packetType", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->packetType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetId) {
    xfer += oprot->writeFieldBegin("packetId", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->packetId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.moreResponsesFlag) {
    xfer += oprot->writeFieldBegin("moreResponsesFlag", ::apache::thrift::protocol::T_BOOL, 4);
    xfer += oprot->writeBool(this->moreResponsesFlag);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 6);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetName) {
    xfer += oprot->writeFieldBegin("packetName", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->packetName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.timeStampData) {
    xfer += oprot->writeFieldBegin("timeStampData", ::apache::thrift::protocol::T_I64, 8);
    xfer += oprot->writeI64(this->timeStampData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.timeStampString) {
    xfer += oprot->writeFieldBegin("timeStampString", ::apache::thrift::protocol::T_STRING, 9);
    xfer += oprot->writeString(this->timeStampString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.binaryPayload) {
    xfer += oprot->writeFieldBegin("binaryPayload", ::apache::thrift::protocol::T_STRING, 10);
    xfer += oprot->writeBinary(this->binaryPayload);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.parsedText) {
    xfer += oprot->writeFieldBegin("parsedText", ::apache::thrift::protocol::T_STRING, 11);
    xfer += oprot->writeString(this->parsedText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.subscriptionId) {
    xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 12);
    xfer += oprot->writeI32(this->subscriptionId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.processorId) {
    xfer += oprot->writeFieldBegin("processorId", ::apache::thrift::protocol::T_I16, 13);
    xfer += oprot->writeI16(this->processorId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.hwTimeStampData) {
    xfer += oprot->writeFieldBegin("hwTimeStampData", ::apache::thrift::protocol::T_I64, 14);
    xfer += oprot->writeI64(this->hwTimeStampData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.hwTimeStampString) {
    xfer += oprot->writeFieldBegin("hwTimeStampString", ::apache::thrift::protocol::T_STRING, 15);
    xfer += oprot->writeString(this->hwTimeStampString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.ulogSource) {
    xfer += oprot->writeFieldBegin("ulogSource", ::apache::thrift::protocol::T_STRING, 16);
    xfer += oprot->writeString(this->ulogSource);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 17);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 18);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.queryResultJson) {
    xfer += oprot->writeFieldBegin("queryResultJson", ::apache::thrift::protocol::T_STRING, 19);
    xfer += oprot->writeString(this->queryResultJson);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.summaryText) {
    xfer += oprot->writeFieldBegin("summaryText", ::apache::thrift::protocol::T_STRING, 20);
    xfer += oprot->writeString(this->summaryText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.transactionId) {
    xfer += oprot->writeFieldBegin("transactionId", ::apache::thrift::protocol::T_I64, 21);
    xfer += oprot->writeI64(this->transactionId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qdssChannelId) {
    xfer += oprot->writeFieldBegin("qdssChannelId", ::apache::thrift::protocol::T_I16, 22);
    xfer += oprot->writeI16(this->qdssChannelId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qdssMasterId) {
    xfer += oprot->writeFieldBegin("qdssMasterId", ::apache::thrift::protocol::T_I16, 23);
    xfer += oprot->writeI16(this->qdssMasterId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qdssAtid) {
    xfer += oprot->writeFieldBegin("qdssAtid", ::apache::thrift::protocol::T_BYTE, 24);
    xfer += oprot->writeByte(this->qdssAtid);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.defaultFormatText) {
    xfer += oprot->writeFieldBegin("defaultFormatText", ::apache::thrift::protocol::T_STRING, 25);
    xfer += oprot->writeString(this->defaultFormatText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.callFrameNumber) {
    xfer += oprot->writeFieldBegin("callFrameNumber", ::apache::thrift::protocol::T_I16, 26);
    xfer += oprot->writeI16(this->callFrameNumber);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.timeStampTodAdjustedData) {
    xfer += oprot->writeFieldBegin("timeStampTodAdjustedData", ::apache::thrift::protocol::T_I64, 27);
    xfer += oprot->writeI64(this->timeStampTodAdjustedData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.timeStampTodAdjustedString) {
    xfer += oprot->writeFieldBegin("timeStampTodAdjustedString", ::apache::thrift::protocol::T_STRING, 28);
    xfer += oprot->writeString(this->timeStampTodAdjustedString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.formatStringArguments) {
    xfer += oprot->writeFieldBegin("formatStringArguments", ::apache::thrift::protocol::T_LIST, 29);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->formatStringArguments.size()));
      std::vector<std::string> ::const_iterator _iter194;
      for (_iter194 = this->formatStringArguments.begin(); _iter194 != this->formatStringArguments.end(); ++_iter194)
      {
        xfer += oprot->writeString((*_iter194));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetSize) {
    xfer += oprot->writeFieldBegin("packetSize", ::apache::thrift::protocol::T_I16, 30);
    xfer += oprot->writeI16(this->packetSize);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qtraceTags) {
    xfer += oprot->writeFieldBegin("qtraceTags", ::apache::thrift::protocol::T_LIST, 31);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->qtraceTags.size()));
      std::vector<std::string> ::const_iterator _iter195;
      for (_iter195 = this->qtraceTags.begin(); _iter195 != this->qtraceTags.end(); ++_iter195)
      {
        xfer += oprot->writeString((*_iter195));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.miscellaneousId) {
    xfer += oprot->writeFieldBegin("miscellaneousId", ::apache::thrift::protocol::T_I32, 32);
    xfer += oprot->writeI32(this->miscellaneousId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.queryResultPickled) {
    xfer += oprot->writeFieldBegin("queryResultPickled", ::apache::thrift::protocol::T_STRING, 33);
    xfer += oprot->writeBinary(this->queryResultPickled);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.formatStringHash) {
    xfer += oprot->writeFieldBegin("formatStringHash", ::apache::thrift::protocol::T_I64, 34);
    xfer += oprot->writeI64(this->formatStringHash);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.encryptionKeyInfo) {
    xfer += oprot->writeFieldBegin("encryptionKeyInfo", ::apache::thrift::protocol::T_STRUCT, 35);
    xfer += this->encryptionKeyInfo.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.exceptionMessageType) {
    xfer += oprot->writeFieldBegin("exceptionMessageType", ::apache::thrift::protocol::T_I32, 36);
    xfer += oprot->writeI32((int32_t)this->exceptionMessageType);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagPacket &a, DiagPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.packetType, b.packetType);
  swap(a.packetId, b.packetId);
  swap(a.moreResponsesFlag, b.moreResponsesFlag);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.packetName, b.packetName);
  swap(a.timeStampData, b.timeStampData);
  swap(a.timeStampString, b.timeStampString);
  swap(a.binaryPayload, b.binaryPayload);
  swap(a.parsedText, b.parsedText);
  swap(a.subscriptionId, b.subscriptionId);
  swap(a.processorId, b.processorId);
  swap(a.hwTimeStampData, b.hwTimeStampData);
  swap(a.hwTimeStampString, b.hwTimeStampString);
  swap(a.ulogSource, b.ulogSource);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.queryResultJson, b.queryResultJson);
  swap(a.summaryText, b.summaryText);
  swap(a.transactionId, b.transactionId);
  swap(a.qdssChannelId, b.qdssChannelId);
  swap(a.qdssMasterId, b.qdssMasterId);
  swap(a.qdssAtid, b.qdssAtid);
  swap(a.defaultFormatText, b.defaultFormatText);
  swap(a.callFrameNumber, b.callFrameNumber);
  swap(a.timeStampTodAdjustedData, b.timeStampTodAdjustedData);
  swap(a.timeStampTodAdjustedString, b.timeStampTodAdjustedString);
  swap(a.formatStringArguments, b.formatStringArguments);
  swap(a.packetSize, b.packetSize);
  swap(a.qtraceTags, b.qtraceTags);
  swap(a.miscellaneousId, b.miscellaneousId);
  swap(a.queryResultPickled, b.queryResultPickled);
  swap(a.formatStringHash, b.formatStringHash);
  swap(a.encryptionKeyInfo, b.encryptionKeyInfo);
  swap(a.exceptionMessageType, b.exceptionMessageType);
  swap(a.__isset, b.__isset);
}

DiagPacket::DiagPacket(const DiagPacket& other196) {
  errorCode = other196.errorCode;
  packetType = other196.packetType;
  packetId = other196.packetId;
  moreResponsesFlag = other196.moreResponsesFlag;
  sessionIndex = other196.sessionIndex;
  protocolIndex = other196.protocolIndex;
  packetName = other196.packetName;
  timeStampData = other196.timeStampData;
  timeStampString = other196.timeStampString;
  binaryPayload = other196.binaryPayload;
  parsedText = other196.parsedText;
  subscriptionId = other196.subscriptionId;
  processorId = other196.processorId;
  hwTimeStampData = other196.hwTimeStampData;
  hwTimeStampString = other196.hwTimeStampString;
  ulogSource = other196.ulogSource;
  receiveTimeData = other196.receiveTimeData;
  receiveTimeString = other196.receiveTimeString;
  queryResultJson = other196.queryResultJson;
  summaryText = other196.summaryText;
  transactionId = other196.transactionId;
  qdssChannelId = other196.qdssChannelId;
  qdssMasterId = other196.qdssMasterId;
  qdssAtid = other196.qdssAtid;
  defaultFormatText = other196.defaultFormatText;
  callFrameNumber = other196.callFrameNumber;
  timeStampTodAdjustedData = other196.timeStampTodAdjustedData;
  timeStampTodAdjustedString = other196.timeStampTodAdjustedString;
  formatStringArguments = other196.formatStringArguments;
  packetSize = other196.packetSize;
  qtraceTags = other196.qtraceTags;
  miscellaneousId = other196.miscellaneousId;
  queryResultPickled = other196.queryResultPickled;
  formatStringHash = other196.formatStringHash;
  encryptionKeyInfo = other196.encryptionKeyInfo;
  exceptionMessageType = other196.exceptionMessageType;
  __isset = other196.__isset;
}
DiagPacket& DiagPacket::operator=(const DiagPacket& other197) {
  errorCode = other197.errorCode;
  packetType = other197.packetType;
  packetId = other197.packetId;
  moreResponsesFlag = other197.moreResponsesFlag;
  sessionIndex = other197.sessionIndex;
  protocolIndex = other197.protocolIndex;
  packetName = other197.packetName;
  timeStampData = other197.timeStampData;
  timeStampString = other197.timeStampString;
  binaryPayload = other197.binaryPayload;
  parsedText = other197.parsedText;
  subscriptionId = other197.subscriptionId;
  processorId = other197.processorId;
  hwTimeStampData = other197.hwTimeStampData;
  hwTimeStampString = other197.hwTimeStampString;
  ulogSource = other197.ulogSource;
  receiveTimeData = other197.receiveTimeData;
  receiveTimeString = other197.receiveTimeString;
  queryResultJson = other197.queryResultJson;
  summaryText = other197.summaryText;
  transactionId = other197.transactionId;
  qdssChannelId = other197.qdssChannelId;
  qdssMasterId = other197.qdssMasterId;
  qdssAtid = other197.qdssAtid;
  defaultFormatText = other197.defaultFormatText;
  callFrameNumber = other197.callFrameNumber;
  timeStampTodAdjustedData = other197.timeStampTodAdjustedData;
  timeStampTodAdjustedString = other197.timeStampTodAdjustedString;
  formatStringArguments = other197.formatStringArguments;
  packetSize = other197.packetSize;
  qtraceTags = other197.qtraceTags;
  miscellaneousId = other197.miscellaneousId;
  queryResultPickled = other197.queryResultPickled;
  formatStringHash = other197.formatStringHash;
  encryptionKeyInfo = other197.encryptionKeyInfo;
  exceptionMessageType = other197.exceptionMessageType;
  __isset = other197.__isset;
  return *this;
}
void DiagPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "packetType="; (__isset.packetType ? (out << to_string(packetType)) : (out << "<null>"));
  out << ", " << "packetId="; (__isset.packetId ? (out << to_string(packetId)) : (out << "<null>"));
  out << ", " << "moreResponsesFlag="; (__isset.moreResponsesFlag ? (out << to_string(moreResponsesFlag)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "packetName="; (__isset.packetName ? (out << to_string(packetName)) : (out << "<null>"));
  out << ", " << "timeStampData="; (__isset.timeStampData ? (out << to_string(timeStampData)) : (out << "<null>"));
  out << ", " << "timeStampString="; (__isset.timeStampString ? (out << to_string(timeStampString)) : (out << "<null>"));
  out << ", " << "binaryPayload="; (__isset.binaryPayload ? (out << to_string(binaryPayload)) : (out << "<null>"));
  out << ", " << "parsedText="; (__isset.parsedText ? (out << to_string(parsedText)) : (out << "<null>"));
  out << ", " << "subscriptionId="; (__isset.subscriptionId ? (out << to_string(subscriptionId)) : (out << "<null>"));
  out << ", " << "processorId="; (__isset.processorId ? (out << to_string(processorId)) : (out << "<null>"));
  out << ", " << "hwTimeStampData="; (__isset.hwTimeStampData ? (out << to_string(hwTimeStampData)) : (out << "<null>"));
  out << ", " << "hwTimeStampString="; (__isset.hwTimeStampString ? (out << to_string(hwTimeStampString)) : (out << "<null>"));
  out << ", " << "ulogSource="; (__isset.ulogSource ? (out << to_string(ulogSource)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ", " << "queryResultJson="; (__isset.queryResultJson ? (out << to_string(queryResultJson)) : (out << "<null>"));
  out << ", " << "summaryText="; (__isset.summaryText ? (out << to_string(summaryText)) : (out << "<null>"));
  out << ", " << "transactionId="; (__isset.transactionId ? (out << to_string(transactionId)) : (out << "<null>"));
  out << ", " << "qdssChannelId="; (__isset.qdssChannelId ? (out << to_string(qdssChannelId)) : (out << "<null>"));
  out << ", " << "qdssMasterId="; (__isset.qdssMasterId ? (out << to_string(qdssMasterId)) : (out << "<null>"));
  out << ", " << "qdssAtid="; (__isset.qdssAtid ? (out << to_string(qdssAtid)) : (out << "<null>"));
  out << ", " << "defaultFormatText="; (__isset.defaultFormatText ? (out << to_string(defaultFormatText)) : (out << "<null>"));
  out << ", " << "callFrameNumber="; (__isset.callFrameNumber ? (out << to_string(callFrameNumber)) : (out << "<null>"));
  out << ", " << "timeStampTodAdjustedData="; (__isset.timeStampTodAdjustedData ? (out << to_string(timeStampTodAdjustedData)) : (out << "<null>"));
  out << ", " << "timeStampTodAdjustedString="; (__isset.timeStampTodAdjustedString ? (out << to_string(timeStampTodAdjustedString)) : (out << "<null>"));
  out << ", " << "formatStringArguments="; (__isset.formatStringArguments ? (out << to_string(formatStringArguments)) : (out << "<null>"));
  out << ", " << "packetSize="; (__isset.packetSize ? (out << to_string(packetSize)) : (out << "<null>"));
  out << ", " << "qtraceTags="; (__isset.qtraceTags ? (out << to_string(qtraceTags)) : (out << "<null>"));
  out << ", " << "miscellaneousId="; (__isset.miscellaneousId ? (out << to_string(miscellaneousId)) : (out << "<null>"));
  out << ", " << "queryResultPickled="; (__isset.queryResultPickled ? (out << to_string(queryResultPickled)) : (out << "<null>"));
  out << ", " << "formatStringHash="; (__isset.formatStringHash ? (out << to_string(formatStringHash)) : (out << "<null>"));
  out << ", " << "encryptionKeyInfo="; (__isset.encryptionKeyInfo ? (out << to_string(encryptionKeyInfo)) : (out << "<null>"));
  out << ", " << "exceptionMessageType="; (__isset.exceptionMessageType ? (out << to_string(exceptionMessageType)) : (out << "<null>"));
  out << ")";
}


AnnotationSearchSettings::~AnnotationSearchSettings() noexcept {
}


void AnnotationSearchSettings::__set_searchString(const std::string& val) {
  this->searchString = val;
__isset.searchString = true;
}

void AnnotationSearchSettings::__set_options(const SearchOptions::type val) {
  this->options = val;
__isset.options = true;
}

void AnnotationSearchSettings::__set_fields(const AnnotationReturnFlags::type val) {
  this->fields = val;
__isset.fields = true;
}
std::ostream& operator<<(std::ostream& out, const AnnotationSearchSettings& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t AnnotationSearchSettings::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->searchString);
          this->__isset.searchString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast198;
          xfer += iprot->readI32(ecast198);
          this->options = (SearchOptions::type)ecast198;
          this->__isset.options = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast199;
          xfer += iprot->readI32(ecast199);
          this->fields = (AnnotationReturnFlags::type)ecast199;
          this->__isset.fields = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AnnotationSearchSettings::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AnnotationSearchSettings");

  if (this->__isset.searchString) {
    xfer += oprot->writeFieldBegin("searchString", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->searchString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.options) {
    xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->options);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.fields) {
    xfer += oprot->writeFieldBegin("fields", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32((int32_t)this->fields);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AnnotationSearchSettings &a, AnnotationSearchSettings &b) {
  using ::std::swap;
  swap(a.searchString, b.searchString);
  swap(a.options, b.options);
  swap(a.fields, b.fields);
  swap(a.__isset, b.__isset);
}

AnnotationSearchSettings::AnnotationSearchSettings(const AnnotationSearchSettings& other200) {
  searchString = other200.searchString;
  options = other200.options;
  fields = other200.fields;
  __isset = other200.__isset;
}
AnnotationSearchSettings& AnnotationSearchSettings::operator=(const AnnotationSearchSettings& other201) {
  searchString = other201.searchString;
  options = other201.options;
  fields = other201.fields;
  __isset = other201.__isset;
  return *this;
}
void AnnotationSearchSettings::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AnnotationSearchSettings(";
  out << "searchString="; (__isset.searchString ? (out << to_string(searchString)) : (out << "<null>"));
  out << ", " << "options="; (__isset.options ? (out << to_string(options)) : (out << "<null>"));
  out << ", " << "fields="; (__isset.fields ? (out << to_string(fields)) : (out << "<null>"));
  out << ")";
}


AnnotationFilterItem::~AnnotationFilterItem() noexcept {
}


void AnnotationFilterItem::__set_messageId(const int64_t val) {
  this->messageId = val;
__isset.messageId = true;
}

void AnnotationFilterItem::__set_searchSettings(const AnnotationSearchSettings& val) {
  this->searchSettings = val;
__isset.searchSettings = true;
}
std::ostream& operator<<(std::ostream& out, const AnnotationFilterItem& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t AnnotationFilterItem::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->messageId);
          this->__isset.messageId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->searchSettings.read(iprot);
          this->__isset.searchSettings = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AnnotationFilterItem::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AnnotationFilterItem");

  if (this->__isset.messageId) {
    xfer += oprot->writeFieldBegin("messageId", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->messageId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.searchSettings) {
    xfer += oprot->writeFieldBegin("searchSettings", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->searchSettings.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AnnotationFilterItem &a, AnnotationFilterItem &b) {
  using ::std::swap;
  swap(a.messageId, b.messageId);
  swap(a.searchSettings, b.searchSettings);
  swap(a.__isset, b.__isset);
}

AnnotationFilterItem::AnnotationFilterItem(const AnnotationFilterItem& other202) {
  messageId = other202.messageId;
  searchSettings = other202.searchSettings;
  __isset = other202.__isset;
}
AnnotationFilterItem& AnnotationFilterItem::operator=(const AnnotationFilterItem& other203) {
  messageId = other203.messageId;
  searchSettings = other203.searchSettings;
  __isset = other203.__isset;
  return *this;
}
void AnnotationFilterItem::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AnnotationFilterItem(";
  out << "messageId="; (__isset.messageId ? (out << to_string(messageId)) : (out << "<null>"));
  out << ", " << "searchSettings="; (__isset.searchSettings ? (out << to_string(searchSettings)) : (out << "<null>"));
  out << ")";
}


AnnotationPacketFilter::~AnnotationPacketFilter() noexcept {
}


void AnnotationPacketFilter::__set_includeAnnotations(const bool val) {
  this->includeAnnotations = val;
__isset.includeAnnotations = true;
}

void AnnotationPacketFilter::__set_messageIdFilter(const std::vector<int64_t> & val) {
  this->messageIdFilter = val;
__isset.messageIdFilter = true;
}

void AnnotationPacketFilter::__set_filter(const std::vector<AnnotationFilterItem> & val) {
  this->filter = val;
__isset.filter = true;
}
std::ostream& operator<<(std::ostream& out, const AnnotationPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t AnnotationPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->includeAnnotations);
          this->__isset.includeAnnotations = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->messageIdFilter.clear();
            uint32_t _size204;
            ::apache::thrift::protocol::TType _etype207;
            xfer += iprot->readListBegin(_etype207, _size204);
            this->messageIdFilter.resize(_size204);
            uint32_t _i208;
            for (_i208 = 0; _i208 < _size204; ++_i208)
            {
              xfer += iprot->readI64(this->messageIdFilter[_i208]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.messageIdFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->filter.clear();
            uint32_t _size209;
            ::apache::thrift::protocol::TType _etype212;
            xfer += iprot->readListBegin(_etype212, _size209);
            this->filter.resize(_size209);
            uint32_t _i213;
            for (_i213 = 0; _i213 < _size209; ++_i213)
            {
              xfer += this->filter[_i213].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.filter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AnnotationPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AnnotationPacketFilter");

  if (this->__isset.includeAnnotations) {
    xfer += oprot->writeFieldBegin("includeAnnotations", ::apache::thrift::protocol::T_BOOL, 1);
    xfer += oprot->writeBool(this->includeAnnotations);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.messageIdFilter) {
    xfer += oprot->writeFieldBegin("messageIdFilter", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->messageIdFilter.size()));
      std::vector<int64_t> ::const_iterator _iter214;
      for (_iter214 = this->messageIdFilter.begin(); _iter214 != this->messageIdFilter.end(); ++_iter214)
      {
        xfer += oprot->writeI64((*_iter214));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.filter) {
    xfer += oprot->writeFieldBegin("filter", ::apache::thrift::protocol::T_LIST, 3);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->filter.size()));
      std::vector<AnnotationFilterItem> ::const_iterator _iter215;
      for (_iter215 = this->filter.begin(); _iter215 != this->filter.end(); ++_iter215)
      {
        xfer += (*_iter215).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AnnotationPacketFilter &a, AnnotationPacketFilter &b) {
  using ::std::swap;
  swap(a.includeAnnotations, b.includeAnnotations);
  swap(a.messageIdFilter, b.messageIdFilter);
  swap(a.filter, b.filter);
  swap(a.__isset, b.__isset);
}

AnnotationPacketFilter::AnnotationPacketFilter(const AnnotationPacketFilter& other216) {
  includeAnnotations = other216.includeAnnotations;
  messageIdFilter = other216.messageIdFilter;
  filter = other216.filter;
  __isset = other216.__isset;
}
AnnotationPacketFilter& AnnotationPacketFilter::operator=(const AnnotationPacketFilter& other217) {
  includeAnnotations = other217.includeAnnotations;
  messageIdFilter = other217.messageIdFilter;
  filter = other217.filter;
  __isset = other217.__isset;
  return *this;
}
void AnnotationPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AnnotationPacketFilter(";
  out << "includeAnnotations="; (__isset.includeAnnotations ? (out << to_string(includeAnnotations)) : (out << "<null>"));
  out << ", " << "messageIdFilter="; (__isset.messageIdFilter ? (out << to_string(messageIdFilter)) : (out << "<null>"));
  out << ", " << "filter="; (__isset.filter ? (out << to_string(filter)) : (out << "<null>"));
  out << ")";
}


AnnotationPacket::~AnnotationPacket() noexcept {
}


void AnnotationPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void AnnotationPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void AnnotationPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void AnnotationPacket::__set_parsedText(const std::string& val) {
  this->parsedText = val;
__isset.parsedText = true;
}

void AnnotationPacket::__set_messageId(const int64_t val) {
  this->messageId = val;
__isset.messageId = true;
}

void AnnotationPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void AnnotationPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}
std::ostream& operator<<(std::ostream& out, const AnnotationPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t AnnotationPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast218;
          xfer += iprot->readI32(ecast218);
          this->errorCode = (ErrorCode::type)ecast218;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->parsedText);
          this->__isset.parsedText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->messageId);
          this->__isset.messageId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AnnotationPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AnnotationPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.parsedText) {
    xfer += oprot->writeFieldBegin("parsedText", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->parsedText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.messageId) {
    xfer += oprot->writeFieldBegin("messageId", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->messageId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 6);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AnnotationPacket &a, AnnotationPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.parsedText, b.parsedText);
  swap(a.messageId, b.messageId);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.__isset, b.__isset);
}

AnnotationPacket::AnnotationPacket(const AnnotationPacket& other219) {
  errorCode = other219.errorCode;
  sessionIndex = other219.sessionIndex;
  protocolIndex = other219.protocolIndex;
  parsedText = other219.parsedText;
  messageId = other219.messageId;
  receiveTimeData = other219.receiveTimeData;
  receiveTimeString = other219.receiveTimeString;
  __isset = other219.__isset;
}
AnnotationPacket& AnnotationPacket::operator=(const AnnotationPacket& other220) {
  errorCode = other220.errorCode;
  sessionIndex = other220.sessionIndex;
  protocolIndex = other220.protocolIndex;
  parsedText = other220.parsedText;
  messageId = other220.messageId;
  receiveTimeData = other220.receiveTimeData;
  receiveTimeString = other220.receiveTimeString;
  __isset = other220.__isset;
  return *this;
}
void AnnotationPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AnnotationPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "parsedText="; (__isset.parsedText ? (out << to_string(parsedText)) : (out << "<null>"));
  out << ", " << "messageId="; (__isset.messageId ? (out << to_string(messageId)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ")";
}


QmiPacketFilter::~QmiPacketFilter() noexcept {
}


void QmiPacketFilter::__set_idOrNameMask(const std::map<QmiPacketType::type, std::vector<std::string> > & val) {
  this->idOrNameMask = val;
__isset.idOrNameMask = true;
}
std::ostream& operator<<(std::ostream& out, const QmiPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmiPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->idOrNameMask.clear();
            uint32_t _size221;
            ::apache::thrift::protocol::TType _ktype222;
            ::apache::thrift::protocol::TType _vtype223;
            xfer += iprot->readMapBegin(_ktype222, _vtype223, _size221);
            uint32_t _i225;
            for (_i225 = 0; _i225 < _size221; ++_i225)
            {
              QmiPacketType::type _key226;
              int32_t ecast228;
              xfer += iprot->readI32(ecast228);
              _key226 = (QmiPacketType::type)ecast228;
              std::vector<std::string> & _val227 = this->idOrNameMask[_key226];
              {
                _val227.clear();
                uint32_t _size229;
                ::apache::thrift::protocol::TType _etype232;
                xfer += iprot->readListBegin(_etype232, _size229);
                _val227.resize(_size229);
                uint32_t _i233;
                for (_i233 = 0; _i233 < _size229; ++_i233)
                {
                  xfer += iprot->readString(_val227[_i233]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.idOrNameMask = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmiPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmiPacketFilter");

  if (this->__isset.idOrNameMask) {
    xfer += oprot->writeFieldBegin("idOrNameMask", ::apache::thrift::protocol::T_MAP, 1);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->idOrNameMask.size()));
      std::map<QmiPacketType::type, std::vector<std::string> > ::const_iterator _iter234;
      for (_iter234 = this->idOrNameMask.begin(); _iter234 != this->idOrNameMask.end(); ++_iter234)
      {
        xfer += oprot->writeI32((int32_t)_iter234->first);
        {
          xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(_iter234->second.size()));
          std::vector<std::string> ::const_iterator _iter235;
          for (_iter235 = _iter234->second.begin(); _iter235 != _iter234->second.end(); ++_iter235)
          {
            xfer += oprot->writeString((*_iter235));
          }
          xfer += oprot->writeListEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmiPacketFilter &a, QmiPacketFilter &b) {
  using ::std::swap;
  swap(a.idOrNameMask, b.idOrNameMask);
  swap(a.__isset, b.__isset);
}

QmiPacketFilter::QmiPacketFilter(const QmiPacketFilter& other236) {
  idOrNameMask = other236.idOrNameMask;
  __isset = other236.__isset;
}
QmiPacketFilter& QmiPacketFilter::operator=(const QmiPacketFilter& other237) {
  idOrNameMask = other237.idOrNameMask;
  __isset = other237.__isset;
  return *this;
}
void QmiPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmiPacketFilter(";
  out << "idOrNameMask="; (__isset.idOrNameMask ? (out << to_string(idOrNameMask)) : (out << "<null>"));
  out << ")";
}


QmiReturns::~QmiReturns() noexcept {
}


void QmiReturns::__set_flags(const QmiReturnFlags::type val) {
  this->flags = val;
__isset.flags = true;
}

void QmiReturns::__set_queries(const std::vector<std::string> & val) {
  this->queries = val;
__isset.queries = true;
}
std::ostream& operator<<(std::ostream& out, const QmiReturns& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmiReturns::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast238;
          xfer += iprot->readI32(ecast238);
          this->flags = (QmiReturnFlags::type)ecast238;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->queries.clear();
            uint32_t _size239;
            ::apache::thrift::protocol::TType _etype242;
            xfer += iprot->readListBegin(_etype242, _size239);
            this->queries.resize(_size239);
            uint32_t _i243;
            for (_i243 = 0; _i243 < _size239; ++_i243)
            {
              xfer += iprot->readString(this->queries[_i243]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.queries = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmiReturns::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmiReturns");

  if (this->__isset.flags) {
    xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->flags);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.queries) {
    xfer += oprot->writeFieldBegin("queries", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->queries.size()));
      std::vector<std::string> ::const_iterator _iter244;
      for (_iter244 = this->queries.begin(); _iter244 != this->queries.end(); ++_iter244)
      {
        xfer += oprot->writeString((*_iter244));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmiReturns &a, QmiReturns &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.queries, b.queries);
  swap(a.__isset, b.__isset);
}

QmiReturns::QmiReturns(const QmiReturns& other245) {
  flags = other245.flags;
  queries = other245.queries;
  __isset = other245.__isset;
}
QmiReturns& QmiReturns::operator=(const QmiReturns& other246) {
  flags = other246.flags;
  queries = other246.queries;
  __isset = other246.__isset;
  return *this;
}
void QmiReturns::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmiReturns(";
  out << "flags="; (__isset.flags ? (out << to_string(flags)) : (out << "<null>"));
  out << ", " << "queries="; (__isset.queries ? (out << to_string(queries)) : (out << "<null>"));
  out << ")";
}


QmiReturnConfig::~QmiReturnConfig() noexcept {
}


void QmiReturnConfig::__set_flags(const QmiReturnFlags::type val) {
  this->flags = val;
}

void QmiReturnConfig::__set_fieldQueries(const std::map<QmiPacketType::type, std::map<std::string, QmiReturns> > & val) {
  this->fieldQueries = val;
__isset.fieldQueries = true;
}
std::ostream& operator<<(std::ostream& out, const QmiReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmiReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast247;
          xfer += iprot->readI32(ecast247);
          this->flags = (QmiReturnFlags::type)ecast247;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->fieldQueries.clear();
            uint32_t _size248;
            ::apache::thrift::protocol::TType _ktype249;
            ::apache::thrift::protocol::TType _vtype250;
            xfer += iprot->readMapBegin(_ktype249, _vtype250, _size248);
            uint32_t _i252;
            for (_i252 = 0; _i252 < _size248; ++_i252)
            {
              QmiPacketType::type _key253;
              int32_t ecast255;
              xfer += iprot->readI32(ecast255);
              _key253 = (QmiPacketType::type)ecast255;
              std::map<std::string, QmiReturns> & _val254 = this->fieldQueries[_key253];
              {
                _val254.clear();
                uint32_t _size256;
                ::apache::thrift::protocol::TType _ktype257;
                ::apache::thrift::protocol::TType _vtype258;
                xfer += iprot->readMapBegin(_ktype257, _vtype258, _size256);
                uint32_t _i260;
                for (_i260 = 0; _i260 < _size256; ++_i260)
                {
                  std::string _key261;
                  xfer += iprot->readString(_key261);
                  QmiReturns& _val262 = _val254[_key261];
                  xfer += _val262.read(iprot);
                }
                xfer += iprot->readMapEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.fieldQueries = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmiReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmiReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.fieldQueries) {
    xfer += oprot->writeFieldBegin("fieldQueries", ::apache::thrift::protocol::T_MAP, 2);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_MAP, static_cast<uint32_t>(this->fieldQueries.size()));
      std::map<QmiPacketType::type, std::map<std::string, QmiReturns> > ::const_iterator _iter263;
      for (_iter263 = this->fieldQueries.begin(); _iter263 != this->fieldQueries.end(); ++_iter263)
      {
        xfer += oprot->writeI32((int32_t)_iter263->first);
        {
          xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(_iter263->second.size()));
          std::map<std::string, QmiReturns> ::const_iterator _iter264;
          for (_iter264 = _iter263->second.begin(); _iter264 != _iter263->second.end(); ++_iter264)
          {
            xfer += oprot->writeString(_iter264->first);
            xfer += _iter264->second.write(oprot);
          }
          xfer += oprot->writeMapEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmiReturnConfig &a, QmiReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.fieldQueries, b.fieldQueries);
  swap(a.__isset, b.__isset);
}

QmiReturnConfig::QmiReturnConfig(const QmiReturnConfig& other265) {
  flags = other265.flags;
  fieldQueries = other265.fieldQueries;
  __isset = other265.__isset;
}
QmiReturnConfig& QmiReturnConfig::operator=(const QmiReturnConfig& other266) {
  flags = other266.flags;
  fieldQueries = other266.fieldQueries;
  __isset = other266.__isset;
  return *this;
}
void QmiReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmiReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ", " << "fieldQueries="; (__isset.fieldQueries ? (out << to_string(fieldQueries)) : (out << "<null>"));
  out << ")";
}


QmiPacket::~QmiPacket() noexcept {
}


void QmiPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void QmiPacket::__set_packetType(const QmiPacketType::type val) {
  this->packetType = val;
__isset.packetType = true;
}

void QmiPacket::__set_serviceId(const int32_t val) {
  this->serviceId = val;
__isset.serviceId = true;
}

void QmiPacket::__set_messageId(const int16_t val) {
  this->messageId = val;
__isset.messageId = true;
}

void QmiPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void QmiPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void QmiPacket::__set_packetName(const std::string& val) {
  this->packetName = val;
__isset.packetName = true;
}

void QmiPacket::__set_binaryPayload(const std::string& val) {
  this->binaryPayload = val;
__isset.binaryPayload = true;
}

void QmiPacket::__set_parsedXml(const std::string& val) {
  this->parsedXml = val;
__isset.parsedXml = true;
}

void QmiPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void QmiPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}

void QmiPacket::__set_queryResultJson(const std::string& val) {
  this->queryResultJson = val;
__isset.queryResultJson = true;
}

void QmiPacket::__set_transactionId(const int64_t val) {
  this->transactionId = val;
__isset.transactionId = true;
}
std::ostream& operator<<(std::ostream& out, const QmiPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmiPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast267;
          xfer += iprot->readI32(ecast267);
          this->errorCode = (ErrorCode::type)ecast267;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast268;
          xfer += iprot->readI32(ecast268);
          this->packetType = (QmiPacketType::type)ecast268;
          this->__isset.packetType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->serviceId);
          this->__isset.serviceId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->messageId);
          this->__isset.messageId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetName);
          this->__isset.packetName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->binaryPayload);
          this->__isset.binaryPayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->parsedXml);
          this->__isset.parsedXml = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->queryResultJson);
          this->__isset.queryResultJson = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->transactionId);
          this->__isset.transactionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmiPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmiPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetType) {
    xfer += oprot->writeFieldBegin("packetType", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->packetType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.serviceId) {
    xfer += oprot->writeFieldBegin("serviceId", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->serviceId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.messageId) {
    xfer += oprot->writeFieldBegin("messageId", ::apache::thrift::protocol::T_I16, 4);
    xfer += oprot->writeI16(this->messageId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 6);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetName) {
    xfer += oprot->writeFieldBegin("packetName", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->packetName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.binaryPayload) {
    xfer += oprot->writeFieldBegin("binaryPayload", ::apache::thrift::protocol::T_STRING, 8);
    xfer += oprot->writeBinary(this->binaryPayload);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.parsedXml) {
    xfer += oprot->writeFieldBegin("parsedXml", ::apache::thrift::protocol::T_STRING, 9);
    xfer += oprot->writeString(this->parsedXml);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 10);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 11);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.queryResultJson) {
    xfer += oprot->writeFieldBegin("queryResultJson", ::apache::thrift::protocol::T_STRING, 12);
    xfer += oprot->writeString(this->queryResultJson);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.transactionId) {
    xfer += oprot->writeFieldBegin("transactionId", ::apache::thrift::protocol::T_I64, 13);
    xfer += oprot->writeI64(this->transactionId);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmiPacket &a, QmiPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.packetType, b.packetType);
  swap(a.serviceId, b.serviceId);
  swap(a.messageId, b.messageId);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.packetName, b.packetName);
  swap(a.binaryPayload, b.binaryPayload);
  swap(a.parsedXml, b.parsedXml);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.queryResultJson, b.queryResultJson);
  swap(a.transactionId, b.transactionId);
  swap(a.__isset, b.__isset);
}

QmiPacket::QmiPacket(const QmiPacket& other269) {
  errorCode = other269.errorCode;
  packetType = other269.packetType;
  serviceId = other269.serviceId;
  messageId = other269.messageId;
  sessionIndex = other269.sessionIndex;
  protocolIndex = other269.protocolIndex;
  packetName = other269.packetName;
  binaryPayload = other269.binaryPayload;
  parsedXml = other269.parsedXml;
  receiveTimeData = other269.receiveTimeData;
  receiveTimeString = other269.receiveTimeString;
  queryResultJson = other269.queryResultJson;
  transactionId = other269.transactionId;
  __isset = other269.__isset;
}
QmiPacket& QmiPacket::operator=(const QmiPacket& other270) {
  errorCode = other270.errorCode;
  packetType = other270.packetType;
  serviceId = other270.serviceId;
  messageId = other270.messageId;
  sessionIndex = other270.sessionIndex;
  protocolIndex = other270.protocolIndex;
  packetName = other270.packetName;
  binaryPayload = other270.binaryPayload;
  parsedXml = other270.parsedXml;
  receiveTimeData = other270.receiveTimeData;
  receiveTimeString = other270.receiveTimeString;
  queryResultJson = other270.queryResultJson;
  transactionId = other270.transactionId;
  __isset = other270.__isset;
  return *this;
}
void QmiPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmiPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "packetType="; (__isset.packetType ? (out << to_string(packetType)) : (out << "<null>"));
  out << ", " << "serviceId="; (__isset.serviceId ? (out << to_string(serviceId)) : (out << "<null>"));
  out << ", " << "messageId="; (__isset.messageId ? (out << to_string(messageId)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "packetName="; (__isset.packetName ? (out << to_string(packetName)) : (out << "<null>"));
  out << ", " << "binaryPayload="; (__isset.binaryPayload ? (out << to_string(binaryPayload)) : (out << "<null>"));
  out << ", " << "parsedXml="; (__isset.parsedXml ? (out << to_string(parsedXml)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ", " << "queryResultJson="; (__isset.queryResultJson ? (out << to_string(queryResultJson)) : (out << "<null>"));
  out << ", " << "transactionId="; (__isset.transactionId ? (out << to_string(transactionId)) : (out << "<null>"));
  out << ")";
}


AdbPacketFilter::~AdbPacketFilter() noexcept {
}


void AdbPacketFilter::__set_regexFilter(const std::string& val) {
  this->regexFilter = val;
__isset.regexFilter = true;
}
std::ostream& operator<<(std::ostream& out, const AdbPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t AdbPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->regexFilter);
          this->__isset.regexFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AdbPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AdbPacketFilter");

  if (this->__isset.regexFilter) {
    xfer += oprot->writeFieldBegin("regexFilter", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->regexFilter);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AdbPacketFilter &a, AdbPacketFilter &b) {
  using ::std::swap;
  swap(a.regexFilter, b.regexFilter);
  swap(a.__isset, b.__isset);
}

AdbPacketFilter::AdbPacketFilter(const AdbPacketFilter& other271) {
  regexFilter = other271.regexFilter;
  __isset = other271.__isset;
}
AdbPacketFilter& AdbPacketFilter::operator=(const AdbPacketFilter& other272) {
  regexFilter = other272.regexFilter;
  __isset = other272.__isset;
  return *this;
}
void AdbPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AdbPacketFilter(";
  out << "regexFilter="; (__isset.regexFilter ? (out << to_string(regexFilter)) : (out << "<null>"));
  out << ")";
}


AdbReturnConfig::~AdbReturnConfig() noexcept {
}


void AdbReturnConfig::__set_flags(const AdbReturnFlags::type val) {
  this->flags = val;
}
std::ostream& operator<<(std::ostream& out, const AdbReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t AdbReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast273;
          xfer += iprot->readI32(ecast273);
          this->flags = (AdbReturnFlags::type)ecast273;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AdbReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AdbReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AdbReturnConfig &a, AdbReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.__isset, b.__isset);
}

AdbReturnConfig::AdbReturnConfig(const AdbReturnConfig& other274) {
  flags = other274.flags;
  __isset = other274.__isset;
}
AdbReturnConfig& AdbReturnConfig::operator=(const AdbReturnConfig& other275) {
  flags = other275.flags;
  __isset = other275.__isset;
  return *this;
}
void AdbReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AdbReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ")";
}


AdbPacket::~AdbPacket() noexcept {
}


void AdbPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void AdbPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void AdbPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void AdbPacket::__set_packetText(const std::string& val) {
  this->packetText = val;
__isset.packetText = true;
}

void AdbPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void AdbPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}
std::ostream& operator<<(std::ostream& out, const AdbPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t AdbPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast276;
          xfer += iprot->readI32(ecast276);
          this->errorCode = (ErrorCode::type)ecast276;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetText);
          this->__isset.packetText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AdbPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AdbPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetText) {
    xfer += oprot->writeFieldBegin("packetText", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->packetText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AdbPacket &a, AdbPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.packetText, b.packetText);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.__isset, b.__isset);
}

AdbPacket::AdbPacket(const AdbPacket& other277) {
  errorCode = other277.errorCode;
  sessionIndex = other277.sessionIndex;
  protocolIndex = other277.protocolIndex;
  packetText = other277.packetText;
  receiveTimeData = other277.receiveTimeData;
  receiveTimeString = other277.receiveTimeString;
  __isset = other277.__isset;
}
AdbPacket& AdbPacket::operator=(const AdbPacket& other278) {
  errorCode = other278.errorCode;
  sessionIndex = other278.sessionIndex;
  protocolIndex = other278.protocolIndex;
  packetText = other278.packetText;
  receiveTimeData = other278.receiveTimeData;
  receiveTimeString = other278.receiveTimeString;
  __isset = other278.__isset;
  return *this;
}
void AdbPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AdbPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "packetText="; (__isset.packetText ? (out << to_string(packetText)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ")";
}


TelnetPacketFilter::~TelnetPacketFilter() noexcept {
}


void TelnetPacketFilter::__set_regexFilter(const std::string& val) {
  this->regexFilter = val;
__isset.regexFilter = true;
}
std::ostream& operator<<(std::ostream& out, const TelnetPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TelnetPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->regexFilter);
          this->__isset.regexFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TelnetPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TelnetPacketFilter");

  if (this->__isset.regexFilter) {
    xfer += oprot->writeFieldBegin("regexFilter", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->regexFilter);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TelnetPacketFilter &a, TelnetPacketFilter &b) {
  using ::std::swap;
  swap(a.regexFilter, b.regexFilter);
  swap(a.__isset, b.__isset);
}

TelnetPacketFilter::TelnetPacketFilter(const TelnetPacketFilter& other279) {
  regexFilter = other279.regexFilter;
  __isset = other279.__isset;
}
TelnetPacketFilter& TelnetPacketFilter::operator=(const TelnetPacketFilter& other280) {
  regexFilter = other280.regexFilter;
  __isset = other280.__isset;
  return *this;
}
void TelnetPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TelnetPacketFilter(";
  out << "regexFilter="; (__isset.regexFilter ? (out << to_string(regexFilter)) : (out << "<null>"));
  out << ")";
}


TelnetReturnConfig::~TelnetReturnConfig() noexcept {
}


void TelnetReturnConfig::__set_flags(const TelnetReturnFlags::type val) {
  this->flags = val;
}
std::ostream& operator<<(std::ostream& out, const TelnetReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TelnetReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast281;
          xfer += iprot->readI32(ecast281);
          this->flags = (TelnetReturnFlags::type)ecast281;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TelnetReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TelnetReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TelnetReturnConfig &a, TelnetReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.__isset, b.__isset);
}

TelnetReturnConfig::TelnetReturnConfig(const TelnetReturnConfig& other282) {
  flags = other282.flags;
  __isset = other282.__isset;
}
TelnetReturnConfig& TelnetReturnConfig::operator=(const TelnetReturnConfig& other283) {
  flags = other283.flags;
  __isset = other283.__isset;
  return *this;
}
void TelnetReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TelnetReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ")";
}


TelnetPacket::~TelnetPacket() noexcept {
}


void TelnetPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void TelnetPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void TelnetPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void TelnetPacket::__set_packetText(const std::string& val) {
  this->packetText = val;
__isset.packetText = true;
}

void TelnetPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void TelnetPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}
std::ostream& operator<<(std::ostream& out, const TelnetPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TelnetPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast284;
          xfer += iprot->readI32(ecast284);
          this->errorCode = (ErrorCode::type)ecast284;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetText);
          this->__isset.packetText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TelnetPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TelnetPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetText) {
    xfer += oprot->writeFieldBegin("packetText", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->packetText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TelnetPacket &a, TelnetPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.packetText, b.packetText);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.__isset, b.__isset);
}

TelnetPacket::TelnetPacket(const TelnetPacket& other285) {
  errorCode = other285.errorCode;
  sessionIndex = other285.sessionIndex;
  protocolIndex = other285.protocolIndex;
  packetText = other285.packetText;
  receiveTimeData = other285.receiveTimeData;
  receiveTimeString = other285.receiveTimeString;
  __isset = other285.__isset;
}
TelnetPacket& TelnetPacket::operator=(const TelnetPacket& other286) {
  errorCode = other286.errorCode;
  sessionIndex = other286.sessionIndex;
  protocolIndex = other286.protocolIndex;
  packetText = other286.packetText;
  receiveTimeData = other286.receiveTimeData;
  receiveTimeString = other286.receiveTimeString;
  __isset = other286.__isset;
  return *this;
}
void TelnetPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TelnetPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "packetText="; (__isset.packetText ? (out << to_string(packetText)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ")";
}


SaharaPacketFilter::~SaharaPacketFilter() noexcept {
}


void SaharaPacketFilter::__set_idOrNameMask(const std::vector<std::string> & val) {
  this->idOrNameMask = val;
__isset.idOrNameMask = true;
}
std::ostream& operator<<(std::ostream& out, const SaharaPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t SaharaPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->idOrNameMask.clear();
            uint32_t _size287;
            ::apache::thrift::protocol::TType _etype290;
            xfer += iprot->readListBegin(_etype290, _size287);
            this->idOrNameMask.resize(_size287);
            uint32_t _i291;
            for (_i291 = 0; _i291 < _size287; ++_i291)
            {
              xfer += iprot->readString(this->idOrNameMask[_i291]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.idOrNameMask = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SaharaPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SaharaPacketFilter");

  if (this->__isset.idOrNameMask) {
    xfer += oprot->writeFieldBegin("idOrNameMask", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->idOrNameMask.size()));
      std::vector<std::string> ::const_iterator _iter292;
      for (_iter292 = this->idOrNameMask.begin(); _iter292 != this->idOrNameMask.end(); ++_iter292)
      {
        xfer += oprot->writeString((*_iter292));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SaharaPacketFilter &a, SaharaPacketFilter &b) {
  using ::std::swap;
  swap(a.idOrNameMask, b.idOrNameMask);
  swap(a.__isset, b.__isset);
}

SaharaPacketFilter::SaharaPacketFilter(const SaharaPacketFilter& other293) {
  idOrNameMask = other293.idOrNameMask;
  __isset = other293.__isset;
}
SaharaPacketFilter& SaharaPacketFilter::operator=(const SaharaPacketFilter& other294) {
  idOrNameMask = other294.idOrNameMask;
  __isset = other294.__isset;
  return *this;
}
void SaharaPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SaharaPacketFilter(";
  out << "idOrNameMask="; (__isset.idOrNameMask ? (out << to_string(idOrNameMask)) : (out << "<null>"));
  out << ")";
}


SaharaReturnConfig::~SaharaReturnConfig() noexcept {
}


void SaharaReturnConfig::__set_flags(const SaharaReturnFlags::type val) {
  this->flags = val;
}
std::ostream& operator<<(std::ostream& out, const SaharaReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t SaharaReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast295;
          xfer += iprot->readI32(ecast295);
          this->flags = (SaharaReturnFlags::type)ecast295;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SaharaReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SaharaReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SaharaReturnConfig &a, SaharaReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.__isset, b.__isset);
}

SaharaReturnConfig::SaharaReturnConfig(const SaharaReturnConfig& other296) {
  flags = other296.flags;
  __isset = other296.__isset;
}
SaharaReturnConfig& SaharaReturnConfig::operator=(const SaharaReturnConfig& other297) {
  flags = other297.flags;
  __isset = other297.__isset;
  return *this;
}
void SaharaReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SaharaReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ")";
}


SaharaPacket::~SaharaPacket() noexcept {
}


void SaharaPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void SaharaPacket::__set_packetId(const int32_t val) {
  this->packetId = val;
__isset.packetId = true;
}

void SaharaPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void SaharaPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void SaharaPacket::__set_packetName(const std::string& val) {
  this->packetName = val;
__isset.packetName = true;
}

void SaharaPacket::__set_binaryPayload(const std::string& val) {
  this->binaryPayload = val;
__isset.binaryPayload = true;
}

void SaharaPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void SaharaPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}
std::ostream& operator<<(std::ostream& out, const SaharaPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t SaharaPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast298;
          xfer += iprot->readI32(ecast298);
          this->errorCode = (ErrorCode::type)ecast298;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->packetId);
          this->__isset.packetId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetName);
          this->__isset.packetName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->binaryPayload);
          this->__isset.binaryPayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SaharaPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SaharaPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetId) {
    xfer += oprot->writeFieldBegin("packetId", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->packetId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 4);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetName) {
    xfer += oprot->writeFieldBegin("packetName", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->packetName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.binaryPayload) {
    xfer += oprot->writeFieldBegin("binaryPayload", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeBinary(this->binaryPayload);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 7);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 8);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SaharaPacket &a, SaharaPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.packetId, b.packetId);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.packetName, b.packetName);
  swap(a.binaryPayload, b.binaryPayload);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.__isset, b.__isset);
}

SaharaPacket::SaharaPacket(const SaharaPacket& other299) {
  errorCode = other299.errorCode;
  packetId = other299.packetId;
  sessionIndex = other299.sessionIndex;
  protocolIndex = other299.protocolIndex;
  packetName = other299.packetName;
  binaryPayload = other299.binaryPayload;
  receiveTimeData = other299.receiveTimeData;
  receiveTimeString = other299.receiveTimeString;
  __isset = other299.__isset;
}
SaharaPacket& SaharaPacket::operator=(const SaharaPacket& other300) {
  errorCode = other300.errorCode;
  packetId = other300.packetId;
  sessionIndex = other300.sessionIndex;
  protocolIndex = other300.protocolIndex;
  packetName = other300.packetName;
  binaryPayload = other300.binaryPayload;
  receiveTimeData = other300.receiveTimeData;
  receiveTimeString = other300.receiveTimeString;
  __isset = other300.__isset;
  return *this;
}
void SaharaPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SaharaPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "packetId="; (__isset.packetId ? (out << to_string(packetId)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "packetName="; (__isset.packetName ? (out << to_string(packetName)) : (out << "<null>"));
  out << ", " << "binaryPayload="; (__isset.binaryPayload ? (out << to_string(binaryPayload)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ")";
}


FastbootPacketFilter::~FastbootPacketFilter() noexcept {
}


void FastbootPacketFilter::__set_regexFilter(const std::string& val) {
  this->regexFilter = val;
__isset.regexFilter = true;
}
std::ostream& operator<<(std::ostream& out, const FastbootPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t FastbootPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->regexFilter);
          this->__isset.regexFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t FastbootPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FastbootPacketFilter");

  if (this->__isset.regexFilter) {
    xfer += oprot->writeFieldBegin("regexFilter", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->regexFilter);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FastbootPacketFilter &a, FastbootPacketFilter &b) {
  using ::std::swap;
  swap(a.regexFilter, b.regexFilter);
  swap(a.__isset, b.__isset);
}

FastbootPacketFilter::FastbootPacketFilter(const FastbootPacketFilter& other301) {
  regexFilter = other301.regexFilter;
  __isset = other301.__isset;
}
FastbootPacketFilter& FastbootPacketFilter::operator=(const FastbootPacketFilter& other302) {
  regexFilter = other302.regexFilter;
  __isset = other302.__isset;
  return *this;
}
void FastbootPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FastbootPacketFilter(";
  out << "regexFilter="; (__isset.regexFilter ? (out << to_string(regexFilter)) : (out << "<null>"));
  out << ")";
}


FastbootReturnConfig::~FastbootReturnConfig() noexcept {
}


void FastbootReturnConfig::__set_flags(const FastbootReturnFlags::type val) {
  this->flags = val;
}
std::ostream& operator<<(std::ostream& out, const FastbootReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t FastbootReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast303;
          xfer += iprot->readI32(ecast303);
          this->flags = (FastbootReturnFlags::type)ecast303;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t FastbootReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FastbootReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FastbootReturnConfig &a, FastbootReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.__isset, b.__isset);
}

FastbootReturnConfig::FastbootReturnConfig(const FastbootReturnConfig& other304) {
  flags = other304.flags;
  __isset = other304.__isset;
}
FastbootReturnConfig& FastbootReturnConfig::operator=(const FastbootReturnConfig& other305) {
  flags = other305.flags;
  __isset = other305.__isset;
  return *this;
}
void FastbootReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FastbootReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ")";
}


FastbootPacket::~FastbootPacket() noexcept {
}


void FastbootPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void FastbootPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void FastbootPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void FastbootPacket::__set_packetText(const std::string& val) {
  this->packetText = val;
__isset.packetText = true;
}

void FastbootPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void FastbootPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}
std::ostream& operator<<(std::ostream& out, const FastbootPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t FastbootPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast306;
          xfer += iprot->readI32(ecast306);
          this->errorCode = (ErrorCode::type)ecast306;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetText);
          this->__isset.packetText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t FastbootPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FastbootPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetText) {
    xfer += oprot->writeFieldBegin("packetText", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->packetText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FastbootPacket &a, FastbootPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.packetText, b.packetText);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.__isset, b.__isset);
}

FastbootPacket::FastbootPacket(const FastbootPacket& other307) {
  errorCode = other307.errorCode;
  sessionIndex = other307.sessionIndex;
  protocolIndex = other307.protocolIndex;
  packetText = other307.packetText;
  receiveTimeData = other307.receiveTimeData;
  receiveTimeString = other307.receiveTimeString;
  __isset = other307.__isset;
}
FastbootPacket& FastbootPacket::operator=(const FastbootPacket& other308) {
  errorCode = other308.errorCode;
  sessionIndex = other308.sessionIndex;
  protocolIndex = other308.protocolIndex;
  packetText = other308.packetText;
  receiveTimeData = other308.receiveTimeData;
  receiveTimeString = other308.receiveTimeString;
  __isset = other308.__isset;
  return *this;
}
void FastbootPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FastbootPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "packetText="; (__isset.packetText ? (out << to_string(packetText)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ")";
}


EudPacketFilter::~EudPacketFilter() noexcept {
}


void EudPacketFilter::__set_opCodeMask(const std::vector<std::string> & val) {
  this->opCodeMask = val;
__isset.opCodeMask = true;
}
std::ostream& operator<<(std::ostream& out, const EudPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t EudPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->opCodeMask.clear();
            uint32_t _size309;
            ::apache::thrift::protocol::TType _etype312;
            xfer += iprot->readListBegin(_etype312, _size309);
            this->opCodeMask.resize(_size309);
            uint32_t _i313;
            for (_i313 = 0; _i313 < _size309; ++_i313)
            {
              xfer += iprot->readString(this->opCodeMask[_i313]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.opCodeMask = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t EudPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EudPacketFilter");

  if (this->__isset.opCodeMask) {
    xfer += oprot->writeFieldBegin("opCodeMask", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->opCodeMask.size()));
      std::vector<std::string> ::const_iterator _iter314;
      for (_iter314 = this->opCodeMask.begin(); _iter314 != this->opCodeMask.end(); ++_iter314)
      {
        xfer += oprot->writeString((*_iter314));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(EudPacketFilter &a, EudPacketFilter &b) {
  using ::std::swap;
  swap(a.opCodeMask, b.opCodeMask);
  swap(a.__isset, b.__isset);
}

EudPacketFilter::EudPacketFilter(const EudPacketFilter& other315) {
  opCodeMask = other315.opCodeMask;
  __isset = other315.__isset;
}
EudPacketFilter& EudPacketFilter::operator=(const EudPacketFilter& other316) {
  opCodeMask = other316.opCodeMask;
  __isset = other316.__isset;
  return *this;
}
void EudPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "EudPacketFilter(";
  out << "opCodeMask="; (__isset.opCodeMask ? (out << to_string(opCodeMask)) : (out << "<null>"));
  out << ")";
}


EudReturnConfig::~EudReturnConfig() noexcept {
}


void EudReturnConfig::__set_flags(const EudReturnFlags::type val) {
  this->flags = val;
}
std::ostream& operator<<(std::ostream& out, const EudReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t EudReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast317;
          xfer += iprot->readI32(ecast317);
          this->flags = (EudReturnFlags::type)ecast317;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t EudReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EudReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(EudReturnConfig &a, EudReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.__isset, b.__isset);
}

EudReturnConfig::EudReturnConfig(const EudReturnConfig& other318) {
  flags = other318.flags;
  __isset = other318.__isset;
}
EudReturnConfig& EudReturnConfig::operator=(const EudReturnConfig& other319) {
  flags = other319.flags;
  __isset = other319.__isset;
  return *this;
}
void EudReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "EudReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ")";
}


EudPacket::~EudPacket() noexcept {
}


void EudPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void EudPacket::__set_packetId(const int32_t val) {
  this->packetId = val;
__isset.packetId = true;
}

void EudPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void EudPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void EudPacket::__set_packetName(const std::string& val) {
  this->packetName = val;
__isset.packetName = true;
}

void EudPacket::__set_binaryPayload(const std::string& val) {
  this->binaryPayload = val;
__isset.binaryPayload = true;
}

void EudPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void EudPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}
std::ostream& operator<<(std::ostream& out, const EudPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t EudPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast320;
          xfer += iprot->readI32(ecast320);
          this->errorCode = (ErrorCode::type)ecast320;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->packetId);
          this->__isset.packetId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetName);
          this->__isset.packetName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->binaryPayload);
          this->__isset.binaryPayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t EudPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EudPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetId) {
    xfer += oprot->writeFieldBegin("packetId", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->packetId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 4);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetName) {
    xfer += oprot->writeFieldBegin("packetName", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->packetName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.binaryPayload) {
    xfer += oprot->writeFieldBegin("binaryPayload", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeBinary(this->binaryPayload);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 7);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 8);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(EudPacket &a, EudPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.packetId, b.packetId);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.packetName, b.packetName);
  swap(a.binaryPayload, b.binaryPayload);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.__isset, b.__isset);
}

EudPacket::EudPacket(const EudPacket& other321) {
  errorCode = other321.errorCode;
  packetId = other321.packetId;
  sessionIndex = other321.sessionIndex;
  protocolIndex = other321.protocolIndex;
  packetName = other321.packetName;
  binaryPayload = other321.binaryPayload;
  receiveTimeData = other321.receiveTimeData;
  receiveTimeString = other321.receiveTimeString;
  __isset = other321.__isset;
}
EudPacket& EudPacket::operator=(const EudPacket& other322) {
  errorCode = other322.errorCode;
  packetId = other322.packetId;
  sessionIndex = other322.sessionIndex;
  protocolIndex = other322.protocolIndex;
  packetName = other322.packetName;
  binaryPayload = other322.binaryPayload;
  receiveTimeData = other322.receiveTimeData;
  receiveTimeString = other322.receiveTimeString;
  __isset = other322.__isset;
  return *this;
}
void EudPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "EudPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "packetId="; (__isset.packetId ? (out << to_string(packetId)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "packetName="; (__isset.packetName ? (out << to_string(packetName)) : (out << "<null>"));
  out << ", " << "binaryPayload="; (__isset.binaryPayload ? (out << to_string(binaryPayload)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ")";
}


RpcToCapabilityNameMap::~RpcToCapabilityNameMap() noexcept {
}


void RpcToCapabilityNameMap::__set_rpcCapabilityNameList(const std::map<std::string, std::vector<std::string> > & val) {
  this->rpcCapabilityNameList = val;
__isset.rpcCapabilityNameList = true;
}
std::ostream& operator<<(std::ostream& out, const RpcToCapabilityNameMap& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t RpcToCapabilityNameMap::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->rpcCapabilityNameList.clear();
            uint32_t _size323;
            ::apache::thrift::protocol::TType _ktype324;
            ::apache::thrift::protocol::TType _vtype325;
            xfer += iprot->readMapBegin(_ktype324, _vtype325, _size323);
            uint32_t _i327;
            for (_i327 = 0; _i327 < _size323; ++_i327)
            {
              std::string _key328;
              xfer += iprot->readString(_key328);
              std::vector<std::string> & _val329 = this->rpcCapabilityNameList[_key328];
              {
                _val329.clear();
                uint32_t _size330;
                ::apache::thrift::protocol::TType _etype333;
                xfer += iprot->readListBegin(_etype333, _size330);
                _val329.resize(_size330);
                uint32_t _i334;
                for (_i334 = 0; _i334 < _size330; ++_i334)
                {
                  xfer += iprot->readString(_val329[_i334]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.rpcCapabilityNameList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t RpcToCapabilityNameMap::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("RpcToCapabilityNameMap");

  if (this->__isset.rpcCapabilityNameList) {
    xfer += oprot->writeFieldBegin("rpcCapabilityNameList", ::apache::thrift::protocol::T_MAP, 1);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->rpcCapabilityNameList.size()));
      std::map<std::string, std::vector<std::string> > ::const_iterator _iter335;
      for (_iter335 = this->rpcCapabilityNameList.begin(); _iter335 != this->rpcCapabilityNameList.end(); ++_iter335)
      {
        xfer += oprot->writeString(_iter335->first);
        {
          xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(_iter335->second.size()));
          std::vector<std::string> ::const_iterator _iter336;
          for (_iter336 = _iter335->second.begin(); _iter336 != _iter335->second.end(); ++_iter336)
          {
            xfer += oprot->writeString((*_iter336));
          }
          xfer += oprot->writeListEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RpcToCapabilityNameMap &a, RpcToCapabilityNameMap &b) {
  using ::std::swap;
  swap(a.rpcCapabilityNameList, b.rpcCapabilityNameList);
  swap(a.__isset, b.__isset);
}

RpcToCapabilityNameMap::RpcToCapabilityNameMap(const RpcToCapabilityNameMap& other337) {
  rpcCapabilityNameList = other337.rpcCapabilityNameList;
  __isset = other337.__isset;
}
RpcToCapabilityNameMap& RpcToCapabilityNameMap::operator=(const RpcToCapabilityNameMap& other338) {
  rpcCapabilityNameList = other338.rpcCapabilityNameList;
  __isset = other338.__isset;
  return *this;
}
void RpcToCapabilityNameMap::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "RpcToCapabilityNameMap(";
  out << "rpcCapabilityNameList="; (__isset.rpcCapabilityNameList ? (out << to_string(rpcCapabilityNameList)) : (out << "<null>"));
  out << ")";
}


ProtoBufPacketFilter::~ProtoBufPacketFilter() noexcept {
}


void ProtoBufPacketFilter::__set_rpcNameMask(const std::map<ProtoBufPacketType::type, RpcToCapabilityNameMap> & val) {
  this->rpcNameMask = val;
__isset.rpcNameMask = true;
}
std::ostream& operator<<(std::ostream& out, const ProtoBufPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProtoBufPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->rpcNameMask.clear();
            uint32_t _size339;
            ::apache::thrift::protocol::TType _ktype340;
            ::apache::thrift::protocol::TType _vtype341;
            xfer += iprot->readMapBegin(_ktype340, _vtype341, _size339);
            uint32_t _i343;
            for (_i343 = 0; _i343 < _size339; ++_i343)
            {
              ProtoBufPacketType::type _key344;
              int32_t ecast346;
              xfer += iprot->readI32(ecast346);
              _key344 = (ProtoBufPacketType::type)ecast346;
              RpcToCapabilityNameMap& _val345 = this->rpcNameMask[_key344];
              xfer += _val345.read(iprot);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.rpcNameMask = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProtoBufPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProtoBufPacketFilter");

  if (this->__isset.rpcNameMask) {
    xfer += oprot->writeFieldBegin("rpcNameMask", ::apache::thrift::protocol::T_MAP, 1);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->rpcNameMask.size()));
      std::map<ProtoBufPacketType::type, RpcToCapabilityNameMap> ::const_iterator _iter347;
      for (_iter347 = this->rpcNameMask.begin(); _iter347 != this->rpcNameMask.end(); ++_iter347)
      {
        xfer += oprot->writeI32((int32_t)_iter347->first);
        xfer += _iter347->second.write(oprot);
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProtoBufPacketFilter &a, ProtoBufPacketFilter &b) {
  using ::std::swap;
  swap(a.rpcNameMask, b.rpcNameMask);
  swap(a.__isset, b.__isset);
}

ProtoBufPacketFilter::ProtoBufPacketFilter(const ProtoBufPacketFilter& other348) {
  rpcNameMask = other348.rpcNameMask;
  __isset = other348.__isset;
}
ProtoBufPacketFilter& ProtoBufPacketFilter::operator=(const ProtoBufPacketFilter& other349) {
  rpcNameMask = other349.rpcNameMask;
  __isset = other349.__isset;
  return *this;
}
void ProtoBufPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProtoBufPacketFilter(";
  out << "rpcNameMask="; (__isset.rpcNameMask ? (out << to_string(rpcNameMask)) : (out << "<null>"));
  out << ")";
}


ProtoBufReturns::~ProtoBufReturns() noexcept {
}


void ProtoBufReturns::__set_flags(const ProtoBufReturnFlags::type val) {
  this->flags = val;
__isset.flags = true;
}

void ProtoBufReturns::__set_queries(const std::vector<std::string> & val) {
  this->queries = val;
__isset.queries = true;
}
std::ostream& operator<<(std::ostream& out, const ProtoBufReturns& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProtoBufReturns::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast350;
          xfer += iprot->readI32(ecast350);
          this->flags = (ProtoBufReturnFlags::type)ecast350;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->queries.clear();
            uint32_t _size351;
            ::apache::thrift::protocol::TType _etype354;
            xfer += iprot->readListBegin(_etype354, _size351);
            this->queries.resize(_size351);
            uint32_t _i355;
            for (_i355 = 0; _i355 < _size351; ++_i355)
            {
              xfer += iprot->readString(this->queries[_i355]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.queries = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProtoBufReturns::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProtoBufReturns");

  if (this->__isset.flags) {
    xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->flags);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.queries) {
    xfer += oprot->writeFieldBegin("queries", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->queries.size()));
      std::vector<std::string> ::const_iterator _iter356;
      for (_iter356 = this->queries.begin(); _iter356 != this->queries.end(); ++_iter356)
      {
        xfer += oprot->writeString((*_iter356));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProtoBufReturns &a, ProtoBufReturns &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.queries, b.queries);
  swap(a.__isset, b.__isset);
}

ProtoBufReturns::ProtoBufReturns(const ProtoBufReturns& other357) {
  flags = other357.flags;
  queries = other357.queries;
  __isset = other357.__isset;
}
ProtoBufReturns& ProtoBufReturns::operator=(const ProtoBufReturns& other358) {
  flags = other358.flags;
  queries = other358.queries;
  __isset = other358.__isset;
  return *this;
}
void ProtoBufReturns::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProtoBufReturns(";
  out << "flags="; (__isset.flags ? (out << to_string(flags)) : (out << "<null>"));
  out << ", " << "queries="; (__isset.queries ? (out << to_string(queries)) : (out << "<null>"));
  out << ")";
}


ProtoBufReturnConfig::~ProtoBufReturnConfig() noexcept {
}


void ProtoBufReturnConfig::__set_flags(const ProtoBufReturnFlags::type val) {
  this->flags = val;
}

void ProtoBufReturnConfig::__set_fieldQueries(const std::map<ProtoBufPacketType::type, std::map<std::string, ProtoBufReturns> > & val) {
  this->fieldQueries = val;
__isset.fieldQueries = true;
}
std::ostream& operator<<(std::ostream& out, const ProtoBufReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProtoBufReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast359;
          xfer += iprot->readI32(ecast359);
          this->flags = (ProtoBufReturnFlags::type)ecast359;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->fieldQueries.clear();
            uint32_t _size360;
            ::apache::thrift::protocol::TType _ktype361;
            ::apache::thrift::protocol::TType _vtype362;
            xfer += iprot->readMapBegin(_ktype361, _vtype362, _size360);
            uint32_t _i364;
            for (_i364 = 0; _i364 < _size360; ++_i364)
            {
              ProtoBufPacketType::type _key365;
              int32_t ecast367;
              xfer += iprot->readI32(ecast367);
              _key365 = (ProtoBufPacketType::type)ecast367;
              std::map<std::string, ProtoBufReturns> & _val366 = this->fieldQueries[_key365];
              {
                _val366.clear();
                uint32_t _size368;
                ::apache::thrift::protocol::TType _ktype369;
                ::apache::thrift::protocol::TType _vtype370;
                xfer += iprot->readMapBegin(_ktype369, _vtype370, _size368);
                uint32_t _i372;
                for (_i372 = 0; _i372 < _size368; ++_i372)
                {
                  std::string _key373;
                  xfer += iprot->readString(_key373);
                  ProtoBufReturns& _val374 = _val366[_key373];
                  xfer += _val374.read(iprot);
                }
                xfer += iprot->readMapEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.fieldQueries = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProtoBufReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProtoBufReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.fieldQueries) {
    xfer += oprot->writeFieldBegin("fieldQueries", ::apache::thrift::protocol::T_MAP, 2);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_MAP, static_cast<uint32_t>(this->fieldQueries.size()));
      std::map<ProtoBufPacketType::type, std::map<std::string, ProtoBufReturns> > ::const_iterator _iter375;
      for (_iter375 = this->fieldQueries.begin(); _iter375 != this->fieldQueries.end(); ++_iter375)
      {
        xfer += oprot->writeI32((int32_t)_iter375->first);
        {
          xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(_iter375->second.size()));
          std::map<std::string, ProtoBufReturns> ::const_iterator _iter376;
          for (_iter376 = _iter375->second.begin(); _iter376 != _iter375->second.end(); ++_iter376)
          {
            xfer += oprot->writeString(_iter376->first);
            xfer += _iter376->second.write(oprot);
          }
          xfer += oprot->writeMapEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProtoBufReturnConfig &a, ProtoBufReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.fieldQueries, b.fieldQueries);
  swap(a.__isset, b.__isset);
}

ProtoBufReturnConfig::ProtoBufReturnConfig(const ProtoBufReturnConfig& other377) {
  flags = other377.flags;
  fieldQueries = other377.fieldQueries;
  __isset = other377.__isset;
}
ProtoBufReturnConfig& ProtoBufReturnConfig::operator=(const ProtoBufReturnConfig& other378) {
  flags = other378.flags;
  fieldQueries = other378.fieldQueries;
  __isset = other378.__isset;
  return *this;
}
void ProtoBufReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProtoBufReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ", " << "fieldQueries="; (__isset.fieldQueries ? (out << to_string(fieldQueries)) : (out << "<null>"));
  out << ")";
}


ProtoBufPacket::~ProtoBufPacket() noexcept {
}


void ProtoBufPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void ProtoBufPacket::__set_packetType(const ProtoBufPacketType::type val) {
  this->packetType = val;
__isset.packetType = true;
}

void ProtoBufPacket::__set_rpcId(const int64_t val) {
  this->rpcId = val;
__isset.rpcId = true;
}

void ProtoBufPacket::__set_messageId(const int16_t val) {
  this->messageId = val;
__isset.messageId = true;
}

void ProtoBufPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void ProtoBufPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void ProtoBufPacket::__set_packetName(const std::string& val) {
  this->packetName = val;
__isset.packetName = true;
}

void ProtoBufPacket::__set_binaryPayload(const std::string& val) {
  this->binaryPayload = val;
__isset.binaryPayload = true;
}

void ProtoBufPacket::__set_parsedText(const std::string& val) {
  this->parsedText = val;
__isset.parsedText = true;
}

void ProtoBufPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void ProtoBufPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}

void ProtoBufPacket::__set_queryResultJson(const std::string& val) {
  this->queryResultJson = val;
__isset.queryResultJson = true;
}

void ProtoBufPacket::__set_queryResultPickled(const std::string& val) {
  this->queryResultPickled = val;
__isset.queryResultPickled = true;
}

void ProtoBufPacket::__set_parsedTextJson(const std::string& val) {
  this->parsedTextJson = val;
__isset.parsedTextJson = true;
}
std::ostream& operator<<(std::ostream& out, const ProtoBufPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProtoBufPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast379;
          xfer += iprot->readI32(ecast379);
          this->errorCode = (ErrorCode::type)ecast379;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast380;
          xfer += iprot->readI32(ecast380);
          this->packetType = (ProtoBufPacketType::type)ecast380;
          this->__isset.packetType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->rpcId);
          this->__isset.rpcId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->messageId);
          this->__isset.messageId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetName);
          this->__isset.packetName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->binaryPayload);
          this->__isset.binaryPayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->parsedText);
          this->__isset.parsedText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->queryResultJson);
          this->__isset.queryResultJson = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->queryResultPickled);
          this->__isset.queryResultPickled = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 14:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->parsedTextJson);
          this->__isset.parsedTextJson = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProtoBufPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProtoBufPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetType) {
    xfer += oprot->writeFieldBegin("packetType", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->packetType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.rpcId) {
    xfer += oprot->writeFieldBegin("rpcId", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->rpcId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.messageId) {
    xfer += oprot->writeFieldBegin("messageId", ::apache::thrift::protocol::T_I16, 4);
    xfer += oprot->writeI16(this->messageId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 6);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetName) {
    xfer += oprot->writeFieldBegin("packetName", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->packetName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.binaryPayload) {
    xfer += oprot->writeFieldBegin("binaryPayload", ::apache::thrift::protocol::T_STRING, 8);
    xfer += oprot->writeBinary(this->binaryPayload);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.parsedText) {
    xfer += oprot->writeFieldBegin("parsedText", ::apache::thrift::protocol::T_STRING, 9);
    xfer += oprot->writeString(this->parsedText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 10);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 11);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.queryResultJson) {
    xfer += oprot->writeFieldBegin("queryResultJson", ::apache::thrift::protocol::T_STRING, 12);
    xfer += oprot->writeString(this->queryResultJson);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.queryResultPickled) {
    xfer += oprot->writeFieldBegin("queryResultPickled", ::apache::thrift::protocol::T_STRING, 13);
    xfer += oprot->writeBinary(this->queryResultPickled);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.parsedTextJson) {
    xfer += oprot->writeFieldBegin("parsedTextJson", ::apache::thrift::protocol::T_STRING, 14);
    xfer += oprot->writeString(this->parsedTextJson);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProtoBufPacket &a, ProtoBufPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.packetType, b.packetType);
  swap(a.rpcId, b.rpcId);
  swap(a.messageId, b.messageId);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.packetName, b.packetName);
  swap(a.binaryPayload, b.binaryPayload);
  swap(a.parsedText, b.parsedText);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.queryResultJson, b.queryResultJson);
  swap(a.queryResultPickled, b.queryResultPickled);
  swap(a.parsedTextJson, b.parsedTextJson);
  swap(a.__isset, b.__isset);
}

ProtoBufPacket::ProtoBufPacket(const ProtoBufPacket& other381) {
  errorCode = other381.errorCode;
  packetType = other381.packetType;
  rpcId = other381.rpcId;
  messageId = other381.messageId;
  sessionIndex = other381.sessionIndex;
  protocolIndex = other381.protocolIndex;
  packetName = other381.packetName;
  binaryPayload = other381.binaryPayload;
  parsedText = other381.parsedText;
  receiveTimeData = other381.receiveTimeData;
  receiveTimeString = other381.receiveTimeString;
  queryResultJson = other381.queryResultJson;
  queryResultPickled = other381.queryResultPickled;
  parsedTextJson = other381.parsedTextJson;
  __isset = other381.__isset;
}
ProtoBufPacket& ProtoBufPacket::operator=(const ProtoBufPacket& other382) {
  errorCode = other382.errorCode;
  packetType = other382.packetType;
  rpcId = other382.rpcId;
  messageId = other382.messageId;
  sessionIndex = other382.sessionIndex;
  protocolIndex = other382.protocolIndex;
  packetName = other382.packetName;
  binaryPayload = other382.binaryPayload;
  parsedText = other382.parsedText;
  receiveTimeData = other382.receiveTimeData;
  receiveTimeString = other382.receiveTimeString;
  queryResultJson = other382.queryResultJson;
  queryResultPickled = other382.queryResultPickled;
  parsedTextJson = other382.parsedTextJson;
  __isset = other382.__isset;
  return *this;
}
void ProtoBufPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProtoBufPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "packetType="; (__isset.packetType ? (out << to_string(packetType)) : (out << "<null>"));
  out << ", " << "rpcId="; (__isset.rpcId ? (out << to_string(rpcId)) : (out << "<null>"));
  out << ", " << "messageId="; (__isset.messageId ? (out << to_string(messageId)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "packetName="; (__isset.packetName ? (out << to_string(packetName)) : (out << "<null>"));
  out << ", " << "binaryPayload="; (__isset.binaryPayload ? (out << to_string(binaryPayload)) : (out << "<null>"));
  out << ", " << "parsedText="; (__isset.parsedText ? (out << to_string(parsedText)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ", " << "queryResultJson="; (__isset.queryResultJson ? (out << to_string(queryResultJson)) : (out << "<null>"));
  out << ", " << "queryResultPickled="; (__isset.queryResultPickled ? (out << to_string(queryResultPickled)) : (out << "<null>"));
  out << ", " << "parsedTextJson="; (__isset.parsedTextJson ? (out << to_string(parsedTextJson)) : (out << "<null>"));
  out << ")";
}


RxTxInfo::~RxTxInfo() noexcept {
}


void RxTxInfo::__set_rxTotalPacketCount(const int64_t val) {
  this->rxTotalPacketCount = val;
}

void RxTxInfo::__set_txTotalPacketCount(const int64_t val) {
  this->txTotalPacketCount = val;
}

void RxTxInfo::__set_rxTotalByteCount(const int64_t val) {
  this->rxTotalByteCount = val;
}

void RxTxInfo::__set_txTotalByteCount(const int64_t val) {
  this->txTotalByteCount = val;
}

void RxTxInfo::__set_rxInstThroughput(const double val) {
  this->rxInstThroughput = val;
}

void RxTxInfo::__set_txInstThroughput(const double val) {
  this->txInstThroughput = val;
}
std::ostream& operator<<(std::ostream& out, const RxTxInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t RxTxInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->rxTotalPacketCount);
          this->__isset.rxTotalPacketCount = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->txTotalPacketCount);
          this->__isset.txTotalPacketCount = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->rxTotalByteCount);
          this->__isset.rxTotalByteCount = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->txTotalByteCount);
          this->__isset.txTotalByteCount = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->rxInstThroughput);
          this->__isset.rxInstThroughput = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->txInstThroughput);
          this->__isset.txInstThroughput = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t RxTxInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("RxTxInfo");

  xfer += oprot->writeFieldBegin("rxTotalPacketCount", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->rxTotalPacketCount);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("txTotalPacketCount", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->txTotalPacketCount);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("rxTotalByteCount", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->rxTotalByteCount);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("txTotalByteCount", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->txTotalByteCount);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("rxInstThroughput", ::apache::thrift::protocol::T_DOUBLE, 5);
  xfer += oprot->writeDouble(this->rxInstThroughput);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("txInstThroughput", ::apache::thrift::protocol::T_DOUBLE, 6);
  xfer += oprot->writeDouble(this->txInstThroughput);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RxTxInfo &a, RxTxInfo &b) {
  using ::std::swap;
  swap(a.rxTotalPacketCount, b.rxTotalPacketCount);
  swap(a.txTotalPacketCount, b.txTotalPacketCount);
  swap(a.rxTotalByteCount, b.rxTotalByteCount);
  swap(a.txTotalByteCount, b.txTotalByteCount);
  swap(a.rxInstThroughput, b.rxInstThroughput);
  swap(a.txInstThroughput, b.txInstThroughput);
  swap(a.__isset, b.__isset);
}

RxTxInfo::RxTxInfo(const RxTxInfo& other383) {
  rxTotalPacketCount = other383.rxTotalPacketCount;
  txTotalPacketCount = other383.txTotalPacketCount;
  rxTotalByteCount = other383.rxTotalByteCount;
  txTotalByteCount = other383.txTotalByteCount;
  rxInstThroughput = other383.rxInstThroughput;
  txInstThroughput = other383.txInstThroughput;
  __isset = other383.__isset;
}
RxTxInfo& RxTxInfo::operator=(const RxTxInfo& other384) {
  rxTotalPacketCount = other384.rxTotalPacketCount;
  txTotalPacketCount = other384.txTotalPacketCount;
  rxTotalByteCount = other384.rxTotalByteCount;
  txTotalByteCount = other384.txTotalByteCount;
  rxInstThroughput = other384.rxInstThroughput;
  txInstThroughput = other384.txInstThroughput;
  __isset = other384.__isset;
  return *this;
}
void RxTxInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "RxTxInfo(";
  out << "rxTotalPacketCount=" << to_string(rxTotalPacketCount);
  out << ", " << "txTotalPacketCount=" << to_string(txTotalPacketCount);
  out << ", " << "rxTotalByteCount=" << to_string(rxTotalByteCount);
  out << ", " << "txTotalByteCount=" << to_string(txTotalByteCount);
  out << ", " << "rxInstThroughput=" << to_string(rxInstThroughput);
  out << ", " << "txInstThroughput=" << to_string(txInstThroughput);
  out << ")";
}


AdplReturnConfig::~AdplReturnConfig() noexcept {
}


void AdplReturnConfig::__set_flags(const AdplReturnFlags::type val) {
  this->flags = val;
}
std::ostream& operator<<(std::ostream& out, const AdplReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t AdplReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast385;
          xfer += iprot->readI32(ecast385);
          this->flags = (AdplReturnFlags::type)ecast385;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AdplReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AdplReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AdplReturnConfig &a, AdplReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.__isset, b.__isset);
}

AdplReturnConfig::AdplReturnConfig(const AdplReturnConfig& other386) {
  flags = other386.flags;
  __isset = other386.__isset;
}
AdplReturnConfig& AdplReturnConfig::operator=(const AdplReturnConfig& other387) {
  flags = other387.flags;
  __isset = other387.__isset;
  return *this;
}
void AdplReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AdplReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ")";
}


AdplPacket::~AdplPacket() noexcept {
}


void AdplPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void AdplPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void AdplPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void AdplPacket::__set_version(const int8_t val) {
  this->version = val;
__isset.version = true;
}

void AdplPacket::__set_binaryPayload(const std::string& val) {
  this->binaryPayload = val;
__isset.binaryPayload = true;
}

void AdplPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void AdplPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}

void AdplPacket::__set_modemTimeData(const int64_t val) {
  this->modemTimeData = val;
__isset.modemTimeData = true;
}

void AdplPacket::__set_modemTimeDataString(const std::string& val) {
  this->modemTimeDataString = val;
__isset.modemTimeDataString = true;
}

void AdplPacket::__set_diagBinaryPayload(const std::string& val) {
  this->diagBinaryPayload = val;
__isset.diagBinaryPayload = true;
}
std::ostream& operator<<(std::ostream& out, const AdplPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t AdplPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast388;
          xfer += iprot->readI32(ecast388);
          this->errorCode = (ErrorCode::type)ecast388;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->version);
          this->__isset.version = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->binaryPayload);
          this->__isset.binaryPayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->modemTimeData);
          this->__isset.modemTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->modemTimeDataString);
          this->__isset.modemTimeDataString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->diagBinaryPayload);
          this->__isset.diagBinaryPayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AdplPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("AdplPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.version) {
    xfer += oprot->writeFieldBegin("version", ::apache::thrift::protocol::T_BYTE, 4);
    xfer += oprot->writeByte(this->version);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.binaryPayload) {
    xfer += oprot->writeFieldBegin("binaryPayload", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->binaryPayload);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 6);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.modemTimeData) {
    xfer += oprot->writeFieldBegin("modemTimeData", ::apache::thrift::protocol::T_I64, 8);
    xfer += oprot->writeI64(this->modemTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.modemTimeDataString) {
    xfer += oprot->writeFieldBegin("modemTimeDataString", ::apache::thrift::protocol::T_STRING, 9);
    xfer += oprot->writeString(this->modemTimeDataString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.diagBinaryPayload) {
    xfer += oprot->writeFieldBegin("diagBinaryPayload", ::apache::thrift::protocol::T_STRING, 10);
    xfer += oprot->writeString(this->diagBinaryPayload);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(AdplPacket &a, AdplPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.version, b.version);
  swap(a.binaryPayload, b.binaryPayload);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.modemTimeData, b.modemTimeData);
  swap(a.modemTimeDataString, b.modemTimeDataString);
  swap(a.diagBinaryPayload, b.diagBinaryPayload);
  swap(a.__isset, b.__isset);
}

AdplPacket::AdplPacket(const AdplPacket& other389) {
  errorCode = other389.errorCode;
  sessionIndex = other389.sessionIndex;
  protocolIndex = other389.protocolIndex;
  version = other389.version;
  binaryPayload = other389.binaryPayload;
  receiveTimeData = other389.receiveTimeData;
  receiveTimeString = other389.receiveTimeString;
  modemTimeData = other389.modemTimeData;
  modemTimeDataString = other389.modemTimeDataString;
  diagBinaryPayload = other389.diagBinaryPayload;
  __isset = other389.__isset;
}
AdplPacket& AdplPacket::operator=(const AdplPacket& other390) {
  errorCode = other390.errorCode;
  sessionIndex = other390.sessionIndex;
  protocolIndex = other390.protocolIndex;
  version = other390.version;
  binaryPayload = other390.binaryPayload;
  receiveTimeData = other390.receiveTimeData;
  receiveTimeString = other390.receiveTimeString;
  modemTimeData = other390.modemTimeData;
  modemTimeDataString = other390.modemTimeDataString;
  diagBinaryPayload = other390.diagBinaryPayload;
  __isset = other390.__isset;
  return *this;
}
void AdplPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "AdplPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "version="; (__isset.version ? (out << to_string(version)) : (out << "<null>"));
  out << ", " << "binaryPayload="; (__isset.binaryPayload ? (out << to_string(binaryPayload)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ", " << "modemTimeData="; (__isset.modemTimeData ? (out << to_string(modemTimeData)) : (out << "<null>"));
  out << ", " << "modemTimeDataString="; (__isset.modemTimeDataString ? (out << to_string(modemTimeDataString)) : (out << "<null>"));
  out << ", " << "diagBinaryPayload="; (__isset.diagBinaryPayload ? (out << to_string(diagBinaryPayload)) : (out << "<null>"));
  out << ")";
}


BuildInfo::~BuildInfo() noexcept {
}


void BuildInfo::__set_msmRevision(const std::string& val) {
  this->msmRevision = val;
__isset.msmRevision = true;
}

void BuildInfo::__set_mobileModelId(const std::string& val) {
  this->mobileModelId = val;
__isset.mobileModelId = true;
}

void BuildInfo::__set_mobileSoftwareRevision(const std::string& val) {
  this->mobileSoftwareRevision = val;
__isset.mobileSoftwareRevision = true;
}

void BuildInfo::__set_mobileModelName(const std::string& val) {
  this->mobileModelName = val;
__isset.mobileModelName = true;
}
std::ostream& operator<<(std::ostream& out, const BuildInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t BuildInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msmRevision);
          this->__isset.msmRevision = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->mobileModelId);
          this->__isset.mobileModelId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->mobileSoftwareRevision);
          this->__isset.mobileSoftwareRevision = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->mobileModelName);
          this->__isset.mobileModelName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t BuildInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("BuildInfo");

  if (this->__isset.msmRevision) {
    xfer += oprot->writeFieldBegin("msmRevision", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->msmRevision);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.mobileModelId) {
    xfer += oprot->writeFieldBegin("mobileModelId", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->mobileModelId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.mobileSoftwareRevision) {
    xfer += oprot->writeFieldBegin("mobileSoftwareRevision", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->mobileSoftwareRevision);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.mobileModelName) {
    xfer += oprot->writeFieldBegin("mobileModelName", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->mobileModelName);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(BuildInfo &a, BuildInfo &b) {
  using ::std::swap;
  swap(a.msmRevision, b.msmRevision);
  swap(a.mobileModelId, b.mobileModelId);
  swap(a.mobileSoftwareRevision, b.mobileSoftwareRevision);
  swap(a.mobileModelName, b.mobileModelName);
  swap(a.__isset, b.__isset);
}

BuildInfo::BuildInfo(const BuildInfo& other391) {
  msmRevision = other391.msmRevision;
  mobileModelId = other391.mobileModelId;
  mobileSoftwareRevision = other391.mobileSoftwareRevision;
  mobileModelName = other391.mobileModelName;
  __isset = other391.__isset;
}
BuildInfo& BuildInfo::operator=(const BuildInfo& other392) {
  msmRevision = other392.msmRevision;
  mobileModelId = other392.mobileModelId;
  mobileSoftwareRevision = other392.mobileSoftwareRevision;
  mobileModelName = other392.mobileModelName;
  __isset = other392.__isset;
  return *this;
}
void BuildInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "BuildInfo(";
  out << "msmRevision="; (__isset.msmRevision ? (out << to_string(msmRevision)) : (out << "<null>"));
  out << ", " << "mobileModelId="; (__isset.mobileModelId ? (out << to_string(mobileModelId)) : (out << "<null>"));
  out << ", " << "mobileSoftwareRevision="; (__isset.mobileSoftwareRevision ? (out << to_string(mobileSoftwareRevision)) : (out << "<null>"));
  out << ", " << "mobileModelName="; (__isset.mobileModelName ? (out << to_string(mobileModelName)) : (out << "<null>"));
  out << ")";
}


ImageInfo::~ImageInfo() noexcept {
}


void ImageInfo::__set_index(const int16_t val) {
  this->index = val;
}

void ImageInfo::__set_imageVersion(const std::string& val) {
  this->imageVersion = val;
}

void ImageInfo::__set_variant(const std::string& val) {
  this->variant = val;
}

void ImageInfo::__set_oemVersion(const std::string& val) {
  this->oemVersion = val;
}
std::ostream& operator<<(std::ostream& out, const ImageInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ImageInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->index);
          this->__isset.index = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->imageVersion);
          this->__isset.imageVersion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->variant);
          this->__isset.variant = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->oemVersion);
          this->__isset.oemVersion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ImageInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageInfo");

  xfer += oprot->writeFieldBegin("index", ::apache::thrift::protocol::T_I16, 1);
  xfer += oprot->writeI16(this->index);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("imageVersion", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->imageVersion);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("variant", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->variant);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("oemVersion", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->oemVersion);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ImageInfo &a, ImageInfo &b) {
  using ::std::swap;
  swap(a.index, b.index);
  swap(a.imageVersion, b.imageVersion);
  swap(a.variant, b.variant);
  swap(a.oemVersion, b.oemVersion);
  swap(a.__isset, b.__isset);
}

ImageInfo::ImageInfo(const ImageInfo& other393) {
  index = other393.index;
  imageVersion = other393.imageVersion;
  variant = other393.variant;
  oemVersion = other393.oemVersion;
  __isset = other393.__isset;
}
ImageInfo& ImageInfo::operator=(const ImageInfo& other394) {
  index = other394.index;
  imageVersion = other394.imageVersion;
  variant = other394.variant;
  oemVersion = other394.oemVersion;
  __isset = other394.__isset;
  return *this;
}
void ImageInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ImageInfo(";
  out << "index=" << to_string(index);
  out << ", " << "imageVersion=" << to_string(imageVersion);
  out << ", " << "variant=" << to_string(variant);
  out << ", " << "oemVersion=" << to_string(oemVersion);
  out << ")";
}


GpsPacket::~GpsPacket() noexcept {
}


void GpsPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void GpsPacket::__set_latitude(const std::string& val) {
  this->latitude = val;
__isset.latitude = true;
}

void GpsPacket::__set_longitude(const std::string& val) {
  this->longitude = val;
__isset.longitude = true;
}

void GpsPacket::__set_altitude(const std::string& val) {
  this->altitude = val;
__isset.altitude = true;
}

void GpsPacket::__set_speed(const std::string& val) {
  this->speed = val;
__isset.speed = true;
}

void GpsPacket::__set_time(const std::string& val) {
  this->time = val;
__isset.time = true;
}

void GpsPacket::__set_date(const std::string& val) {
  this->date = val;
__isset.date = true;
}
std::ostream& operator<<(std::ostream& out, const GpsPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t GpsPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast395;
          xfer += iprot->readI32(ecast395);
          this->errorCode = (ErrorCode::type)ecast395;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->latitude);
          this->__isset.latitude = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->longitude);
          this->__isset.longitude = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->altitude);
          this->__isset.altitude = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->speed);
          this->__isset.speed = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->time);
          this->__isset.time = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->date);
          this->__isset.date = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t GpsPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("GpsPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.latitude) {
    xfer += oprot->writeFieldBegin("latitude", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->latitude);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.longitude) {
    xfer += oprot->writeFieldBegin("longitude", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->longitude);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.altitude) {
    xfer += oprot->writeFieldBegin("altitude", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->altitude);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.speed) {
    xfer += oprot->writeFieldBegin("speed", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->speed);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.time) {
    xfer += oprot->writeFieldBegin("time", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->time);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.date) {
    xfer += oprot->writeFieldBegin("date", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->date);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(GpsPacket &a, GpsPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.latitude, b.latitude);
  swap(a.longitude, b.longitude);
  swap(a.altitude, b.altitude);
  swap(a.speed, b.speed);
  swap(a.time, b.time);
  swap(a.date, b.date);
  swap(a.__isset, b.__isset);
}

GpsPacket::GpsPacket(const GpsPacket& other396) {
  errorCode = other396.errorCode;
  latitude = other396.latitude;
  longitude = other396.longitude;
  altitude = other396.altitude;
  speed = other396.speed;
  time = other396.time;
  date = other396.date;
  __isset = other396.__isset;
}
GpsPacket& GpsPacket::operator=(const GpsPacket& other397) {
  errorCode = other397.errorCode;
  latitude = other397.latitude;
  longitude = other397.longitude;
  altitude = other397.altitude;
  speed = other397.speed;
  time = other397.time;
  date = other397.date;
  __isset = other397.__isset;
  return *this;
}
void GpsPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "GpsPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "latitude="; (__isset.latitude ? (out << to_string(latitude)) : (out << "<null>"));
  out << ", " << "longitude="; (__isset.longitude ? (out << to_string(longitude)) : (out << "<null>"));
  out << ", " << "altitude="; (__isset.altitude ? (out << to_string(altitude)) : (out << "<null>"));
  out << ", " << "speed="; (__isset.speed ? (out << to_string(speed)) : (out << "<null>"));
  out << ", " << "time="; (__isset.time ? (out << to_string(time)) : (out << "<null>"));
  out << ", " << "date="; (__isset.date ? (out << to_string(date)) : (out << "<null>"));
  out << ")";
}


NvItem::~NvItem() noexcept {
}


void NvItem::__set_id(const int64_t val) {
  this->id = val;
__isset.id = true;
}

void NvItem::__set_name(const std::string& val) {
  this->name = val;
__isset.name = true;
}

void NvItem::__set_description(const std::string& val) {
  this->description = val;
__isset.description = true;
}

void NvItem::__set_category(const std::string& val) {
  this->category = val;
__isset.category = true;
}
std::ostream& operator<<(std::ostream& out, const NvItem& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t NvItem::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->category);
          this->__isset.category = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t NvItem::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("NvItem");

  if (this->__isset.id) {
    xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->id);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.name) {
    xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->name);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.description) {
    xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->description);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.category) {
    xfer += oprot->writeFieldBegin("category", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->category);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(NvItem &a, NvItem &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.name, b.name);
  swap(a.description, b.description);
  swap(a.category, b.category);
  swap(a.__isset, b.__isset);
}

NvItem::NvItem(const NvItem& other398) {
  id = other398.id;
  name = other398.name;
  description = other398.description;
  category = other398.category;
  __isset = other398.__isset;
}
NvItem& NvItem::operator=(const NvItem& other399) {
  id = other399.id;
  name = other399.name;
  description = other399.description;
  category = other399.category;
  __isset = other399.__isset;
  return *this;
}
void NvItem::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "NvItem(";
  out << "id="; (__isset.id ? (out << to_string(id)) : (out << "<null>"));
  out << ", " << "name="; (__isset.name ? (out << to_string(name)) : (out << "<null>"));
  out << ", " << "description="; (__isset.description ? (out << to_string(description)) : (out << "<null>"));
  out << ", " << "category="; (__isset.category ? (out << to_string(category)) : (out << "<null>"));
  out << ")";
}


MbnNvItemDiffDetails::~MbnNvItemDiffDetails() noexcept {
}


void MbnNvItemDiffDetails::__set_result(const MbnNvItemDiffResult::type val) {
  this->result = val;
}

void MbnNvItemDiffDetails::__set_itemDescriptor(const NvItem& val) {
  this->itemDescriptor = val;
}

void MbnNvItemDiffDetails::__set_index(const int8_t val) {
  this->index = val;
}

void MbnNvItemDiffDetails::__set_mbnPayload(const std::string& val) {
  this->mbnPayload = val;
}

void MbnNvItemDiffDetails::__set_phonePayload(const std::string& val) {
  this->phonePayload = val;
}
std::ostream& operator<<(std::ostream& out, const MbnNvItemDiffDetails& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t MbnNvItemDiffDetails::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast400;
          xfer += iprot->readI32(ecast400);
          this->result = (MbnNvItemDiffResult::type)ecast400;
          this->__isset.result = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->itemDescriptor.read(iprot);
          this->__isset.itemDescriptor = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->index);
          this->__isset.index = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->mbnPayload);
          this->__isset.mbnPayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->phonePayload);
          this->__isset.phonePayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MbnNvItemDiffDetails::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MbnNvItemDiffDetails");

  xfer += oprot->writeFieldBegin("result", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->result);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("itemDescriptor", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->itemDescriptor.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("index", ::apache::thrift::protocol::T_BYTE, 3);
  xfer += oprot->writeByte(this->index);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnPayload", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeBinary(this->mbnPayload);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("phonePayload", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeBinary(this->phonePayload);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MbnNvItemDiffDetails &a, MbnNvItemDiffDetails &b) {
  using ::std::swap;
  swap(a.result, b.result);
  swap(a.itemDescriptor, b.itemDescriptor);
  swap(a.index, b.index);
  swap(a.mbnPayload, b.mbnPayload);
  swap(a.phonePayload, b.phonePayload);
  swap(a.__isset, b.__isset);
}

MbnNvItemDiffDetails::MbnNvItemDiffDetails(const MbnNvItemDiffDetails& other401) {
  result = other401.result;
  itemDescriptor = other401.itemDescriptor;
  index = other401.index;
  mbnPayload = other401.mbnPayload;
  phonePayload = other401.phonePayload;
  __isset = other401.__isset;
}
MbnNvItemDiffDetails& MbnNvItemDiffDetails::operator=(const MbnNvItemDiffDetails& other402) {
  result = other402.result;
  itemDescriptor = other402.itemDescriptor;
  index = other402.index;
  mbnPayload = other402.mbnPayload;
  phonePayload = other402.phonePayload;
  __isset = other402.__isset;
  return *this;
}
void MbnNvItemDiffDetails::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MbnNvItemDiffDetails(";
  out << "result=" << to_string(result);
  out << ", " << "itemDescriptor=" << to_string(itemDescriptor);
  out << ", " << "index=" << to_string(index);
  out << ", " << "mbnPayload=" << to_string(mbnPayload);
  out << ", " << "phonePayload=" << to_string(phonePayload);
  out << ")";
}


MbnNvDiffDetailsPerSub::~MbnNvDiffDetailsPerSub() noexcept {
}


void MbnNvDiffDetailsPerSub::__set_subscriptionId(const int32_t val) {
  this->subscriptionId = val;
}

void MbnNvDiffDetailsPerSub::__set_mbnNvItemDiffDetails(const std::vector<MbnNvItemDiffDetails> & val) {
  this->mbnNvItemDiffDetails = val;
}
std::ostream& operator<<(std::ostream& out, const MbnNvDiffDetailsPerSub& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t MbnNvDiffDetailsPerSub::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->mbnNvItemDiffDetails.clear();
            uint32_t _size403;
            ::apache::thrift::protocol::TType _etype406;
            xfer += iprot->readListBegin(_etype406, _size403);
            this->mbnNvItemDiffDetails.resize(_size403);
            uint32_t _i407;
            for (_i407 = 0; _i407 < _size403; ++_i407)
            {
              xfer += this->mbnNvItemDiffDetails[_i407].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.mbnNvItemDiffDetails = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MbnNvDiffDetailsPerSub::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MbnNvDiffDetailsPerSub");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnNvItemDiffDetails", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->mbnNvItemDiffDetails.size()));
    std::vector<MbnNvItemDiffDetails> ::const_iterator _iter408;
    for (_iter408 = this->mbnNvItemDiffDetails.begin(); _iter408 != this->mbnNvItemDiffDetails.end(); ++_iter408)
    {
      xfer += (*_iter408).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MbnNvDiffDetailsPerSub &a, MbnNvDiffDetailsPerSub &b) {
  using ::std::swap;
  swap(a.subscriptionId, b.subscriptionId);
  swap(a.mbnNvItemDiffDetails, b.mbnNvItemDiffDetails);
  swap(a.__isset, b.__isset);
}

MbnNvDiffDetailsPerSub::MbnNvDiffDetailsPerSub(const MbnNvDiffDetailsPerSub& other409) {
  subscriptionId = other409.subscriptionId;
  mbnNvItemDiffDetails = other409.mbnNvItemDiffDetails;
  __isset = other409.__isset;
}
MbnNvDiffDetailsPerSub& MbnNvDiffDetailsPerSub::operator=(const MbnNvDiffDetailsPerSub& other410) {
  subscriptionId = other410.subscriptionId;
  mbnNvItemDiffDetails = other410.mbnNvItemDiffDetails;
  __isset = other410.__isset;
  return *this;
}
void MbnNvDiffDetailsPerSub::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MbnNvDiffDetailsPerSub(";
  out << "subscriptionId=" << to_string(subscriptionId);
  out << ", " << "mbnNvItemDiffDetails=" << to_string(mbnNvItemDiffDetails);
  out << ")";
}


MbnDiffGroupHeader::~MbnDiffGroupHeader() noexcept {
}


void MbnDiffGroupHeader::__set_groupName(const std::string& val) {
  this->groupName = val;
}

void MbnDiffGroupHeader::__set_path(const std::vector<std::string> & val) {
  this->path = val;
}
std::ostream& operator<<(std::ostream& out, const MbnDiffGroupHeader& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t MbnDiffGroupHeader::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->groupName);
          this->__isset.groupName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->path.clear();
            uint32_t _size411;
            ::apache::thrift::protocol::TType _etype414;
            xfer += iprot->readListBegin(_etype414, _size411);
            this->path.resize(_size411);
            uint32_t _i415;
            for (_i415 = 0; _i415 < _size411; ++_i415)
            {
              xfer += iprot->readString(this->path[_i415]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.path = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MbnDiffGroupHeader::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MbnDiffGroupHeader");

  xfer += oprot->writeFieldBegin("groupName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->groupName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("path", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->path.size()));
    std::vector<std::string> ::const_iterator _iter416;
    for (_iter416 = this->path.begin(); _iter416 != this->path.end(); ++_iter416)
    {
      xfer += oprot->writeString((*_iter416));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MbnDiffGroupHeader &a, MbnDiffGroupHeader &b) {
  using ::std::swap;
  swap(a.groupName, b.groupName);
  swap(a.path, b.path);
  swap(a.__isset, b.__isset);
}

MbnDiffGroupHeader::MbnDiffGroupHeader(const MbnDiffGroupHeader& other417) {
  groupName = other417.groupName;
  path = other417.path;
  __isset = other417.__isset;
}
MbnDiffGroupHeader& MbnDiffGroupHeader::operator=(const MbnDiffGroupHeader& other418) {
  groupName = other418.groupName;
  path = other418.path;
  __isset = other418.__isset;
  return *this;
}
void MbnDiffGroupHeader::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MbnDiffGroupHeader(";
  out << "groupName=" << to_string(groupName);
  out << ", " << "path=" << to_string(path);
  out << ")";
}


MbnDiffResult::~MbnDiffResult() noexcept {
}


void MbnDiffResult::__set_mbnGroupHeader(const MbnDiffGroupHeader& val) {
  this->mbnGroupHeader = val;
}

void MbnDiffResult::__set_phoneGroupHeader(const MbnDiffGroupHeader& val) {
  this->phoneGroupHeader = val;
}

void MbnDiffResult::__set_mbnNvPerSub(const std::vector<MbnNvDiffDetailsPerSub> & val) {
  this->mbnNvPerSub = val;
}
std::ostream& operator<<(std::ostream& out, const MbnDiffResult& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t MbnDiffResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->mbnGroupHeader.read(iprot);
          this->__isset.mbnGroupHeader = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->phoneGroupHeader.read(iprot);
          this->__isset.phoneGroupHeader = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->mbnNvPerSub.clear();
            uint32_t _size419;
            ::apache::thrift::protocol::TType _etype422;
            xfer += iprot->readListBegin(_etype422, _size419);
            this->mbnNvPerSub.resize(_size419);
            uint32_t _i423;
            for (_i423 = 0; _i423 < _size419; ++_i423)
            {
              xfer += this->mbnNvPerSub[_i423].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.mbnNvPerSub = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MbnDiffResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MbnDiffResult");

  xfer += oprot->writeFieldBegin("mbnGroupHeader", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->mbnGroupHeader.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("phoneGroupHeader", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->phoneGroupHeader.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnNvPerSub", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->mbnNvPerSub.size()));
    std::vector<MbnNvDiffDetailsPerSub> ::const_iterator _iter424;
    for (_iter424 = this->mbnNvPerSub.begin(); _iter424 != this->mbnNvPerSub.end(); ++_iter424)
    {
      xfer += (*_iter424).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MbnDiffResult &a, MbnDiffResult &b) {
  using ::std::swap;
  swap(a.mbnGroupHeader, b.mbnGroupHeader);
  swap(a.phoneGroupHeader, b.phoneGroupHeader);
  swap(a.mbnNvPerSub, b.mbnNvPerSub);
  swap(a.__isset, b.__isset);
}

MbnDiffResult::MbnDiffResult(const MbnDiffResult& other425) {
  mbnGroupHeader = other425.mbnGroupHeader;
  phoneGroupHeader = other425.phoneGroupHeader;
  mbnNvPerSub = other425.mbnNvPerSub;
  __isset = other425.__isset;
}
MbnDiffResult& MbnDiffResult::operator=(const MbnDiffResult& other426) {
  mbnGroupHeader = other426.mbnGroupHeader;
  phoneGroupHeader = other426.phoneGroupHeader;
  mbnNvPerSub = other426.mbnNvPerSub;
  __isset = other426.__isset;
  return *this;
}
void MbnDiffResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MbnDiffResult(";
  out << "mbnGroupHeader=" << to_string(mbnGroupHeader);
  out << ", " << "phoneGroupHeader=" << to_string(phoneGroupHeader);
  out << ", " << "mbnNvPerSub=" << to_string(mbnNvPerSub);
  out << ")";
}


NmeaReturnConfig::~NmeaReturnConfig() noexcept {
}


void NmeaReturnConfig::__set_flags(const NmeaReturnFlags::type val) {
  this->flags = val;
}
std::ostream& operator<<(std::ostream& out, const NmeaReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t NmeaReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast427;
          xfer += iprot->readI32(ecast427);
          this->flags = (NmeaReturnFlags::type)ecast427;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t NmeaReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("NmeaReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(NmeaReturnConfig &a, NmeaReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.__isset, b.__isset);
}

NmeaReturnConfig::NmeaReturnConfig(const NmeaReturnConfig& other428) {
  flags = other428.flags;
  __isset = other428.__isset;
}
NmeaReturnConfig& NmeaReturnConfig::operator=(const NmeaReturnConfig& other429) {
  flags = other429.flags;
  __isset = other429.__isset;
  return *this;
}
void NmeaReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "NmeaReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ")";
}


NmeaPacket::~NmeaPacket() noexcept {
}


void NmeaPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void NmeaPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void NmeaPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void NmeaPacket::__set_packetText(const std::string& val) {
  this->packetText = val;
__isset.packetText = true;
}

void NmeaPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void NmeaPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}

void NmeaPacket::__set_packetId(const std::string& val) {
  this->packetId = val;
__isset.packetId = true;
}

void NmeaPacket::__set_binaryPayload(const std::string& val) {
  this->binaryPayload = val;
__isset.binaryPayload = true;
}
std::ostream& operator<<(std::ostream& out, const NmeaPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t NmeaPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast430;
          xfer += iprot->readI32(ecast430);
          this->errorCode = (ErrorCode::type)ecast430;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetText);
          this->__isset.packetText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetId);
          this->__isset.packetId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->binaryPayload);
          this->__isset.binaryPayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t NmeaPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("NmeaPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetText) {
    xfer += oprot->writeFieldBegin("packetText", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->packetText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetId) {
    xfer += oprot->writeFieldBegin("packetId", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->packetId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.binaryPayload) {
    xfer += oprot->writeFieldBegin("binaryPayload", ::apache::thrift::protocol::T_STRING, 8);
    xfer += oprot->writeBinary(this->binaryPayload);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(NmeaPacket &a, NmeaPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.packetText, b.packetText);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.packetId, b.packetId);
  swap(a.binaryPayload, b.binaryPayload);
  swap(a.__isset, b.__isset);
}

NmeaPacket::NmeaPacket(const NmeaPacket& other431) {
  errorCode = other431.errorCode;
  sessionIndex = other431.sessionIndex;
  protocolIndex = other431.protocolIndex;
  packetText = other431.packetText;
  receiveTimeData = other431.receiveTimeData;
  receiveTimeString = other431.receiveTimeString;
  packetId = other431.packetId;
  binaryPayload = other431.binaryPayload;
  __isset = other431.__isset;
}
NmeaPacket& NmeaPacket::operator=(const NmeaPacket& other432) {
  errorCode = other432.errorCode;
  sessionIndex = other432.sessionIndex;
  protocolIndex = other432.protocolIndex;
  packetText = other432.packetText;
  receiveTimeData = other432.receiveTimeData;
  receiveTimeString = other432.receiveTimeString;
  packetId = other432.packetId;
  binaryPayload = other432.binaryPayload;
  __isset = other432.__isset;
  return *this;
}
void NmeaPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "NmeaPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "packetText="; (__isset.packetText ? (out << to_string(packetText)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ", " << "packetId="; (__isset.packetId ? (out << to_string(packetId)) : (out << "<null>"));
  out << ", " << "binaryPayload="; (__isset.binaryPayload ? (out << to_string(binaryPayload)) : (out << "<null>"));
  out << ")";
}


NmeaPacketFilter::~NmeaPacketFilter() noexcept {
}


void NmeaPacketFilter::__set_nameMask(const std::vector<std::string> & val) {
  this->nameMask = val;
__isset.nameMask = true;
}
std::ostream& operator<<(std::ostream& out, const NmeaPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t NmeaPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->nameMask.clear();
            uint32_t _size433;
            ::apache::thrift::protocol::TType _etype436;
            xfer += iprot->readListBegin(_etype436, _size433);
            this->nameMask.resize(_size433);
            uint32_t _i437;
            for (_i437 = 0; _i437 < _size433; ++_i437)
            {
              xfer += iprot->readString(this->nameMask[_i437]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.nameMask = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t NmeaPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("NmeaPacketFilter");

  if (this->__isset.nameMask) {
    xfer += oprot->writeFieldBegin("nameMask", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->nameMask.size()));
      std::vector<std::string> ::const_iterator _iter438;
      for (_iter438 = this->nameMask.begin(); _iter438 != this->nameMask.end(); ++_iter438)
      {
        xfer += oprot->writeString((*_iter438));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(NmeaPacketFilter &a, NmeaPacketFilter &b) {
  using ::std::swap;
  swap(a.nameMask, b.nameMask);
  swap(a.__isset, b.__isset);
}

NmeaPacketFilter::NmeaPacketFilter(const NmeaPacketFilter& other439) {
  nameMask = other439.nameMask;
  __isset = other439.__isset;
}
NmeaPacketFilter& NmeaPacketFilter::operator=(const NmeaPacketFilter& other440) {
  nameMask = other440.nameMask;
  __isset = other440.__isset;
  return *this;
}
void NmeaPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "NmeaPacketFilter(";
  out << "nameMask="; (__isset.nameMask ? (out << to_string(nameMask)) : (out << "<null>"));
  out << ")";
}


QmiUnpackReturn::~QmiUnpackReturn() noexcept {
}


void QmiUnpackReturn::__set_msgName(const std::string& val) {
  this->msgName = val;
__isset.msgName = true;
}

void QmiUnpackReturn::__set_tlvXml(const std::string& val) {
  this->tlvXml = val;
__isset.tlvXml = true;
}
std::ostream& operator<<(std::ostream& out, const QmiUnpackReturn& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmiUnpackReturn::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msgName);
          this->__isset.msgName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->tlvXml);
          this->__isset.tlvXml = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmiUnpackReturn::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmiUnpackReturn");

  if (this->__isset.msgName) {
    xfer += oprot->writeFieldBegin("msgName", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->msgName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.tlvXml) {
    xfer += oprot->writeFieldBegin("tlvXml", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->tlvXml);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmiUnpackReturn &a, QmiUnpackReturn &b) {
  using ::std::swap;
  swap(a.msgName, b.msgName);
  swap(a.tlvXml, b.tlvXml);
  swap(a.__isset, b.__isset);
}

QmiUnpackReturn::QmiUnpackReturn(const QmiUnpackReturn& other441) {
  msgName = other441.msgName;
  tlvXml = other441.tlvXml;
  __isset = other441.__isset;
}
QmiUnpackReturn& QmiUnpackReturn::operator=(const QmiUnpackReturn& other442) {
  msgName = other442.msgName;
  tlvXml = other442.tlvXml;
  __isset = other442.__isset;
  return *this;
}
void QmiUnpackReturn::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmiUnpackReturn(";
  out << "msgName="; (__isset.msgName ? (out << to_string(msgName)) : (out << "<null>"));
  out << ", " << "tlvXml="; (__isset.tlvXml ? (out << to_string(tlvXml)) : (out << "<null>"));
  out << ")";
}


QdssPacketFilter::~QdssPacketFilter() noexcept {
}


void QdssPacketFilter::__set_atIds(const std::vector<int32_t> & val) {
  this->atIds = val;
__isset.atIds = true;
}
std::ostream& operator<<(std::ostream& out, const QdssPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QdssPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->atIds.clear();
            uint32_t _size443;
            ::apache::thrift::protocol::TType _etype446;
            xfer += iprot->readListBegin(_etype446, _size443);
            this->atIds.resize(_size443);
            uint32_t _i447;
            for (_i447 = 0; _i447 < _size443; ++_i447)
            {
              xfer += iprot->readI32(this->atIds[_i447]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.atIds = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QdssPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QdssPacketFilter");

  if (this->__isset.atIds) {
    xfer += oprot->writeFieldBegin("atIds", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->atIds.size()));
      std::vector<int32_t> ::const_iterator _iter448;
      for (_iter448 = this->atIds.begin(); _iter448 != this->atIds.end(); ++_iter448)
      {
        xfer += oprot->writeI32((*_iter448));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QdssPacketFilter &a, QdssPacketFilter &b) {
  using ::std::swap;
  swap(a.atIds, b.atIds);
  swap(a.__isset, b.__isset);
}

QdssPacketFilter::QdssPacketFilter(const QdssPacketFilter& other449) {
  atIds = other449.atIds;
  __isset = other449.__isset;
}
QdssPacketFilter& QdssPacketFilter::operator=(const QdssPacketFilter& other450) {
  atIds = other450.atIds;
  __isset = other450.__isset;
  return *this;
}
void QdssPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QdssPacketFilter(";
  out << "atIds="; (__isset.atIds ? (out << to_string(atIds)) : (out << "<null>"));
  out << ")";
}


QdssReturnConfig::~QdssReturnConfig() noexcept {
}


void QdssReturnConfig::__set_flags(const QdssReturnFlags::type val) {
  this->flags = val;
}
std::ostream& operator<<(std::ostream& out, const QdssReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QdssReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast451;
          xfer += iprot->readI32(ecast451);
          this->flags = (QdssReturnFlags::type)ecast451;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QdssReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QdssReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QdssReturnConfig &a, QdssReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.__isset, b.__isset);
}

QdssReturnConfig::QdssReturnConfig(const QdssReturnConfig& other452) {
  flags = other452.flags;
  __isset = other452.__isset;
}
QdssReturnConfig& QdssReturnConfig::operator=(const QdssReturnConfig& other453) {
  flags = other453.flags;
  __isset = other453.__isset;
  return *this;
}
void QdssReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QdssReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ")";
}


QdssPacket::~QdssPacket() noexcept {
}


void QdssPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void QdssPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void QdssPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void QdssPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void QdssPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}

void QdssPacket::__set_atid(const int8_t val) {
  this->atid = val;
__isset.atid = true;
}

void QdssPacket::__set_binaryPayload(const std::string& val) {
  this->binaryPayload = val;
__isset.binaryPayload = true;
}

void QdssPacket::__set_hwTimeStampData(const int64_t val) {
  this->hwTimeStampData = val;
__isset.hwTimeStampData = true;
}

void QdssPacket::__set_hwTimeStampString(const std::string& val) {
  this->hwTimeStampString = val;
__isset.hwTimeStampString = true;
}

void QdssPacket::__set_channelId(const int16_t val) {
  this->channelId = val;
__isset.channelId = true;
}

void QdssPacket::__set_masterId(const int16_t val) {
  this->masterId = val;
__isset.masterId = true;
}
std::ostream& operator<<(std::ostream& out, const QdssPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QdssPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast454;
          xfer += iprot->readI32(ecast454);
          this->errorCode = (ErrorCode::type)ecast454;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->atid);
          this->__isset.atid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->binaryPayload);
          this->__isset.binaryPayload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->hwTimeStampData);
          this->__isset.hwTimeStampData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->hwTimeStampString);
          this->__isset.hwTimeStampString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->channelId);
          this->__isset.channelId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->masterId);
          this->__isset.masterId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QdssPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QdssPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 4);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.atid) {
    xfer += oprot->writeFieldBegin("atid", ::apache::thrift::protocol::T_BYTE, 6);
    xfer += oprot->writeByte(this->atid);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.binaryPayload) {
    xfer += oprot->writeFieldBegin("binaryPayload", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeBinary(this->binaryPayload);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.hwTimeStampData) {
    xfer += oprot->writeFieldBegin("hwTimeStampData", ::apache::thrift::protocol::T_I64, 8);
    xfer += oprot->writeI64(this->hwTimeStampData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.hwTimeStampString) {
    xfer += oprot->writeFieldBegin("hwTimeStampString", ::apache::thrift::protocol::T_STRING, 9);
    xfer += oprot->writeString(this->hwTimeStampString);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.channelId) {
    xfer += oprot->writeFieldBegin("channelId", ::apache::thrift::protocol::T_I16, 10);
    xfer += oprot->writeI16(this->channelId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.masterId) {
    xfer += oprot->writeFieldBegin("masterId", ::apache::thrift::protocol::T_I16, 11);
    xfer += oprot->writeI16(this->masterId);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QdssPacket &a, QdssPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.atid, b.atid);
  swap(a.binaryPayload, b.binaryPayload);
  swap(a.hwTimeStampData, b.hwTimeStampData);
  swap(a.hwTimeStampString, b.hwTimeStampString);
  swap(a.channelId, b.channelId);
  swap(a.masterId, b.masterId);
  swap(a.__isset, b.__isset);
}

QdssPacket::QdssPacket(const QdssPacket& other455) {
  errorCode = other455.errorCode;
  sessionIndex = other455.sessionIndex;
  protocolIndex = other455.protocolIndex;
  receiveTimeData = other455.receiveTimeData;
  receiveTimeString = other455.receiveTimeString;
  atid = other455.atid;
  binaryPayload = other455.binaryPayload;
  hwTimeStampData = other455.hwTimeStampData;
  hwTimeStampString = other455.hwTimeStampString;
  channelId = other455.channelId;
  masterId = other455.masterId;
  __isset = other455.__isset;
}
QdssPacket& QdssPacket::operator=(const QdssPacket& other456) {
  errorCode = other456.errorCode;
  sessionIndex = other456.sessionIndex;
  protocolIndex = other456.protocolIndex;
  receiveTimeData = other456.receiveTimeData;
  receiveTimeString = other456.receiveTimeString;
  atid = other456.atid;
  binaryPayload = other456.binaryPayload;
  hwTimeStampData = other456.hwTimeStampData;
  hwTimeStampString = other456.hwTimeStampString;
  channelId = other456.channelId;
  masterId = other456.masterId;
  __isset = other456.__isset;
  return *this;
}
void QdssPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QdssPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ", " << "atid="; (__isset.atid ? (out << to_string(atid)) : (out << "<null>"));
  out << ", " << "binaryPayload="; (__isset.binaryPayload ? (out << to_string(binaryPayload)) : (out << "<null>"));
  out << ", " << "hwTimeStampData="; (__isset.hwTimeStampData ? (out << to_string(hwTimeStampData)) : (out << "<null>"));
  out << ", " << "hwTimeStampString="; (__isset.hwTimeStampString ? (out << to_string(hwTimeStampString)) : (out << "<null>"));
  out << ", " << "channelId="; (__isset.channelId ? (out << to_string(channelId)) : (out << "<null>"));
  out << ", " << "masterId="; (__isset.masterId ? (out << to_string(masterId)) : (out << "<null>"));
  out << ")";
}


DunPacketFilter::~DunPacketFilter() noexcept {
}


void DunPacketFilter::__set_commandMask(const std::vector<std::string> & val) {
  this->commandMask = val;
__isset.commandMask = true;
}
std::ostream& operator<<(std::ostream& out, const DunPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DunPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->commandMask.clear();
            uint32_t _size457;
            ::apache::thrift::protocol::TType _etype460;
            xfer += iprot->readListBegin(_etype460, _size457);
            this->commandMask.resize(_size457);
            uint32_t _i461;
            for (_i461 = 0; _i461 < _size457; ++_i461)
            {
              xfer += iprot->readString(this->commandMask[_i461]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.commandMask = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DunPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DunPacketFilter");

  if (this->__isset.commandMask) {
    xfer += oprot->writeFieldBegin("commandMask", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->commandMask.size()));
      std::vector<std::string> ::const_iterator _iter462;
      for (_iter462 = this->commandMask.begin(); _iter462 != this->commandMask.end(); ++_iter462)
      {
        xfer += oprot->writeString((*_iter462));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DunPacketFilter &a, DunPacketFilter &b) {
  using ::std::swap;
  swap(a.commandMask, b.commandMask);
  swap(a.__isset, b.__isset);
}

DunPacketFilter::DunPacketFilter(const DunPacketFilter& other463) {
  commandMask = other463.commandMask;
  __isset = other463.__isset;
}
DunPacketFilter& DunPacketFilter::operator=(const DunPacketFilter& other464) {
  commandMask = other464.commandMask;
  __isset = other464.__isset;
  return *this;
}
void DunPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DunPacketFilter(";
  out << "commandMask="; (__isset.commandMask ? (out << to_string(commandMask)) : (out << "<null>"));
  out << ")";
}


DunReturnConfig::~DunReturnConfig() noexcept {
}


void DunReturnConfig::__set_flags(const DunReturnFlags::type val) {
  this->flags = val;
}
std::ostream& operator<<(std::ostream& out, const DunReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DunReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast465;
          xfer += iprot->readI32(ecast465);
          this->flags = (DunReturnFlags::type)ecast465;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DunReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DunReturnConfig");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DunReturnConfig &a, DunReturnConfig &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.__isset, b.__isset);
}

DunReturnConfig::DunReturnConfig(const DunReturnConfig& other466) {
  flags = other466.flags;
  __isset = other466.__isset;
}
DunReturnConfig& DunReturnConfig::operator=(const DunReturnConfig& other467) {
  flags = other467.flags;
  __isset = other467.__isset;
  return *this;
}
void DunReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DunReturnConfig(";
  out << "flags=" << to_string(flags);
  out << ")";
}


DunPacket::~DunPacket() noexcept {
}


void DunPacket::__set_errorCode(const ErrorCode::type val) {
  this->errorCode = val;
__isset.errorCode = true;
}

void DunPacket::__set_sessionIndex(const int64_t val) {
  this->sessionIndex = val;
__isset.sessionIndex = true;
}

void DunPacket::__set_protocolIndex(const int64_t val) {
  this->protocolIndex = val;
__isset.protocolIndex = true;
}

void DunPacket::__set_packetId(const std::string& val) {
  this->packetId = val;
__isset.packetId = true;
}

void DunPacket::__set_packetText(const std::string& val) {
  this->packetText = val;
__isset.packetText = true;
}

void DunPacket::__set_receiveTimeData(const int64_t val) {
  this->receiveTimeData = val;
__isset.receiveTimeData = true;
}

void DunPacket::__set_receiveTimeString(const std::string& val) {
  this->receiveTimeString = val;
__isset.receiveTimeString = true;
}
std::ostream& operator<<(std::ostream& out, const DunPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DunPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast468;
          xfer += iprot->readI32(ecast468);
          this->errorCode = (ErrorCode::type)ecast468;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionIndex);
          this->__isset.sessionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolIndex);
          this->__isset.protocolIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetId);
          this->__isset.packetId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->packetText);
          this->__isset.packetText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->receiveTimeData);
          this->__isset.receiveTimeData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->receiveTimeString);
          this->__isset.receiveTimeString = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DunPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DunPacket");

  if (this->__isset.errorCode) {
    xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->errorCode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sessionIndex) {
    xfer += oprot->writeFieldBegin("sessionIndex", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->sessionIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolIndex) {
    xfer += oprot->writeFieldBegin("protocolIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->protocolIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetId) {
    xfer += oprot->writeFieldBegin("packetId", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->packetId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.packetText) {
    xfer += oprot->writeFieldBegin("packetText", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->packetText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeData) {
    xfer += oprot->writeFieldBegin("receiveTimeData", ::apache::thrift::protocol::T_I64, 6);
    xfer += oprot->writeI64(this->receiveTimeData);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.receiveTimeString) {
    xfer += oprot->writeFieldBegin("receiveTimeString", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->receiveTimeString);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DunPacket &a, DunPacket &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.sessionIndex, b.sessionIndex);
  swap(a.protocolIndex, b.protocolIndex);
  swap(a.packetId, b.packetId);
  swap(a.packetText, b.packetText);
  swap(a.receiveTimeData, b.receiveTimeData);
  swap(a.receiveTimeString, b.receiveTimeString);
  swap(a.__isset, b.__isset);
}

DunPacket::DunPacket(const DunPacket& other469) {
  errorCode = other469.errorCode;
  sessionIndex = other469.sessionIndex;
  protocolIndex = other469.protocolIndex;
  packetId = other469.packetId;
  packetText = other469.packetText;
  receiveTimeData = other469.receiveTimeData;
  receiveTimeString = other469.receiveTimeString;
  __isset = other469.__isset;
}
DunPacket& DunPacket::operator=(const DunPacket& other470) {
  errorCode = other470.errorCode;
  sessionIndex = other470.sessionIndex;
  protocolIndex = other470.protocolIndex;
  packetId = other470.packetId;
  packetText = other470.packetText;
  receiveTimeData = other470.receiveTimeData;
  receiveTimeString = other470.receiveTimeString;
  __isset = other470.__isset;
  return *this;
}
void DunPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DunPacket(";
  out << "errorCode="; (__isset.errorCode ? (out << to_string(errorCode)) : (out << "<null>"));
  out << ", " << "sessionIndex="; (__isset.sessionIndex ? (out << to_string(sessionIndex)) : (out << "<null>"));
  out << ", " << "protocolIndex="; (__isset.protocolIndex ? (out << to_string(protocolIndex)) : (out << "<null>"));
  out << ", " << "packetId="; (__isset.packetId ? (out << to_string(packetId)) : (out << "<null>"));
  out << ", " << "packetText="; (__isset.packetText ? (out << to_string(packetText)) : (out << "<null>"));
  out << ", " << "receiveTimeData="; (__isset.receiveTimeData ? (out << to_string(receiveTimeData)) : (out << "<null>"));
  out << ", " << "receiveTimeString="; (__isset.receiveTimeString ? (out << to_string(receiveTimeString)) : (out << "<null>"));
  out << ")";
}


DiagPacketIdList::~DiagPacketIdList() noexcept {
}


void DiagPacketIdList::__set_idOrName(const std::vector<std::string> & val) {
  this->idOrName = val;
}
std::ostream& operator<<(std::ostream& out, const DiagPacketIdList& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagPacketIdList::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->idOrName.clear();
            uint32_t _size471;
            ::apache::thrift::protocol::TType _etype474;
            xfer += iprot->readListBegin(_etype474, _size471);
            this->idOrName.resize(_size471);
            uint32_t _i475;
            for (_i475 = 0; _i475 < _size471; ++_i475)
            {
              xfer += iprot->readString(this->idOrName[_i475]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.idOrName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DiagPacketIdList::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagPacketIdList");

  xfer += oprot->writeFieldBegin("idOrName", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->idOrName.size()));
    std::vector<std::string> ::const_iterator _iter476;
    for (_iter476 = this->idOrName.begin(); _iter476 != this->idOrName.end(); ++_iter476)
    {
      xfer += oprot->writeString((*_iter476));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagPacketIdList &a, DiagPacketIdList &b) {
  using ::std::swap;
  swap(a.idOrName, b.idOrName);
  swap(a.__isset, b.__isset);
}

DiagPacketIdList::DiagPacketIdList(const DiagPacketIdList& other477) {
  idOrName = other477.idOrName;
  __isset = other477.__isset;
}
DiagPacketIdList& DiagPacketIdList::operator=(const DiagPacketIdList& other478) {
  idOrName = other478.idOrName;
  __isset = other478.__isset;
  return *this;
}
void DiagPacketIdList::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagPacketIdList(";
  out << "idOrName=" << to_string(idOrName);
  out << ")";
}


DiagPacketMap::~DiagPacketMap() noexcept {
}


void DiagPacketMap::__set_subIdTypeIdMaskMap(const std::map<int32_t, std::map<DiagPacketType::type, DiagPacketIdList> > & val) {
  this->subIdTypeIdMaskMap = val;
}
std::ostream& operator<<(std::ostream& out, const DiagPacketMap& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagPacketMap::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->subIdTypeIdMaskMap.clear();
            uint32_t _size479;
            ::apache::thrift::protocol::TType _ktype480;
            ::apache::thrift::protocol::TType _vtype481;
            xfer += iprot->readMapBegin(_ktype480, _vtype481, _size479);
            uint32_t _i483;
            for (_i483 = 0; _i483 < _size479; ++_i483)
            {
              int32_t _key484;
              xfer += iprot->readI32(_key484);
              std::map<DiagPacketType::type, DiagPacketIdList> & _val485 = this->subIdTypeIdMaskMap[_key484];
              {
                _val485.clear();
                uint32_t _size486;
                ::apache::thrift::protocol::TType _ktype487;
                ::apache::thrift::protocol::TType _vtype488;
                xfer += iprot->readMapBegin(_ktype487, _vtype488, _size486);
                uint32_t _i490;
                for (_i490 = 0; _i490 < _size486; ++_i490)
                {
                  DiagPacketType::type _key491;
                  int32_t ecast493;
                  xfer += iprot->readI32(ecast493);
                  _key491 = (DiagPacketType::type)ecast493;
                  DiagPacketIdList& _val492 = _val485[_key491];
                  xfer += _val492.read(iprot);
                }
                xfer += iprot->readMapEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.subIdTypeIdMaskMap = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DiagPacketMap::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagPacketMap");

  xfer += oprot->writeFieldBegin("subIdTypeIdMaskMap", ::apache::thrift::protocol::T_MAP, 1);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_MAP, static_cast<uint32_t>(this->subIdTypeIdMaskMap.size()));
    std::map<int32_t, std::map<DiagPacketType::type, DiagPacketIdList> > ::const_iterator _iter494;
    for (_iter494 = this->subIdTypeIdMaskMap.begin(); _iter494 != this->subIdTypeIdMaskMap.end(); ++_iter494)
    {
      xfer += oprot->writeI32(_iter494->first);
      {
        xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(_iter494->second.size()));
        std::map<DiagPacketType::type, DiagPacketIdList> ::const_iterator _iter495;
        for (_iter495 = _iter494->second.begin(); _iter495 != _iter494->second.end(); ++_iter495)
        {
          xfer += oprot->writeI32((int32_t)_iter495->first);
          xfer += _iter495->second.write(oprot);
        }
        xfer += oprot->writeMapEnd();
      }
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagPacketMap &a, DiagPacketMap &b) {
  using ::std::swap;
  swap(a.subIdTypeIdMaskMap, b.subIdTypeIdMaskMap);
  swap(a.__isset, b.__isset);
}

DiagPacketMap::DiagPacketMap(const DiagPacketMap& other496) {
  subIdTypeIdMaskMap = other496.subIdTypeIdMaskMap;
  __isset = other496.__isset;
}
DiagPacketMap& DiagPacketMap::operator=(const DiagPacketMap& other497) {
  subIdTypeIdMaskMap = other497.subIdTypeIdMaskMap;
  __isset = other497.__isset;
  return *this;
}
void DiagPacketMap::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagPacketMap(";
  out << "subIdTypeIdMaskMap=" << to_string(subIdTypeIdMaskMap);
  out << ")";
}


QmiConnectionOptions::~QmiConnectionOptions() noexcept {
}


void QmiConnectionOptions::__set_protocolHandle(const int64_t val) {
  this->protocolHandle = val;
__isset.protocolHandle = true;
}
std::ostream& operator<<(std::ostream& out, const QmiConnectionOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmiConnectionOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmiConnectionOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmiConnectionOptions");

  if (this->__isset.protocolHandle) {
    xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->protocolHandle);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmiConnectionOptions &a, QmiConnectionOptions &b) {
  using ::std::swap;
  swap(a.protocolHandle, b.protocolHandle);
  swap(a.__isset, b.__isset);
}

QmiConnectionOptions::QmiConnectionOptions(const QmiConnectionOptions& other498) {
  protocolHandle = other498.protocolHandle;
  __isset = other498.__isset;
}
QmiConnectionOptions& QmiConnectionOptions::operator=(const QmiConnectionOptions& other499) {
  protocolHandle = other499.protocolHandle;
  __isset = other499.__isset;
  return *this;
}
void QmiConnectionOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmiConnectionOptions(";
  out << "protocolHandle="; (__isset.protocolHandle ? (out << to_string(protocolHandle)) : (out << "<null>"));
  out << ")";
}


LogOptions::~LogOptions() noexcept {
}


void LogOptions::__set_level(const LogLevel::type val) {
  this->level = val;
__isset.level = true;
}

void LogOptions::__set_format(const LogFormat::type val) {
  this->format = val;
__isset.format = true;
}

void LogOptions::__set_layout(const std::vector<LogLayout::type> & val) {
  this->layout = val;
__isset.layout = true;
}

void LogOptions::__set_sizeRotationKB(const int32_t val) {
  this->sizeRotationKB = val;
__isset.sizeRotationKB = true;
}

void LogOptions::__set_savePath(const std::string& val) {
  this->savePath = val;
__isset.savePath = true;
}

void LogOptions::__set_maxDataPrintSize(const int32_t val) {
  this->maxDataPrintSize = val;
__isset.maxDataPrintSize = true;
}
std::ostream& operator<<(std::ostream& out, const LogOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t LogOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast500;
          xfer += iprot->readI32(ecast500);
          this->level = (LogLevel::type)ecast500;
          this->__isset.level = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast501;
          xfer += iprot->readI32(ecast501);
          this->format = (LogFormat::type)ecast501;
          this->__isset.format = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->layout.clear();
            uint32_t _size502;
            ::apache::thrift::protocol::TType _etype505;
            xfer += iprot->readListBegin(_etype505, _size502);
            this->layout.resize(_size502);
            uint32_t _i506;
            for (_i506 = 0; _i506 < _size502; ++_i506)
            {
              int32_t ecast507;
              xfer += iprot->readI32(ecast507);
              this->layout[_i506] = (LogLayout::type)ecast507;
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.layout = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->sizeRotationKB);
          this->__isset.sizeRotationKB = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->savePath);
          this->__isset.savePath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->maxDataPrintSize);
          this->__isset.maxDataPrintSize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t LogOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("LogOptions");

  if (this->__isset.level) {
    xfer += oprot->writeFieldBegin("level", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->level);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.format) {
    xfer += oprot->writeFieldBegin("format", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->format);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.layout) {
    xfer += oprot->writeFieldBegin("layout", ::apache::thrift::protocol::T_LIST, 3);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->layout.size()));
      std::vector<LogLayout::type> ::const_iterator _iter508;
      for (_iter508 = this->layout.begin(); _iter508 != this->layout.end(); ++_iter508)
      {
        xfer += oprot->writeI32((int32_t)(*_iter508));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sizeRotationKB) {
    xfer += oprot->writeFieldBegin("sizeRotationKB", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->sizeRotationKB);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.savePath) {
    xfer += oprot->writeFieldBegin("savePath", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->savePath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.maxDataPrintSize) {
    xfer += oprot->writeFieldBegin("maxDataPrintSize", ::apache::thrift::protocol::T_I32, 6);
    xfer += oprot->writeI32(this->maxDataPrintSize);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(LogOptions &a, LogOptions &b) {
  using ::std::swap;
  swap(a.level, b.level);
  swap(a.format, b.format);
  swap(a.layout, b.layout);
  swap(a.sizeRotationKB, b.sizeRotationKB);
  swap(a.savePath, b.savePath);
  swap(a.maxDataPrintSize, b.maxDataPrintSize);
  swap(a.__isset, b.__isset);
}

LogOptions::LogOptions(const LogOptions& other509) {
  level = other509.level;
  format = other509.format;
  layout = other509.layout;
  sizeRotationKB = other509.sizeRotationKB;
  savePath = other509.savePath;
  maxDataPrintSize = other509.maxDataPrintSize;
  __isset = other509.__isset;
}
LogOptions& LogOptions::operator=(const LogOptions& other510) {
  level = other510.level;
  format = other510.format;
  layout = other510.layout;
  sizeRotationKB = other510.sizeRotationKB;
  savePath = other510.savePath;
  maxDataPrintSize = other510.maxDataPrintSize;
  __isset = other510.__isset;
  return *this;
}
void LogOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "LogOptions(";
  out << "level="; (__isset.level ? (out << to_string(level)) : (out << "<null>"));
  out << ", " << "format="; (__isset.format ? (out << to_string(format)) : (out << "<null>"));
  out << ", " << "layout="; (__isset.layout ? (out << to_string(layout)) : (out << "<null>"));
  out << ", " << "sizeRotationKB="; (__isset.sizeRotationKB ? (out << to_string(sizeRotationKB)) : (out << "<null>"));
  out << ", " << "savePath="; (__isset.savePath ? (out << to_string(savePath)) : (out << "<null>"));
  out << ", " << "maxDataPrintSize="; (__isset.maxDataPrintSize ? (out << to_string(maxDataPrintSize)) : (out << "<null>"));
  out << ")";
}


PhoneProperty::~PhoneProperty() noexcept {
}


void PhoneProperty::__set_esn(const int32_t val) {
  this->esn = val;
}

void PhoneProperty::__set_phoneModel(const int32_t val) {
  this->phoneModel = val;
}

void PhoneProperty::__set_nvMajor(const int32_t val) {
  this->nvMajor = val;
}

void PhoneProperty::__set_nvMinor(const int32_t val) {
  this->nvMinor = val;
}

void PhoneProperty::__set_swVersion(const std::string& val) {
  this->swVersion = val;
}

void PhoneProperty::__set_clientName(const std::string& val) {
  this->clientName = val;
}
std::ostream& operator<<(std::ostream& out, const PhoneProperty& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t PhoneProperty::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->esn);
          this->__isset.esn = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->phoneModel);
          this->__isset.phoneModel = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->nvMajor);
          this->__isset.nvMajor = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->nvMinor);
          this->__isset.nvMinor = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->swVersion);
          this->__isset.swVersion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->clientName);
          this->__isset.clientName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t PhoneProperty::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("PhoneProperty");

  xfer += oprot->writeFieldBegin("esn", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->esn);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("phoneModel", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->phoneModel);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("nvMajor", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->nvMajor);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("nvMinor", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->nvMinor);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("swVersion", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->swVersion);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("clientName", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->clientName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PhoneProperty &a, PhoneProperty &b) {
  using ::std::swap;
  swap(a.esn, b.esn);
  swap(a.phoneModel, b.phoneModel);
  swap(a.nvMajor, b.nvMajor);
  swap(a.nvMinor, b.nvMinor);
  swap(a.swVersion, b.swVersion);
  swap(a.clientName, b.clientName);
  swap(a.__isset, b.__isset);
}

PhoneProperty::PhoneProperty(const PhoneProperty& other511) {
  esn = other511.esn;
  phoneModel = other511.phoneModel;
  nvMajor = other511.nvMajor;
  nvMinor = other511.nvMinor;
  swVersion = other511.swVersion;
  clientName = other511.clientName;
  __isset = other511.__isset;
}
PhoneProperty& PhoneProperty::operator=(const PhoneProperty& other512) {
  esn = other512.esn;
  phoneModel = other512.phoneModel;
  nvMajor = other512.nvMajor;
  nvMinor = other512.nvMinor;
  swVersion = other512.swVersion;
  clientName = other512.clientName;
  __isset = other512.__isset;
  return *this;
}
void PhoneProperty::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "PhoneProperty(";
  out << "esn=" << to_string(esn);
  out << ", " << "phoneModel=" << to_string(phoneModel);
  out << ", " << "nvMajor=" << to_string(nvMajor);
  out << ", " << "nvMinor=" << to_string(nvMinor);
  out << ", " << "swVersion=" << to_string(swVersion);
  out << ", " << "clientName=" << to_string(clientName);
  out << ")";
}


QcnHeader::~QcnHeader() noexcept {
}


void QcnHeader::__set_configurationName(const std::string& val) {
  this->configurationName = val;
}

void QcnHeader::__set_fileMajor(const int32_t val) {
  this->fileMajor = val;
}

void QcnHeader::__set_fileMinor(const int32_t val) {
  this->fileMinor = val;
}

void QcnHeader::__set_fileRevision(const int32_t val) {
  this->fileRevision = val;
}

void QcnHeader::__set_phoneProperty(const PhoneProperty& val) {
  this->phoneProperty = val;
}
std::ostream& operator<<(std::ostream& out, const QcnHeader& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnHeader::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->configurationName);
          this->__isset.configurationName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->fileMajor);
          this->__isset.fileMajor = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->fileMinor);
          this->__isset.fileMinor = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->fileRevision);
          this->__isset.fileRevision = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->phoneProperty.read(iprot);
          this->__isset.phoneProperty = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnHeader::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnHeader");

  xfer += oprot->writeFieldBegin("configurationName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->configurationName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("fileMajor", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->fileMajor);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("fileMinor", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->fileMinor);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("fileRevision", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->fileRevision);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("phoneProperty", ::apache::thrift::protocol::T_STRUCT, 5);
  xfer += this->phoneProperty.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnHeader &a, QcnHeader &b) {
  using ::std::swap;
  swap(a.configurationName, b.configurationName);
  swap(a.fileMajor, b.fileMajor);
  swap(a.fileMinor, b.fileMinor);
  swap(a.fileRevision, b.fileRevision);
  swap(a.phoneProperty, b.phoneProperty);
  swap(a.__isset, b.__isset);
}

QcnHeader::QcnHeader(const QcnHeader& other513) {
  configurationName = other513.configurationName;
  fileMajor = other513.fileMajor;
  fileMinor = other513.fileMinor;
  fileRevision = other513.fileRevision;
  phoneProperty = other513.phoneProperty;
  __isset = other513.__isset;
}
QcnHeader& QcnHeader::operator=(const QcnHeader& other514) {
  configurationName = other514.configurationName;
  fileMajor = other514.fileMajor;
  fileMinor = other514.fileMinor;
  fileRevision = other514.fileRevision;
  phoneProperty = other514.phoneProperty;
  __isset = other514.__isset;
  return *this;
}
void QcnHeader::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnHeader(";
  out << "configurationName=" << to_string(configurationName);
  out << ", " << "fileMajor=" << to_string(fileMajor);
  out << ", " << "fileMinor=" << to_string(fileMinor);
  out << ", " << "fileRevision=" << to_string(fileRevision);
  out << ", " << "phoneProperty=" << to_string(phoneProperty);
  out << ")";
}


QcnItemDiffDetails::~QcnItemDiffDetails() noexcept {
}


void QcnItemDiffDetails::__set_result(const QcnItemDiffResult::type val) {
  this->result = val;
}

void QcnItemDiffDetails::__set_nvId(const int32_t val) {
  this->nvId = val;
}

void QcnItemDiffDetails::__set_subscriptionId(const int32_t val) {
  this->subscriptionId = val;
}

void QcnItemDiffDetails::__set_index(const int32_t val) {
  this->index = val;
}

void QcnItemDiffDetails::__set_efsFilePath(const std::string& val) {
  this->efsFilePath = val;
}

void QcnItemDiffDetails::__set_payload1(const std::string& val) {
  this->payload1 = val;
}

void QcnItemDiffDetails::__set_payload2(const std::string& val) {
  this->payload2 = val;
}
std::ostream& operator<<(std::ostream& out, const QcnItemDiffDetails& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnItemDiffDetails::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast515;
          xfer += iprot->readI32(ecast515);
          this->result = (QcnItemDiffResult::type)ecast515;
          this->__isset.result = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->nvId);
          this->__isset.nvId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->index);
          this->__isset.index = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->efsFilePath);
          this->__isset.efsFilePath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload1);
          this->__isset.payload1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload2);
          this->__isset.payload2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnItemDiffDetails::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnItemDiffDetails");

  xfer += oprot->writeFieldBegin("result", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->result);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("nvId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->nvId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("index", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->index);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsFilePath", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->efsFilePath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload1", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeBinary(this->payload1);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload2", ::apache::thrift::protocol::T_STRING, 7);
  xfer += oprot->writeBinary(this->payload2);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnItemDiffDetails &a, QcnItemDiffDetails &b) {
  using ::std::swap;
  swap(a.result, b.result);
  swap(a.nvId, b.nvId);
  swap(a.subscriptionId, b.subscriptionId);
  swap(a.index, b.index);
  swap(a.efsFilePath, b.efsFilePath);
  swap(a.payload1, b.payload1);
  swap(a.payload2, b.payload2);
  swap(a.__isset, b.__isset);
}

QcnItemDiffDetails::QcnItemDiffDetails(const QcnItemDiffDetails& other516) {
  result = other516.result;
  nvId = other516.nvId;
  subscriptionId = other516.subscriptionId;
  index = other516.index;
  efsFilePath = other516.efsFilePath;
  payload1 = other516.payload1;
  payload2 = other516.payload2;
  __isset = other516.__isset;
}
QcnItemDiffDetails& QcnItemDiffDetails::operator=(const QcnItemDiffDetails& other517) {
  result = other517.result;
  nvId = other517.nvId;
  subscriptionId = other517.subscriptionId;
  index = other517.index;
  efsFilePath = other517.efsFilePath;
  payload1 = other517.payload1;
  payload2 = other517.payload2;
  __isset = other517.__isset;
  return *this;
}
void QcnItemDiffDetails::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnItemDiffDetails(";
  out << "result=" << to_string(result);
  out << ", " << "nvId=" << to_string(nvId);
  out << ", " << "subscriptionId=" << to_string(subscriptionId);
  out << ", " << "index=" << to_string(index);
  out << ", " << "efsFilePath=" << to_string(efsFilePath);
  out << ", " << "payload1=" << to_string(payload1);
  out << ", " << "payload2=" << to_string(payload2);
  out << ")";
}


QcnFeatureMaskDiffDetails::~QcnFeatureMaskDiffDetails() noexcept {
}


void QcnFeatureMaskDiffDetails::__set_result(const QcnItemDiffResult::type val) {
  this->result = val;
}

void QcnFeatureMaskDiffDetails::__set_payload1(const std::string& val) {
  this->payload1 = val;
}

void QcnFeatureMaskDiffDetails::__set_payload2(const std::string& val) {
  this->payload2 = val;
}
std::ostream& operator<<(std::ostream& out, const QcnFeatureMaskDiffDetails& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnFeatureMaskDiffDetails::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast518;
          xfer += iprot->readI32(ecast518);
          this->result = (QcnItemDiffResult::type)ecast518;
          this->__isset.result = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload1);
          this->__isset.payload1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload2);
          this->__isset.payload2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnFeatureMaskDiffDetails::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnFeatureMaskDiffDetails");

  xfer += oprot->writeFieldBegin("result", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->result);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload1", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->payload1);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload2", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeBinary(this->payload2);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnFeatureMaskDiffDetails &a, QcnFeatureMaskDiffDetails &b) {
  using ::std::swap;
  swap(a.result, b.result);
  swap(a.payload1, b.payload1);
  swap(a.payload2, b.payload2);
  swap(a.__isset, b.__isset);
}

QcnFeatureMaskDiffDetails::QcnFeatureMaskDiffDetails(const QcnFeatureMaskDiffDetails& other519) {
  result = other519.result;
  payload1 = other519.payload1;
  payload2 = other519.payload2;
  __isset = other519.__isset;
}
QcnFeatureMaskDiffDetails& QcnFeatureMaskDiffDetails::operator=(const QcnFeatureMaskDiffDetails& other520) {
  result = other520.result;
  payload1 = other520.payload1;
  payload2 = other520.payload2;
  __isset = other520.__isset;
  return *this;
}
void QcnFeatureMaskDiffDetails::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnFeatureMaskDiffDetails(";
  out << "result=" << to_string(result);
  out << ", " << "payload1=" << to_string(payload1);
  out << ", " << "payload2=" << to_string(payload2);
  out << ")";
}


QcnPrlDiffDetails::~QcnPrlDiffDetails() noexcept {
}


void QcnPrlDiffDetails::__set_result(const QcnItemDiffResult::type val) {
  this->result = val;
}

void QcnPrlDiffDetails::__set_subscriptionId(const int32_t val) {
  this->subscriptionId = val;
}

void QcnPrlDiffDetails::__set_nam(const int32_t val) {
  this->nam = val;
}

void QcnPrlDiffDetails::__set_payload1(const std::string& val) {
  this->payload1 = val;
}

void QcnPrlDiffDetails::__set_payload2(const std::string& val) {
  this->payload2 = val;
}
std::ostream& operator<<(std::ostream& out, const QcnPrlDiffDetails& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnPrlDiffDetails::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast521;
          xfer += iprot->readI32(ecast521);
          this->result = (QcnItemDiffResult::type)ecast521;
          this->__isset.result = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->nam);
          this->__isset.nam = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload1);
          this->__isset.payload1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload2);
          this->__isset.payload2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnPrlDiffDetails::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnPrlDiffDetails");

  xfer += oprot->writeFieldBegin("result", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->result);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("nam", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->nam);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload1", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeBinary(this->payload1);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload2", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeBinary(this->payload2);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnPrlDiffDetails &a, QcnPrlDiffDetails &b) {
  using ::std::swap;
  swap(a.result, b.result);
  swap(a.subscriptionId, b.subscriptionId);
  swap(a.nam, b.nam);
  swap(a.payload1, b.payload1);
  swap(a.payload2, b.payload2);
  swap(a.__isset, b.__isset);
}

QcnPrlDiffDetails::QcnPrlDiffDetails(const QcnPrlDiffDetails& other522) {
  result = other522.result;
  subscriptionId = other522.subscriptionId;
  nam = other522.nam;
  payload1 = other522.payload1;
  payload2 = other522.payload2;
  __isset = other522.__isset;
}
QcnPrlDiffDetails& QcnPrlDiffDetails::operator=(const QcnPrlDiffDetails& other523) {
  result = other523.result;
  subscriptionId = other523.subscriptionId;
  nam = other523.nam;
  payload1 = other523.payload1;
  payload2 = other523.payload2;
  __isset = other523.__isset;
  return *this;
}
void QcnPrlDiffDetails::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnPrlDiffDetails(";
  out << "result=" << to_string(result);
  out << ", " << "subscriptionId=" << to_string(subscriptionId);
  out << ", " << "nam=" << to_string(nam);
  out << ", " << "payload1=" << to_string(payload1);
  out << ", " << "payload2=" << to_string(payload2);
  out << ")";
}


QcnDiffResult::~QcnDiffResult() noexcept {
}


void QcnDiffResult::__set_header1(const QcnHeader& val) {
  this->header1 = val;
}

void QcnDiffResult::__set_header2(const QcnHeader& val) {
  this->header2 = val;
}

void QcnDiffResult::__set_featureMask(const QcnFeatureMaskDiffDetails& val) {
  this->featureMask = val;
}

void QcnDiffResult::__set_prls(const std::vector<QcnPrlDiffDetails> & val) {
  this->prls = val;
}

void QcnDiffResult::__set_items(const std::vector<QcnItemDiffDetails> & val) {
  this->items = val;
}
std::ostream& operator<<(std::ostream& out, const QcnDiffResult& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnDiffResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->header1.read(iprot);
          this->__isset.header1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->header2.read(iprot);
          this->__isset.header2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->featureMask.read(iprot);
          this->__isset.featureMask = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->prls.clear();
            uint32_t _size524;
            ::apache::thrift::protocol::TType _etype527;
            xfer += iprot->readListBegin(_etype527, _size524);
            this->prls.resize(_size524);
            uint32_t _i528;
            for (_i528 = 0; _i528 < _size524; ++_i528)
            {
              xfer += this->prls[_i528].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.prls = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->items.clear();
            uint32_t _size529;
            ::apache::thrift::protocol::TType _etype532;
            xfer += iprot->readListBegin(_etype532, _size529);
            this->items.resize(_size529);
            uint32_t _i533;
            for (_i533 = 0; _i533 < _size529; ++_i533)
            {
              xfer += this->items[_i533].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.items = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnDiffResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnDiffResult");

  xfer += oprot->writeFieldBegin("header1", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->header1.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("header2", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->header2.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("featureMask", ::apache::thrift::protocol::T_STRUCT, 3);
  xfer += this->featureMask.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("prls", ::apache::thrift::protocol::T_LIST, 4);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->prls.size()));
    std::vector<QcnPrlDiffDetails> ::const_iterator _iter534;
    for (_iter534 = this->prls.begin(); _iter534 != this->prls.end(); ++_iter534)
    {
      xfer += (*_iter534).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("items", ::apache::thrift::protocol::T_LIST, 5);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->items.size()));
    std::vector<QcnItemDiffDetails> ::const_iterator _iter535;
    for (_iter535 = this->items.begin(); _iter535 != this->items.end(); ++_iter535)
    {
      xfer += (*_iter535).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnDiffResult &a, QcnDiffResult &b) {
  using ::std::swap;
  swap(a.header1, b.header1);
  swap(a.header2, b.header2);
  swap(a.featureMask, b.featureMask);
  swap(a.prls, b.prls);
  swap(a.items, b.items);
  swap(a.__isset, b.__isset);
}

QcnDiffResult::QcnDiffResult(const QcnDiffResult& other536) {
  header1 = other536.header1;
  header2 = other536.header2;
  featureMask = other536.featureMask;
  prls = other536.prls;
  items = other536.items;
  __isset = other536.__isset;
}
QcnDiffResult& QcnDiffResult::operator=(const QcnDiffResult& other537) {
  header1 = other537.header1;
  header2 = other537.header2;
  featureMask = other537.featureMask;
  prls = other537.prls;
  items = other537.items;
  __isset = other537.__isset;
  return *this;
}
void QcnDiffResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnDiffResult(";
  out << "header1=" << to_string(header1);
  out << ", " << "header2=" << to_string(header2);
  out << ", " << "featureMask=" << to_string(featureMask);
  out << ", " << "prls=" << to_string(prls);
  out << ", " << "items=" << to_string(items);
  out << ")";
}


QcnPrl::~QcnPrl() noexcept {
}


void QcnPrl::__set_nam(const int32_t val) {
  this->nam = val;
}

void QcnPrl::__set_payload(const std::string& val) {
  this->payload = val;
}
std::ostream& operator<<(std::ostream& out, const QcnPrl& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnPrl::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->nam);
          this->__isset.nam = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload);
          this->__isset.payload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnPrl::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnPrl");

  xfer += oprot->writeFieldBegin("nam", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->nam);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->payload);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnPrl &a, QcnPrl &b) {
  using ::std::swap;
  swap(a.nam, b.nam);
  swap(a.payload, b.payload);
  swap(a.__isset, b.__isset);
}

QcnPrl::QcnPrl(const QcnPrl& other538) {
  nam = other538.nam;
  payload = other538.payload;
  __isset = other538.__isset;
}
QcnPrl& QcnPrl::operator=(const QcnPrl& other539) {
  nam = other539.nam;
  payload = other539.payload;
  __isset = other539.__isset;
  return *this;
}
void QcnPrl::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnPrl(";
  out << "nam=" << to_string(nam);
  out << ", " << "payload=" << to_string(payload);
  out << ")";
}


QcnPrlList::~QcnPrlList() noexcept {
}


void QcnPrlList::__set_subscriptionId(const int32_t val) {
  this->subscriptionId = val;
}

void QcnPrlList::__set_prls(const std::vector<QcnPrl> & val) {
  this->prls = val;
}
std::ostream& operator<<(std::ostream& out, const QcnPrlList& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnPrlList::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->prls.clear();
            uint32_t _size540;
            ::apache::thrift::protocol::TType _etype543;
            xfer += iprot->readListBegin(_etype543, _size540);
            this->prls.resize(_size540);
            uint32_t _i544;
            for (_i544 = 0; _i544 < _size540; ++_i544)
            {
              xfer += this->prls[_i544].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.prls = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnPrlList::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnPrlList");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("prls", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->prls.size()));
    std::vector<QcnPrl> ::const_iterator _iter545;
    for (_iter545 = this->prls.begin(); _iter545 != this->prls.end(); ++_iter545)
    {
      xfer += (*_iter545).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnPrlList &a, QcnPrlList &b) {
  using ::std::swap;
  swap(a.subscriptionId, b.subscriptionId);
  swap(a.prls, b.prls);
  swap(a.__isset, b.__isset);
}

QcnPrlList::QcnPrlList(const QcnPrlList& other546) {
  subscriptionId = other546.subscriptionId;
  prls = other546.prls;
  __isset = other546.__isset;
}
QcnPrlList& QcnPrlList::operator=(const QcnPrlList& other547) {
  subscriptionId = other547.subscriptionId;
  prls = other547.prls;
  __isset = other547.__isset;
  return *this;
}
void QcnPrlList::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnPrlList(";
  out << "subscriptionId=" << to_string(subscriptionId);
  out << ", " << "prls=" << to_string(prls);
  out << ")";
}


QcnNumberedNv::~QcnNumberedNv() noexcept {
}


void QcnNumberedNv::__set_nvId(const int32_t val) {
  this->nvId = val;
}

void QcnNumberedNv::__set_index(const int8_t val) {
  this->index = val;
}

void QcnNumberedNv::__set_payload(const std::string& val) {
  this->payload = val;
}
std::ostream& operator<<(std::ostream& out, const QcnNumberedNv& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnNumberedNv::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->nvId);
          this->__isset.nvId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->index);
          this->__isset.index = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload);
          this->__isset.payload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnNumberedNv::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnNumberedNv");

  xfer += oprot->writeFieldBegin("nvId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->nvId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("index", ::apache::thrift::protocol::T_BYTE, 2);
  xfer += oprot->writeByte(this->index);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeBinary(this->payload);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnNumberedNv &a, QcnNumberedNv &b) {
  using ::std::swap;
  swap(a.nvId, b.nvId);
  swap(a.index, b.index);
  swap(a.payload, b.payload);
  swap(a.__isset, b.__isset);
}

QcnNumberedNv::QcnNumberedNv(const QcnNumberedNv& other548) {
  nvId = other548.nvId;
  index = other548.index;
  payload = other548.payload;
  __isset = other548.__isset;
}
QcnNumberedNv& QcnNumberedNv::operator=(const QcnNumberedNv& other549) {
  nvId = other549.nvId;
  index = other549.index;
  payload = other549.payload;
  __isset = other549.__isset;
  return *this;
}
void QcnNumberedNv::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnNumberedNv(";
  out << "nvId=" << to_string(nvId);
  out << ", " << "index=" << to_string(index);
  out << ", " << "payload=" << to_string(payload);
  out << ")";
}


QcnNumberedNvList::~QcnNumberedNvList() noexcept {
}


void QcnNumberedNvList::__set_subscriptionId(const int32_t val) {
  this->subscriptionId = val;
}

void QcnNumberedNvList::__set_nvs(const std::vector<QcnNumberedNv> & val) {
  this->nvs = val;
}
std::ostream& operator<<(std::ostream& out, const QcnNumberedNvList& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnNumberedNvList::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->nvs.clear();
            uint32_t _size550;
            ::apache::thrift::protocol::TType _etype553;
            xfer += iprot->readListBegin(_etype553, _size550);
            this->nvs.resize(_size550);
            uint32_t _i554;
            for (_i554 = 0; _i554 < _size550; ++_i554)
            {
              xfer += this->nvs[_i554].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.nvs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnNumberedNvList::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnNumberedNvList");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("nvs", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->nvs.size()));
    std::vector<QcnNumberedNv> ::const_iterator _iter555;
    for (_iter555 = this->nvs.begin(); _iter555 != this->nvs.end(); ++_iter555)
    {
      xfer += (*_iter555).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnNumberedNvList &a, QcnNumberedNvList &b) {
  using ::std::swap;
  swap(a.subscriptionId, b.subscriptionId);
  swap(a.nvs, b.nvs);
  swap(a.__isset, b.__isset);
}

QcnNumberedNvList::QcnNumberedNvList(const QcnNumberedNvList& other556) {
  subscriptionId = other556.subscriptionId;
  nvs = other556.nvs;
  __isset = other556.__isset;
}
QcnNumberedNvList& QcnNumberedNvList::operator=(const QcnNumberedNvList& other557) {
  subscriptionId = other557.subscriptionId;
  nvs = other557.nvs;
  __isset = other557.__isset;
  return *this;
}
void QcnNumberedNvList::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnNumberedNvList(";
  out << "subscriptionId=" << to_string(subscriptionId);
  out << ", " << "nvs=" << to_string(nvs);
  out << ")";
}


QcnEfsFile::~QcnEfsFile() noexcept {
}


void QcnEfsFile::__set_efsPath(const std::string& val) {
  this->efsPath = val;
}

void QcnEfsFile::__set_flags(const int16_t val) {
  this->flags = val;
}

void QcnEfsFile::__set_bufferingOption(const int8_t val) {
  this->bufferingOption = val;
}

void QcnEfsFile::__set_cleanupOption(const int8_t val) {
  this->cleanupOption = val;
}

void QcnEfsFile::__set_fileCreationTimeStamp(const int32_t val) {
  this->fileCreationTimeStamp = val;
}

void QcnEfsFile::__set_payload(const std::string& val) {
  this->payload = val;
}
std::ostream& operator<<(std::ostream& out, const QcnEfsFile& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnEfsFile::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->efsPath);
          this->__isset.efsPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->flags);
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->bufferingOption);
          this->__isset.bufferingOption = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->cleanupOption);
          this->__isset.cleanupOption = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->fileCreationTimeStamp);
          this->__isset.fileCreationTimeStamp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload);
          this->__isset.payload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnEfsFile::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnEfsFile");

  xfer += oprot->writeFieldBegin("efsPath", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->efsPath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I16, 2);
  xfer += oprot->writeI16(this->flags);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("bufferingOption", ::apache::thrift::protocol::T_BYTE, 3);
  xfer += oprot->writeByte(this->bufferingOption);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("cleanupOption", ::apache::thrift::protocol::T_BYTE, 4);
  xfer += oprot->writeByte(this->cleanupOption);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("fileCreationTimeStamp", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32(this->fileCreationTimeStamp);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeBinary(this->payload);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnEfsFile &a, QcnEfsFile &b) {
  using ::std::swap;
  swap(a.efsPath, b.efsPath);
  swap(a.flags, b.flags);
  swap(a.bufferingOption, b.bufferingOption);
  swap(a.cleanupOption, b.cleanupOption);
  swap(a.fileCreationTimeStamp, b.fileCreationTimeStamp);
  swap(a.payload, b.payload);
  swap(a.__isset, b.__isset);
}

QcnEfsFile::QcnEfsFile(const QcnEfsFile& other558) {
  efsPath = other558.efsPath;
  flags = other558.flags;
  bufferingOption = other558.bufferingOption;
  cleanupOption = other558.cleanupOption;
  fileCreationTimeStamp = other558.fileCreationTimeStamp;
  payload = other558.payload;
  __isset = other558.__isset;
}
QcnEfsFile& QcnEfsFile::operator=(const QcnEfsFile& other559) {
  efsPath = other559.efsPath;
  flags = other559.flags;
  bufferingOption = other559.bufferingOption;
  cleanupOption = other559.cleanupOption;
  fileCreationTimeStamp = other559.fileCreationTimeStamp;
  payload = other559.payload;
  __isset = other559.__isset;
  return *this;
}
void QcnEfsFile::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnEfsFile(";
  out << "efsPath=" << to_string(efsPath);
  out << ", " << "flags=" << to_string(flags);
  out << ", " << "bufferingOption=" << to_string(bufferingOption);
  out << ", " << "cleanupOption=" << to_string(cleanupOption);
  out << ", " << "fileCreationTimeStamp=" << to_string(fileCreationTimeStamp);
  out << ", " << "payload=" << to_string(payload);
  out << ")";
}


QcnEfsItem::~QcnEfsItem() noexcept {
}


void QcnEfsItem::__set_efsPath(const std::string& val) {
  this->efsPath = val;
}

void QcnEfsItem::__set_payload(const std::string& val) {
  this->payload = val;
}
std::ostream& operator<<(std::ostream& out, const QcnEfsItem& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnEfsItem::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->efsPath);
          this->__isset.efsPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload);
          this->__isset.payload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnEfsItem::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnEfsItem");

  xfer += oprot->writeFieldBegin("efsPath", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->efsPath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->payload);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnEfsItem &a, QcnEfsItem &b) {
  using ::std::swap;
  swap(a.efsPath, b.efsPath);
  swap(a.payload, b.payload);
  swap(a.__isset, b.__isset);
}

QcnEfsItem::QcnEfsItem(const QcnEfsItem& other560) {
  efsPath = other560.efsPath;
  payload = other560.payload;
  __isset = other560.__isset;
}
QcnEfsItem& QcnEfsItem::operator=(const QcnEfsItem& other561) {
  efsPath = other561.efsPath;
  payload = other561.payload;
  __isset = other561.__isset;
  return *this;
}
void QcnEfsItem::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnEfsItem(";
  out << "efsPath=" << to_string(efsPath);
  out << ", " << "payload=" << to_string(payload);
  out << ")";
}


QcnEfsItemList::~QcnEfsItemList() noexcept {
}


void QcnEfsItemList::__set_subscriptionId(const int32_t val) {
  this->subscriptionId = val;
}

void QcnEfsItemList::__set_efsItems(const std::vector<QcnEfsItem> & val) {
  this->efsItems = val;
}
std::ostream& operator<<(std::ostream& out, const QcnEfsItemList& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnEfsItemList::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->efsItems.clear();
            uint32_t _size562;
            ::apache::thrift::protocol::TType _etype565;
            xfer += iprot->readListBegin(_etype565, _size562);
            this->efsItems.resize(_size562);
            uint32_t _i566;
            for (_i566 = 0; _i566 < _size562; ++_i566)
            {
              xfer += this->efsItems[_i566].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.efsItems = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnEfsItemList::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnEfsItemList");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsItems", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->efsItems.size()));
    std::vector<QcnEfsItem> ::const_iterator _iter567;
    for (_iter567 = this->efsItems.begin(); _iter567 != this->efsItems.end(); ++_iter567)
    {
      xfer += (*_iter567).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnEfsItemList &a, QcnEfsItemList &b) {
  using ::std::swap;
  swap(a.subscriptionId, b.subscriptionId);
  swap(a.efsItems, b.efsItems);
  swap(a.__isset, b.__isset);
}

QcnEfsItemList::QcnEfsItemList(const QcnEfsItemList& other568) {
  subscriptionId = other568.subscriptionId;
  efsItems = other568.efsItems;
  __isset = other568.__isset;
}
QcnEfsItemList& QcnEfsItemList::operator=(const QcnEfsItemList& other569) {
  subscriptionId = other569.subscriptionId;
  efsItems = other569.efsItems;
  __isset = other569.__isset;
  return *this;
}
void QcnEfsItemList::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnEfsItemList(";
  out << "subscriptionId=" << to_string(subscriptionId);
  out << ", " << "efsItems=" << to_string(efsItems);
  out << ")";
}


QcnContent::~QcnContent() noexcept {
}


void QcnContent::__set_header(const QcnHeader& val) {
  this->header = val;
}

void QcnContent::__set_featureMask(const std::string& val) {
  this->featureMask = val;
}

void QcnContent::__set_prlLists(const std::vector<QcnPrlList> & val) {
  this->prlLists = val;
}

void QcnContent::__set_nvLists(const std::vector<QcnNumberedNvList> & val) {
  this->nvLists = val;
}

void QcnContent::__set_efsItemLists(const std::vector<QcnEfsItemList> & val) {
  this->efsItemLists = val;
}

void QcnContent::__set_efsFiles(const std::vector<QcnEfsFile> & val) {
  this->efsFiles = val;
}
std::ostream& operator<<(std::ostream& out, const QcnContent& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QcnContent::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->header.read(iprot);
          this->__isset.header = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->featureMask);
          this->__isset.featureMask = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->prlLists.clear();
            uint32_t _size570;
            ::apache::thrift::protocol::TType _etype573;
            xfer += iprot->readListBegin(_etype573, _size570);
            this->prlLists.resize(_size570);
            uint32_t _i574;
            for (_i574 = 0; _i574 < _size570; ++_i574)
            {
              xfer += this->prlLists[_i574].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.prlLists = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->nvLists.clear();
            uint32_t _size575;
            ::apache::thrift::protocol::TType _etype578;
            xfer += iprot->readListBegin(_etype578, _size575);
            this->nvLists.resize(_size575);
            uint32_t _i579;
            for (_i579 = 0; _i579 < _size575; ++_i579)
            {
              xfer += this->nvLists[_i579].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.nvLists = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->efsItemLists.clear();
            uint32_t _size580;
            ::apache::thrift::protocol::TType _etype583;
            xfer += iprot->readListBegin(_etype583, _size580);
            this->efsItemLists.resize(_size580);
            uint32_t _i584;
            for (_i584 = 0; _i584 < _size580; ++_i584)
            {
              xfer += this->efsItemLists[_i584].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.efsItemLists = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->efsFiles.clear();
            uint32_t _size585;
            ::apache::thrift::protocol::TType _etype588;
            xfer += iprot->readListBegin(_etype588, _size585);
            this->efsFiles.resize(_size585);
            uint32_t _i589;
            for (_i589 = 0; _i589 < _size585; ++_i589)
            {
              xfer += this->efsFiles[_i589].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.efsFiles = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QcnContent::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QcnContent");

  xfer += oprot->writeFieldBegin("header", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->header.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("featureMask", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->featureMask);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("prlLists", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->prlLists.size()));
    std::vector<QcnPrlList> ::const_iterator _iter590;
    for (_iter590 = this->prlLists.begin(); _iter590 != this->prlLists.end(); ++_iter590)
    {
      xfer += (*_iter590).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("nvLists", ::apache::thrift::protocol::T_LIST, 4);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->nvLists.size()));
    std::vector<QcnNumberedNvList> ::const_iterator _iter591;
    for (_iter591 = this->nvLists.begin(); _iter591 != this->nvLists.end(); ++_iter591)
    {
      xfer += (*_iter591).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsItemLists", ::apache::thrift::protocol::T_LIST, 5);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->efsItemLists.size()));
    std::vector<QcnEfsItemList> ::const_iterator _iter592;
    for (_iter592 = this->efsItemLists.begin(); _iter592 != this->efsItemLists.end(); ++_iter592)
    {
      xfer += (*_iter592).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsFiles", ::apache::thrift::protocol::T_LIST, 6);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->efsFiles.size()));
    std::vector<QcnEfsFile> ::const_iterator _iter593;
    for (_iter593 = this->efsFiles.begin(); _iter593 != this->efsFiles.end(); ++_iter593)
    {
      xfer += (*_iter593).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QcnContent &a, QcnContent &b) {
  using ::std::swap;
  swap(a.header, b.header);
  swap(a.featureMask, b.featureMask);
  swap(a.prlLists, b.prlLists);
  swap(a.nvLists, b.nvLists);
  swap(a.efsItemLists, b.efsItemLists);
  swap(a.efsFiles, b.efsFiles);
  swap(a.__isset, b.__isset);
}

QcnContent::QcnContent(const QcnContent& other594) {
  header = other594.header;
  featureMask = other594.featureMask;
  prlLists = other594.prlLists;
  nvLists = other594.nvLists;
  efsItemLists = other594.efsItemLists;
  efsFiles = other594.efsFiles;
  __isset = other594.__isset;
}
QcnContent& QcnContent::operator=(const QcnContent& other595) {
  header = other595.header;
  featureMask = other595.featureMask;
  prlLists = other595.prlLists;
  nvLists = other595.nvLists;
  efsItemLists = other595.efsItemLists;
  efsFiles = other595.efsFiles;
  __isset = other595.__isset;
  return *this;
}
void QcnContent::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QcnContent(";
  out << "header=" << to_string(header);
  out << ", " << "featureMask=" << to_string(featureMask);
  out << ", " << "prlLists=" << to_string(prlLists);
  out << ", " << "nvLists=" << to_string(nvLists);
  out << ", " << "efsItemLists=" << to_string(efsItemLists);
  out << ", " << "efsFiles=" << to_string(efsFiles);
  out << ")";
}


ProtocolConfiguration::~ProtocolConfiguration() noexcept {
}


void ProtocolConfiguration::__set_protocolHandle(const int64_t val) {
  this->protocolHandle = val;
}

void ProtocolConfiguration::__set_overrideProtocolType(const ProtocolType::type val) {
  this->overrideProtocolType = val;
__isset.overrideProtocolType = true;
}

void ProtocolConfiguration::__set_baudRate(const BaudRate::type val) {
  this->baudRate = val;
__isset.baudRate = true;
}

void ProtocolConfiguration::__set_timeout(const int64_t val) {
  this->timeout = val;
__isset.timeout = true;
}

void ProtocolConfiguration::__set_enableHdlcOnly(const bool val) {
  this->enableHdlcOnly = val;
__isset.enableHdlcOnly = true;
}

void ProtocolConfiguration::__set_blockingLogMaskClearOnConnection(const bool val) {
  this->blockingLogMaskClearOnConnection = val;
__isset.blockingLogMaskClearOnConnection = true;
}

void ProtocolConfiguration::__set_clearLogMaskOnDisconnect(const bool val) {
  this->clearLogMaskOnDisconnect = val;
__isset.clearLogMaskOnDisconnect = true;
}

void ProtocolConfiguration::__set_disablePolling(const bool val) {
  this->disablePolling = val;
__isset.disablePolling = true;
}
std::ostream& operator<<(std::ostream& out, const ProtocolConfiguration& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProtocolConfiguration::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast596;
          xfer += iprot->readI32(ecast596);
          this->overrideProtocolType = (ProtocolType::type)ecast596;
          this->__isset.overrideProtocolType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast597;
          xfer += iprot->readI32(ecast597);
          this->baudRate = (BaudRate::type)ecast597;
          this->__isset.baudRate = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timeout);
          this->__isset.timeout = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->enableHdlcOnly);
          this->__isset.enableHdlcOnly = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->blockingLogMaskClearOnConnection);
          this->__isset.blockingLogMaskClearOnConnection = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->clearLogMaskOnDisconnect);
          this->__isset.clearLogMaskOnDisconnect = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->disablePolling);
          this->__isset.disablePolling = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProtocolConfiguration::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProtocolConfiguration");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.overrideProtocolType) {
    xfer += oprot->writeFieldBegin("overrideProtocolType", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->overrideProtocolType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.baudRate) {
    xfer += oprot->writeFieldBegin("baudRate", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32((int32_t)this->baudRate);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.timeout) {
    xfer += oprot->writeFieldBegin("timeout", ::apache::thrift::protocol::T_I64, 4);
    xfer += oprot->writeI64(this->timeout);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.enableHdlcOnly) {
    xfer += oprot->writeFieldBegin("enableHdlcOnly", ::apache::thrift::protocol::T_BOOL, 5);
    xfer += oprot->writeBool(this->enableHdlcOnly);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.blockingLogMaskClearOnConnection) {
    xfer += oprot->writeFieldBegin("blockingLogMaskClearOnConnection", ::apache::thrift::protocol::T_BOOL, 6);
    xfer += oprot->writeBool(this->blockingLogMaskClearOnConnection);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.clearLogMaskOnDisconnect) {
    xfer += oprot->writeFieldBegin("clearLogMaskOnDisconnect", ::apache::thrift::protocol::T_BOOL, 7);
    xfer += oprot->writeBool(this->clearLogMaskOnDisconnect);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.disablePolling) {
    xfer += oprot->writeFieldBegin("disablePolling", ::apache::thrift::protocol::T_BOOL, 8);
    xfer += oprot->writeBool(this->disablePolling);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProtocolConfiguration &a, ProtocolConfiguration &b) {
  using ::std::swap;
  swap(a.protocolHandle, b.protocolHandle);
  swap(a.overrideProtocolType, b.overrideProtocolType);
  swap(a.baudRate, b.baudRate);
  swap(a.timeout, b.timeout);
  swap(a.enableHdlcOnly, b.enableHdlcOnly);
  swap(a.blockingLogMaskClearOnConnection, b.blockingLogMaskClearOnConnection);
  swap(a.clearLogMaskOnDisconnect, b.clearLogMaskOnDisconnect);
  swap(a.disablePolling, b.disablePolling);
  swap(a.__isset, b.__isset);
}

ProtocolConfiguration::ProtocolConfiguration(const ProtocolConfiguration& other598) {
  protocolHandle = other598.protocolHandle;
  overrideProtocolType = other598.overrideProtocolType;
  baudRate = other598.baudRate;
  timeout = other598.timeout;
  enableHdlcOnly = other598.enableHdlcOnly;
  blockingLogMaskClearOnConnection = other598.blockingLogMaskClearOnConnection;
  clearLogMaskOnDisconnect = other598.clearLogMaskOnDisconnect;
  disablePolling = other598.disablePolling;
  __isset = other598.__isset;
}
ProtocolConfiguration& ProtocolConfiguration::operator=(const ProtocolConfiguration& other599) {
  protocolHandle = other599.protocolHandle;
  overrideProtocolType = other599.overrideProtocolType;
  baudRate = other599.baudRate;
  timeout = other599.timeout;
  enableHdlcOnly = other599.enableHdlcOnly;
  blockingLogMaskClearOnConnection = other599.blockingLogMaskClearOnConnection;
  clearLogMaskOnDisconnect = other599.clearLogMaskOnDisconnect;
  disablePolling = other599.disablePolling;
  __isset = other599.__isset;
  return *this;
}
void ProtocolConfiguration::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProtocolConfiguration(";
  out << "protocolHandle=" << to_string(protocolHandle);
  out << ", " << "overrideProtocolType="; (__isset.overrideProtocolType ? (out << to_string(overrideProtocolType)) : (out << "<null>"));
  out << ", " << "baudRate="; (__isset.baudRate ? (out << to_string(baudRate)) : (out << "<null>"));
  out << ", " << "timeout="; (__isset.timeout ? (out << to_string(timeout)) : (out << "<null>"));
  out << ", " << "enableHdlcOnly="; (__isset.enableHdlcOnly ? (out << to_string(enableHdlcOnly)) : (out << "<null>"));
  out << ", " << "blockingLogMaskClearOnConnection="; (__isset.blockingLogMaskClearOnConnection ? (out << to_string(blockingLogMaskClearOnConnection)) : (out << "<null>"));
  out << ", " << "clearLogMaskOnDisconnect="; (__isset.clearLogMaskOnDisconnect ? (out << to_string(clearLogMaskOnDisconnect)) : (out << "<null>"));
  out << ", " << "disablePolling="; (__isset.disablePolling ? (out << to_string(disablePolling)) : (out << "<null>"));
  out << ")";
}


DiagProtocolConnectionOptions::~DiagProtocolConnectionOptions() noexcept {
}


void DiagProtocolConnectionOptions::__set_protocolHandle(const int64_t val) {
  this->protocolHandle = val;
__isset.protocolHandle = true;
}

void DiagProtocolConnectionOptions::__set_openQdssPort(const bool val) {
  this->openQdssPort = val;
__isset.openQdssPort = true;
}

void DiagProtocolConnectionOptions::__set_enableDefaultQdssConfiguration(const bool val) {
  this->enableDefaultQdssConfiguration = val;
__isset.enableDefaultQdssConfiguration = true;
}

void DiagProtocolConnectionOptions::__set_hdlcMode(const HdlcMode::type val) {
  this->hdlcMode = val;
__isset.hdlcMode = true;
}
std::ostream& operator<<(std::ostream& out, const DiagProtocolConnectionOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagProtocolConnectionOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->openQdssPort);
          this->__isset.openQdssPort = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->enableDefaultQdssConfiguration);
          this->__isset.enableDefaultQdssConfiguration = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast600;
          xfer += iprot->readI32(ecast600);
          this->hdlcMode = (HdlcMode::type)ecast600;
          this->__isset.hdlcMode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DiagProtocolConnectionOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagProtocolConnectionOptions");

  if (this->__isset.protocolHandle) {
    xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->protocolHandle);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.openQdssPort) {
    xfer += oprot->writeFieldBegin("openQdssPort", ::apache::thrift::protocol::T_BOOL, 2);
    xfer += oprot->writeBool(this->openQdssPort);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.enableDefaultQdssConfiguration) {
    xfer += oprot->writeFieldBegin("enableDefaultQdssConfiguration", ::apache::thrift::protocol::T_BOOL, 3);
    xfer += oprot->writeBool(this->enableDefaultQdssConfiguration);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.hdlcMode) {
    xfer += oprot->writeFieldBegin("hdlcMode", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32((int32_t)this->hdlcMode);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagProtocolConnectionOptions &a, DiagProtocolConnectionOptions &b) {
  using ::std::swap;
  swap(a.protocolHandle, b.protocolHandle);
  swap(a.openQdssPort, b.openQdssPort);
  swap(a.enableDefaultQdssConfiguration, b.enableDefaultQdssConfiguration);
  swap(a.hdlcMode, b.hdlcMode);
  swap(a.__isset, b.__isset);
}

DiagProtocolConnectionOptions::DiagProtocolConnectionOptions(const DiagProtocolConnectionOptions& other601) {
  protocolHandle = other601.protocolHandle;
  openQdssPort = other601.openQdssPort;
  enableDefaultQdssConfiguration = other601.enableDefaultQdssConfiguration;
  hdlcMode = other601.hdlcMode;
  __isset = other601.__isset;
}
DiagProtocolConnectionOptions& DiagProtocolConnectionOptions::operator=(const DiagProtocolConnectionOptions& other602) {
  protocolHandle = other602.protocolHandle;
  openQdssPort = other602.openQdssPort;
  enableDefaultQdssConfiguration = other602.enableDefaultQdssConfiguration;
  hdlcMode = other602.hdlcMode;
  __isset = other602.__isset;
  return *this;
}
void DiagProtocolConnectionOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagProtocolConnectionOptions(";
  out << "protocolHandle="; (__isset.protocolHandle ? (out << to_string(protocolHandle)) : (out << "<null>"));
  out << ", " << "openQdssPort="; (__isset.openQdssPort ? (out << to_string(openQdssPort)) : (out << "<null>"));
  out << ", " << "enableDefaultQdssConfiguration="; (__isset.enableDefaultQdssConfiguration ? (out << to_string(enableDefaultQdssConfiguration)) : (out << "<null>"));
  out << ", " << "hdlcMode="; (__isset.hdlcMode ? (out << to_string(hdlcMode)) : (out << "<null>"));
  out << ")";
}


InternetConnectionOptions::~InternetConnectionOptions() noexcept {
}


void InternetConnectionOptions::__set_username(const std::string& val) {
  this->username = val;
__isset.username = true;
}

void InternetConnectionOptions::__set_password(const std::string& val) {
  this->password = val;
__isset.password = true;
}

void InternetConnectionOptions::__set_telnetPort(const int32_t val) {
  this->telnetPort = val;
__isset.telnetPort = true;
}

void InternetConnectionOptions::__set_ftpPort(const int32_t val) {
  this->ftpPort = val;
__isset.ftpPort = true;
}
std::ostream& operator<<(std::ostream& out, const InternetConnectionOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t InternetConnectionOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->username);
          this->__isset.username = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->password);
          this->__isset.password = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->telnetPort);
          this->__isset.telnetPort = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->ftpPort);
          this->__isset.ftpPort = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t InternetConnectionOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("InternetConnectionOptions");

  if (this->__isset.username) {
    xfer += oprot->writeFieldBegin("username", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->username);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.password) {
    xfer += oprot->writeFieldBegin("password", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->password);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.telnetPort) {
    xfer += oprot->writeFieldBegin("telnetPort", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->telnetPort);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.ftpPort) {
    xfer += oprot->writeFieldBegin("ftpPort", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->ftpPort);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(InternetConnectionOptions &a, InternetConnectionOptions &b) {
  using ::std::swap;
  swap(a.username, b.username);
  swap(a.password, b.password);
  swap(a.telnetPort, b.telnetPort);
  swap(a.ftpPort, b.ftpPort);
  swap(a.__isset, b.__isset);
}

InternetConnectionOptions::InternetConnectionOptions(const InternetConnectionOptions& other603) {
  username = other603.username;
  password = other603.password;
  telnetPort = other603.telnetPort;
  ftpPort = other603.ftpPort;
  __isset = other603.__isset;
}
InternetConnectionOptions& InternetConnectionOptions::operator=(const InternetConnectionOptions& other604) {
  username = other604.username;
  password = other604.password;
  telnetPort = other604.telnetPort;
  ftpPort = other604.ftpPort;
  __isset = other604.__isset;
  return *this;
}
void InternetConnectionOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "InternetConnectionOptions(";
  out << "username="; (__isset.username ? (out << to_string(username)) : (out << "<null>"));
  out << ", " << "password="; (__isset.password ? (out << to_string(password)) : (out << "<null>"));
  out << ", " << "telnetPort="; (__isset.telnetPort ? (out << to_string(telnetPort)) : (out << "<null>"));
  out << ", " << "ftpPort="; (__isset.ftpPort ? (out << to_string(ftpPort)) : (out << "<null>"));
  out << ")";
}


ProtocolConnectionOptions::~ProtocolConnectionOptions() noexcept {
}


void ProtocolConnectionOptions::__set_diagProtocolConfiguration(const DiagProtocolConnectionOptions& val) {
  this->diagProtocolConfiguration = val;
__isset.diagProtocolConfiguration = true;
}

void ProtocolConnectionOptions::__set_internetConnectionConfiguration(const InternetConnectionOptions& val) {
  this->internetConnectionConfiguration = val;
__isset.internetConnectionConfiguration = true;
}
std::ostream& operator<<(std::ostream& out, const ProtocolConnectionOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProtocolConnectionOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->diagProtocolConfiguration.read(iprot);
          this->__isset.diagProtocolConfiguration = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->internetConnectionConfiguration.read(iprot);
          this->__isset.internetConnectionConfiguration = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProtocolConnectionOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProtocolConnectionOptions");

  if (this->__isset.diagProtocolConfiguration) {
    xfer += oprot->writeFieldBegin("diagProtocolConfiguration", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->diagProtocolConfiguration.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.internetConnectionConfiguration) {
    xfer += oprot->writeFieldBegin("internetConnectionConfiguration", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->internetConnectionConfiguration.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProtocolConnectionOptions &a, ProtocolConnectionOptions &b) {
  using ::std::swap;
  swap(a.diagProtocolConfiguration, b.diagProtocolConfiguration);
  swap(a.internetConnectionConfiguration, b.internetConnectionConfiguration);
  swap(a.__isset, b.__isset);
}

ProtocolConnectionOptions::ProtocolConnectionOptions(const ProtocolConnectionOptions& other605) {
  diagProtocolConfiguration = other605.diagProtocolConfiguration;
  internetConnectionConfiguration = other605.internetConnectionConfiguration;
  __isset = other605.__isset;
}
ProtocolConnectionOptions& ProtocolConnectionOptions::operator=(const ProtocolConnectionOptions& other606) {
  diagProtocolConfiguration = other606.diagProtocolConfiguration;
  internetConnectionConfiguration = other606.internetConnectionConfiguration;
  __isset = other606.__isset;
  return *this;
}
void ProtocolConnectionOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProtocolConnectionOptions(";
  out << "diagProtocolConfiguration="; (__isset.diagProtocolConfiguration ? (out << to_string(diagProtocolConfiguration)) : (out << "<null>"));
  out << ", " << "internetConnectionConfiguration="; (__isset.internetConnectionConfiguration ? (out << to_string(internetConnectionConfiguration)) : (out << "<null>"));
  out << ")";
}


TcpOptions::~TcpOptions() noexcept {
}


void TcpOptions::__set_description(const std::string& val) {
  this->description = val;
}

void TcpOptions::__set_protocolType(const ProtocolType::type val) {
  this->protocolType = val;
}

void TcpOptions::__set_isClient(const bool val) {
  this->isClient = val;
}

void TcpOptions::__set_deviceHandle(const int64_t val) {
  this->deviceHandle = val;
__isset.deviceHandle = true;
}

void TcpOptions::__set_adbSerialNumber(const std::string& val) {
  this->adbSerialNumber = val;
__isset.adbSerialNumber = true;
}

void TcpOptions::__set_chipSerialNumber(const std::string& val) {
  this->chipSerialNumber = val;
__isset.chipSerialNumber = true;
}

void TcpOptions::__set_protocolConnectionOptions(const ProtocolConnectionOptions& val) {
  this->protocolConnectionOptions = val;
__isset.protocolConnectionOptions = true;
}

void TcpOptions::__set_useExistingConnectionIfAvailable(const bool val) {
  this->useExistingConnectionIfAvailable = val;
__isset.useExistingConnectionIfAvailable = true;
}
std::ostream& operator<<(std::ostream& out, const TcpOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TcpOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast607;
          xfer += iprot->readI32(ecast607);
          this->protocolType = (ProtocolType::type)ecast607;
          this->__isset.protocolType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isClient);
          this->__isset.isClient = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->deviceHandle);
          this->__isset.deviceHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->adbSerialNumber);
          this->__isset.adbSerialNumber = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->chipSerialNumber);
          this->__isset.chipSerialNumber = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->protocolConnectionOptions.read(iprot);
          this->__isset.protocolConnectionOptions = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->useExistingConnectionIfAvailable);
          this->__isset.useExistingConnectionIfAvailable = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TcpOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TcpOptions");

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->description);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolType", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->protocolType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("isClient", ::apache::thrift::protocol::T_BOOL, 3);
  xfer += oprot->writeBool(this->isClient);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.deviceHandle) {
    xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 4);
    xfer += oprot->writeI64(this->deviceHandle);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.adbSerialNumber) {
    xfer += oprot->writeFieldBegin("adbSerialNumber", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->adbSerialNumber);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.chipSerialNumber) {
    xfer += oprot->writeFieldBegin("chipSerialNumber", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->chipSerialNumber);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolConnectionOptions) {
    xfer += oprot->writeFieldBegin("protocolConnectionOptions", ::apache::thrift::protocol::T_STRUCT, 7);
    xfer += this->protocolConnectionOptions.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.useExistingConnectionIfAvailable) {
    xfer += oprot->writeFieldBegin("useExistingConnectionIfAvailable", ::apache::thrift::protocol::T_BOOL, 8);
    xfer += oprot->writeBool(this->useExistingConnectionIfAvailable);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TcpOptions &a, TcpOptions &b) {
  using ::std::swap;
  swap(a.description, b.description);
  swap(a.protocolType, b.protocolType);
  swap(a.isClient, b.isClient);
  swap(a.deviceHandle, b.deviceHandle);
  swap(a.adbSerialNumber, b.adbSerialNumber);
  swap(a.chipSerialNumber, b.chipSerialNumber);
  swap(a.protocolConnectionOptions, b.protocolConnectionOptions);
  swap(a.useExistingConnectionIfAvailable, b.useExistingConnectionIfAvailable);
  swap(a.__isset, b.__isset);
}

TcpOptions::TcpOptions(const TcpOptions& other608) {
  description = other608.description;
  protocolType = other608.protocolType;
  isClient = other608.isClient;
  deviceHandle = other608.deviceHandle;
  adbSerialNumber = other608.adbSerialNumber;
  chipSerialNumber = other608.chipSerialNumber;
  protocolConnectionOptions = other608.protocolConnectionOptions;
  useExistingConnectionIfAvailable = other608.useExistingConnectionIfAvailable;
  __isset = other608.__isset;
}
TcpOptions& TcpOptions::operator=(const TcpOptions& other609) {
  description = other609.description;
  protocolType = other609.protocolType;
  isClient = other609.isClient;
  deviceHandle = other609.deviceHandle;
  adbSerialNumber = other609.adbSerialNumber;
  chipSerialNumber = other609.chipSerialNumber;
  protocolConnectionOptions = other609.protocolConnectionOptions;
  useExistingConnectionIfAvailable = other609.useExistingConnectionIfAvailable;
  __isset = other609.__isset;
  return *this;
}
void TcpOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TcpOptions(";
  out << "description=" << to_string(description);
  out << ", " << "protocolType=" << to_string(protocolType);
  out << ", " << "isClient=" << to_string(isClient);
  out << ", " << "deviceHandle="; (__isset.deviceHandle ? (out << to_string(deviceHandle)) : (out << "<null>"));
  out << ", " << "adbSerialNumber="; (__isset.adbSerialNumber ? (out << to_string(adbSerialNumber)) : (out << "<null>"));
  out << ", " << "chipSerialNumber="; (__isset.chipSerialNumber ? (out << to_string(chipSerialNumber)) : (out << "<null>"));
  out << ", " << "protocolConnectionOptions="; (__isset.protocolConnectionOptions ? (out << to_string(protocolConnectionOptions)) : (out << "<null>"));
  out << ", " << "useExistingConnectionIfAvailable="; (__isset.useExistingConnectionIfAvailable ? (out << to_string(useExistingConnectionIfAvailable)) : (out << "<null>"));
  out << ")";
}


TransferFileOptions::~TransferFileOptions() noexcept {
}


void TransferFileOptions::__set_protocolHandle(const int64_t val) {
  this->protocolHandle = val;
__isset.protocolHandle = true;
}

void TransferFileOptions::__set_protocolType(const ProtocolType::type val) {
  this->protocolType = val;
__isset.protocolType = true;
}

void TransferFileOptions::__set_wildcardPattern(const std::string& val) {
  this->wildcardPattern = val;
__isset.wildcardPattern = true;
}
std::ostream& operator<<(std::ostream& out, const TransferFileOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TransferFileOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast610;
          xfer += iprot->readI32(ecast610);
          this->protocolType = (ProtocolType::type)ecast610;
          this->__isset.protocolType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->wildcardPattern);
          this->__isset.wildcardPattern = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TransferFileOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TransferFileOptions");

  if (this->__isset.protocolHandle) {
    xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->protocolHandle);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolType) {
    xfer += oprot->writeFieldBegin("protocolType", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->protocolType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.wildcardPattern) {
    xfer += oprot->writeFieldBegin("wildcardPattern", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->wildcardPattern);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TransferFileOptions &a, TransferFileOptions &b) {
  using ::std::swap;
  swap(a.protocolHandle, b.protocolHandle);
  swap(a.protocolType, b.protocolType);
  swap(a.wildcardPattern, b.wildcardPattern);
  swap(a.__isset, b.__isset);
}

TransferFileOptions::TransferFileOptions(const TransferFileOptions& other611) {
  protocolHandle = other611.protocolHandle;
  protocolType = other611.protocolType;
  wildcardPattern = other611.wildcardPattern;
  __isset = other611.__isset;
}
TransferFileOptions& TransferFileOptions::operator=(const TransferFileOptions& other612) {
  protocolHandle = other612.protocolHandle;
  protocolType = other612.protocolType;
  wildcardPattern = other612.wildcardPattern;
  __isset = other612.__isset;
  return *this;
}
void TransferFileOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TransferFileOptions(";
  out << "protocolHandle="; (__isset.protocolHandle ? (out << to_string(protocolHandle)) : (out << "<null>"));
  out << ", " << "protocolType="; (__isset.protocolType ? (out << to_string(protocolType)) : (out << "<null>"));
  out << ", " << "wildcardPattern="; (__isset.wildcardPattern ? (out << to_string(wildcardPattern)) : (out << "<null>"));
  out << ")";
}


TransferFileResult::~TransferFileResult() noexcept {
}


void TransferFileResult::__set_errorType(const ErrorType& val) {
  this->errorType = val;
__isset.errorType = true;
}

void TransferFileResult::__set_sequence(const std::string& val) {
  this->sequence = val;
__isset.sequence = true;
}
std::ostream& operator<<(std::ostream& out, const TransferFileResult& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TransferFileResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->errorType.read(iprot);
          this->__isset.errorType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->sequence);
          this->__isset.sequence = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t TransferFileResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TransferFileResult");

  if (this->__isset.errorType) {
    xfer += oprot->writeFieldBegin("errorType", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->errorType.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.sequence) {
    xfer += oprot->writeFieldBegin("sequence", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->sequence);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TransferFileResult &a, TransferFileResult &b) {
  using ::std::swap;
  swap(a.errorType, b.errorType);
  swap(a.sequence, b.sequence);
  swap(a.__isset, b.__isset);
}

TransferFileResult::TransferFileResult(const TransferFileResult& other613) {
  errorType = other613.errorType;
  sequence = other613.sequence;
  __isset = other613.__isset;
}
TransferFileResult& TransferFileResult::operator=(const TransferFileResult& other614) {
  errorType = other614.errorType;
  sequence = other614.sequence;
  __isset = other614.__isset;
  return *this;
}
void TransferFileResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TransferFileResult(";
  out << "errorType="; (__isset.errorType ? (out << to_string(errorType)) : (out << "<null>"));
  out << ", " << "sequence="; (__isset.sequence ? (out << to_string(sequence)) : (out << "<null>"));
  out << ")";
}


ClientCloseRequest::~ClientCloseRequest() noexcept {
}


void ClientCloseRequest::__set_purpose(const std::string& val) {
  this->purpose = val;
}
std::ostream& operator<<(std::ostream& out, const ClientCloseRequest& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ClientCloseRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->purpose);
          this->__isset.purpose = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ClientCloseRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCloseRequest");

  xfer += oprot->writeFieldBegin("purpose", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->purpose);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ClientCloseRequest &a, ClientCloseRequest &b) {
  using ::std::swap;
  swap(a.purpose, b.purpose);
  swap(a.__isset, b.__isset);
}

ClientCloseRequest::ClientCloseRequest(const ClientCloseRequest& other615) {
  purpose = other615.purpose;
  __isset = other615.__isset;
}
ClientCloseRequest& ClientCloseRequest::operator=(const ClientCloseRequest& other616) {
  purpose = other616.purpose;
  __isset = other616.__isset;
  return *this;
}
void ClientCloseRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ClientCloseRequest(";
  out << "purpose=" << to_string(purpose);
  out << ")";
}


ClientCloseReason::~ClientCloseReason() noexcept {
}


void ClientCloseReason::__set_reason(const std::string& val) {
  this->reason = val;
}
std::ostream& operator<<(std::ostream& out, const ClientCloseReason& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ClientCloseReason::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->reason);
          this->__isset.reason = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ClientCloseReason::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCloseReason");

  xfer += oprot->writeFieldBegin("reason", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->reason);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ClientCloseReason &a, ClientCloseReason &b) {
  using ::std::swap;
  swap(a.reason, b.reason);
  swap(a.__isset, b.__isset);
}

ClientCloseReason::ClientCloseReason(const ClientCloseReason& other617) {
  reason = other617.reason;
  __isset = other617.__isset;
}
ClientCloseReason& ClientCloseReason::operator=(const ClientCloseReason& other618) {
  reason = other618.reason;
  __isset = other618.__isset;
  return *this;
}
void ClientCloseReason::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ClientCloseReason(";
  out << "reason=" << to_string(reason);
  out << ")";
}


ProtocolConfigurationResult::~ProtocolConfigurationResult() noexcept {
}


void ProtocolConfigurationResult::__set_errorType(const ErrorType& val) {
  this->errorType = val;
__isset.errorType = true;
}

void ProtocolConfigurationResult::__set_protocolHandle(const int64_t val) {
  this->protocolHandle = val;
__isset.protocolHandle = true;
}

void ProtocolConfigurationResult::__set_protocolType(const ProtocolType::type val) {
  this->protocolType = val;
__isset.protocolType = true;
}

void ProtocolConfigurationResult::__set_baudRate(const BaudRate::type val) {
  this->baudRate = val;
__isset.baudRate = true;
}

void ProtocolConfigurationResult::__set_timeout(const int64_t val) {
  this->timeout = val;
__isset.timeout = true;
}

void ProtocolConfigurationResult::__set_hdlcOnlyMode(const HdlcModeStatus::type val) {
  this->hdlcOnlyMode = val;
__isset.hdlcOnlyMode = true;
}

void ProtocolConfigurationResult::__set_disablePolling(const bool val) {
  this->disablePolling = val;
__isset.disablePolling = true;
}
std::ostream& operator<<(std::ostream& out, const ProtocolConfigurationResult& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProtocolConfigurationResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->errorType.read(iprot);
          this->__isset.errorType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast619;
          xfer += iprot->readI32(ecast619);
          this->protocolType = (ProtocolType::type)ecast619;
          this->__isset.protocolType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast620;
          xfer += iprot->readI32(ecast620);
          this->baudRate = (BaudRate::type)ecast620;
          this->__isset.baudRate = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timeout);
          this->__isset.timeout = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast621;
          xfer += iprot->readI32(ecast621);
          this->hdlcOnlyMode = (HdlcModeStatus::type)ecast621;
          this->__isset.hdlcOnlyMode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->disablePolling);
          this->__isset.disablePolling = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProtocolConfigurationResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProtocolConfigurationResult");

  if (this->__isset.errorType) {
    xfer += oprot->writeFieldBegin("errorType", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->errorType.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolHandle) {
    xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->protocolHandle);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protocolType) {
    xfer += oprot->writeFieldBegin("protocolType", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32((int32_t)this->protocolType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.baudRate) {
    xfer += oprot->writeFieldBegin("baudRate", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32((int32_t)this->baudRate);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.timeout) {
    xfer += oprot->writeFieldBegin("timeout", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->timeout);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.hdlcOnlyMode) {
    xfer += oprot->writeFieldBegin("hdlcOnlyMode", ::apache::thrift::protocol::T_I32, 6);
    xfer += oprot->writeI32((int32_t)this->hdlcOnlyMode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.disablePolling) {
    xfer += oprot->writeFieldBegin("disablePolling", ::apache::thrift::protocol::T_BOOL, 7);
    xfer += oprot->writeBool(this->disablePolling);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProtocolConfigurationResult &a, ProtocolConfigurationResult &b) {
  using ::std::swap;
  swap(a.errorType, b.errorType);
  swap(a.protocolHandle, b.protocolHandle);
  swap(a.protocolType, b.protocolType);
  swap(a.baudRate, b.baudRate);
  swap(a.timeout, b.timeout);
  swap(a.hdlcOnlyMode, b.hdlcOnlyMode);
  swap(a.disablePolling, b.disablePolling);
  swap(a.__isset, b.__isset);
}

ProtocolConfigurationResult::ProtocolConfigurationResult(const ProtocolConfigurationResult& other622) {
  errorType = other622.errorType;
  protocolHandle = other622.protocolHandle;
  protocolType = other622.protocolType;
  baudRate = other622.baudRate;
  timeout = other622.timeout;
  hdlcOnlyMode = other622.hdlcOnlyMode;
  disablePolling = other622.disablePolling;
  __isset = other622.__isset;
}
ProtocolConfigurationResult& ProtocolConfigurationResult::operator=(const ProtocolConfigurationResult& other623) {
  errorType = other623.errorType;
  protocolHandle = other623.protocolHandle;
  protocolType = other623.protocolType;
  baudRate = other623.baudRate;
  timeout = other623.timeout;
  hdlcOnlyMode = other623.hdlcOnlyMode;
  disablePolling = other623.disablePolling;
  __isset = other623.__isset;
  return *this;
}
void ProtocolConfigurationResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProtocolConfigurationResult(";
  out << "errorType="; (__isset.errorType ? (out << to_string(errorType)) : (out << "<null>"));
  out << ", " << "protocolHandle="; (__isset.protocolHandle ? (out << to_string(protocolHandle)) : (out << "<null>"));
  out << ", " << "protocolType="; (__isset.protocolType ? (out << to_string(protocolType)) : (out << "<null>"));
  out << ", " << "baudRate="; (__isset.baudRate ? (out << to_string(baudRate)) : (out << "<null>"));
  out << ", " << "timeout="; (__isset.timeout ? (out << to_string(timeout)) : (out << "<null>"));
  out << ", " << "hdlcOnlyMode="; (__isset.hdlcOnlyMode ? (out << to_string(hdlcOnlyMode)) : (out << "<null>"));
  out << ", " << "disablePolling="; (__isset.disablePolling ? (out << to_string(disablePolling)) : (out << "<null>"));
  out << ")";
}


XqcnRestoreOptions::~XqcnRestoreOptions() noexcept {
}


void XqcnRestoreOptions::__set_xqcnFileContents(const std::string& val) {
  this->xqcnFileContents = val;
}

void XqcnRestoreOptions::__set_sourceFilePath(const std::string& val) {
  this->sourceFilePath = val;
}

void XqcnRestoreOptions::__set_serviceProgrammingCode(const std::string& val) {
  this->serviceProgrammingCode = val;
}

void XqcnRestoreOptions::__set_bAllowEsnMismatch(const bool val) {
  this->bAllowEsnMismatch = val;
}

void XqcnRestoreOptions::__set_bResetUponCompletion(const bool val) {
  this->bResetUponCompletion = val;
}

void XqcnRestoreOptions::__set_resetTimeout(const int32_t val) {
  this->resetTimeout = val;
}

void XqcnRestoreOptions::__set_filterFileContents(const std::string& val) {
  this->filterFileContents = val;
}
std::ostream& operator<<(std::ostream& out, const XqcnRestoreOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t XqcnRestoreOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->xqcnFileContents);
          this->__isset.xqcnFileContents = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->sourceFilePath);
          this->__isset.sourceFilePath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->serviceProgrammingCode);
          this->__isset.serviceProgrammingCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->bAllowEsnMismatch);
          this->__isset.bAllowEsnMismatch = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->bResetUponCompletion);
          this->__isset.bResetUponCompletion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->resetTimeout);
          this->__isset.resetTimeout = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->filterFileContents);
          this->__isset.filterFileContents = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t XqcnRestoreOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("XqcnRestoreOptions");

  xfer += oprot->writeFieldBegin("xqcnFileContents", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->xqcnFileContents);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("sourceFilePath", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->sourceFilePath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("serviceProgrammingCode", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->serviceProgrammingCode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("bAllowEsnMismatch", ::apache::thrift::protocol::T_BOOL, 4);
  xfer += oprot->writeBool(this->bAllowEsnMismatch);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("bResetUponCompletion", ::apache::thrift::protocol::T_BOOL, 5);
  xfer += oprot->writeBool(this->bResetUponCompletion);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("resetTimeout", ::apache::thrift::protocol::T_I32, 6);
  xfer += oprot->writeI32(this->resetTimeout);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("filterFileContents", ::apache::thrift::protocol::T_STRING, 7);
  xfer += oprot->writeString(this->filterFileContents);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(XqcnRestoreOptions &a, XqcnRestoreOptions &b) {
  using ::std::swap;
  swap(a.xqcnFileContents, b.xqcnFileContents);
  swap(a.sourceFilePath, b.sourceFilePath);
  swap(a.serviceProgrammingCode, b.serviceProgrammingCode);
  swap(a.bAllowEsnMismatch, b.bAllowEsnMismatch);
  swap(a.bResetUponCompletion, b.bResetUponCompletion);
  swap(a.resetTimeout, b.resetTimeout);
  swap(a.filterFileContents, b.filterFileContents);
  swap(a.__isset, b.__isset);
}

XqcnRestoreOptions::XqcnRestoreOptions(const XqcnRestoreOptions& other624) {
  xqcnFileContents = other624.xqcnFileContents;
  sourceFilePath = other624.sourceFilePath;
  serviceProgrammingCode = other624.serviceProgrammingCode;
  bAllowEsnMismatch = other624.bAllowEsnMismatch;
  bResetUponCompletion = other624.bResetUponCompletion;
  resetTimeout = other624.resetTimeout;
  filterFileContents = other624.filterFileContents;
  __isset = other624.__isset;
}
XqcnRestoreOptions& XqcnRestoreOptions::operator=(const XqcnRestoreOptions& other625) {
  xqcnFileContents = other625.xqcnFileContents;
  sourceFilePath = other625.sourceFilePath;
  serviceProgrammingCode = other625.serviceProgrammingCode;
  bAllowEsnMismatch = other625.bAllowEsnMismatch;
  bResetUponCompletion = other625.bResetUponCompletion;
  resetTimeout = other625.resetTimeout;
  filterFileContents = other625.filterFileContents;
  __isset = other625.__isset;
  return *this;
}
void XqcnRestoreOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "XqcnRestoreOptions(";
  out << "xqcnFileContents=" << to_string(xqcnFileContents);
  out << ", " << "sourceFilePath=" << to_string(sourceFilePath);
  out << ", " << "serviceProgrammingCode=" << to_string(serviceProgrammingCode);
  out << ", " << "bAllowEsnMismatch=" << to_string(bAllowEsnMismatch);
  out << ", " << "bResetUponCompletion=" << to_string(bResetUponCompletion);
  out << ", " << "resetTimeout=" << to_string(resetTimeout);
  out << ", " << "filterFileContents=" << to_string(filterFileContents);
  out << ")";
}


XqcnBackupOptions::~XqcnBackupOptions() noexcept {
}


void XqcnBackupOptions::__set_serviceProgrammingCode(const std::string& val) {
  this->serviceProgrammingCode = val;
}

void XqcnBackupOptions::__set_bResetUponCompletion(const bool val) {
  this->bResetUponCompletion = val;
}

void XqcnBackupOptions::__set_resetTimeout(const int32_t val) {
  this->resetTimeout = val;
}

void XqcnBackupOptions::__set_filterFileContents(const std::string& val) {
  this->filterFileContents = val;
}
std::ostream& operator<<(std::ostream& out, const XqcnBackupOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t XqcnBackupOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->serviceProgrammingCode);
          this->__isset.serviceProgrammingCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->bResetUponCompletion);
          this->__isset.bResetUponCompletion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->resetTimeout);
          this->__isset.resetTimeout = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->filterFileContents);
          this->__isset.filterFileContents = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t XqcnBackupOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("XqcnBackupOptions");

  xfer += oprot->writeFieldBegin("serviceProgrammingCode", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->serviceProgrammingCode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("bResetUponCompletion", ::apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool(this->bResetUponCompletion);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("resetTimeout", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->resetTimeout);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("filterFileContents", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->filterFileContents);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(XqcnBackupOptions &a, XqcnBackupOptions &b) {
  using ::std::swap;
  swap(a.serviceProgrammingCode, b.serviceProgrammingCode);
  swap(a.bResetUponCompletion, b.bResetUponCompletion);
  swap(a.resetTimeout, b.resetTimeout);
  swap(a.filterFileContents, b.filterFileContents);
  swap(a.__isset, b.__isset);
}

XqcnBackupOptions::XqcnBackupOptions(const XqcnBackupOptions& other626) {
  serviceProgrammingCode = other626.serviceProgrammingCode;
  bResetUponCompletion = other626.bResetUponCompletion;
  resetTimeout = other626.resetTimeout;
  filterFileContents = other626.filterFileContents;
  __isset = other626.__isset;
}
XqcnBackupOptions& XqcnBackupOptions::operator=(const XqcnBackupOptions& other627) {
  serviceProgrammingCode = other627.serviceProgrammingCode;
  bResetUponCompletion = other627.bResetUponCompletion;
  resetTimeout = other627.resetTimeout;
  filterFileContents = other627.filterFileContents;
  __isset = other627.__isset;
  return *this;
}
void XqcnBackupOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "XqcnBackupOptions(";
  out << "serviceProgrammingCode=" << to_string(serviceProgrammingCode);
  out << ", " << "bResetUponCompletion=" << to_string(bResetUponCompletion);
  out << ", " << "resetTimeout=" << to_string(resetTimeout);
  out << ", " << "filterFileContents=" << to_string(filterFileContents);
  out << ")";
}


DeviceConfigResp::~DeviceConfigResp() noexcept {
}


void DeviceConfigResp::__set_returnCode(const ErrorCode::type val) {
  this->returnCode = val;
}

void DeviceConfigResp::__set_xqcnFileContents(const std::string& val) {
  this->xqcnFileContents = val;
}
std::ostream& operator<<(std::ostream& out, const DeviceConfigResp& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DeviceConfigResp::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast628;
          xfer += iprot->readI32(ecast628);
          this->returnCode = (ErrorCode::type)ecast628;
          this->__isset.returnCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->xqcnFileContents);
          this->__isset.xqcnFileContents = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DeviceConfigResp::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigResp");

  xfer += oprot->writeFieldBegin("returnCode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->returnCode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("xqcnFileContents", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->xqcnFileContents);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DeviceConfigResp &a, DeviceConfigResp &b) {
  using ::std::swap;
  swap(a.returnCode, b.returnCode);
  swap(a.xqcnFileContents, b.xqcnFileContents);
  swap(a.__isset, b.__isset);
}

DeviceConfigResp::DeviceConfigResp(const DeviceConfigResp& other629) {
  returnCode = other629.returnCode;
  xqcnFileContents = other629.xqcnFileContents;
  __isset = other629.__isset;
}
DeviceConfigResp& DeviceConfigResp::operator=(const DeviceConfigResp& other630) {
  returnCode = other630.returnCode;
  xqcnFileContents = other630.xqcnFileContents;
  __isset = other630.__isset;
  return *this;
}
void DeviceConfigResp::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DeviceConfigResp(";
  out << "returnCode=" << to_string(returnCode);
  out << ", " << "xqcnFileContents=" << to_string(xqcnFileContents);
  out << ")";
}


QmBackendInfoType::~QmBackendInfoType() noexcept {
}


void QmBackendInfoType::__set_backendName(const std::string& val) {
  this->backendName = val;
__isset.backendName = true;
}

void QmBackendInfoType::__set_backendId(const int32_t val) {
  this->backendId = val;
__isset.backendId = true;
}
std::ostream& operator<<(std::ostream& out, const QmBackendInfoType& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmBackendInfoType::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->backendName);
          this->__isset.backendName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->backendId);
          this->__isset.backendId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmBackendInfoType::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmBackendInfoType");

  if (this->__isset.backendName) {
    xfer += oprot->writeFieldBegin("backendName", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->backendName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.backendId) {
    xfer += oprot->writeFieldBegin("backendId", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->backendId);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmBackendInfoType &a, QmBackendInfoType &b) {
  using ::std::swap;
  swap(a.backendName, b.backendName);
  swap(a.backendId, b.backendId);
  swap(a.__isset, b.__isset);
}

QmBackendInfoType::QmBackendInfoType(const QmBackendInfoType& other631) {
  backendName = other631.backendName;
  backendId = other631.backendId;
  __isset = other631.__isset;
}
QmBackendInfoType& QmBackendInfoType::operator=(const QmBackendInfoType& other632) {
  backendName = other632.backendName;
  backendId = other632.backendId;
  __isset = other632.__isset;
  return *this;
}
void QmBackendInfoType::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmBackendInfoType(";
  out << "backendName="; (__isset.backendName ? (out << to_string(backendName)) : (out << "<null>"));
  out << ", " << "backendId="; (__isset.backendId ? (out << to_string(backendId)) : (out << "<null>"));
  out << ")";
}


QmBackendInfo::~QmBackendInfo() noexcept {
}


void QmBackendInfo::__set_status(const QmStatusType::type val) {
  this->status = val;
__isset.status = true;
}

void QmBackendInfo::__set_backendInfoList(const std::vector<QmBackendInfoType> & val) {
  this->backendInfoList = val;
__isset.backendInfoList = true;
}
std::ostream& operator<<(std::ostream& out, const QmBackendInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmBackendInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast633;
          xfer += iprot->readI32(ecast633);
          this->status = (QmStatusType::type)ecast633;
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->backendInfoList.clear();
            uint32_t _size634;
            ::apache::thrift::protocol::TType _etype637;
            xfer += iprot->readListBegin(_etype637, _size634);
            this->backendInfoList.resize(_size634);
            uint32_t _i638;
            for (_i638 = 0; _i638 < _size634; ++_i638)
            {
              xfer += this->backendInfoList[_i638].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.backendInfoList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmBackendInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmBackendInfo");

  if (this->__isset.status) {
    xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->status);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.backendInfoList) {
    xfer += oprot->writeFieldBegin("backendInfoList", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->backendInfoList.size()));
      std::vector<QmBackendInfoType> ::const_iterator _iter639;
      for (_iter639 = this->backendInfoList.begin(); _iter639 != this->backendInfoList.end(); ++_iter639)
      {
        xfer += (*_iter639).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmBackendInfo &a, QmBackendInfo &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.backendInfoList, b.backendInfoList);
  swap(a.__isset, b.__isset);
}

QmBackendInfo::QmBackendInfo(const QmBackendInfo& other640) {
  status = other640.status;
  backendInfoList = other640.backendInfoList;
  __isset = other640.__isset;
}
QmBackendInfo& QmBackendInfo::operator=(const QmBackendInfo& other641) {
  status = other641.status;
  backendInfoList = other641.backendInfoList;
  __isset = other641.__isset;
  return *this;
}
void QmBackendInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmBackendInfo(";
  out << "status="; (__isset.status ? (out << to_string(status)) : (out << "<null>"));
  out << ", " << "backendInfoList="; (__isset.backendInfoList ? (out << to_string(backendInfoList)) : (out << "<null>"));
  out << ")";
}


QmBackendInfoResponse::~QmBackendInfoResponse() noexcept {
}


void QmBackendInfoResponse::__set_backendInfo(const std::vector<QmBackendInfo> & val) {
  this->backendInfo = val;
__isset.backendInfo = true;
}
std::ostream& operator<<(std::ostream& out, const QmBackendInfoResponse& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmBackendInfoResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->backendInfo.clear();
            uint32_t _size642;
            ::apache::thrift::protocol::TType _etype645;
            xfer += iprot->readListBegin(_etype645, _size642);
            this->backendInfo.resize(_size642);
            uint32_t _i646;
            for (_i646 = 0; _i646 < _size642; ++_i646)
            {
              xfer += this->backendInfo[_i646].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.backendInfo = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmBackendInfoResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmBackendInfoResponse");

  if (this->__isset.backendInfo) {
    xfer += oprot->writeFieldBegin("backendInfo", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->backendInfo.size()));
      std::vector<QmBackendInfo> ::const_iterator _iter647;
      for (_iter647 = this->backendInfo.begin(); _iter647 != this->backendInfo.end(); ++_iter647)
      {
        xfer += (*_iter647).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmBackendInfoResponse &a, QmBackendInfoResponse &b) {
  using ::std::swap;
  swap(a.backendInfo, b.backendInfo);
  swap(a.__isset, b.__isset);
}

QmBackendInfoResponse::QmBackendInfoResponse(const QmBackendInfoResponse& other648) {
  backendInfo = other648.backendInfo;
  __isset = other648.__isset;
}
QmBackendInfoResponse& QmBackendInfoResponse::operator=(const QmBackendInfoResponse& other649) {
  backendInfo = other649.backendInfo;
  __isset = other649.__isset;
  return *this;
}
void QmBackendInfoResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmBackendInfoResponse(";
  out << "backendInfo="; (__isset.backendInfo ? (out << to_string(backendInfo)) : (out << "<null>"));
  out << ")";
}


QmCapabilitiesInfo::~QmCapabilitiesInfo() noexcept {
}


void QmCapabilitiesInfo::__set_status(const QmStatusType::type val) {
  this->status = val;
__isset.status = true;
}

void QmCapabilitiesInfo::__set_capabilityInfoList(const std::vector<StreamingCapabilityInfoType> & val) {
  this->capabilityInfoList = val;
__isset.capabilityInfoList = true;
}
std::ostream& operator<<(std::ostream& out, const QmCapabilitiesInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmCapabilitiesInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast650;
          xfer += iprot->readI32(ecast650);
          this->status = (QmStatusType::type)ecast650;
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->capabilityInfoList.clear();
            uint32_t _size651;
            ::apache::thrift::protocol::TType _etype654;
            xfer += iprot->readListBegin(_etype654, _size651);
            this->capabilityInfoList.resize(_size651);
            uint32_t _i655;
            for (_i655 = 0; _i655 < _size651; ++_i655)
            {
              xfer += this->capabilityInfoList[_i655].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.capabilityInfoList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmCapabilitiesInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmCapabilitiesInfo");

  if (this->__isset.status) {
    xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->status);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.capabilityInfoList) {
    xfer += oprot->writeFieldBegin("capabilityInfoList", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->capabilityInfoList.size()));
      std::vector<StreamingCapabilityInfoType> ::const_iterator _iter656;
      for (_iter656 = this->capabilityInfoList.begin(); _iter656 != this->capabilityInfoList.end(); ++_iter656)
      {
        xfer += (*_iter656).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmCapabilitiesInfo &a, QmCapabilitiesInfo &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.capabilityInfoList, b.capabilityInfoList);
  swap(a.__isset, b.__isset);
}

QmCapabilitiesInfo::QmCapabilitiesInfo(const QmCapabilitiesInfo& other657) {
  status = other657.status;
  capabilityInfoList = other657.capabilityInfoList;
  __isset = other657.__isset;
}
QmCapabilitiesInfo& QmCapabilitiesInfo::operator=(const QmCapabilitiesInfo& other658) {
  status = other658.status;
  capabilityInfoList = other658.capabilityInfoList;
  __isset = other658.__isset;
  return *this;
}
void QmCapabilitiesInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmCapabilitiesInfo(";
  out << "status="; (__isset.status ? (out << to_string(status)) : (out << "<null>"));
  out << ", " << "capabilityInfoList="; (__isset.capabilityInfoList ? (out << to_string(capabilityInfoList)) : (out << "<null>"));
  out << ")";
}


QmCapabilitiesInfoResponse::~QmCapabilitiesInfoResponse() noexcept {
}


void QmCapabilitiesInfoResponse::__set_capabilityInfo(const std::vector<QmCapabilitiesInfo> & val) {
  this->capabilityInfo = val;
__isset.capabilityInfo = true;
}
std::ostream& operator<<(std::ostream& out, const QmCapabilitiesInfoResponse& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmCapabilitiesInfoResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->capabilityInfo.clear();
            uint32_t _size659;
            ::apache::thrift::protocol::TType _etype662;
            xfer += iprot->readListBegin(_etype662, _size659);
            this->capabilityInfo.resize(_size659);
            uint32_t _i663;
            for (_i663 = 0; _i663 < _size659; ++_i663)
            {
              xfer += this->capabilityInfo[_i663].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.capabilityInfo = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmCapabilitiesInfoResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmCapabilitiesInfoResponse");

  if (this->__isset.capabilityInfo) {
    xfer += oprot->writeFieldBegin("capabilityInfo", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->capabilityInfo.size()));
      std::vector<QmCapabilitiesInfo> ::const_iterator _iter664;
      for (_iter664 = this->capabilityInfo.begin(); _iter664 != this->capabilityInfo.end(); ++_iter664)
      {
        xfer += (*_iter664).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmCapabilitiesInfoResponse &a, QmCapabilitiesInfoResponse &b) {
  using ::std::swap;
  swap(a.capabilityInfo, b.capabilityInfo);
  swap(a.__isset, b.__isset);
}

QmCapabilitiesInfoResponse::QmCapabilitiesInfoResponse(const QmCapabilitiesInfoResponse& other665) {
  capabilityInfo = other665.capabilityInfo;
  __isset = other665.__isset;
}
QmCapabilitiesInfoResponse& QmCapabilitiesInfoResponse::operator=(const QmCapabilitiesInfoResponse& other666) {
  capabilityInfo = other666.capabilityInfo;
  __isset = other666.__isset;
  return *this;
}
void QmCapabilitiesInfoResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmCapabilitiesInfoResponse(";
  out << "capabilityInfo="; (__isset.capabilityInfo ? (out << to_string(capabilityInfo)) : (out << "<null>"));
  out << ")";
}


StreamingCapabilityCustomization::~StreamingCapabilityCustomization() noexcept {
}


void StreamingCapabilityCustomization::__set_customParam(const std::string& val) {
  this->customParam = val;
__isset.customParam = true;
}
std::ostream& operator<<(std::ostream& out, const StreamingCapabilityCustomization& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t StreamingCapabilityCustomization::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->customParam);
          this->__isset.customParam = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t StreamingCapabilityCustomization::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("StreamingCapabilityCustomization");

  if (this->__isset.customParam) {
    xfer += oprot->writeFieldBegin("customParam", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeBinary(this->customParam);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(StreamingCapabilityCustomization &a, StreamingCapabilityCustomization &b) {
  using ::std::swap;
  swap(a.customParam, b.customParam);
  swap(a.__isset, b.__isset);
}

StreamingCapabilityCustomization::StreamingCapabilityCustomization(const StreamingCapabilityCustomization& other667) {
  customParam = other667.customParam;
  __isset = other667.__isset;
}
StreamingCapabilityCustomization& StreamingCapabilityCustomization::operator=(const StreamingCapabilityCustomization& other668) {
  customParam = other668.customParam;
  __isset = other668.__isset;
  return *this;
}
void StreamingCapabilityCustomization::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "StreamingCapabilityCustomization(";
  out << "customParam="; (__isset.customParam ? (out << to_string(customParam)) : (out << "<null>"));
  out << ")";
}


StreamingCapabilityInfoType::~StreamingCapabilityInfoType() noexcept {
}


void StreamingCapabilityInfoType::__set_capabilityId(const int32_t val) {
  this->capabilityId = val;
__isset.capabilityId = true;
}

void StreamingCapabilityInfoType::__set_name(const std::string& val) {
  this->name = val;
__isset.name = true;
}

void StreamingCapabilityInfoType::__set_persistenceType(const ResourcePersistenceType::type val) {
  this->persistenceType = val;
__isset.persistenceType = true;
}

void StreamingCapabilityInfoType::__set_available_streamingRatesMs(const std::vector<int32_t> & val) {
  this->available_streamingRatesMs = val;
__isset.available_streamingRatesMs = true;
}

void StreamingCapabilityInfoType::__set_availableSamplingRates(const std::vector<SamplingRatesEnum::type> & val) {
  this->availableSamplingRates = val;
__isset.availableSamplingRates = true;
}

void StreamingCapabilityInfoType::__set_default_samplingRateMs(const SamplingRatesEnum::type val) {
  this->default_samplingRateMs = val;
__isset.default_samplingRateMs = true;
}

void StreamingCapabilityInfoType::__set_customization(const StreamingCapabilityCustomization& val) {
  this->customization = val;
__isset.customization = true;
}
std::ostream& operator<<(std::ostream& out, const StreamingCapabilityInfoType& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t StreamingCapabilityInfoType::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->capabilityId);
          this->__isset.capabilityId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast669;
          xfer += iprot->readI32(ecast669);
          this->persistenceType = (ResourcePersistenceType::type)ecast669;
          this->__isset.persistenceType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->available_streamingRatesMs.clear();
            uint32_t _size670;
            ::apache::thrift::protocol::TType _etype673;
            xfer += iprot->readListBegin(_etype673, _size670);
            this->available_streamingRatesMs.resize(_size670);
            uint32_t _i674;
            for (_i674 = 0; _i674 < _size670; ++_i674)
            {
              xfer += iprot->readI32(this->available_streamingRatesMs[_i674]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.available_streamingRatesMs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->availableSamplingRates.clear();
            uint32_t _size675;
            ::apache::thrift::protocol::TType _etype678;
            xfer += iprot->readListBegin(_etype678, _size675);
            this->availableSamplingRates.resize(_size675);
            uint32_t _i679;
            for (_i679 = 0; _i679 < _size675; ++_i679)
            {
              int32_t ecast680;
              xfer += iprot->readI32(ecast680);
              this->availableSamplingRates[_i679] = (SamplingRatesEnum::type)ecast680;
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.availableSamplingRates = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast681;
          xfer += iprot->readI32(ecast681);
          this->default_samplingRateMs = (SamplingRatesEnum::type)ecast681;
          this->__isset.default_samplingRateMs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->customization.read(iprot);
          this->__isset.customization = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t StreamingCapabilityInfoType::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("StreamingCapabilityInfoType");

  if (this->__isset.capabilityId) {
    xfer += oprot->writeFieldBegin("capabilityId", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32(this->capabilityId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.name) {
    xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->name);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.persistenceType) {
    xfer += oprot->writeFieldBegin("persistenceType", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32((int32_t)this->persistenceType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.available_streamingRatesMs) {
    xfer += oprot->writeFieldBegin("available_streamingRatesMs", ::apache::thrift::protocol::T_LIST, 4);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->available_streamingRatesMs.size()));
      std::vector<int32_t> ::const_iterator _iter682;
      for (_iter682 = this->available_streamingRatesMs.begin(); _iter682 != this->available_streamingRatesMs.end(); ++_iter682)
      {
        xfer += oprot->writeI32((*_iter682));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.availableSamplingRates) {
    xfer += oprot->writeFieldBegin("availableSamplingRates", ::apache::thrift::protocol::T_LIST, 5);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->availableSamplingRates.size()));
      std::vector<SamplingRatesEnum::type> ::const_iterator _iter683;
      for (_iter683 = this->availableSamplingRates.begin(); _iter683 != this->availableSamplingRates.end(); ++_iter683)
      {
        xfer += oprot->writeI32((int32_t)(*_iter683));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.default_samplingRateMs) {
    xfer += oprot->writeFieldBegin("default_samplingRateMs", ::apache::thrift::protocol::T_I32, 6);
    xfer += oprot->writeI32((int32_t)this->default_samplingRateMs);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.customization) {
    xfer += oprot->writeFieldBegin("customization", ::apache::thrift::protocol::T_STRUCT, 7);
    xfer += this->customization.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(StreamingCapabilityInfoType &a, StreamingCapabilityInfoType &b) {
  using ::std::swap;
  swap(a.capabilityId, b.capabilityId);
  swap(a.name, b.name);
  swap(a.persistenceType, b.persistenceType);
  swap(a.available_streamingRatesMs, b.available_streamingRatesMs);
  swap(a.availableSamplingRates, b.availableSamplingRates);
  swap(a.default_samplingRateMs, b.default_samplingRateMs);
  swap(a.customization, b.customization);
  swap(a.__isset, b.__isset);
}

StreamingCapabilityInfoType::StreamingCapabilityInfoType(const StreamingCapabilityInfoType& other684) {
  capabilityId = other684.capabilityId;
  name = other684.name;
  persistenceType = other684.persistenceType;
  available_streamingRatesMs = other684.available_streamingRatesMs;
  availableSamplingRates = other684.availableSamplingRates;
  default_samplingRateMs = other684.default_samplingRateMs;
  customization = other684.customization;
  __isset = other684.__isset;
}
StreamingCapabilityInfoType& StreamingCapabilityInfoType::operator=(const StreamingCapabilityInfoType& other685) {
  capabilityId = other685.capabilityId;
  name = other685.name;
  persistenceType = other685.persistenceType;
  available_streamingRatesMs = other685.available_streamingRatesMs;
  availableSamplingRates = other685.availableSamplingRates;
  default_samplingRateMs = other685.default_samplingRateMs;
  customization = other685.customization;
  __isset = other685.__isset;
  return *this;
}
void StreamingCapabilityInfoType::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "StreamingCapabilityInfoType(";
  out << "capabilityId="; (__isset.capabilityId ? (out << to_string(capabilityId)) : (out << "<null>"));
  out << ", " << "name="; (__isset.name ? (out << to_string(name)) : (out << "<null>"));
  out << ", " << "persistenceType="; (__isset.persistenceType ? (out << to_string(persistenceType)) : (out << "<null>"));
  out << ", " << "available_streamingRatesMs="; (__isset.available_streamingRatesMs ? (out << to_string(available_streamingRatesMs)) : (out << "<null>"));
  out << ", " << "availableSamplingRates="; (__isset.availableSamplingRates ? (out << to_string(availableSamplingRates)) : (out << "<null>"));
  out << ", " << "default_samplingRateMs="; (__isset.default_samplingRateMs ? (out << to_string(default_samplingRateMs)) : (out << "<null>"));
  out << ", " << "customization="; (__isset.customization ? (out << to_string(customization)) : (out << "<null>"));
  out << ")";
}


QmLoopbackRequest::~QmLoopbackRequest() noexcept {
}


void QmLoopbackRequest::__set_msg(const std::string& val) {
  this->msg = val;
__isset.msg = true;
}
std::ostream& operator<<(std::ostream& out, const QmLoopbackRequest& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmLoopbackRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msg);
          this->__isset.msg = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmLoopbackRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmLoopbackRequest");

  if (this->__isset.msg) {
    xfer += oprot->writeFieldBegin("msg", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->msg);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmLoopbackRequest &a, QmLoopbackRequest &b) {
  using ::std::swap;
  swap(a.msg, b.msg);
  swap(a.__isset, b.__isset);
}

QmLoopbackRequest::QmLoopbackRequest(const QmLoopbackRequest& other686) {
  msg = other686.msg;
  __isset = other686.__isset;
}
QmLoopbackRequest& QmLoopbackRequest::operator=(const QmLoopbackRequest& other687) {
  msg = other687.msg;
  __isset = other687.__isset;
  return *this;
}
void QmLoopbackRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmLoopbackRequest(";
  out << "msg="; (__isset.msg ? (out << to_string(msg)) : (out << "<null>"));
  out << ")";
}


QmLoopback::~QmLoopback() noexcept {
}


void QmLoopback::__set_status(const QmStatusType::type val) {
  this->status = val;
__isset.status = true;
}

void QmLoopback::__set_msg(const std::string& val) {
  this->msg = val;
__isset.msg = true;
}
std::ostream& operator<<(std::ostream& out, const QmLoopback& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmLoopback::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast688;
          xfer += iprot->readI32(ecast688);
          this->status = (QmStatusType::type)ecast688;
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msg);
          this->__isset.msg = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmLoopback::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmLoopback");

  if (this->__isset.status) {
    xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->status);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.msg) {
    xfer += oprot->writeFieldBegin("msg", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->msg);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmLoopback &a, QmLoopback &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.msg, b.msg);
  swap(a.__isset, b.__isset);
}

QmLoopback::QmLoopback(const QmLoopback& other689) {
  status = other689.status;
  msg = other689.msg;
  __isset = other689.__isset;
}
QmLoopback& QmLoopback::operator=(const QmLoopback& other690) {
  status = other690.status;
  msg = other690.msg;
  __isset = other690.__isset;
  return *this;
}
void QmLoopback::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmLoopback(";
  out << "status="; (__isset.status ? (out << to_string(status)) : (out << "<null>"));
  out << ", " << "msg="; (__isset.msg ? (out << to_string(msg)) : (out << "<null>"));
  out << ")";
}


QmLoopbackResponse::~QmLoopbackResponse() noexcept {
}


void QmLoopbackResponse::__set_loopbackList(const std::vector<QmLoopback> & val) {
  this->loopbackList = val;
__isset.loopbackList = true;
}
std::ostream& operator<<(std::ostream& out, const QmLoopbackResponse& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t QmLoopbackResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->loopbackList.clear();
            uint32_t _size691;
            ::apache::thrift::protocol::TType _etype694;
            xfer += iprot->readListBegin(_etype694, _size691);
            this->loopbackList.resize(_size691);
            uint32_t _i695;
            for (_i695 = 0; _i695 < _size691; ++_i695)
            {
              xfer += this->loopbackList[_i695].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.loopbackList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t QmLoopbackResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("QmLoopbackResponse");

  if (this->__isset.loopbackList) {
    xfer += oprot->writeFieldBegin("loopbackList", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->loopbackList.size()));
      std::vector<QmLoopback> ::const_iterator _iter696;
      for (_iter696 = this->loopbackList.begin(); _iter696 != this->loopbackList.end(); ++_iter696)
      {
        xfer += (*_iter696).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(QmLoopbackResponse &a, QmLoopbackResponse &b) {
  using ::std::swap;
  swap(a.loopbackList, b.loopbackList);
  swap(a.__isset, b.__isset);
}

QmLoopbackResponse::QmLoopbackResponse(const QmLoopbackResponse& other697) {
  loopbackList = other697.loopbackList;
  __isset = other697.__isset;
}
QmLoopbackResponse& QmLoopbackResponse::operator=(const QmLoopbackResponse& other698) {
  loopbackList = other698.loopbackList;
  __isset = other698.__isset;
  return *this;
}
void QmLoopbackResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "QmLoopbackResponse(";
  out << "loopbackList="; (__isset.loopbackList ? (out << to_string(loopbackList)) : (out << "<null>"));
  out << ")";
}


StreamingCapabilitySelect::~StreamingCapabilitySelect() noexcept {
}


void StreamingCapabilitySelect::__set_capabilityNameOrId(const std::string& val) {
  this->capabilityNameOrId = val;
__isset.capabilityNameOrId = true;
}

void StreamingCapabilitySelect::__set_select_streaming_rate_ms(const int32_t val) {
  this->select_streaming_rate_ms = val;
__isset.select_streaming_rate_ms = true;
}

void StreamingCapabilitySelect::__set_broadcast(const bool val) {
  this->broadcast = val;
__isset.broadcast = true;
}

void StreamingCapabilitySelect::__set_custom_select(const std::string& val) {
  this->custom_select = val;
__isset.custom_select = true;
}

void StreamingCapabilitySelect::__set_enableOrDisable(const bool val) {
  this->enableOrDisable = val;
__isset.enableOrDisable = true;
}
std::ostream& operator<<(std::ostream& out, const StreamingCapabilitySelect& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t StreamingCapabilitySelect::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->capabilityNameOrId);
          this->__isset.capabilityNameOrId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->select_streaming_rate_ms);
          this->__isset.select_streaming_rate_ms = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->broadcast);
          this->__isset.broadcast = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->custom_select);
          this->__isset.custom_select = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->enableOrDisable);
          this->__isset.enableOrDisable = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t StreamingCapabilitySelect::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("StreamingCapabilitySelect");

  if (this->__isset.capabilityNameOrId) {
    xfer += oprot->writeFieldBegin("capabilityNameOrId", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->capabilityNameOrId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.select_streaming_rate_ms) {
    xfer += oprot->writeFieldBegin("select_streaming_rate_ms", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->select_streaming_rate_ms);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.broadcast) {
    xfer += oprot->writeFieldBegin("broadcast", ::apache::thrift::protocol::T_BOOL, 3);
    xfer += oprot->writeBool(this->broadcast);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.custom_select) {
    xfer += oprot->writeFieldBegin("custom_select", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeBinary(this->custom_select);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.enableOrDisable) {
    xfer += oprot->writeFieldBegin("enableOrDisable", ::apache::thrift::protocol::T_BOOL, 5);
    xfer += oprot->writeBool(this->enableOrDisable);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(StreamingCapabilitySelect &a, StreamingCapabilitySelect &b) {
  using ::std::swap;
  swap(a.capabilityNameOrId, b.capabilityNameOrId);
  swap(a.select_streaming_rate_ms, b.select_streaming_rate_ms);
  swap(a.broadcast, b.broadcast);
  swap(a.custom_select, b.custom_select);
  swap(a.enableOrDisable, b.enableOrDisable);
  swap(a.__isset, b.__isset);
}

StreamingCapabilitySelect::StreamingCapabilitySelect(const StreamingCapabilitySelect& other699) {
  capabilityNameOrId = other699.capabilityNameOrId;
  select_streaming_rate_ms = other699.select_streaming_rate_ms;
  broadcast = other699.broadcast;
  custom_select = other699.custom_select;
  enableOrDisable = other699.enableOrDisable;
  __isset = other699.__isset;
}
StreamingCapabilitySelect& StreamingCapabilitySelect::operator=(const StreamingCapabilitySelect& other700) {
  capabilityNameOrId = other700.capabilityNameOrId;
  select_streaming_rate_ms = other700.select_streaming_rate_ms;
  broadcast = other700.broadcast;
  custom_select = other700.custom_select;
  enableOrDisable = other700.enableOrDisable;
  __isset = other700.__isset;
  return *this;
}
void StreamingCapabilitySelect::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "StreamingCapabilitySelect(";
  out << "capabilityNameOrId="; (__isset.capabilityNameOrId ? (out << to_string(capabilityNameOrId)) : (out << "<null>"));
  out << ", " << "select_streaming_rate_ms="; (__isset.select_streaming_rate_ms ? (out << to_string(select_streaming_rate_ms)) : (out << "<null>"));
  out << ", " << "broadcast="; (__isset.broadcast ? (out << to_string(broadcast)) : (out << "<null>"));
  out << ", " << "custom_select="; (__isset.custom_select ? (out << to_string(custom_select)) : (out << "<null>"));
  out << ", " << "enableOrDisable="; (__isset.enableOrDisable ? (out << to_string(enableOrDisable)) : (out << "<null>"));
  out << ")";
}


StreamingCapabilitySelectList::~StreamingCapabilitySelectList() noexcept {
}


void StreamingCapabilitySelectList::__set_streamingCapabilitySelectList(const std::vector<StreamingCapabilitySelect> & val) {
  this->streamingCapabilitySelectList = val;
__isset.streamingCapabilitySelectList = true;
}
std::ostream& operator<<(std::ostream& out, const StreamingCapabilitySelectList& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t StreamingCapabilitySelectList::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->streamingCapabilitySelectList.clear();
            uint32_t _size701;
            ::apache::thrift::protocol::TType _etype704;
            xfer += iprot->readListBegin(_etype704, _size701);
            this->streamingCapabilitySelectList.resize(_size701);
            uint32_t _i705;
            for (_i705 = 0; _i705 < _size701; ++_i705)
            {
              xfer += this->streamingCapabilitySelectList[_i705].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.streamingCapabilitySelectList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t StreamingCapabilitySelectList::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("StreamingCapabilitySelectList");

  if (this->__isset.streamingCapabilitySelectList) {
    xfer += oprot->writeFieldBegin("streamingCapabilitySelectList", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->streamingCapabilitySelectList.size()));
      std::vector<StreamingCapabilitySelect> ::const_iterator _iter706;
      for (_iter706 = this->streamingCapabilitySelectList.begin(); _iter706 != this->streamingCapabilitySelectList.end(); ++_iter706)
      {
        xfer += (*_iter706).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(StreamingCapabilitySelectList &a, StreamingCapabilitySelectList &b) {
  using ::std::swap;
  swap(a.streamingCapabilitySelectList, b.streamingCapabilitySelectList);
  swap(a.__isset, b.__isset);
}

StreamingCapabilitySelectList::StreamingCapabilitySelectList(const StreamingCapabilitySelectList& other707) {
  streamingCapabilitySelectList = other707.streamingCapabilitySelectList;
  __isset = other707.__isset;
}
StreamingCapabilitySelectList& StreamingCapabilitySelectList::operator=(const StreamingCapabilitySelectList& other708) {
  streamingCapabilitySelectList = other708.streamingCapabilitySelectList;
  __isset = other708.__isset;
  return *this;
}
void StreamingCapabilitySelectList::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "StreamingCapabilitySelectList(";
  out << "streamingCapabilitySelectList="; (__isset.streamingCapabilitySelectList ? (out << to_string(streamingCapabilitySelectList)) : (out << "<null>"));
  out << ")";
}


ProfilingRawRequestParams::~ProfilingRawRequestParams() noexcept {
}


void ProfilingRawRequestParams::__set_rpcName(const std::string& val) {
  this->rpcName = val;
__isset.rpcName = true;
}

void ProfilingRawRequestParams::__set_request(const std::string& val) {
  this->request = val;
__isset.request = true;
}

void ProfilingRawRequestParams::__set_timeout(const int32_t val) {
  this->timeout = val;
__isset.timeout = true;
}

void ProfilingRawRequestParams::__set_capabilityName(const std::string& val) {
  this->capabilityName = val;
__isset.capabilityName = true;
}
std::ostream& operator<<(std::ostream& out, const ProfilingRawRequestParams& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProfilingRawRequestParams::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->rpcName);
          this->__isset.rpcName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->request);
          this->__isset.request = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->timeout);
          this->__isset.timeout = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->capabilityName);
          this->__isset.capabilityName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProfilingRawRequestParams::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProfilingRawRequestParams");

  if (this->__isset.rpcName) {
    xfer += oprot->writeFieldBegin("rpcName", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->rpcName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.request) {
    xfer += oprot->writeFieldBegin("request", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeBinary(this->request);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.timeout) {
    xfer += oprot->writeFieldBegin("timeout", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->timeout);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.capabilityName) {
    xfer += oprot->writeFieldBegin("capabilityName", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->capabilityName);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProfilingRawRequestParams &a, ProfilingRawRequestParams &b) {
  using ::std::swap;
  swap(a.rpcName, b.rpcName);
  swap(a.request, b.request);
  swap(a.timeout, b.timeout);
  swap(a.capabilityName, b.capabilityName);
  swap(a.__isset, b.__isset);
}

ProfilingRawRequestParams::ProfilingRawRequestParams(const ProfilingRawRequestParams& other709) {
  rpcName = other709.rpcName;
  request = other709.request;
  timeout = other709.timeout;
  capabilityName = other709.capabilityName;
  __isset = other709.__isset;
}
ProfilingRawRequestParams& ProfilingRawRequestParams::operator=(const ProfilingRawRequestParams& other710) {
  rpcName = other710.rpcName;
  request = other710.request;
  timeout = other710.timeout;
  capabilityName = other710.capabilityName;
  __isset = other710.__isset;
  return *this;
}
void ProfilingRawRequestParams::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProfilingRawRequestParams(";
  out << "rpcName="; (__isset.rpcName ? (out << to_string(rpcName)) : (out << "<null>"));
  out << ", " << "request="; (__isset.request ? (out << to_string(request)) : (out << "<null>"));
  out << ", " << "timeout="; (__isset.timeout ? (out << to_string(timeout)) : (out << "<null>"));
  out << ", " << "capabilityName="; (__isset.capabilityName ? (out << to_string(capabilityName)) : (out << "<null>"));
  out << ")";
}


ProfilingRequestParams::~ProfilingRequestParams() noexcept {
}


void ProfilingRequestParams::__set_rpcName(const std::string& val) {
  this->rpcName = val;
__isset.rpcName = true;
}

void ProfilingRequestParams::__set_jsonInput(const std::string& val) {
  this->jsonInput = val;
__isset.jsonInput = true;
}

void ProfilingRequestParams::__set_returnConfig(const ProtoBufReturns& val) {
  this->returnConfig = val;
__isset.returnConfig = true;
}

void ProfilingRequestParams::__set_timeout(const int32_t val) {
  this->timeout = val;
__isset.timeout = true;
}
std::ostream& operator<<(std::ostream& out, const ProfilingRequestParams& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProfilingRequestParams::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->rpcName);
          this->__isset.rpcName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->jsonInput);
          this->__isset.jsonInput = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->returnConfig.read(iprot);
          this->__isset.returnConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->timeout);
          this->__isset.timeout = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProfilingRequestParams::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProfilingRequestParams");

  if (this->__isset.rpcName) {
    xfer += oprot->writeFieldBegin("rpcName", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->rpcName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.jsonInput) {
    xfer += oprot->writeFieldBegin("jsonInput", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->jsonInput);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.returnConfig) {
    xfer += oprot->writeFieldBegin("returnConfig", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->returnConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.timeout) {
    xfer += oprot->writeFieldBegin("timeout", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->timeout);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProfilingRequestParams &a, ProfilingRequestParams &b) {
  using ::std::swap;
  swap(a.rpcName, b.rpcName);
  swap(a.jsonInput, b.jsonInput);
  swap(a.returnConfig, b.returnConfig);
  swap(a.timeout, b.timeout);
  swap(a.__isset, b.__isset);
}

ProfilingRequestParams::ProfilingRequestParams(const ProfilingRequestParams& other711) {
  rpcName = other711.rpcName;
  jsonInput = other711.jsonInput;
  returnConfig = other711.returnConfig;
  timeout = other711.timeout;
  __isset = other711.__isset;
}
ProfilingRequestParams& ProfilingRequestParams::operator=(const ProfilingRequestParams& other712) {
  rpcName = other712.rpcName;
  jsonInput = other712.jsonInput;
  returnConfig = other712.returnConfig;
  timeout = other712.timeout;
  __isset = other712.__isset;
  return *this;
}
void ProfilingRequestParams::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProfilingRequestParams(";
  out << "rpcName="; (__isset.rpcName ? (out << to_string(rpcName)) : (out << "<null>"));
  out << ", " << "jsonInput="; (__isset.jsonInput ? (out << to_string(jsonInput)) : (out << "<null>"));
  out << ", " << "returnConfig="; (__isset.returnConfig ? (out << to_string(returnConfig)) : (out << "<null>"));
  out << ", " << "timeout="; (__isset.timeout ? (out << to_string(timeout)) : (out << "<null>"));
  out << ")";
}


ProfilingBackendParams::~ProfilingBackendParams() noexcept {
}


void ProfilingBackendParams::__set_backendName(const std::string& val) {
  this->backendName = val;
__isset.backendName = true;
}
std::ostream& operator<<(std::ostream& out, const ProfilingBackendParams& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProfilingBackendParams::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->backendName);
          this->__isset.backendName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProfilingBackendParams::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProfilingBackendParams");

  if (this->__isset.backendName) {
    xfer += oprot->writeFieldBegin("backendName", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->backendName);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProfilingBackendParams &a, ProfilingBackendParams &b) {
  using ::std::swap;
  swap(a.backendName, b.backendName);
  swap(a.__isset, b.__isset);
}

ProfilingBackendParams::ProfilingBackendParams(const ProfilingBackendParams& other713) {
  backendName = other713.backendName;
  __isset = other713.__isset;
}
ProfilingBackendParams& ProfilingBackendParams::operator=(const ProfilingBackendParams& other714) {
  backendName = other714.backendName;
  __isset = other714.__isset;
  return *this;
}
void ProfilingBackendParams::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProfilingBackendParams(";
  out << "backendName="; (__isset.backendName ? (out << to_string(backendName)) : (out << "<null>"));
  out << ")";
}


ProfilingLoopbackParams::~ProfilingLoopbackParams() noexcept {
}


void ProfilingLoopbackParams::__set_backendName(const std::string& val) {
  this->backendName = val;
__isset.backendName = true;
}

void ProfilingLoopbackParams::__set_loopbackRequest(const QmLoopbackRequest& val) {
  this->loopbackRequest = val;
__isset.loopbackRequest = true;
}
std::ostream& operator<<(std::ostream& out, const ProfilingLoopbackParams& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProfilingLoopbackParams::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->backendName);
          this->__isset.backendName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->loopbackRequest.read(iprot);
          this->__isset.loopbackRequest = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProfilingLoopbackParams::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProfilingLoopbackParams");

  if (this->__isset.backendName) {
    xfer += oprot->writeFieldBegin("backendName", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->backendName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.loopbackRequest) {
    xfer += oprot->writeFieldBegin("loopbackRequest", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->loopbackRequest.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProfilingLoopbackParams &a, ProfilingLoopbackParams &b) {
  using ::std::swap;
  swap(a.backendName, b.backendName);
  swap(a.loopbackRequest, b.loopbackRequest);
  swap(a.__isset, b.__isset);
}

ProfilingLoopbackParams::ProfilingLoopbackParams(const ProfilingLoopbackParams& other715) {
  backendName = other715.backendName;
  loopbackRequest = other715.loopbackRequest;
  __isset = other715.__isset;
}
ProfilingLoopbackParams& ProfilingLoopbackParams::operator=(const ProfilingLoopbackParams& other716) {
  backendName = other716.backendName;
  loopbackRequest = other716.loopbackRequest;
  __isset = other716.__isset;
  return *this;
}
void ProfilingLoopbackParams::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProfilingLoopbackParams(";
  out << "backendName="; (__isset.backendName ? (out << to_string(backendName)) : (out << "<null>"));
  out << ", " << "loopbackRequest="; (__isset.loopbackRequest ? (out << to_string(loopbackRequest)) : (out << "<null>"));
  out << ")";
}


ProfilingStartParams::~ProfilingStartParams() noexcept {
}


void ProfilingStartParams::__set_backendName(const std::string& val) {
  this->backendName = val;
__isset.backendName = true;
}

void ProfilingStartParams::__set_capabilitySelect(const StreamingCapabilitySelect& val) {
  this->capabilitySelect = val;
__isset.capabilitySelect = true;
}
std::ostream& operator<<(std::ostream& out, const ProfilingStartParams& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProfilingStartParams::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->backendName);
          this->__isset.backendName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->capabilitySelect.read(iprot);
          this->__isset.capabilitySelect = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProfilingStartParams::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProfilingStartParams");

  if (this->__isset.backendName) {
    xfer += oprot->writeFieldBegin("backendName", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->backendName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.capabilitySelect) {
    xfer += oprot->writeFieldBegin("capabilitySelect", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->capabilitySelect.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProfilingStartParams &a, ProfilingStartParams &b) {
  using ::std::swap;
  swap(a.backendName, b.backendName);
  swap(a.capabilitySelect, b.capabilitySelect);
  swap(a.__isset, b.__isset);
}

ProfilingStartParams::ProfilingStartParams(const ProfilingStartParams& other717) {
  backendName = other717.backendName;
  capabilitySelect = other717.capabilitySelect;
  __isset = other717.__isset;
}
ProfilingStartParams& ProfilingStartParams::operator=(const ProfilingStartParams& other718) {
  backendName = other718.backendName;
  capabilitySelect = other718.capabilitySelect;
  __isset = other718.__isset;
  return *this;
}
void ProfilingStartParams::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProfilingStartParams(";
  out << "backendName="; (__isset.backendName ? (out << to_string(backendName)) : (out << "<null>"));
  out << ", " << "capabilitySelect="; (__isset.capabilitySelect ? (out << to_string(capabilitySelect)) : (out << "<null>"));
  out << ")";
}


ProfilingMetadataParams::~ProfilingMetadataParams() noexcept {
}


void ProfilingMetadataParams::__set_rpcName(const std::string& val) {
  this->rpcName = val;
__isset.rpcName = true;
}

void ProfilingMetadataParams::__set_entityType(const ProtoBufPacketType::type val) {
  this->entityType = val;
__isset.entityType = true;
}
std::ostream& operator<<(std::ostream& out, const ProfilingMetadataParams& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ProfilingMetadataParams::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->rpcName);
          this->__isset.rpcName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast719;
          xfer += iprot->readI32(ecast719);
          this->entityType = (ProtoBufPacketType::type)ecast719;
          this->__isset.entityType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ProfilingMetadataParams::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ProfilingMetadataParams");

  if (this->__isset.rpcName) {
    xfer += oprot->writeFieldBegin("rpcName", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->rpcName);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.entityType) {
    xfer += oprot->writeFieldBegin("entityType", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->entityType);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ProfilingMetadataParams &a, ProfilingMetadataParams &b) {
  using ::std::swap;
  swap(a.rpcName, b.rpcName);
  swap(a.entityType, b.entityType);
  swap(a.__isset, b.__isset);
}

ProfilingMetadataParams::ProfilingMetadataParams(const ProfilingMetadataParams& other720) {
  rpcName = other720.rpcName;
  entityType = other720.entityType;
  __isset = other720.__isset;
}
ProfilingMetadataParams& ProfilingMetadataParams::operator=(const ProfilingMetadataParams& other721) {
  rpcName = other721.rpcName;
  entityType = other721.entityType;
  __isset = other721.__isset;
  return *this;
}
void ProfilingMetadataParams::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ProfilingMetadataParams(";
  out << "rpcName="; (__isset.rpcName ? (out << to_string(rpcName)) : (out << "<null>"));
  out << ", " << "entityType="; (__isset.entityType ? (out << to_string(entityType)) : (out << "<null>"));
  out << ")";
}

} // namespace
