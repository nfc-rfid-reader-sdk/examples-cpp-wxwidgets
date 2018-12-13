/*
 * indoor_display_lib.h
 *
 *  Created on: Jul 15, 2015
 *      Author: Novica Perić
 */

#ifndef INDOOR_DISPLAY_LIB_H_
#define INDOOR_DISPLAY_LIB_H_

#include <stdint.h>
#include <stddef.h>

typedef const char * chr_ptr;

#if __linux__
#	define DL_API
#else
// WINDOWS
#	ifdef DL_API_STATIC_LIB
#		define DL_API
#	else
#		ifndef DL_API_EXPORTS
#			define DL_API /* __declspec(dllimport) */ __stdcall
#		else
#			define DL_API __declspec(dllexport) __stdcall
#		endif
#	endif
#endif // __linux__

#if defined(DL_API_EXPORTS) || defined(DL_API_STATIC_LIB)
	typedef struct S_IN_DISP_HANDLE * IN_DISP_HANDLE;
#else
	typedef void * IN_DISP_HANDLE;
#endif


// API Status Codes Type:
typedef enum IN_DISP_ERROR_CODES
{
	IN_DISP_OK = 0,
	IN_DISP_COMMUNICATION_ERROR = 0x01,

	IN_DISP_COMMUNICATION_BREAK = 0x50,
	IN_DISP_NO_MEMORY_ERROR = 0x51,
	IN_DISP_CAN_NOT_OPEN_DISPLAY = 0x52,
	IN_DISP_DISPLAY_NOT_SUPPORTED = 0x53,
	IN_DISP_DISPLAY_OPENING_ERROR = 0x54,
	IN_DISP_DISPLAY_PORT_NOT_OPENED = 0x55,
	IN_DISP_CANT_CLOSE_DISPLAY_PORT = 0x56,

	IN_DISP_DEVICE_WRONG_HANDLE = 0x100,
	IN_DISP_DEVICE_INDEX_OUT_OF_BOUND,
	IN_DISP_DEVICE_ALREADY_OPENED,
	IN_DISP_DEVICE_ALREADY_CLOSED,

	FILE_OPEN_ERROR = 0x300,
	FILE_READING_ERROR,
	FILE_MAX_LENGTH_EXCEEDED,
	FILE_CONTENT_ERROR,

	BMP_DATA_WRONG_LENGTH,

}IN_DISP_STATUS;

//Single FTDI function definition
#ifdef __cplusplus
extern "C"
{
#endif

DL_API IN_DISP_STATUS DisplayOpen(void);
DL_API IN_DISP_STATUS DisplayClose(void);

DL_API IN_DISP_STATUS GetDisplayVersion(uint32_t *hw_version, uint32_t *fw_version);

DL_API IN_DISP_STATUS GetDisplayConfig(uint32_t *module_row_nr, uint32_t *module_col_nr, uint32_t *brightness);
DL_API IN_DISP_STATUS SetDisplayConfig(uint32_t module_row_nr, uint32_t module_col_nr, uint32_t brightness);

DL_API IN_DISP_STATUS UploadDisplayBmp(const char *file_name);

DL_API IN_DISP_STATUS UploadDisplayDataMono(uint8_t *data, uint32_t data_size);
DL_API IN_DISP_STATUS UploadDisplayDataRgb(uint8_t *data, uint32_t data_size);

DL_API IN_DISP_STATUS SetRelayState(uint32_t relay_on);

DL_API IN_DISP_STATUS SetDefaultColor(uint8_t red, uint8_t green, uint8_t blue);
DL_API IN_DISP_STATUS GetDefaultColor(uint8_t *red, uint8_t *green, uint8_t *blue);

//DLL version
DL_API uint32_t GetDllVersion(void);
DL_API chr_ptr GetDllVersionStr(void);

#ifdef __cplusplus
}
#endif

#endif /* INDOOR_DISPLAY_LIB_H_ */
