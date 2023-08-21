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

#define BIT(x) (1 << x)