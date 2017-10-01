#pragma once
#include "resource.h"
#include "Module.h"
#include "Process.h"
#include "afxwin.h"

// CDumpInfoDlg ��ܤ��

class CDumpInfoDlg : public CDialog
{
	DECLARE_EASYSIZE
	DECLARE_DYNAMIC(CDumpInfoDlg)

public:
	CDumpInfoDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CDumpInfoDlg();

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGDUMPINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_txtDump;
	vector<HookInfo> m_vecDumpInfo;
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
