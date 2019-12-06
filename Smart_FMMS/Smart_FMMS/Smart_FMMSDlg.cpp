
// Smart_FMMSDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "Smart_FMMSDlg.h"
#include "afxdialogex.h"

#include "DlgEnClosureAdd.h"
#include "DlgEnClosureMonitering.h"
#include "DlgMCCheck.h"
#include "DlgMCMonitering.h"
#include "DlgStatistics.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.

	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSmart_FMMSDlg ��ȭ ����



CSmart_FMMSDlg::CSmart_FMMSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSmart_FMMSDlg::IDD, pParent)
	, m_pDlgEnClosureAdd(nullptr)
	, m_pDlgEnClosureMonitering(nullptr)
	, m_pDlgMCCheck(nullptr)
	, m_pDlgMCMonitering(nullptr)
	, m_pDlgStatistics(nullptr)
	, m_nButtonSelect(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSmart_FMMSDlg::~CSmart_FMMSDlg()
{
	delete m_pDlgEnClosureAdd;
	delete m_pDlgEnClosureMonitering;
	delete m_pDlgMCCheck;
	delete m_pDlgMCMonitering;
	delete m_pDlgStatistics;
}

void CSmart_FMMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_ENCLOSURE_ADD, m_checkEnclosureAdd);
	DDX_Control(pDX, IDC_CHECK_ENCLOSURE_MONITERING, m_checkEnclosureMonitering);
	DDX_Control(pDX, IDC_CHECK_MC_MONITERING, m_checkMCMonitering);
	DDX_Control(pDX, IDC_CHECK_MC_CHECK, m_checkMCCheck);
	DDX_Control(pDX, IDC_CHECK_STATISTICS, m_checkStatistics);
}

BEGIN_MESSAGE_MAP(CSmart_FMMSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_ENCLOSURE_ADD, &CSmart_FMMSDlg::OnBnClickedCheckEnclosureAdd)
	ON_BN_CLICKED(IDC_CHECK_ENCLOSURE_MONITERING, &CSmart_FMMSDlg::OnBnClickedCheckEnclosureMonitering)
	ON_BN_CLICKED(IDC_CHECK_MC_MONITERING, &CSmart_FMMSDlg::OnBnClickedCheckMcMonitering)
	ON_BN_CLICKED(IDC_CHECK_MC_CHECK, &CSmart_FMMSDlg::OnBnClickedCheckMcCheck)
	ON_BN_CLICKED(IDC_CHECK_STATISTICS, &CSmart_FMMSDlg::OnBnClickedCheckStatistics)
END_MESSAGE_MAP()


// CSmart_FMMSDlg �޽��� ó����

BOOL CSmart_FMMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	LoadEnClosureMCInfo();

	// �� ���̾�α� ����
	m_pDlgEnClosureAdd = new CDlgEnClosureAdd(this);
	m_pDlgEnClosureAdd->Create(CDlgEnClosureAdd::IDD, this);
	m_pDlgEnClosureAdd->SetParent(this);
	m_pDlgEnClosureAdd->SetWindowPos(nullptr, 0, 60, 0, 0, SWP_SHOWWINDOW|SWP_NOSIZE);
	m_pDlgEnClosureAdd->ShowWindow(SW_HIDE);

	m_pDlgEnClosureMonitering = new CDlgEnClosureMonitering(this);
	m_pDlgEnClosureMonitering->Create(CDlgEnClosureMonitering::IDD, this);
	m_pDlgEnClosureMonitering->SetParent(this);
	m_pDlgEnClosureMonitering->SetWindowPos(nullptr, 0, 60, 0, 0, SWP_SHOWWINDOW|SWP_NOSIZE);
	m_pDlgEnClosureMonitering->ShowWindow(SW_HIDE);

	m_pDlgMCMonitering = new CDlgMCMonitering(this);
	m_pDlgMCMonitering->Create(CDlgMCMonitering::IDD, this);
	m_pDlgMCMonitering->SetParent(this);
	m_pDlgMCMonitering->SetWindowPos(nullptr, 0, 60, 0, 0, SWP_SHOWWINDOW|SWP_NOSIZE);
	m_pDlgMCMonitering->ShowWindow(SW_HIDE);

	m_pDlgMCCheck = new CDlgMCCheck(this);
	m_pDlgMCCheck->Create(CDlgMCCheck::IDD, this);
	m_pDlgMCCheck->SetParent(this);
	m_pDlgMCCheck->SetWindowPos(nullptr, 0, 60, 0, 0, SWP_SHOWWINDOW|SWP_NOSIZE);
	m_pDlgMCCheck->ShowWindow(SW_HIDE);

	m_pDlgStatistics = new CDlgStatistics(this);
	m_pDlgStatistics->Create(CDlgStatistics::IDD, this);
	m_pDlgStatistics->SetParent(this);
	m_pDlgStatistics->SetWindowPos(nullptr, 0, 60, 0, 0, SWP_SHOWWINDOW|SWP_NOSIZE);
	m_pDlgStatistics->ShowWindow(SW_HIDE);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}


void CSmart_FMMSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CSmart_FMMSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CSmart_FMMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CSmart_FMMSDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message == WM_KEYDOWN || pMsg->message == WM_SYSKEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_ESCAPE: // ESC ��ư ����
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CSmart_FMMSDlg::LoadEnClosureMCInfo()
{
	// �⺻ 3�� �Է�
	/*CDataRowset DataRowset;
	if (!DataRowset.Open()) {
		AfxMessageBox(_T("������ �ҽ��� ���� ����"));
	}*/
	// ��� ���� ����Ʈ�� ��� ���
	/*int data = 0;
	int num;
	CString str;

	DataRowset.MoveFirst();
	while (!DataRowset.IsEOF()) {


		m_listMCData.InsertItem(data, DataRowset.m_EquipmentType);

		m_listMCData.SetItemText(data, 1, DataRowset.m_LocationName);
		m_listMCData.SetItemText(data, 2, DataRowset.m_Manufacturer);
		m_listMCData.SetItemText(data, 3, DataRowset.m_ModelName);
		m_listMCData.SetItemText(data, 4, DataRowset.m_IPAddress);
		m_listMCData.SetItemText(data, 5, DataRowset.m_Etc);*/
	SEnClosureInfo EnClosureInfoTemp;

	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("����2�� �������;�1"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.27"), _T(""), _T(""), _T("�Ｚ��ũ��"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("����2�� �������;�2"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��39"), _T(""), _T(""), _T("192.168.0.27"), _T(""), _T(""), _T("�Ｚ��ũ��"), _T(""), _T(""), _T("��ֹ߻�"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("�������Ÿ�1"), _T(""), _T(""), _T("���1��"), _T("���ȱ� �ùδ��381"), _T(""), _T(""), _T("192.168.0.27"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("����"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("�������Ÿ�2"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("������_����"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("������_�����1"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("������_�����2"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.20"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("������_�Ĺ�1"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.20"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("������_�Ĺ�2"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("������_�Ĺ�3"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.20"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("�δ����� ��"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("�δ����� ��"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.23"), _T(""), _T(""), _T("�Ｚ��ũ��"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("�߾Ӱ����м���"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("�߾Ӱ��� ����"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.25"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("�߾Ӱ��� ����"), _T(""), _T(""), _T("���2��"), _T("���ȱ� �ùδ��38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("������"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	// �⺻ 3�� �Է�
	SInstallMCInfo InstallMCInfoTemp;

	InstallMCInfoTemp.AddData(_T("IP Camera"), _T("����2�� �������;�1"), _T("�Ｚ��ũ��"), _T("SNP-5300H"), _T("192.168.0.27"), _T("��̺�ȣ"));
	m_vecInstallMCInfo.push_back(InstallMCInfoTemp);
	InstallMCInfoTemp.AddData(_T("IP Camera"), _T("����2�� �������;�2"), _T("�Ｚ��ũ��"), _T("SNP-5300H"), _T("192.168.0.27"), _T("��̺�ȣ"));
	m_vecInstallMCInfo.push_back(InstallMCInfoTemp);
	InstallMCInfoTemp.AddData(_T("IP Camera"), _T("���� ���Ÿ�1"), _T("�Ｚ��ũ��"), _T("SNP-5300H"), _T("192.168.0.27"), _T("��̺�ȣ"));
	m_vecInstallMCInfo.push_back(InstallMCInfoTemp);
}

void CSmart_FMMSDlg::OnBnClickedCheckEnclosureAdd() // ��ü ���
{
	m_nButtonSelect = 1;

	// üũ�ڽ� ����
	m_checkEnclosureAdd.SetCheck(TRUE);
	m_checkEnclosureMonitering.SetCheck(FALSE);
	m_checkMCMonitering.SetCheck(FALSE);
	m_checkMCCheck.SetCheck(FALSE);
	m_checkStatistics.SetCheck(FALSE);

	// �ش� ���̾�α� �����ֱ�
	m_pDlgEnClosureAdd->ShowWindow(SW_SHOW);
	m_pDlgEnClosureMonitering->ShowWindow(SW_HIDE);
	m_pDlgMCMonitering->ShowWindow(SW_HIDE);
	m_pDlgMCCheck->ShowWindow(SW_HIDE);
	m_pDlgStatistics->ShowWindow(SW_HIDE);

	m_pDlgEnClosureAdd->DisplayDialog();
}


void CSmart_FMMSDlg::OnBnClickedCheckEnclosureMonitering() // ��ü ����͸�
{
	m_nButtonSelect = 2;

	m_checkEnclosureAdd.SetCheck(FALSE);
	m_checkEnclosureMonitering.SetCheck(TRUE);
	m_checkMCMonitering.SetCheck(FALSE);
	m_checkMCCheck.SetCheck(FALSE);
	m_checkStatistics.SetCheck(FALSE);

	m_pDlgEnClosureAdd->ShowWindow(SW_HIDE);
	m_pDlgEnClosureMonitering->ShowWindow(SW_SHOW);
	m_pDlgMCMonitering->ShowWindow(SW_HIDE);
	m_pDlgMCCheck->ShowWindow(SW_HIDE);
	m_pDlgStatistics->ShowWindow(SW_HIDE);

	m_pDlgEnClosureMonitering->DisplayDialog();
}


void CSmart_FMMSDlg::OnBnClickedCheckMcMonitering() // ��� ����͸�
{
	m_nButtonSelect = 3;

	m_checkEnclosureAdd.SetCheck(FALSE);
	m_checkEnclosureMonitering.SetCheck(FALSE);
	m_checkMCMonitering.SetCheck(TRUE);
	m_checkMCCheck.SetCheck(FALSE);
	m_checkStatistics.SetCheck(FALSE);

	m_pDlgEnClosureAdd->ShowWindow(SW_HIDE);
	m_pDlgEnClosureMonitering->ShowWindow(SW_HIDE);
	m_pDlgMCMonitering->ShowWindow(SW_SHOW);
	m_pDlgMCCheck->ShowWindow(SW_HIDE);
	m_pDlgStatistics->ShowWindow(SW_HIDE);

	m_pDlgMCCheck->DisplayDialog();
}


void CSmart_FMMSDlg::OnBnClickedCheckMcCheck() // ��� ����
{
	m_nButtonSelect = 4;

	m_checkEnclosureAdd.SetCheck(FALSE);
	m_checkEnclosureMonitering.SetCheck(FALSE);
	m_checkMCMonitering.SetCheck(FALSE);
	m_checkMCCheck.SetCheck(TRUE);
	m_checkStatistics.SetCheck(FALSE);

	m_pDlgEnClosureAdd->ShowWindow(SW_HIDE);
	m_pDlgEnClosureMonitering->ShowWindow(SW_HIDE);
	m_pDlgMCMonitering->ShowWindow(SW_HIDE);
	m_pDlgMCCheck->ShowWindow(SW_SHOW);
	m_pDlgStatistics->ShowWindow(SW_HIDE);

	m_pDlgMCMonitering->DisplayDialog();
}


void CSmart_FMMSDlg::OnBnClickedCheckStatistics() // ���
{
	m_nButtonSelect = 5;

	m_checkEnclosureAdd.SetCheck(FALSE);
	m_checkEnclosureMonitering.SetCheck(FALSE);
	m_checkMCMonitering.SetCheck(FALSE);
	m_checkMCCheck.SetCheck(FALSE);
	m_checkStatistics.SetCheck(TRUE);

	m_pDlgEnClosureAdd->ShowWindow(SW_HIDE);
	m_pDlgEnClosureMonitering->ShowWindow(SW_HIDE);
	m_pDlgMCMonitering->ShowWindow(SW_HIDE);
	m_pDlgMCCheck->ShowWindow(SW_HIDE);
	m_pDlgStatistics->ShowWindow(SW_SHOW);

	m_pDlgStatistics->DisplayDialog();
}

