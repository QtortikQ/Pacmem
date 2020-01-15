#ifndef MY_PERFORMENCE_COUNTER_
#define MY_PERFORMENCE_COUNTER_

#include <windows.h>

class CStopwatch
{
public:
	CStopwatch();
	void CStart();
	int CNow();
	int CTime();
private:
	LARGE_INTEGER m_liPerfFreq;
	LARGE_INTEGER m_liPerfStart;
};

CStopwatch::CStopwatch()
{
    QueryPerformanceFrequency(&m_liPerfFreq);
    CStart();
}

void CStopwatch::CStart()
{
    QueryPerformanceCounter(&m_liPerfStart);
}

int CStopwatch::CNow()
{
        LARGE_INTEGER liPerfNow;
        QueryPerformanceCounter(&liPerfNow);
	return (((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000) / m_liPerfFreq.QuadPart);
}

int CStopwatch::CTime()
{
    LARGE_INTEGER liPerfNow;
	QueryPerformanceCounter(&liPerfNow);
	return ((liPerfNow.QuadPart * 1000) / m_liPerfFreq.QuadPart);
}

#endif
