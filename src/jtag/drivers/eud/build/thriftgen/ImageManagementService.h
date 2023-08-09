/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef ImageManagementService_H
#define ImageManagementService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "ImageManagementService_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ImageManagementServiceIf {
 public:
  virtual ~ImageManagementServiceIf() {}
  virtual void getLastError( ::Uts::ErrorType& _return) = 0;
  virtual  ::Uts::ErrorCode::type initializeService() = 0;
  virtual  ::Uts::ErrorCode::type destroyService() = 0;
  virtual DeviceImageMode::type getDeviceImageMode() = 0;
  virtual void transferImages(TransferImageResult& _return, const std::map<int32_t, std::string> & imageList) = 0;
  virtual void getDeviceInfo(EdlDeviceInfo& _return) = 0;
  virtual  ::Uts::ErrorCode::type collectPblDumpV3(const std::string& pathName) = 0;
  virtual  ::Uts::ErrorCode::type downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options) = 0;
  virtual  ::Uts::ErrorCode::type collectMemoryDump(const std::string& pathName) = 0;
  virtual  ::Uts::ErrorCode::type collectMemoryDumpWithOptions(const MemoryDumpOptions& options) = 0;
  virtual  ::Uts::ErrorCode::type startRemoteEfsSync(const std::string& pathName) = 0;
  virtual  ::Uts::ErrorCode::type stopRemoteEfsSync() = 0;
  virtual  ::Uts::ErrorCode::type setDdrStorePath(const std::string& ddrStorePath) = 0;
  virtual  ::Uts::ErrorCode::type resetDevice(const int32_t timeout) = 0;
  virtual  ::Uts::ErrorCode::type switchToEdl() = 0;
  virtual  ::Uts::ErrorCode::type erasePartition(const DownloadBuildOptions& options) = 0;
  virtual void getFlashInfo(std::vector<FlashInfo> & _return, const DownloadBuildOptions& options) = 0;
  virtual void initPartitionTable(std::vector<PartitionInfo> & _return, const DownloadBuildOptions& options) = 0;
  virtual  ::Uts::ErrorCode::type readPartitionData(const std::vector<DataChunkOptions> & dataChunks) = 0;
  virtual  ::Uts::ErrorCode::type writePartitionData(const std::vector<DataChunkOptions> & dataChunks) = 0;
  virtual  ::Uts::ErrorCode::type erasePartitionData(const std::vector<DataChunkOptions> & dataChunks) = 0;
};

class ImageManagementServiceIfFactory {
 public:
  typedef ImageManagementServiceIf Handler;

  virtual ~ImageManagementServiceIfFactory() {}

  virtual ImageManagementServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ImageManagementServiceIf* /* handler */) = 0;
};

class ImageManagementServiceIfSingletonFactory : virtual public ImageManagementServiceIfFactory {
 public:
  ImageManagementServiceIfSingletonFactory(const ::std::shared_ptr<ImageManagementServiceIf>& iface) : iface_(iface) {}
  virtual ~ImageManagementServiceIfSingletonFactory() {}

  virtual ImageManagementServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ImageManagementServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<ImageManagementServiceIf> iface_;
};

class ImageManagementServiceNull : virtual public ImageManagementServiceIf {
 public:
  virtual ~ImageManagementServiceNull() {}
  void getLastError( ::Uts::ErrorType& /* _return */) {
    return;
  }
   ::Uts::ErrorCode::type initializeService() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type destroyService() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  DeviceImageMode::type getDeviceImageMode() {
    DeviceImageMode::type _return = (DeviceImageMode::type)0;
    return _return;
  }
  void transferImages(TransferImageResult& /* _return */, const std::map<int32_t, std::string> & /* imageList */) {
    return;
  }
  void getDeviceInfo(EdlDeviceInfo& /* _return */) {
    return;
  }
   ::Uts::ErrorCode::type collectPblDumpV3(const std::string& /* pathName */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type downloadBuild(const std::string& /* buildPath */, const DownloadBuildOptions& /* options */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type collectMemoryDump(const std::string& /* pathName */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type collectMemoryDumpWithOptions(const MemoryDumpOptions& /* options */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type startRemoteEfsSync(const std::string& /* pathName */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type stopRemoteEfsSync() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setDdrStorePath(const std::string& /* ddrStorePath */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type resetDevice(const int32_t /* timeout */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type switchToEdl() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type erasePartition(const DownloadBuildOptions& /* options */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void getFlashInfo(std::vector<FlashInfo> & /* _return */, const DownloadBuildOptions& /* options */) {
    return;
  }
  void initPartitionTable(std::vector<PartitionInfo> & /* _return */, const DownloadBuildOptions& /* options */) {
    return;
  }
   ::Uts::ErrorCode::type readPartitionData(const std::vector<DataChunkOptions> & /* dataChunks */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type writePartitionData(const std::vector<DataChunkOptions> & /* dataChunks */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type erasePartitionData(const std::vector<DataChunkOptions> & /* dataChunks */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
};


class ImageManagementService_getLastError_args {
 public:

  ImageManagementService_getLastError_args(const ImageManagementService_getLastError_args&);
  ImageManagementService_getLastError_args& operator=(const ImageManagementService_getLastError_args&);
  ImageManagementService_getLastError_args() {
  }

  virtual ~ImageManagementService_getLastError_args() noexcept;

  bool operator == (const ImageManagementService_getLastError_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ImageManagementService_getLastError_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_getLastError_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_getLastError_pargs {
 public:


  virtual ~ImageManagementService_getLastError_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_getLastError_result__isset {
  _ImageManagementService_getLastError_result__isset() : success(false) {}
  bool success :1;
} _ImageManagementService_getLastError_result__isset;

class ImageManagementService_getLastError_result {
 public:

  ImageManagementService_getLastError_result(const ImageManagementService_getLastError_result&);
  ImageManagementService_getLastError_result& operator=(const ImageManagementService_getLastError_result&);
  ImageManagementService_getLastError_result() {
  }

  virtual ~ImageManagementService_getLastError_result() noexcept;
   ::Uts::ErrorType success;

  _ImageManagementService_getLastError_result__isset __isset;

  void __set_success(const  ::Uts::ErrorType& val);

  bool operator == (const ImageManagementService_getLastError_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_getLastError_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_getLastError_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_getLastError_presult__isset {
  _ImageManagementService_getLastError_presult__isset() : success(false) {}
  bool success :1;
} _ImageManagementService_getLastError_presult__isset;

class ImageManagementService_getLastError_presult {
 public:


  virtual ~ImageManagementService_getLastError_presult() noexcept;
   ::Uts::ErrorType* success;

  _ImageManagementService_getLastError_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ImageManagementService_initializeService_args {
 public:

  ImageManagementService_initializeService_args(const ImageManagementService_initializeService_args&);
  ImageManagementService_initializeService_args& operator=(const ImageManagementService_initializeService_args&);
  ImageManagementService_initializeService_args() {
  }

  virtual ~ImageManagementService_initializeService_args() noexcept;

  bool operator == (const ImageManagementService_initializeService_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ImageManagementService_initializeService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_initializeService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_initializeService_pargs {
 public:


  virtual ~ImageManagementService_initializeService_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_initializeService_result__isset {
  _ImageManagementService_initializeService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_initializeService_result__isset;

class ImageManagementService_initializeService_result {
 public:

  ImageManagementService_initializeService_result(const ImageManagementService_initializeService_result&);
  ImageManagementService_initializeService_result& operator=(const ImageManagementService_initializeService_result&);
  ImageManagementService_initializeService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_initializeService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_initializeService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_initializeService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_initializeService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_initializeService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_initializeService_presult__isset {
  _ImageManagementService_initializeService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_initializeService_presult__isset;

class ImageManagementService_initializeService_presult {
 public:


  virtual ~ImageManagementService_initializeService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_initializeService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ImageManagementService_destroyService_args {
 public:

  ImageManagementService_destroyService_args(const ImageManagementService_destroyService_args&);
  ImageManagementService_destroyService_args& operator=(const ImageManagementService_destroyService_args&);
  ImageManagementService_destroyService_args() {
  }

  virtual ~ImageManagementService_destroyService_args() noexcept;

  bool operator == (const ImageManagementService_destroyService_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ImageManagementService_destroyService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_destroyService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_destroyService_pargs {
 public:


  virtual ~ImageManagementService_destroyService_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_destroyService_result__isset {
  _ImageManagementService_destroyService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_destroyService_result__isset;

class ImageManagementService_destroyService_result {
 public:

  ImageManagementService_destroyService_result(const ImageManagementService_destroyService_result&);
  ImageManagementService_destroyService_result& operator=(const ImageManagementService_destroyService_result&);
  ImageManagementService_destroyService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_destroyService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_destroyService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_destroyService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_destroyService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_destroyService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_destroyService_presult__isset {
  _ImageManagementService_destroyService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_destroyService_presult__isset;

class ImageManagementService_destroyService_presult {
 public:


  virtual ~ImageManagementService_destroyService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_destroyService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ImageManagementService_getDeviceImageMode_args {
 public:

  ImageManagementService_getDeviceImageMode_args(const ImageManagementService_getDeviceImageMode_args&);
  ImageManagementService_getDeviceImageMode_args& operator=(const ImageManagementService_getDeviceImageMode_args&);
  ImageManagementService_getDeviceImageMode_args() {
  }

  virtual ~ImageManagementService_getDeviceImageMode_args() noexcept;

  bool operator == (const ImageManagementService_getDeviceImageMode_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ImageManagementService_getDeviceImageMode_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_getDeviceImageMode_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_getDeviceImageMode_pargs {
 public:


  virtual ~ImageManagementService_getDeviceImageMode_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_getDeviceImageMode_result__isset {
  _ImageManagementService_getDeviceImageMode_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_getDeviceImageMode_result__isset;

class ImageManagementService_getDeviceImageMode_result {
 public:

  ImageManagementService_getDeviceImageMode_result(const ImageManagementService_getDeviceImageMode_result&);
  ImageManagementService_getDeviceImageMode_result& operator=(const ImageManagementService_getDeviceImageMode_result&);
  ImageManagementService_getDeviceImageMode_result() : success((DeviceImageMode::type)0) {
  }

  virtual ~ImageManagementService_getDeviceImageMode_result() noexcept;
  DeviceImageMode::type success;
   ::Uts::AppException e;

  _ImageManagementService_getDeviceImageMode_result__isset __isset;

  void __set_success(const DeviceImageMode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_getDeviceImageMode_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_getDeviceImageMode_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_getDeviceImageMode_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_getDeviceImageMode_presult__isset {
  _ImageManagementService_getDeviceImageMode_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_getDeviceImageMode_presult__isset;

class ImageManagementService_getDeviceImageMode_presult {
 public:


  virtual ~ImageManagementService_getDeviceImageMode_presult() noexcept;
  DeviceImageMode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_getDeviceImageMode_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_transferImages_args__isset {
  _ImageManagementService_transferImages_args__isset() : imageList(false) {}
  bool imageList :1;
} _ImageManagementService_transferImages_args__isset;

class ImageManagementService_transferImages_args {
 public:

  ImageManagementService_transferImages_args(const ImageManagementService_transferImages_args&);
  ImageManagementService_transferImages_args& operator=(const ImageManagementService_transferImages_args&);
  ImageManagementService_transferImages_args() {
  }

  virtual ~ImageManagementService_transferImages_args() noexcept;
  std::map<int32_t, std::string>  imageList;

  _ImageManagementService_transferImages_args__isset __isset;

  void __set_imageList(const std::map<int32_t, std::string> & val);

  bool operator == (const ImageManagementService_transferImages_args & rhs) const
  {
    if (!(imageList == rhs.imageList))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_transferImages_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_transferImages_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_transferImages_pargs {
 public:


  virtual ~ImageManagementService_transferImages_pargs() noexcept;
  const std::map<int32_t, std::string> * imageList;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_transferImages_result__isset {
  _ImageManagementService_transferImages_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_transferImages_result__isset;

class ImageManagementService_transferImages_result {
 public:

  ImageManagementService_transferImages_result(const ImageManagementService_transferImages_result&);
  ImageManagementService_transferImages_result& operator=(const ImageManagementService_transferImages_result&);
  ImageManagementService_transferImages_result() {
  }

  virtual ~ImageManagementService_transferImages_result() noexcept;
  TransferImageResult success;
   ::Uts::AppException e;

  _ImageManagementService_transferImages_result__isset __isset;

  void __set_success(const TransferImageResult& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_transferImages_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_transferImages_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_transferImages_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_transferImages_presult__isset {
  _ImageManagementService_transferImages_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_transferImages_presult__isset;

class ImageManagementService_transferImages_presult {
 public:


  virtual ~ImageManagementService_transferImages_presult() noexcept;
  TransferImageResult* success;
   ::Uts::AppException e;

  _ImageManagementService_transferImages_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ImageManagementService_getDeviceInfo_args {
 public:

  ImageManagementService_getDeviceInfo_args(const ImageManagementService_getDeviceInfo_args&);
  ImageManagementService_getDeviceInfo_args& operator=(const ImageManagementService_getDeviceInfo_args&);
  ImageManagementService_getDeviceInfo_args() {
  }

  virtual ~ImageManagementService_getDeviceInfo_args() noexcept;

  bool operator == (const ImageManagementService_getDeviceInfo_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ImageManagementService_getDeviceInfo_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_getDeviceInfo_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_getDeviceInfo_pargs {
 public:


  virtual ~ImageManagementService_getDeviceInfo_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_getDeviceInfo_result__isset {
  _ImageManagementService_getDeviceInfo_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_getDeviceInfo_result__isset;

class ImageManagementService_getDeviceInfo_result {
 public:

  ImageManagementService_getDeviceInfo_result(const ImageManagementService_getDeviceInfo_result&);
  ImageManagementService_getDeviceInfo_result& operator=(const ImageManagementService_getDeviceInfo_result&);
  ImageManagementService_getDeviceInfo_result() {
  }

  virtual ~ImageManagementService_getDeviceInfo_result() noexcept;
  EdlDeviceInfo success;
   ::Uts::AppException e;

  _ImageManagementService_getDeviceInfo_result__isset __isset;

  void __set_success(const EdlDeviceInfo& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_getDeviceInfo_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_getDeviceInfo_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_getDeviceInfo_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_getDeviceInfo_presult__isset {
  _ImageManagementService_getDeviceInfo_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_getDeviceInfo_presult__isset;

class ImageManagementService_getDeviceInfo_presult {
 public:


  virtual ~ImageManagementService_getDeviceInfo_presult() noexcept;
  EdlDeviceInfo* success;
   ::Uts::AppException e;

  _ImageManagementService_getDeviceInfo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_collectPblDumpV3_args__isset {
  _ImageManagementService_collectPblDumpV3_args__isset() : pathName(false) {}
  bool pathName :1;
} _ImageManagementService_collectPblDumpV3_args__isset;

class ImageManagementService_collectPblDumpV3_args {
 public:

  ImageManagementService_collectPblDumpV3_args(const ImageManagementService_collectPblDumpV3_args&);
  ImageManagementService_collectPblDumpV3_args& operator=(const ImageManagementService_collectPblDumpV3_args&);
  ImageManagementService_collectPblDumpV3_args() : pathName() {
  }

  virtual ~ImageManagementService_collectPblDumpV3_args() noexcept;
  std::string pathName;

  _ImageManagementService_collectPblDumpV3_args__isset __isset;

  void __set_pathName(const std::string& val);

  bool operator == (const ImageManagementService_collectPblDumpV3_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_collectPblDumpV3_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_collectPblDumpV3_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_collectPblDumpV3_pargs {
 public:


  virtual ~ImageManagementService_collectPblDumpV3_pargs() noexcept;
  const std::string* pathName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_collectPblDumpV3_result__isset {
  _ImageManagementService_collectPblDumpV3_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_collectPblDumpV3_result__isset;

class ImageManagementService_collectPblDumpV3_result {
 public:

  ImageManagementService_collectPblDumpV3_result(const ImageManagementService_collectPblDumpV3_result&);
  ImageManagementService_collectPblDumpV3_result& operator=(const ImageManagementService_collectPblDumpV3_result&);
  ImageManagementService_collectPblDumpV3_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_collectPblDumpV3_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_collectPblDumpV3_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_collectPblDumpV3_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_collectPblDumpV3_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_collectPblDumpV3_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_collectPblDumpV3_presult__isset {
  _ImageManagementService_collectPblDumpV3_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_collectPblDumpV3_presult__isset;

class ImageManagementService_collectPblDumpV3_presult {
 public:


  virtual ~ImageManagementService_collectPblDumpV3_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_collectPblDumpV3_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_downloadBuild_args__isset {
  _ImageManagementService_downloadBuild_args__isset() : buildPath(false), options(false) {}
  bool buildPath :1;
  bool options :1;
} _ImageManagementService_downloadBuild_args__isset;

class ImageManagementService_downloadBuild_args {
 public:

  ImageManagementService_downloadBuild_args(const ImageManagementService_downloadBuild_args&);
  ImageManagementService_downloadBuild_args& operator=(const ImageManagementService_downloadBuild_args&);
  ImageManagementService_downloadBuild_args() : buildPath() {
  }

  virtual ~ImageManagementService_downloadBuild_args() noexcept;
  std::string buildPath;
  DownloadBuildOptions options;

  _ImageManagementService_downloadBuild_args__isset __isset;

  void __set_buildPath(const std::string& val);

  void __set_options(const DownloadBuildOptions& val);

  bool operator == (const ImageManagementService_downloadBuild_args & rhs) const
  {
    if (!(buildPath == rhs.buildPath))
      return false;
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_downloadBuild_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_downloadBuild_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_downloadBuild_pargs {
 public:


  virtual ~ImageManagementService_downloadBuild_pargs() noexcept;
  const std::string* buildPath;
  const DownloadBuildOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_downloadBuild_result__isset {
  _ImageManagementService_downloadBuild_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_downloadBuild_result__isset;

class ImageManagementService_downloadBuild_result {
 public:

  ImageManagementService_downloadBuild_result(const ImageManagementService_downloadBuild_result&);
  ImageManagementService_downloadBuild_result& operator=(const ImageManagementService_downloadBuild_result&);
  ImageManagementService_downloadBuild_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_downloadBuild_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_downloadBuild_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_downloadBuild_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_downloadBuild_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_downloadBuild_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_downloadBuild_presult__isset {
  _ImageManagementService_downloadBuild_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_downloadBuild_presult__isset;

class ImageManagementService_downloadBuild_presult {
 public:


  virtual ~ImageManagementService_downloadBuild_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_downloadBuild_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_collectMemoryDump_args__isset {
  _ImageManagementService_collectMemoryDump_args__isset() : pathName(false) {}
  bool pathName :1;
} _ImageManagementService_collectMemoryDump_args__isset;

class ImageManagementService_collectMemoryDump_args {
 public:

  ImageManagementService_collectMemoryDump_args(const ImageManagementService_collectMemoryDump_args&);
  ImageManagementService_collectMemoryDump_args& operator=(const ImageManagementService_collectMemoryDump_args&);
  ImageManagementService_collectMemoryDump_args() : pathName() {
  }

  virtual ~ImageManagementService_collectMemoryDump_args() noexcept;
  std::string pathName;

  _ImageManagementService_collectMemoryDump_args__isset __isset;

  void __set_pathName(const std::string& val);

  bool operator == (const ImageManagementService_collectMemoryDump_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_collectMemoryDump_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_collectMemoryDump_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_collectMemoryDump_pargs {
 public:


  virtual ~ImageManagementService_collectMemoryDump_pargs() noexcept;
  const std::string* pathName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_collectMemoryDump_result__isset {
  _ImageManagementService_collectMemoryDump_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_collectMemoryDump_result__isset;

class ImageManagementService_collectMemoryDump_result {
 public:

  ImageManagementService_collectMemoryDump_result(const ImageManagementService_collectMemoryDump_result&);
  ImageManagementService_collectMemoryDump_result& operator=(const ImageManagementService_collectMemoryDump_result&);
  ImageManagementService_collectMemoryDump_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_collectMemoryDump_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_collectMemoryDump_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_collectMemoryDump_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_collectMemoryDump_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_collectMemoryDump_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_collectMemoryDump_presult__isset {
  _ImageManagementService_collectMemoryDump_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_collectMemoryDump_presult__isset;

class ImageManagementService_collectMemoryDump_presult {
 public:


  virtual ~ImageManagementService_collectMemoryDump_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_collectMemoryDump_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_collectMemoryDumpWithOptions_args__isset {
  _ImageManagementService_collectMemoryDumpWithOptions_args__isset() : options(false) {}
  bool options :1;
} _ImageManagementService_collectMemoryDumpWithOptions_args__isset;

class ImageManagementService_collectMemoryDumpWithOptions_args {
 public:

  ImageManagementService_collectMemoryDumpWithOptions_args(const ImageManagementService_collectMemoryDumpWithOptions_args&);
  ImageManagementService_collectMemoryDumpWithOptions_args& operator=(const ImageManagementService_collectMemoryDumpWithOptions_args&);
  ImageManagementService_collectMemoryDumpWithOptions_args() {
  }

  virtual ~ImageManagementService_collectMemoryDumpWithOptions_args() noexcept;
  MemoryDumpOptions options;

  _ImageManagementService_collectMemoryDumpWithOptions_args__isset __isset;

  void __set_options(const MemoryDumpOptions& val);

  bool operator == (const ImageManagementService_collectMemoryDumpWithOptions_args & rhs) const
  {
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_collectMemoryDumpWithOptions_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_collectMemoryDumpWithOptions_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_collectMemoryDumpWithOptions_pargs {
 public:


  virtual ~ImageManagementService_collectMemoryDumpWithOptions_pargs() noexcept;
  const MemoryDumpOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_collectMemoryDumpWithOptions_result__isset {
  _ImageManagementService_collectMemoryDumpWithOptions_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_collectMemoryDumpWithOptions_result__isset;

class ImageManagementService_collectMemoryDumpWithOptions_result {
 public:

  ImageManagementService_collectMemoryDumpWithOptions_result(const ImageManagementService_collectMemoryDumpWithOptions_result&);
  ImageManagementService_collectMemoryDumpWithOptions_result& operator=(const ImageManagementService_collectMemoryDumpWithOptions_result&);
  ImageManagementService_collectMemoryDumpWithOptions_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_collectMemoryDumpWithOptions_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_collectMemoryDumpWithOptions_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_collectMemoryDumpWithOptions_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_collectMemoryDumpWithOptions_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_collectMemoryDumpWithOptions_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_collectMemoryDumpWithOptions_presult__isset {
  _ImageManagementService_collectMemoryDumpWithOptions_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_collectMemoryDumpWithOptions_presult__isset;

class ImageManagementService_collectMemoryDumpWithOptions_presult {
 public:


  virtual ~ImageManagementService_collectMemoryDumpWithOptions_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_collectMemoryDumpWithOptions_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_startRemoteEfsSync_args__isset {
  _ImageManagementService_startRemoteEfsSync_args__isset() : pathName(false) {}
  bool pathName :1;
} _ImageManagementService_startRemoteEfsSync_args__isset;

class ImageManagementService_startRemoteEfsSync_args {
 public:

  ImageManagementService_startRemoteEfsSync_args(const ImageManagementService_startRemoteEfsSync_args&);
  ImageManagementService_startRemoteEfsSync_args& operator=(const ImageManagementService_startRemoteEfsSync_args&);
  ImageManagementService_startRemoteEfsSync_args() : pathName() {
  }

  virtual ~ImageManagementService_startRemoteEfsSync_args() noexcept;
  std::string pathName;

  _ImageManagementService_startRemoteEfsSync_args__isset __isset;

  void __set_pathName(const std::string& val);

  bool operator == (const ImageManagementService_startRemoteEfsSync_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_startRemoteEfsSync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_startRemoteEfsSync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_startRemoteEfsSync_pargs {
 public:


  virtual ~ImageManagementService_startRemoteEfsSync_pargs() noexcept;
  const std::string* pathName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_startRemoteEfsSync_result__isset {
  _ImageManagementService_startRemoteEfsSync_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_startRemoteEfsSync_result__isset;

class ImageManagementService_startRemoteEfsSync_result {
 public:

  ImageManagementService_startRemoteEfsSync_result(const ImageManagementService_startRemoteEfsSync_result&);
  ImageManagementService_startRemoteEfsSync_result& operator=(const ImageManagementService_startRemoteEfsSync_result&);
  ImageManagementService_startRemoteEfsSync_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_startRemoteEfsSync_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_startRemoteEfsSync_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_startRemoteEfsSync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_startRemoteEfsSync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_startRemoteEfsSync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_startRemoteEfsSync_presult__isset {
  _ImageManagementService_startRemoteEfsSync_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_startRemoteEfsSync_presult__isset;

class ImageManagementService_startRemoteEfsSync_presult {
 public:


  virtual ~ImageManagementService_startRemoteEfsSync_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_startRemoteEfsSync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ImageManagementService_stopRemoteEfsSync_args {
 public:

  ImageManagementService_stopRemoteEfsSync_args(const ImageManagementService_stopRemoteEfsSync_args&);
  ImageManagementService_stopRemoteEfsSync_args& operator=(const ImageManagementService_stopRemoteEfsSync_args&);
  ImageManagementService_stopRemoteEfsSync_args() {
  }

  virtual ~ImageManagementService_stopRemoteEfsSync_args() noexcept;

  bool operator == (const ImageManagementService_stopRemoteEfsSync_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ImageManagementService_stopRemoteEfsSync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_stopRemoteEfsSync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_stopRemoteEfsSync_pargs {
 public:


  virtual ~ImageManagementService_stopRemoteEfsSync_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_stopRemoteEfsSync_result__isset {
  _ImageManagementService_stopRemoteEfsSync_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_stopRemoteEfsSync_result__isset;

class ImageManagementService_stopRemoteEfsSync_result {
 public:

  ImageManagementService_stopRemoteEfsSync_result(const ImageManagementService_stopRemoteEfsSync_result&);
  ImageManagementService_stopRemoteEfsSync_result& operator=(const ImageManagementService_stopRemoteEfsSync_result&);
  ImageManagementService_stopRemoteEfsSync_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_stopRemoteEfsSync_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_stopRemoteEfsSync_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_stopRemoteEfsSync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_stopRemoteEfsSync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_stopRemoteEfsSync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_stopRemoteEfsSync_presult__isset {
  _ImageManagementService_stopRemoteEfsSync_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_stopRemoteEfsSync_presult__isset;

class ImageManagementService_stopRemoteEfsSync_presult {
 public:


  virtual ~ImageManagementService_stopRemoteEfsSync_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_stopRemoteEfsSync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_setDdrStorePath_args__isset {
  _ImageManagementService_setDdrStorePath_args__isset() : ddrStorePath(false) {}
  bool ddrStorePath :1;
} _ImageManagementService_setDdrStorePath_args__isset;

class ImageManagementService_setDdrStorePath_args {
 public:

  ImageManagementService_setDdrStorePath_args(const ImageManagementService_setDdrStorePath_args&);
  ImageManagementService_setDdrStorePath_args& operator=(const ImageManagementService_setDdrStorePath_args&);
  ImageManagementService_setDdrStorePath_args() : ddrStorePath() {
  }

  virtual ~ImageManagementService_setDdrStorePath_args() noexcept;
  std::string ddrStorePath;

  _ImageManagementService_setDdrStorePath_args__isset __isset;

  void __set_ddrStorePath(const std::string& val);

  bool operator == (const ImageManagementService_setDdrStorePath_args & rhs) const
  {
    if (!(ddrStorePath == rhs.ddrStorePath))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_setDdrStorePath_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_setDdrStorePath_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_setDdrStorePath_pargs {
 public:


  virtual ~ImageManagementService_setDdrStorePath_pargs() noexcept;
  const std::string* ddrStorePath;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_setDdrStorePath_result__isset {
  _ImageManagementService_setDdrStorePath_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_setDdrStorePath_result__isset;

class ImageManagementService_setDdrStorePath_result {
 public:

  ImageManagementService_setDdrStorePath_result(const ImageManagementService_setDdrStorePath_result&);
  ImageManagementService_setDdrStorePath_result& operator=(const ImageManagementService_setDdrStorePath_result&);
  ImageManagementService_setDdrStorePath_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_setDdrStorePath_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_setDdrStorePath_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_setDdrStorePath_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_setDdrStorePath_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_setDdrStorePath_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_setDdrStorePath_presult__isset {
  _ImageManagementService_setDdrStorePath_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_setDdrStorePath_presult__isset;

class ImageManagementService_setDdrStorePath_presult {
 public:


  virtual ~ImageManagementService_setDdrStorePath_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_setDdrStorePath_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_resetDevice_args__isset {
  _ImageManagementService_resetDevice_args__isset() : timeout(false) {}
  bool timeout :1;
} _ImageManagementService_resetDevice_args__isset;

class ImageManagementService_resetDevice_args {
 public:

  ImageManagementService_resetDevice_args(const ImageManagementService_resetDevice_args&);
  ImageManagementService_resetDevice_args& operator=(const ImageManagementService_resetDevice_args&);
  ImageManagementService_resetDevice_args() : timeout(0) {
  }

  virtual ~ImageManagementService_resetDevice_args() noexcept;
  int32_t timeout;

  _ImageManagementService_resetDevice_args__isset __isset;

  void __set_timeout(const int32_t val);

  bool operator == (const ImageManagementService_resetDevice_args & rhs) const
  {
    if (!(timeout == rhs.timeout))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_resetDevice_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_resetDevice_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_resetDevice_pargs {
 public:


  virtual ~ImageManagementService_resetDevice_pargs() noexcept;
  const int32_t* timeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_resetDevice_result__isset {
  _ImageManagementService_resetDevice_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_resetDevice_result__isset;

class ImageManagementService_resetDevice_result {
 public:

  ImageManagementService_resetDevice_result(const ImageManagementService_resetDevice_result&);
  ImageManagementService_resetDevice_result& operator=(const ImageManagementService_resetDevice_result&);
  ImageManagementService_resetDevice_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_resetDevice_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_resetDevice_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_resetDevice_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_resetDevice_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_resetDevice_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_resetDevice_presult__isset {
  _ImageManagementService_resetDevice_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_resetDevice_presult__isset;

class ImageManagementService_resetDevice_presult {
 public:


  virtual ~ImageManagementService_resetDevice_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_resetDevice_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ImageManagementService_switchToEdl_args {
 public:

  ImageManagementService_switchToEdl_args(const ImageManagementService_switchToEdl_args&);
  ImageManagementService_switchToEdl_args& operator=(const ImageManagementService_switchToEdl_args&);
  ImageManagementService_switchToEdl_args() {
  }

  virtual ~ImageManagementService_switchToEdl_args() noexcept;

  bool operator == (const ImageManagementService_switchToEdl_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ImageManagementService_switchToEdl_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_switchToEdl_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_switchToEdl_pargs {
 public:


  virtual ~ImageManagementService_switchToEdl_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_switchToEdl_result__isset {
  _ImageManagementService_switchToEdl_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_switchToEdl_result__isset;

class ImageManagementService_switchToEdl_result {
 public:

  ImageManagementService_switchToEdl_result(const ImageManagementService_switchToEdl_result&);
  ImageManagementService_switchToEdl_result& operator=(const ImageManagementService_switchToEdl_result&);
  ImageManagementService_switchToEdl_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_switchToEdl_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_switchToEdl_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_switchToEdl_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_switchToEdl_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_switchToEdl_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_switchToEdl_presult__isset {
  _ImageManagementService_switchToEdl_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_switchToEdl_presult__isset;

class ImageManagementService_switchToEdl_presult {
 public:


  virtual ~ImageManagementService_switchToEdl_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_switchToEdl_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_erasePartition_args__isset {
  _ImageManagementService_erasePartition_args__isset() : options(false) {}
  bool options :1;
} _ImageManagementService_erasePartition_args__isset;

class ImageManagementService_erasePartition_args {
 public:

  ImageManagementService_erasePartition_args(const ImageManagementService_erasePartition_args&);
  ImageManagementService_erasePartition_args& operator=(const ImageManagementService_erasePartition_args&);
  ImageManagementService_erasePartition_args() {
  }

  virtual ~ImageManagementService_erasePartition_args() noexcept;
  DownloadBuildOptions options;

  _ImageManagementService_erasePartition_args__isset __isset;

  void __set_options(const DownloadBuildOptions& val);

  bool operator == (const ImageManagementService_erasePartition_args & rhs) const
  {
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_erasePartition_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_erasePartition_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_erasePartition_pargs {
 public:


  virtual ~ImageManagementService_erasePartition_pargs() noexcept;
  const DownloadBuildOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_erasePartition_result__isset {
  _ImageManagementService_erasePartition_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_erasePartition_result__isset;

class ImageManagementService_erasePartition_result {
 public:

  ImageManagementService_erasePartition_result(const ImageManagementService_erasePartition_result&);
  ImageManagementService_erasePartition_result& operator=(const ImageManagementService_erasePartition_result&);
  ImageManagementService_erasePartition_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_erasePartition_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_erasePartition_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_erasePartition_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_erasePartition_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_erasePartition_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_erasePartition_presult__isset {
  _ImageManagementService_erasePartition_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_erasePartition_presult__isset;

class ImageManagementService_erasePartition_presult {
 public:


  virtual ~ImageManagementService_erasePartition_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_erasePartition_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_getFlashInfo_args__isset {
  _ImageManagementService_getFlashInfo_args__isset() : options(false) {}
  bool options :1;
} _ImageManagementService_getFlashInfo_args__isset;

class ImageManagementService_getFlashInfo_args {
 public:

  ImageManagementService_getFlashInfo_args(const ImageManagementService_getFlashInfo_args&);
  ImageManagementService_getFlashInfo_args& operator=(const ImageManagementService_getFlashInfo_args&);
  ImageManagementService_getFlashInfo_args() {
  }

  virtual ~ImageManagementService_getFlashInfo_args() noexcept;
  DownloadBuildOptions options;

  _ImageManagementService_getFlashInfo_args__isset __isset;

  void __set_options(const DownloadBuildOptions& val);

  bool operator == (const ImageManagementService_getFlashInfo_args & rhs) const
  {
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_getFlashInfo_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_getFlashInfo_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_getFlashInfo_pargs {
 public:


  virtual ~ImageManagementService_getFlashInfo_pargs() noexcept;
  const DownloadBuildOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_getFlashInfo_result__isset {
  _ImageManagementService_getFlashInfo_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_getFlashInfo_result__isset;

class ImageManagementService_getFlashInfo_result {
 public:

  ImageManagementService_getFlashInfo_result(const ImageManagementService_getFlashInfo_result&);
  ImageManagementService_getFlashInfo_result& operator=(const ImageManagementService_getFlashInfo_result&);
  ImageManagementService_getFlashInfo_result() {
  }

  virtual ~ImageManagementService_getFlashInfo_result() noexcept;
  std::vector<FlashInfo>  success;
   ::Uts::AppException e;

  _ImageManagementService_getFlashInfo_result__isset __isset;

  void __set_success(const std::vector<FlashInfo> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_getFlashInfo_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_getFlashInfo_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_getFlashInfo_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_getFlashInfo_presult__isset {
  _ImageManagementService_getFlashInfo_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_getFlashInfo_presult__isset;

class ImageManagementService_getFlashInfo_presult {
 public:


  virtual ~ImageManagementService_getFlashInfo_presult() noexcept;
  std::vector<FlashInfo> * success;
   ::Uts::AppException e;

  _ImageManagementService_getFlashInfo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_initPartitionTable_args__isset {
  _ImageManagementService_initPartitionTable_args__isset() : options(false) {}
  bool options :1;
} _ImageManagementService_initPartitionTable_args__isset;

class ImageManagementService_initPartitionTable_args {
 public:

  ImageManagementService_initPartitionTable_args(const ImageManagementService_initPartitionTable_args&);
  ImageManagementService_initPartitionTable_args& operator=(const ImageManagementService_initPartitionTable_args&);
  ImageManagementService_initPartitionTable_args() {
  }

  virtual ~ImageManagementService_initPartitionTable_args() noexcept;
  DownloadBuildOptions options;

  _ImageManagementService_initPartitionTable_args__isset __isset;

  void __set_options(const DownloadBuildOptions& val);

  bool operator == (const ImageManagementService_initPartitionTable_args & rhs) const
  {
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_initPartitionTable_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_initPartitionTable_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_initPartitionTable_pargs {
 public:


  virtual ~ImageManagementService_initPartitionTable_pargs() noexcept;
  const DownloadBuildOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_initPartitionTable_result__isset {
  _ImageManagementService_initPartitionTable_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_initPartitionTable_result__isset;

class ImageManagementService_initPartitionTable_result {
 public:

  ImageManagementService_initPartitionTable_result(const ImageManagementService_initPartitionTable_result&);
  ImageManagementService_initPartitionTable_result& operator=(const ImageManagementService_initPartitionTable_result&);
  ImageManagementService_initPartitionTable_result() {
  }

  virtual ~ImageManagementService_initPartitionTable_result() noexcept;
  std::vector<PartitionInfo>  success;
   ::Uts::AppException e;

  _ImageManagementService_initPartitionTable_result__isset __isset;

  void __set_success(const std::vector<PartitionInfo> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_initPartitionTable_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_initPartitionTable_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_initPartitionTable_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_initPartitionTable_presult__isset {
  _ImageManagementService_initPartitionTable_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_initPartitionTable_presult__isset;

class ImageManagementService_initPartitionTable_presult {
 public:


  virtual ~ImageManagementService_initPartitionTable_presult() noexcept;
  std::vector<PartitionInfo> * success;
   ::Uts::AppException e;

  _ImageManagementService_initPartitionTable_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_readPartitionData_args__isset {
  _ImageManagementService_readPartitionData_args__isset() : dataChunks(false) {}
  bool dataChunks :1;
} _ImageManagementService_readPartitionData_args__isset;

class ImageManagementService_readPartitionData_args {
 public:

  ImageManagementService_readPartitionData_args(const ImageManagementService_readPartitionData_args&);
  ImageManagementService_readPartitionData_args& operator=(const ImageManagementService_readPartitionData_args&);
  ImageManagementService_readPartitionData_args() {
  }

  virtual ~ImageManagementService_readPartitionData_args() noexcept;
  std::vector<DataChunkOptions>  dataChunks;

  _ImageManagementService_readPartitionData_args__isset __isset;

  void __set_dataChunks(const std::vector<DataChunkOptions> & val);

  bool operator == (const ImageManagementService_readPartitionData_args & rhs) const
  {
    if (!(dataChunks == rhs.dataChunks))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_readPartitionData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_readPartitionData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_readPartitionData_pargs {
 public:


  virtual ~ImageManagementService_readPartitionData_pargs() noexcept;
  const std::vector<DataChunkOptions> * dataChunks;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_readPartitionData_result__isset {
  _ImageManagementService_readPartitionData_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_readPartitionData_result__isset;

class ImageManagementService_readPartitionData_result {
 public:

  ImageManagementService_readPartitionData_result(const ImageManagementService_readPartitionData_result&);
  ImageManagementService_readPartitionData_result& operator=(const ImageManagementService_readPartitionData_result&);
  ImageManagementService_readPartitionData_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_readPartitionData_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_readPartitionData_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_readPartitionData_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_readPartitionData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_readPartitionData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_readPartitionData_presult__isset {
  _ImageManagementService_readPartitionData_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_readPartitionData_presult__isset;

class ImageManagementService_readPartitionData_presult {
 public:


  virtual ~ImageManagementService_readPartitionData_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_readPartitionData_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_writePartitionData_args__isset {
  _ImageManagementService_writePartitionData_args__isset() : dataChunks(false) {}
  bool dataChunks :1;
} _ImageManagementService_writePartitionData_args__isset;

class ImageManagementService_writePartitionData_args {
 public:

  ImageManagementService_writePartitionData_args(const ImageManagementService_writePartitionData_args&);
  ImageManagementService_writePartitionData_args& operator=(const ImageManagementService_writePartitionData_args&);
  ImageManagementService_writePartitionData_args() {
  }

  virtual ~ImageManagementService_writePartitionData_args() noexcept;
  std::vector<DataChunkOptions>  dataChunks;

  _ImageManagementService_writePartitionData_args__isset __isset;

  void __set_dataChunks(const std::vector<DataChunkOptions> & val);

  bool operator == (const ImageManagementService_writePartitionData_args & rhs) const
  {
    if (!(dataChunks == rhs.dataChunks))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_writePartitionData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_writePartitionData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_writePartitionData_pargs {
 public:


  virtual ~ImageManagementService_writePartitionData_pargs() noexcept;
  const std::vector<DataChunkOptions> * dataChunks;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_writePartitionData_result__isset {
  _ImageManagementService_writePartitionData_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_writePartitionData_result__isset;

class ImageManagementService_writePartitionData_result {
 public:

  ImageManagementService_writePartitionData_result(const ImageManagementService_writePartitionData_result&);
  ImageManagementService_writePartitionData_result& operator=(const ImageManagementService_writePartitionData_result&);
  ImageManagementService_writePartitionData_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_writePartitionData_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_writePartitionData_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_writePartitionData_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_writePartitionData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_writePartitionData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_writePartitionData_presult__isset {
  _ImageManagementService_writePartitionData_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_writePartitionData_presult__isset;

class ImageManagementService_writePartitionData_presult {
 public:


  virtual ~ImageManagementService_writePartitionData_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_writePartitionData_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ImageManagementService_erasePartitionData_args__isset {
  _ImageManagementService_erasePartitionData_args__isset() : dataChunks(false) {}
  bool dataChunks :1;
} _ImageManagementService_erasePartitionData_args__isset;

class ImageManagementService_erasePartitionData_args {
 public:

  ImageManagementService_erasePartitionData_args(const ImageManagementService_erasePartitionData_args&);
  ImageManagementService_erasePartitionData_args& operator=(const ImageManagementService_erasePartitionData_args&);
  ImageManagementService_erasePartitionData_args() {
  }

  virtual ~ImageManagementService_erasePartitionData_args() noexcept;
  std::vector<DataChunkOptions>  dataChunks;

  _ImageManagementService_erasePartitionData_args__isset __isset;

  void __set_dataChunks(const std::vector<DataChunkOptions> & val);

  bool operator == (const ImageManagementService_erasePartitionData_args & rhs) const
  {
    if (!(dataChunks == rhs.dataChunks))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_erasePartitionData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_erasePartitionData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ImageManagementService_erasePartitionData_pargs {
 public:


  virtual ~ImageManagementService_erasePartitionData_pargs() noexcept;
  const std::vector<DataChunkOptions> * dataChunks;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_erasePartitionData_result__isset {
  _ImageManagementService_erasePartitionData_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_erasePartitionData_result__isset;

class ImageManagementService_erasePartitionData_result {
 public:

  ImageManagementService_erasePartitionData_result(const ImageManagementService_erasePartitionData_result&);
  ImageManagementService_erasePartitionData_result& operator=(const ImageManagementService_erasePartitionData_result&);
  ImageManagementService_erasePartitionData_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~ImageManagementService_erasePartitionData_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _ImageManagementService_erasePartitionData_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const ImageManagementService_erasePartitionData_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const ImageManagementService_erasePartitionData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ImageManagementService_erasePartitionData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ImageManagementService_erasePartitionData_presult__isset {
  _ImageManagementService_erasePartitionData_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _ImageManagementService_erasePartitionData_presult__isset;

class ImageManagementService_erasePartitionData_presult {
 public:


  virtual ~ImageManagementService_erasePartitionData_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _ImageManagementService_erasePartitionData_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ImageManagementServiceClient : virtual public ImageManagementServiceIf {
 public:
  ImageManagementServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ImageManagementServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getLastError( ::Uts::ErrorType& _return);
  void send_getLastError();
  void recv_getLastError( ::Uts::ErrorType& _return);
   ::Uts::ErrorCode::type initializeService();
  void send_initializeService();
   ::Uts::ErrorCode::type recv_initializeService();
   ::Uts::ErrorCode::type destroyService();
  void send_destroyService();
   ::Uts::ErrorCode::type recv_destroyService();
  DeviceImageMode::type getDeviceImageMode();
  void send_getDeviceImageMode();
  DeviceImageMode::type recv_getDeviceImageMode();
  void transferImages(TransferImageResult& _return, const std::map<int32_t, std::string> & imageList);
  void send_transferImages(const std::map<int32_t, std::string> & imageList);
  void recv_transferImages(TransferImageResult& _return);
  void getDeviceInfo(EdlDeviceInfo& _return);
  void send_getDeviceInfo();
  void recv_getDeviceInfo(EdlDeviceInfo& _return);
   ::Uts::ErrorCode::type collectPblDumpV3(const std::string& pathName);
  void send_collectPblDumpV3(const std::string& pathName);
   ::Uts::ErrorCode::type recv_collectPblDumpV3();
   ::Uts::ErrorCode::type downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options);
  void send_downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options);
   ::Uts::ErrorCode::type recv_downloadBuild();
   ::Uts::ErrorCode::type collectMemoryDump(const std::string& pathName);
  void send_collectMemoryDump(const std::string& pathName);
   ::Uts::ErrorCode::type recv_collectMemoryDump();
   ::Uts::ErrorCode::type collectMemoryDumpWithOptions(const MemoryDumpOptions& options);
  void send_collectMemoryDumpWithOptions(const MemoryDumpOptions& options);
   ::Uts::ErrorCode::type recv_collectMemoryDumpWithOptions();
   ::Uts::ErrorCode::type startRemoteEfsSync(const std::string& pathName);
  void send_startRemoteEfsSync(const std::string& pathName);
   ::Uts::ErrorCode::type recv_startRemoteEfsSync();
   ::Uts::ErrorCode::type stopRemoteEfsSync();
  void send_stopRemoteEfsSync();
   ::Uts::ErrorCode::type recv_stopRemoteEfsSync();
   ::Uts::ErrorCode::type setDdrStorePath(const std::string& ddrStorePath);
  void send_setDdrStorePath(const std::string& ddrStorePath);
   ::Uts::ErrorCode::type recv_setDdrStorePath();
   ::Uts::ErrorCode::type resetDevice(const int32_t timeout);
  void send_resetDevice(const int32_t timeout);
   ::Uts::ErrorCode::type recv_resetDevice();
   ::Uts::ErrorCode::type switchToEdl();
  void send_switchToEdl();
   ::Uts::ErrorCode::type recv_switchToEdl();
   ::Uts::ErrorCode::type erasePartition(const DownloadBuildOptions& options);
  void send_erasePartition(const DownloadBuildOptions& options);
   ::Uts::ErrorCode::type recv_erasePartition();
  void getFlashInfo(std::vector<FlashInfo> & _return, const DownloadBuildOptions& options);
  void send_getFlashInfo(const DownloadBuildOptions& options);
  void recv_getFlashInfo(std::vector<FlashInfo> & _return);
  void initPartitionTable(std::vector<PartitionInfo> & _return, const DownloadBuildOptions& options);
  void send_initPartitionTable(const DownloadBuildOptions& options);
  void recv_initPartitionTable(std::vector<PartitionInfo> & _return);
   ::Uts::ErrorCode::type readPartitionData(const std::vector<DataChunkOptions> & dataChunks);
  void send_readPartitionData(const std::vector<DataChunkOptions> & dataChunks);
   ::Uts::ErrorCode::type recv_readPartitionData();
   ::Uts::ErrorCode::type writePartitionData(const std::vector<DataChunkOptions> & dataChunks);
  void send_writePartitionData(const std::vector<DataChunkOptions> & dataChunks);
   ::Uts::ErrorCode::type recv_writePartitionData();
   ::Uts::ErrorCode::type erasePartitionData(const std::vector<DataChunkOptions> & dataChunks);
  void send_erasePartitionData(const std::vector<DataChunkOptions> & dataChunks);
   ::Uts::ErrorCode::type recv_erasePartitionData();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ImageManagementServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<ImageManagementServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ImageManagementServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getLastError(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_initializeService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_destroyService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDeviceImageMode(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_transferImages(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDeviceInfo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_collectPblDumpV3(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_downloadBuild(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_collectMemoryDump(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_collectMemoryDumpWithOptions(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startRemoteEfsSync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_stopRemoteEfsSync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setDdrStorePath(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_resetDevice(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_switchToEdl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_erasePartition(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getFlashInfo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_initPartitionTable(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_readPartitionData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_writePartitionData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_erasePartitionData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ImageManagementServiceProcessor(::std::shared_ptr<ImageManagementServiceIf> iface) :
    iface_(iface) {
    processMap_["getLastError"] = &ImageManagementServiceProcessor::process_getLastError;
    processMap_["initializeService"] = &ImageManagementServiceProcessor::process_initializeService;
    processMap_["destroyService"] = &ImageManagementServiceProcessor::process_destroyService;
    processMap_["getDeviceImageMode"] = &ImageManagementServiceProcessor::process_getDeviceImageMode;
    processMap_["transferImages"] = &ImageManagementServiceProcessor::process_transferImages;
    processMap_["getDeviceInfo"] = &ImageManagementServiceProcessor::process_getDeviceInfo;
    processMap_["collectPblDumpV3"] = &ImageManagementServiceProcessor::process_collectPblDumpV3;
    processMap_["downloadBuild"] = &ImageManagementServiceProcessor::process_downloadBuild;
    processMap_["collectMemoryDump"] = &ImageManagementServiceProcessor::process_collectMemoryDump;
    processMap_["collectMemoryDumpWithOptions"] = &ImageManagementServiceProcessor::process_collectMemoryDumpWithOptions;
    processMap_["startRemoteEfsSync"] = &ImageManagementServiceProcessor::process_startRemoteEfsSync;
    processMap_["stopRemoteEfsSync"] = &ImageManagementServiceProcessor::process_stopRemoteEfsSync;
    processMap_["setDdrStorePath"] = &ImageManagementServiceProcessor::process_setDdrStorePath;
    processMap_["resetDevice"] = &ImageManagementServiceProcessor::process_resetDevice;
    processMap_["switchToEdl"] = &ImageManagementServiceProcessor::process_switchToEdl;
    processMap_["erasePartition"] = &ImageManagementServiceProcessor::process_erasePartition;
    processMap_["getFlashInfo"] = &ImageManagementServiceProcessor::process_getFlashInfo;
    processMap_["initPartitionTable"] = &ImageManagementServiceProcessor::process_initPartitionTable;
    processMap_["readPartitionData"] = &ImageManagementServiceProcessor::process_readPartitionData;
    processMap_["writePartitionData"] = &ImageManagementServiceProcessor::process_writePartitionData;
    processMap_["erasePartitionData"] = &ImageManagementServiceProcessor::process_erasePartitionData;
  }

  virtual ~ImageManagementServiceProcessor() {}
};

class ImageManagementServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ImageManagementServiceProcessorFactory(const ::std::shared_ptr< ImageManagementServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< ImageManagementServiceIfFactory > handlerFactory_;
};

class ImageManagementServiceMultiface : virtual public ImageManagementServiceIf {
 public:
  ImageManagementServiceMultiface(std::vector<std::shared_ptr<ImageManagementServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ImageManagementServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<ImageManagementServiceIf> > ifaces_;
  ImageManagementServiceMultiface() {}
  void add(::std::shared_ptr<ImageManagementServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getLastError( ::Uts::ErrorType& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getLastError(_return);
    }
    ifaces_[i]->getLastError(_return);
    return;
  }

   ::Uts::ErrorCode::type initializeService() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->initializeService();
    }
    return ifaces_[i]->initializeService();
  }

   ::Uts::ErrorCode::type destroyService() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->destroyService();
    }
    return ifaces_[i]->destroyService();
  }

  DeviceImageMode::type getDeviceImageMode() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDeviceImageMode();
    }
    return ifaces_[i]->getDeviceImageMode();
  }

  void transferImages(TransferImageResult& _return, const std::map<int32_t, std::string> & imageList) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->transferImages(_return, imageList);
    }
    ifaces_[i]->transferImages(_return, imageList);
    return;
  }

  void getDeviceInfo(EdlDeviceInfo& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDeviceInfo(_return);
    }
    ifaces_[i]->getDeviceInfo(_return);
    return;
  }

   ::Uts::ErrorCode::type collectPblDumpV3(const std::string& pathName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->collectPblDumpV3(pathName);
    }
    return ifaces_[i]->collectPblDumpV3(pathName);
  }

   ::Uts::ErrorCode::type downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->downloadBuild(buildPath, options);
    }
    return ifaces_[i]->downloadBuild(buildPath, options);
  }

   ::Uts::ErrorCode::type collectMemoryDump(const std::string& pathName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->collectMemoryDump(pathName);
    }
    return ifaces_[i]->collectMemoryDump(pathName);
  }

   ::Uts::ErrorCode::type collectMemoryDumpWithOptions(const MemoryDumpOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->collectMemoryDumpWithOptions(options);
    }
    return ifaces_[i]->collectMemoryDumpWithOptions(options);
  }

   ::Uts::ErrorCode::type startRemoteEfsSync(const std::string& pathName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->startRemoteEfsSync(pathName);
    }
    return ifaces_[i]->startRemoteEfsSync(pathName);
  }

   ::Uts::ErrorCode::type stopRemoteEfsSync() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->stopRemoteEfsSync();
    }
    return ifaces_[i]->stopRemoteEfsSync();
  }

   ::Uts::ErrorCode::type setDdrStorePath(const std::string& ddrStorePath) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setDdrStorePath(ddrStorePath);
    }
    return ifaces_[i]->setDdrStorePath(ddrStorePath);
  }

   ::Uts::ErrorCode::type resetDevice(const int32_t timeout) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->resetDevice(timeout);
    }
    return ifaces_[i]->resetDevice(timeout);
  }

   ::Uts::ErrorCode::type switchToEdl() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->switchToEdl();
    }
    return ifaces_[i]->switchToEdl();
  }

   ::Uts::ErrorCode::type erasePartition(const DownloadBuildOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->erasePartition(options);
    }
    return ifaces_[i]->erasePartition(options);
  }

  void getFlashInfo(std::vector<FlashInfo> & _return, const DownloadBuildOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getFlashInfo(_return, options);
    }
    ifaces_[i]->getFlashInfo(_return, options);
    return;
  }

  void initPartitionTable(std::vector<PartitionInfo> & _return, const DownloadBuildOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->initPartitionTable(_return, options);
    }
    ifaces_[i]->initPartitionTable(_return, options);
    return;
  }

   ::Uts::ErrorCode::type readPartitionData(const std::vector<DataChunkOptions> & dataChunks) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->readPartitionData(dataChunks);
    }
    return ifaces_[i]->readPartitionData(dataChunks);
  }

   ::Uts::ErrorCode::type writePartitionData(const std::vector<DataChunkOptions> & dataChunks) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->writePartitionData(dataChunks);
    }
    return ifaces_[i]->writePartitionData(dataChunks);
  }

   ::Uts::ErrorCode::type erasePartitionData(const std::vector<DataChunkOptions> & dataChunks) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->erasePartitionData(dataChunks);
    }
    return ifaces_[i]->erasePartitionData(dataChunks);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ImageManagementServiceConcurrentClient : virtual public ImageManagementServiceIf {
 public:
  ImageManagementServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  ImageManagementServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getLastError( ::Uts::ErrorType& _return);
  int32_t send_getLastError();
  void recv_getLastError( ::Uts::ErrorType& _return, const int32_t seqid);
   ::Uts::ErrorCode::type initializeService();
  int32_t send_initializeService();
   ::Uts::ErrorCode::type recv_initializeService(const int32_t seqid);
   ::Uts::ErrorCode::type destroyService();
  int32_t send_destroyService();
   ::Uts::ErrorCode::type recv_destroyService(const int32_t seqid);
  DeviceImageMode::type getDeviceImageMode();
  int32_t send_getDeviceImageMode();
  DeviceImageMode::type recv_getDeviceImageMode(const int32_t seqid);
  void transferImages(TransferImageResult& _return, const std::map<int32_t, std::string> & imageList);
  int32_t send_transferImages(const std::map<int32_t, std::string> & imageList);
  void recv_transferImages(TransferImageResult& _return, const int32_t seqid);
  void getDeviceInfo(EdlDeviceInfo& _return);
  int32_t send_getDeviceInfo();
  void recv_getDeviceInfo(EdlDeviceInfo& _return, const int32_t seqid);
   ::Uts::ErrorCode::type collectPblDumpV3(const std::string& pathName);
  int32_t send_collectPblDumpV3(const std::string& pathName);
   ::Uts::ErrorCode::type recv_collectPblDumpV3(const int32_t seqid);
   ::Uts::ErrorCode::type downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options);
  int32_t send_downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options);
   ::Uts::ErrorCode::type recv_downloadBuild(const int32_t seqid);
   ::Uts::ErrorCode::type collectMemoryDump(const std::string& pathName);
  int32_t send_collectMemoryDump(const std::string& pathName);
   ::Uts::ErrorCode::type recv_collectMemoryDump(const int32_t seqid);
   ::Uts::ErrorCode::type collectMemoryDumpWithOptions(const MemoryDumpOptions& options);
  int32_t send_collectMemoryDumpWithOptions(const MemoryDumpOptions& options);
   ::Uts::ErrorCode::type recv_collectMemoryDumpWithOptions(const int32_t seqid);
   ::Uts::ErrorCode::type startRemoteEfsSync(const std::string& pathName);
  int32_t send_startRemoteEfsSync(const std::string& pathName);
   ::Uts::ErrorCode::type recv_startRemoteEfsSync(const int32_t seqid);
   ::Uts::ErrorCode::type stopRemoteEfsSync();
  int32_t send_stopRemoteEfsSync();
   ::Uts::ErrorCode::type recv_stopRemoteEfsSync(const int32_t seqid);
   ::Uts::ErrorCode::type setDdrStorePath(const std::string& ddrStorePath);
  int32_t send_setDdrStorePath(const std::string& ddrStorePath);
   ::Uts::ErrorCode::type recv_setDdrStorePath(const int32_t seqid);
   ::Uts::ErrorCode::type resetDevice(const int32_t timeout);
  int32_t send_resetDevice(const int32_t timeout);
   ::Uts::ErrorCode::type recv_resetDevice(const int32_t seqid);
   ::Uts::ErrorCode::type switchToEdl();
  int32_t send_switchToEdl();
   ::Uts::ErrorCode::type recv_switchToEdl(const int32_t seqid);
   ::Uts::ErrorCode::type erasePartition(const DownloadBuildOptions& options);
  int32_t send_erasePartition(const DownloadBuildOptions& options);
   ::Uts::ErrorCode::type recv_erasePartition(const int32_t seqid);
  void getFlashInfo(std::vector<FlashInfo> & _return, const DownloadBuildOptions& options);
  int32_t send_getFlashInfo(const DownloadBuildOptions& options);
  void recv_getFlashInfo(std::vector<FlashInfo> & _return, const int32_t seqid);
  void initPartitionTable(std::vector<PartitionInfo> & _return, const DownloadBuildOptions& options);
  int32_t send_initPartitionTable(const DownloadBuildOptions& options);
  void recv_initPartitionTable(std::vector<PartitionInfo> & _return, const int32_t seqid);
   ::Uts::ErrorCode::type readPartitionData(const std::vector<DataChunkOptions> & dataChunks);
  int32_t send_readPartitionData(const std::vector<DataChunkOptions> & dataChunks);
   ::Uts::ErrorCode::type recv_readPartitionData(const int32_t seqid);
   ::Uts::ErrorCode::type writePartitionData(const std::vector<DataChunkOptions> & dataChunks);
  int32_t send_writePartitionData(const std::vector<DataChunkOptions> & dataChunks);
   ::Uts::ErrorCode::type recv_writePartitionData(const int32_t seqid);
   ::Uts::ErrorCode::type erasePartitionData(const std::vector<DataChunkOptions> & dataChunks);
  int32_t send_erasePartitionData(const std::vector<DataChunkOptions> & dataChunks);
   ::Uts::ErrorCode::type recv_erasePartitionData(const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
