#include "stdafx.h"
#include "my_lib.h"

#define MAX_FRIENDLY_PORTNAME_LEN 1024


int MgpEnumerateSystemPorts(LPCTSTR pszDevClassName, LPCTSTR pszFriendlyNamePrefix, CStringList* pDestList, LPFENUMSYSTEMPORT pCallback)
{
// typedef DWORD /*WINAPI*/ (*CM_Open_DevNode_Key)(DWORD, DWORD, DWORD, DWORD, PHKEY, DWORD);
// static CM_Open_DevNode_Key OpenDevNodeKey = NULL;
// static HINSTANCE cfgManDLL = NULL;
 
 SP_DEVINFO_DATA devData;
 HDEVINFO devInfo;
 DWORD classCnt = 0;
 GUID* classGuids = NULL;
 int foundCnt = 0;
 CString name, shortname;
 
/* if(!OpenDevNodeKey)
 {
  if((cfgManDLL = LoadLibrary("cfgmgr32")) == NULL)
   return 0;
 }
 
 OpenDevNodeKey = (CM_Open_DevNode_Key)GetProcAddress(cfgManDLL, "CM_Open_DevNode_Key");
 if(!OpenDevNodeKey)
 {
  FreeLibrary(cfgManDLL);
  return 0;
 }
*/
 
 // all "ports" classes
 SetupDiClassGuidsFromName(pszDevClassName, 0, 0, &classCnt);
 if(!classCnt || classCnt >= 0x1000) // sanity check
  return 0;
 
 classGuids = new GUID[classCnt];
 if(SetupDiClassGuidsFromName(pszDevClassName, classGuids, classCnt, &classCnt))
 {
  // walk thru all classes
  for(DWORD i=0; i<classCnt; i++)
  {
   // get all devices of the class
   if((devInfo = SetupDiGetClassDevs(classGuids+i, NULL, NULL, DIGCF_PRESENT)) != INVALID_HANDLE_VALUE)
   {
     devData.cbSize = sizeof(devData);
 
    for(DWORD j=0; SetupDiEnumDeviceInfo(devInfo, j, &devData); j++)
    {
     // get friendly name
     SetupDiGetDeviceRegistryProperty(devInfo, &devData, SPDRP_FRIENDLYNAME, NULL, 
      (PBYTE)name.GetBuffer(MAX_FRIENDLY_PORTNAME_LEN), MAX_FRIENDLY_PORTNAME_LEN, NULL);
     name.ReleaseBuffer();
 
     // short name is the same by default
     shortname = name;
     
     // look for prefix
     if(pszFriendlyNamePrefix)
     {
      LPCTSTR ps = _tcsstr(name, pszFriendlyNamePrefix);
      if(!ps) continue;
 
      LPCTSTR pe = ps + _tcslen(pszFriendlyNamePrefix);
      while(isdigit(*pe))
       pe++;
 
      shortname = CString(ps, (int)(pe-ps));
     }
 
     // add name to list
     if(pDestList)
      pDestList->AddTail(shortname + '\n' + name);
 
     // callback
     if(pCallback)
      pCallback(name, shortname, devInfo, &devData);
 
     // count this one
     foundCnt++;
 
     // preapre size for next round
      devData.cbSize = sizeof(devData);
    }
   }
 
   SetupDiDestroyDeviceInfoList(devInfo);
  }
 }
 
 delete[] classGuids;
 return foundCnt;
}

bool open_file(CStdioFile file, CString name)
{
	CFileException fileException;

	if ( !file.Open( name, CStdioFile::modeReadWrite, &fileException ) )
	{
		if ( !file.Open( name, CStdioFile::modeCreate |   
				  CStdioFile::modeReadWrite, &fileException ) )
		{
			
			TRACE( "Can't open file %s, error = %u\n",
			   name, fileException.m_cause );
			return(false);
		}
	}
	return(true);
}

bool read_line(CStdioFile file, CString &line, int x_line)
{
	file.SeekToEnd();
	file.ReadString(line);
	return(true);
}

bool write_new_line(CStdioFile file, CString line)
{
	file.SeekToEnd();
	line += _T("\n\r");
	file.WriteString(line);
	return(true);
}


bool delete_line(CStdioFile file, int x_line)
{
	
	return(true);
}

bool close_file(CStdioFile file)
{

	if (file==NULL)
	{
		TRACE( "Can't close file \n" );
		return(false);
	}
	file.Close();
	return(true);
}

 