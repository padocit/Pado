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

#ifdef PADO_ENABLE_ASSERTS
	#define PADO_ASSERT(x, ...) { if(!(x)) { PADO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PADO_CORE_ASSERT(x, ...) { if(!(x)) { PADO_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PADO_ASSERT(x, ...)
	#define PADO_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)