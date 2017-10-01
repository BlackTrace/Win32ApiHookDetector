// SearchDlg.cpp : ��@��
//

#include "stdafx.h"
#include "HookRepairer.h"
#include "SearchDlg.h"
#include "afxdialogex.h"

// CSearchDlg ��ܤ��

IMPLEMENT_DYNAMIC(CSearchDlg, CDialog)

CSearchDlg::CSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLGFIND, pParent)
{
	m_isResume = false;
}

CSearchDlg::~CSearchDlg()
{
}

void CSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FIND_SEARCH, m_ProcName);
}


BEGIN_MESSAGE_MAP(CSearchDlg, CDialog)
	//ON_BN_CLICKED(IDC_FIND_NEXT, &CSearchDlg::OnBnClickedFindNext)
	ON_BN_CLICKED(IDOK, &CSearchDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SEARCH_RESUME, &CSearchDlg::OnBnClickedSearchResume)
END_MESSAGE_MAP()


// CSearchDlg �T���B�z�`��

/*void CSearchDlg::OnBnClickedFindNext()
{
//	m_tab2->findProcByName();
}*/


void CSearchDlg::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	m_isResume = false;
	m_ProcName.GetWindowTextA(m_strKeyword);
	CDialog::OnOK();
}

void CSearchDlg::OnBnClickedSearchResume()
{
	m_strKeyword = "";
	m_isResume = true;
	CDialog::OnOK();
}
