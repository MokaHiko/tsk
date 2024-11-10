/**
 * @file defines.h
 * @brief This file contains common declarations for the Tusk library.
 *
 * @author Moka
 * @date 2024-11-03
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#ifdef TUSK_EXPORTS
	#define TUSK_API __declspec(dllexport)
#else
	#define TUSK_API  
#endif

#if defined(_MSC_VER)
    #define TUSK_NO_VTABLE __declspec(novtable)
#elif defined(__GNUC__) || defined(__clang__)
    #define TUSK_NO_VTABLE __attribute__((no_vtable))
#else
    #define TUSK_NO_VTABLE  // Default, do nothing for other compilers
#endif

namespace tsk {

} // namespace tusk

#endif
