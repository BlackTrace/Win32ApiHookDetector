
// HookRepairerDlg.cpp : ��@��

#include "stdafx.h"
#include "HookRepairer.h"
#include "HookRepairerDlg.h"
#include "afxdialogex.h"
#include "resource.h"
vector<Process> vec_ProcessList;

/*   resize */


BEGIN_EASYSIZE_MAP(CHookRepairerDlg)
	EASYSIZE(IDC_TAB, ES_BORDER, ES_BORDER, ES_BORDER, ES_BORDER, 0)
	//EASYSIZE(IDD_TAB1, ES_BORDER, ES_BORDER, ES_BORDER, ES_BORDER, 0)
END_EASYSIZE_MAP
/*=======================================================*/
// CHookRepairerDlg ��ܤ��



CHookRepairerDlg::CHookRepairerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HOOKREPAIRER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHookRepairerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tabCtl);
}

BEGIN_MESSAGE_MAP(CHookRepairerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CHookRepairerDlg::OnSelchangeTab)
ON_BN_CLICKED(IDCANCEL, &CHookRepairerDlg::OnBnClickedCancel)
ON_BN_CLICKED(IDOK, &CHookRepairerDlg::OnBnClickedOk)
ON_UPDATE_COMMAND_UI(IDD_HOOKREPAIRER_DIALOG, &CHookRepairerDlg::OnUpdateIddHookrepairerDialog)
ON_WM_SIZE()
ON_WM_CLOSE()
END_MESSAGE_MAP()


// CHookRepairerDlg �T���B�z�`��

BOOL CHookRepairerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �N [����...] �\���[�J�t�Υ\���C

	// IDM_ABOUTBOX �����b�t�ΩR�O�d�򤧤��C
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		/*BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}*/
	}

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	//

	// TODO: �b���[�J�B�~����l�]�w

	m_tab1.Create(IDD_TAB1, &m_tabCtl);
	TCITEM item1;
	item1.mask = TCIF_TEXT | TCIF_PARAM;
	item1.lParam = (LPARAM)& m_tab1;
	item1.pszText = "Process/Module";
	m_tabCtl.InsertItem(0, &item1);
	CRect rc;
	m_tabCtl.GetItemRect(0, &rc);
	//m_tab1.SetWindowPos(NULL, rc.left, rc.bottom + 1, rc.left + rc.Width(), rc.bottom + 1 + rc.Height(), SWP_NOZORDER);
	m_tab1.SetWindowPos(NULL, rc.left, rc.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_tab1.ShowWindow(SW_SHOW);

	m_tab1.m_ProcessList.InsertColumn(0, "PID", LVCFMT_LEFT, 60);
	m_tab1.m_ProcessList.InsertColumn(1, "NAME", LVCFMT_LEFT, 200);
	//m_ProcessList.SetTextBkColor((COLORREF)RGB(255.0.0));
	m_tab1.m_ProcessList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_INFOTIP | LVS_EX_ONECLICKACTIVATE);
	m_tab1.getAllProcess();

	m_tab1.m_ModuleList.InsertColumn(0, "Module", LVCFMT_CENTER, 150);
	m_tab1.m_ModuleList.InsertColumn(1, "Start Address", LVCFMT_LEFT, 80);
	m_tab1.m_ModuleList.InsertColumn(2, "Module Path", LVCFMT_LEFT, 1000);
	m_tab1.m_ModuleList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_INFOTIP | LVS_EX_ONECLICKACTIVATE);
	DWORD dwExStyle = m_tab1.m_ModuleList.GetExtendedStyle();
	m_tab1.m_ModuleList.SetExtendedStyle(dwExStyle | LVS_EX_CHECKBOXES );
	m_tab1.m_SelectDLL.SetCheck(true);
	m_tab1.m_ScanOpts.SetCurSel(0);
	m_tab1.m_tabCtl = &m_tabCtl;
	/*LVITEM item2;
	::ZeroMemory(&item2, sizeof(item2));
	item2.mask = LVIF_IMAGE | LVIF_TEXT | LVIF_STATE;
	item2.pszText = "Tetst";
	item2.iImage = 1;
	item2.state = LVIS_SELECTED | LVIS_FOCUSED;
	m_tab1.m_ProcessList.InsertItem(&item2);*/
	m_tab2.Create(IDD_TAB2, &m_tabCtl);
	TCITEM item2;
	item2.mask = TCIF_TEXT | TCIF_PARAM;
	item2.lParam = (LPARAM)& m_tab2;
	item2.pszText = "Hook Info";
	m_tabCtl.InsertItem(1, &item2);

	m_tab2.m_ProcList.InsertColumn(0, "Module", LVCFMT_LEFT, 100);
	m_tab2.m_ProcList.InsertColumn(1, "Proc", LVCFMT_LEFT, 250);
	m_tab2.m_ProcList.InsertColumn(2, "Proc Address", LVCFMT_LEFT, 200);
	//m_tab2.m_ProcList.InsertColumn(3, "Proc Size", LVCFMT_LEFT, 200);
	m_tab2.m_ProcList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_INFOTIP | LVS_EX_ONECLICKACTIVATE);
	m_tab1.m_tab2 = &m_tab2;

	m_tab3.Create(IDD_TAB3, &m_tabCtl);
	TCITEM item3;
	item3.mask = TCIF_TEXT | TCIF_PARAM;
	item3.lParam = (LPARAM)& m_tab3;
	item3.pszText = "About";
	m_tabCtl.InsertItem(2, &item3);

	INIT_EASYSIZE;
	ifstream fin("HookDetourMainDlg.ini");
	if ( !fin )
		ShowWindow(SW_NORMAL);
	else
	{
		RECT fRc;
		char tmp[100];
		fin >> tmp >> fRc.left;
		fin >> tmp >> fRc.top;
		fin >> tmp >> fRc.right;
		fin >> tmp >> fRc.bottom;
		fin.close();
		this->SetWindowPos(NULL, fRc.left, fRc.top, fRc.right, fRc.bottom, SWP_SHOWWINDOW);
	} // else

	m_Menu.LoadMenuA(IDR_HookInfoMENU);
	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
}

void CHookRepairerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	
	CDialogEx::OnSysCommand(nID, lParam);
	
}

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CHookRepairerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ø�s���˸m���e

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N�ϥܸm����Τ�ݯx��
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �yø�ϥ�
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


// ��ϥΪ̩즲�̤p�Ƶ����ɡA
// �t�ΩI�s�o�ӥ\����o�����ܡC
HCURSOR CHookRepairerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CHookRepairerDlg::OnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	int iSel = m_tabCtl.GetCurSel();
	
	CRect rc;
	switch (iSel) {
	case 0:
		//m_tabCtl.GetItemRect(0, &rc);
		//m_tab1.SetWindowPos(NULL, rc.left, rc.bottom + 1, rc.left + rc.Width(), rc.bottom + 1 + rc.Height(),  SWP_NOZORDER);
		//m_tab1.SetWindowPos(NULL, rc.left, rc.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		m_tab1.ShowWindow(SW_SHOW);
		m_tab2.ShowWindow(SW_HIDE);
		m_tab3.ShowWindow(SW_HIDE);
		break;
	case 1:
		//m_tabCtl.GetItemRect(0, &rc);
		//m_tab2.SetWindowPos(NULL, rc.left, rc.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		m_tab2.ShowWindow(SW_SHOW);
		m_tab1.ShowWindow(SW_HIDE);
		m_tab3.ShowWindow(SW_HIDE);
		break;
	case 2:
		//m_tabCtl->GetItemRect(0, &rc);
		m_tab3.ShowWindow(SW_SHOW);
		m_tab1.ShowWindow(SW_HIDE);
		m_tab2.ShowWindow(SW_HIDE);
		break;
	} // switch
	*pResult = 0;
}


void CHookRepairerDlg::OnBnClickedCancel()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CDialogEx::OnCancel();
}


void CHookRepairerDlg::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	for (Process p : vec_ProcessList)
		p.Clear();
	vector<Process>().swap(vec_ProcessList); // clear vector
	CDialogEx::OnOK();
}


void CHookRepairerDlg::OnBnClickedButton1()
{
	MessageBox("Close", "", MB_OK);
	// TODO: �b���[�J����i���B�z�`���{���X
	
	
}


void CHookRepairerDlg::OnUpdateIddHookrepairerDialog(CCmdUI *pCmdUI)
{
	// TODO: �b���[�J�z���R�O��s UI �B�z�`���{���X

}

void CHookRepairerDlg::OnSize(UINT nType, int cx, int cy)
{
	
	CDialogEx::OnSize(nType, cx, cy);
	
	// TODO: �b���[�J�z���T���B�z�`���{���X
	if (nType != SIZE_MINIMIZED)
	{
		UPDATE_EASYSIZE;
		/*MessageBox("RESIZE", "", MB_OK);*/
		CRect rc, wc;
		m_tabCtl.GetItemRect(0, &rc);
		GetClientRect(&wc);
		m_tab1.SetWindowPos(NULL, rc.left, rc.bottom + 1, rc.left + wc.Width(), rc.bottom + 1 + wc.Height()-60, SWP_NOZORDER);
		m_tab2.SetWindowPos(NULL, rc.left, rc.bottom + 1, rc.left + wc.Width(), rc.bottom + 1 + wc.Height() - 60, SWP_NOZORDER);
		m_tab3.SetWindowPos(NULL, rc.left, rc.bottom + 1, rc.left + wc.Width(), rc.bottom + 1 + wc.Height() - 60, SWP_NOZORDER);
		//m_tab1.m_ModuleList.InsertColumn(2, "Module Path", LVCFMT_LEFT, wc.Width());
		//m_tab1.m_ModuleList.SetColumnWidth( 2, wc.Width()/2);
		/*ReSize(IDOK, cx, cy, false);
		ReSize(IDC_TAB, cx, cy, true);//MessageBox("RESIZE", "", MB_OK);
		ReSize(IDD_TAB1, cx, cy, true);

		GetClientRect(&m_rect);*/
	}
}

void CHookRepairerDlg::OnClose()
{
	// TODO: �b���[�J�z���T���B�z�`���{���X�M (��) �I�s�w�]��
	//MessageBox("Close", "", MB_OK);
	CRect fRc;
	GetWindowRect(&fRc);
	m_tab2.m_vecProc.Clear();
	ofstream fout("HookDetourMainDlg.ini");
	fout << "[mainDlg.left]= " << fRc.left << endl;
	fout << "[mainDlg.top]= " << fRc.top << endl;
	fout << "[mainDlg.width]= " << fRc.Width() << endl;
	fout << "[mainDlg.height]= " << fRc.Height() << endl;
	fout.close();
	for (Process p : vec_ProcessList)
		p.Clear();
	vector<Process>().swap(vec_ProcessList); // clear vector
	CDialogEx::OnClose();
}