#include "tsk/time.h"

#ifdef TUSK_WIN32
#ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
#endif 
    #include <windows.h>
#endif

namespace tsk {

int64_t get_hp_counter() {
#ifdef TUSK_WIN32
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return li.QuadPart;
#endif

    return 0;
}

TUSK_API int64_t get_hp_frequency() {
#ifdef TUSK_WIN32
    LARGE_INTEGER li; 
    QueryPerformanceFrequency(&li);
    return li.QuadPart;
#endif

    return 0;
}

} // namespace tsk

