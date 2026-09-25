#ifndef TELEMATICS_WRAPPER
#define TELEMATICS_WRAPPER

#include "TelematicsClient.h"

#ifdef WIN32
  #define DllExport   __declspec( dllexport )
#else
  #define DllExport
#endif

using namespace Telematics;
#define TELEMATICS_MAX_MESSAGE_SIZE 4096
#define TELEMATICS_MAX_LOG_SIZE 65536


//! cTelematicsClient is a singleton.
//! Use this to get the instance of cTelematicsClient
extern cTelematicsClient* Telematics_Client;

#ifndef WIN32
   typedef void(* ErrorCallback)  (char* errStr);
   typedef void(* WarningCallback)(char* warningStr);
   typedef void(* InfoCallback)   (char* infoStr);
#else
   typedef void(__stdcall * ErrorCallback)(char* errStr);
   typedef void(__stdcall * WarningCallback)(char* warningStr);
   typedef void(__stdcall * InfoCallback)(char* infoStr);
#endif

extern ErrorCallback Telematics_ErrorCallback;
extern InfoCallback  Telematics_InfoCallback;

class Telematics_Callback : public cTelematicsCallback
{
    void error(std::string error)
    {
        if (Telematics_ErrorCallback)
        {
            (*Telematics_ErrorCallback)((char *) error.c_str());
        }
    }

    void info(std::string info)
    {
        if (Telematics_InfoCallback)
        {
            (*Telematics_InfoCallback)((char *)info.c_str());
        }
    }
};


extern "C" {

	//! Used to initialize the lime client with the session
	/*! Provide the unique productID of the tool. Metadata is attached with every
	//  data entry, so use with sparingly.
	\return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS, TELEMATICS_OTHER_ERROR
	*/
	DllExport eTelematicsReturnCode Telematics_Initialize(char* productId,
		char* metaData);

	//! Used to track events using the given eventId
	/*!
	\return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS, TELEMATICS_OTHER_ERROR
	//  eventData could be json object string.
	*/
	DllExport eTelematicsReturnCode Telematics_TrackEvent(char* eventId, char* eventData);

	//! Used to track Metrics using the given metricId and metricValue
	/*!
	\return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS, TELEMATICS_OTHER_ERROR
	*/
	DllExport eTelematicsReturnCode Telematics_TrackMetric(char*  metricId, 
														   double metricValue);

	//! Used to track exceptions using the given exception
	/*!
	\return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS, TELEMATICS_OTHER_ERROR
	*/
	DllExport eTelematicsReturnCode Telematics_TrackException(std::exception ex); 

	//! Used to track Licenses using the given featureId
	/*!
	\return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS, TELEMATICS_OTHER_ERROR
	*/
	DllExport eTelematicsReturnCode Telematics_TrackLicenseCheck(char* featureId);


	//! Used to get active Telematics.
	// This API should NOT be used by all clients. 
	DllExport eTelematicsReturnCode Telematics_GetAvailableTelematics
        (char* telematicsIds,
         int   telematicsIdsSize);

   //! Used to getVersion of the TelematicsCLient.
   /*!
   \return string Version of the TelematicsClient
   */
	DllExport eTelematicsReturnCode Telematics_GetVersion(char *Ver, int nlen);
   
   //! Used to compress files of TelematicsCLient.
   /*! This API should NOT be used by all clients. 
   \return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS, TELEMATICS_OTHER_ERROR
   */
   DllExport eTelematicsReturnCode Telematics_Compress(bool forceCurrent);
   
   //! Used to set asynchronous error callbacks.
   /*!
   \param pError    Function pointer to error callback
   \return
   */
   DllExport void Telematics_SetErrorCallback(ErrorCallback pErrorCB);
   
   //! Used to set asynchronous warning callbacks.
   /*!
   \param pWarning    Function pointer to warning callback
   \return
   */
   DllExport void Telematics_SetWarningCallback(WarningCallback pWarningCB);

   //! Used to set asynchronous info callbacks.
   /*!
   \param pInfo    Function pointer to info callback
   \return
   */
   DllExport void Telematics_SetInfoCallback(InfoCallback pInfoCB);
}

 #endif
