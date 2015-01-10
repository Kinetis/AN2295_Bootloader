#ifndef __MY_LIB_H
#define __MY_LIB_H

#include <setupapi.h>
#pragma comment(lib, "setupapi.lib")

typedef BOOL (*LPFENUMSYSTEMPORT)(LPCTSTR pszFriendlyName, LPCTSTR pszShortName, HDEVINFO devInfo, const SP_DEVINFO_DATA* pdevData);
int MgpEnumerateSystemPorts(LPCTSTR pszDevClassName, LPCTSTR pszFriendlyNamePrefix, CStringList* pDestList, LPFENUMSYSTEMPORT pCallback = NULL);


#endif /* __MY_LIB_H */
