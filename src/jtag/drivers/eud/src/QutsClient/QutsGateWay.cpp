/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include <iostream>
#include <sstream>

#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/operations.hpp>
#include <chrono>
// dummy comment

#if 0
#include "..\QutsClient\ClientCallbackServer.h"
#include "../QutsClient/QutsClient.h"
#include "../QutsClient/TemplateManagerService.h"
#include "../QutsClient/TemplateManagerService.cpp"
#include "../QutsClient/ThriftGenFiles/EudService.h"
#include "../QutsClient/ThriftGenFiles/EudService_constants.h"
#include "../QutsClient/ThriftGenFiles/EudSwdService.h"
#include "../QutsClient/ThriftGenFiles/EudSwdService_constants.h"
#include "../QutsClient/ThriftGenFiles/EudCtlService.h"
#include "../QutsClient/ThriftGenFiles/EudCtlService_constants.h"
#include "../QutsClient/ThriftGenFiles/DiagService.h"
#include "../QutsClient/ThriftGenFiles/DiagService_constants.h"
#else
#include "ClientCallbackServer.h"
#include "QutsClient.h"
#include "TemplateManagerService.h"
#include "TemplateManagerService.cpp"
#include "EudService.h"
#include "EudService_constants.h"
#include "EudSwdService.h"
#include "EudSwdService_types.h"
#include "EudSwdService_constants.h"
#include "EudCtlService.h"
#include "EudCtlService_constants.h"
#include "DiagService.h"
#include "DiagService_constants.h"
#endif

#define QUTS_GATEWAY_DEBUG 0
#define QUTS_GATEWAY_TIME 0

Uts::ClientInfo clientInfo;
std::shared_ptr<QutsClient::QutsClient> client = nullptr;
std::shared_ptr<QutsClient::QutsClient> client2 = nullptr;
Uts::ProtocolInfo protInfo;
std::shared_ptr<Uts::EudCtlServiceClient> eudCtlServiceClient;
std::shared_ptr<Uts::EudSwdServiceClient> eudSwdServiceClient;
using namespace std;
#if QUTS_GATEWAY_TIME
using namespace std::chrono;
#endif

extern "C" int EudInitWrapper(void);
extern "C" int EudSWDInitWrapper(void);
extern "C" int SwdReadWrapper(uint32_t, uint32_t, uint32_t *);
extern "C" int SwdWriteWrapper(uint32_t, uint32_t, uint32_t);
extern "C" int EudQuitWrapper(void);
extern "C" int BitbangWrapper(uint32_t, uint32_t *);
extern "C" void Jtag_to_SWD();
extern "C" int SwdFlush();
void updatePointers();

std::vector<uint32_t *> readPtrs;
Uts::BfrTckr bfrObj;

void onMessage(Uts::MessageLevel::type level, const std::string &location, const std::string &title, const std::string &description)
{
#if QUTS_GATEWAY_DEBUG
    std::cout << "onMessage: level->" << level << ", location->" << location << ", title->" << title << ", description->" << description << std::endl;
#endif
}

void onDeviceConnected(const ::Uts::DeviceInfo &deviceInfo)
{
#if QUTS_GATEWAY_DEBUG
    std::cout << "onDeviceConnected: adbSerialNumber->" << deviceInfo.adbSerialNumber << ", description->" << deviceInfo.description << ", deviceHandle->" << deviceInfo.deviceHandle << ", edlChipId->" << deviceInfo.edlChipId << ", location->" << deviceInfo.location << ", pid->" << deviceInfo.pid << std::endl;
#endif
}

void onDeviceDisconnected(const ::Uts::DeviceInfo &deviceInfo)
{
#if QUTS_GATEWAY_DEBUG
    std::cout << "onDeviceDisconnected: adbSerialNumber->" << deviceInfo.adbSerialNumber << ", description->" << deviceInfo.description << ", deviceHandle->" << deviceInfo.deviceHandle << ", edlChipId->" << deviceInfo.edlChipId << ", location->" << deviceInfo.location << ", pid->" << deviceInfo.pid << std::endl;
#endif
}

std::shared_ptr<QutsClient::QutsClient> GetQutsClient(Uts::ClientInfo &clientInfo, const std::string &serviceStr, Uts::ProtocolInfo &protInfo)
{
    std::shared_ptr<QutsClient::QutsClient> client;

    client = std::shared_ptr<QutsClient::QutsClient>(new QutsClient::QutsClient(clientInfo, "localhost", 50089, false));
    if (client != nullptr && client.get() != nullptr)
    {
        client->setMessageCallback(onMessage); // set callback
        client->setDeviceConnectedCallback(onDeviceConnected);
        client->setDeviceDisconnectedCallback(onDeviceDisconnected);

        std::shared_ptr<Uts::DeviceManagerClient> devMngrClient = client->getDeviceManager();
        std::shared_ptr<Uts::UtilityServiceClient> utilityClient = client->getUtilityService();

        std::vector<Uts::DeviceInfo> dInfos;
        Uts::DeviceInfo dInfo;

        devMngrClient->getDeviceList(dInfos);
        std::vector<Uts::DeviceInfo>::iterator it;
        for (it = dInfos.begin(); it != dInfos.end(); it++)
        {
            // std::cout << it->description << std::endl;
            // size_t found = it->description.find("EUD Control");  //EUD SWD
            size_t found = it->description.find(serviceStr); // EUD SWD
            if (found != std::string::npos)
            {
                std::cout << it->description << std::endl;
                dInfo = *it;
                break;
            }
        }

        std::vector<Uts::ProtocolInfo> pInfos;
        // Uts::ProtocolInfo pInfo;
        // get eud protocol
        devMngrClient->getProtocolList(pInfos, dInfo.deviceHandle);
        std::vector<Uts::ProtocolInfo>::iterator itp;
        for (itp = pInfos.begin(); itp != pInfos.end(); itp++)
        {
            // std::cout << itp->description << std::endl;
            // size_t found = itp->description.find("EUD Control");  //EUD SWD
            size_t found = itp->description.find(serviceStr); // EUD SWD
            if (found != std::string::npos)
            {
                std::cout << itp->description << std::endl;
                protInfo = *itp;
                break;
            }
        }

#if QUTS_GATEWAY_DEBUG
        std::cout << "Protocol Info: device handle:" << protInfo.deviceHandle << ", protocol handle:" << protInfo.protocolHandle << ", protocol type:" << protInfo.protocolType << ", protocol state:" << protInfo.protocolState << ", protocol description:" << protInfo.description << std::endl;
#endif
    }
    else
    {
        client = nullptr;
    }

    return client;
}

std::shared_ptr<Uts::EudCtlServiceClient> CreateEUDCTLServiceClient(std::shared_ptr<QutsClient::QutsClient> &client, Uts::ProtocolInfo &protInfo)
{
    std::shared_ptr<Uts::EudCtlServiceClient> eudCtlServiceClient = nullptr;

    if (client != nullptr)
    {
        Uts::EudCtlServiceConstants eudCtlServiceConstants;

        eudCtlServiceClient = std::shared_ptr<Uts::EudCtlServiceClient>(new Uts::EudCtlServiceClient(
            client->createService(eudCtlServiceConstants.EUD_CTL_SERVICE_NAME, protInfo.deviceHandle)));
    }

    return eudCtlServiceClient;
}

std::shared_ptr<Uts::EudSwdServiceClient> CreateEUDSWDServiceClient(std::shared_ptr<QutsClient::QutsClient> &client, Uts::ProtocolInfo &protInfo)
{
    std::shared_ptr<Uts::EudSwdServiceClient> eudSwdServiceClient = nullptr;

    if (client != nullptr)
    {
        Uts::EudSwdServiceConstants eudSwdServiceConstants;

        eudSwdServiceClient = std::shared_ptr<Uts::EudSwdServiceClient>(new Uts::EudSwdServiceClient(
            client->createService(eudSwdServiceConstants.EUD_SWD_SERVICE_NAME, protInfo.deviceHandle)));
    }

    return eudSwdServiceClient;
}

extern "C" int EudInitWrapper(void)
{
    clientInfo.__set_clientName("QutsGateWay");
    clientInfo.__set_appName("QutsGateWay");
#if QUTS_GATEWAY_TIME
    auto start = high_resolution_clock::now();
#endif
    client = GetQutsClient(clientInfo, "EUD Control", protInfo);

#if QUTS_GATEWAY_TIME
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by GetQutsClient EUD ctrl: "
         << duration.count() << " milliseconds" << endl;
#endif
    if (client != nullptr)
    {
#if QUTS_GATEWAY_TIME
        start = high_resolution_clock::now();
#endif
        eudCtlServiceClient = CreateEUDCTLServiceClient(client, protInfo);

#if QUTS_GATEWAY_TIME
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken by CreateEUDCTLServiceClient: "
             << duration.count() << " milliseconds" << endl;
#endif
        if (eudCtlServiceClient != nullptr && eudCtlServiceClient.get() != nullptr)
        {
#if QUTS_GATEWAY_DEBUG
            std::cout << " initializeServiceByProtocol before with protocolHandle: " << protInfo.protocolHandle << ", device handle:" << protInfo.deviceHandle << std::endl;
#endif

#if QUTS_GATEWAY_TIME
            start = high_resolution_clock::now();
#endif
            ::Uts::ErrorCode::type errCode = eudCtlServiceClient->initializeServiceByProtocol(protInfo.protocolHandle);

#if QUTS_GATEWAY_TIME
            stop = high_resolution_clock::now();
            duration = duration_cast<milliseconds>(stop - start);
            cout << "Time taken by initializeServiceByProtocol: "
                 << duration.count() << " milliseconds" << endl;
#endif
            if (errCode == ::Uts::ErrorCode::DEVICE_NO_ERROR)
            {
#if QUTS_GATEWAY_DEBUG
                std::cout << " initializeServiceByProtocol affter with protocolHandle: " << protInfo.protocolHandle << ", device handle:" << protInfo.deviceHandle << std::endl;
#endif

#if QUTS_GATEWAY_TIME
                start = high_resolution_clock::now();
#endif
                // EUD CTL plugin calls
                errCode = eudCtlServiceClient->enableSwd();

#if QUTS_GATEWAY_TIME
                stop = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop - start);
                cout << "Time taken by enableSwd: "
                     << duration.count() << " milliseconds" << endl;
#endif

                if (errCode == ::Uts::ErrorCode::DEVICE_NO_ERROR)
                {
#if QUTS_GATEWAY_DEBUG
                    std::cout << " SWD enablement SUCCESSFUL!!" << std::endl;
#endif
                }
                else
                {
#if QUTS_GATEWAY_DEBUG
                    std::cout << " SWD enablement FAILED!! ErrorCode = " << errCode << std::endl;
#endif
                }
                Sleep(7000); // TBD
#if QUTS_GATEWAY_TIME
                start = high_resolution_clock::now();
#endif
                client2 = GetQutsClient(clientInfo, "EUD SWD", protInfo);
#if QUTS_GATEWAY_TIME
                stop = high_resolution_clock::now();
                duration = duration_cast<milliseconds>(stop - start);
                cout << "Time taken by GetQutsClient EUD SWD: "
                     << duration.count() << " milliseconds" << endl;
#endif
                if (client2 != nullptr)
                {
#if QUTS_GATEWAY_TIME
                    start = high_resolution_clock::now();
#endif

                    eudSwdServiceClient = CreateEUDSWDServiceClient(client2, protInfo);

#if QUTS_GATEWAY_TIME
                    stop = high_resolution_clock::now();
                    duration = duration_cast<milliseconds>(stop - start);
                    cout << "Time taken by CreateEUDSWDServiceClient: "
                         << duration.count() << " milliseconds" << endl;
#endif
                    if (eudSwdServiceClient != nullptr && eudSwdServiceClient.get() != nullptr)
                    {
#if QUTS_GATEWAY_DEBUG
                        std::cout << " initializeServiceByProtocol before with protocolHandle: " << protInfo.protocolHandle << ", device handle:" << protInfo.deviceHandle << std::endl;
#endif

#if QUTS_GATEWAY_TIME
                        start = high_resolution_clock::now();
#endif
                        ::Uts::ErrorCode::type errCode = eudSwdServiceClient->initializeServiceByProtocol(protInfo.protocolHandle);
#if QUTS_GATEWAY_TIME
                        stop = high_resolution_clock::now();
                        duration = duration_cast<milliseconds>(stop - start);
                        cout << "Time taken by initializeServiceByProtocol: "
                             << duration.count() << " milliseconds" << endl;
#endif
                    }
                    else
                    {
                        return -1;
                    }
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                std::cout << "CtlService error "<<errCode<<"\n";
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

    return 0;
}

extern "C" int EudSWDInitWrapper(void)
{
    int ret = eudSwdServiceClient->InitSWD(0);
    // cout<<" Eud init retval "<<ret<<endl;
    if(!ret)
    {
        cout<<"License check failed for SWD Service";
        exit(10);
        return -1;
    }
    return 0;
}

void updatePointers()
{
    // std::cout << "Qutsgateway updateptrs call \n";
    int64_t temp = 0;
    uint32_t *ptr = NULL;
    std::stringstream ss;
    for (int i = 0; i < readPtrs.size(); i++)
    {
        
        // std::cout << "Qutsgateway updateptrs fill "<<i<<endl;
        // std::cout << "QutsRead :" << std::hex << bfrObj.bfrVector[i] << " "
        //           << "\n";
#if QUTS_GATEWAY_DEBUG
        std::cout << "QutsRead :" << std::hex << bfrObj.bfrVector[i] << " "
                  << "\n";
#endif
        ss << std::hex << bfrObj.bfrVector[i];
        ss >> temp;
        *(readPtrs[i]) = static_cast<uint32_t>(temp);
        ss.clear();
    }
    readPtrs.clear();
    // std::cout << "Qutsgateway updateptrs return \n";
}

extern "C" int SwdFlush()
{
    // std::cout << "Qutsgateway flush \n";
    // Uts::BfrTckr bfrObj;
    eudSwdServiceClient->swdFlush(bfrObj);
    // std::cout << "Qutsgateway flush finished\n";
    if (bfrObj.status && (readPtrs.size() != 0))
    {
        // std::cout << "Qutsgateway calling updtptr\n";
        updatePointers();
        // std::cout << "Qutsgateway returning updtptr\n";
    }
    // std::cout << "Qutsgateway flush returning\n";
    return 0;
}


extern "C" int SwdReadWrapper(uint32_t APnDP, uint32_t A2_3, uint32_t *value)
{
    // std::cout << "Qutsgateway read start \n";
#if QUTS_GATEWAY_DEBUG
    std::cout << "Qutsgateway read start \n";
#endif
    readPtrs.push_back(value);
    std::vector<int64_t> readdata; // Data read back
    // Uts::BfrTckr bfrObj;

    eudSwdServiceClient->swdRead_wrapper(bfrObj, APnDP, A2_3);
    if (bfrObj.status && (readPtrs.size() != 0))
    {
        updatePointers();
    }

#if QUTS_GATEWAY_DEBUG
    std::cout << "Qutsgateway read end \n";
#endif
    return 0;
}

extern "C" int SwdWriteWrapper(uint32_t APnDP, uint32_t A2_3, uint32_t value)
{
    std::vector<int64_t> readdata; // Data read back
    // Uts::BfrTckr bfrObj;
#if QUTS_GATEWAY_DEBUG
    std::cout << "Qutsgateway write start \n";+
#endif
    eudSwdServiceClient->swdWrite(bfrObj, APnDP, A2_3, value);
    if (bfrObj.status && (readPtrs.size() != 0))
    {
        updatePointers();
    }
#if QUTS_GATEWAY_DEBUG
    std::cout << "Qutsgateway write end \n";
#endif
    return 0;
}

extern "C" int EudQuitWrapper(void)
{
    eudSwdServiceClient->destroyService();
#if QUTS_GATEWAY_DEBUG
    std::cout << "destroyService before " << std::endl;
#endif
    eudCtlServiceClient->destroyService();

#if QUTS_GATEWAY_DEBUG
    std::cout << "destroyService after " << std::endl;
    std::cout << "delete Quts Client object after 30000 ms" << std::endl;
#endif
    client->clearCallbacks();
    client2->clearCallbacks();
    Sleep(3000);
    if (client.get())
    {
        client.reset();
    }

    if (client2.get())
        client2.reset();

    return 0;
}

extern "C" int BitbangWrapper(uint32_t bitBangVal, uint32_t *returnPtr)
{
#if QUTS_GATEWAY_DEBUG
    std::cout << "Quts bitbang\n";
#endif
    std::vector<int32_t> tmpPtr;
    eudSwdServiceClient->SWDBitbang(tmpPtr, (int32_t)bitBangVal);
    if (tmpPtr.size() != 0)
    {
        *returnPtr = tmpPtr[0];
    }
    return 0;
}

extern "C" void Jtag_to_SWD()
{
#if QUTS_GATEWAY_DEBUG
    std::cout << "Quts Jtag_to_SWD entry\n";
#endif
    eudSwdServiceClient->Jtag_to_SWD();
#if QUTS_GATEWAY_DEBUG
    std::cout << "Quts Jtag_to_SWD exit\n";
#endif
}

int dummy_main() // this function is dummy & used for refernce. DO NOT remove.
{
#if 0
    Uts::ClientInfo clientInfo;
    clientInfo.clientName = "SampleTest";
    clientInfo.appName = "SampleTest";

    std::shared_ptr<QutsClient::QutsClient> client = nullptr;
    std::shared_ptr<QutsClient::QutsClient> client2 = nullptr;
    Uts::ProtocolInfo protInfo;

    try
    {
        client = GetQutsClient(clientInfo, "EUD Control", protInfo);
        if (client != nullptr)
        {
            std::shared_ptr<Uts::EudCtlServiceClient> eudCtlServiceClient;

            eudCtlServiceClient = CreateEUDCTLServiceClient(client, protInfo);
            if (eudCtlServiceClient != nullptr && eudCtlServiceClient.get() != nullptr)
            {
                std::cout << " initializeServiceByProtocol before with protocolHandle: " << protInfo.protocolHandle << ", device handle:" << protInfo.deviceHandle << std::endl;

                ::Uts::ErrorCode::type errCode = eudCtlServiceClient->initializeServiceByProtocol(protInfo.protocolHandle);
                if (errCode == ::Uts::ErrorCode::DEVICE_NO_ERROR)
                {
                    std::cout << " initializeServiceByProtocol affter with protocolHandle: " << protInfo.protocolHandle << ", device handle:" << protInfo.deviceHandle << std::endl;

                    // EUD CTL plugin calls
                    errCode = eudCtlServiceClient->enableSwd();
                    if (errCode == ::Uts::ErrorCode::DEVICE_NO_ERROR)
                        std::cout << " SWD enablement SUCCESSFUL!!" << std::endl;
                    else
                        std::cout << " SWD enablement FAILED!! ErrorCode = " << errCode << std::endl;

                    Sleep(10000);

                    client2 = GetQutsClient(clientInfo, "EUD SWD", protInfo);
                    if (client2 != nullptr)
                    {
                        std::shared_ptr<Uts::EudSwdServiceClient> eudSwdServiceClient;

                        eudSwdServiceClient = CreateEUDSWDServiceClient(client2, protInfo);
                        if (eudSwdServiceClient != nullptr && eudSwdServiceClient.get() != nullptr)
                        {
                            std::cout << " initializeServiceByProtocol before with protocolHandle: " << protInfo.protocolHandle << ", device handle:" << protInfo.deviceHandle << std::endl;

                            ::Uts::ErrorCode::type errCode = eudSwdServiceClient->initializeServiceByProtocol(protInfo.protocolHandle);
                            if (errCode == ::Uts::ErrorCode::DEVICE_NO_ERROR)
                            {
#if 0
                                int dataR;
                                std::string datastr = "0x00ce5634";
                                std::stringstream iss(datastr);
                                std::vector<int32_t> data;
                                int32_t startAddr = 0x146BFAF8;

                                eudSwdServiceClient->readRegister(data, startAddr, 4, 1);
#endif
                                eudSwdServiceClient->InitSWD(0);
                                std::vector<int32_t> readdata; // Data read back
                                int APnDP = 0, A2_3 = 0;
                                eudSwdServiceClient->swdRead_wrapper(readdata, APnDP, A2_3);
                                unsigned int i;
                                for (i = 0; i < readdata.size(); i++)
                                    std::cout << "DPIDR :" << std::hex << readdata[i] << " ";
                                std::cout << "\n\n";
                                readdata[0] = 0;

                                // Abort register write
                                APnDP = 0;
                                A2_3 = 0;
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, 0x1e);
                                std::cout << "Writing to Select register\n";

                                // reading Ctrlstat
                                // Write to Select register
                                APnDP = 0;
                                A2_3 = 2;
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, 0);
                                std::cout << "Writing to Select register\n";

                                // Read from ctrlstat
                                APnDP = 0;
                                A2_3 = 1;
                                eudSwdServiceClient->swdRead_wrapper(readdata, APnDP, A2_3);
                                for (i = 0; i < readdata.size(); i++)
                                    std::cout << "CTRLSTAT :" << std::hex << readdata[i] << " ";
                                std::cout << "\n\n";
                                readdata[0] = 0;

#if 1
                                // Writing ctrlstat
                                APnDP = 0;
                                A2_3 = 1;
                                unsigned int senddata = 0x50000020;
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, (signed int)senddata);
                                std::cout << "Written 0x50000020 to CTRLSTST register\n";

                                // Read from ctrlstat again
                                APnDP = 0;
                                A2_3 = 1;
                                eudSwdServiceClient->swdRead_wrapper(readdata, APnDP, A2_3);
                                for (i = 0; i < readdata.size(); i++)
                                    std::cout << "CTRLSTAT :" << std::hex << readdata[i] << " ";
                                std::cout << "\n\n";
                                readdata[0] = 0;

                                std::cout << " ***Attempt AP write*****\n";
                                APnDP = 0;
                                A2_3 = 2;
                                std::cout << "Writing to Select register\n";
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, (signed int)0);
                                APnDP = 1;
                                A2_3 = 0;
                                std::cout << "Writing size 2(32-bit) to csw register\n";
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, 0xa2000022);
                                APnDP = 1;
                                A2_3 = 1;
                                std::cout << "Writing address to LOW TAR \n";
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, (signed int)0x80000000);
                                APnDP = 1;
                                A2_3 = 2;
                                std::cout << "Writing address to High TAR \n";
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, 0);
                                APnDP = 1;
                                A2_3 = 3;
                                std::cout << "Writing content to DRW : MEM-AP \n";
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, (signed int)0xDEADBEEF);

                                std::cout << " ***Attempt AP Read*****\n";
                                APnDP = 0;
                                A2_3 = 2;
                                std::cout << "Writing to Select register\n";
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, (signed int)0);
                                APnDP = 1;
                                A2_3 = 0;
                                std::cout << "Writing size 2(32-bit) to csw register\n";
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, 0xa2000022);
                                APnDP = 1;
                                A2_3 = 1;
                                std::cout << "Writing address to Low TAR \n";
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, (signed int)0x80000000);
                                APnDP = 1;
                                A2_3 = 2;
                                std::cout << "Writing address to High TAR \n";
                                eudSwdServiceClient->swdWrite(APnDP, A2_3, 0);
                                APnDP = 1;
                                A2_3 = 3;
                                std::cout << "Reading content from DRW: MEM-AP \n";
                                eudSwdServiceClient->swdRead_wrapper(readdata, APnDP, A2_3);
                                for (i = 0; i < readdata.size(); i++)
                                    std::cout << "DRW :" << std::hex << readdata[i] << " ";
                                std::cout << "\n";
                                readdata[0] = 0;
                                APnDP = 0;
                                A2_3 = 3;
                                std::cout << "Reading content from RdBuff: \n";
                                eudSwdServiceClient->swdRead_wrapper(readdata, APnDP, A2_3);
                                for (i = 0; i < readdata.size(); i++)
                                    std::cout << "RdBuff :" << std::hex << readdata[i] << " ";
                                std::cout << "\n\n";
                                readdata[0] = 0;

#endif
                                /*
                                                                std::stringstream ss;
                                                                copy(readdata.begin(), readdata.end(), std::ostream_iterator<int>(ss, " "));
                                                                std::string readstr = ss.str();
                                                                readstr = readstr.substr(0, readstr.length() - 1);  // get rid of the trailing space
                                                                std::cout << "\n readdata = " << readstr;
                                */
                            }

                            eudSwdServiceClient->destroyService();
                        }
                    }

                    std::cout << " destroyService before " << std::endl;
                    eudCtlServiceClient->destroyService();
                    std::cout << " destroyService after " << std::endl;
                }
            }

            std::cout << " delete Quts Client object after 30000 ms" << std::endl;
            client->clearCallbacks();
            client2->clearCallbacks();
            Sleep(3000);
        }
    }
    catch (std::exception ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    if (client.get())
    {
        client.reset();
    }

    if (client2.get())
        client2.reset();
#endif
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
