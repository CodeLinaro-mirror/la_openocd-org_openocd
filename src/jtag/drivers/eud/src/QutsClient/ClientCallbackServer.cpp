/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "ClientCallbackServer.h"
namespace ClientCallbackServer
{
	ClientCallbackServer::ClientCallbackServer()
	{
		clearCallback();
	};

	ClientCallbackServer::~ClientCallbackServer()
	{
		clearCallback();
	};


	void ClientCallbackServer::onMessage(const Uts::MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description)
	{
		try {
			if (m_messageCallback != nullptr) {
				m_messageCallback(level, location, title, description);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onDeviceConnected(const::Uts::DeviceInfo& deviceInfo)
	{
		try {
			if (m_deviceConnectedCallback != nullptr) {
				m_deviceConnectedCallback(deviceInfo);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onDeviceDisconnected(const::Uts::DeviceInfo& deviceInfo)
	{
		try {
			if (m_deviceDisconnectedCallback != nullptr) {
				m_deviceDisconnectedCallback(deviceInfo);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onDeviceModeChange(const int64_t deviceHandle, const::Uts::DeviceMode::type newMode)
	{
		try {
			if (m_deviceModeChangeCallback != nullptr) {
				m_deviceModeChangeCallback(deviceHandle, newMode);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onProtocolAdded(const::Uts::DeviceInfo& deviceInfo, const::Uts::ProtocolInfo& protocolInfo)
	{
		try {
			if (m_protocolAddedCallback != nullptr) {
				m_protocolAddedCallback(deviceInfo, protocolInfo);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onProtocolRemoved(const::Uts::DeviceInfo& deviceInfo, const::Uts::ProtocolInfo& protocolInfo)
	{
		try {
			if (m_protocolRemovedCallback != nullptr) {
				m_protocolRemovedCallback(deviceInfo, protocolInfo);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onProtocolStateChange(const int64_t protocolHandle, const::Uts::ProtocolState::type newState)
	{
		try {
			if (m_protocolStateChangeCallback != nullptr) {
				m_protocolStateChangeCallback(protocolHandle, newState);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onProtocolFlowControlStatusChange(const int64_t protocolHandle, const::Uts::Direction::type dir, const::Uts::FlowControlStatus::type newStatus)
	{
		try {
			if (m_protocolFlowControlStatusChangeCallback != nullptr) {
				m_protocolFlowControlStatusChangeCallback(protocolHandle, dir, newStatus);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onProtocolLockStatusChange(const int64_t protocolHandle, const::Uts::LockStatus& newStatus)
	{
		try {
			if (m_protocolLockStatusChangeCallback != nullptr) {
				m_protocolLockStatusChangeCallback(protocolHandle, newStatus);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const::Uts::MbnDownloadStatus& newStatus)
	{
		try {
			if (m_protocolMbnDownloadStatusChangeCallback != nullptr) {
				m_protocolMbnDownloadStatusChangeCallback(protocolHandle, newStatus);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onClientCloseRequest(const::Uts::ClientCloseReason& closeReason)
	{
		try {
			if (m_clientCloseRequestCallback != nullptr) {
				m_clientCloseRequestCallback(closeReason);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid)
	{
		try {
			if (m_missingQShrinkHashFileCallback != nullptr) {
				m_missingQShrinkHashFileCallback(protocolHandle, missingFileGuid);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid)
	{
		try {
			if (m_logSessionMissingQShrinkHashFileCallback != nullptr) {
				m_logSessionMissingQShrinkHashFileCallback(logSessionInstance, protocolHandle, missingFileGuid);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId)
	{
		try {
			if (m_asyncResponseCallback != nullptr) {
				m_asyncResponseCallback(protocolHandle, transactionId);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onDataQueueUpdated(const std::string& queueName, const int32_t queueSize)
	{
		try {
			if (m_dataQueueUpdatedCallback != nullptr) {
				m_dataQueueUpdatedCallback(queueName, queueSize);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished)
	{
		try {
			if (m_dataViewUpdatedCallback != nullptr) {
				m_dataViewUpdatedCallback(viewName, viewSize, finished);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle)
	{
		try {
			if (m_serviceAvailableCallback != nullptr) {
				m_serviceAvailableCallback(serviceName, deviceHandle);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onServiceEnded(const std::string& serviceName, const int64_t deviceHandle)
	{
		try {
			if (m_serviceEndedCallback != nullptr) {
				m_serviceEndedCallback(serviceName, deviceHandle);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription)
	{
		try {
			if (m_serviceEventCallback != nullptr) {
				m_serviceEventCallback(serviceName, eventId, eventDescription);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription)
	{
		try {
			if (m_imageManagementServiceEventCallback != nullptr) {
				m_imageManagementServiceEventCallback(serviceName, deviceHandle, protocolHandle, eventId, eventDescription);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription)
	{
		try {
			if (m_deviceConfigServiceEventCallback != nullptr) {
				m_deviceConfigServiceEventCallback(serviceName, deviceHandle, protocolHandle, eventId, eventDescription);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onQShrinkStateUpdated(const int64_t protocolHandle, const::Uts::QShrink4DownloadState::type newState)
	{
		try {
			if (m_qShrinkStateUpdatedCallback != nullptr) {
				m_qShrinkStateUpdatedCallback(protocolHandle, newState);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const::Uts::KeyInfo& keyInfo)
	{
		try {
			if (m_decryptionKeyStatusUpdateCallback != nullptr) {
				m_decryptionKeyStatusUpdateCallback(protocolHandle, keyInfo);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const::Uts::KeyInfo& keyInfo)
	{
		try {
			if (m_logSessionDecryptionKeyStatusUpdateCallback != nullptr) {
				m_logSessionDecryptionKeyStatusUpdateCallback(logSesssionInstance, protocolHandle, keyInfo);
			}
		}
		catch (...) {

		}
	}

	void ClientCallbackServer::clearCallback()
	{
		m_messageCallback = nullptr;
		m_deviceConnectedCallback = nullptr;
		m_deviceDisconnectedCallback = nullptr;
		m_deviceModeChangeCallback = nullptr;
		m_protocolAddedCallback = nullptr;
		m_protocolRemovedCallback = nullptr;
		m_protocolStateChangeCallback = nullptr;
		m_protocolFlowControlStatusChangeCallback = nullptr;
		m_protocolLockStatusChangeCallback = nullptr;
		m_protocolMbnDownloadStatusChangeCallback = nullptr;
		m_clientCloseRequestCallback = nullptr;
		m_missingQShrinkHashFileCallback = nullptr;
		m_logSessionMissingQShrinkHashFileCallback = nullptr;
		m_asyncResponseCallback = nullptr;
		m_dataQueueUpdatedCallback = nullptr;
		m_dataViewUpdatedCallback = nullptr;
		m_serviceAvailableCallback = nullptr;
		m_serviceEndedCallback = nullptr;
		m_serviceEventCallback = nullptr;
		m_imageManagementServiceEventCallback = nullptr;
		m_deviceConfigServiceEventCallback = nullptr;
		m_qShrinkStateUpdatedCallback = nullptr;
		m_decryptionKeyStatusUpdateCallback = nullptr;
		m_logSessionDecryptionKeyStatusUpdateCallback = nullptr;
	}

	void ClientCallbackServer::setMessageCallback(const MessageCallback& callback)
	{
		if (callback != nullptr) {
			m_messageCallback = callback;
		}
	}

	void ClientCallbackServer::setDeviceConnectedCallback(const DeviceConnectedCallback& callback)
	{
		if (callback != nullptr) {
			m_deviceConnectedCallback = callback;
		}
	}

	void ClientCallbackServer::setDeviceDisconnectedCallback(const DeviceDisconnectedCallback& callback)
	{
		if (callback != nullptr) {
			m_deviceDisconnectedCallback = callback;
		}
	}

	void ClientCallbackServer::setDeviceModeChangeCallback(const DeviceModeChangeCallback& callback)
	{
		if (callback != nullptr) {
			m_deviceModeChangeCallback = callback;
		}
	}

	void ClientCallbackServer::setProtocolAddedCallback(const ProtocolAddedCallback& callback)
	{
		if (callback != nullptr) {
			m_protocolAddedCallback = callback;
		}
	}

	void ClientCallbackServer::setProtocolRemovedCallback(const ProtocolRemovedCallback& callback)
	{
		if (callback != nullptr) {
			m_protocolRemovedCallback = callback;
		}
	}

	void ClientCallbackServer::setProtocolStateChangeCallback(const ProtocolStateChangeCallback& callback)
	{
		if (callback != nullptr) {
			m_protocolStateChangeCallback = callback;
		}
	}

	void ClientCallbackServer::setProtocolFlowControlStatusChangeCallback(const ProtocolFlowControlStatusChangeCallback& callback)
	{
		if (callback != nullptr) {
			m_protocolFlowControlStatusChangeCallback = callback;
		}
	}

	void ClientCallbackServer::setProtocolLockStatusChangeCallback(const ProtocolLockStatusChangeCallback& callback)
	{
		if (callback != nullptr) {
			m_protocolLockStatusChangeCallback = callback;
		}
	}

	void ClientCallbackServer::setProtocolMbnDownloadStatusChangeCallback(const ProtocolMbnDownloadStatusChangeCallback& callback)
	{
		if (callback != nullptr) {
			m_protocolMbnDownloadStatusChangeCallback = callback;
		}
	}

	void ClientCallbackServer::setClientCloseRequestCallback(const ClientCloseRequestCallback& callback)
	{
		if (callback != nullptr) {
			m_clientCloseRequestCallback = callback;
		}
	}

	void ClientCallbackServer::setMissingQShrinkHashFileCallback(const MissingQShrinkHashFileCallback& callback)
	{
		if (callback != nullptr) {
			m_missingQShrinkHashFileCallback = callback;
		}
	}

	void ClientCallbackServer::setLogSessionMissingQShrinkHashFileCallback(const LogSessionMissingQShrinkHashFileCallback& callback)
	{
		if (callback != nullptr) {
			m_logSessionMissingQShrinkHashFileCallback = callback;
		}
	}

	void ClientCallbackServer::setAsyncResponseCallback(const AsyncResponseCallback& callback)
	{
		if (callback != nullptr) {
			m_asyncResponseCallback = callback;
		}
	}

	void ClientCallbackServer::setDataQueueUpdatedCallback(const DataQueueUpdatedCallback& callback)
	{
		if (callback != nullptr) {
			m_dataQueueUpdatedCallback = callback;
		}
	}

	void ClientCallbackServer::setDataViewUpdatedCallback(const DataViewUpdatedCallback& callback)
	{
		if (callback != nullptr) {
			m_dataViewUpdatedCallback = callback;
		}
	}

	void ClientCallbackServer::setServiceAvailableCallback(const ServiceAvailableCallback& callback)
	{
		if (callback != nullptr) {
			m_serviceAvailableCallback = callback;
		}
	}

	void ClientCallbackServer::setServiceEndedCallback(const ServiceEndedCallback& callback)
	{
		if (callback != nullptr) {
			m_serviceEndedCallback = callback;
		}
	}

	void ClientCallbackServer::setServiceEventCallback(const ServiceEventCallback& callback)
	{
		if (callback != nullptr) {
			m_serviceEventCallback = callback;
		}
	}

	void ClientCallbackServer::setImageManagementServiceEventCallback(const ImageManagementServiceEventCallback& callback)
	{
		if (callback != nullptr) {
			m_imageManagementServiceEventCallback = callback;
		}
	}

	void ClientCallbackServer::setDeviceConfigServiceEventCallback(const DeviceConfigServiceEventCallback& callback)
	{
		if (callback != nullptr) {
			m_deviceConfigServiceEventCallback = callback;
		}
	}

	void ClientCallbackServer::setQShrinkStateUpdatedCallback(const QShrinkStateUpdatedCallback& callback)
	{
		if (callback != nullptr) {
			m_qShrinkStateUpdatedCallback = callback;
		}
	}

	void ClientCallbackServer::setDecryptionKeyStatusUpdateCallback(const DecryptionKeyStatusUpdateCallback& callback)
	{
		if (callback != nullptr) {
			m_decryptionKeyStatusUpdateCallback = callback;
		}
	}

	void ClientCallbackServer::setLogSessionDecryptionKeyStatusUpdateCallback(const LogSessionDecryptionKeyStatusUpdateCallback& callback)
	{
		if (callback != nullptr) {
			m_logSessionDecryptionKeyStatusUpdateCallback = callback;
		}
	}
}