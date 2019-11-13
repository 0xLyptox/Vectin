#pragma once

#ifdef VN_PLATFORM_WINDOWS
	#ifdef VN_BUILD_DLL
		#define VECTIN_API __declspec(dllexport)
	#else
		#define VECTIN_API __declspec(dllimport)
	#endif
#else
	#error Vectin supports only Windows
#endif