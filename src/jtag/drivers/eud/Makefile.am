noinst_LTLIBRARIES += %D%/libquts.la
%C%_libquts_la_LIBADD =

# SUBDIRS += %D%/libjaylink
# DIST_SUBDIRS += %D%/libjaylink

%C%_libquts_la_SOURCES = \
	$(QUTSFILES) \
	$(QUTSHEADERS)

# %C%_libquts_la_CPPFLAGS = $(AM_CPPFLAGS) -std=c++11 -fPIC -Wall -Wno-narrowing
%C%_libquts_la_CPPFLAGS =   -Wall -Wno-narrowing
%C%_libquts_la_LIBADD += $(LIBUSB1_LIBS) -lthrift -L/c/tools/boost_1_81_0/stage/lib -lboost_thread-mgw12-mt-d-x64-1_81 -lboost_system-mgw12-mt-d-x64-1_81 -lboost_chrono-mgw12-mt-d-x64-1_81 -lboost_log_setup-mgw12-mt-d-x64-1_81 -lboost_log-mgw12-mt-d-x64-1_81 -lboost_filesystem-mgw12-mt-d-x64-1_81    

%C%_libquts_la_CPPFLAGS +=  -I%D%/src -I%D%/build/thriftgen -I/c/tools/boost_1_81_0/boost 
# libjaylink/libjaylink -I$(srcdir)/%D%/libjaylink

# EXTRA_DIST += $(ULINK_FIRMWARE) \
# 	%D%/usb_blaster/README.CheapClone \
# 	%D%/Makefile.rlink \
# 	%D%/rlink_call.m4 \
# 	%D%/rlink_init.m4

QUTSFILES =
QUTSHEADERS =

# Standard Driver: common files
# QUTSHEADERS += %D%/src/QutsClient/*.h
# QUTSHEADERS += %D%/build/thriftgen/*.h
# QUTSFILES += %D%/src/QutsClient/*.cpp
# QUTSFILES += %D%/build/thriftgen/*.cpp

QUTSFILES += %D%/src/QutsClient/Buffer.cpp
QUTSFILES += %D%/src/QutsClient/ClientCallbackServer.cpp
QUTSFILES += %D%/src/QutsClient/Constants.cpp
QUTSFILES += %D%/src/QutsClient/Event.cpp
QUTSFILES += %D%/src/QutsClient/QutsClient.cpp
QUTSFILES += %D%/src/QutsClient/QutsThreadedBinaryProtocol.cpp
QUTSFILES += %D%/src/QutsClient/ServerEventHandler.cpp
QUTSFILES += %D%/src/QutsClient/TemplateManagerService.cpp

QUTSHEADERS += %D%/build/thriftgen/ClientCallback_constants.h
QUTSHEADERS += %D%/build/thriftgen/ClientCallback.h
QUTSHEADERS += %D%/build/thriftgen/Common_constants.h
QUTSHEADERS += %D%/build/thriftgen/Common_types.h
QUTSHEADERS += %D%/build/thriftgen/DeviceConfigService_constants.h
QUTSHEADERS += %D%/build/thriftgen/DeviceConfigService.h
QUTSHEADERS += %D%/build/thriftgen/DeviceConfigService_server.skeleton.h
QUTSHEADERS += %D%/build/thriftgen/DeviceConfigService_types.h
QUTSHEADERS += %D%/build/thriftgen/DeviceManager_constants.h
QUTSHEADERS += %D%/build/thriftgen/DiagService.h
QUTSHEADERS += %D%/build/thriftgen/DiagService_constants.h
QUTSHEADERS += %D%/build/thriftgen/DiagService_types.h
QUTSHEADERS += %D%/build/thriftgen/EudCtlService_constants.h
QUTSHEADERS += %D%/build/thriftgen/EudCtlService.h
QUTSHEADERS += %D%/build/thriftgen/EudCtlService_server.skeleton.h
QUTSHEADERS += %D%/build/thriftgen/EudCtlService_types.h
QUTSHEADERS += %D%/build/thriftgen/EudService_constants.h
QUTSHEADERS += %D%/build/thriftgen/EudService.h
QUTSHEADERS += %D%/build/thriftgen/EudService_server.skeleton.h
QUTSHEADERS += %D%/build/thriftgen/EudService_types.h
QUTSHEADERS += %D%/build/thriftgen/EudSwdService_constants.h
QUTSHEADERS += %D%/build/thriftgen/EudSwdService.h
QUTSHEADERS += %D%/build/thriftgen/EudSwdService_server.skeleton.h
QUTSHEADERS += %D%/build/thriftgen/EudSwdService_types.h
QUTSHEADERS += %D%/build/thriftgen/EudTraceService_constants.h
QUTSHEADERS += %D%/build/thriftgen/EudTraceService.h
QUTSHEADERS += %D%/build/thriftgen/EudTraceService_types.h
QUTSHEADERS += %D%/build/thriftgen/ImageManagementService_constants.h
QUTSHEADERS += %D%/build/thriftgen/ImageManagementService.h
QUTSHEADERS += %D%/build/thriftgen/ImageManagementService_types.h
QUTSHEADERS += %D%/build/thriftgen/LogSession_constants.h
QUTSHEADERS += %D%/build/thriftgen/LogSession.h
QUTSHEADERS += %D%/build/thriftgen/LogSession_types.h
QUTSHEADERS += %D%/build/thriftgen/QutsService_constants.h
QUTSHEADERS += %D%/build/thriftgen/QutsService.h
QUTSHEADERS += %D%/build/thriftgen/QutsService_types.h
QUTSHEADERS += %D%/build/thriftgen/UtilityService_constants.h
QUTSHEADERS += %D%/build/thriftgen/UtilityService.h
QUTSHEADERS += %D%/build/thriftgen/UtilityService_constants.h
QUTSHEADERS += %D%/build/thriftgen/UtilityService_types.h
QUTSHEADERS += %D%/build/thriftgen/UtsClientManager_constants.h
QUTSHEADERS += %D%/build/thriftgen/UtsClientManager.h
QUTSHEADERS += %D%/build/thriftgen/UtsClientManager_types.h


QUTSFILES += %D%/build/thriftgen/ClientCallback_constants.cpp
QUTSFILES += %D%/build/thriftgen/ClientCallback.cpp
QUTSFILES += %D%/build/thriftgen/ClientCallback_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/ClientCallback_types.cpp
QUTSFILES += %D%/build/thriftgen/Common_constants.cpp
QUTSFILES += %D%/build/thriftgen/Common_types.cpp
QUTSFILES += %D%/build/thriftgen/DeviceConfigService_constants.cpp
QUTSFILES += %D%/build/thriftgen/DeviceConfigService.cpp
QUTSFILES += %D%/build/thriftgen/DeviceConfigService_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/DeviceConfigService_types.cpp
QUTSFILES += %D%/build/thriftgen/DeviceManager_constants.cpp
QUTSFILES += %D%/build/thriftgen/DeviceManager.cpp
QUTSFILES += %D%/build/thriftgen/DeviceManager_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/DeviceManager_types.cpp
QUTSFILES += %D%/build/thriftgen/DiagService_constants.cpp
QUTSFILES += %D%/build/thriftgen/DiagService.cpp
QUTSFILES += %D%/build/thriftgen/DiagService_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/DiagService_types.cpp
QUTSFILES += %D%/build/thriftgen/EudCtlService_constants.cpp
QUTSFILES += %D%/build/thriftgen/EudCtlService.cpp
QUTSFILES += %D%/build/thriftgen/EudCtlService_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/EudCtlService_types.cpp
QUTSFILES += %D%/build/thriftgen/EudService_constants.cpp
QUTSFILES += %D%/build/thriftgen/EudService.cpp
QUTSFILES += %D%/build/thriftgen/EudService_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/EudService_types.cpp
QUTSFILES += %D%/build/thriftgen/EudSwdService_constants.cpp
QUTSFILES += %D%/build/thriftgen/EudSwdService.cpp
QUTSFILES += %D%/build/thriftgen/EudSwdService_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/EudSwdService_types.cpp
QUTSFILES += %D%/build/thriftgen/EudTraceService_constants.cpp
QUTSFILES += %D%/build/thriftgen/EudTraceService.cpp
QUTSFILES += %D%/build/thriftgen/EudTraceService_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/EudTraceService_types.cpp
QUTSFILES += %D%/build/thriftgen/ImageManagementService_constants.cpp
QUTSFILES += %D%/build/thriftgen/ImageManagementService.cpp
QUTSFILES += %D%/build/thriftgen/ImageManagementService_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/ImageManagementService_types.cpp
QUTSFILES += %D%/build/thriftgen/LogSession_constants.cpp
QUTSFILES += %D%/build/thriftgen/LogSession.cpp
QUTSFILES += %D%/build/thriftgen/LogSession_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/LogSession_types.cpp
QUTSFILES += %D%/build/thriftgen/QutsService_constants.cpp
QUTSFILES += %D%/build/thriftgen/QutsService.cpp
QUTSFILES += %D%/build/thriftgen/QutsService_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/QutsService_types.cpp
QUTSFILES += %D%/build/thriftgen/UtilityService_constants.cpp
QUTSFILES += %D%/build/thriftgen/UtilityService.cpp
QUTSFILES += %D%/build/thriftgen/UtilityService_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/UtilityService_types.cpp
QUTSFILES += %D%/build/thriftgen/UtsClientManager_constants.cpp
QUTSFILES += %D%/build/thriftgen/UtsClientManager.cpp
QUTSFILES += %D%/build/thriftgen/UtsClientManager_server.skeleton.cpp
QUTSFILES += %D%/build/thriftgen/UtsClientManager_types.cpp
QUTSFILES += %D%/src/QutsClient/QutsGateWay.cpp

# %C%_libquts_la_LIBADD += -lm

# QUTSHEADERS = \
# 	%D%/bitbang.h \
# 	%D%/bitq.h 

