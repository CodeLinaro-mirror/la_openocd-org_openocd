/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef Common_TYPES_H
#define Common_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>


namespace Uts {

struct ErrorCode {
  enum type {
    DEVICE_NO_ERROR = 0,
    DEVICE_UNKNOWN_ERROR = 1,
    DEVICE_INVALID_PARAMETERS = 2,
    DEVICE_PERMISSIONS_ERROR = 3,
    DEVICE_INVALID_DEVICE_HANDLE = 4,
    DEVICE_INVALID_PROTOCOL_HANDLE = 5,
    DEVICE_INVALID_CONNECTION_HANDLE = 6,
    DEVICE_CONNECTION_LOCKED = 7,
    DEVICE_DISCONNECTED = 8,
    DEVICE_PROTOCOL_INVALID = 9,
    DEVICE_PROTOCOL_DISCONNECTED = 10,
    DEVICE_PROTOCOL_UNRESPONSIVE = 11,
    DEVICE_TX_CANCELLED = 12,
    DEVICE_TIMEOUT = 13,
    DEVICE_INVALID_PROCESSOR = 14,
    DEVICE_INVALID_PACKET = 15,
    DEVICE_RESPONSE_ERROR = 16,
    DEVICE_INVALID_LOG_SESSION = 17,
    DEVICE_SERVICE_NOT_INITIALIZED = 18,
    DEVICE_TCP_PORT_FAILURE = 19,
    DEVICE_SERVICE_ALREADY_INITIALIZED = 20,
    DEVICE_LICENSE_ERROR = 21,
    DEVICE_OTP_PROGRAMED = 22,
    DEVICE_DECRYPTION_FAILED = 23
  };
};

extern const std::map<int, const char*> _ErrorCode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ErrorCode::type& val);

std::string to_string(const ErrorCode::type& val);

struct QutsOperatingMode {
  enum type {
    DEVICE_DISCOVERY = 0,
    POST_PROCESSING = 1
  };
};

extern const std::map<int, const char*> _QutsOperatingMode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const QutsOperatingMode::type& val);

std::string to_string(const QutsOperatingMode::type& val);

struct OpenProp {
  enum type {
    OPEN_NONE = 0,
    OPEN_READ = 1,
    OPEN_WRITE = 2,
    OPEN_READ_WRITE = 3
  };
};

extern const std::map<int, const char*> _OpenProp_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const OpenProp::type& val);

std::string to_string(const OpenProp::type& val);

struct ProtocolType {
  enum type {
    PROT_UNKNOWN = -1,
    PROT_DIAG = 0,
    PROT_QMI = 1,
    PROT_ADB = 2,
    PROT_SAHARA = 3,
    PROT_FIREHOSE = 4,
    PROT_QDSS = 5,
    PROT_ADPL = 6,
    PROT_FASTBOOT = 7,
    PROT_NMEA = 8,
    PROT_DUN = 9,
    PROT_RMNET = 10,
    PROT_RNDIS = 11,
    PROT_MBIM = 12,
    PROT_PROTOBUF = 13,
    PROT_TAC = 14,
    PROT_EPM = 15,
    PROT_TELNET = 16,
    PROT_FTP = 17,
    PROT_EUD = 18,
    PROT_MAX = 19
  };
};

extern const std::map<int, const char*> _ProtocolType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ProtocolType::type& val);

std::string to_string(const ProtocolType::type& val);

struct ConnectionType {
  enum type {
    CONNECT_UNKNOWN = -1,
    CONNECT_USB = 0,
    CONNECT_TCP = 1,
    CONNECT_FILE = 2,
    CONNECT_ETHERNET = 3,
    CONNECT_MAX = 4
  };
};

extern const std::map<int, const char*> _ConnectionType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ConnectionType::type& val);

std::string to_string(const ConnectionType::type& val);

struct ProtocolState {
  enum type {
    STATE_AVAILABLE = 0,
    STATE_DISCONNECTED = 1,
    STATE_UNRESPONSIVE = 2,
    STATE_INITIALIZING = 3
  };
};

extern const std::map<int, const char*> _ProtocolState_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ProtocolState::type& val);

std::string to_string(const ProtocolState::type& val);

struct Direction {
  enum type {
    DIR_RX = 1,
    DIR_TX = 2
  };
};

extern const std::map<int, const char*> _Direction_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const Direction::type& val);

std::string to_string(const Direction::type& val);

struct FlowControlStatus {
  enum type {
    FLOW_CONTROL_OFF = 0,
    FLOW_CONTROL_ON = 1
  };
};

extern const std::map<int, const char*> _FlowControlStatus_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const FlowControlStatus::type& val);

std::string to_string(const FlowControlStatus::type& val);

struct FlowControlLevel {
  enum type {
    FLOW_CONTROL_LOW = 0,
    FLOW_CONTROL_MID = 1,
    FLOW_CONTROL_HIGH = 2,
    FLOW_CONTROL_DNE = 3
  };
};

extern const std::map<int, const char*> _FlowControlLevel_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const FlowControlLevel::type& val);

std::string to_string(const FlowControlLevel::type& val);

struct LockState {
  enum type {
    LOCK_STATE_OFF = 0,
    LOCK_STATE_ON = 1
  };
};

extern const std::map<int, const char*> _LockState_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const LockState::type& val);

std::string to_string(const LockState::type& val);

struct MbnDownloadState {
  enum type {
    INVALID = 0,
    RESET = 1,
    REQUEST_SENT = 2,
    WAIT_IMMEDIATE_REPONSE = 3,
    IMMEDIATE_REPONSE_RECIEVED = 4,
    WAIT_DELAYED_RESPONSE = 5,
    DELAYED_RESPONSE_RECEIVED = 6,
    DOWNLOAD_COMPLETED = 7,
    DEVICE_CONFIGURATION_STATUS_CHECK_COMPLETED = 8,
    MBN_FILE_DOWNLOAD_COMPLETED = 9,
    XML_FILE_DOWNLOAD_COMPLETED = 10,
    FILE_REPLAYSTATE = 11,
    ERROR_STATE = 12
  };
};

extern const std::map<int, const char*> _MbnDownloadState_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const MbnDownloadState::type& val);

std::string to_string(const MbnDownloadState::type& val);

struct DeviceMode {
  enum type {
    DEVICE_MODE_NONE = 0,
    DEVICE_MODE_SAHARA_DOWNLOAD = 1,
    DEVICE_MODE_SAHARA_CRASH = 2,
    DEVICE_MODE_SAHARA_EFS_SYNC = 4
  };
};

extern const std::map<int, const char*> _DeviceMode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const DeviceMode::type& val);

std::string to_string(const DeviceMode::type& val);

struct KeyClass {
  enum type {
    KEY_NONE = 0,
    KEY_PROPRIETARY = 1
  };
};

extern const std::map<int, const char*> _KeyClass_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const KeyClass::type& val);

std::string to_string(const KeyClass::type& val);

struct KeyLoadStatus {
  enum type {
    KEY_LOAD_SUCCESS = 0,
    KEY_LOAD_NO_SERVER_CONNECTION = 1,
    KEY_LOAD_ERROR = 2,
    KEY_LOAD_AUTHENTICATION_ERROR = 3
  };
};

extern const std::map<int, const char*> _KeyLoadStatus_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const KeyLoadStatus::type& val);

std::string to_string(const KeyLoadStatus::type& val);

struct DiagPacketType {
  enum type {
    UNKNOWN_PACKET_TYPE = -1,
    LOG_PACKET = 0,
    EVENT = 1,
    NV_ITEM = 2,
    DEBUG_MSG = 3,
    REQUEST = 4,
    RESPONSE = 5,
    SUBSYS_REQUEST = 6,
    SUBSYS_RESPONSE = 7,
    SUBSYSV2_REQUEST = 8,
    SUBSYSV2_IMMEDIATE_RESPONSE = 9,
    SUBSYSV2_DELAYED_RESPONSE = 10,
    QTRACE = 11,
    QSH_METRIC = 12,
    QSH_EVENT = 13
  };
};

extern const std::map<int, const char*> _DiagPacketType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const DiagPacketType::type& val);

std::string to_string(const DiagPacketType::type& val);

struct DataSourceType {
  enum type {
    FILE_DATA = 0,
    BINARY_MASK_DATA = 1
  };
};

extern const std::map<int, const char*> _DataSourceType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const DataSourceType::type& val);

std::string to_string(const DataSourceType::type& val);

struct LogMaskFormat {
  enum type {
    INVALID = -1,
    CFG_FORMAT = 0,
    CFG2_FORMAT = 1,
    DMC_FORMAT = 2,
    CFG_FORMAT_ENABLE_MULTISIM = 3,
    CFG2_FORMAT_ENABLE_MULTISIM = 4,
    DMC_FORMAT_ENABLE_MULTISIM = 5
  };
};

extern const std::map<int, const char*> _LogMaskFormat_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const LogMaskFormat::type& val);

std::string to_string(const LogMaskFormat::type& val);

struct QShrink4DownloadState {
  enum type {
    QSR4_STATE_INIT = 0,
    QSR4_STATE_DOWNLOADING = 1,
    QSR4_STATE_DOWNLOADED = 2,
    QSR4_STATE_LOADED = 3,
    QSR4_STATE_FAILED = 4
  };
};

extern const std::map<int, const char*> _QShrink4DownloadState_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const QShrink4DownloadState::type& val);

std::string to_string(const QShrink4DownloadState::type& val);

struct InternalPacketFlag {
  enum type {
    INTERNAL_FLAG_NOT_SET = 0,
    INTERNAL_PACKET_ONLY = 1,
    EXTERNAL_PACKET_ONLY = 2
  };
};

extern const std::map<int, const char*> _InternalPacketFlag_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const InternalPacketFlag::type& val);

std::string to_string(const InternalPacketFlag::type& val);

struct DiagReturnFlags {
  enum type {
    NO_FLAGS_SET = 0,
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_TYPE = 16,
    PACKET_ID = 32,
    PACKET_NAME = 64,
    BINARY_PAYLOAD = 128,
    PARSED_TEXT = 256,
    TIME_STAMP_DATA = 512,
    TIME_STAMP_STRING = 1024,
    SUBSCRIPTION_ID = 2048,
    PROCESSOR_ID = 4096,
    HW_TIME_STAMP_DATA = 8192,
    HW_TIME_STAMP_STRING = 16384,
    ULOG_SOURCE = 32768,
    MORE_RESPONSES_FLAG = 65536,
    SUMMARY_TEXT = 131072,
    QDSS_CHANNEL_ID = 262144,
    QDSS_MASTER_ID = 524288,
    QDSS_AT_ID = 1048576,
    DEFAULT_FORMAT_TEXT = 2097152,
    CALL_FRAME_NUMBER = 4194304,
    TIME_STAMP_TOD_ADJUSTED_DATA = 8388608,
    TIME_STAMP_TOD_ADJUSTED_STRING = 16777216,
    PACKET_SIZE = 33554432,
    QTRACE_TAG_LIST = 67108864,
    MISCELLANEOUS_ID = 134217728,
    QUERY_RESULT_PICKLED = 268435456,
    FORMAT_STRING_HASH = 536870912,
    ENCRYPTION_KEY_INFO = 1073741824
  };
};

extern const std::map<int, const char*> _DiagReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const DiagReturnFlags::type& val);

std::string to_string(const DiagReturnFlags::type& val);

struct DiagReturnFlagsExt {
  enum type {
    NO_USER_PARSING = 0,
    USER_PARSED_TEXT = 1,
    USER_PARSED_SUMMARY = 2,
    EXCEPTION_MESSAGE_TYPE = 4,
    QUERY_RESULT_PICKLED_AND_JSON = 8
  };
};

extern const std::map<int, const char*> _DiagReturnFlagsExt_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const DiagReturnFlagsExt::type& val);

std::string to_string(const DiagReturnFlagsExt::type& val);

struct SearchOptions {
  enum type {
    NO_OPTIONS_SET = 0,
    USE_REGEX_MATCH = 1,
    INVERT_SEARCH = 2,
    CASE_INSENSITIVE = 4
  };
};

extern const std::map<int, const char*> _SearchOptions_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const SearchOptions::type& val);

std::string to_string(const SearchOptions::type& val);

struct ExceptionMessageType {
  enum type {
    NOT_SET = 0,
    UNKNOWN_EXCEPTION_MESSAGE = 1,
    NOT_ENOUGH_ARGUMENT_COUNT_PROVIDED = 2
  };
};

extern const std::map<int, const char*> _ExceptionMessageType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ExceptionMessageType::type& val);

std::string to_string(const ExceptionMessageType::type& val);

struct AnnotationReturnFlags {
  enum type {
    NO_FLAGS_SET = 0,
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    MESSAGE_ID = 16,
    PARSED_TEXT = 32
  };
};

extern const std::map<int, const char*> _AnnotationReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const AnnotationReturnFlags::type& val);

std::string to_string(const AnnotationReturnFlags::type& val);

struct QmiPacketType {
  enum type {
    QMI_REQUEST = 0,
    QMI_RESPONSE = 1,
    QMI_INDICATION = 2
  };
};

extern const std::map<int, const char*> _QmiPacketType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const QmiPacketType::type& val);

std::string to_string(const QmiPacketType::type& val);

struct QmiReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_TYPE = 16,
    PACKET_NAME = 64,
    BINARY_PAYLOAD = 128,
    PARSED_XML = 256,
    SERVICE_ID = 512,
    MESSAGE_ID = 1024
  };
};

extern const std::map<int, const char*> _QmiReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const QmiReturnFlags::type& val);

std::string to_string(const QmiReturnFlags::type& val);

struct AdbReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_TEXT = 256
  };
};

extern const std::map<int, const char*> _AdbReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const AdbReturnFlags::type& val);

std::string to_string(const AdbReturnFlags::type& val);

struct TelnetReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_TEXT = 16
  };
};

extern const std::map<int, const char*> _TelnetReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TelnetReturnFlags::type& val);

std::string to_string(const TelnetReturnFlags::type& val);

struct SaharaReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_ID = 32,
    PACKET_NAME = 64,
    BINARY_PAYLOAD = 128
  };
};

extern const std::map<int, const char*> _SaharaReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const SaharaReturnFlags::type& val);

std::string to_string(const SaharaReturnFlags::type& val);

struct FastbootReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_TEXT = 256
  };
};

extern const std::map<int, const char*> _FastbootReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const FastbootReturnFlags::type& val);

std::string to_string(const FastbootReturnFlags::type& val);

struct EudReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_ID = 32,
    PACKET_NAME = 64,
    BINARY_PAYLOAD = 128
  };
};

extern const std::map<int, const char*> _EudReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const EudReturnFlags::type& val);

std::string to_string(const EudReturnFlags::type& val);

struct ProtoBufPacketType {
  enum type {
    UNKNOWN_PACKET_TYPE = -1,
    REQUEST = 0,
    RESPONSE = 1
  };
};

extern const std::map<int, const char*> _ProtoBufPacketType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ProtoBufPacketType::type& val);

std::string to_string(const ProtoBufPacketType::type& val);

struct ProtoBufReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_TYPE = 16,
    PACKET_NAME = 64,
    BINARY_PAYLOAD = 128,
    PARSED_TEXT = 256,
    RPC_ID = 512,
    QUERY_RESULT_PICKLED = 1024,
    PARSED_TEXT_JSON = 2048,
    QUERY_RESULT_PICKLED_AND_JSON = 4096
  };
};

extern const std::map<int, const char*> _ProtoBufReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ProtoBufReturnFlags::type& val);

std::string to_string(const ProtoBufReturnFlags::type& val);

struct AdplReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_VERSION = 16,
    BINARY_PAYLOAD = 128,
    MODEM_TIMESTAMP = 256,
    MODEM_TIMESTAMP_STRING = 512,
    DIAG_BINARY_PAYLOAD = 1024
  };
};

extern const std::map<int, const char*> _AdplReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const AdplReturnFlags::type& val);

std::string to_string(const AdplReturnFlags::type& val);

struct MbnNvItemDiffResult {
  enum type {
    NV_ITEM_PAYLOAD_MATCHED = 0,
    NV_ITEM_ONLY_IN_MBN = 1,
    NV_ITEM_PAYLOAD_MISMATCHED = 2
  };
};

extern const std::map<int, const char*> _MbnNvItemDiffResult_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const MbnNvItemDiffResult::type& val);

std::string to_string(const MbnNvItemDiffResult::type& val);

struct NmeaReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_ID = 32,
    BINARY_PAYLOAD = 128,
    PACKET_TEXT = 256
  };
};

extern const std::map<int, const char*> _NmeaReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const NmeaReturnFlags::type& val);

std::string to_string(const NmeaReturnFlags::type& val);

struct QdssReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    AT_ID = 32,
    BINARY_PAYLOAD = 128,
    HW_TIME_STAMP_DATA = 8192,
    HW_TIME_STAMP_STRING = 16384,
    CHANNEL_ID = 131072,
    MASTER_ID = 262144
  };
};

extern const std::map<int, const char*> _QdssReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const QdssReturnFlags::type& val);

std::string to_string(const QdssReturnFlags::type& val);

struct DunReturnFlags {
  enum type {
    SESSION_INDEX = 1,
    PROTOCOL_INDEX = 2,
    RECEIVE_TIME_DATA = 4,
    RECEIVE_TIME_STRING = 8,
    PACKET_ID = 32,
    PACKET_TEXT = 256
  };
};

extern const std::map<int, const char*> _DunReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const DunReturnFlags::type& val);

std::string to_string(const DunReturnFlags::type& val);

struct FunctionArea {
  enum type {
    FUNCTION_AREA_SAHARA_PORT_TRACE = 1,
    FUNCTION_AREA_FIREHOSE_PORT_TRACE = 2,
    FUNCTION_AREA_FIREHOSE_LOADER = 3,
    FUNCTION_AREA_QDSS_DIAG_RAW_TRACE = 4,
    FUNCTION_AREA_XQCN = 5
  };
};

extern const std::map<int, const char*> _FunctionArea_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const FunctionArea::type& val);

std::string to_string(const FunctionArea::type& val);

struct LogLevel {
  enum type {
    LOG_DEFAULT = 0,
    LOG_DATA = 1,
    LOG_DEBUG = 2,
    LOG_INFO = 4,
    LOG_WARNING = 8,
    LOG_ERROR = 16,
    LOG_EXCEPTION = 32,
    LOG_FATAL = 64,
    LOG_ALL = 2147483647
  };
};

extern const std::map<int, const char*> _LogLevel_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const LogLevel::type& val);

std::string to_string(const LogLevel::type& val);

struct LogFormat {
  enum type {
    LOG_CSV = 1,
    LOG_BINARY = 2
  };
};

extern const std::map<int, const char*> _LogFormat_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const LogFormat::type& val);

std::string to_string(const LogFormat::type& val);

struct LogLayout {
  enum type {
    LOG_DATE = 0,
    LOG_DATEUTC = 1,
    LOG_DATETIME = 2,
    LOG_DATETIMEUTC = 3,
    LOG_TIME = 4,
    LOG_TIMEUTC = 5,
    LOG_TIMEZONE = 6,
    LOG_EPOCH = 7,
    LOG_UPTIME = 8,
    LOG_RUNTIME = 9,
    LOG_SEQUENCE = 10,
    LOG_LOGSEQUENCE = 11,
    LOG_LEVEL = 12,
    LOG_MESSAGE = 13,
    LOG_COMBINED = 14,
    LOG_DATATYPE = 15,
    LOG_DATALEN = 16,
    LOG_DATA = 17,
    LOG_LOGGER = 18,
    LOG_CLASS = 19,
    LOG_NAMESPACE = 20,
    LOG_APPNAME = 21,
    LOG_APPVER = 22,
    LOG_PROCNAME = 23,
    LOG_PID = 24,
    LOG_PROCID = 25,
    LOG_TID = 26,
    LOG_THREADID = 27,
    LOG_THREADNAME = 28,
    LOG_HOSTNAME = 29,
    LOG_USERNAME = 30,
    LOG_CALLERFILE = 31,
    LOG_CALLERPATH = 32,
    LOG_CALLERLINE = 33,
    LOG_CALLERMETHOD = 34,
    LOG_TRACE = 35,
    LOG_EXCEPTION = 36,
    LOG_EXCEPTIONMESSAGE = 37,
    LOG_EXCEPTIONNAME = 38,
    LOG_EXCEPTIONSTACK = 39
  };
};

extern const std::map<int, const char*> _LogLayout_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const LogLayout::type& val);

std::string to_string(const LogLayout::type& val);

struct QcnItemDiffResult {
  enum type {
    QCN_ITEM_SAME = 0,
    QCN_ITEM_PLUS = 1,
    QCN_ITEM_MINUS = 2,
    QCN_ITEM_PAYLOAD_MISMATCH = 3
  };
};

extern const std::map<int, const char*> _QcnItemDiffResult_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const QcnItemDiffResult::type& val);

std::string to_string(const QcnItemDiffResult::type& val);

struct CdmaProtocolRevision {
  enum type {
    IS_95A = 0,
    IS_95B = 4,
    IS_2000_Rev_0 = 6,
    IS_2000_Rev_A = 7,
    IS_2000_Rev_B = 8,
    IS_2000_Rev_C = 9,
    IS_2000_Rev_C2 = 10,
    IS_2000_Rev_D = 11,
    IS_2000_Rev_E = 12
  };
};

extern const std::map<int, const char*> _CdmaProtocolRevision_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const CdmaProtocolRevision::type& val);

std::string to_string(const CdmaProtocolRevision::type& val);

struct WcdmaProtocolRevision {
  enum type {
    VB50 = 186651395,
    VA70 = 169873923,
    V9B0 = 153096711,
    VC80 = 203429377,
    VAB1 = 169874193,
    V930 = 153094418,
    V8A0 = 136318979,
    V860 = 136317187,
    V7G0 = 119541763,
    V790 = 119539717,
    V780 = 119539715,
    V770 = 119539474,
    V6F0 = 102762249,
    V6B0 = 102761993,
    V6A0 = 102761990,
    V690 = 102761987,
    V680 = 102761746,
    V590 = 85984262,
    V3I0 = 52429827,
    V3A0 = 52429315,
    V370 = 52429062,
    V350 = 52009216,
    VC81 = 203429378
  };
};

extern const std::map<int, const char*> _WcdmaProtocolRevision_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const WcdmaProtocolRevision::type& val);

std::string to_string(const WcdmaProtocolRevision::type& val);

struct BaudRate {
  enum type {
    BAUD_RATE_75 = 75,
    BAUD_RATE_110 = 110,
    BAUD_RATE_134 = 134,
    BAUD_RATE_150 = 150,
    BAUD_RATE_300 = 300,
    BAUD_RATE_600 = 600,
    BAUD_RATE_1200 = 1200,
    BAUD_RATE_1800 = 1800,
    BAUD_RATE_2400 = 2400,
    BAUD_RATE_4800 = 4800,
    BAUD_RATE_7200 = 7200,
    BAUD_RATE_9600 = 9600,
    BAUD_RATE_14400 = 14400,
    BAUD_RATE_19200 = 19200,
    BAUD_RATE_38400 = 38400,
    BAUD_RATE_57600 = 57600,
    BAUD_RATE_115200 = 115200,
    BAUD_RATE_128000 = 128000,
    BAUD_RATE_230400 = 230400,
    BAUD_RATE_460800 = 460800,
    BAUD_RATE_921600 = 921600,
    BAUD_RATE_1200000 = 1200000,
    BAUD_RATE_1843200 = 1843200,
    BAUD_RATE_3000000 = 3000000
  };
};

extern const std::map<int, const char*> _BaudRate_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const BaudRate::type& val);

std::string to_string(const BaudRate::type& val);

struct HdlcModeStatus {
  enum type {
    NOT_SET = 0,
    DISABLE = 1,
    ENABLE = 2
  };
};

extern const std::map<int, const char*> _HdlcModeStatus_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const HdlcModeStatus::type& val);

std::string to_string(const HdlcModeStatus::type& val);

struct HdlcMode {
  enum type {
    NON_HDLC_AUTO = 0,
    HDLC_ONLY = 1
  };
};

extern const std::map<int, const char*> _HdlcMode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const HdlcMode::type& val);

std::string to_string(const HdlcMode::type& val);

struct EudPeripheralType {
  enum type {
    PERIPHERALTYPE_EUD_NULL = 0,
    PERIPHERALTYPE_EUD_CTL = 1,
    PERIPHERALTYPE_EUD_JTG = 2,
    PERIPHERALTYPE_EUD_SWD = 3,
    PERIPHERALTYPE_EUD_TRC = 4,
    PERIPHERALTYPE_EUD_COM = 5
  };
};

extern const std::map<int, const char*> _EudPeripheralType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const EudPeripheralType::type& val);

std::string to_string(const EudPeripheralType::type& val);

struct XqcnOperationType {
  enum type {
    XQCN_BACKUP = 0,
    XQCN_RESTORE = 1
  };
};

extern const std::map<int, const char*> _XqcnOperationType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const XqcnOperationType::type& val);

std::string to_string(const XqcnOperationType::type& val);

struct QmStatusType {
  enum type {
    SUCCESS = 0,
    E_DEVICE_ERROR = 1,
    E_NOT_SUPPORTED = 2,
    E_INVALID = 3
  };
};

extern const std::map<int, const char*> _QmStatusType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const QmStatusType::type& val);

std::string to_string(const QmStatusType::type& val);

struct ResourcePersistenceType {
  enum type {
    STATIC_RESOURCE_PERSISTENCE = 0,
    DYNAMIC_RESOURCE_PERSISTENCE = 1
  };
};

extern const std::map<int, const char*> _ResourcePersistenceType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ResourcePersistenceType::type& val);

std::string to_string(const ResourcePersistenceType::type& val);

struct SamplingRatesEnum {
  enum type {
    FULL_RATE = 0,
    HALF_RATE = 1,
    QUARTER_RATE = 2,
    EIGHT_RATE = 3,
    SIXTEENTH_RATE = 4
  };
};

extern const std::map<int, const char*> _SamplingRatesEnum_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const SamplingRatesEnum::type& val);

std::string to_string(const SamplingRatesEnum::type& val);

class ClientInfo;

class ErrorType;

class AppException;

class ProtocolUsageIndicator;

class UsageIndicators;

class LockStatus;

class MbnDownloadStatus;

class ProtocolInfo;

class DeviceInfo;

class KeyInfo;

class InputLogMask;

class DiagPacketFilter;

class DiagSearchSettings;

class DiagIdFilterItem;

class DiagReturns;

class DiagReturnConfig;

class DiagPacket;

class AnnotationSearchSettings;

class AnnotationFilterItem;

class AnnotationPacketFilter;

class AnnotationPacket;

class QmiPacketFilter;

class QmiReturns;

class QmiReturnConfig;

class QmiPacket;

class AdbPacketFilter;

class AdbReturnConfig;

class AdbPacket;

class TelnetPacketFilter;

class TelnetReturnConfig;

class TelnetPacket;

class SaharaPacketFilter;

class SaharaReturnConfig;

class SaharaPacket;

class FastbootPacketFilter;

class FastbootReturnConfig;

class FastbootPacket;

class EudPacketFilter;

class EudReturnConfig;

class EudPacket;

class RpcToCapabilityNameMap;

class ProtoBufPacketFilter;

class ProtoBufReturns;

class ProtoBufReturnConfig;

class ProtoBufPacket;

class RxTxInfo;

class AdplReturnConfig;

class AdplPacket;

class BuildInfo;

class ImageInfo;

class GpsPacket;

class NvItem;

class MbnNvItemDiffDetails;

class MbnNvDiffDetailsPerSub;

class MbnDiffGroupHeader;

class MbnDiffResult;

class NmeaReturnConfig;

class NmeaPacket;

class NmeaPacketFilter;

class QmiUnpackReturn;

class QdssPacketFilter;

class QdssReturnConfig;

class QdssPacket;

class DunPacketFilter;

class DunReturnConfig;

class DunPacket;

class DiagPacketIdList;

class DiagPacketMap;

class QmiConnectionOptions;

class LogOptions;

class PhoneProperty;

class QcnHeader;

class QcnItemDiffDetails;

class QcnFeatureMaskDiffDetails;

class QcnPrlDiffDetails;

class QcnDiffResult;

class QcnPrl;

class QcnPrlList;

class QcnNumberedNv;

class QcnNumberedNvList;

class QcnEfsFile;

class QcnEfsItem;

class QcnEfsItemList;

class QcnContent;

class ProtocolConfiguration;

class DiagProtocolConnectionOptions;

class InternetConnectionOptions;

class ProtocolConnectionOptions;

class TcpOptions;

class TransferFileOptions;

class TransferFileResult;

class ClientCloseRequest;

class ClientCloseReason;

class ProtocolConfigurationResult;

class XqcnRestoreOptions;

class XqcnBackupOptions;

class DeviceConfigResp;

class QmBackendInfoType;

class QmBackendInfo;

class QmBackendInfoResponse;

class QmCapabilitiesInfo;

class QmCapabilitiesInfoResponse;

class StreamingCapabilityCustomization;

class StreamingCapabilityInfoType;

class QmLoopbackRequest;

class QmLoopback;

class QmLoopbackResponse;

class StreamingCapabilitySelect;

class StreamingCapabilitySelectList;

class ProfilingRawRequestParams;

class ProfilingRequestParams;

class ProfilingBackendParams;

class ProfilingLoopbackParams;

class ProfilingStartParams;

class ProfilingMetadataParams;

typedef struct _ClientInfo__isset {
  _ClientInfo__isset() : licenseKey(false), isAutomation(false), appName(false), username(false), qutsOperatingMode(false) {}
  bool licenseKey :1;
  bool isAutomation :1;
  bool appName :1;
  bool username :1;
  bool qutsOperatingMode :1;
} _ClientInfo__isset;

class ClientInfo : public virtual ::apache::thrift::TBase {
 public:

  ClientInfo(const ClientInfo&);
  ClientInfo& operator=(const ClientInfo&);
  ClientInfo() : clientName(), licenseKey(), isAutomation(0), appName(), username(), qutsOperatingMode((QutsOperatingMode::type)0) {
  }

  virtual ~ClientInfo() noexcept;
  std::string clientName;
  std::string licenseKey;
  bool isAutomation;
  std::string appName;
  std::string username;
  QutsOperatingMode::type qutsOperatingMode;

  _ClientInfo__isset __isset;

  void __set_clientName(const std::string& val);

  void __set_licenseKey(const std::string& val);

  void __set_isAutomation(const bool val);

  void __set_appName(const std::string& val);

  void __set_username(const std::string& val);

  void __set_qutsOperatingMode(const QutsOperatingMode::type val);

  bool operator == (const ClientInfo & rhs) const
  {
    if (!(clientName == rhs.clientName))
      return false;
    if (!(licenseKey == rhs.licenseKey))
      return false;
    if (__isset.isAutomation != rhs.__isset.isAutomation)
      return false;
    else if (__isset.isAutomation && !(isAutomation == rhs.isAutomation))
      return false;
    if (__isset.appName != rhs.__isset.appName)
      return false;
    else if (__isset.appName && !(appName == rhs.appName))
      return false;
    if (__isset.username != rhs.__isset.username)
      return false;
    else if (__isset.username && !(username == rhs.username))
      return false;
    if (__isset.qutsOperatingMode != rhs.__isset.qutsOperatingMode)
      return false;
    else if (__isset.qutsOperatingMode && !(qutsOperatingMode == rhs.qutsOperatingMode))
      return false;
    return true;
  }
  bool operator != (const ClientInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ClientInfo &a, ClientInfo &b);

std::ostream& operator<<(std::ostream& out, const ClientInfo& obj);


class ErrorType : public virtual ::apache::thrift::TBase {
 public:

  ErrorType(const ErrorType&);
  ErrorType& operator=(const ErrorType&);
  ErrorType() : errorCode((ErrorCode::type)0), errorString() {
  }

  virtual ~ErrorType() noexcept;
  ErrorCode::type errorCode;
  std::string errorString;

  void __set_errorCode(const ErrorCode::type val);

  void __set_errorString(const std::string& val);

  bool operator == (const ErrorType & rhs) const
  {
    if (!(errorCode == rhs.errorCode))
      return false;
    if (!(errorString == rhs.errorString))
      return false;
    return true;
  }
  bool operator != (const ErrorType &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ErrorType & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ErrorType &a, ErrorType &b);

std::ostream& operator<<(std::ostream& out, const ErrorType& obj);


class AppException : public ::apache::thrift::TException {
 public:

  AppException(const AppException&);
  AppException& operator=(const AppException&);
  AppException() : errorCode((ErrorCode::type)0), errorString() {
  }

  virtual ~AppException() noexcept;
  ErrorCode::type errorCode;
  std::string errorString;

  void __set_errorCode(const ErrorCode::type val);

  void __set_errorString(const std::string& val);

  bool operator == (const AppException & rhs) const
  {
    if (!(errorCode == rhs.errorCode))
      return false;
    if (!(errorString == rhs.errorString))
      return false;
    return true;
  }
  bool operator != (const AppException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AppException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
  mutable std::string thriftTExceptionMessageHolder_;
  const char* what() const noexcept;
};

void swap(AppException &a, AppException &b);

std::ostream& operator<<(std::ostream& out, const AppException& obj);

typedef struct _ProtocolUsageIndicator__isset {
  _ProtocolUsageIndicator__isset() : flowControlStatus(false), flowControlLevel(false), ioWatermark(false), functionWatermark(false) {}
  bool flowControlStatus :1;
  bool flowControlLevel :1;
  bool ioWatermark :1;
  bool functionWatermark :1;
} _ProtocolUsageIndicator__isset;

class ProtocolUsageIndicator : public virtual ::apache::thrift::TBase {
 public:

  ProtocolUsageIndicator(const ProtocolUsageIndicator&);
  ProtocolUsageIndicator& operator=(const ProtocolUsageIndicator&);
  ProtocolUsageIndicator() : flowControlStatus((FlowControlStatus::type)0), flowControlLevel((FlowControlLevel::type)0), ioWatermark(0), functionWatermark(0) {
  }

  virtual ~ProtocolUsageIndicator() noexcept;
  FlowControlStatus::type flowControlStatus;
  FlowControlLevel::type flowControlLevel;
  int32_t ioWatermark;
  int32_t functionWatermark;

  _ProtocolUsageIndicator__isset __isset;

  void __set_flowControlStatus(const FlowControlStatus::type val);

  void __set_flowControlLevel(const FlowControlLevel::type val);

  void __set_ioWatermark(const int32_t val);

  void __set_functionWatermark(const int32_t val);

  bool operator == (const ProtocolUsageIndicator & rhs) const
  {
    if (!(flowControlStatus == rhs.flowControlStatus))
      return false;
    if (!(flowControlLevel == rhs.flowControlLevel))
      return false;
    if (!(ioWatermark == rhs.ioWatermark))
      return false;
    if (!(functionWatermark == rhs.functionWatermark))
      return false;
    return true;
  }
  bool operator != (const ProtocolUsageIndicator &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProtocolUsageIndicator & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProtocolUsageIndicator &a, ProtocolUsageIndicator &b);

std::ostream& operator<<(std::ostream& out, const ProtocolUsageIndicator& obj);

typedef struct _UsageIndicators__isset {
  _UsageIndicators__isset() : isOptimal(false), indicators(false) {}
  bool isOptimal :1;
  bool indicators :1;
} _UsageIndicators__isset;

class UsageIndicators : public virtual ::apache::thrift::TBase {
 public:

  UsageIndicators(const UsageIndicators&);
  UsageIndicators& operator=(const UsageIndicators&);
  UsageIndicators() : isOptimal(0) {
  }

  virtual ~UsageIndicators() noexcept;
  bool isOptimal;
  std::map<int64_t, ProtocolUsageIndicator>  indicators;

  _UsageIndicators__isset __isset;

  void __set_isOptimal(const bool val);

  void __set_indicators(const std::map<int64_t, ProtocolUsageIndicator> & val);

  bool operator == (const UsageIndicators & rhs) const
  {
    if (!(isOptimal == rhs.isOptimal))
      return false;
    if (!(indicators == rhs.indicators))
      return false;
    return true;
  }
  bool operator != (const UsageIndicators &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UsageIndicators & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(UsageIndicators &a, UsageIndicators &b);

std::ostream& operator<<(std::ostream& out, const UsageIndicators& obj);

typedef struct _LockStatus__isset {
  _LockStatus__isset() : lockState(false), clientId(false), reason(false) {}
  bool lockState :1;
  bool clientId :1;
  bool reason :1;
} _LockStatus__isset;

class LockStatus : public virtual ::apache::thrift::TBase {
 public:

  LockStatus(const LockStatus&);
  LockStatus& operator=(const LockStatus&);
  LockStatus() : lockState((LockState::type)0), clientId(0), reason() {
  }

  virtual ~LockStatus() noexcept;
  LockState::type lockState;
  int64_t clientId;
  std::string reason;

  _LockStatus__isset __isset;

  void __set_lockState(const LockState::type val);

  void __set_clientId(const int64_t val);

  void __set_reason(const std::string& val);

  bool operator == (const LockStatus & rhs) const
  {
    if (!(lockState == rhs.lockState))
      return false;
    if (__isset.clientId != rhs.__isset.clientId)
      return false;
    else if (__isset.clientId && !(clientId == rhs.clientId))
      return false;
    if (__isset.reason != rhs.__isset.reason)
      return false;
    else if (__isset.reason && !(reason == rhs.reason))
      return false;
    return true;
  }
  bool operator != (const LockStatus &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LockStatus & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(LockStatus &a, LockStatus &b);

std::ostream& operator<<(std::ostream& out, const LockStatus& obj);

typedef struct _MbnDownloadStatus__isset {
  _MbnDownloadStatus__isset() : downloadState(false), indicationToken(false), configType(false), subscriptionId(false), activeConfigId(false), pendingConfigId(false) {}
  bool downloadState :1;
  bool indicationToken :1;
  bool configType :1;
  bool subscriptionId :1;
  bool activeConfigId :1;
  bool pendingConfigId :1;
} _MbnDownloadStatus__isset;

class MbnDownloadStatus : public virtual ::apache::thrift::TBase {
 public:

  MbnDownloadStatus(const MbnDownloadStatus&);
  MbnDownloadStatus& operator=(const MbnDownloadStatus&);
  MbnDownloadStatus() : downloadState((MbnDownloadState::type)0), indicationToken(0), configType(0), subscriptionId(0), activeConfigId(), pendingConfigId() {
  }

  virtual ~MbnDownloadStatus() noexcept;
  MbnDownloadState::type downloadState;
  int32_t indicationToken;
  int32_t configType;
  int32_t subscriptionId;
  std::string activeConfigId;
  std::string pendingConfigId;

  _MbnDownloadStatus__isset __isset;

  void __set_downloadState(const MbnDownloadState::type val);

  void __set_indicationToken(const int32_t val);

  void __set_configType(const int32_t val);

  void __set_subscriptionId(const int32_t val);

  void __set_activeConfigId(const std::string& val);

  void __set_pendingConfigId(const std::string& val);

  bool operator == (const MbnDownloadStatus & rhs) const
  {
    if (!(downloadState == rhs.downloadState))
      return false;
    if (__isset.indicationToken != rhs.__isset.indicationToken)
      return false;
    else if (__isset.indicationToken && !(indicationToken == rhs.indicationToken))
      return false;
    if (__isset.configType != rhs.__isset.configType)
      return false;
    else if (__isset.configType && !(configType == rhs.configType))
      return false;
    if (__isset.subscriptionId != rhs.__isset.subscriptionId)
      return false;
    else if (__isset.subscriptionId && !(subscriptionId == rhs.subscriptionId))
      return false;
    if (__isset.activeConfigId != rhs.__isset.activeConfigId)
      return false;
    else if (__isset.activeConfigId && !(activeConfigId == rhs.activeConfigId))
      return false;
    if (__isset.pendingConfigId != rhs.__isset.pendingConfigId)
      return false;
    else if (__isset.pendingConfigId && !(pendingConfigId == rhs.pendingConfigId))
      return false;
    return true;
  }
  bool operator != (const MbnDownloadStatus &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MbnDownloadStatus & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(MbnDownloadStatus &a, MbnDownloadStatus &b);

std::ostream& operator<<(std::ostream& out, const MbnDownloadStatus& obj);

typedef struct _ProtocolInfo__isset {
  _ProtocolInfo__isset() : protocolHandle(false), deviceHandle(false), description(false), protocolType(false), connectionType(false), connectionStatus(false), shareStatus(false), protocolState(false) {}
  bool protocolHandle :1;
  bool deviceHandle :1;
  bool description :1;
  bool protocolType :1;
  bool connectionType :1;
  bool connectionStatus :1;
  bool shareStatus :1;
  bool protocolState :1;
} _ProtocolInfo__isset;

class ProtocolInfo : public virtual ::apache::thrift::TBase {
 public:

  ProtocolInfo(const ProtocolInfo&);
  ProtocolInfo& operator=(const ProtocolInfo&);
  ProtocolInfo() : protocolHandle(0), deviceHandle(0), description(), protocolType((ProtocolType::type)0), connectionType((ConnectionType::type)0), connectionStatus((OpenProp::type)0), shareStatus((OpenProp::type)0), protocolState((ProtocolState::type)0) {
  }

  virtual ~ProtocolInfo() noexcept;
  int64_t protocolHandle;
  int64_t deviceHandle;
  std::string description;
  ProtocolType::type protocolType;
  ConnectionType::type connectionType;
  OpenProp::type connectionStatus;
  OpenProp::type shareStatus;
  ProtocolState::type protocolState;

  _ProtocolInfo__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_deviceHandle(const int64_t val);

  void __set_description(const std::string& val);

  void __set_protocolType(const ProtocolType::type val);

  void __set_connectionType(const ConnectionType::type val);

  void __set_connectionStatus(const OpenProp::type val);

  void __set_shareStatus(const OpenProp::type val);

  void __set_protocolState(const ProtocolState::type val);

  bool operator == (const ProtocolInfo & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(description == rhs.description))
      return false;
    if (!(protocolType == rhs.protocolType))
      return false;
    if (!(connectionType == rhs.connectionType))
      return false;
    if (!(connectionStatus == rhs.connectionStatus))
      return false;
    if (!(shareStatus == rhs.shareStatus))
      return false;
    if (!(protocolState == rhs.protocolState))
      return false;
    return true;
  }
  bool operator != (const ProtocolInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProtocolInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProtocolInfo &a, ProtocolInfo &b);

std::ostream& operator<<(std::ostream& out, const ProtocolInfo& obj);

typedef struct _DeviceInfo__isset {
  _DeviceInfo__isset() : deviceHandle(false), description(false), protocols(false), services(false), serialNumber(false), adbSerialNumber(false), location(false), vid(false), pid(false), edlChipId(false) {}
  bool deviceHandle :1;
  bool description :1;
  bool protocols :1;
  bool services :1;
  bool serialNumber :1;
  bool adbSerialNumber :1;
  bool location :1;
  bool vid :1;
  bool pid :1;
  bool edlChipId :1;
} _DeviceInfo__isset;

class DeviceInfo : public virtual ::apache::thrift::TBase {
 public:

  DeviceInfo(const DeviceInfo&);
  DeviceInfo& operator=(const DeviceInfo&);
  DeviceInfo() : deviceHandle(0), description(), serialNumber(), adbSerialNumber(), location(), vid(), pid(), edlChipId() {
  }

  virtual ~DeviceInfo() noexcept;
  int64_t deviceHandle;
  std::string description;
  std::vector<ProtocolInfo>  protocols;
  std::vector<std::string>  services;
  std::string serialNumber;
  std::string adbSerialNumber;
  std::string location;
  std::string vid;
  std::string pid;
  std::string edlChipId;

  _DeviceInfo__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_description(const std::string& val);

  void __set_protocols(const std::vector<ProtocolInfo> & val);

  void __set_services(const std::vector<std::string> & val);

  void __set_serialNumber(const std::string& val);

  void __set_adbSerialNumber(const std::string& val);

  void __set_location(const std::string& val);

  void __set_vid(const std::string& val);

  void __set_pid(const std::string& val);

  void __set_edlChipId(const std::string& val);

  bool operator == (const DeviceInfo & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(description == rhs.description))
      return false;
    if (!(protocols == rhs.protocols))
      return false;
    if (!(services == rhs.services))
      return false;
    if (!(serialNumber == rhs.serialNumber))
      return false;
    if (!(adbSerialNumber == rhs.adbSerialNumber))
      return false;
    if (!(location == rhs.location))
      return false;
    if (!(vid == rhs.vid))
      return false;
    if (!(pid == rhs.pid))
      return false;
    if (!(edlChipId == rhs.edlChipId))
      return false;
    return true;
  }
  bool operator != (const DeviceInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DeviceInfo &a, DeviceInfo &b);

std::ostream& operator<<(std::ostream& out, const DeviceInfo& obj);

typedef struct _KeyInfo__isset {
  _KeyInfo__isset() : keyClassification(false), status(false) {}
  bool keyClassification :1;
  bool status :1;
} _KeyInfo__isset;

class KeyInfo : public virtual ::apache::thrift::TBase {
 public:

  KeyInfo(const KeyInfo&);
  KeyInfo& operator=(const KeyInfo&);
  KeyInfo() : keyClassification((KeyClass::type)0), status((KeyLoadStatus::type)0) {
  }

  virtual ~KeyInfo() noexcept;
  KeyClass::type keyClassification;
  KeyLoadStatus::type status;

  _KeyInfo__isset __isset;

  void __set_keyClassification(const KeyClass::type val);

  void __set_status(const KeyLoadStatus::type val);

  bool operator == (const KeyInfo & rhs) const
  {
    if (__isset.keyClassification != rhs.__isset.keyClassification)
      return false;
    else if (__isset.keyClassification && !(keyClassification == rhs.keyClassification))
      return false;
    if (__isset.status != rhs.__isset.status)
      return false;
    else if (__isset.status && !(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const KeyInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const KeyInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(KeyInfo &a, KeyInfo &b);

std::ostream& operator<<(std::ostream& out, const KeyInfo& obj);

typedef struct _InputLogMask__isset {
  _InputLogMask__isset() : dataSourceType(false), filename(false), maskFileContent(false), format(false) {}
  bool dataSourceType :1;
  bool filename :1;
  bool maskFileContent :1;
  bool format :1;
} _InputLogMask__isset;

class InputLogMask : public virtual ::apache::thrift::TBase {
 public:

  InputLogMask(const InputLogMask&);
  InputLogMask& operator=(const InputLogMask&);
  InputLogMask() : dataSourceType((DataSourceType::type)0), filename(), maskFileContent(), format((LogMaskFormat::type)0) {
  }

  virtual ~InputLogMask() noexcept;
  DataSourceType::type dataSourceType;
  std::string filename;
  std::string maskFileContent;
  LogMaskFormat::type format;

  _InputLogMask__isset __isset;

  void __set_dataSourceType(const DataSourceType::type val);

  void __set_filename(const std::string& val);

  void __set_maskFileContent(const std::string& val);

  void __set_format(const LogMaskFormat::type val);

  bool operator == (const InputLogMask & rhs) const
  {
    if (__isset.dataSourceType != rhs.__isset.dataSourceType)
      return false;
    else if (__isset.dataSourceType && !(dataSourceType == rhs.dataSourceType))
      return false;
    if (__isset.filename != rhs.__isset.filename)
      return false;
    else if (__isset.filename && !(filename == rhs.filename))
      return false;
    if (__isset.maskFileContent != rhs.__isset.maskFileContent)
      return false;
    else if (__isset.maskFileContent && !(maskFileContent == rhs.maskFileContent))
      return false;
    if (!(format == rhs.format))
      return false;
    return true;
  }
  bool operator != (const InputLogMask &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const InputLogMask & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(InputLogMask &a, InputLogMask &b);

std::ostream& operator<<(std::ostream& out, const InputLogMask& obj);

typedef struct _DiagPacketFilter__isset {
  _DiagPacketFilter__isset() : idOrNameMask(false), subscriptionId(false), logMask(false), formatStringFilter(false), enableMultiSim(false), miscellaneousId(false), internalPacketEnum(false), includeAllOtaLogPackets(false), f3FormatStringFilter(false), qtraceFormatStringFilter(false), prefixFormatStringFilter(false), excludeQEventsFromQTraceTypeFilter(false) {}
  bool idOrNameMask :1;
  bool subscriptionId :1;
  bool logMask :1;
  bool formatStringFilter :1;
  bool enableMultiSim :1;
  bool miscellaneousId :1;
  bool internalPacketEnum :1;
  bool includeAllOtaLogPackets :1;
  bool f3FormatStringFilter :1;
  bool qtraceFormatStringFilter :1;
  bool prefixFormatStringFilter :1;
  bool excludeQEventsFromQTraceTypeFilter :1;
} _DiagPacketFilter__isset;

class DiagPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  DiagPacketFilter(const DiagPacketFilter&);
  DiagPacketFilter& operator=(const DiagPacketFilter&);
  DiagPacketFilter() : enableMultiSim(0), internalPacketEnum((InternalPacketFlag::type)0), includeAllOtaLogPackets(0), excludeQEventsFromQTraceTypeFilter(0) {
  }

  virtual ~DiagPacketFilter() noexcept;
  std::map<DiagPacketType::type, std::vector<DiagIdFilterItem> >  idOrNameMask;
  std::vector<int32_t>  subscriptionId;
  InputLogMask logMask;
  std::vector<std::string>  formatStringFilter;
  bool enableMultiSim;
  std::vector<int32_t>  miscellaneousId;
  InternalPacketFlag::type internalPacketEnum;
  bool includeAllOtaLogPackets;
  std::map<int32_t, std::vector<std::string> >  f3FormatStringFilter;
  std::map<int32_t, std::vector<std::string> >  qtraceFormatStringFilter;
  std::vector<std::string>  prefixFormatStringFilter;
  bool excludeQEventsFromQTraceTypeFilter;

  _DiagPacketFilter__isset __isset;

  void __set_idOrNameMask(const std::map<DiagPacketType::type, std::vector<DiagIdFilterItem> > & val);

  void __set_subscriptionId(const std::vector<int32_t> & val);

  void __set_logMask(const InputLogMask& val);

  void __set_formatStringFilter(const std::vector<std::string> & val);

  void __set_enableMultiSim(const bool val);

  void __set_miscellaneousId(const std::vector<int32_t> & val);

  void __set_internalPacketEnum(const InternalPacketFlag::type val);

  void __set_includeAllOtaLogPackets(const bool val);

  void __set_f3FormatStringFilter(const std::map<int32_t, std::vector<std::string> > & val);

  void __set_qtraceFormatStringFilter(const std::map<int32_t, std::vector<std::string> > & val);

  void __set_prefixFormatStringFilter(const std::vector<std::string> & val);

  void __set_excludeQEventsFromQTraceTypeFilter(const bool val);

  bool operator == (const DiagPacketFilter & rhs) const
  {
    if (__isset.idOrNameMask != rhs.__isset.idOrNameMask)
      return false;
    else if (__isset.idOrNameMask && !(idOrNameMask == rhs.idOrNameMask))
      return false;
    if (__isset.subscriptionId != rhs.__isset.subscriptionId)
      return false;
    else if (__isset.subscriptionId && !(subscriptionId == rhs.subscriptionId))
      return false;
    if (__isset.logMask != rhs.__isset.logMask)
      return false;
    else if (__isset.logMask && !(logMask == rhs.logMask))
      return false;
    if (__isset.formatStringFilter != rhs.__isset.formatStringFilter)
      return false;
    else if (__isset.formatStringFilter && !(formatStringFilter == rhs.formatStringFilter))
      return false;
    if (__isset.enableMultiSim != rhs.__isset.enableMultiSim)
      return false;
    else if (__isset.enableMultiSim && !(enableMultiSim == rhs.enableMultiSim))
      return false;
    if (__isset.miscellaneousId != rhs.__isset.miscellaneousId)
      return false;
    else if (__isset.miscellaneousId && !(miscellaneousId == rhs.miscellaneousId))
      return false;
    if (__isset.internalPacketEnum != rhs.__isset.internalPacketEnum)
      return false;
    else if (__isset.internalPacketEnum && !(internalPacketEnum == rhs.internalPacketEnum))
      return false;
    if (__isset.includeAllOtaLogPackets != rhs.__isset.includeAllOtaLogPackets)
      return false;
    else if (__isset.includeAllOtaLogPackets && !(includeAllOtaLogPackets == rhs.includeAllOtaLogPackets))
      return false;
    if (__isset.f3FormatStringFilter != rhs.__isset.f3FormatStringFilter)
      return false;
    else if (__isset.f3FormatStringFilter && !(f3FormatStringFilter == rhs.f3FormatStringFilter))
      return false;
    if (__isset.qtraceFormatStringFilter != rhs.__isset.qtraceFormatStringFilter)
      return false;
    else if (__isset.qtraceFormatStringFilter && !(qtraceFormatStringFilter == rhs.qtraceFormatStringFilter))
      return false;
    if (__isset.prefixFormatStringFilter != rhs.__isset.prefixFormatStringFilter)
      return false;
    else if (__isset.prefixFormatStringFilter && !(prefixFormatStringFilter == rhs.prefixFormatStringFilter))
      return false;
    if (__isset.excludeQEventsFromQTraceTypeFilter != rhs.__isset.excludeQEventsFromQTraceTypeFilter)
      return false;
    else if (__isset.excludeQEventsFromQTraceTypeFilter && !(excludeQEventsFromQTraceTypeFilter == rhs.excludeQEventsFromQTraceTypeFilter))
      return false;
    return true;
  }
  bool operator != (const DiagPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagPacketFilter &a, DiagPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const DiagPacketFilter& obj);

typedef struct _DiagSearchSettings__isset {
  _DiagSearchSettings__isset() : searchString(false), options(false), fields(false), extfields(false) {}
  bool searchString :1;
  bool options :1;
  bool fields :1;
  bool extfields :1;
} _DiagSearchSettings__isset;

class DiagSearchSettings : public virtual ::apache::thrift::TBase {
 public:

  DiagSearchSettings(const DiagSearchSettings&);
  DiagSearchSettings& operator=(const DiagSearchSettings&);
  DiagSearchSettings() : searchString(), options((SearchOptions::type)0), fields((DiagReturnFlags::type)0), extfields((DiagReturnFlagsExt::type)0) {
  }

  virtual ~DiagSearchSettings() noexcept;
  std::string searchString;
  SearchOptions::type options;
  DiagReturnFlags::type fields;
  DiagReturnFlagsExt::type extfields;

  _DiagSearchSettings__isset __isset;

  void __set_searchString(const std::string& val);

  void __set_options(const SearchOptions::type val);

  void __set_fields(const DiagReturnFlags::type val);

  void __set_extfields(const DiagReturnFlagsExt::type val);

  bool operator == (const DiagSearchSettings & rhs) const
  {
    if (__isset.searchString != rhs.__isset.searchString)
      return false;
    else if (__isset.searchString && !(searchString == rhs.searchString))
      return false;
    if (__isset.options != rhs.__isset.options)
      return false;
    else if (__isset.options && !(options == rhs.options))
      return false;
    if (__isset.fields != rhs.__isset.fields)
      return false;
    else if (__isset.fields && !(fields == rhs.fields))
      return false;
    if (__isset.extfields != rhs.__isset.extfields)
      return false;
    else if (__isset.extfields && !(extfields == rhs.extfields))
      return false;
    return true;
  }
  bool operator != (const DiagSearchSettings &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagSearchSettings & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagSearchSettings &a, DiagSearchSettings &b);

std::ostream& operator<<(std::ostream& out, const DiagSearchSettings& obj);

typedef struct _DiagIdFilterItem__isset {
  _DiagIdFilterItem__isset() : idOrName(false), regexFilter(false), summaryRegexFilter(false), caseInsensitive(false), searchSettings(false) {}
  bool idOrName :1;
  bool regexFilter :1;
  bool summaryRegexFilter :1;
  bool caseInsensitive :1;
  bool searchSettings :1;
} _DiagIdFilterItem__isset;

class DiagIdFilterItem : public virtual ::apache::thrift::TBase {
 public:

  DiagIdFilterItem(const DiagIdFilterItem&);
  DiagIdFilterItem& operator=(const DiagIdFilterItem&);
  DiagIdFilterItem() : idOrName(), regexFilter(), summaryRegexFilter(), caseInsensitive(0) {
  }

  virtual ~DiagIdFilterItem() noexcept;
  std::string idOrName;
  std::string regexFilter;
  std::string summaryRegexFilter;
  bool caseInsensitive;
  DiagSearchSettings searchSettings;

  _DiagIdFilterItem__isset __isset;

  void __set_idOrName(const std::string& val);

  void __set_regexFilter(const std::string& val);

  void __set_summaryRegexFilter(const std::string& val);

  void __set_caseInsensitive(const bool val);

  void __set_searchSettings(const DiagSearchSettings& val);

  bool operator == (const DiagIdFilterItem & rhs) const
  {
    if (__isset.idOrName != rhs.__isset.idOrName)
      return false;
    else if (__isset.idOrName && !(idOrName == rhs.idOrName))
      return false;
    if (__isset.regexFilter != rhs.__isset.regexFilter)
      return false;
    else if (__isset.regexFilter && !(regexFilter == rhs.regexFilter))
      return false;
    if (__isset.summaryRegexFilter != rhs.__isset.summaryRegexFilter)
      return false;
    else if (__isset.summaryRegexFilter && !(summaryRegexFilter == rhs.summaryRegexFilter))
      return false;
    if (__isset.caseInsensitive != rhs.__isset.caseInsensitive)
      return false;
    else if (__isset.caseInsensitive && !(caseInsensitive == rhs.caseInsensitive))
      return false;
    if (__isset.searchSettings != rhs.__isset.searchSettings)
      return false;
    else if (__isset.searchSettings && !(searchSettings == rhs.searchSettings))
      return false;
    return true;
  }
  bool operator != (const DiagIdFilterItem &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagIdFilterItem & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagIdFilterItem &a, DiagIdFilterItem &b);

std::ostream& operator<<(std::ostream& out, const DiagIdFilterItem& obj);

typedef struct _DiagReturns__isset {
  _DiagReturns__isset() : flags(false), queries(false), extFlags(false) {}
  bool flags :1;
  bool queries :1;
  bool extFlags :1;
} _DiagReturns__isset;

class DiagReturns : public virtual ::apache::thrift::TBase {
 public:

  DiagReturns(const DiagReturns&);
  DiagReturns& operator=(const DiagReturns&);
  DiagReturns() : flags((DiagReturnFlags::type)0), extFlags((DiagReturnFlagsExt::type)0) {
  }

  virtual ~DiagReturns() noexcept;
  DiagReturnFlags::type flags;
  std::vector<std::string>  queries;
  DiagReturnFlagsExt::type extFlags;

  _DiagReturns__isset __isset;

  void __set_flags(const DiagReturnFlags::type val);

  void __set_queries(const std::vector<std::string> & val);

  void __set_extFlags(const DiagReturnFlagsExt::type val);

  bool operator == (const DiagReturns & rhs) const
  {
    if (__isset.flags != rhs.__isset.flags)
      return false;
    else if (__isset.flags && !(flags == rhs.flags))
      return false;
    if (__isset.queries != rhs.__isset.queries)
      return false;
    else if (__isset.queries && !(queries == rhs.queries))
      return false;
    if (__isset.extFlags != rhs.__isset.extFlags)
      return false;
    else if (__isset.extFlags && !(extFlags == rhs.extFlags))
      return false;
    return true;
  }
  bool operator != (const DiagReturns &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagReturns & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagReturns &a, DiagReturns &b);

std::ostream& operator<<(std::ostream& out, const DiagReturns& obj);

typedef struct _DiagReturnConfig__isset {
  _DiagReturnConfig__isset() : flags(false), fieldQueries(false), diagTimeSorted(false), formatStringArguments(false), extFlags(false), enumReturnRawValue(false), useFormatForFieldQuery(false) {}
  bool flags :1;
  bool fieldQueries :1;
  bool diagTimeSorted :1;
  bool formatStringArguments :1;
  bool extFlags :1;
  bool enumReturnRawValue :1;
  bool useFormatForFieldQuery :1;
} _DiagReturnConfig__isset;

class DiagReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  DiagReturnConfig(const DiagReturnConfig&);
  DiagReturnConfig& operator=(const DiagReturnConfig&);
  DiagReturnConfig() : flags((DiagReturnFlags::type)0), diagTimeSorted(0), extFlags((DiagReturnFlagsExt::type)0), enumReturnRawValue(0), useFormatForFieldQuery(0) {
  }

  virtual ~DiagReturnConfig() noexcept;
  DiagReturnFlags::type flags;
  std::map<DiagPacketType::type, std::map<std::string, DiagReturns> >  fieldQueries;
  bool diagTimeSorted;
  std::map<std::string, std::set<int32_t> >  formatStringArguments;
  DiagReturnFlagsExt::type extFlags;
  bool enumReturnRawValue;
  bool useFormatForFieldQuery;

  _DiagReturnConfig__isset __isset;

  void __set_flags(const DiagReturnFlags::type val);

  void __set_fieldQueries(const std::map<DiagPacketType::type, std::map<std::string, DiagReturns> > & val);

  void __set_diagTimeSorted(const bool val);

  void __set_formatStringArguments(const std::map<std::string, std::set<int32_t> > & val);

  void __set_extFlags(const DiagReturnFlagsExt::type val);

  void __set_enumReturnRawValue(const bool val);

  void __set_useFormatForFieldQuery(const bool val);

  bool operator == (const DiagReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    if (__isset.fieldQueries != rhs.__isset.fieldQueries)
      return false;
    else if (__isset.fieldQueries && !(fieldQueries == rhs.fieldQueries))
      return false;
    if (__isset.diagTimeSorted != rhs.__isset.diagTimeSorted)
      return false;
    else if (__isset.diagTimeSorted && !(diagTimeSorted == rhs.diagTimeSorted))
      return false;
    if (__isset.formatStringArguments != rhs.__isset.formatStringArguments)
      return false;
    else if (__isset.formatStringArguments && !(formatStringArguments == rhs.formatStringArguments))
      return false;
    if (__isset.extFlags != rhs.__isset.extFlags)
      return false;
    else if (__isset.extFlags && !(extFlags == rhs.extFlags))
      return false;
    if (__isset.enumReturnRawValue != rhs.__isset.enumReturnRawValue)
      return false;
    else if (__isset.enumReturnRawValue && !(enumReturnRawValue == rhs.enumReturnRawValue))
      return false;
    if (__isset.useFormatForFieldQuery != rhs.__isset.useFormatForFieldQuery)
      return false;
    else if (__isset.useFormatForFieldQuery && !(useFormatForFieldQuery == rhs.useFormatForFieldQuery))
      return false;
    return true;
  }
  bool operator != (const DiagReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagReturnConfig &a, DiagReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const DiagReturnConfig& obj);

typedef struct _DiagPacket__isset {
  _DiagPacket__isset() : errorCode(false), packetType(false), packetId(false), moreResponsesFlag(false), sessionIndex(false), protocolIndex(false), packetName(false), timeStampData(false), timeStampString(false), binaryPayload(false), parsedText(false), subscriptionId(false), processorId(false), hwTimeStampData(false), hwTimeStampString(false), ulogSource(false), receiveTimeData(false), receiveTimeString(false), queryResultJson(false), summaryText(false), transactionId(false), qdssChannelId(false), qdssMasterId(false), qdssAtid(false), defaultFormatText(false), callFrameNumber(false), timeStampTodAdjustedData(false), timeStampTodAdjustedString(false), formatStringArguments(false), packetSize(false), qtraceTags(false), miscellaneousId(false), queryResultPickled(false), formatStringHash(false), encryptionKeyInfo(false), exceptionMessageType(false) {}
  bool errorCode :1;
  bool packetType :1;
  bool packetId :1;
  bool moreResponsesFlag :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool packetName :1;
  bool timeStampData :1;
  bool timeStampString :1;
  bool binaryPayload :1;
  bool parsedText :1;
  bool subscriptionId :1;
  bool processorId :1;
  bool hwTimeStampData :1;
  bool hwTimeStampString :1;
  bool ulogSource :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
  bool queryResultJson :1;
  bool summaryText :1;
  bool transactionId :1;
  bool qdssChannelId :1;
  bool qdssMasterId :1;
  bool qdssAtid :1;
  bool defaultFormatText :1;
  bool callFrameNumber :1;
  bool timeStampTodAdjustedData :1;
  bool timeStampTodAdjustedString :1;
  bool formatStringArguments :1;
  bool packetSize :1;
  bool qtraceTags :1;
  bool miscellaneousId :1;
  bool queryResultPickled :1;
  bool formatStringHash :1;
  bool encryptionKeyInfo :1;
  bool exceptionMessageType :1;
} _DiagPacket__isset;

class DiagPacket : public virtual ::apache::thrift::TBase {
 public:

  DiagPacket(const DiagPacket&);
  DiagPacket& operator=(const DiagPacket&);
  DiagPacket() : errorCode((ErrorCode::type)0), packetType((DiagPacketType::type)0), packetId(), moreResponsesFlag(0), sessionIndex(0), protocolIndex(0), packetName(), timeStampData(0), timeStampString(), binaryPayload(), parsedText(), subscriptionId(0), processorId(0), hwTimeStampData(0), hwTimeStampString(), ulogSource(), receiveTimeData(0), receiveTimeString(), queryResultJson(), summaryText(), transactionId(0), qdssChannelId(0), qdssMasterId(0), qdssAtid(0), defaultFormatText(), callFrameNumber(0), timeStampTodAdjustedData(0), timeStampTodAdjustedString(), packetSize(0), miscellaneousId(0), queryResultPickled(), formatStringHash(0), exceptionMessageType((ExceptionMessageType::type)0) {
  }

  virtual ~DiagPacket() noexcept;
  ErrorCode::type errorCode;
  DiagPacketType::type packetType;
  std::string packetId;
  bool moreResponsesFlag;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string packetName;
  int64_t timeStampData;
  std::string timeStampString;
  std::string binaryPayload;
  std::string parsedText;
  int32_t subscriptionId;
  int16_t processorId;
  int64_t hwTimeStampData;
  std::string hwTimeStampString;
  std::string ulogSource;
  int64_t receiveTimeData;
  std::string receiveTimeString;
  std::string queryResultJson;
  std::string summaryText;
  int64_t transactionId;
  int16_t qdssChannelId;
  int16_t qdssMasterId;
  int8_t qdssAtid;
  std::string defaultFormatText;
  int16_t callFrameNumber;
  int64_t timeStampTodAdjustedData;
  std::string timeStampTodAdjustedString;
  std::vector<std::string>  formatStringArguments;
  int16_t packetSize;
  std::vector<std::string>  qtraceTags;
  int32_t miscellaneousId;
  std::string queryResultPickled;
  int64_t formatStringHash;
  KeyInfo encryptionKeyInfo;
  ExceptionMessageType::type exceptionMessageType;

  _DiagPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_packetType(const DiagPacketType::type val);

  void __set_packetId(const std::string& val);

  void __set_moreResponsesFlag(const bool val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_packetName(const std::string& val);

  void __set_timeStampData(const int64_t val);

  void __set_timeStampString(const std::string& val);

  void __set_binaryPayload(const std::string& val);

  void __set_parsedText(const std::string& val);

  void __set_subscriptionId(const int32_t val);

  void __set_processorId(const int16_t val);

  void __set_hwTimeStampData(const int64_t val);

  void __set_hwTimeStampString(const std::string& val);

  void __set_ulogSource(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  void __set_queryResultJson(const std::string& val);

  void __set_summaryText(const std::string& val);

  void __set_transactionId(const int64_t val);

  void __set_qdssChannelId(const int16_t val);

  void __set_qdssMasterId(const int16_t val);

  void __set_qdssAtid(const int8_t val);

  void __set_defaultFormatText(const std::string& val);

  void __set_callFrameNumber(const int16_t val);

  void __set_timeStampTodAdjustedData(const int64_t val);

  void __set_timeStampTodAdjustedString(const std::string& val);

  void __set_formatStringArguments(const std::vector<std::string> & val);

  void __set_packetSize(const int16_t val);

  void __set_qtraceTags(const std::vector<std::string> & val);

  void __set_miscellaneousId(const int32_t val);

  void __set_queryResultPickled(const std::string& val);

  void __set_formatStringHash(const int64_t val);

  void __set_encryptionKeyInfo(const KeyInfo& val);

  void __set_exceptionMessageType(const ExceptionMessageType::type val);

  bool operator == (const DiagPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.packetType != rhs.__isset.packetType)
      return false;
    else if (__isset.packetType && !(packetType == rhs.packetType))
      return false;
    if (__isset.packetId != rhs.__isset.packetId)
      return false;
    else if (__isset.packetId && !(packetId == rhs.packetId))
      return false;
    if (__isset.moreResponsesFlag != rhs.__isset.moreResponsesFlag)
      return false;
    else if (__isset.moreResponsesFlag && !(moreResponsesFlag == rhs.moreResponsesFlag))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.packetName != rhs.__isset.packetName)
      return false;
    else if (__isset.packetName && !(packetName == rhs.packetName))
      return false;
    if (__isset.timeStampData != rhs.__isset.timeStampData)
      return false;
    else if (__isset.timeStampData && !(timeStampData == rhs.timeStampData))
      return false;
    if (__isset.timeStampString != rhs.__isset.timeStampString)
      return false;
    else if (__isset.timeStampString && !(timeStampString == rhs.timeStampString))
      return false;
    if (__isset.binaryPayload != rhs.__isset.binaryPayload)
      return false;
    else if (__isset.binaryPayload && !(binaryPayload == rhs.binaryPayload))
      return false;
    if (__isset.parsedText != rhs.__isset.parsedText)
      return false;
    else if (__isset.parsedText && !(parsedText == rhs.parsedText))
      return false;
    if (__isset.subscriptionId != rhs.__isset.subscriptionId)
      return false;
    else if (__isset.subscriptionId && !(subscriptionId == rhs.subscriptionId))
      return false;
    if (__isset.processorId != rhs.__isset.processorId)
      return false;
    else if (__isset.processorId && !(processorId == rhs.processorId))
      return false;
    if (__isset.hwTimeStampData != rhs.__isset.hwTimeStampData)
      return false;
    else if (__isset.hwTimeStampData && !(hwTimeStampData == rhs.hwTimeStampData))
      return false;
    if (__isset.hwTimeStampString != rhs.__isset.hwTimeStampString)
      return false;
    else if (__isset.hwTimeStampString && !(hwTimeStampString == rhs.hwTimeStampString))
      return false;
    if (__isset.ulogSource != rhs.__isset.ulogSource)
      return false;
    else if (__isset.ulogSource && !(ulogSource == rhs.ulogSource))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    if (__isset.queryResultJson != rhs.__isset.queryResultJson)
      return false;
    else if (__isset.queryResultJson && !(queryResultJson == rhs.queryResultJson))
      return false;
    if (__isset.summaryText != rhs.__isset.summaryText)
      return false;
    else if (__isset.summaryText && !(summaryText == rhs.summaryText))
      return false;
    if (__isset.transactionId != rhs.__isset.transactionId)
      return false;
    else if (__isset.transactionId && !(transactionId == rhs.transactionId))
      return false;
    if (__isset.qdssChannelId != rhs.__isset.qdssChannelId)
      return false;
    else if (__isset.qdssChannelId && !(qdssChannelId == rhs.qdssChannelId))
      return false;
    if (__isset.qdssMasterId != rhs.__isset.qdssMasterId)
      return false;
    else if (__isset.qdssMasterId && !(qdssMasterId == rhs.qdssMasterId))
      return false;
    if (__isset.qdssAtid != rhs.__isset.qdssAtid)
      return false;
    else if (__isset.qdssAtid && !(qdssAtid == rhs.qdssAtid))
      return false;
    if (__isset.defaultFormatText != rhs.__isset.defaultFormatText)
      return false;
    else if (__isset.defaultFormatText && !(defaultFormatText == rhs.defaultFormatText))
      return false;
    if (__isset.callFrameNumber != rhs.__isset.callFrameNumber)
      return false;
    else if (__isset.callFrameNumber && !(callFrameNumber == rhs.callFrameNumber))
      return false;
    if (__isset.timeStampTodAdjustedData != rhs.__isset.timeStampTodAdjustedData)
      return false;
    else if (__isset.timeStampTodAdjustedData && !(timeStampTodAdjustedData == rhs.timeStampTodAdjustedData))
      return false;
    if (__isset.timeStampTodAdjustedString != rhs.__isset.timeStampTodAdjustedString)
      return false;
    else if (__isset.timeStampTodAdjustedString && !(timeStampTodAdjustedString == rhs.timeStampTodAdjustedString))
      return false;
    if (__isset.formatStringArguments != rhs.__isset.formatStringArguments)
      return false;
    else if (__isset.formatStringArguments && !(formatStringArguments == rhs.formatStringArguments))
      return false;
    if (__isset.packetSize != rhs.__isset.packetSize)
      return false;
    else if (__isset.packetSize && !(packetSize == rhs.packetSize))
      return false;
    if (__isset.qtraceTags != rhs.__isset.qtraceTags)
      return false;
    else if (__isset.qtraceTags && !(qtraceTags == rhs.qtraceTags))
      return false;
    if (__isset.miscellaneousId != rhs.__isset.miscellaneousId)
      return false;
    else if (__isset.miscellaneousId && !(miscellaneousId == rhs.miscellaneousId))
      return false;
    if (__isset.queryResultPickled != rhs.__isset.queryResultPickled)
      return false;
    else if (__isset.queryResultPickled && !(queryResultPickled == rhs.queryResultPickled))
      return false;
    if (__isset.formatStringHash != rhs.__isset.formatStringHash)
      return false;
    else if (__isset.formatStringHash && !(formatStringHash == rhs.formatStringHash))
      return false;
    if (__isset.encryptionKeyInfo != rhs.__isset.encryptionKeyInfo)
      return false;
    else if (__isset.encryptionKeyInfo && !(encryptionKeyInfo == rhs.encryptionKeyInfo))
      return false;
    if (__isset.exceptionMessageType != rhs.__isset.exceptionMessageType)
      return false;
    else if (__isset.exceptionMessageType && !(exceptionMessageType == rhs.exceptionMessageType))
      return false;
    return true;
  }
  bool operator != (const DiagPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagPacket &a, DiagPacket &b);

std::ostream& operator<<(std::ostream& out, const DiagPacket& obj);

typedef struct _AnnotationSearchSettings__isset {
  _AnnotationSearchSettings__isset() : searchString(false), options(false), fields(false) {}
  bool searchString :1;
  bool options :1;
  bool fields :1;
} _AnnotationSearchSettings__isset;

class AnnotationSearchSettings : public virtual ::apache::thrift::TBase {
 public:

  AnnotationSearchSettings(const AnnotationSearchSettings&);
  AnnotationSearchSettings& operator=(const AnnotationSearchSettings&);
  AnnotationSearchSettings() : searchString(), options((SearchOptions::type)0), fields((AnnotationReturnFlags::type)0) {
  }

  virtual ~AnnotationSearchSettings() noexcept;
  std::string searchString;
  SearchOptions::type options;
  AnnotationReturnFlags::type fields;

  _AnnotationSearchSettings__isset __isset;

  void __set_searchString(const std::string& val);

  void __set_options(const SearchOptions::type val);

  void __set_fields(const AnnotationReturnFlags::type val);

  bool operator == (const AnnotationSearchSettings & rhs) const
  {
    if (__isset.searchString != rhs.__isset.searchString)
      return false;
    else if (__isset.searchString && !(searchString == rhs.searchString))
      return false;
    if (__isset.options != rhs.__isset.options)
      return false;
    else if (__isset.options && !(options == rhs.options))
      return false;
    if (__isset.fields != rhs.__isset.fields)
      return false;
    else if (__isset.fields && !(fields == rhs.fields))
      return false;
    return true;
  }
  bool operator != (const AnnotationSearchSettings &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AnnotationSearchSettings & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(AnnotationSearchSettings &a, AnnotationSearchSettings &b);

std::ostream& operator<<(std::ostream& out, const AnnotationSearchSettings& obj);

typedef struct _AnnotationFilterItem__isset {
  _AnnotationFilterItem__isset() : messageId(false), searchSettings(false) {}
  bool messageId :1;
  bool searchSettings :1;
} _AnnotationFilterItem__isset;

class AnnotationFilterItem : public virtual ::apache::thrift::TBase {
 public:

  AnnotationFilterItem(const AnnotationFilterItem&);
  AnnotationFilterItem& operator=(const AnnotationFilterItem&);
  AnnotationFilterItem() : messageId(0) {
  }

  virtual ~AnnotationFilterItem() noexcept;
  int64_t messageId;
  AnnotationSearchSettings searchSettings;

  _AnnotationFilterItem__isset __isset;

  void __set_messageId(const int64_t val);

  void __set_searchSettings(const AnnotationSearchSettings& val);

  bool operator == (const AnnotationFilterItem & rhs) const
  {
    if (__isset.messageId != rhs.__isset.messageId)
      return false;
    else if (__isset.messageId && !(messageId == rhs.messageId))
      return false;
    if (__isset.searchSettings != rhs.__isset.searchSettings)
      return false;
    else if (__isset.searchSettings && !(searchSettings == rhs.searchSettings))
      return false;
    return true;
  }
  bool operator != (const AnnotationFilterItem &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AnnotationFilterItem & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(AnnotationFilterItem &a, AnnotationFilterItem &b);

std::ostream& operator<<(std::ostream& out, const AnnotationFilterItem& obj);

typedef struct _AnnotationPacketFilter__isset {
  _AnnotationPacketFilter__isset() : includeAnnotations(false), messageIdFilter(false), filter(false) {}
  bool includeAnnotations :1;
  bool messageIdFilter :1;
  bool filter :1;
} _AnnotationPacketFilter__isset;

class AnnotationPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  AnnotationPacketFilter(const AnnotationPacketFilter&);
  AnnotationPacketFilter& operator=(const AnnotationPacketFilter&);
  AnnotationPacketFilter() : includeAnnotations(0) {
  }

  virtual ~AnnotationPacketFilter() noexcept;
  bool includeAnnotations;
  std::vector<int64_t>  messageIdFilter;
  std::vector<AnnotationFilterItem>  filter;

  _AnnotationPacketFilter__isset __isset;

  void __set_includeAnnotations(const bool val);

  void __set_messageIdFilter(const std::vector<int64_t> & val);

  void __set_filter(const std::vector<AnnotationFilterItem> & val);

  bool operator == (const AnnotationPacketFilter & rhs) const
  {
    if (__isset.includeAnnotations != rhs.__isset.includeAnnotations)
      return false;
    else if (__isset.includeAnnotations && !(includeAnnotations == rhs.includeAnnotations))
      return false;
    if (__isset.messageIdFilter != rhs.__isset.messageIdFilter)
      return false;
    else if (__isset.messageIdFilter && !(messageIdFilter == rhs.messageIdFilter))
      return false;
    if (__isset.filter != rhs.__isset.filter)
      return false;
    else if (__isset.filter && !(filter == rhs.filter))
      return false;
    return true;
  }
  bool operator != (const AnnotationPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AnnotationPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(AnnotationPacketFilter &a, AnnotationPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const AnnotationPacketFilter& obj);

typedef struct _AnnotationPacket__isset {
  _AnnotationPacket__isset() : errorCode(false), sessionIndex(false), protocolIndex(false), parsedText(false), messageId(false), receiveTimeData(false), receiveTimeString(false) {}
  bool errorCode :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool parsedText :1;
  bool messageId :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
} _AnnotationPacket__isset;

class AnnotationPacket : public virtual ::apache::thrift::TBase {
 public:

  AnnotationPacket(const AnnotationPacket&);
  AnnotationPacket& operator=(const AnnotationPacket&);
  AnnotationPacket() : errorCode((ErrorCode::type)0), sessionIndex(0), protocolIndex(0), parsedText(), messageId(0), receiveTimeData(0), receiveTimeString() {
  }

  virtual ~AnnotationPacket() noexcept;
  ErrorCode::type errorCode;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string parsedText;
  int64_t messageId;
  int64_t receiveTimeData;
  std::string receiveTimeString;

  _AnnotationPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_parsedText(const std::string& val);

  void __set_messageId(const int64_t val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  bool operator == (const AnnotationPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.parsedText != rhs.__isset.parsedText)
      return false;
    else if (__isset.parsedText && !(parsedText == rhs.parsedText))
      return false;
    if (__isset.messageId != rhs.__isset.messageId)
      return false;
    else if (__isset.messageId && !(messageId == rhs.messageId))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    return true;
  }
  bool operator != (const AnnotationPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AnnotationPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(AnnotationPacket &a, AnnotationPacket &b);

std::ostream& operator<<(std::ostream& out, const AnnotationPacket& obj);

typedef struct _QmiPacketFilter__isset {
  _QmiPacketFilter__isset() : idOrNameMask(false) {}
  bool idOrNameMask :1;
} _QmiPacketFilter__isset;

class QmiPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  QmiPacketFilter(const QmiPacketFilter&);
  QmiPacketFilter& operator=(const QmiPacketFilter&);
  QmiPacketFilter() {
  }

  virtual ~QmiPacketFilter() noexcept;
  std::map<QmiPacketType::type, std::vector<std::string> >  idOrNameMask;

  _QmiPacketFilter__isset __isset;

  void __set_idOrNameMask(const std::map<QmiPacketType::type, std::vector<std::string> > & val);

  bool operator == (const QmiPacketFilter & rhs) const
  {
    if (__isset.idOrNameMask != rhs.__isset.idOrNameMask)
      return false;
    else if (__isset.idOrNameMask && !(idOrNameMask == rhs.idOrNameMask))
      return false;
    return true;
  }
  bool operator != (const QmiPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmiPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmiPacketFilter &a, QmiPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const QmiPacketFilter& obj);

typedef struct _QmiReturns__isset {
  _QmiReturns__isset() : flags(false), queries(false) {}
  bool flags :1;
  bool queries :1;
} _QmiReturns__isset;

class QmiReturns : public virtual ::apache::thrift::TBase {
 public:

  QmiReturns(const QmiReturns&);
  QmiReturns& operator=(const QmiReturns&);
  QmiReturns() : flags((QmiReturnFlags::type)0) {
  }

  virtual ~QmiReturns() noexcept;
  QmiReturnFlags::type flags;
  std::vector<std::string>  queries;

  _QmiReturns__isset __isset;

  void __set_flags(const QmiReturnFlags::type val);

  void __set_queries(const std::vector<std::string> & val);

  bool operator == (const QmiReturns & rhs) const
  {
    if (__isset.flags != rhs.__isset.flags)
      return false;
    else if (__isset.flags && !(flags == rhs.flags))
      return false;
    if (__isset.queries != rhs.__isset.queries)
      return false;
    else if (__isset.queries && !(queries == rhs.queries))
      return false;
    return true;
  }
  bool operator != (const QmiReturns &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmiReturns & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmiReturns &a, QmiReturns &b);

std::ostream& operator<<(std::ostream& out, const QmiReturns& obj);

typedef struct _QmiReturnConfig__isset {
  _QmiReturnConfig__isset() : flags(false), fieldQueries(false) {}
  bool flags :1;
  bool fieldQueries :1;
} _QmiReturnConfig__isset;

class QmiReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  QmiReturnConfig(const QmiReturnConfig&);
  QmiReturnConfig& operator=(const QmiReturnConfig&);
  QmiReturnConfig() : flags((QmiReturnFlags::type)0) {
  }

  virtual ~QmiReturnConfig() noexcept;
  QmiReturnFlags::type flags;
  std::map<QmiPacketType::type, std::map<std::string, QmiReturns> >  fieldQueries;

  _QmiReturnConfig__isset __isset;

  void __set_flags(const QmiReturnFlags::type val);

  void __set_fieldQueries(const std::map<QmiPacketType::type, std::map<std::string, QmiReturns> > & val);

  bool operator == (const QmiReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    if (__isset.fieldQueries != rhs.__isset.fieldQueries)
      return false;
    else if (__isset.fieldQueries && !(fieldQueries == rhs.fieldQueries))
      return false;
    return true;
  }
  bool operator != (const QmiReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmiReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmiReturnConfig &a, QmiReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const QmiReturnConfig& obj);

typedef struct _QmiPacket__isset {
  _QmiPacket__isset() : errorCode(false), packetType(false), serviceId(false), messageId(false), sessionIndex(false), protocolIndex(false), packetName(false), binaryPayload(false), parsedXml(false), receiveTimeData(false), receiveTimeString(false), queryResultJson(false), transactionId(false) {}
  bool errorCode :1;
  bool packetType :1;
  bool serviceId :1;
  bool messageId :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool packetName :1;
  bool binaryPayload :1;
  bool parsedXml :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
  bool queryResultJson :1;
  bool transactionId :1;
} _QmiPacket__isset;

class QmiPacket : public virtual ::apache::thrift::TBase {
 public:

  QmiPacket(const QmiPacket&);
  QmiPacket& operator=(const QmiPacket&);
  QmiPacket() : errorCode((ErrorCode::type)0), packetType((QmiPacketType::type)0), serviceId(0), messageId(0), sessionIndex(0), protocolIndex(0), packetName(), binaryPayload(), parsedXml(), receiveTimeData(0), receiveTimeString(), queryResultJson(), transactionId(0) {
  }

  virtual ~QmiPacket() noexcept;
  ErrorCode::type errorCode;
  QmiPacketType::type packetType;
  int32_t serviceId;
  int16_t messageId;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string packetName;
  std::string binaryPayload;
  std::string parsedXml;
  int64_t receiveTimeData;
  std::string receiveTimeString;
  std::string queryResultJson;
  int64_t transactionId;

  _QmiPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_packetType(const QmiPacketType::type val);

  void __set_serviceId(const int32_t val);

  void __set_messageId(const int16_t val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_packetName(const std::string& val);

  void __set_binaryPayload(const std::string& val);

  void __set_parsedXml(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  void __set_queryResultJson(const std::string& val);

  void __set_transactionId(const int64_t val);

  bool operator == (const QmiPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.packetType != rhs.__isset.packetType)
      return false;
    else if (__isset.packetType && !(packetType == rhs.packetType))
      return false;
    if (__isset.serviceId != rhs.__isset.serviceId)
      return false;
    else if (__isset.serviceId && !(serviceId == rhs.serviceId))
      return false;
    if (__isset.messageId != rhs.__isset.messageId)
      return false;
    else if (__isset.messageId && !(messageId == rhs.messageId))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.packetName != rhs.__isset.packetName)
      return false;
    else if (__isset.packetName && !(packetName == rhs.packetName))
      return false;
    if (__isset.binaryPayload != rhs.__isset.binaryPayload)
      return false;
    else if (__isset.binaryPayload && !(binaryPayload == rhs.binaryPayload))
      return false;
    if (__isset.parsedXml != rhs.__isset.parsedXml)
      return false;
    else if (__isset.parsedXml && !(parsedXml == rhs.parsedXml))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    if (__isset.queryResultJson != rhs.__isset.queryResultJson)
      return false;
    else if (__isset.queryResultJson && !(queryResultJson == rhs.queryResultJson))
      return false;
    if (__isset.transactionId != rhs.__isset.transactionId)
      return false;
    else if (__isset.transactionId && !(transactionId == rhs.transactionId))
      return false;
    return true;
  }
  bool operator != (const QmiPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmiPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmiPacket &a, QmiPacket &b);

std::ostream& operator<<(std::ostream& out, const QmiPacket& obj);

typedef struct _AdbPacketFilter__isset {
  _AdbPacketFilter__isset() : regexFilter(false) {}
  bool regexFilter :1;
} _AdbPacketFilter__isset;

class AdbPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  AdbPacketFilter(const AdbPacketFilter&);
  AdbPacketFilter& operator=(const AdbPacketFilter&);
  AdbPacketFilter() : regexFilter() {
  }

  virtual ~AdbPacketFilter() noexcept;
  std::string regexFilter;

  _AdbPacketFilter__isset __isset;

  void __set_regexFilter(const std::string& val);

  bool operator == (const AdbPacketFilter & rhs) const
  {
    if (__isset.regexFilter != rhs.__isset.regexFilter)
      return false;
    else if (__isset.regexFilter && !(regexFilter == rhs.regexFilter))
      return false;
    return true;
  }
  bool operator != (const AdbPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AdbPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(AdbPacketFilter &a, AdbPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const AdbPacketFilter& obj);

typedef struct _AdbReturnConfig__isset {
  _AdbReturnConfig__isset() : flags(false) {}
  bool flags :1;
} _AdbReturnConfig__isset;

class AdbReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  AdbReturnConfig(const AdbReturnConfig&);
  AdbReturnConfig& operator=(const AdbReturnConfig&);
  AdbReturnConfig() : flags((AdbReturnFlags::type)0) {
  }

  virtual ~AdbReturnConfig() noexcept;
  AdbReturnFlags::type flags;

  _AdbReturnConfig__isset __isset;

  void __set_flags(const AdbReturnFlags::type val);

  bool operator == (const AdbReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    return true;
  }
  bool operator != (const AdbReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AdbReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(AdbReturnConfig &a, AdbReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const AdbReturnConfig& obj);

typedef struct _AdbPacket__isset {
  _AdbPacket__isset() : errorCode(false), sessionIndex(false), protocolIndex(false), packetText(false), receiveTimeData(false), receiveTimeString(false) {}
  bool errorCode :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool packetText :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
} _AdbPacket__isset;

class AdbPacket : public virtual ::apache::thrift::TBase {
 public:

  AdbPacket(const AdbPacket&);
  AdbPacket& operator=(const AdbPacket&);
  AdbPacket() : errorCode((ErrorCode::type)0), sessionIndex(0), protocolIndex(0), packetText(), receiveTimeData(0), receiveTimeString() {
  }

  virtual ~AdbPacket() noexcept;
  ErrorCode::type errorCode;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string packetText;
  int64_t receiveTimeData;
  std::string receiveTimeString;

  _AdbPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_packetText(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  bool operator == (const AdbPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.packetText != rhs.__isset.packetText)
      return false;
    else if (__isset.packetText && !(packetText == rhs.packetText))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    return true;
  }
  bool operator != (const AdbPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AdbPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(AdbPacket &a, AdbPacket &b);

std::ostream& operator<<(std::ostream& out, const AdbPacket& obj);

typedef struct _TelnetPacketFilter__isset {
  _TelnetPacketFilter__isset() : regexFilter(false) {}
  bool regexFilter :1;
} _TelnetPacketFilter__isset;

class TelnetPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  TelnetPacketFilter(const TelnetPacketFilter&);
  TelnetPacketFilter& operator=(const TelnetPacketFilter&);
  TelnetPacketFilter() : regexFilter() {
  }

  virtual ~TelnetPacketFilter() noexcept;
  std::string regexFilter;

  _TelnetPacketFilter__isset __isset;

  void __set_regexFilter(const std::string& val);

  bool operator == (const TelnetPacketFilter & rhs) const
  {
    if (__isset.regexFilter != rhs.__isset.regexFilter)
      return false;
    else if (__isset.regexFilter && !(regexFilter == rhs.regexFilter))
      return false;
    return true;
  }
  bool operator != (const TelnetPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TelnetPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TelnetPacketFilter &a, TelnetPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const TelnetPacketFilter& obj);

typedef struct _TelnetReturnConfig__isset {
  _TelnetReturnConfig__isset() : flags(false) {}
  bool flags :1;
} _TelnetReturnConfig__isset;

class TelnetReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  TelnetReturnConfig(const TelnetReturnConfig&);
  TelnetReturnConfig& operator=(const TelnetReturnConfig&);
  TelnetReturnConfig() : flags((TelnetReturnFlags::type)0) {
  }

  virtual ~TelnetReturnConfig() noexcept;
  TelnetReturnFlags::type flags;

  _TelnetReturnConfig__isset __isset;

  void __set_flags(const TelnetReturnFlags::type val);

  bool operator == (const TelnetReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    return true;
  }
  bool operator != (const TelnetReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TelnetReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TelnetReturnConfig &a, TelnetReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const TelnetReturnConfig& obj);

typedef struct _TelnetPacket__isset {
  _TelnetPacket__isset() : errorCode(false), sessionIndex(false), protocolIndex(false), packetText(false), receiveTimeData(false), receiveTimeString(false) {}
  bool errorCode :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool packetText :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
} _TelnetPacket__isset;

class TelnetPacket : public virtual ::apache::thrift::TBase {
 public:

  TelnetPacket(const TelnetPacket&);
  TelnetPacket& operator=(const TelnetPacket&);
  TelnetPacket() : errorCode((ErrorCode::type)0), sessionIndex(0), protocolIndex(0), packetText(), receiveTimeData(0), receiveTimeString() {
  }

  virtual ~TelnetPacket() noexcept;
  ErrorCode::type errorCode;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string packetText;
  int64_t receiveTimeData;
  std::string receiveTimeString;

  _TelnetPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_packetText(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  bool operator == (const TelnetPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.packetText != rhs.__isset.packetText)
      return false;
    else if (__isset.packetText && !(packetText == rhs.packetText))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    return true;
  }
  bool operator != (const TelnetPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TelnetPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TelnetPacket &a, TelnetPacket &b);

std::ostream& operator<<(std::ostream& out, const TelnetPacket& obj);

typedef struct _SaharaPacketFilter__isset {
  _SaharaPacketFilter__isset() : idOrNameMask(false) {}
  bool idOrNameMask :1;
} _SaharaPacketFilter__isset;

class SaharaPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  SaharaPacketFilter(const SaharaPacketFilter&);
  SaharaPacketFilter& operator=(const SaharaPacketFilter&);
  SaharaPacketFilter() {
  }

  virtual ~SaharaPacketFilter() noexcept;
  std::vector<std::string>  idOrNameMask;

  _SaharaPacketFilter__isset __isset;

  void __set_idOrNameMask(const std::vector<std::string> & val);

  bool operator == (const SaharaPacketFilter & rhs) const
  {
    if (__isset.idOrNameMask != rhs.__isset.idOrNameMask)
      return false;
    else if (__isset.idOrNameMask && !(idOrNameMask == rhs.idOrNameMask))
      return false;
    return true;
  }
  bool operator != (const SaharaPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SaharaPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SaharaPacketFilter &a, SaharaPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const SaharaPacketFilter& obj);

typedef struct _SaharaReturnConfig__isset {
  _SaharaReturnConfig__isset() : flags(false) {}
  bool flags :1;
} _SaharaReturnConfig__isset;

class SaharaReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  SaharaReturnConfig(const SaharaReturnConfig&);
  SaharaReturnConfig& operator=(const SaharaReturnConfig&);
  SaharaReturnConfig() : flags((SaharaReturnFlags::type)0) {
  }

  virtual ~SaharaReturnConfig() noexcept;
  SaharaReturnFlags::type flags;

  _SaharaReturnConfig__isset __isset;

  void __set_flags(const SaharaReturnFlags::type val);

  bool operator == (const SaharaReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    return true;
  }
  bool operator != (const SaharaReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SaharaReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SaharaReturnConfig &a, SaharaReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const SaharaReturnConfig& obj);

typedef struct _SaharaPacket__isset {
  _SaharaPacket__isset() : errorCode(false), packetId(false), sessionIndex(false), protocolIndex(false), packetName(false), binaryPayload(false), receiveTimeData(false), receiveTimeString(false) {}
  bool errorCode :1;
  bool packetId :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool packetName :1;
  bool binaryPayload :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
} _SaharaPacket__isset;

class SaharaPacket : public virtual ::apache::thrift::TBase {
 public:

  SaharaPacket(const SaharaPacket&);
  SaharaPacket& operator=(const SaharaPacket&);
  SaharaPacket() : errorCode((ErrorCode::type)0), packetId(0), sessionIndex(0), protocolIndex(0), packetName(), binaryPayload(), receiveTimeData(0), receiveTimeString() {
  }

  virtual ~SaharaPacket() noexcept;
  ErrorCode::type errorCode;
  int32_t packetId;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string packetName;
  std::string binaryPayload;
  int64_t receiveTimeData;
  std::string receiveTimeString;

  _SaharaPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_packetId(const int32_t val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_packetName(const std::string& val);

  void __set_binaryPayload(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  bool operator == (const SaharaPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.packetId != rhs.__isset.packetId)
      return false;
    else if (__isset.packetId && !(packetId == rhs.packetId))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.packetName != rhs.__isset.packetName)
      return false;
    else if (__isset.packetName && !(packetName == rhs.packetName))
      return false;
    if (__isset.binaryPayload != rhs.__isset.binaryPayload)
      return false;
    else if (__isset.binaryPayload && !(binaryPayload == rhs.binaryPayload))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    return true;
  }
  bool operator != (const SaharaPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SaharaPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SaharaPacket &a, SaharaPacket &b);

std::ostream& operator<<(std::ostream& out, const SaharaPacket& obj);

typedef struct _FastbootPacketFilter__isset {
  _FastbootPacketFilter__isset() : regexFilter(false) {}
  bool regexFilter :1;
} _FastbootPacketFilter__isset;

class FastbootPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  FastbootPacketFilter(const FastbootPacketFilter&);
  FastbootPacketFilter& operator=(const FastbootPacketFilter&);
  FastbootPacketFilter() : regexFilter() {
  }

  virtual ~FastbootPacketFilter() noexcept;
  std::string regexFilter;

  _FastbootPacketFilter__isset __isset;

  void __set_regexFilter(const std::string& val);

  bool operator == (const FastbootPacketFilter & rhs) const
  {
    if (__isset.regexFilter != rhs.__isset.regexFilter)
      return false;
    else if (__isset.regexFilter && !(regexFilter == rhs.regexFilter))
      return false;
    return true;
  }
  bool operator != (const FastbootPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FastbootPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(FastbootPacketFilter &a, FastbootPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const FastbootPacketFilter& obj);

typedef struct _FastbootReturnConfig__isset {
  _FastbootReturnConfig__isset() : flags(false) {}
  bool flags :1;
} _FastbootReturnConfig__isset;

class FastbootReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  FastbootReturnConfig(const FastbootReturnConfig&);
  FastbootReturnConfig& operator=(const FastbootReturnConfig&);
  FastbootReturnConfig() : flags((FastbootReturnFlags::type)0) {
  }

  virtual ~FastbootReturnConfig() noexcept;
  FastbootReturnFlags::type flags;

  _FastbootReturnConfig__isset __isset;

  void __set_flags(const FastbootReturnFlags::type val);

  bool operator == (const FastbootReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    return true;
  }
  bool operator != (const FastbootReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FastbootReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(FastbootReturnConfig &a, FastbootReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const FastbootReturnConfig& obj);

typedef struct _FastbootPacket__isset {
  _FastbootPacket__isset() : errorCode(false), sessionIndex(false), protocolIndex(false), packetText(false), receiveTimeData(false), receiveTimeString(false) {}
  bool errorCode :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool packetText :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
} _FastbootPacket__isset;

class FastbootPacket : public virtual ::apache::thrift::TBase {
 public:

  FastbootPacket(const FastbootPacket&);
  FastbootPacket& operator=(const FastbootPacket&);
  FastbootPacket() : errorCode((ErrorCode::type)0), sessionIndex(0), protocolIndex(0), packetText(), receiveTimeData(0), receiveTimeString() {
  }

  virtual ~FastbootPacket() noexcept;
  ErrorCode::type errorCode;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string packetText;
  int64_t receiveTimeData;
  std::string receiveTimeString;

  _FastbootPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_packetText(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  bool operator == (const FastbootPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.packetText != rhs.__isset.packetText)
      return false;
    else if (__isset.packetText && !(packetText == rhs.packetText))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    return true;
  }
  bool operator != (const FastbootPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FastbootPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(FastbootPacket &a, FastbootPacket &b);

std::ostream& operator<<(std::ostream& out, const FastbootPacket& obj);

typedef struct _EudPacketFilter__isset {
  _EudPacketFilter__isset() : opCodeMask(false) {}
  bool opCodeMask :1;
} _EudPacketFilter__isset;

class EudPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  EudPacketFilter(const EudPacketFilter&);
  EudPacketFilter& operator=(const EudPacketFilter&);
  EudPacketFilter() {
  }

  virtual ~EudPacketFilter() noexcept;
  std::vector<std::string>  opCodeMask;

  _EudPacketFilter__isset __isset;

  void __set_opCodeMask(const std::vector<std::string> & val);

  bool operator == (const EudPacketFilter & rhs) const
  {
    if (__isset.opCodeMask != rhs.__isset.opCodeMask)
      return false;
    else if (__isset.opCodeMask && !(opCodeMask == rhs.opCodeMask))
      return false;
    return true;
  }
  bool operator != (const EudPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(EudPacketFilter &a, EudPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const EudPacketFilter& obj);

typedef struct _EudReturnConfig__isset {
  _EudReturnConfig__isset() : flags(false) {}
  bool flags :1;
} _EudReturnConfig__isset;

class EudReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  EudReturnConfig(const EudReturnConfig&);
  EudReturnConfig& operator=(const EudReturnConfig&);
  EudReturnConfig() : flags((EudReturnFlags::type)0) {
  }

  virtual ~EudReturnConfig() noexcept;
  EudReturnFlags::type flags;

  _EudReturnConfig__isset __isset;

  void __set_flags(const EudReturnFlags::type val);

  bool operator == (const EudReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    return true;
  }
  bool operator != (const EudReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(EudReturnConfig &a, EudReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const EudReturnConfig& obj);

typedef struct _EudPacket__isset {
  _EudPacket__isset() : errorCode(false), packetId(false), sessionIndex(false), protocolIndex(false), packetName(false), binaryPayload(false), receiveTimeData(false), receiveTimeString(false) {}
  bool errorCode :1;
  bool packetId :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool packetName :1;
  bool binaryPayload :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
} _EudPacket__isset;

class EudPacket : public virtual ::apache::thrift::TBase {
 public:

  EudPacket(const EudPacket&);
  EudPacket& operator=(const EudPacket&);
  EudPacket() : errorCode((ErrorCode::type)0), packetId(0), sessionIndex(0), protocolIndex(0), packetName(), binaryPayload(), receiveTimeData(0), receiveTimeString() {
  }

  virtual ~EudPacket() noexcept;
  ErrorCode::type errorCode;
  int32_t packetId;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string packetName;
  std::string binaryPayload;
  int64_t receiveTimeData;
  std::string receiveTimeString;

  _EudPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_packetId(const int32_t val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_packetName(const std::string& val);

  void __set_binaryPayload(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  bool operator == (const EudPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.packetId != rhs.__isset.packetId)
      return false;
    else if (__isset.packetId && !(packetId == rhs.packetId))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.packetName != rhs.__isset.packetName)
      return false;
    else if (__isset.packetName && !(packetName == rhs.packetName))
      return false;
    if (__isset.binaryPayload != rhs.__isset.binaryPayload)
      return false;
    else if (__isset.binaryPayload && !(binaryPayload == rhs.binaryPayload))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    return true;
  }
  bool operator != (const EudPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(EudPacket &a, EudPacket &b);

std::ostream& operator<<(std::ostream& out, const EudPacket& obj);

typedef struct _RpcToCapabilityNameMap__isset {
  _RpcToCapabilityNameMap__isset() : rpcCapabilityNameList(false) {}
  bool rpcCapabilityNameList :1;
} _RpcToCapabilityNameMap__isset;

class RpcToCapabilityNameMap : public virtual ::apache::thrift::TBase {
 public:

  RpcToCapabilityNameMap(const RpcToCapabilityNameMap&);
  RpcToCapabilityNameMap& operator=(const RpcToCapabilityNameMap&);
  RpcToCapabilityNameMap() {
  }

  virtual ~RpcToCapabilityNameMap() noexcept;
  std::map<std::string, std::vector<std::string> >  rpcCapabilityNameList;

  _RpcToCapabilityNameMap__isset __isset;

  void __set_rpcCapabilityNameList(const std::map<std::string, std::vector<std::string> > & val);

  bool operator == (const RpcToCapabilityNameMap & rhs) const
  {
    if (__isset.rpcCapabilityNameList != rhs.__isset.rpcCapabilityNameList)
      return false;
    else if (__isset.rpcCapabilityNameList && !(rpcCapabilityNameList == rhs.rpcCapabilityNameList))
      return false;
    return true;
  }
  bool operator != (const RpcToCapabilityNameMap &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RpcToCapabilityNameMap & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(RpcToCapabilityNameMap &a, RpcToCapabilityNameMap &b);

std::ostream& operator<<(std::ostream& out, const RpcToCapabilityNameMap& obj);

typedef struct _ProtoBufPacketFilter__isset {
  _ProtoBufPacketFilter__isset() : rpcNameMask(false) {}
  bool rpcNameMask :1;
} _ProtoBufPacketFilter__isset;

class ProtoBufPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  ProtoBufPacketFilter(const ProtoBufPacketFilter&);
  ProtoBufPacketFilter& operator=(const ProtoBufPacketFilter&);
  ProtoBufPacketFilter() {
  }

  virtual ~ProtoBufPacketFilter() noexcept;
  std::map<ProtoBufPacketType::type, RpcToCapabilityNameMap>  rpcNameMask;

  _ProtoBufPacketFilter__isset __isset;

  void __set_rpcNameMask(const std::map<ProtoBufPacketType::type, RpcToCapabilityNameMap> & val);

  bool operator == (const ProtoBufPacketFilter & rhs) const
  {
    if (__isset.rpcNameMask != rhs.__isset.rpcNameMask)
      return false;
    else if (__isset.rpcNameMask && !(rpcNameMask == rhs.rpcNameMask))
      return false;
    return true;
  }
  bool operator != (const ProtoBufPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProtoBufPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProtoBufPacketFilter &a, ProtoBufPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const ProtoBufPacketFilter& obj);

typedef struct _ProtoBufReturns__isset {
  _ProtoBufReturns__isset() : flags(false), queries(false) {}
  bool flags :1;
  bool queries :1;
} _ProtoBufReturns__isset;

class ProtoBufReturns : public virtual ::apache::thrift::TBase {
 public:

  ProtoBufReturns(const ProtoBufReturns&);
  ProtoBufReturns& operator=(const ProtoBufReturns&);
  ProtoBufReturns() : flags((ProtoBufReturnFlags::type)0) {
  }

  virtual ~ProtoBufReturns() noexcept;
  ProtoBufReturnFlags::type flags;
  std::vector<std::string>  queries;

  _ProtoBufReturns__isset __isset;

  void __set_flags(const ProtoBufReturnFlags::type val);

  void __set_queries(const std::vector<std::string> & val);

  bool operator == (const ProtoBufReturns & rhs) const
  {
    if (__isset.flags != rhs.__isset.flags)
      return false;
    else if (__isset.flags && !(flags == rhs.flags))
      return false;
    if (__isset.queries != rhs.__isset.queries)
      return false;
    else if (__isset.queries && !(queries == rhs.queries))
      return false;
    return true;
  }
  bool operator != (const ProtoBufReturns &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProtoBufReturns & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProtoBufReturns &a, ProtoBufReturns &b);

std::ostream& operator<<(std::ostream& out, const ProtoBufReturns& obj);

typedef struct _ProtoBufReturnConfig__isset {
  _ProtoBufReturnConfig__isset() : flags(false), fieldQueries(false) {}
  bool flags :1;
  bool fieldQueries :1;
} _ProtoBufReturnConfig__isset;

class ProtoBufReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  ProtoBufReturnConfig(const ProtoBufReturnConfig&);
  ProtoBufReturnConfig& operator=(const ProtoBufReturnConfig&);
  ProtoBufReturnConfig() : flags((ProtoBufReturnFlags::type)0) {
  }

  virtual ~ProtoBufReturnConfig() noexcept;
  ProtoBufReturnFlags::type flags;
  std::map<ProtoBufPacketType::type, std::map<std::string, ProtoBufReturns> >  fieldQueries;

  _ProtoBufReturnConfig__isset __isset;

  void __set_flags(const ProtoBufReturnFlags::type val);

  void __set_fieldQueries(const std::map<ProtoBufPacketType::type, std::map<std::string, ProtoBufReturns> > & val);

  bool operator == (const ProtoBufReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    if (__isset.fieldQueries != rhs.__isset.fieldQueries)
      return false;
    else if (__isset.fieldQueries && !(fieldQueries == rhs.fieldQueries))
      return false;
    return true;
  }
  bool operator != (const ProtoBufReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProtoBufReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProtoBufReturnConfig &a, ProtoBufReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const ProtoBufReturnConfig& obj);

typedef struct _ProtoBufPacket__isset {
  _ProtoBufPacket__isset() : errorCode(false), packetType(false), rpcId(false), messageId(false), sessionIndex(false), protocolIndex(false), packetName(false), binaryPayload(false), parsedText(false), receiveTimeData(false), receiveTimeString(false), queryResultJson(false), queryResultPickled(false), parsedTextJson(false) {}
  bool errorCode :1;
  bool packetType :1;
  bool rpcId :1;
  bool messageId :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool packetName :1;
  bool binaryPayload :1;
  bool parsedText :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
  bool queryResultJson :1;
  bool queryResultPickled :1;
  bool parsedTextJson :1;
} _ProtoBufPacket__isset;

class ProtoBufPacket : public virtual ::apache::thrift::TBase {
 public:

  ProtoBufPacket(const ProtoBufPacket&);
  ProtoBufPacket& operator=(const ProtoBufPacket&);
  ProtoBufPacket() : errorCode((ErrorCode::type)0), packetType((ProtoBufPacketType::type)0), rpcId(0), messageId(0), sessionIndex(0), protocolIndex(0), packetName(), binaryPayload(), parsedText(), receiveTimeData(0), receiveTimeString(), queryResultJson(), queryResultPickled(), parsedTextJson() {
  }

  virtual ~ProtoBufPacket() noexcept;
  ErrorCode::type errorCode;
  ProtoBufPacketType::type packetType;
  int64_t rpcId;
  int16_t messageId;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string packetName;
  std::string binaryPayload;
  std::string parsedText;
  int64_t receiveTimeData;
  std::string receiveTimeString;
  std::string queryResultJson;
  std::string queryResultPickled;
  std::string parsedTextJson;

  _ProtoBufPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_packetType(const ProtoBufPacketType::type val);

  void __set_rpcId(const int64_t val);

  void __set_messageId(const int16_t val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_packetName(const std::string& val);

  void __set_binaryPayload(const std::string& val);

  void __set_parsedText(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  void __set_queryResultJson(const std::string& val);

  void __set_queryResultPickled(const std::string& val);

  void __set_parsedTextJson(const std::string& val);

  bool operator == (const ProtoBufPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.packetType != rhs.__isset.packetType)
      return false;
    else if (__isset.packetType && !(packetType == rhs.packetType))
      return false;
    if (__isset.rpcId != rhs.__isset.rpcId)
      return false;
    else if (__isset.rpcId && !(rpcId == rhs.rpcId))
      return false;
    if (__isset.messageId != rhs.__isset.messageId)
      return false;
    else if (__isset.messageId && !(messageId == rhs.messageId))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.packetName != rhs.__isset.packetName)
      return false;
    else if (__isset.packetName && !(packetName == rhs.packetName))
      return false;
    if (__isset.binaryPayload != rhs.__isset.binaryPayload)
      return false;
    else if (__isset.binaryPayload && !(binaryPayload == rhs.binaryPayload))
      return false;
    if (__isset.parsedText != rhs.__isset.parsedText)
      return false;
    else if (__isset.parsedText && !(parsedText == rhs.parsedText))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    if (__isset.queryResultJson != rhs.__isset.queryResultJson)
      return false;
    else if (__isset.queryResultJson && !(queryResultJson == rhs.queryResultJson))
      return false;
    if (__isset.queryResultPickled != rhs.__isset.queryResultPickled)
      return false;
    else if (__isset.queryResultPickled && !(queryResultPickled == rhs.queryResultPickled))
      return false;
    if (__isset.parsedTextJson != rhs.__isset.parsedTextJson)
      return false;
    else if (__isset.parsedTextJson && !(parsedTextJson == rhs.parsedTextJson))
      return false;
    return true;
  }
  bool operator != (const ProtoBufPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProtoBufPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProtoBufPacket &a, ProtoBufPacket &b);

std::ostream& operator<<(std::ostream& out, const ProtoBufPacket& obj);

typedef struct _RxTxInfo__isset {
  _RxTxInfo__isset() : rxTotalPacketCount(false), txTotalPacketCount(false), rxTotalByteCount(false), txTotalByteCount(false), rxInstThroughput(false), txInstThroughput(false) {}
  bool rxTotalPacketCount :1;
  bool txTotalPacketCount :1;
  bool rxTotalByteCount :1;
  bool txTotalByteCount :1;
  bool rxInstThroughput :1;
  bool txInstThroughput :1;
} _RxTxInfo__isset;

class RxTxInfo : public virtual ::apache::thrift::TBase {
 public:

  RxTxInfo(const RxTxInfo&);
  RxTxInfo& operator=(const RxTxInfo&);
  RxTxInfo() : rxTotalPacketCount(0), txTotalPacketCount(0), rxTotalByteCount(0), txTotalByteCount(0), rxInstThroughput(0), txInstThroughput(0) {
  }

  virtual ~RxTxInfo() noexcept;
  int64_t rxTotalPacketCount;
  int64_t txTotalPacketCount;
  int64_t rxTotalByteCount;
  int64_t txTotalByteCount;
  double rxInstThroughput;
  double txInstThroughput;

  _RxTxInfo__isset __isset;

  void __set_rxTotalPacketCount(const int64_t val);

  void __set_txTotalPacketCount(const int64_t val);

  void __set_rxTotalByteCount(const int64_t val);

  void __set_txTotalByteCount(const int64_t val);

  void __set_rxInstThroughput(const double val);

  void __set_txInstThroughput(const double val);

  bool operator == (const RxTxInfo & rhs) const
  {
    if (!(rxTotalPacketCount == rhs.rxTotalPacketCount))
      return false;
    if (!(txTotalPacketCount == rhs.txTotalPacketCount))
      return false;
    if (!(rxTotalByteCount == rhs.rxTotalByteCount))
      return false;
    if (!(txTotalByteCount == rhs.txTotalByteCount))
      return false;
    if (!(rxInstThroughput == rhs.rxInstThroughput))
      return false;
    if (!(txInstThroughput == rhs.txInstThroughput))
      return false;
    return true;
  }
  bool operator != (const RxTxInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RxTxInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(RxTxInfo &a, RxTxInfo &b);

std::ostream& operator<<(std::ostream& out, const RxTxInfo& obj);

typedef struct _AdplReturnConfig__isset {
  _AdplReturnConfig__isset() : flags(false) {}
  bool flags :1;
} _AdplReturnConfig__isset;

class AdplReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  AdplReturnConfig(const AdplReturnConfig&);
  AdplReturnConfig& operator=(const AdplReturnConfig&);
  AdplReturnConfig() : flags((AdplReturnFlags::type)0) {
  }

  virtual ~AdplReturnConfig() noexcept;
  AdplReturnFlags::type flags;

  _AdplReturnConfig__isset __isset;

  void __set_flags(const AdplReturnFlags::type val);

  bool operator == (const AdplReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    return true;
  }
  bool operator != (const AdplReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AdplReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(AdplReturnConfig &a, AdplReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const AdplReturnConfig& obj);

typedef struct _AdplPacket__isset {
  _AdplPacket__isset() : errorCode(false), sessionIndex(false), protocolIndex(false), version(false), binaryPayload(false), receiveTimeData(false), receiveTimeString(false), modemTimeData(false), modemTimeDataString(false), diagBinaryPayload(false) {}
  bool errorCode :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool version :1;
  bool binaryPayload :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
  bool modemTimeData :1;
  bool modemTimeDataString :1;
  bool diagBinaryPayload :1;
} _AdplPacket__isset;

class AdplPacket : public virtual ::apache::thrift::TBase {
 public:

  AdplPacket(const AdplPacket&);
  AdplPacket& operator=(const AdplPacket&);
  AdplPacket() : errorCode((ErrorCode::type)0), sessionIndex(0), protocolIndex(0), version(0), binaryPayload(), receiveTimeData(0), receiveTimeString(), modemTimeData(0), modemTimeDataString(), diagBinaryPayload() {
  }

  virtual ~AdplPacket() noexcept;
  ErrorCode::type errorCode;
  int64_t sessionIndex;
  int64_t protocolIndex;
  int8_t version;
  std::string binaryPayload;
  int64_t receiveTimeData;
  std::string receiveTimeString;
  int64_t modemTimeData;
  std::string modemTimeDataString;
  std::string diagBinaryPayload;

  _AdplPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_version(const int8_t val);

  void __set_binaryPayload(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  void __set_modemTimeData(const int64_t val);

  void __set_modemTimeDataString(const std::string& val);

  void __set_diagBinaryPayload(const std::string& val);

  bool operator == (const AdplPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.version != rhs.__isset.version)
      return false;
    else if (__isset.version && !(version == rhs.version))
      return false;
    if (__isset.binaryPayload != rhs.__isset.binaryPayload)
      return false;
    else if (__isset.binaryPayload && !(binaryPayload == rhs.binaryPayload))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    if (__isset.modemTimeData != rhs.__isset.modemTimeData)
      return false;
    else if (__isset.modemTimeData && !(modemTimeData == rhs.modemTimeData))
      return false;
    if (__isset.modemTimeDataString != rhs.__isset.modemTimeDataString)
      return false;
    else if (__isset.modemTimeDataString && !(modemTimeDataString == rhs.modemTimeDataString))
      return false;
    if (__isset.diagBinaryPayload != rhs.__isset.diagBinaryPayload)
      return false;
    else if (__isset.diagBinaryPayload && !(diagBinaryPayload == rhs.diagBinaryPayload))
      return false;
    return true;
  }
  bool operator != (const AdplPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const AdplPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(AdplPacket &a, AdplPacket &b);

std::ostream& operator<<(std::ostream& out, const AdplPacket& obj);

typedef struct _BuildInfo__isset {
  _BuildInfo__isset() : msmRevision(false), mobileModelId(false), mobileSoftwareRevision(false), mobileModelName(false) {}
  bool msmRevision :1;
  bool mobileModelId :1;
  bool mobileSoftwareRevision :1;
  bool mobileModelName :1;
} _BuildInfo__isset;

class BuildInfo : public virtual ::apache::thrift::TBase {
 public:

  BuildInfo(const BuildInfo&);
  BuildInfo& operator=(const BuildInfo&);
  BuildInfo() : msmRevision(), mobileModelId(), mobileSoftwareRevision(), mobileModelName() {
  }

  virtual ~BuildInfo() noexcept;
  std::string msmRevision;
  std::string mobileModelId;
  std::string mobileSoftwareRevision;
  std::string mobileModelName;

  _BuildInfo__isset __isset;

  void __set_msmRevision(const std::string& val);

  void __set_mobileModelId(const std::string& val);

  void __set_mobileSoftwareRevision(const std::string& val);

  void __set_mobileModelName(const std::string& val);

  bool operator == (const BuildInfo & rhs) const
  {
    if (__isset.msmRevision != rhs.__isset.msmRevision)
      return false;
    else if (__isset.msmRevision && !(msmRevision == rhs.msmRevision))
      return false;
    if (__isset.mobileModelId != rhs.__isset.mobileModelId)
      return false;
    else if (__isset.mobileModelId && !(mobileModelId == rhs.mobileModelId))
      return false;
    if (__isset.mobileSoftwareRevision != rhs.__isset.mobileSoftwareRevision)
      return false;
    else if (__isset.mobileSoftwareRevision && !(mobileSoftwareRevision == rhs.mobileSoftwareRevision))
      return false;
    if (__isset.mobileModelName != rhs.__isset.mobileModelName)
      return false;
    else if (__isset.mobileModelName && !(mobileModelName == rhs.mobileModelName))
      return false;
    return true;
  }
  bool operator != (const BuildInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BuildInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(BuildInfo &a, BuildInfo &b);

std::ostream& operator<<(std::ostream& out, const BuildInfo& obj);

typedef struct _ImageInfo__isset {
  _ImageInfo__isset() : index(false), imageVersion(false), variant(false), oemVersion(false) {}
  bool index :1;
  bool imageVersion :1;
  bool variant :1;
  bool oemVersion :1;
} _ImageInfo__isset;

class ImageInfo : public virtual ::apache::thrift::TBase {
 public:

  ImageInfo(const ImageInfo&);
  ImageInfo& operator=(const ImageInfo&);
  ImageInfo() : index(0), imageVersion(), variant(), oemVersion() {
  }

  virtual ~ImageInfo() noexcept;
  int16_t index;
  std::string imageVersion;
  std::string variant;
  std::string oemVersion;

  _ImageInfo__isset __isset;

  void __set_index(const int16_t val);

  void __set_imageVersion(const std::string& val);

  void __set_variant(const std::string& val);

  void __set_oemVersion(const std::string& val);

  bool operator == (const ImageInfo & rhs) const
  {
    if (!(index == rhs.index))
      return false;
    if (!(imageVersion == rhs.imageVersion))
      return false;
    if (!(variant == rhs.variant))
      return false;
    if (!(oemVersion == rhs.oemVersion))
      return false;
    return true;
  }
  bool operator != (const ImageInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ImageInfo &a, ImageInfo &b);

std::ostream& operator<<(std::ostream& out, const ImageInfo& obj);

typedef struct _GpsPacket__isset {
  _GpsPacket__isset() : errorCode(false), latitude(false), longitude(false), altitude(false), speed(false), time(false), date(false) {}
  bool errorCode :1;
  bool latitude :1;
  bool longitude :1;
  bool altitude :1;
  bool speed :1;
  bool time :1;
  bool date :1;
} _GpsPacket__isset;

class GpsPacket : public virtual ::apache::thrift::TBase {
 public:

  GpsPacket(const GpsPacket&);
  GpsPacket& operator=(const GpsPacket&);
  GpsPacket() : errorCode((ErrorCode::type)0), latitude(), longitude(), altitude(), speed(), time(), date() {
  }

  virtual ~GpsPacket() noexcept;
  ErrorCode::type errorCode;
  std::string latitude;
  std::string longitude;
  std::string altitude;
  std::string speed;
  std::string time;
  std::string date;

  _GpsPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_latitude(const std::string& val);

  void __set_longitude(const std::string& val);

  void __set_altitude(const std::string& val);

  void __set_speed(const std::string& val);

  void __set_time(const std::string& val);

  void __set_date(const std::string& val);

  bool operator == (const GpsPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.latitude != rhs.__isset.latitude)
      return false;
    else if (__isset.latitude && !(latitude == rhs.latitude))
      return false;
    if (__isset.longitude != rhs.__isset.longitude)
      return false;
    else if (__isset.longitude && !(longitude == rhs.longitude))
      return false;
    if (__isset.altitude != rhs.__isset.altitude)
      return false;
    else if (__isset.altitude && !(altitude == rhs.altitude))
      return false;
    if (__isset.speed != rhs.__isset.speed)
      return false;
    else if (__isset.speed && !(speed == rhs.speed))
      return false;
    if (__isset.time != rhs.__isset.time)
      return false;
    else if (__isset.time && !(time == rhs.time))
      return false;
    if (__isset.date != rhs.__isset.date)
      return false;
    else if (__isset.date && !(date == rhs.date))
      return false;
    return true;
  }
  bool operator != (const GpsPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GpsPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(GpsPacket &a, GpsPacket &b);

std::ostream& operator<<(std::ostream& out, const GpsPacket& obj);

typedef struct _NvItem__isset {
  _NvItem__isset() : id(false), name(false), description(false), category(false) {}
  bool id :1;
  bool name :1;
  bool description :1;
  bool category :1;
} _NvItem__isset;

class NvItem : public virtual ::apache::thrift::TBase {
 public:

  NvItem(const NvItem&);
  NvItem& operator=(const NvItem&);
  NvItem() : id(0), name(), description(), category() {
  }

  virtual ~NvItem() noexcept;
  int64_t id;
  std::string name;
  std::string description;
  std::string category;

  _NvItem__isset __isset;

  void __set_id(const int64_t val);

  void __set_name(const std::string& val);

  void __set_description(const std::string& val);

  void __set_category(const std::string& val);

  bool operator == (const NvItem & rhs) const
  {
    if (__isset.id != rhs.__isset.id)
      return false;
    else if (__isset.id && !(id == rhs.id))
      return false;
    if (__isset.name != rhs.__isset.name)
      return false;
    else if (__isset.name && !(name == rhs.name))
      return false;
    if (__isset.description != rhs.__isset.description)
      return false;
    else if (__isset.description && !(description == rhs.description))
      return false;
    if (__isset.category != rhs.__isset.category)
      return false;
    else if (__isset.category && !(category == rhs.category))
      return false;
    return true;
  }
  bool operator != (const NvItem &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NvItem & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(NvItem &a, NvItem &b);

std::ostream& operator<<(std::ostream& out, const NvItem& obj);

typedef struct _MbnNvItemDiffDetails__isset {
  _MbnNvItemDiffDetails__isset() : result(false), itemDescriptor(false), index(false), mbnPayload(false), phonePayload(false) {}
  bool result :1;
  bool itemDescriptor :1;
  bool index :1;
  bool mbnPayload :1;
  bool phonePayload :1;
} _MbnNvItemDiffDetails__isset;

class MbnNvItemDiffDetails : public virtual ::apache::thrift::TBase {
 public:

  MbnNvItemDiffDetails(const MbnNvItemDiffDetails&);
  MbnNvItemDiffDetails& operator=(const MbnNvItemDiffDetails&);
  MbnNvItemDiffDetails() : result((MbnNvItemDiffResult::type)0), index(0), mbnPayload(), phonePayload() {
  }

  virtual ~MbnNvItemDiffDetails() noexcept;
  MbnNvItemDiffResult::type result;
  NvItem itemDescriptor;
  int8_t index;
  std::string mbnPayload;
  std::string phonePayload;

  _MbnNvItemDiffDetails__isset __isset;

  void __set_result(const MbnNvItemDiffResult::type val);

  void __set_itemDescriptor(const NvItem& val);

  void __set_index(const int8_t val);

  void __set_mbnPayload(const std::string& val);

  void __set_phonePayload(const std::string& val);

  bool operator == (const MbnNvItemDiffDetails & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (!(itemDescriptor == rhs.itemDescriptor))
      return false;
    if (!(index == rhs.index))
      return false;
    if (!(mbnPayload == rhs.mbnPayload))
      return false;
    if (!(phonePayload == rhs.phonePayload))
      return false;
    return true;
  }
  bool operator != (const MbnNvItemDiffDetails &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MbnNvItemDiffDetails & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(MbnNvItemDiffDetails &a, MbnNvItemDiffDetails &b);

std::ostream& operator<<(std::ostream& out, const MbnNvItemDiffDetails& obj);

typedef struct _MbnNvDiffDetailsPerSub__isset {
  _MbnNvDiffDetailsPerSub__isset() : subscriptionId(false), mbnNvItemDiffDetails(false) {}
  bool subscriptionId :1;
  bool mbnNvItemDiffDetails :1;
} _MbnNvDiffDetailsPerSub__isset;

class MbnNvDiffDetailsPerSub : public virtual ::apache::thrift::TBase {
 public:

  MbnNvDiffDetailsPerSub(const MbnNvDiffDetailsPerSub&);
  MbnNvDiffDetailsPerSub& operator=(const MbnNvDiffDetailsPerSub&);
  MbnNvDiffDetailsPerSub() : subscriptionId(0) {
  }

  virtual ~MbnNvDiffDetailsPerSub() noexcept;
  int32_t subscriptionId;
  std::vector<MbnNvItemDiffDetails>  mbnNvItemDiffDetails;

  _MbnNvDiffDetailsPerSub__isset __isset;

  void __set_subscriptionId(const int32_t val);

  void __set_mbnNvItemDiffDetails(const std::vector<MbnNvItemDiffDetails> & val);

  bool operator == (const MbnNvDiffDetailsPerSub & rhs) const
  {
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(mbnNvItemDiffDetails == rhs.mbnNvItemDiffDetails))
      return false;
    return true;
  }
  bool operator != (const MbnNvDiffDetailsPerSub &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MbnNvDiffDetailsPerSub & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(MbnNvDiffDetailsPerSub &a, MbnNvDiffDetailsPerSub &b);

std::ostream& operator<<(std::ostream& out, const MbnNvDiffDetailsPerSub& obj);

typedef struct _MbnDiffGroupHeader__isset {
  _MbnDiffGroupHeader__isset() : groupName(false), path(false) {}
  bool groupName :1;
  bool path :1;
} _MbnDiffGroupHeader__isset;

class MbnDiffGroupHeader : public virtual ::apache::thrift::TBase {
 public:

  MbnDiffGroupHeader(const MbnDiffGroupHeader&);
  MbnDiffGroupHeader& operator=(const MbnDiffGroupHeader&);
  MbnDiffGroupHeader() : groupName() {
  }

  virtual ~MbnDiffGroupHeader() noexcept;
  std::string groupName;
  std::vector<std::string>  path;

  _MbnDiffGroupHeader__isset __isset;

  void __set_groupName(const std::string& val);

  void __set_path(const std::vector<std::string> & val);

  bool operator == (const MbnDiffGroupHeader & rhs) const
  {
    if (!(groupName == rhs.groupName))
      return false;
    if (!(path == rhs.path))
      return false;
    return true;
  }
  bool operator != (const MbnDiffGroupHeader &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MbnDiffGroupHeader & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(MbnDiffGroupHeader &a, MbnDiffGroupHeader &b);

std::ostream& operator<<(std::ostream& out, const MbnDiffGroupHeader& obj);

typedef struct _MbnDiffResult__isset {
  _MbnDiffResult__isset() : mbnGroupHeader(false), phoneGroupHeader(false), mbnNvPerSub(false) {}
  bool mbnGroupHeader :1;
  bool phoneGroupHeader :1;
  bool mbnNvPerSub :1;
} _MbnDiffResult__isset;

class MbnDiffResult : public virtual ::apache::thrift::TBase {
 public:

  MbnDiffResult(const MbnDiffResult&);
  MbnDiffResult& operator=(const MbnDiffResult&);
  MbnDiffResult() {
  }

  virtual ~MbnDiffResult() noexcept;
  MbnDiffGroupHeader mbnGroupHeader;
  MbnDiffGroupHeader phoneGroupHeader;
  std::vector<MbnNvDiffDetailsPerSub>  mbnNvPerSub;

  _MbnDiffResult__isset __isset;

  void __set_mbnGroupHeader(const MbnDiffGroupHeader& val);

  void __set_phoneGroupHeader(const MbnDiffGroupHeader& val);

  void __set_mbnNvPerSub(const std::vector<MbnNvDiffDetailsPerSub> & val);

  bool operator == (const MbnDiffResult & rhs) const
  {
    if (!(mbnGroupHeader == rhs.mbnGroupHeader))
      return false;
    if (!(phoneGroupHeader == rhs.phoneGroupHeader))
      return false;
    if (!(mbnNvPerSub == rhs.mbnNvPerSub))
      return false;
    return true;
  }
  bool operator != (const MbnDiffResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MbnDiffResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(MbnDiffResult &a, MbnDiffResult &b);

std::ostream& operator<<(std::ostream& out, const MbnDiffResult& obj);

typedef struct _NmeaReturnConfig__isset {
  _NmeaReturnConfig__isset() : flags(false) {}
  bool flags :1;
} _NmeaReturnConfig__isset;

class NmeaReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  NmeaReturnConfig(const NmeaReturnConfig&);
  NmeaReturnConfig& operator=(const NmeaReturnConfig&);
  NmeaReturnConfig() : flags((NmeaReturnFlags::type)0) {
  }

  virtual ~NmeaReturnConfig() noexcept;
  NmeaReturnFlags::type flags;

  _NmeaReturnConfig__isset __isset;

  void __set_flags(const NmeaReturnFlags::type val);

  bool operator == (const NmeaReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    return true;
  }
  bool operator != (const NmeaReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NmeaReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(NmeaReturnConfig &a, NmeaReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const NmeaReturnConfig& obj);

typedef struct _NmeaPacket__isset {
  _NmeaPacket__isset() : errorCode(false), sessionIndex(false), protocolIndex(false), packetText(false), receiveTimeData(false), receiveTimeString(false), packetId(false), binaryPayload(false) {}
  bool errorCode :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool packetText :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
  bool packetId :1;
  bool binaryPayload :1;
} _NmeaPacket__isset;

class NmeaPacket : public virtual ::apache::thrift::TBase {
 public:

  NmeaPacket(const NmeaPacket&);
  NmeaPacket& operator=(const NmeaPacket&);
  NmeaPacket() : errorCode((ErrorCode::type)0), sessionIndex(0), protocolIndex(0), packetText(), receiveTimeData(0), receiveTimeString(), packetId(), binaryPayload() {
  }

  virtual ~NmeaPacket() noexcept;
  ErrorCode::type errorCode;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string packetText;
  int64_t receiveTimeData;
  std::string receiveTimeString;
  std::string packetId;
  std::string binaryPayload;

  _NmeaPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_packetText(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  void __set_packetId(const std::string& val);

  void __set_binaryPayload(const std::string& val);

  bool operator == (const NmeaPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.packetText != rhs.__isset.packetText)
      return false;
    else if (__isset.packetText && !(packetText == rhs.packetText))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    if (__isset.packetId != rhs.__isset.packetId)
      return false;
    else if (__isset.packetId && !(packetId == rhs.packetId))
      return false;
    if (__isset.binaryPayload != rhs.__isset.binaryPayload)
      return false;
    else if (__isset.binaryPayload && !(binaryPayload == rhs.binaryPayload))
      return false;
    return true;
  }
  bool operator != (const NmeaPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NmeaPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(NmeaPacket &a, NmeaPacket &b);

std::ostream& operator<<(std::ostream& out, const NmeaPacket& obj);

typedef struct _NmeaPacketFilter__isset {
  _NmeaPacketFilter__isset() : nameMask(false) {}
  bool nameMask :1;
} _NmeaPacketFilter__isset;

class NmeaPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  NmeaPacketFilter(const NmeaPacketFilter&);
  NmeaPacketFilter& operator=(const NmeaPacketFilter&);
  NmeaPacketFilter() {
  }

  virtual ~NmeaPacketFilter() noexcept;
  std::vector<std::string>  nameMask;

  _NmeaPacketFilter__isset __isset;

  void __set_nameMask(const std::vector<std::string> & val);

  bool operator == (const NmeaPacketFilter & rhs) const
  {
    if (__isset.nameMask != rhs.__isset.nameMask)
      return false;
    else if (__isset.nameMask && !(nameMask == rhs.nameMask))
      return false;
    return true;
  }
  bool operator != (const NmeaPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NmeaPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(NmeaPacketFilter &a, NmeaPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const NmeaPacketFilter& obj);

typedef struct _QmiUnpackReturn__isset {
  _QmiUnpackReturn__isset() : msgName(false), tlvXml(false) {}
  bool msgName :1;
  bool tlvXml :1;
} _QmiUnpackReturn__isset;

class QmiUnpackReturn : public virtual ::apache::thrift::TBase {
 public:

  QmiUnpackReturn(const QmiUnpackReturn&);
  QmiUnpackReturn& operator=(const QmiUnpackReturn&);
  QmiUnpackReturn() : msgName(), tlvXml() {
  }

  virtual ~QmiUnpackReturn() noexcept;
  std::string msgName;
  std::string tlvXml;

  _QmiUnpackReturn__isset __isset;

  void __set_msgName(const std::string& val);

  void __set_tlvXml(const std::string& val);

  bool operator == (const QmiUnpackReturn & rhs) const
  {
    if (__isset.msgName != rhs.__isset.msgName)
      return false;
    else if (__isset.msgName && !(msgName == rhs.msgName))
      return false;
    if (__isset.tlvXml != rhs.__isset.tlvXml)
      return false;
    else if (__isset.tlvXml && !(tlvXml == rhs.tlvXml))
      return false;
    return true;
  }
  bool operator != (const QmiUnpackReturn &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmiUnpackReturn & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmiUnpackReturn &a, QmiUnpackReturn &b);

std::ostream& operator<<(std::ostream& out, const QmiUnpackReturn& obj);

typedef struct _QdssPacketFilter__isset {
  _QdssPacketFilter__isset() : atIds(false) {}
  bool atIds :1;
} _QdssPacketFilter__isset;

class QdssPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  QdssPacketFilter(const QdssPacketFilter&);
  QdssPacketFilter& operator=(const QdssPacketFilter&);
  QdssPacketFilter() {
  }

  virtual ~QdssPacketFilter() noexcept;
  std::vector<int32_t>  atIds;

  _QdssPacketFilter__isset __isset;

  void __set_atIds(const std::vector<int32_t> & val);

  bool operator == (const QdssPacketFilter & rhs) const
  {
    if (__isset.atIds != rhs.__isset.atIds)
      return false;
    else if (__isset.atIds && !(atIds == rhs.atIds))
      return false;
    return true;
  }
  bool operator != (const QdssPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QdssPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QdssPacketFilter &a, QdssPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const QdssPacketFilter& obj);

typedef struct _QdssReturnConfig__isset {
  _QdssReturnConfig__isset() : flags(false) {}
  bool flags :1;
} _QdssReturnConfig__isset;

class QdssReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  QdssReturnConfig(const QdssReturnConfig&);
  QdssReturnConfig& operator=(const QdssReturnConfig&);
  QdssReturnConfig() : flags((QdssReturnFlags::type)0) {
  }

  virtual ~QdssReturnConfig() noexcept;
  QdssReturnFlags::type flags;

  _QdssReturnConfig__isset __isset;

  void __set_flags(const QdssReturnFlags::type val);

  bool operator == (const QdssReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    return true;
  }
  bool operator != (const QdssReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QdssReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QdssReturnConfig &a, QdssReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const QdssReturnConfig& obj);

typedef struct _QdssPacket__isset {
  _QdssPacket__isset() : errorCode(false), sessionIndex(false), protocolIndex(false), receiveTimeData(false), receiveTimeString(false), atid(false), binaryPayload(false), hwTimeStampData(false), hwTimeStampString(false), channelId(false), masterId(false) {}
  bool errorCode :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
  bool atid :1;
  bool binaryPayload :1;
  bool hwTimeStampData :1;
  bool hwTimeStampString :1;
  bool channelId :1;
  bool masterId :1;
} _QdssPacket__isset;

class QdssPacket : public virtual ::apache::thrift::TBase {
 public:

  QdssPacket(const QdssPacket&);
  QdssPacket& operator=(const QdssPacket&);
  QdssPacket() : errorCode((ErrorCode::type)0), sessionIndex(0), protocolIndex(0), receiveTimeData(0), receiveTimeString(), atid(0), binaryPayload(), hwTimeStampData(0), hwTimeStampString(), channelId(0), masterId(0) {
  }

  virtual ~QdssPacket() noexcept;
  ErrorCode::type errorCode;
  int64_t sessionIndex;
  int64_t protocolIndex;
  int64_t receiveTimeData;
  std::string receiveTimeString;
  int8_t atid;
  std::string binaryPayload;
  int64_t hwTimeStampData;
  std::string hwTimeStampString;
  int16_t channelId;
  int16_t masterId;

  _QdssPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  void __set_atid(const int8_t val);

  void __set_binaryPayload(const std::string& val);

  void __set_hwTimeStampData(const int64_t val);

  void __set_hwTimeStampString(const std::string& val);

  void __set_channelId(const int16_t val);

  void __set_masterId(const int16_t val);

  bool operator == (const QdssPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    if (__isset.atid != rhs.__isset.atid)
      return false;
    else if (__isset.atid && !(atid == rhs.atid))
      return false;
    if (__isset.binaryPayload != rhs.__isset.binaryPayload)
      return false;
    else if (__isset.binaryPayload && !(binaryPayload == rhs.binaryPayload))
      return false;
    if (__isset.hwTimeStampData != rhs.__isset.hwTimeStampData)
      return false;
    else if (__isset.hwTimeStampData && !(hwTimeStampData == rhs.hwTimeStampData))
      return false;
    if (__isset.hwTimeStampString != rhs.__isset.hwTimeStampString)
      return false;
    else if (__isset.hwTimeStampString && !(hwTimeStampString == rhs.hwTimeStampString))
      return false;
    if (__isset.channelId != rhs.__isset.channelId)
      return false;
    else if (__isset.channelId && !(channelId == rhs.channelId))
      return false;
    if (__isset.masterId != rhs.__isset.masterId)
      return false;
    else if (__isset.masterId && !(masterId == rhs.masterId))
      return false;
    return true;
  }
  bool operator != (const QdssPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QdssPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QdssPacket &a, QdssPacket &b);

std::ostream& operator<<(std::ostream& out, const QdssPacket& obj);

typedef struct _DunPacketFilter__isset {
  _DunPacketFilter__isset() : commandMask(false) {}
  bool commandMask :1;
} _DunPacketFilter__isset;

class DunPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  DunPacketFilter(const DunPacketFilter&);
  DunPacketFilter& operator=(const DunPacketFilter&);
  DunPacketFilter() {
  }

  virtual ~DunPacketFilter() noexcept;
  std::vector<std::string>  commandMask;

  _DunPacketFilter__isset __isset;

  void __set_commandMask(const std::vector<std::string> & val);

  bool operator == (const DunPacketFilter & rhs) const
  {
    if (__isset.commandMask != rhs.__isset.commandMask)
      return false;
    else if (__isset.commandMask && !(commandMask == rhs.commandMask))
      return false;
    return true;
  }
  bool operator != (const DunPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DunPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DunPacketFilter &a, DunPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const DunPacketFilter& obj);

typedef struct _DunReturnConfig__isset {
  _DunReturnConfig__isset() : flags(false) {}
  bool flags :1;
} _DunReturnConfig__isset;

class DunReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  DunReturnConfig(const DunReturnConfig&);
  DunReturnConfig& operator=(const DunReturnConfig&);
  DunReturnConfig() : flags((DunReturnFlags::type)0) {
  }

  virtual ~DunReturnConfig() noexcept;
  DunReturnFlags::type flags;

  _DunReturnConfig__isset __isset;

  void __set_flags(const DunReturnFlags::type val);

  bool operator == (const DunReturnConfig & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    return true;
  }
  bool operator != (const DunReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DunReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DunReturnConfig &a, DunReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const DunReturnConfig& obj);

typedef struct _DunPacket__isset {
  _DunPacket__isset() : errorCode(false), sessionIndex(false), protocolIndex(false), packetId(false), packetText(false), receiveTimeData(false), receiveTimeString(false) {}
  bool errorCode :1;
  bool sessionIndex :1;
  bool protocolIndex :1;
  bool packetId :1;
  bool packetText :1;
  bool receiveTimeData :1;
  bool receiveTimeString :1;
} _DunPacket__isset;

class DunPacket : public virtual ::apache::thrift::TBase {
 public:

  DunPacket(const DunPacket&);
  DunPacket& operator=(const DunPacket&);
  DunPacket() : errorCode((ErrorCode::type)0), sessionIndex(0), protocolIndex(0), packetId(), packetText(), receiveTimeData(0), receiveTimeString() {
  }

  virtual ~DunPacket() noexcept;
  ErrorCode::type errorCode;
  int64_t sessionIndex;
  int64_t protocolIndex;
  std::string packetId;
  std::string packetText;
  int64_t receiveTimeData;
  std::string receiveTimeString;

  _DunPacket__isset __isset;

  void __set_errorCode(const ErrorCode::type val);

  void __set_sessionIndex(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  void __set_packetId(const std::string& val);

  void __set_packetText(const std::string& val);

  void __set_receiveTimeData(const int64_t val);

  void __set_receiveTimeString(const std::string& val);

  bool operator == (const DunPacket & rhs) const
  {
    if (__isset.errorCode != rhs.__isset.errorCode)
      return false;
    else if (__isset.errorCode && !(errorCode == rhs.errorCode))
      return false;
    if (__isset.sessionIndex != rhs.__isset.sessionIndex)
      return false;
    else if (__isset.sessionIndex && !(sessionIndex == rhs.sessionIndex))
      return false;
    if (__isset.protocolIndex != rhs.__isset.protocolIndex)
      return false;
    else if (__isset.protocolIndex && !(protocolIndex == rhs.protocolIndex))
      return false;
    if (__isset.packetId != rhs.__isset.packetId)
      return false;
    else if (__isset.packetId && !(packetId == rhs.packetId))
      return false;
    if (__isset.packetText != rhs.__isset.packetText)
      return false;
    else if (__isset.packetText && !(packetText == rhs.packetText))
      return false;
    if (__isset.receiveTimeData != rhs.__isset.receiveTimeData)
      return false;
    else if (__isset.receiveTimeData && !(receiveTimeData == rhs.receiveTimeData))
      return false;
    if (__isset.receiveTimeString != rhs.__isset.receiveTimeString)
      return false;
    else if (__isset.receiveTimeString && !(receiveTimeString == rhs.receiveTimeString))
      return false;
    return true;
  }
  bool operator != (const DunPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DunPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DunPacket &a, DunPacket &b);

std::ostream& operator<<(std::ostream& out, const DunPacket& obj);

typedef struct _DiagPacketIdList__isset {
  _DiagPacketIdList__isset() : idOrName(false) {}
  bool idOrName :1;
} _DiagPacketIdList__isset;

class DiagPacketIdList : public virtual ::apache::thrift::TBase {
 public:

  DiagPacketIdList(const DiagPacketIdList&);
  DiagPacketIdList& operator=(const DiagPacketIdList&);
  DiagPacketIdList() {
  }

  virtual ~DiagPacketIdList() noexcept;
  std::vector<std::string>  idOrName;

  _DiagPacketIdList__isset __isset;

  void __set_idOrName(const std::vector<std::string> & val);

  bool operator == (const DiagPacketIdList & rhs) const
  {
    if (!(idOrName == rhs.idOrName))
      return false;
    return true;
  }
  bool operator != (const DiagPacketIdList &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagPacketIdList & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagPacketIdList &a, DiagPacketIdList &b);

std::ostream& operator<<(std::ostream& out, const DiagPacketIdList& obj);

typedef struct _DiagPacketMap__isset {
  _DiagPacketMap__isset() : subIdTypeIdMaskMap(false) {}
  bool subIdTypeIdMaskMap :1;
} _DiagPacketMap__isset;

class DiagPacketMap : public virtual ::apache::thrift::TBase {
 public:

  DiagPacketMap(const DiagPacketMap&);
  DiagPacketMap& operator=(const DiagPacketMap&);
  DiagPacketMap() {
  }

  virtual ~DiagPacketMap() noexcept;
  std::map<int32_t, std::map<DiagPacketType::type, DiagPacketIdList> >  subIdTypeIdMaskMap;

  _DiagPacketMap__isset __isset;

  void __set_subIdTypeIdMaskMap(const std::map<int32_t, std::map<DiagPacketType::type, DiagPacketIdList> > & val);

  bool operator == (const DiagPacketMap & rhs) const
  {
    if (!(subIdTypeIdMaskMap == rhs.subIdTypeIdMaskMap))
      return false;
    return true;
  }
  bool operator != (const DiagPacketMap &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagPacketMap & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagPacketMap &a, DiagPacketMap &b);

std::ostream& operator<<(std::ostream& out, const DiagPacketMap& obj);

typedef struct _QmiConnectionOptions__isset {
  _QmiConnectionOptions__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _QmiConnectionOptions__isset;

class QmiConnectionOptions : public virtual ::apache::thrift::TBase {
 public:

  QmiConnectionOptions(const QmiConnectionOptions&);
  QmiConnectionOptions& operator=(const QmiConnectionOptions&);
  QmiConnectionOptions() : protocolHandle(0) {
  }

  virtual ~QmiConnectionOptions() noexcept;
  int64_t protocolHandle;

  _QmiConnectionOptions__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const QmiConnectionOptions & rhs) const
  {
    if (__isset.protocolHandle != rhs.__isset.protocolHandle)
      return false;
    else if (__isset.protocolHandle && !(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const QmiConnectionOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmiConnectionOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmiConnectionOptions &a, QmiConnectionOptions &b);

std::ostream& operator<<(std::ostream& out, const QmiConnectionOptions& obj);

typedef struct _LogOptions__isset {
  _LogOptions__isset() : level(false), format(false), layout(false), sizeRotationKB(false), savePath(false), maxDataPrintSize(false) {}
  bool level :1;
  bool format :1;
  bool layout :1;
  bool sizeRotationKB :1;
  bool savePath :1;
  bool maxDataPrintSize :1;
} _LogOptions__isset;

class LogOptions : public virtual ::apache::thrift::TBase {
 public:

  LogOptions(const LogOptions&);
  LogOptions& operator=(const LogOptions&);
  LogOptions() : level((LogLevel::type)0), format((LogFormat::type)0), sizeRotationKB(0), savePath(), maxDataPrintSize(0) {
  }

  virtual ~LogOptions() noexcept;
  LogLevel::type level;
  LogFormat::type format;
  std::vector<LogLayout::type>  layout;
  int32_t sizeRotationKB;
  std::string savePath;
  int32_t maxDataPrintSize;

  _LogOptions__isset __isset;

  void __set_level(const LogLevel::type val);

  void __set_format(const LogFormat::type val);

  void __set_layout(const std::vector<LogLayout::type> & val);

  void __set_sizeRotationKB(const int32_t val);

  void __set_savePath(const std::string& val);

  void __set_maxDataPrintSize(const int32_t val);

  bool operator == (const LogOptions & rhs) const
  {
    if (__isset.level != rhs.__isset.level)
      return false;
    else if (__isset.level && !(level == rhs.level))
      return false;
    if (__isset.format != rhs.__isset.format)
      return false;
    else if (__isset.format && !(format == rhs.format))
      return false;
    if (__isset.layout != rhs.__isset.layout)
      return false;
    else if (__isset.layout && !(layout == rhs.layout))
      return false;
    if (__isset.sizeRotationKB != rhs.__isset.sizeRotationKB)
      return false;
    else if (__isset.sizeRotationKB && !(sizeRotationKB == rhs.sizeRotationKB))
      return false;
    if (__isset.savePath != rhs.__isset.savePath)
      return false;
    else if (__isset.savePath && !(savePath == rhs.savePath))
      return false;
    if (__isset.maxDataPrintSize != rhs.__isset.maxDataPrintSize)
      return false;
    else if (__isset.maxDataPrintSize && !(maxDataPrintSize == rhs.maxDataPrintSize))
      return false;
    return true;
  }
  bool operator != (const LogOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(LogOptions &a, LogOptions &b);

std::ostream& operator<<(std::ostream& out, const LogOptions& obj);

typedef struct _PhoneProperty__isset {
  _PhoneProperty__isset() : esn(false), phoneModel(false), nvMajor(false), nvMinor(false), swVersion(false), clientName(false) {}
  bool esn :1;
  bool phoneModel :1;
  bool nvMajor :1;
  bool nvMinor :1;
  bool swVersion :1;
  bool clientName :1;
} _PhoneProperty__isset;

class PhoneProperty : public virtual ::apache::thrift::TBase {
 public:

  PhoneProperty(const PhoneProperty&);
  PhoneProperty& operator=(const PhoneProperty&);
  PhoneProperty() : esn(0), phoneModel(0), nvMajor(0), nvMinor(0), swVersion(), clientName() {
  }

  virtual ~PhoneProperty() noexcept;
  int32_t esn;
  int32_t phoneModel;
  int32_t nvMajor;
  int32_t nvMinor;
  std::string swVersion;
  std::string clientName;

  _PhoneProperty__isset __isset;

  void __set_esn(const int32_t val);

  void __set_phoneModel(const int32_t val);

  void __set_nvMajor(const int32_t val);

  void __set_nvMinor(const int32_t val);

  void __set_swVersion(const std::string& val);

  void __set_clientName(const std::string& val);

  bool operator == (const PhoneProperty & rhs) const
  {
    if (!(esn == rhs.esn))
      return false;
    if (!(phoneModel == rhs.phoneModel))
      return false;
    if (!(nvMajor == rhs.nvMajor))
      return false;
    if (!(nvMinor == rhs.nvMinor))
      return false;
    if (!(swVersion == rhs.swVersion))
      return false;
    if (!(clientName == rhs.clientName))
      return false;
    return true;
  }
  bool operator != (const PhoneProperty &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PhoneProperty & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(PhoneProperty &a, PhoneProperty &b);

std::ostream& operator<<(std::ostream& out, const PhoneProperty& obj);

typedef struct _QcnHeader__isset {
  _QcnHeader__isset() : configurationName(false), fileMajor(false), fileMinor(false), fileRevision(false), phoneProperty(false) {}
  bool configurationName :1;
  bool fileMajor :1;
  bool fileMinor :1;
  bool fileRevision :1;
  bool phoneProperty :1;
} _QcnHeader__isset;

class QcnHeader : public virtual ::apache::thrift::TBase {
 public:

  QcnHeader(const QcnHeader&);
  QcnHeader& operator=(const QcnHeader&);
  QcnHeader() : configurationName(), fileMajor(0), fileMinor(0), fileRevision(0) {
  }

  virtual ~QcnHeader() noexcept;
  std::string configurationName;
  int32_t fileMajor;
  int32_t fileMinor;
  int32_t fileRevision;
  PhoneProperty phoneProperty;

  _QcnHeader__isset __isset;

  void __set_configurationName(const std::string& val);

  void __set_fileMajor(const int32_t val);

  void __set_fileMinor(const int32_t val);

  void __set_fileRevision(const int32_t val);

  void __set_phoneProperty(const PhoneProperty& val);

  bool operator == (const QcnHeader & rhs) const
  {
    if (!(configurationName == rhs.configurationName))
      return false;
    if (!(fileMajor == rhs.fileMajor))
      return false;
    if (!(fileMinor == rhs.fileMinor))
      return false;
    if (!(fileRevision == rhs.fileRevision))
      return false;
    if (!(phoneProperty == rhs.phoneProperty))
      return false;
    return true;
  }
  bool operator != (const QcnHeader &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnHeader & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnHeader &a, QcnHeader &b);

std::ostream& operator<<(std::ostream& out, const QcnHeader& obj);

typedef struct _QcnItemDiffDetails__isset {
  _QcnItemDiffDetails__isset() : result(false), nvId(false), subscriptionId(false), index(false), efsFilePath(false), payload1(false), payload2(false) {}
  bool result :1;
  bool nvId :1;
  bool subscriptionId :1;
  bool index :1;
  bool efsFilePath :1;
  bool payload1 :1;
  bool payload2 :1;
} _QcnItemDiffDetails__isset;

class QcnItemDiffDetails : public virtual ::apache::thrift::TBase {
 public:

  QcnItemDiffDetails(const QcnItemDiffDetails&);
  QcnItemDiffDetails& operator=(const QcnItemDiffDetails&);
  QcnItemDiffDetails() : result((QcnItemDiffResult::type)0), nvId(0), subscriptionId(0), index(0), efsFilePath(), payload1(), payload2() {
  }

  virtual ~QcnItemDiffDetails() noexcept;
  QcnItemDiffResult::type result;
  int32_t nvId;
  int32_t subscriptionId;
  int32_t index;
  std::string efsFilePath;
  std::string payload1;
  std::string payload2;

  _QcnItemDiffDetails__isset __isset;

  void __set_result(const QcnItemDiffResult::type val);

  void __set_nvId(const int32_t val);

  void __set_subscriptionId(const int32_t val);

  void __set_index(const int32_t val);

  void __set_efsFilePath(const std::string& val);

  void __set_payload1(const std::string& val);

  void __set_payload2(const std::string& val);

  bool operator == (const QcnItemDiffDetails & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (!(nvId == rhs.nvId))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(index == rhs.index))
      return false;
    if (!(efsFilePath == rhs.efsFilePath))
      return false;
    if (!(payload1 == rhs.payload1))
      return false;
    if (!(payload2 == rhs.payload2))
      return false;
    return true;
  }
  bool operator != (const QcnItemDiffDetails &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnItemDiffDetails & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnItemDiffDetails &a, QcnItemDiffDetails &b);

std::ostream& operator<<(std::ostream& out, const QcnItemDiffDetails& obj);

typedef struct _QcnFeatureMaskDiffDetails__isset {
  _QcnFeatureMaskDiffDetails__isset() : result(false), payload1(false), payload2(false) {}
  bool result :1;
  bool payload1 :1;
  bool payload2 :1;
} _QcnFeatureMaskDiffDetails__isset;

class QcnFeatureMaskDiffDetails : public virtual ::apache::thrift::TBase {
 public:

  QcnFeatureMaskDiffDetails(const QcnFeatureMaskDiffDetails&);
  QcnFeatureMaskDiffDetails& operator=(const QcnFeatureMaskDiffDetails&);
  QcnFeatureMaskDiffDetails() : result((QcnItemDiffResult::type)0), payload1(), payload2() {
  }

  virtual ~QcnFeatureMaskDiffDetails() noexcept;
  QcnItemDiffResult::type result;
  std::string payload1;
  std::string payload2;

  _QcnFeatureMaskDiffDetails__isset __isset;

  void __set_result(const QcnItemDiffResult::type val);

  void __set_payload1(const std::string& val);

  void __set_payload2(const std::string& val);

  bool operator == (const QcnFeatureMaskDiffDetails & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (!(payload1 == rhs.payload1))
      return false;
    if (!(payload2 == rhs.payload2))
      return false;
    return true;
  }
  bool operator != (const QcnFeatureMaskDiffDetails &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnFeatureMaskDiffDetails & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnFeatureMaskDiffDetails &a, QcnFeatureMaskDiffDetails &b);

std::ostream& operator<<(std::ostream& out, const QcnFeatureMaskDiffDetails& obj);

typedef struct _QcnPrlDiffDetails__isset {
  _QcnPrlDiffDetails__isset() : result(false), subscriptionId(false), nam(false), payload1(false), payload2(false) {}
  bool result :1;
  bool subscriptionId :1;
  bool nam :1;
  bool payload1 :1;
  bool payload2 :1;
} _QcnPrlDiffDetails__isset;

class QcnPrlDiffDetails : public virtual ::apache::thrift::TBase {
 public:

  QcnPrlDiffDetails(const QcnPrlDiffDetails&);
  QcnPrlDiffDetails& operator=(const QcnPrlDiffDetails&);
  QcnPrlDiffDetails() : result((QcnItemDiffResult::type)0), subscriptionId(0), nam(0), payload1(), payload2() {
  }

  virtual ~QcnPrlDiffDetails() noexcept;
  QcnItemDiffResult::type result;
  int32_t subscriptionId;
  int32_t nam;
  std::string payload1;
  std::string payload2;

  _QcnPrlDiffDetails__isset __isset;

  void __set_result(const QcnItemDiffResult::type val);

  void __set_subscriptionId(const int32_t val);

  void __set_nam(const int32_t val);

  void __set_payload1(const std::string& val);

  void __set_payload2(const std::string& val);

  bool operator == (const QcnPrlDiffDetails & rhs) const
  {
    if (!(result == rhs.result))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(nam == rhs.nam))
      return false;
    if (!(payload1 == rhs.payload1))
      return false;
    if (!(payload2 == rhs.payload2))
      return false;
    return true;
  }
  bool operator != (const QcnPrlDiffDetails &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnPrlDiffDetails & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnPrlDiffDetails &a, QcnPrlDiffDetails &b);

std::ostream& operator<<(std::ostream& out, const QcnPrlDiffDetails& obj);

typedef struct _QcnDiffResult__isset {
  _QcnDiffResult__isset() : header1(false), header2(false), featureMask(false), prls(false), items(false) {}
  bool header1 :1;
  bool header2 :1;
  bool featureMask :1;
  bool prls :1;
  bool items :1;
} _QcnDiffResult__isset;

class QcnDiffResult : public virtual ::apache::thrift::TBase {
 public:

  QcnDiffResult(const QcnDiffResult&);
  QcnDiffResult& operator=(const QcnDiffResult&);
  QcnDiffResult() {
  }

  virtual ~QcnDiffResult() noexcept;
  QcnHeader header1;
  QcnHeader header2;
  QcnFeatureMaskDiffDetails featureMask;
  std::vector<QcnPrlDiffDetails>  prls;
  std::vector<QcnItemDiffDetails>  items;

  _QcnDiffResult__isset __isset;

  void __set_header1(const QcnHeader& val);

  void __set_header2(const QcnHeader& val);

  void __set_featureMask(const QcnFeatureMaskDiffDetails& val);

  void __set_prls(const std::vector<QcnPrlDiffDetails> & val);

  void __set_items(const std::vector<QcnItemDiffDetails> & val);

  bool operator == (const QcnDiffResult & rhs) const
  {
    if (!(header1 == rhs.header1))
      return false;
    if (!(header2 == rhs.header2))
      return false;
    if (!(featureMask == rhs.featureMask))
      return false;
    if (!(prls == rhs.prls))
      return false;
    if (!(items == rhs.items))
      return false;
    return true;
  }
  bool operator != (const QcnDiffResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnDiffResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnDiffResult &a, QcnDiffResult &b);

std::ostream& operator<<(std::ostream& out, const QcnDiffResult& obj);

typedef struct _QcnPrl__isset {
  _QcnPrl__isset() : nam(false), payload(false) {}
  bool nam :1;
  bool payload :1;
} _QcnPrl__isset;

class QcnPrl : public virtual ::apache::thrift::TBase {
 public:

  QcnPrl(const QcnPrl&);
  QcnPrl& operator=(const QcnPrl&);
  QcnPrl() : nam(0), payload() {
  }

  virtual ~QcnPrl() noexcept;
  int32_t nam;
  std::string payload;

  _QcnPrl__isset __isset;

  void __set_nam(const int32_t val);

  void __set_payload(const std::string& val);

  bool operator == (const QcnPrl & rhs) const
  {
    if (!(nam == rhs.nam))
      return false;
    if (!(payload == rhs.payload))
      return false;
    return true;
  }
  bool operator != (const QcnPrl &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnPrl & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnPrl &a, QcnPrl &b);

std::ostream& operator<<(std::ostream& out, const QcnPrl& obj);

typedef struct _QcnPrlList__isset {
  _QcnPrlList__isset() : subscriptionId(false), prls(false) {}
  bool subscriptionId :1;
  bool prls :1;
} _QcnPrlList__isset;

class QcnPrlList : public virtual ::apache::thrift::TBase {
 public:

  QcnPrlList(const QcnPrlList&);
  QcnPrlList& operator=(const QcnPrlList&);
  QcnPrlList() : subscriptionId(0) {
  }

  virtual ~QcnPrlList() noexcept;
  int32_t subscriptionId;
  std::vector<QcnPrl>  prls;

  _QcnPrlList__isset __isset;

  void __set_subscriptionId(const int32_t val);

  void __set_prls(const std::vector<QcnPrl> & val);

  bool operator == (const QcnPrlList & rhs) const
  {
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(prls == rhs.prls))
      return false;
    return true;
  }
  bool operator != (const QcnPrlList &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnPrlList & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnPrlList &a, QcnPrlList &b);

std::ostream& operator<<(std::ostream& out, const QcnPrlList& obj);

typedef struct _QcnNumberedNv__isset {
  _QcnNumberedNv__isset() : nvId(false), index(false), payload(false) {}
  bool nvId :1;
  bool index :1;
  bool payload :1;
} _QcnNumberedNv__isset;

class QcnNumberedNv : public virtual ::apache::thrift::TBase {
 public:

  QcnNumberedNv(const QcnNumberedNv&);
  QcnNumberedNv& operator=(const QcnNumberedNv&);
  QcnNumberedNv() : nvId(0), index(0), payload() {
  }

  virtual ~QcnNumberedNv() noexcept;
  int32_t nvId;
  int8_t index;
  std::string payload;

  _QcnNumberedNv__isset __isset;

  void __set_nvId(const int32_t val);

  void __set_index(const int8_t val);

  void __set_payload(const std::string& val);

  bool operator == (const QcnNumberedNv & rhs) const
  {
    if (!(nvId == rhs.nvId))
      return false;
    if (!(index == rhs.index))
      return false;
    if (!(payload == rhs.payload))
      return false;
    return true;
  }
  bool operator != (const QcnNumberedNv &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnNumberedNv & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnNumberedNv &a, QcnNumberedNv &b);

std::ostream& operator<<(std::ostream& out, const QcnNumberedNv& obj);

typedef struct _QcnNumberedNvList__isset {
  _QcnNumberedNvList__isset() : subscriptionId(false), nvs(false) {}
  bool subscriptionId :1;
  bool nvs :1;
} _QcnNumberedNvList__isset;

class QcnNumberedNvList : public virtual ::apache::thrift::TBase {
 public:

  QcnNumberedNvList(const QcnNumberedNvList&);
  QcnNumberedNvList& operator=(const QcnNumberedNvList&);
  QcnNumberedNvList() : subscriptionId(0) {
  }

  virtual ~QcnNumberedNvList() noexcept;
  int32_t subscriptionId;
  std::vector<QcnNumberedNv>  nvs;

  _QcnNumberedNvList__isset __isset;

  void __set_subscriptionId(const int32_t val);

  void __set_nvs(const std::vector<QcnNumberedNv> & val);

  bool operator == (const QcnNumberedNvList & rhs) const
  {
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(nvs == rhs.nvs))
      return false;
    return true;
  }
  bool operator != (const QcnNumberedNvList &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnNumberedNvList & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnNumberedNvList &a, QcnNumberedNvList &b);

std::ostream& operator<<(std::ostream& out, const QcnNumberedNvList& obj);

typedef struct _QcnEfsFile__isset {
  _QcnEfsFile__isset() : efsPath(false), flags(false), bufferingOption(false), cleanupOption(false), fileCreationTimeStamp(false), payload(false) {}
  bool efsPath :1;
  bool flags :1;
  bool bufferingOption :1;
  bool cleanupOption :1;
  bool fileCreationTimeStamp :1;
  bool payload :1;
} _QcnEfsFile__isset;

class QcnEfsFile : public virtual ::apache::thrift::TBase {
 public:

  QcnEfsFile(const QcnEfsFile&);
  QcnEfsFile& operator=(const QcnEfsFile&);
  QcnEfsFile() : efsPath(), flags(0), bufferingOption(0), cleanupOption(0), fileCreationTimeStamp(0), payload() {
  }

  virtual ~QcnEfsFile() noexcept;
  std::string efsPath;
  int16_t flags;
  int8_t bufferingOption;
  int8_t cleanupOption;
  int32_t fileCreationTimeStamp;
  std::string payload;

  _QcnEfsFile__isset __isset;

  void __set_efsPath(const std::string& val);

  void __set_flags(const int16_t val);

  void __set_bufferingOption(const int8_t val);

  void __set_cleanupOption(const int8_t val);

  void __set_fileCreationTimeStamp(const int32_t val);

  void __set_payload(const std::string& val);

  bool operator == (const QcnEfsFile & rhs) const
  {
    if (!(efsPath == rhs.efsPath))
      return false;
    if (!(flags == rhs.flags))
      return false;
    if (!(bufferingOption == rhs.bufferingOption))
      return false;
    if (!(cleanupOption == rhs.cleanupOption))
      return false;
    if (!(fileCreationTimeStamp == rhs.fileCreationTimeStamp))
      return false;
    if (!(payload == rhs.payload))
      return false;
    return true;
  }
  bool operator != (const QcnEfsFile &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnEfsFile & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnEfsFile &a, QcnEfsFile &b);

std::ostream& operator<<(std::ostream& out, const QcnEfsFile& obj);

typedef struct _QcnEfsItem__isset {
  _QcnEfsItem__isset() : efsPath(false), payload(false) {}
  bool efsPath :1;
  bool payload :1;
} _QcnEfsItem__isset;

class QcnEfsItem : public virtual ::apache::thrift::TBase {
 public:

  QcnEfsItem(const QcnEfsItem&);
  QcnEfsItem& operator=(const QcnEfsItem&);
  QcnEfsItem() : efsPath(), payload() {
  }

  virtual ~QcnEfsItem() noexcept;
  std::string efsPath;
  std::string payload;

  _QcnEfsItem__isset __isset;

  void __set_efsPath(const std::string& val);

  void __set_payload(const std::string& val);

  bool operator == (const QcnEfsItem & rhs) const
  {
    if (!(efsPath == rhs.efsPath))
      return false;
    if (!(payload == rhs.payload))
      return false;
    return true;
  }
  bool operator != (const QcnEfsItem &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnEfsItem & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnEfsItem &a, QcnEfsItem &b);

std::ostream& operator<<(std::ostream& out, const QcnEfsItem& obj);

typedef struct _QcnEfsItemList__isset {
  _QcnEfsItemList__isset() : subscriptionId(false), efsItems(false) {}
  bool subscriptionId :1;
  bool efsItems :1;
} _QcnEfsItemList__isset;

class QcnEfsItemList : public virtual ::apache::thrift::TBase {
 public:

  QcnEfsItemList(const QcnEfsItemList&);
  QcnEfsItemList& operator=(const QcnEfsItemList&);
  QcnEfsItemList() : subscriptionId(0) {
  }

  virtual ~QcnEfsItemList() noexcept;
  int32_t subscriptionId;
  std::vector<QcnEfsItem>  efsItems;

  _QcnEfsItemList__isset __isset;

  void __set_subscriptionId(const int32_t val);

  void __set_efsItems(const std::vector<QcnEfsItem> & val);

  bool operator == (const QcnEfsItemList & rhs) const
  {
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(efsItems == rhs.efsItems))
      return false;
    return true;
  }
  bool operator != (const QcnEfsItemList &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnEfsItemList & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnEfsItemList &a, QcnEfsItemList &b);

std::ostream& operator<<(std::ostream& out, const QcnEfsItemList& obj);

typedef struct _QcnContent__isset {
  _QcnContent__isset() : header(false), featureMask(false), prlLists(false), nvLists(false), efsItemLists(false), efsFiles(false) {}
  bool header :1;
  bool featureMask :1;
  bool prlLists :1;
  bool nvLists :1;
  bool efsItemLists :1;
  bool efsFiles :1;
} _QcnContent__isset;

class QcnContent : public virtual ::apache::thrift::TBase {
 public:

  QcnContent(const QcnContent&);
  QcnContent& operator=(const QcnContent&);
  QcnContent() : featureMask() {
  }

  virtual ~QcnContent() noexcept;
  QcnHeader header;
  std::string featureMask;
  std::vector<QcnPrlList>  prlLists;
  std::vector<QcnNumberedNvList>  nvLists;
  std::vector<QcnEfsItemList>  efsItemLists;
  std::vector<QcnEfsFile>  efsFiles;

  _QcnContent__isset __isset;

  void __set_header(const QcnHeader& val);

  void __set_featureMask(const std::string& val);

  void __set_prlLists(const std::vector<QcnPrlList> & val);

  void __set_nvLists(const std::vector<QcnNumberedNvList> & val);

  void __set_efsItemLists(const std::vector<QcnEfsItemList> & val);

  void __set_efsFiles(const std::vector<QcnEfsFile> & val);

  bool operator == (const QcnContent & rhs) const
  {
    if (!(header == rhs.header))
      return false;
    if (!(featureMask == rhs.featureMask))
      return false;
    if (!(prlLists == rhs.prlLists))
      return false;
    if (!(nvLists == rhs.nvLists))
      return false;
    if (!(efsItemLists == rhs.efsItemLists))
      return false;
    if (!(efsFiles == rhs.efsFiles))
      return false;
    return true;
  }
  bool operator != (const QcnContent &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QcnContent & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QcnContent &a, QcnContent &b);

std::ostream& operator<<(std::ostream& out, const QcnContent& obj);

typedef struct _ProtocolConfiguration__isset {
  _ProtocolConfiguration__isset() : protocolHandle(false), overrideProtocolType(false), baudRate(false), timeout(false), enableHdlcOnly(false), blockingLogMaskClearOnConnection(false), clearLogMaskOnDisconnect(false), disablePolling(false) {}
  bool protocolHandle :1;
  bool overrideProtocolType :1;
  bool baudRate :1;
  bool timeout :1;
  bool enableHdlcOnly :1;
  bool blockingLogMaskClearOnConnection :1;
  bool clearLogMaskOnDisconnect :1;
  bool disablePolling :1;
} _ProtocolConfiguration__isset;

class ProtocolConfiguration : public virtual ::apache::thrift::TBase {
 public:

  ProtocolConfiguration(const ProtocolConfiguration&);
  ProtocolConfiguration& operator=(const ProtocolConfiguration&);
  ProtocolConfiguration() : protocolHandle(0), overrideProtocolType((ProtocolType::type)0), baudRate((BaudRate::type)0), timeout(0), enableHdlcOnly(0), blockingLogMaskClearOnConnection(0), clearLogMaskOnDisconnect(0), disablePolling(0) {
  }

  virtual ~ProtocolConfiguration() noexcept;
  int64_t protocolHandle;
  ProtocolType::type overrideProtocolType;
  BaudRate::type baudRate;
  int64_t timeout;
  bool enableHdlcOnly;
  bool blockingLogMaskClearOnConnection;
  bool clearLogMaskOnDisconnect;
  bool disablePolling;

  _ProtocolConfiguration__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_overrideProtocolType(const ProtocolType::type val);

  void __set_baudRate(const BaudRate::type val);

  void __set_timeout(const int64_t val);

  void __set_enableHdlcOnly(const bool val);

  void __set_blockingLogMaskClearOnConnection(const bool val);

  void __set_clearLogMaskOnDisconnect(const bool val);

  void __set_disablePolling(const bool val);

  bool operator == (const ProtocolConfiguration & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (__isset.overrideProtocolType != rhs.__isset.overrideProtocolType)
      return false;
    else if (__isset.overrideProtocolType && !(overrideProtocolType == rhs.overrideProtocolType))
      return false;
    if (__isset.baudRate != rhs.__isset.baudRate)
      return false;
    else if (__isset.baudRate && !(baudRate == rhs.baudRate))
      return false;
    if (__isset.timeout != rhs.__isset.timeout)
      return false;
    else if (__isset.timeout && !(timeout == rhs.timeout))
      return false;
    if (__isset.enableHdlcOnly != rhs.__isset.enableHdlcOnly)
      return false;
    else if (__isset.enableHdlcOnly && !(enableHdlcOnly == rhs.enableHdlcOnly))
      return false;
    if (__isset.blockingLogMaskClearOnConnection != rhs.__isset.blockingLogMaskClearOnConnection)
      return false;
    else if (__isset.blockingLogMaskClearOnConnection && !(blockingLogMaskClearOnConnection == rhs.blockingLogMaskClearOnConnection))
      return false;
    if (__isset.clearLogMaskOnDisconnect != rhs.__isset.clearLogMaskOnDisconnect)
      return false;
    else if (__isset.clearLogMaskOnDisconnect && !(clearLogMaskOnDisconnect == rhs.clearLogMaskOnDisconnect))
      return false;
    if (__isset.disablePolling != rhs.__isset.disablePolling)
      return false;
    else if (__isset.disablePolling && !(disablePolling == rhs.disablePolling))
      return false;
    return true;
  }
  bool operator != (const ProtocolConfiguration &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProtocolConfiguration & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProtocolConfiguration &a, ProtocolConfiguration &b);

std::ostream& operator<<(std::ostream& out, const ProtocolConfiguration& obj);

typedef struct _DiagProtocolConnectionOptions__isset {
  _DiagProtocolConnectionOptions__isset() : protocolHandle(false), openQdssPort(false), enableDefaultQdssConfiguration(false), hdlcMode(false) {}
  bool protocolHandle :1;
  bool openQdssPort :1;
  bool enableDefaultQdssConfiguration :1;
  bool hdlcMode :1;
} _DiagProtocolConnectionOptions__isset;

class DiagProtocolConnectionOptions : public virtual ::apache::thrift::TBase {
 public:

  DiagProtocolConnectionOptions(const DiagProtocolConnectionOptions&);
  DiagProtocolConnectionOptions& operator=(const DiagProtocolConnectionOptions&);
  DiagProtocolConnectionOptions() : protocolHandle(0), openQdssPort(0), enableDefaultQdssConfiguration(0), hdlcMode((HdlcMode::type)0) {
  }

  virtual ~DiagProtocolConnectionOptions() noexcept;
  int64_t protocolHandle;
  bool openQdssPort;
  bool enableDefaultQdssConfiguration;
  HdlcMode::type hdlcMode;

  _DiagProtocolConnectionOptions__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_openQdssPort(const bool val);

  void __set_enableDefaultQdssConfiguration(const bool val);

  void __set_hdlcMode(const HdlcMode::type val);

  bool operator == (const DiagProtocolConnectionOptions & rhs) const
  {
    if (__isset.protocolHandle != rhs.__isset.protocolHandle)
      return false;
    else if (__isset.protocolHandle && !(protocolHandle == rhs.protocolHandle))
      return false;
    if (__isset.openQdssPort != rhs.__isset.openQdssPort)
      return false;
    else if (__isset.openQdssPort && !(openQdssPort == rhs.openQdssPort))
      return false;
    if (__isset.enableDefaultQdssConfiguration != rhs.__isset.enableDefaultQdssConfiguration)
      return false;
    else if (__isset.enableDefaultQdssConfiguration && !(enableDefaultQdssConfiguration == rhs.enableDefaultQdssConfiguration))
      return false;
    if (__isset.hdlcMode != rhs.__isset.hdlcMode)
      return false;
    else if (__isset.hdlcMode && !(hdlcMode == rhs.hdlcMode))
      return false;
    return true;
  }
  bool operator != (const DiagProtocolConnectionOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagProtocolConnectionOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagProtocolConnectionOptions &a, DiagProtocolConnectionOptions &b);

std::ostream& operator<<(std::ostream& out, const DiagProtocolConnectionOptions& obj);

typedef struct _InternetConnectionOptions__isset {
  _InternetConnectionOptions__isset() : username(false), password(false), telnetPort(false), ftpPort(false) {}
  bool username :1;
  bool password :1;
  bool telnetPort :1;
  bool ftpPort :1;
} _InternetConnectionOptions__isset;

class InternetConnectionOptions : public virtual ::apache::thrift::TBase {
 public:

  InternetConnectionOptions(const InternetConnectionOptions&);
  InternetConnectionOptions& operator=(const InternetConnectionOptions&);
  InternetConnectionOptions() : username(), password(), telnetPort(0), ftpPort(0) {
  }

  virtual ~InternetConnectionOptions() noexcept;
  std::string username;
  std::string password;
  int32_t telnetPort;
  int32_t ftpPort;

  _InternetConnectionOptions__isset __isset;

  void __set_username(const std::string& val);

  void __set_password(const std::string& val);

  void __set_telnetPort(const int32_t val);

  void __set_ftpPort(const int32_t val);

  bool operator == (const InternetConnectionOptions & rhs) const
  {
    if (__isset.username != rhs.__isset.username)
      return false;
    else if (__isset.username && !(username == rhs.username))
      return false;
    if (__isset.password != rhs.__isset.password)
      return false;
    else if (__isset.password && !(password == rhs.password))
      return false;
    if (__isset.telnetPort != rhs.__isset.telnetPort)
      return false;
    else if (__isset.telnetPort && !(telnetPort == rhs.telnetPort))
      return false;
    if (__isset.ftpPort != rhs.__isset.ftpPort)
      return false;
    else if (__isset.ftpPort && !(ftpPort == rhs.ftpPort))
      return false;
    return true;
  }
  bool operator != (const InternetConnectionOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const InternetConnectionOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(InternetConnectionOptions &a, InternetConnectionOptions &b);

std::ostream& operator<<(std::ostream& out, const InternetConnectionOptions& obj);

typedef struct _ProtocolConnectionOptions__isset {
  _ProtocolConnectionOptions__isset() : diagProtocolConfiguration(false), internetConnectionConfiguration(false) {}
  bool diagProtocolConfiguration :1;
  bool internetConnectionConfiguration :1;
} _ProtocolConnectionOptions__isset;

class ProtocolConnectionOptions : public virtual ::apache::thrift::TBase {
 public:

  ProtocolConnectionOptions(const ProtocolConnectionOptions&);
  ProtocolConnectionOptions& operator=(const ProtocolConnectionOptions&);
  ProtocolConnectionOptions() {
  }

  virtual ~ProtocolConnectionOptions() noexcept;
  DiagProtocolConnectionOptions diagProtocolConfiguration;
  InternetConnectionOptions internetConnectionConfiguration;

  _ProtocolConnectionOptions__isset __isset;

  void __set_diagProtocolConfiguration(const DiagProtocolConnectionOptions& val);

  void __set_internetConnectionConfiguration(const InternetConnectionOptions& val);

  bool operator == (const ProtocolConnectionOptions & rhs) const
  {
    if (__isset.diagProtocolConfiguration != rhs.__isset.diagProtocolConfiguration)
      return false;
    else if (__isset.diagProtocolConfiguration && !(diagProtocolConfiguration == rhs.diagProtocolConfiguration))
      return false;
    if (__isset.internetConnectionConfiguration != rhs.__isset.internetConnectionConfiguration)
      return false;
    else if (__isset.internetConnectionConfiguration && !(internetConnectionConfiguration == rhs.internetConnectionConfiguration))
      return false;
    return true;
  }
  bool operator != (const ProtocolConnectionOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProtocolConnectionOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProtocolConnectionOptions &a, ProtocolConnectionOptions &b);

std::ostream& operator<<(std::ostream& out, const ProtocolConnectionOptions& obj);

typedef struct _TcpOptions__isset {
  _TcpOptions__isset() : description(false), protocolType(false), isClient(false), deviceHandle(false), adbSerialNumber(false), chipSerialNumber(false), protocolConnectionOptions(false), useExistingConnectionIfAvailable(false) {}
  bool description :1;
  bool protocolType :1;
  bool isClient :1;
  bool deviceHandle :1;
  bool adbSerialNumber :1;
  bool chipSerialNumber :1;
  bool protocolConnectionOptions :1;
  bool useExistingConnectionIfAvailable :1;
} _TcpOptions__isset;

class TcpOptions : public virtual ::apache::thrift::TBase {
 public:

  TcpOptions(const TcpOptions&);
  TcpOptions& operator=(const TcpOptions&);
  TcpOptions() : description(), protocolType((ProtocolType::type)0), isClient(0), deviceHandle(0), adbSerialNumber(), chipSerialNumber(), useExistingConnectionIfAvailable(0) {
  }

  virtual ~TcpOptions() noexcept;
  std::string description;
  ProtocolType::type protocolType;
  bool isClient;
  int64_t deviceHandle;
  std::string adbSerialNumber;
  std::string chipSerialNumber;
  ProtocolConnectionOptions protocolConnectionOptions;
  bool useExistingConnectionIfAvailable;

  _TcpOptions__isset __isset;

  void __set_description(const std::string& val);

  void __set_protocolType(const ProtocolType::type val);

  void __set_isClient(const bool val);

  void __set_deviceHandle(const int64_t val);

  void __set_adbSerialNumber(const std::string& val);

  void __set_chipSerialNumber(const std::string& val);

  void __set_protocolConnectionOptions(const ProtocolConnectionOptions& val);

  void __set_useExistingConnectionIfAvailable(const bool val);

  bool operator == (const TcpOptions & rhs) const
  {
    if (!(description == rhs.description))
      return false;
    if (!(protocolType == rhs.protocolType))
      return false;
    if (!(isClient == rhs.isClient))
      return false;
    if (__isset.deviceHandle != rhs.__isset.deviceHandle)
      return false;
    else if (__isset.deviceHandle && !(deviceHandle == rhs.deviceHandle))
      return false;
    if (__isset.adbSerialNumber != rhs.__isset.adbSerialNumber)
      return false;
    else if (__isset.adbSerialNumber && !(adbSerialNumber == rhs.adbSerialNumber))
      return false;
    if (__isset.chipSerialNumber != rhs.__isset.chipSerialNumber)
      return false;
    else if (__isset.chipSerialNumber && !(chipSerialNumber == rhs.chipSerialNumber))
      return false;
    if (__isset.protocolConnectionOptions != rhs.__isset.protocolConnectionOptions)
      return false;
    else if (__isset.protocolConnectionOptions && !(protocolConnectionOptions == rhs.protocolConnectionOptions))
      return false;
    if (__isset.useExistingConnectionIfAvailable != rhs.__isset.useExistingConnectionIfAvailable)
      return false;
    else if (__isset.useExistingConnectionIfAvailable && !(useExistingConnectionIfAvailable == rhs.useExistingConnectionIfAvailable))
      return false;
    return true;
  }
  bool operator != (const TcpOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TcpOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TcpOptions &a, TcpOptions &b);

std::ostream& operator<<(std::ostream& out, const TcpOptions& obj);

typedef struct _TransferFileOptions__isset {
  _TransferFileOptions__isset() : protocolHandle(false), protocolType(false), wildcardPattern(false) {}
  bool protocolHandle :1;
  bool protocolType :1;
  bool wildcardPattern :1;
} _TransferFileOptions__isset;

class TransferFileOptions : public virtual ::apache::thrift::TBase {
 public:

  TransferFileOptions(const TransferFileOptions&);
  TransferFileOptions& operator=(const TransferFileOptions&);
  TransferFileOptions() : protocolHandle(0), protocolType((ProtocolType::type)0), wildcardPattern() {
  }

  virtual ~TransferFileOptions() noexcept;
  int64_t protocolHandle;
  ProtocolType::type protocolType;
  std::string wildcardPattern;

  _TransferFileOptions__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_protocolType(const ProtocolType::type val);

  void __set_wildcardPattern(const std::string& val);

  bool operator == (const TransferFileOptions & rhs) const
  {
    if (__isset.protocolHandle != rhs.__isset.protocolHandle)
      return false;
    else if (__isset.protocolHandle && !(protocolHandle == rhs.protocolHandle))
      return false;
    if (__isset.protocolType != rhs.__isset.protocolType)
      return false;
    else if (__isset.protocolType && !(protocolType == rhs.protocolType))
      return false;
    if (__isset.wildcardPattern != rhs.__isset.wildcardPattern)
      return false;
    else if (__isset.wildcardPattern && !(wildcardPattern == rhs.wildcardPattern))
      return false;
    return true;
  }
  bool operator != (const TransferFileOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TransferFileOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TransferFileOptions &a, TransferFileOptions &b);

std::ostream& operator<<(std::ostream& out, const TransferFileOptions& obj);

typedef struct _TransferFileResult__isset {
  _TransferFileResult__isset() : errorType(false), sequence(false) {}
  bool errorType :1;
  bool sequence :1;
} _TransferFileResult__isset;

class TransferFileResult : public virtual ::apache::thrift::TBase {
 public:

  TransferFileResult(const TransferFileResult&);
  TransferFileResult& operator=(const TransferFileResult&);
  TransferFileResult() : sequence() {
  }

  virtual ~TransferFileResult() noexcept;
  ErrorType errorType;
  std::string sequence;

  _TransferFileResult__isset __isset;

  void __set_errorType(const ErrorType& val);

  void __set_sequence(const std::string& val);

  bool operator == (const TransferFileResult & rhs) const
  {
    if (__isset.errorType != rhs.__isset.errorType)
      return false;
    else if (__isset.errorType && !(errorType == rhs.errorType))
      return false;
    if (__isset.sequence != rhs.__isset.sequence)
      return false;
    else if (__isset.sequence && !(sequence == rhs.sequence))
      return false;
    return true;
  }
  bool operator != (const TransferFileResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TransferFileResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TransferFileResult &a, TransferFileResult &b);

std::ostream& operator<<(std::ostream& out, const TransferFileResult& obj);

typedef struct _ClientCloseRequest__isset {
  _ClientCloseRequest__isset() : purpose(false) {}
  bool purpose :1;
} _ClientCloseRequest__isset;

class ClientCloseRequest : public virtual ::apache::thrift::TBase {
 public:

  ClientCloseRequest(const ClientCloseRequest&);
  ClientCloseRequest& operator=(const ClientCloseRequest&);
  ClientCloseRequest() : purpose() {
  }

  virtual ~ClientCloseRequest() noexcept;
  std::string purpose;

  _ClientCloseRequest__isset __isset;

  void __set_purpose(const std::string& val);

  bool operator == (const ClientCloseRequest & rhs) const
  {
    if (!(purpose == rhs.purpose))
      return false;
    return true;
  }
  bool operator != (const ClientCloseRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCloseRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ClientCloseRequest &a, ClientCloseRequest &b);

std::ostream& operator<<(std::ostream& out, const ClientCloseRequest& obj);

typedef struct _ClientCloseReason__isset {
  _ClientCloseReason__isset() : reason(false) {}
  bool reason :1;
} _ClientCloseReason__isset;

class ClientCloseReason : public virtual ::apache::thrift::TBase {
 public:

  ClientCloseReason(const ClientCloseReason&);
  ClientCloseReason& operator=(const ClientCloseReason&);
  ClientCloseReason() : reason() {
  }

  virtual ~ClientCloseReason() noexcept;
  std::string reason;

  _ClientCloseReason__isset __isset;

  void __set_reason(const std::string& val);

  bool operator == (const ClientCloseReason & rhs) const
  {
    if (!(reason == rhs.reason))
      return false;
    return true;
  }
  bool operator != (const ClientCloseReason &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientCloseReason & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ClientCloseReason &a, ClientCloseReason &b);

std::ostream& operator<<(std::ostream& out, const ClientCloseReason& obj);

typedef struct _ProtocolConfigurationResult__isset {
  _ProtocolConfigurationResult__isset() : errorType(false), protocolHandle(false), protocolType(false), baudRate(false), timeout(false), hdlcOnlyMode(false), disablePolling(false) {}
  bool errorType :1;
  bool protocolHandle :1;
  bool protocolType :1;
  bool baudRate :1;
  bool timeout :1;
  bool hdlcOnlyMode :1;
  bool disablePolling :1;
} _ProtocolConfigurationResult__isset;

class ProtocolConfigurationResult : public virtual ::apache::thrift::TBase {
 public:

  ProtocolConfigurationResult(const ProtocolConfigurationResult&);
  ProtocolConfigurationResult& operator=(const ProtocolConfigurationResult&);
  ProtocolConfigurationResult() : protocolHandle(0), protocolType((ProtocolType::type)0), baudRate((BaudRate::type)0), timeout(0), hdlcOnlyMode((HdlcModeStatus::type)0), disablePolling(0) {
  }

  virtual ~ProtocolConfigurationResult() noexcept;
  ErrorType errorType;
  int64_t protocolHandle;
  ProtocolType::type protocolType;
  BaudRate::type baudRate;
  int64_t timeout;
  HdlcModeStatus::type hdlcOnlyMode;
  bool disablePolling;

  _ProtocolConfigurationResult__isset __isset;

  void __set_errorType(const ErrorType& val);

  void __set_protocolHandle(const int64_t val);

  void __set_protocolType(const ProtocolType::type val);

  void __set_baudRate(const BaudRate::type val);

  void __set_timeout(const int64_t val);

  void __set_hdlcOnlyMode(const HdlcModeStatus::type val);

  void __set_disablePolling(const bool val);

  bool operator == (const ProtocolConfigurationResult & rhs) const
  {
    if (__isset.errorType != rhs.__isset.errorType)
      return false;
    else if (__isset.errorType && !(errorType == rhs.errorType))
      return false;
    if (__isset.protocolHandle != rhs.__isset.protocolHandle)
      return false;
    else if (__isset.protocolHandle && !(protocolHandle == rhs.protocolHandle))
      return false;
    if (__isset.protocolType != rhs.__isset.protocolType)
      return false;
    else if (__isset.protocolType && !(protocolType == rhs.protocolType))
      return false;
    if (__isset.baudRate != rhs.__isset.baudRate)
      return false;
    else if (__isset.baudRate && !(baudRate == rhs.baudRate))
      return false;
    if (__isset.timeout != rhs.__isset.timeout)
      return false;
    else if (__isset.timeout && !(timeout == rhs.timeout))
      return false;
    if (__isset.hdlcOnlyMode != rhs.__isset.hdlcOnlyMode)
      return false;
    else if (__isset.hdlcOnlyMode && !(hdlcOnlyMode == rhs.hdlcOnlyMode))
      return false;
    if (__isset.disablePolling != rhs.__isset.disablePolling)
      return false;
    else if (__isset.disablePolling && !(disablePolling == rhs.disablePolling))
      return false;
    return true;
  }
  bool operator != (const ProtocolConfigurationResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProtocolConfigurationResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProtocolConfigurationResult &a, ProtocolConfigurationResult &b);

std::ostream& operator<<(std::ostream& out, const ProtocolConfigurationResult& obj);

typedef struct _XqcnRestoreOptions__isset {
  _XqcnRestoreOptions__isset() : xqcnFileContents(false), sourceFilePath(false), serviceProgrammingCode(false), bAllowEsnMismatch(false), bResetUponCompletion(false), resetTimeout(false), filterFileContents(false) {}
  bool xqcnFileContents :1;
  bool sourceFilePath :1;
  bool serviceProgrammingCode :1;
  bool bAllowEsnMismatch :1;
  bool bResetUponCompletion :1;
  bool resetTimeout :1;
  bool filterFileContents :1;
} _XqcnRestoreOptions__isset;

class XqcnRestoreOptions : public virtual ::apache::thrift::TBase {
 public:

  XqcnRestoreOptions(const XqcnRestoreOptions&);
  XqcnRestoreOptions& operator=(const XqcnRestoreOptions&);
  XqcnRestoreOptions() : xqcnFileContents(), sourceFilePath(), serviceProgrammingCode(), bAllowEsnMismatch(0), bResetUponCompletion(0), resetTimeout(0), filterFileContents() {
  }

  virtual ~XqcnRestoreOptions() noexcept;
  std::string xqcnFileContents;
  std::string sourceFilePath;
  std::string serviceProgrammingCode;
  bool bAllowEsnMismatch;
  bool bResetUponCompletion;
  int32_t resetTimeout;
  std::string filterFileContents;

  _XqcnRestoreOptions__isset __isset;

  void __set_xqcnFileContents(const std::string& val);

  void __set_sourceFilePath(const std::string& val);

  void __set_serviceProgrammingCode(const std::string& val);

  void __set_bAllowEsnMismatch(const bool val);

  void __set_bResetUponCompletion(const bool val);

  void __set_resetTimeout(const int32_t val);

  void __set_filterFileContents(const std::string& val);

  bool operator == (const XqcnRestoreOptions & rhs) const
  {
    if (!(xqcnFileContents == rhs.xqcnFileContents))
      return false;
    if (!(sourceFilePath == rhs.sourceFilePath))
      return false;
    if (!(serviceProgrammingCode == rhs.serviceProgrammingCode))
      return false;
    if (!(bAllowEsnMismatch == rhs.bAllowEsnMismatch))
      return false;
    if (!(bResetUponCompletion == rhs.bResetUponCompletion))
      return false;
    if (!(resetTimeout == rhs.resetTimeout))
      return false;
    if (!(filterFileContents == rhs.filterFileContents))
      return false;
    return true;
  }
  bool operator != (const XqcnRestoreOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const XqcnRestoreOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(XqcnRestoreOptions &a, XqcnRestoreOptions &b);

std::ostream& operator<<(std::ostream& out, const XqcnRestoreOptions& obj);

typedef struct _XqcnBackupOptions__isset {
  _XqcnBackupOptions__isset() : serviceProgrammingCode(false), bResetUponCompletion(false), resetTimeout(false), filterFileContents(false) {}
  bool serviceProgrammingCode :1;
  bool bResetUponCompletion :1;
  bool resetTimeout :1;
  bool filterFileContents :1;
} _XqcnBackupOptions__isset;

class XqcnBackupOptions : public virtual ::apache::thrift::TBase {
 public:

  XqcnBackupOptions(const XqcnBackupOptions&);
  XqcnBackupOptions& operator=(const XqcnBackupOptions&);
  XqcnBackupOptions() : serviceProgrammingCode(), bResetUponCompletion(0), resetTimeout(0), filterFileContents() {
  }

  virtual ~XqcnBackupOptions() noexcept;
  std::string serviceProgrammingCode;
  bool bResetUponCompletion;
  int32_t resetTimeout;
  std::string filterFileContents;

  _XqcnBackupOptions__isset __isset;

  void __set_serviceProgrammingCode(const std::string& val);

  void __set_bResetUponCompletion(const bool val);

  void __set_resetTimeout(const int32_t val);

  void __set_filterFileContents(const std::string& val);

  bool operator == (const XqcnBackupOptions & rhs) const
  {
    if (!(serviceProgrammingCode == rhs.serviceProgrammingCode))
      return false;
    if (!(bResetUponCompletion == rhs.bResetUponCompletion))
      return false;
    if (!(resetTimeout == rhs.resetTimeout))
      return false;
    if (!(filterFileContents == rhs.filterFileContents))
      return false;
    return true;
  }
  bool operator != (const XqcnBackupOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const XqcnBackupOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(XqcnBackupOptions &a, XqcnBackupOptions &b);

std::ostream& operator<<(std::ostream& out, const XqcnBackupOptions& obj);

typedef struct _DeviceConfigResp__isset {
  _DeviceConfigResp__isset() : returnCode(false), xqcnFileContents(false) {}
  bool returnCode :1;
  bool xqcnFileContents :1;
} _DeviceConfigResp__isset;

class DeviceConfigResp : public virtual ::apache::thrift::TBase {
 public:

  DeviceConfigResp(const DeviceConfigResp&);
  DeviceConfigResp& operator=(const DeviceConfigResp&);
  DeviceConfigResp() : returnCode((ErrorCode::type)0), xqcnFileContents() {
  }

  virtual ~DeviceConfigResp() noexcept;
  ErrorCode::type returnCode;
  std::string xqcnFileContents;

  _DeviceConfigResp__isset __isset;

  void __set_returnCode(const ErrorCode::type val);

  void __set_xqcnFileContents(const std::string& val);

  bool operator == (const DeviceConfigResp & rhs) const
  {
    if (!(returnCode == rhs.returnCode))
      return false;
    if (!(xqcnFileContents == rhs.xqcnFileContents))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigResp &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigResp & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DeviceConfigResp &a, DeviceConfigResp &b);

std::ostream& operator<<(std::ostream& out, const DeviceConfigResp& obj);

typedef struct _QmBackendInfoType__isset {
  _QmBackendInfoType__isset() : backendName(false), backendId(false) {}
  bool backendName :1;
  bool backendId :1;
} _QmBackendInfoType__isset;

class QmBackendInfoType : public virtual ::apache::thrift::TBase {
 public:

  QmBackendInfoType(const QmBackendInfoType&);
  QmBackendInfoType& operator=(const QmBackendInfoType&);
  QmBackendInfoType() : backendName(), backendId(0) {
  }

  virtual ~QmBackendInfoType() noexcept;
  std::string backendName;
  int32_t backendId;

  _QmBackendInfoType__isset __isset;

  void __set_backendName(const std::string& val);

  void __set_backendId(const int32_t val);

  bool operator == (const QmBackendInfoType & rhs) const
  {
    if (__isset.backendName != rhs.__isset.backendName)
      return false;
    else if (__isset.backendName && !(backendName == rhs.backendName))
      return false;
    if (__isset.backendId != rhs.__isset.backendId)
      return false;
    else if (__isset.backendId && !(backendId == rhs.backendId))
      return false;
    return true;
  }
  bool operator != (const QmBackendInfoType &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmBackendInfoType & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmBackendInfoType &a, QmBackendInfoType &b);

std::ostream& operator<<(std::ostream& out, const QmBackendInfoType& obj);

typedef struct _QmBackendInfo__isset {
  _QmBackendInfo__isset() : status(false), backendInfoList(false) {}
  bool status :1;
  bool backendInfoList :1;
} _QmBackendInfo__isset;

class QmBackendInfo : public virtual ::apache::thrift::TBase {
 public:

  QmBackendInfo(const QmBackendInfo&);
  QmBackendInfo& operator=(const QmBackendInfo&);
  QmBackendInfo() : status((QmStatusType::type)0) {
  }

  virtual ~QmBackendInfo() noexcept;
  QmStatusType::type status;
  std::vector<QmBackendInfoType>  backendInfoList;

  _QmBackendInfo__isset __isset;

  void __set_status(const QmStatusType::type val);

  void __set_backendInfoList(const std::vector<QmBackendInfoType> & val);

  bool operator == (const QmBackendInfo & rhs) const
  {
    if (__isset.status != rhs.__isset.status)
      return false;
    else if (__isset.status && !(status == rhs.status))
      return false;
    if (__isset.backendInfoList != rhs.__isset.backendInfoList)
      return false;
    else if (__isset.backendInfoList && !(backendInfoList == rhs.backendInfoList))
      return false;
    return true;
  }
  bool operator != (const QmBackendInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmBackendInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmBackendInfo &a, QmBackendInfo &b);

std::ostream& operator<<(std::ostream& out, const QmBackendInfo& obj);

typedef struct _QmBackendInfoResponse__isset {
  _QmBackendInfoResponse__isset() : backendInfo(false) {}
  bool backendInfo :1;
} _QmBackendInfoResponse__isset;

class QmBackendInfoResponse : public virtual ::apache::thrift::TBase {
 public:

  QmBackendInfoResponse(const QmBackendInfoResponse&);
  QmBackendInfoResponse& operator=(const QmBackendInfoResponse&);
  QmBackendInfoResponse() {
  }

  virtual ~QmBackendInfoResponse() noexcept;
  std::vector<QmBackendInfo>  backendInfo;

  _QmBackendInfoResponse__isset __isset;

  void __set_backendInfo(const std::vector<QmBackendInfo> & val);

  bool operator == (const QmBackendInfoResponse & rhs) const
  {
    if (__isset.backendInfo != rhs.__isset.backendInfo)
      return false;
    else if (__isset.backendInfo && !(backendInfo == rhs.backendInfo))
      return false;
    return true;
  }
  bool operator != (const QmBackendInfoResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmBackendInfoResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmBackendInfoResponse &a, QmBackendInfoResponse &b);

std::ostream& operator<<(std::ostream& out, const QmBackendInfoResponse& obj);

typedef struct _QmCapabilitiesInfo__isset {
  _QmCapabilitiesInfo__isset() : status(false), capabilityInfoList(false) {}
  bool status :1;
  bool capabilityInfoList :1;
} _QmCapabilitiesInfo__isset;

class QmCapabilitiesInfo : public virtual ::apache::thrift::TBase {
 public:

  QmCapabilitiesInfo(const QmCapabilitiesInfo&);
  QmCapabilitiesInfo& operator=(const QmCapabilitiesInfo&);
  QmCapabilitiesInfo() : status((QmStatusType::type)0) {
  }

  virtual ~QmCapabilitiesInfo() noexcept;
  QmStatusType::type status;
  std::vector<StreamingCapabilityInfoType>  capabilityInfoList;

  _QmCapabilitiesInfo__isset __isset;

  void __set_status(const QmStatusType::type val);

  void __set_capabilityInfoList(const std::vector<StreamingCapabilityInfoType> & val);

  bool operator == (const QmCapabilitiesInfo & rhs) const
  {
    if (__isset.status != rhs.__isset.status)
      return false;
    else if (__isset.status && !(status == rhs.status))
      return false;
    if (__isset.capabilityInfoList != rhs.__isset.capabilityInfoList)
      return false;
    else if (__isset.capabilityInfoList && !(capabilityInfoList == rhs.capabilityInfoList))
      return false;
    return true;
  }
  bool operator != (const QmCapabilitiesInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmCapabilitiesInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmCapabilitiesInfo &a, QmCapabilitiesInfo &b);

std::ostream& operator<<(std::ostream& out, const QmCapabilitiesInfo& obj);

typedef struct _QmCapabilitiesInfoResponse__isset {
  _QmCapabilitiesInfoResponse__isset() : capabilityInfo(false) {}
  bool capabilityInfo :1;
} _QmCapabilitiesInfoResponse__isset;

class QmCapabilitiesInfoResponse : public virtual ::apache::thrift::TBase {
 public:

  QmCapabilitiesInfoResponse(const QmCapabilitiesInfoResponse&);
  QmCapabilitiesInfoResponse& operator=(const QmCapabilitiesInfoResponse&);
  QmCapabilitiesInfoResponse() {
  }

  virtual ~QmCapabilitiesInfoResponse() noexcept;
  std::vector<QmCapabilitiesInfo>  capabilityInfo;

  _QmCapabilitiesInfoResponse__isset __isset;

  void __set_capabilityInfo(const std::vector<QmCapabilitiesInfo> & val);

  bool operator == (const QmCapabilitiesInfoResponse & rhs) const
  {
    if (__isset.capabilityInfo != rhs.__isset.capabilityInfo)
      return false;
    else if (__isset.capabilityInfo && !(capabilityInfo == rhs.capabilityInfo))
      return false;
    return true;
  }
  bool operator != (const QmCapabilitiesInfoResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmCapabilitiesInfoResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmCapabilitiesInfoResponse &a, QmCapabilitiesInfoResponse &b);

std::ostream& operator<<(std::ostream& out, const QmCapabilitiesInfoResponse& obj);

typedef struct _StreamingCapabilityCustomization__isset {
  _StreamingCapabilityCustomization__isset() : customParam(false) {}
  bool customParam :1;
} _StreamingCapabilityCustomization__isset;

class StreamingCapabilityCustomization : public virtual ::apache::thrift::TBase {
 public:

  StreamingCapabilityCustomization(const StreamingCapabilityCustomization&);
  StreamingCapabilityCustomization& operator=(const StreamingCapabilityCustomization&);
  StreamingCapabilityCustomization() : customParam() {
  }

  virtual ~StreamingCapabilityCustomization() noexcept;
  std::string customParam;

  _StreamingCapabilityCustomization__isset __isset;

  void __set_customParam(const std::string& val);

  bool operator == (const StreamingCapabilityCustomization & rhs) const
  {
    if (__isset.customParam != rhs.__isset.customParam)
      return false;
    else if (__isset.customParam && !(customParam == rhs.customParam))
      return false;
    return true;
  }
  bool operator != (const StreamingCapabilityCustomization &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const StreamingCapabilityCustomization & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(StreamingCapabilityCustomization &a, StreamingCapabilityCustomization &b);

std::ostream& operator<<(std::ostream& out, const StreamingCapabilityCustomization& obj);

typedef struct _StreamingCapabilityInfoType__isset {
  _StreamingCapabilityInfoType__isset() : capabilityId(false), name(false), persistenceType(false), available_streamingRatesMs(false), availableSamplingRates(false), default_samplingRateMs(false), customization(false) {}
  bool capabilityId :1;
  bool name :1;
  bool persistenceType :1;
  bool available_streamingRatesMs :1;
  bool availableSamplingRates :1;
  bool default_samplingRateMs :1;
  bool customization :1;
} _StreamingCapabilityInfoType__isset;

class StreamingCapabilityInfoType : public virtual ::apache::thrift::TBase {
 public:

  StreamingCapabilityInfoType(const StreamingCapabilityInfoType&);
  StreamingCapabilityInfoType& operator=(const StreamingCapabilityInfoType&);
  StreamingCapabilityInfoType() : capabilityId(0), name(), persistenceType((ResourcePersistenceType::type)0), default_samplingRateMs((SamplingRatesEnum::type)0) {
  }

  virtual ~StreamingCapabilityInfoType() noexcept;
  int32_t capabilityId;
  std::string name;
  ResourcePersistenceType::type persistenceType;
  std::vector<int32_t>  available_streamingRatesMs;
  std::vector<SamplingRatesEnum::type>  availableSamplingRates;
  SamplingRatesEnum::type default_samplingRateMs;
  StreamingCapabilityCustomization customization;

  _StreamingCapabilityInfoType__isset __isset;

  void __set_capabilityId(const int32_t val);

  void __set_name(const std::string& val);

  void __set_persistenceType(const ResourcePersistenceType::type val);

  void __set_available_streamingRatesMs(const std::vector<int32_t> & val);

  void __set_availableSamplingRates(const std::vector<SamplingRatesEnum::type> & val);

  void __set_default_samplingRateMs(const SamplingRatesEnum::type val);

  void __set_customization(const StreamingCapabilityCustomization& val);

  bool operator == (const StreamingCapabilityInfoType & rhs) const
  {
    if (__isset.capabilityId != rhs.__isset.capabilityId)
      return false;
    else if (__isset.capabilityId && !(capabilityId == rhs.capabilityId))
      return false;
    if (__isset.name != rhs.__isset.name)
      return false;
    else if (__isset.name && !(name == rhs.name))
      return false;
    if (__isset.persistenceType != rhs.__isset.persistenceType)
      return false;
    else if (__isset.persistenceType && !(persistenceType == rhs.persistenceType))
      return false;
    if (__isset.available_streamingRatesMs != rhs.__isset.available_streamingRatesMs)
      return false;
    else if (__isset.available_streamingRatesMs && !(available_streamingRatesMs == rhs.available_streamingRatesMs))
      return false;
    if (__isset.availableSamplingRates != rhs.__isset.availableSamplingRates)
      return false;
    else if (__isset.availableSamplingRates && !(availableSamplingRates == rhs.availableSamplingRates))
      return false;
    if (__isset.default_samplingRateMs != rhs.__isset.default_samplingRateMs)
      return false;
    else if (__isset.default_samplingRateMs && !(default_samplingRateMs == rhs.default_samplingRateMs))
      return false;
    if (__isset.customization != rhs.__isset.customization)
      return false;
    else if (__isset.customization && !(customization == rhs.customization))
      return false;
    return true;
  }
  bool operator != (const StreamingCapabilityInfoType &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const StreamingCapabilityInfoType & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(StreamingCapabilityInfoType &a, StreamingCapabilityInfoType &b);

std::ostream& operator<<(std::ostream& out, const StreamingCapabilityInfoType& obj);

typedef struct _QmLoopbackRequest__isset {
  _QmLoopbackRequest__isset() : msg(false) {}
  bool msg :1;
} _QmLoopbackRequest__isset;

class QmLoopbackRequest : public virtual ::apache::thrift::TBase {
 public:

  QmLoopbackRequest(const QmLoopbackRequest&);
  QmLoopbackRequest& operator=(const QmLoopbackRequest&);
  QmLoopbackRequest() : msg() {
  }

  virtual ~QmLoopbackRequest() noexcept;
  std::string msg;

  _QmLoopbackRequest__isset __isset;

  void __set_msg(const std::string& val);

  bool operator == (const QmLoopbackRequest & rhs) const
  {
    if (__isset.msg != rhs.__isset.msg)
      return false;
    else if (__isset.msg && !(msg == rhs.msg))
      return false;
    return true;
  }
  bool operator != (const QmLoopbackRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmLoopbackRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmLoopbackRequest &a, QmLoopbackRequest &b);

std::ostream& operator<<(std::ostream& out, const QmLoopbackRequest& obj);

typedef struct _QmLoopback__isset {
  _QmLoopback__isset() : status(false), msg(false) {}
  bool status :1;
  bool msg :1;
} _QmLoopback__isset;

class QmLoopback : public virtual ::apache::thrift::TBase {
 public:

  QmLoopback(const QmLoopback&);
  QmLoopback& operator=(const QmLoopback&);
  QmLoopback() : status((QmStatusType::type)0), msg() {
  }

  virtual ~QmLoopback() noexcept;
  QmStatusType::type status;
  std::string msg;

  _QmLoopback__isset __isset;

  void __set_status(const QmStatusType::type val);

  void __set_msg(const std::string& val);

  bool operator == (const QmLoopback & rhs) const
  {
    if (__isset.status != rhs.__isset.status)
      return false;
    else if (__isset.status && !(status == rhs.status))
      return false;
    if (__isset.msg != rhs.__isset.msg)
      return false;
    else if (__isset.msg && !(msg == rhs.msg))
      return false;
    return true;
  }
  bool operator != (const QmLoopback &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmLoopback & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmLoopback &a, QmLoopback &b);

std::ostream& operator<<(std::ostream& out, const QmLoopback& obj);

typedef struct _QmLoopbackResponse__isset {
  _QmLoopbackResponse__isset() : loopbackList(false) {}
  bool loopbackList :1;
} _QmLoopbackResponse__isset;

class QmLoopbackResponse : public virtual ::apache::thrift::TBase {
 public:

  QmLoopbackResponse(const QmLoopbackResponse&);
  QmLoopbackResponse& operator=(const QmLoopbackResponse&);
  QmLoopbackResponse() {
  }

  virtual ~QmLoopbackResponse() noexcept;
  std::vector<QmLoopback>  loopbackList;

  _QmLoopbackResponse__isset __isset;

  void __set_loopbackList(const std::vector<QmLoopback> & val);

  bool operator == (const QmLoopbackResponse & rhs) const
  {
    if (__isset.loopbackList != rhs.__isset.loopbackList)
      return false;
    else if (__isset.loopbackList && !(loopbackList == rhs.loopbackList))
      return false;
    return true;
  }
  bool operator != (const QmLoopbackResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QmLoopbackResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(QmLoopbackResponse &a, QmLoopbackResponse &b);

std::ostream& operator<<(std::ostream& out, const QmLoopbackResponse& obj);

typedef struct _StreamingCapabilitySelect__isset {
  _StreamingCapabilitySelect__isset() : capabilityNameOrId(false), select_streaming_rate_ms(false), broadcast(false), custom_select(false), enableOrDisable(false) {}
  bool capabilityNameOrId :1;
  bool select_streaming_rate_ms :1;
  bool broadcast :1;
  bool custom_select :1;
  bool enableOrDisable :1;
} _StreamingCapabilitySelect__isset;

class StreamingCapabilitySelect : public virtual ::apache::thrift::TBase {
 public:

  StreamingCapabilitySelect(const StreamingCapabilitySelect&);
  StreamingCapabilitySelect& operator=(const StreamingCapabilitySelect&);
  StreamingCapabilitySelect() : capabilityNameOrId(), select_streaming_rate_ms(0), broadcast(0), custom_select(), enableOrDisable(0) {
  }

  virtual ~StreamingCapabilitySelect() noexcept;
  std::string capabilityNameOrId;
  int32_t select_streaming_rate_ms;
  bool broadcast;
  std::string custom_select;
  bool enableOrDisable;

  _StreamingCapabilitySelect__isset __isset;

  void __set_capabilityNameOrId(const std::string& val);

  void __set_select_streaming_rate_ms(const int32_t val);

  void __set_broadcast(const bool val);

  void __set_custom_select(const std::string& val);

  void __set_enableOrDisable(const bool val);

  bool operator == (const StreamingCapabilitySelect & rhs) const
  {
    if (__isset.capabilityNameOrId != rhs.__isset.capabilityNameOrId)
      return false;
    else if (__isset.capabilityNameOrId && !(capabilityNameOrId == rhs.capabilityNameOrId))
      return false;
    if (__isset.select_streaming_rate_ms != rhs.__isset.select_streaming_rate_ms)
      return false;
    else if (__isset.select_streaming_rate_ms && !(select_streaming_rate_ms == rhs.select_streaming_rate_ms))
      return false;
    if (__isset.broadcast != rhs.__isset.broadcast)
      return false;
    else if (__isset.broadcast && !(broadcast == rhs.broadcast))
      return false;
    if (__isset.custom_select != rhs.__isset.custom_select)
      return false;
    else if (__isset.custom_select && !(custom_select == rhs.custom_select))
      return false;
    if (__isset.enableOrDisable != rhs.__isset.enableOrDisable)
      return false;
    else if (__isset.enableOrDisable && !(enableOrDisable == rhs.enableOrDisable))
      return false;
    return true;
  }
  bool operator != (const StreamingCapabilitySelect &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const StreamingCapabilitySelect & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(StreamingCapabilitySelect &a, StreamingCapabilitySelect &b);

std::ostream& operator<<(std::ostream& out, const StreamingCapabilitySelect& obj);

typedef struct _StreamingCapabilitySelectList__isset {
  _StreamingCapabilitySelectList__isset() : streamingCapabilitySelectList(false) {}
  bool streamingCapabilitySelectList :1;
} _StreamingCapabilitySelectList__isset;

class StreamingCapabilitySelectList : public virtual ::apache::thrift::TBase {
 public:

  StreamingCapabilitySelectList(const StreamingCapabilitySelectList&);
  StreamingCapabilitySelectList& operator=(const StreamingCapabilitySelectList&);
  StreamingCapabilitySelectList() {
  }

  virtual ~StreamingCapabilitySelectList() noexcept;
  std::vector<StreamingCapabilitySelect>  streamingCapabilitySelectList;

  _StreamingCapabilitySelectList__isset __isset;

  void __set_streamingCapabilitySelectList(const std::vector<StreamingCapabilitySelect> & val);

  bool operator == (const StreamingCapabilitySelectList & rhs) const
  {
    if (__isset.streamingCapabilitySelectList != rhs.__isset.streamingCapabilitySelectList)
      return false;
    else if (__isset.streamingCapabilitySelectList && !(streamingCapabilitySelectList == rhs.streamingCapabilitySelectList))
      return false;
    return true;
  }
  bool operator != (const StreamingCapabilitySelectList &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const StreamingCapabilitySelectList & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(StreamingCapabilitySelectList &a, StreamingCapabilitySelectList &b);

std::ostream& operator<<(std::ostream& out, const StreamingCapabilitySelectList& obj);

typedef struct _ProfilingRawRequestParams__isset {
  _ProfilingRawRequestParams__isset() : rpcName(false), request(false), timeout(false), capabilityName(false) {}
  bool rpcName :1;
  bool request :1;
  bool timeout :1;
  bool capabilityName :1;
} _ProfilingRawRequestParams__isset;

class ProfilingRawRequestParams : public virtual ::apache::thrift::TBase {
 public:

  ProfilingRawRequestParams(const ProfilingRawRequestParams&);
  ProfilingRawRequestParams& operator=(const ProfilingRawRequestParams&);
  ProfilingRawRequestParams() : rpcName(), request(), timeout(0), capabilityName() {
  }

  virtual ~ProfilingRawRequestParams() noexcept;
  std::string rpcName;
  std::string request;
  int32_t timeout;
  std::string capabilityName;

  _ProfilingRawRequestParams__isset __isset;

  void __set_rpcName(const std::string& val);

  void __set_request(const std::string& val);

  void __set_timeout(const int32_t val);

  void __set_capabilityName(const std::string& val);

  bool operator == (const ProfilingRawRequestParams & rhs) const
  {
    if (__isset.rpcName != rhs.__isset.rpcName)
      return false;
    else if (__isset.rpcName && !(rpcName == rhs.rpcName))
      return false;
    if (__isset.request != rhs.__isset.request)
      return false;
    else if (__isset.request && !(request == rhs.request))
      return false;
    if (__isset.timeout != rhs.__isset.timeout)
      return false;
    else if (__isset.timeout && !(timeout == rhs.timeout))
      return false;
    if (__isset.capabilityName != rhs.__isset.capabilityName)
      return false;
    else if (__isset.capabilityName && !(capabilityName == rhs.capabilityName))
      return false;
    return true;
  }
  bool operator != (const ProfilingRawRequestParams &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProfilingRawRequestParams & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProfilingRawRequestParams &a, ProfilingRawRequestParams &b);

std::ostream& operator<<(std::ostream& out, const ProfilingRawRequestParams& obj);

typedef struct _ProfilingRequestParams__isset {
  _ProfilingRequestParams__isset() : rpcName(false), jsonInput(false), returnConfig(false), timeout(false) {}
  bool rpcName :1;
  bool jsonInput :1;
  bool returnConfig :1;
  bool timeout :1;
} _ProfilingRequestParams__isset;

class ProfilingRequestParams : public virtual ::apache::thrift::TBase {
 public:

  ProfilingRequestParams(const ProfilingRequestParams&);
  ProfilingRequestParams& operator=(const ProfilingRequestParams&);
  ProfilingRequestParams() : rpcName(), jsonInput(), timeout(0) {
  }

  virtual ~ProfilingRequestParams() noexcept;
  std::string rpcName;
  std::string jsonInput;
  ProtoBufReturns returnConfig;
  int32_t timeout;

  _ProfilingRequestParams__isset __isset;

  void __set_rpcName(const std::string& val);

  void __set_jsonInput(const std::string& val);

  void __set_returnConfig(const ProtoBufReturns& val);

  void __set_timeout(const int32_t val);

  bool operator == (const ProfilingRequestParams & rhs) const
  {
    if (__isset.rpcName != rhs.__isset.rpcName)
      return false;
    else if (__isset.rpcName && !(rpcName == rhs.rpcName))
      return false;
    if (__isset.jsonInput != rhs.__isset.jsonInput)
      return false;
    else if (__isset.jsonInput && !(jsonInput == rhs.jsonInput))
      return false;
    if (__isset.returnConfig != rhs.__isset.returnConfig)
      return false;
    else if (__isset.returnConfig && !(returnConfig == rhs.returnConfig))
      return false;
    if (__isset.timeout != rhs.__isset.timeout)
      return false;
    else if (__isset.timeout && !(timeout == rhs.timeout))
      return false;
    return true;
  }
  bool operator != (const ProfilingRequestParams &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProfilingRequestParams & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProfilingRequestParams &a, ProfilingRequestParams &b);

std::ostream& operator<<(std::ostream& out, const ProfilingRequestParams& obj);

typedef struct _ProfilingBackendParams__isset {
  _ProfilingBackendParams__isset() : backendName(false) {}
  bool backendName :1;
} _ProfilingBackendParams__isset;

class ProfilingBackendParams : public virtual ::apache::thrift::TBase {
 public:

  ProfilingBackendParams(const ProfilingBackendParams&);
  ProfilingBackendParams& operator=(const ProfilingBackendParams&);
  ProfilingBackendParams() : backendName() {
  }

  virtual ~ProfilingBackendParams() noexcept;
  std::string backendName;

  _ProfilingBackendParams__isset __isset;

  void __set_backendName(const std::string& val);

  bool operator == (const ProfilingBackendParams & rhs) const
  {
    if (__isset.backendName != rhs.__isset.backendName)
      return false;
    else if (__isset.backendName && !(backendName == rhs.backendName))
      return false;
    return true;
  }
  bool operator != (const ProfilingBackendParams &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProfilingBackendParams & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProfilingBackendParams &a, ProfilingBackendParams &b);

std::ostream& operator<<(std::ostream& out, const ProfilingBackendParams& obj);

typedef struct _ProfilingLoopbackParams__isset {
  _ProfilingLoopbackParams__isset() : backendName(false), loopbackRequest(false) {}
  bool backendName :1;
  bool loopbackRequest :1;
} _ProfilingLoopbackParams__isset;

class ProfilingLoopbackParams : public virtual ::apache::thrift::TBase {
 public:

  ProfilingLoopbackParams(const ProfilingLoopbackParams&);
  ProfilingLoopbackParams& operator=(const ProfilingLoopbackParams&);
  ProfilingLoopbackParams() : backendName() {
  }

  virtual ~ProfilingLoopbackParams() noexcept;
  std::string backendName;
  QmLoopbackRequest loopbackRequest;

  _ProfilingLoopbackParams__isset __isset;

  void __set_backendName(const std::string& val);

  void __set_loopbackRequest(const QmLoopbackRequest& val);

  bool operator == (const ProfilingLoopbackParams & rhs) const
  {
    if (__isset.backendName != rhs.__isset.backendName)
      return false;
    else if (__isset.backendName && !(backendName == rhs.backendName))
      return false;
    if (__isset.loopbackRequest != rhs.__isset.loopbackRequest)
      return false;
    else if (__isset.loopbackRequest && !(loopbackRequest == rhs.loopbackRequest))
      return false;
    return true;
  }
  bool operator != (const ProfilingLoopbackParams &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProfilingLoopbackParams & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProfilingLoopbackParams &a, ProfilingLoopbackParams &b);

std::ostream& operator<<(std::ostream& out, const ProfilingLoopbackParams& obj);

typedef struct _ProfilingStartParams__isset {
  _ProfilingStartParams__isset() : backendName(false), capabilitySelect(false) {}
  bool backendName :1;
  bool capabilitySelect :1;
} _ProfilingStartParams__isset;

class ProfilingStartParams : public virtual ::apache::thrift::TBase {
 public:

  ProfilingStartParams(const ProfilingStartParams&);
  ProfilingStartParams& operator=(const ProfilingStartParams&);
  ProfilingStartParams() : backendName() {
  }

  virtual ~ProfilingStartParams() noexcept;
  std::string backendName;
  StreamingCapabilitySelect capabilitySelect;

  _ProfilingStartParams__isset __isset;

  void __set_backendName(const std::string& val);

  void __set_capabilitySelect(const StreamingCapabilitySelect& val);

  bool operator == (const ProfilingStartParams & rhs) const
  {
    if (__isset.backendName != rhs.__isset.backendName)
      return false;
    else if (__isset.backendName && !(backendName == rhs.backendName))
      return false;
    if (__isset.capabilitySelect != rhs.__isset.capabilitySelect)
      return false;
    else if (__isset.capabilitySelect && !(capabilitySelect == rhs.capabilitySelect))
      return false;
    return true;
  }
  bool operator != (const ProfilingStartParams &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProfilingStartParams & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProfilingStartParams &a, ProfilingStartParams &b);

std::ostream& operator<<(std::ostream& out, const ProfilingStartParams& obj);

typedef struct _ProfilingMetadataParams__isset {
  _ProfilingMetadataParams__isset() : rpcName(false), entityType(false) {}
  bool rpcName :1;
  bool entityType :1;
} _ProfilingMetadataParams__isset;

class ProfilingMetadataParams : public virtual ::apache::thrift::TBase {
 public:

  ProfilingMetadataParams(const ProfilingMetadataParams&);
  ProfilingMetadataParams& operator=(const ProfilingMetadataParams&);
  ProfilingMetadataParams() : rpcName(), entityType((ProtoBufPacketType::type)0) {
  }

  virtual ~ProfilingMetadataParams() noexcept;
  std::string rpcName;
  ProtoBufPacketType::type entityType;

  _ProfilingMetadataParams__isset __isset;

  void __set_rpcName(const std::string& val);

  void __set_entityType(const ProtoBufPacketType::type val);

  bool operator == (const ProfilingMetadataParams & rhs) const
  {
    if (__isset.rpcName != rhs.__isset.rpcName)
      return false;
    else if (__isset.rpcName && !(rpcName == rhs.rpcName))
      return false;
    if (__isset.entityType != rhs.__isset.entityType)
      return false;
    else if (__isset.entityType && !(entityType == rhs.entityType))
      return false;
    return true;
  }
  bool operator != (const ProfilingMetadataParams &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProfilingMetadataParams & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProfilingMetadataParams &a, ProfilingMetadataParams &b);

std::ostream& operator<<(std::ostream& out, const ProfilingMetadataParams& obj);

} // namespace

#endif
