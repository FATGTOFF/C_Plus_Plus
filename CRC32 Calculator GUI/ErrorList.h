#ifndef _ERRORLIST_
#define _ERRORLIST_

#include <map>
#include <cerrno>
#include <string>
#include <iostream>
#include <fstream>

#define DEBUG_ERROR false

#if (DEBUG_ERROR)
#include <iterator>
#endif

class ErrorList
{
private:

   const std::map<const int, const std::string> errorMessageList
   {
      {E2BIG,           "Argument list too long."},
      {EACCES,          "Permission denied."},
      {EAGAIN,          "No more processes or not enough memory or maximum nesting level reached."},
      {EBADF,           "Bad file number."},
      {EBUSY,           "Device or resource busy."},
      {ECHILD,          "No spawned processes."},
      {EDEADLK,         "Resource deadlock would occur."},
      {EDOM,            "The argument to a math function isn't in the domain of the function."},
      {EEXIST,          "An attempt has been made to create a file that already exists."},
      {EFAULT,          "Bad address."},
      {EFBIG,           "File too large."},
      {EILSEQ,          "Illegal sequence of bytes."},
      {EINTR,           "Interrupted function."},
      {EINVAL,          "An invalid value was given for one of the arguments to a function."},
      {EIO,             "I/O error."},
      {EISDIR,          "Is a directory."},
      {EMFILE,          "Too many open files. No more file descriptors are available, so no more files can be opened."},
      {EMLINK,          "Too many links."},
      {ENAMETOOLONG,    "Filename too long."},
      {ENFILE,          "Too many files open in system."},
      {ENODEV,          "No such device."},
      {ENOENT,          "No such file or directory."},
      {ENOEXEC,         "Exec format error."},
      {ENOLCK,          "No locks available."},
      {ENOMEM,          "Not enough memory is available for the attempted operator."},
      {ENOSPC,          "No space left on device."},
      {ENOSYS,          "Function not supported."},
      {ENOTDIR,         "Not a directory."},
      {ENOTEMPTY,       "Directory not empty."},
      {ENOTTY,          "Inappropriate I/O control operation."},
      {ENXIO,           "No such device or address."},
      {EPERM,           "Operation not permitted."},
      {EPIPE,           "Broken pipe."},
      {ERANGE,          "An argument to a math function is too large, resulting in partial or total loss of significance in the result."},
      {EROFS,           "Read only file system."},
      {ESPIPE,          "Invalid seek."},
      {ESRCH,           "No such process."},
      {EXDEV,           "An attempt was made to move a file to a different device (using the rename function)."},
      {STRUNCATE,       "A string copy or concatenation resulted in a truncated string."},
      {EADDRINUSE,      "Address in use."},
      {EADDRNOTAVAIL,   "Address not available."},
      {EAFNOSUPPORT,    "Address family not supported."},
      {EALREADY,        "Connection already in progress."},
      {EBADMSG,         "Bad message."},
      {ECANCELED,       "Operation canceled.."},
      {ECONNABORTED,    "Connection aborted."},
      {ECONNREFUSED,    "Connection refused."},
      {ECONNRESET,      "Connection reset."},
      {EDESTADDRREQ,    "Destination address required."},
      {EHOSTUNREACH,    "Host unreachable."},
      {EIDRM,           "Identifier removed."},
      {EINPROGRESS,     "Operation in progress."},
      {EISCONN,         "Already connected."},
      {ELOOP,           "Too many symbolic link levels."},
      {EMSGSIZE,        "Message size."},
      {ENETDOWN,        "Network down."},
      {ENETRESET,       "Network reset."},
      {ENETUNREACH,     "Network unreachable."},
      {ENOBUFS,         "No buffer space."},
      {ENODATA,         "No message available."},
      {ENOLINK,         "No link."},
      {ENOMSG,          "No message."},
      {ENOPROTOOPT,     "No protocol option."},
      {ENOSR,           "No stream resources."},
      {ENOSTR,          "Not a stream."},
      {ENOTCONN,        "Not connected."},
      {ENOTRECOVERABLE, "State not recoverable."},
      {ENOTSOCK,        "Not a socket."},
      {ENOTSUP,         "Not supported."},
      {EOPNOTSUPP,      "Operation not supported."},
      {EOTHER,          "Other."},
      {EOVERFLOW,       "Value too large."},
      {EOWNERDEAD,      "Not a stream."},
      {EPROTO,          "Protocol error."},
      {EPROTONOSUPPORT, "Protocol not supported."},
      {EPROTOTYPE,	  "Wrong protocol type."},
      {ETIME,           "Stream timeout."},
      {ETIMEDOUT,       "Timed out."},
      {ETXTBSY,         "Text file busy."},
      {EWOULDBLOCK,     "Operation would block."}
   };

   const std::map<const int, const std::wstring> errorMessageList_w
   {
      {E2BIG,           L"Argument list too long."},
      {EACCES,          L"Permission denied."},
      {EAGAIN,          L"No more processes or not enough memory or maximum nesting level reached."},
      {EBADF,           L"Bad file number."},
      {EBUSY,           L"Device or resource busy."},
      {ECHILD,          L"No spawned processes."},
      {EDEADLK,         L"Resource deadlock would occur."},
      {EDOM,            L"The argument to a math function isn't in the domain of the function."},
      {EEXIST,          L"An attempt has been made to create a file that already exists."},
      {EFAULT,          L"Bad address."},
      {EFBIG,           L"File too large."},
      {EILSEQ,          L"Illegal sequence of bytes."},
      {EINTR,           L"Interrupted function."},
      {EINVAL,          L"An invalid value was given for one of the arguments to a function."},
      {EIO,             L"I/O error."},
      {EISDIR,          L"Is a directory."},
      {EMFILE,          L"Too many open files. No more file descriptors are available, so no more files can be opened."},
      {EMLINK,          L"Too many links."},
      {ENAMETOOLONG,    L"Filename too long."},
      {ENFILE,          L"Too many files open in system."},
      {ENODEV,          L"No such device."},
      {ENOENT,          L"No such file or directory."},
      {ENOEXEC,         L"Exec format error."},
      {ENOLCK,          L"No locks available."},
      {ENOMEM,          L"Not enough memory is available for the attempted operator."},
      {ENOSPC,          L"No space left on device."},
      {ENOSYS,          L"Function not supported."},
      {ENOTDIR,         L"Not a directory."},
      {ENOTEMPTY,       L"Directory not empty."},
      {ENOTTY,          L"Inappropriate I/O control operation."},
      {ENXIO,           L"No such device or address."},
      {EPERM,           L"Operation not permitted."},
      {EPIPE,           L"Broken pipe."},
      {ERANGE,          L"An argument to a math function is too large, resulting in partial or total loss of significance in the result."},
      {EROFS,           L"Read only file system."},
      {ESPIPE,          L"Invalid seek."},
      {ESRCH,           L"No such process."},
      {EXDEV,           L"An attempt was made to move a file to a different device (using the rename function)."},
      {STRUNCATE,       L"A string copy or concatenation resulted in a truncated string."},
      {EADDRINUSE,      L"Address in use."},
      {EADDRNOTAVAIL,   L"Address not available."},
      {EAFNOSUPPORT,    L"Address family not supported."},
      {EALREADY,        L"Connection already in progress."},
      {EBADMSG,         L"Bad message."},
      {ECANCELED,       L"Operation canceled.."},
      {ECONNABORTED,    L"Connection aborted."},
      {ECONNREFUSED,    L"Connection refused."},
      {ECONNRESET,      L"Connection reset."},
      {EDESTADDRREQ,    L"Destination address required."},
      {EHOSTUNREACH,    L"Host unreachable."},
      {EIDRM,           L"Identifier removed."},
      {EINPROGRESS,     L"Operation in progress."},
      {EISCONN,         L"Already connected."},
      {ELOOP,           L"Too many symbolic link levels."},
      {EMSGSIZE,        L"Message size."},
      {ENETDOWN,        L"Network down."},
      {ENETRESET,       L"Network reset."},
      {ENETUNREACH,     L"Network unreachable."},
      {ENOBUFS,         L"No buffer space."},
      {ENODATA,         L"No message available."},
      {ENOLINK,         L"No link."},
      {ENOMSG,          L"No message."},
      {ENOPROTOOPT,     L"No protocol option."},
      {ENOSR,           L"No stream resources."},
      {ENOSTR,          L"Not a stream."},
      {ENOTCONN,        L"Not connected."},
      {ENOTRECOVERABLE, L"State not recoverable."},
      {ENOTSOCK,        L"Not a socket."},
      {ENOTSUP,         L"Not supported."},
      {EOPNOTSUPP,      L"Operation not supported."},
      {EOTHER,          L"Other."},
      {EOVERFLOW,       L"Value too large."},
      {EOWNERDEAD,      L"Not a stream."},
      {EPROTO,          L"Protocol error."},
      {EPROTONOSUPPORT, L"Protocol not supported."},
      {EPROTOTYPE,	  L"Wrong protocol type."},
      {ETIME,           L"Stream timeout."},
      {ETIMEDOUT,       L"Timed out."},
      {ETXTBSY,         L"Text file busy."},
      {EWOULDBLOCK,     L"Operation would block."}
   };

   const std::wstring path{L".\\"};
   const std::wstring errorLogFileName{ L"errorLog.out" };
   const std::wstring getErrorLogPathName{ path + errorLogFileName };
   int errorNumber{};
   mutable std::string errorMessage{};
   mutable std::wstring errorMessage_w{};

public:

#if (!DEBUG_ERROR)
   ErrorList() = default;
#else
   ErrorList();
#endif // !DEBUG

protected:
   int getErrorNumber() const noexcept;
   std::string getErrorMessage(const int errNum) const;
   std::wstring getErrorMessage_w(const int errNum) const;

 public:
   void printErrorMessage(const std::string& errTypeMsg, const int errNum) const;
   void printErrorMessage_w(const std::wstring& errTypeMsg, const int errNum) const;
   void printErrorMessage(const int errNum) const;
};

#endif
