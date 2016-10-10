#include "indoor_display_lib_1.h"
#include "windows.h"

TDisplayOpen DisplayOpen;
TDisplayClose DisplayClose;
TGetDisplayVersion GetDisplayVersion;
TGetDisplayConfig GetDisplayConfig;
TSetDisplayConfig SetDisplayConfig;
TUploadDisplayBmp UploadDisplayBmp;
TUploadDisplayDataMono UploadDisplayDataMono;
TUploadDisplayDataRgb UploadDisplayDataRgb;
TSetRelayState SetRelayState;
TSetDefaultColor SetDefaultColor;
TGetDefaultColor GetDefaultColor;
TGetDllVersion GetDllVersion;
TGetDllVersionStr GetDllVersionStr;

void GetLoadLibrary()
{
	char* libPath;
	HINSTANCE handle = NULL;
	#ifdef WIN32
		libPath = ".\\lib\\Windows\\x86\\display_rgb_8x6-x86.dll";
	#else
		libPath = ".\\lib\\Windows\\x86\\display_rgb_8x6-x86.dll";
	#endif

	handle = LoadLibraryA(libPath);
	if (handle != NULL)
	 {
	   DisplayOpen = (TDisplayOpen) GetProcAddress(handle, "DisplayOpen");
	   DisplayClose = (TDisplayClose) GetProcAddress(handle, "DisplayClose");
	   GetDisplayVersion = (TGetDisplayVersion) GetProcAddress(handle, "GetDisplayVersion");
	   GetDisplayConfig = (TGetDisplayConfig) GetProcAddress(handle, "GetDisplayConfig");
	   SetDisplayConfig = (TSetDisplayConfig) GetProcAddress(handle, "SetDisplayConfig");
	   UploadDisplayBmp = (TUploadDisplayBmp) GetProcAddress(handle, "UploadDisplayBmp");
	   UploadDisplayDataMono = (TUploadDisplayDataMono) GetProcAddress(handle, "UploadDisplayDataMono");
       UploadDisplayDataRgb = (TUploadDisplayDataRgb) GetProcAddress(handle, "UploadDisplayDataRgb");
       SetRelayState = (TSetRelayState) GetProcAddress(handle, "SetRelayState");
       SetDefaultColor = (TSetDefaultColor) GetProcAddress(handle, "SetDefaultColor");
       GetDefaultColor = (TGetDefaultColor) GetProcAddress(handle, "GetDefaultColor");
       GetDllVersion = (TGetDllVersion) GetProcAddress(handle, "GetDllVersion");
       GetDllVersionStr = (TGetDllVersionStr) GetProcAddress(handle, "GetDllVersionStr");
	}
}
