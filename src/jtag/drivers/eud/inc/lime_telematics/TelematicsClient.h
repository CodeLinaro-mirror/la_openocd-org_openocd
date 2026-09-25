/*===========================================================================
FILE:
   TelematicsClient.h

DESCRIPTION:
   Defines the API for the License Management Client

Copyright (C) 2017 Qualcomm Technologies, Inc.
All rights reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/
#include <string>
#include <list>

namespace Telematics
{
#ifndef TELEMATICS_DEFS
#define TELEMATICS_DEFS

   /*!======================================================================*/
   //! enum eTelematicsReturnCode
   //!    enumeration of TelematicsReturnCodes
   /*!======================================================================*/
   enum eTelematicsReturnCode
   {
      TELEMATICS_CLIENT_SUCCESS      = 0,
      TELEMATICS_FILE_ACCESS_ERROR   = 1,
      TELEMATICS_INVALID_MACHINE     = 2,
      TELEMATICS_INVALID_ID          = 3,
      TELEMATICS_LICENSE_UNAVAILABLE = 4,
      TELEMATICS_DECODE_ERROR        = 5,
      TELEMATICS_ENCODE_ERROR        = 6,
      TELEMATICS_SERVER_ERROR        = 7,
      TELEMATICS_PARSING_ERROR       = 8,
      TELEMATICS_STALE_UPDATE        = 9,
      TELEMATICS_FILE_SIZE_EXEEDED   = 10,
      TELEMATICS_OTHER_ERROR         = 99
   };


/// TODO: Define basic classes for event, licensecheck, trace, severity properties.
   class cTelematicsEvent{
   public:
	   int id;
	   int productId;

	   int getId();
	   int getProductId();
	   void setId();
	   void setProductId(); //probably not necessary 
   };
   class cTelematicsTrace{
	   //TODO
   };

   enum cTelematicsSeverity{
	   //not sure what others to put here
	   TELEMATICS_WARNING = 0,
	   TELEMATICS_ERROR = 1
   };
   enum cTelematicsProperties{
	   //not sure what else to put here
	   TELEMATICS_PROPERTY = 0
   };
   class cTelematicsLicenseCheck{
	   //TODO
   };

   /*======================================================================*/
   // Class cTelematicsLicense
   //    Provides callbacks when required
   /*======================================================================*/
   class cTelematicsCallback
   {
      public:
         
         virtual void error( std::string errorString );

         virtual void warning( std::string warningString );

         virtual void info( std::string infoString );
    };

   /*======================================================================*/
   // Class cTelematicsClient
   //    Provides all licensing functionality
   /*======================================================================*/
   class cTelematicsClient
   {
      public:
         //! cTelematicsClient is a singleton.
         //! Use this to get the instance of cTelematicsClient
         static cTelematicsClient * getInstance();

         //! Used to initialize the telematics client with the session
         /*!
            \param productId Well defined product ID. 
            \return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS, TELEMATICS_OTHER_ERROR

            !!!!!!!!THIS FUNCTION IS NOT THREADSAFE!!!!!!!!!
         */
         eTelematicsReturnCode initialize( std::string productId, 
			                               std::string metaData );


         //! Used to getVersion of the TelematicsCLient.
         /*
            \return string Version of the TelematicsClient
         */
         std::string getVersion();


         //! Used to set class for asynchronous callbacks.
         /*!
            \param callback    Class defining callback methods
            \return
         */
         void setCallback( cTelematicsCallback * pCallback );

         //! Used to set function pointer for error callbacks.
         /*!
         \param callback    function pointer for error callbacks
         \return
         */
         void setErrorCallback(cTelematicsCallback * pCallback);

         //! Used to set function pointer for debug callbacks.
         /*!
         \param callback    function pointer for debug callbacks
         \return
         */
         void setInfoCallback(cTelematicsCallback * pCallback);


         //! Used to generate track Events
         /*!
            \param eventId: client defined event id. 
            \param eventData user event data
            \return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS
         */
         eTelematicsReturnCode trackEvent(std::string  eventId, std::string  eventData);
                                          
         //! Used to track Metrics
         /*!
         \param metricId GUID that uniquely identifies a metric
         \return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS
         */
         eTelematicsReturnCode trackMetric(std::string metricId,
	                                   double      metricValue);		 
		 
         //! Used to track LicenseCheck
         /*!
         \param featureId GUID that uniquely identifies the feature
         \return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS
         */
         eTelematicsReturnCode trackLicenseCheck(std::string featureId);

         //! Used to track Exceptions
         /*!
         \param exception Exception occuring in code. 
         \return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS
         */
         eTelematicsReturnCode trackException(std::exception exception);

         //! Used for logging
         /*!
         \param exception Exception occuring in code.
         \return eTelematicsReturnCode TELEMATICS_CLIENT_SUCCESS
         */
         eTelematicsReturnCode compress(bool forceCurrent = false);

         //! Used to get active telematics Client files
         eTelematicsReturnCode getAvailableTelematics(std::string& telematicsIds);
         eTelematicsReturnCode getAvailableTelematicsList(std::list<std::string>& telematicsIdList);

      private:
         //! Constructor
         cTelematicsClient();

         //! Deconstructor
         ~cTelematicsClient();

         //! Static pointer to single instance of this class
         static cTelematicsClient * mpTelematicsClient;
   };
#endif // TELEMATICS_DEFS
}
