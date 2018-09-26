#include <windows.h>

void main()
{
    HANDLE mutex;

    mutex = CreateMutex(NULL, TRUE, "RestartGuard.DoubleBootLock");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
	return;

    while (1) {
	SYSTEMTIME systemTime;
	DWORD activeHoursEnd, activeHoursStart = 0;
	HKEY hKey = {0};

	GetLocalTime(&systemTime);
	if (systemTime.wHour < 6)
	    activeHoursStart = 24;
	activeHoursStart += systemTime.wHour - 6;
	activeHoursEnd = systemTime.wHour + 6;
	if (activeHoursEnd >= 24)
	    activeHoursEnd -= 24;

	RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		     "SOFTWARE\\Microsoft\\WindowsUpdate\\UX\\Settings\\",
		     0, KEY_WRITE, &hKey);
	if (GetLastError() != ERROR_SUCCESS)
	    break;
	RegSetValueEx(hKey,
		      "ActiveHoursStart",
		      0,
		      REG_DWORD,
		      (CONST BYTE *)&activeHoursStart,
		      sizeof(activeHoursStart));
	RegSetValueEx(hKey,
		      "ActiveHoursEnd",
		      0,
		      REG_DWORD,
		      (CONST BYTE *)&activeHoursEnd,
		      sizeof(activeHoursEnd));
	RegCloseKey(hKey);

	Sleep((60 - systemTime.wMinute) * 60 * 1000);
    }

    CloseHandle(mutex);
    return;
}
