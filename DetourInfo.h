#pragma once
#include "resource.h"
#include "Module.h"
#include "Process.h"
#include "afxwin.h"

// DetourInfo ��ܤ��

class DetourInfo : public CDialog
{
	DECLARE_DYNAMIC(DetourInfo)

public:

	DetourInfo(CWnd* pParent = NULL);   // �зǫغc�禡
	

	virtual ~DetourInfo();

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGDETOURINFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	int m_Index;
	CStatic m_cIndex;
	CEdit m_ProcName;
	CEdit m_Address;
	CEdit m_RetAddress;
	CEdit m_DetourLength;
	CEdit m_Bytes;
	CEdit m_Code;
	vector<HookInfo> m_vecHookInfo;
	/*CString m_strProcName;
	CString m_strAddr;
	CString m_strRetAddr;
	CString m_strDLength;
	CString m_strBytes;
	CString m_strCode;*/
	virtual BOOL OnInitDialog();
	
	afx_msg void OnClose();
	afx_msg void OnBnClickedDetourNext();
	
	afx_msg void OnBnClickedDetourBack();
};
