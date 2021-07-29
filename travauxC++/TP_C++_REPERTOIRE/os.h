//This header file will detect the current user's operating system

#ifdef _WIN32 // Includes both 32 bit and 64 bit
    #ifdef _WIN64
        #define OS 64
    #else
	    #define OS 32
    #endif
#endif
	    
#ifdef __APPLE__
    #define OS 1

#endif