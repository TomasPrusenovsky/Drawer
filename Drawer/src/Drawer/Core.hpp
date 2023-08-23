#pragma once

#ifdef DW_PLATFORM_WINDOWS
	#ifdef	DW_BUILD_DLL
		#define DRAWER_API _declspec(dllexport)
	#else
		#define DRAWER_API _declspec(dllimport)
	#endif // DW_BUILD_DLL
#else 
	#error Drawer only supports windows!

#endif // DW_PLATFORM_WINDOWS

#ifdef DW_ENABLE_ASSERTS
	#define DW_ASSERT(x, ...) { if(!(x)) { DW_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DW_CORE_ASSERT(x, ...) { if(!(x)) { DW_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DW_ASSERT(x, ...)
	#define DW_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)