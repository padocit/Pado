#pragma once

#ifdef PADO_PLATFORM_WINDOWS
	#ifdef PADO_BUILD_DLL
		#define PADO_API __declspec(dllexport)
	#else
		#define PADO_API __declspec(dllimport)
	#endif 
#else
	#error Pado only supports Windows!
#endif

#define BIT(x) (1 << x)