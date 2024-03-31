#ifndef _ERRORLIST_
#define _ERRORLIST_

#include <map>
#include <cerrno>
#include <string>
#include <iostream>

#define DEBUG false

#if (DEBUG)
#include <iterator>
#endif

class ErrorList
{
private:

	std::map<const int, const std::string> errorMessageList
	{
		{E2BIG,          "Argument list too long."},
		{EACCES,         "Permission denied."},
		{EAGAIN,         "No more processes or not enough memory or maximum nesting level reached."},
		{EBADF,          "Bad file number."},
		{EBUSY,          "Device or resource busy."},
		{ECHILD,         "No spawned processes."},
		{EDEADLK,        "Resource deadlock would occur."},
		{EDOM,           "The argument to a math function isn't in the domain of the function."},
		{EEXIST,         "An attempt has been made to create a file that already exists."},
		{EFAULT,         "Bad address."},
		{EFBIG,          "File too large."},
		{EILSEQ,         "Illegal sequence of bytes."},
		{EINTR,          "Interrupted function."},
		{EINVAL,         "An invalid value was given for one of the arguments to a function."},
		{EIO,            "I/O error."},
		{EISDIR,         "Is a directory."},
		{EMFILE,         "Too many open files. No more file descriptors are available, so no more files can be opened."},
		{EMLINK,         "Too many links."},
		{ENAMETOOLONG,   "Filename too long."},
		{ENFILE,         "Too many files open in system."},
		{ENODEV,         "No such device."},
		{ENOENT,         "No such file or directory."},
		{ENOEXEC,        "Exec format error."},
		{ENOLCK,         "No locks available."},
		{ENOMEM,         "Not enough memory is available for the attempted operator."},
		{ENOSPC,         "No space left on device."},
		{ENOSYS,         "Function not supported."},
		{ENOTDIR,        "Not a directory."},
		{ENOTEMPTY,      "Directory not empty."},
		{ENOTTY,         "Inappropriate I/O control operation."},
		{ENXIO,          "No such device or address."},
		{EPERM,          "Operation not permitted."},
		{EPIPE,          "Broken pipe."},
		{ERANGE,         "An argument to a math function is too large, resulting in partial or total loss of significance in the result."},
		{EROFS,          "Read only file system."},
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

	int errorNumber{};
	std::string errorMessage{};

public:

#if (!DEBUG)
	ErrorList() = default;
#else
	ErrorList();
#endif // !DEBUG

	void setErrorNumber(const int errNum);
	int getErrorNumber() const;
	std::string getErrorMessage();
};


#endif
