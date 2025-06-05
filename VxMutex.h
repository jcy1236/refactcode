#include <Windows.h>
#include <stdlib.h>

class vxHandle
{
public:
    vxHandle();

protected:
    vxHandle handle_;
};

class vxMutex : public vxHandle
{
public:
    vxMutex();
    ~vxMutex();
    bool Open(const char* mutexName = 0);
    const char* GetName();
    bool Lock(DWORD waitTime =INFINITE, DWORD* pdwResult = nullptr);
    void Unlock();
    void CLose();
};

class vxScopeLock : public vxHandle
{
public:
    vxScopeLock(vxMutex* mutex, DWORD waitTime = INFINITE);
    ~vxScopeLock();
    void Unlock();
    void Lock(DWORD waitTime = INIFINITE);
    bool IsLock();
    DWORD GetLockResult();
private:
    const char* m_comment;
}