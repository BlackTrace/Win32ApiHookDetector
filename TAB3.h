#pragma once
#include "resource.h"

// CTAB3 ��ܤ��

class CTAB3 : public CDialog
{
	DECLARE_DYNAMIC(CTAB3)

public:
	CTAB3(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CTAB3();

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
};
