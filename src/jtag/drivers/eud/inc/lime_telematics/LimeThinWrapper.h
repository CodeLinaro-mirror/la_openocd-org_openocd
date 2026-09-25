#ifndef LIME_WRAPPER
#define LIME_WRAPPER

#include "LimeThinClient.h"

#ifdef WIN32
  #define DllExport   __declspec( dllexport )
#else
  #define DllExport
#endif

using namespace Lime;
#define LIME_MAX_MESSAGE_SIZE 4096
#define LIME_MAX_LOG_SIZE 65536


//! cLimeClient is a singleton.
//! Use this to get the instance of cLimeClient
extern cLimeThinClient* Lime_Client;

// Typedefs for callback methods
#ifndef WIN32
   typedef void(* ErrorCallback)  (char* errStr);
   typedef void(* WarningCallback)(char* warningStr);
   typedef void(* InfoCallback)   (char* infoStr);
#else
   typedef void(__stdcall * ErrorCallback)(char* errStr);
   typedef void(__stdcall * WarningCallback)(char* warningStr);
   typedef void(__stdcall * InfoCallback)(char* infoStr);
#endif

extern ErrorCallback Lime_ErrorCallback;
extern InfoCallback  Lime_InfoCallback;

class Lime_Callback : public cLimeCallback
{
    void error(std::string error)
    {
        if (Lime_ErrorCallback)
        {
            (*Lime_ErrorCallback)((char *) error.c_str());
        }
    }

    void info(std::string info)
    {
        if (Lime_InfoCallback)
        {
            (*Lime_InfoCallback)((char *)info.c_str());
        }
    }
};


extern "C" {

    //! Used to initialize the lime client with the session
    /*!
    \return eLimeReturnCode LIME_CLIENT_SUCCESS, LIME_OTHER_ERROR
    */
    DllExport eLimeReturnCode Lime_Initialize(char* userId,
        char* storageLocation);

   //! Used to getVersion of the LimeCLient.
   /*!
   \return string Version of the LimeClient
   */
   DllExport char* Lime_GetVersion();
   
   //! Used to set asynchronous error callbacks.
   /*!
   \param pError    Function pointer to error callback
   \return
   */
   DllExport void Lime_SetErrorCallback(ErrorCallback pErrorCB);
   
   //! Used to set asynchronous warning callbacks.
   /*!
   \param pWarning    Function pointer to warning callback
   \return
   */
   DllExport void Lime_SetWarningCallback(WarningCallback pWarningCB);

   //! Used to set asynchronous info callbacks.
   /*!
   \param pInfo    Function pointer to info callback
   \return
   */
   DllExport void Lime_SetInfoCallback(InfoCallback pInfoCB);
   
    

    //! Used to get License Information.
    /*!
      \param activationId Activation Identifier
      \param license Reference to return license information
      \return eLimeReturnCode LIME_SUCCESS, LIME_CANNOT_REACH_SERVER
                                        LIME_INVALID_ID
    */
    DllExport eLimeReturnCode Lime_GetLicenseInfo
        (char* activationId,
         char* license,
         int   licenseSize);

    //! Used to Check Feature Availability
    /*!
      \param productId Product Identifier
      \param featureId Feature Identifier
      \return eLimeReturnCode LIME_CLIENT_SUCCESS, LIME_INVALID_ID,
                                        LIME_INVALID_LICENSE
    */
    DllExport eLimeReturnCode Lime_CheckLicense
        (char* productId,
         char* featureId);

  //!  Used to get a Token for a license of a feature.
  /*!
    \param productId Product Identifier
    \param featureId Feature Identifier
    \param licenseKey Reference to return license Key
    \return eLimeReturnCode LIME_CLIENT_SUCCESS, LIME_LICENSE_UNAVAILABLE
 */
  DllExport eLimeReturnCode Lime_GetLicenseKey
        (char* productId,
         char * featureId,
         char * licenseKey,
         int    licenseKeyLength
         );
		 
  //!  Used to verify the Token for a license of a feature.
  /*!
    \param licenseKey license Key to be verified
    \param productId Reference to return Product Identifier
    \param featureId Reference to return Feature Identifier
    \param timeStamp Reference to return timestamp of the license key
    \return eLimeReturnCode LIME_CLIENT_SUCCESS, LIME_LICENSE_UNAVAILABLE
 */
  DllExport eLimeReturnCode Lime_VerifyLicenseKey
        (char*  licenseKey,
         char*  productId,
         int    productIdLength,
         char*  featureId,
         int    featureIdLength,
         char*  timeStamp,
         int    timeStampLength
         );

    //! Used to get Error string for logging
    /*!
    \param errorString reference to return error string
    \param errorStringSize max size of error string
    \return eLimeReturnCode LIME_CLIENT_SUCCESS, LIME_DECODE_ERROR
    */
    DllExport eLimeReturnCode Lime_GetErrorString
        (char* errorString, 
             int   errorStringSize);

}

#endif
