noinst_LTLIBRARIES += %D%/libquts.la
%C%_libquts_la_LIBADD =

# SUBDIRS += %D%/libjaylink
# DIST_SUBDIRS += %D%/libjaylink

%C%_libquts_la_SOURCES = \
	$(QUTSFILES) \
	$(QUTSHEADERS)

# %C%_libquts_la_CPPFLAGS = $(AM_CPPFLAGS) -std=c++11 -fPIC -Wall -Wno-narrowing
%C%_libquts_la_CPPFLAGS =   -Wall -Wno-narrowing
%C%_libquts_la_LIBADD += $(LIBUSB1_LIBS) -lthrift -L/c/msys64/ucrt64/lib/ -lboost_thread-mt -lboost_system-mt -lboost_chrono-mt -lboost_log_setup-mt  -lboost_log-mt -lboost_filesystem-mt
%C%_libquts_la_CPPFLAGS +=  -I%D%/src -I%D%/build/thriftgen -I/c/msys64/ucrt64/include/ 
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

