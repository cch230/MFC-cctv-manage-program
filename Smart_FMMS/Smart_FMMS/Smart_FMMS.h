
// Smart_FMMS.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSmart_FMMSApp:
// �� Ŭ������ ������ ���ؼ��� Smart_FMMS.cpp�� �����Ͻʽÿ�.
//

class CSmart_FMMSApp : public CWinApp
{
public:
	CSmart_FMMSApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSmart_FMMSApp theApp;