#ifndef EXAMPLE_DLL
    #define EXAMPLE_DLL
    #ifdef _MSC_VER  //Comprueba si esta en VS
        #ifdef V3RN13R_GAME
            #define EXAMPLE_API __declspec(dllexport)
        #else
            #define EXAMPLE_API __declspec(dllimport)
        #endif
    #endif
#endif