#ifndef V3RN13R_DLL
    #define V3RN13R_DLL
    #ifdef _MSC_VER  //Comprueba si esta en VS
        #ifdef V3RN13R_ENGINE
            #define V3RN13R_API __declspec(dllexport)
        #else
            #define V3RN13R_API __declspec(dllimport)
        #endif
    #endif
#endif