
// HookRepairer.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CHookRepairerApp: 
// �аѾ\��@�����O�� HookRepairer.cpp
//

class CHookRepairerApp : public CWinApp
{
public:
	CHookRepairerApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CHookRepairerApp theApp;