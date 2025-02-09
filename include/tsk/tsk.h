#ifndef TSK_H_
#define TSK_H_

#ifdef TSK_EXPORTS
#ifdef TSK_WIN32
	#define TSK_API __declspec(dllexport)
#else 
	#define TSK_API
#endif
#else
	#define TSK_API
#endif

#if defined(_MSC_VER)
    #define TSK_NO_VTABLE __declspec(novtable)
#else
    #define TSK_NO_VTABLE  // Default, do nothing for other compilers
#endif

#endif 
