#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifndef VR_NEW
#define VR_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new VR_NEW
#endif
#endif