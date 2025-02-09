#include "tsk_pch.h"

#include "tsk/time.h"

#ifdef TSK_MACOS
    #include <sys/time.h>
#endif

#ifdef TSK_WIN32
#ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
#endif 
    #include <windows.h>
#endif

namespace tsk {

int64_t get_hp_counter() {

#ifdef TSK_MACOS
    struct timeval now;
    gettimeofday(&now, NULL);
    int64_t i64 = now.tv_sec*INT64_C(1000000) + now.tv_usec;
    return i64;
#endif

#ifdef TSK_WIN32
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return li.QuadPart;
#endif

    return 0;
}

int64_t get_hp_frequency() {
#ifdef TSK_WIN32
    LARGE_INTEGER li; 
    QueryPerformanceFrequency(&li);
    return li.QuadPart;
#endif

#ifdef TSK_MACOS
    return INT64_C(1000000);
#endif

    return 0;
}

} // namespace tsk

