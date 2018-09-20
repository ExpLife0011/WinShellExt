// ShellExtern.cpp : Implementation of CShellExtern
#include "stdafx.h"
#include "ShellExt.h"
#include "ShellExtern.h"
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////
// CShellExtern
STDMETHODIMP CShellExtern::Initialize(LPCITEMIDLIST pIDFolder, LPDATAOBJECT pDataObj, HKEY hKeyID)
{
	return SHGetPathFromIDList ( pIDFolder, m_szPathName) ? S_OK : E_INVALIDARG;
}

STDMETHODIMP CShellExtern::QueryContextMenu(HMENU hMenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags)
{
	if ( uFlags & CMF_DEFAULTONLY )
	{
        return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 0 );
	}

	InsertMenu(hMenu, indexMenu, MF_BYPOSITION | MF_SEPARATOR, 0, NULL);
	InsertMenu (hMenu, indexMenu+1, MF_BYPOSITION, idCmdFirst, _T("���������cmd"));
	InsertMenu(hMenu, indexMenu+2, MF_BYPOSITION | MF_SEPARATOR, 0, NULL);
	return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 1 );
}

STDMETHODIMP CShellExtern::InvokeCommand(LPCMINVOKECOMMANDINFO pInfo)
{
    if ( 0 != HIWORD( pInfo->lpVerb ))	//���lpVerbָ���ַ���������Դ˴ε��ò��˳�
	{
        return E_INVALIDARG;
	}
	
     if ( 0 != LOWORD( pInfo->lpVerb ))	//�˵����ID����Ϊ0����Ϊֻ�����һ���˵���
 	{
         return E_INVALIDARG;
 	}

	ShellExecute(NULL, _T("open"), _T("cmd.exe"), _T(""), m_szPathName, SW_SHOWNORMAL);
	return S_OK;
}

STDMETHODIMP CShellExtern::GetCommandString (UINT uCmd, UINT uFlags, UINT* puReserved, LPSTR pszName, UINT cchMax )
{	
	static TCHAR COMMAND_HELP_STRING[] = _T("�ڵ�ǰĿ¼��cmd����...");//�˵���ʾ�ִ�
	USES_CONVERSION ;	//ʹ���ִ�ת��

 	if (uCmd != 0)
 	{
 		return E_INVALIDARG;
 	}

	if ( uFlags & GCS_HELPTEXT )
	{        
		if ( uFlags & GCS_UNICODE )
		{
			// pszName ��ΪUnicode �ַ���, ��ʹ��Unicode�ַ������� API.
			lstrcpynW ( (LPWSTR) pszName, T2CW(COMMAND_HELP_STRING), cchMax );
		}
		else
		{
			// ʹ�� ANSI �ַ������� API ���ذ����ַ���.
			lstrcpynA ( pszName, T2CA(COMMAND_HELP_STRING), cchMax );
		}
	}	
    return S_OK;
}
