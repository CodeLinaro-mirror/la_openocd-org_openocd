/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#pragma once

#if 0
#include "ThriftGenFiles/ClientCallback.h"
#else
#include "ClientCallback.h"
#endif

namespace ClientCallbackServer
{
	class ClientCallbackServer : public Uts::ClientCallbackIf
	{
	public:
		ClientCallbackServer();
		virtual ~ClientCallbackServer();

		// Define Callback Function
		typedef void(*MessageCallback)(const ::Uts::MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description);
		typedef void(*DeviceConnectedCallback)(const ::Uts::DeviceInfo& deviceInfo);
		typedef void(*DeviceDisconnectedCallback)(const ::Uts::DeviceInfo& deviceInfo);
		typedef void(*DeviceModeChangeCallback)(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode);
		typedef void(*ProtocolAddedCallback)(const ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
		typedef void(*ProtocolRemovedCallback)(const ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
		typedef void(*ProtocolStateChangeCallback)(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState);
		typedef void(*ProtocolFlowControlStatusChangeCallback)(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus);
		typedef void(*ProtocolLockStatusChangeCallback)(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus);
		typedef void(*ProtocolMbnDownloadStatusChangeCallback)(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus);
		typedef void(*ClientCloseRequestCallback)(const  ::Uts::ClientCloseReason& closeReason);
		typedef void(*MissingQShrinkHashFileCallback)(const int64_t protocolHandle, const std::string& missingFileGuid);
		typedef void(*LogSessionMissingQShrinkHashFileCallback)(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid);
		typedef void(*AsyncResponseCallback)(const int64_t protocolHandle, const int64_t transactionId);
		typedef void(*DataQueueUpdatedCallback)(const std::string& queueName, const int32_t queueSize);
		typedef void(*DataViewUpdatedCallback)(const std::string& viewName, const int32_t viewSize, const bool finished);
		typedef void(*ServiceAvailableCallback)(const std::string& serviceName, const int64_t deviceHandle);
		typedef void(*ServiceEndedCallback)(const std::string& serviceName, const int64_t deviceHandle);
		typedef void(*ServiceEventCallback)(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription);
		typedef void(*ImageManagementServiceEventCallback)(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
		typedef void(*DeviceConfigServiceEventCallback)(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
		typedef void(*QShrinkStateUpdatedCallback)(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState);
		typedef void(*DecryptionKeyStatusUpdateCallback)(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);
		typedef void(*LogSessionDecryptionKeyStatusUpdateCallback)(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);

		void clearCallback();

		// Register Callback Function
		void setMessageCallback(const MessageCallback& callback);
		void setDeviceConnectedCallback(const DeviceConnectedCallback& callback);
		void setDeviceDisconnectedCallback(const DeviceDisconnectedCallback& callback);
		void setDeviceModeChangeCallback(const DeviceModeChangeCallback& callback);
		void setProtocolAddedCallback(const ProtocolAddedCallback& callback);
		void setProtocolRemovedCallback(const ProtocolRemovedCallback& callback);
		void setProtocolStateChangeCallback(const ProtocolStateChangeCallback& callback);
		void setProtocolFlowControlStatusChangeCallback(const ProtocolFlowControlStatusChangeCallback& callback);
		void setProtocolLockStatusChangeCallback(const ProtocolLockStatusChangeCallback& callback);
		void setProtocolMbnDownloadStatusChangeCallback(const ProtocolMbnDownloadStatusChangeCallback& callback);
		void setClientCloseRequestCallback(const ClientCloseRequestCallback& callback);
		void setMissingQShrinkHashFileCallback(const MissingQShrinkHashFileCallback& callback);
		void setLogSessionMissingQShrinkHashFileCallback(const LogSessionMissingQShrinkHashFileCallback& callback);
		void setAsyncResponseCallback(const AsyncResponseCallback& callback);
		void setDataQueueUpdatedCallback(const DataQueueUpdatedCallback& callback);
		void setDataViewUpdatedCallback(const DataViewUpdatedCallback& callback);
		void setServiceAvailableCallback(const ServiceAvailableCallback& callback);
		void setServiceEndedCallback(const ServiceEndedCallback& callback);
		void setServiceEventCallback(const ServiceEventCallback& callback);
		void setImageManagementServiceEventCallback(const ImageManagementServiceEventCallback& callback);
		void setDeviceConfigServiceEventCallback(const DeviceConfigServiceEventCallback& callback);
		void setQShrinkStateUpdatedCallback(const QShrinkStateUpdatedCallback& callback);
		void setDecryptionKeyStatusUpdateCallback(const DecryptionKeyStatusUpdateCallback& callback);
		void setLogSessionDecryptionKeyStatusUpdateCallback(const LogSessionDecryptionKeyStatusUpdateCallback& callback);

		// Functions from ClientCallback.thrift
		void onMessage(const ::Uts::MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description);
		void onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo);
		void onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo);
		void onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode);
		void onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
		void onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo);
		void onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState);
		void onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus);
		void onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus);
		void onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus);
		void onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason);
		void onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid);
		void onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid);
		void onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId);
		void onDataQueueUpdated(const std::string& queueName, const int32_t queueSize);
		void onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished);
		void onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle);
		void onServiceEnded(const std::string& serviceName, const int64_t deviceHandle);
		void onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription);
		void onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
		void onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription);
		void onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState);
		void onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);
		void onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo);

	private:
		MessageCallback m_messageCallback;
		DeviceConnectedCallback m_deviceConnectedCallback;
		DeviceDisconnectedCallback m_deviceDisconnectedCallback;
		DeviceModeChangeCallback m_deviceModeChangeCallback;
		ProtocolAddedCallback m_protocolAddedCallback;
		ProtocolRemovedCallback m_protocolRemovedCallback;
		ProtocolStateChangeCallback m_protocolStateChangeCallback;
		ProtocolFlowControlStatusChangeCallback m_protocolFlowControlStatusChangeCallback;
		ProtocolLockStatusChangeCallback m_protocolLockStatusChangeCallback;
		ProtocolMbnDownloadStatusChangeCallback m_protocolMbnDownloadStatusChangeCallback;
		ClientCloseRequestCallback m_clientCloseRequestCallback;
		MissingQShrinkHashFileCallback m_missingQShrinkHashFileCallback;
		LogSessionMissingQShrinkHashFileCallback m_logSessionMissingQShrinkHashFileCallback;
		AsyncResponseCallback m_asyncResponseCallback;
		DataQueueUpdatedCallback m_dataQueueUpdatedCallback;
		DataViewUpdatedCallback m_dataViewUpdatedCallback;
		ServiceAvailableCallback m_serviceAvailableCallback;
		ServiceEndedCallback m_serviceEndedCallback;
		ServiceEventCallback m_serviceEventCallback;
		ImageManagementServiceEventCallback m_imageManagementServiceEventCallback;
		DeviceConfigServiceEventCallback m_deviceConfigServiceEventCallback;
		QShrinkStateUpdatedCallback m_qShrinkStateUpdatedCallback;
		DecryptionKeyStatusUpdateCallback m_decryptionKeyStatusUpdateCallback;
		LogSessionDecryptionKeyStatusUpdateCallback m_logSessionDecryptionKeyStatusUpdateCallback;
	};
}

