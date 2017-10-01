// DumpInfoDlg.cpp : ��@��
//

#include "stdafx.h"
#include "HookRepairer.h"
#include "DumpInfoDlg.h"
#include "afxdialogex.h"

BEGIN_EASYSIZE_MAP(CDumpInfoDlg)
	EASYSIZE(IDC_TXTDUMP, ES_BORDER, ES_BORDER, ES_BORDER, ES_BORDER, 0)
END_EASYSIZE_MAP
// CDumpInfoDlg ��ܤ��

IMPLEMENT_DYNAMIC(CDumpInfoDlg, CDialog)

CDumpInfoDlg::CDumpInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLGDUMPINFO, pParent)
{

}

CDumpInfoDlg::~CDumpInfoDlg()
{
}

void CDumpInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TXTDUMP, m_txtDump);
}


BEGIN_MESSAGE_MAP(CDumpInfoDlg, CDialog)
	ON_WM_CLOSE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDumpInfoDlg �T���B�z�`��


void CDumpInfoDlg::OnClose()
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
	vector<HookInfo>().swap(m_vecDumpInfo);
	CDialog::OnClose();
}


BOOL CDumpInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �b���[�J�B�~����l��
	CString result = (m_vecDumpInfo[0].m_strProcName + "\r\n\r\n");
	CString tab = "\t", csAddr, csBytes, csCode;
	csAddr.Format( "%-10s", "Address:" );
	csBytes.Format("%-32s", "Bytes:");
	csCode.Format("%-40s", "Code:");
	result += ("Size:" + tab + csAddr + tab + csBytes + tab + csCode + "\r\n");
	for (auto dp : m_vecDumpInfo)
	{
		result += (dp.m_strDLength + tab + dp.m_strAddr + tab+ dp.m_strBytes + tab + dp.m_strCode + "\r\n");
	} // for

	m_txtDump.SetWindowTextA(result);
	m_txtDump.ShowScrollBar(SB_VERT, TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}


void CDumpInfoDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if (nType != SIZE_MINIMIZED)
	{
		UPDATE_EASYSIZE;
	} // if
	// TODO: �b���[�J�z���T���B�z�`���{���X
}
