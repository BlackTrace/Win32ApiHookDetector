// DetourInfo.cpp : ��@��
//

#include "stdafx.h"
#include "HookRepairer.h"
#include "DetourInfo.h"
#include "afxdialogex.h"


// DetourInfo ��ܤ��

IMPLEMENT_DYNAMIC(DetourInfo, CDialog)

DetourInfo::DetourInfo(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLGDETOURINFO, pParent)
{
}


DetourInfo::~DetourInfo()
{
}

void DetourInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DETOUR_ADDR, m_Address);
	DDX_Control(pDX, IDC_DETOUR_RETADDR, m_RetAddress);
	DDX_Control(pDX, IDC_DETOUR_LENGTH, m_DetourLength);
	DDX_Control(pDX, IDC_DETOUR_BYTE, m_Bytes);
	DDX_Control(pDX, IDC_DETOUR_CODE, m_Code);
	DDX_Control(pDX, IDC_DETOUR_PROCNAME, m_ProcName);
	DDX_Control(pDX, IDC_DETOUR_INDEX, m_cIndex);
}


BEGIN_MESSAGE_MAP(DetourInfo, CDialog)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_DETOUR_NEXT, &DetourInfo::OnBnClickedDetourNext)
	ON_BN_CLICKED(IDC_DETOUR_BACK, &DetourInfo::OnBnClickedDetourBack)
END_MESSAGE_MAP()


// DetourInfo �T���B�z�`��


BOOL DetourInfo::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �b���[�J�B�~����l��
	m_Index = 0;
	CString title;
	title.Format("Index: %d / %d", m_Index+1, m_vecHookInfo.size());
	m_cIndex.SetWindowTextA(title);
	m_ProcName.SetWindowTextA(m_vecHookInfo[0].m_strProcName);
	m_Address.SetWindowTextA(m_vecHookInfo[0].m_strAddr);
	m_RetAddress.SetWindowTextA(m_vecHookInfo[0].m_strRetAddr);
	m_DetourLength.SetWindowTextA(m_vecHookInfo[0].m_strDLength);
	m_Bytes.SetWindowTextA(m_vecHookInfo[0].m_strBytes);
	m_Code.SetWindowTextA(m_vecHookInfo[0].m_strCode);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}


void DetourInfo::OnClose()
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
	vector<HookInfo>().swap(m_vecHookInfo);
	CDialog::OnClose();
}


void DetourInfo::OnBnClickedDetourNext()
{
	
	if (m_Index == m_vecHookInfo.size() - 1)
		return;
	m_Index++;
	CString title;
	title.Format("Index: %d / %d", m_Index+1, m_vecHookInfo.size());
	m_cIndex.SetWindowTextA(title);
	m_ProcName.SetWindowTextA(m_vecHookInfo[m_Index].m_strProcName);
	m_Address.SetWindowTextA(m_vecHookInfo[m_Index].m_strAddr);
	m_RetAddress.SetWindowTextA(m_vecHookInfo[m_Index].m_strRetAddr);
	m_DetourLength.SetWindowTextA(m_vecHookInfo[m_Index].m_strDLength);
	m_Bytes.SetWindowTextA(m_vecHookInfo[m_Index].m_strBytes);
	m_Code.SetWindowTextA(m_vecHookInfo[m_Index].m_strCode);
}


void DetourInfo::OnBnClickedDetourBack()
{
	
	if (m_Index == 0)
		return;
	m_Index--;
	CString title;
	title.Format("Index: %d / %d", m_Index + 1, m_vecHookInfo.size());
	m_cIndex.SetWindowTextA(title);
	m_ProcName.SetWindowTextA(m_vecHookInfo[m_Index].m_strProcName);
	m_Address.SetWindowTextA(m_vecHookInfo[m_Index].m_strAddr);
	m_RetAddress.SetWindowTextA(m_vecHookInfo[m_Index].m_strRetAddr);
	m_DetourLength.SetWindowTextA(m_vecHookInfo[m_Index].m_strDLength);
	m_Bytes.SetWindowTextA(m_vecHookInfo[m_Index].m_strBytes);
	m_Code.SetWindowTextA(m_vecHookInfo[m_Index].m_strCode);
}
