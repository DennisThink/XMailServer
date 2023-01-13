

#ifndef _XMAIL_SYS_UTIL_H_
#define _XMAIL_SYS_UTIL_H_
#include "SysTypes.h"
#include "dt_const_value.h"
class SysUtil
{
public:
	//Memory
	static void* SysAllocNZ(unsigned int uSize);
	static void* SysAlloc(unsigned int uSize);
	static void  SysFree(void* pData);
	static void* SysRealloc(void* pData, unsigned int uSize);
	//Library
	//static int SysInitLibrary(void);
	//static void SysCleanupLibrary(void);
	//static int SysShutdownLibrary(int iMode = SYS_SHUTDOWN_SOFT);
	
	//static int SysAddThreadExitHook(void (*pfHook)(void*, SYS_THREAD, int), void* pPrivate);
	/*int SysSetupSocketBuffers(int* piSndBufSize, int* piRcvBufSize);
	SYS_SOCKET SysCreateSocket(int iAddressFamily, int iType, int iProtocol);
	void SysCloseSocket(SYS_SOCKET SockFD);
	int SysShutdownSocket(SYS_SOCKET SockFD, int iHow);
	int SysBlockSocket(SYS_SOCKET SockFD, int iBlocking);
	int SysBindSocket(SYS_SOCKET SockFD, const SYS_INET_ADDR* SockName);
	void SysListenSocket(SYS_SOCKET SockFD, int iConnections);
	int SysRecvData(SYS_SOCKET SockFD, char* pszBuffer, int iBufferSize, int iTimeout);
	int SysRecv(SYS_SOCKET SockFD, char* pszBuffer, int iBufferSize, int iTimeout);
	int SysRecvDataFrom(SYS_SOCKET SockFD, SYS_INET_ADDR* pFrom, char* pszBuffer,
		int iBufferSize, int iTimeout);
	int SysSendData(SYS_SOCKET SockFD, char const* pszBuffer, int iBufferSize, int iTimeout);
	int SysSend(SYS_SOCKET SockFD, char const* pszBuffer, int iBufferSize, int iTimeout);
	int SysSendDataTo(SYS_SOCKET SockFD, const SYS_INET_ADDR* pTo,
		char const* pszBuffer, int iBufferSize, int iTimeout);
	int SysConnect(SYS_SOCKET SockFD, const SYS_INET_ADDR* pSockName, int iTimeout);
	SYS_SOCKET SysAccept(SYS_SOCKET SockFD, SYS_INET_ADDR* pSockName, int iTimeout);
	int SysSelect(int iMaxFD, SYS_fd_set* pReadFDs, SYS_fd_set* pWriteFDs, SYS_fd_set* pExcptFDs,
		int iTimeout);
	int SysSendFile(SYS_SOCKET SockFD, char const* pszFileName, SYS_OFF_T llBaseOffset,
		SYS_OFF_T llEndOffset, int iTimeout);
	int SysInetAnySetup(SYS_INET_ADDR& AddrInfo, int iFamily, int iPortNo);
	int SysGetAddrFamily(SYS_INET_ADDR const& AddrInfo);
	int SysGetAddrPort(SYS_INET_ADDR const& AddrInfo);
	int SysSetAddrPort(SYS_INET_ADDR& AddrInfo, int iPortNo);
	int SysGetHostByName(char const* pszName, int iFamily, SYS_INET_ADDR& AddrInfo);
	int SysGetHostByAddr(SYS_INET_ADDR const& AddrInfo, char* pszFQDN, int iSize);
	int SysGetPeerInfo(SYS_SOCKET SockFD, SYS_INET_ADDR& AddrInfo);
	int SysGetSockInfo(SYS_SOCKET SockFD, SYS_INET_ADDR& AddrInfo);
	char* SysInetNToA(SYS_INET_ADDR const& AddrInfo, char* pszIP, int iSize);
	char* SysInetRevNToA(SYS_INET_ADDR const& AddrInfo, char* pszRevIP, int iSize);
	void const* SysInetAddrData(SYS_INET_ADDR const& AddrInfo, int* piSize);
	int SysInetIPV6CompatIPV4(SYS_INET_ADDR const& Addr);
	int SysInetIPV6ToIPV4(SYS_INET_ADDR const& SAddr, SYS_INET_ADDR& DAddr);
	int SysInetAddrMatch(SYS_INET_ADDR const& Addr, SYS_UINT8 const* pMask, int iMaskSize,
		SYS_INET_ADDR const& TestAddr);
	int SysInetAddrMatch(SYS_INET_ADDR const& Addr, SYS_INET_ADDR const& TestAddr);

	SYS_SEMAPHORE SysCreateSemaphore(int iInitCount, int iMaxCount);
	int SysCloseSemaphore(SYS_SEMAPHORE hSemaphore);
	int SysWaitSemaphore(SYS_SEMAPHORE hSemaphore, int iTimeout);
	int SysReleaseSemaphore(SYS_SEMAPHORE hSemaphore, int iCount);
	int SysTryWaitSemaphore(SYS_SEMAPHORE hSemaphore);

	SYS_MUTEX SysCreateMutex(void);
	int SysCloseMutex(SYS_MUTEX hMutex);
	int SysLockMutex(SYS_MUTEX hMutex, int iTimeout);
	int SysUnlockMutex(SYS_MUTEX hMutex);
	int SysTryLockMutex(SYS_MUTEX hMutex);

	SYS_EVENT SysCreateEvent(int iManualReset);
	int SysCloseEvent(SYS_EVENT hEvent);
	int SysWaitEvent(SYS_EVENT hEvent, int iTimeout);
	int SysSetEvent(SYS_EVENT hEvent);
	int SysResetEvent(SYS_EVENT hEvent);
	int SysTryWaitEvent(SYS_EVENT hEvent);

	/*
	 * Why? On Unix, the best implementation for events is based on the pthread
	 * API, which cannot be waited together with file/socket descriptors (unless
	 * you do use separate wait threads, which is a lot uglier than having two
	 * event APIs).
	 */
	/*SYS_PEVENT SysCreatePEvent(int iManualReset);
	int SysClosePEvent(SYS_PEVENT hPEvent);
	int SysWaitPEvent(SYS_PEVENT hPEvent, int iTimeout);
	int SysSetPEvent(SYS_PEVENT hPEvent);
	int SysResetPEvent(SYS_PEVENT hPEvent);
	int SysTryWaitPEvent(SYS_PEVENT hPEvent);

	SYS_THREAD SysCreateThread(unsigned int (*pThreadProc) (void*), void* pThreadData);
	void SysCloseThread(SYS_THREAD ThreadID, int iForce);
	int SysSetThreadPriority(SYS_THREAD ThreadID, int iPriority);
	int SysWaitThread(SYS_THREAD ThreadID, int iTimeout);
	unsigned long SysGetCurrentThreadId(void);
	int SysExec(char const* pszCommand, char const* const* pszArgs, int iWaitTimeout = 0,
		int iPriority = SYS_PRIORITY_NORMAL, int* piExitStatus = NULL);
	void SysSetBreakHandler(void (*pBreakHandler) (void));
	unsigned long SysGetCurrentProcessId(void);

	int SysCreateTlsKey(SYS_TLSKEY& TlsKey, void (*pFreeProc) (void*) = NULL);
	int SysDeleteTlsKey(SYS_TLSKEY& TlsKey);
	int SysSetTlsKeyData(SYS_TLSKEY& TlsKey, void* pData);
	void* SysGetTlsKeyData(SYS_TLSKEY& TlsKey);

	void SysThreadOnce(SYS_THREAD_ONCE* pThrOnce, void (*pOnceProc) (void));


	int SysLockFile(char const* pszFileName, char const* pszLockExt = ".lock");
	int SysUnlockFile(char const* pszFileName, char const* pszLockExt = ".lock");

	SYS_HANDLE SysOpenModule(char const* pszFilePath);
	int SysCloseModule(SYS_HANDLE hModule);
	void* SysGetSymbol(SYS_HANDLE hModule, char const* pszSymbol);

	int SysEventLogV(int iLogLevel, char const* pszFormat, va_list Args);
	int SysEventLog(int iLogLevel, char const* pszFormat, ...);
	int SysLogMessage(int iLogLevel, char const* pszFormat, ...);
	int SysSleep(int iTimeout);
	int SysMsSleep(int iMsTimeout);
	SYS_INT64 SysMsTime(void);
	int SysExistFile(char const* pszFilePath);
	int SysExistDir(char const* pszDirPath);
	SYS_HANDLE SysFirstFile(char const* pszPath, char* pszFileName, int iSize);
	int SysIsDirectory(SYS_HANDLE hFind);
	SYS_OFF_T SysGetSize(SYS_HANDLE hFind);
	int SysNextFile(SYS_HANDLE hFind, char* pszFileName, int iSize);
	void SysFindClose(SYS_HANDLE hFind);
	int SysGetFileInfo(char const* pszFileName, SYS_FILE_INFO& FI);
	int SysSetFileModTime(char const* pszFileName, time_t tMod);
	char* SysStrDup(char const* pszString);
	char* SysGetEnv(char const* pszVarName);
	char* SysGetTempDir(char* pszPath, int iMaxPath);
	int SysRemove(char const* pszFileName);
	int SysMakeDir(char const* pszPath);
	int SysRemoveDir(char const* pszPath);
	int SysMoveFile(char const* pszOldName, char const* pszNewName);

	int SysVSNPrintf(char* pszBuffer, int iSize, char const* pszFormat, va_list Args);
	int SysFileSync(FILE* pFile);

	char* SysStrTok(char* pszData, char const* pszDelim, char** ppszSavePtr);
	char* SysCTime(time_t* pTimer, char* pszBuffer, int iBufferSize);
	struct tm* SysLocalTime(time_t* pTimer, struct tm* pTStruct);
	struct tm* SysGMTime(time_t* pTimer, struct tm* pTStruct);
	char* SysAscTime(struct tm* pTStruct, char* pszBuffer, int iBufferSize);
	long SysGetTimeZone(void);
	long SysGetDayLight(void);

	int SysGetDiskSpace(char const* pszPath, SYS_INT64* pTotal, SYS_INT64* pFree);
	int SysMemoryInfo(SYS_INT64* pRamTotal, SYS_INT64* pRamFree,
		SYS_INT64* pVirtTotal, SYS_INT64* pVirtFree);

	SYS_MMAP SysCreateMMap(char const* pszFileName, unsigned long ulFlags);
	void SysCloseMMap(SYS_MMAP hMap);
	SYS_OFF_T SysMMapSize(SYS_MMAP hMap);
	SYS_OFF_T SysMMapOffsetAlign(SYS_MMAP hMap, SYS_OFF_T llOffset);
	void* SysMapMMap(SYS_MMAP hMap, SYS_OFF_T llOffset, SYS_SIZE_T lSize);
	int SysUnmapMMap(SYS_MMAP hMap, void* pAddr, SYS_SIZE_T lSize);*/
};
#endif