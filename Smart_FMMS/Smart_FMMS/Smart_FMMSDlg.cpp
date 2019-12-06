
// Smart_FMMSDlg.cpp : 구현 파일
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


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.

	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CSmart_FMMSDlg 대화 상자



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


// CSmart_FMMSDlg 메시지 처리기

BOOL CSmart_FMMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	LoadEnClosureMCInfo();

	// 각 다이얼로그 생성
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSmart_FMMSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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
		case VK_ESCAPE: // ESC 버튼 무시
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CSmart_FMMSDlg::LoadEnClosureMCInfo()
{
	// 기본 3개 입력
	/*CDataRowset DataRowset;
	if (!DataRowset.Open()) {
		AfxMessageBox(_T("데이터 소스와 연결 못함"));
	}*/
	// 장비 정보 리스트에 모두 출력
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

	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("관양2동 복지센터앞1"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.27"), _T(""), _T(""), _T("삼성테크원"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("관양2동 복지센터앞2"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로39"), _T(""), _T(""), _T("192.168.0.27"), _T(""), _T(""), _T("삼성테크원"), _T(""), _T(""), _T("장애발생"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("벌말오거리1"), _T(""), _T(""), _T("방범1차"), _T("동안구 시민대로381"), _T(""), _T(""), _T("192.168.0.27"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("벌말오거리2"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("벌말초_정문"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("벌말초_통행로1"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("벌말초_통행로2"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.20"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("벌말초_후문1"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.20"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("벌말초_후문2"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("벌말초_후문3"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.20"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("민덕원고 앞"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("민덕원역 앞"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.23"), _T(""), _T(""), _T("삼성테크원"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("중앙공원분수대"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("중앙공원 우측"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.25"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	EnClosureInfoTemp.AddData(_T(""), _T(""), _T(""), _T("중앙공원 좌측"), _T(""), _T(""), _T("방범2차"), _T("동안구 시민대로38"), _T(""), _T(""), _T("192.168.0.22"), _T(""), _T(""), _T("HIKVISION"), _T(""), _T(""), _T("정상동작"));
	m_vecEnClosureInfo.push_back(EnClosureInfoTemp);
	// 기본 3개 입력
	SInstallMCInfo InstallMCInfoTemp;

	InstallMCInfoTemp.AddData(_T("IP Camera"), _T("관양2동 복지센터앞1"), _T("삼성테크윈"), _T("SNP-5300H"), _T("192.168.0.27"), _T("어린이보호"));
	m_vecInstallMCInfo.push_back(InstallMCInfoTemp);
	InstallMCInfoTemp.AddData(_T("IP Camera"), _T("관양2동 복지센터앞2"), _T("삼성테크윈"), _T("SNP-5300H"), _T("192.168.0.27"), _T("어린이보호"));
	m_vecInstallMCInfo.push_back(InstallMCInfoTemp);
	InstallMCInfoTemp.AddData(_T("IP Camera"), _T("벌말 오거리1"), _T("삼성테크윈"), _T("SNP-5300H"), _T("192.168.0.27"), _T("어린이보호"));
	m_vecInstallMCInfo.push_back(InstallMCInfoTemp);
}

void CSmart_FMMSDlg::OnBnClickedCheckEnclosureAdd() // 함체 등록
{
	m_nButtonSelect = 1;

	// 체크박스 설정
	m_checkEnclosureAdd.SetCheck(TRUE);
	m_checkEnclosureMonitering.SetCheck(FALSE);
	m_checkMCMonitering.SetCheck(FALSE);
	m_checkMCCheck.SetCheck(FALSE);
	m_checkStatistics.SetCheck(FALSE);

	// 해당 다이얼로그 보여주기
	m_pDlgEnClosureAdd->ShowWindow(SW_SHOW);
	m_pDlgEnClosureMonitering->ShowWindow(SW_HIDE);
	m_pDlgMCMonitering->ShowWindow(SW_HIDE);
	m_pDlgMCCheck->ShowWindow(SW_HIDE);
	m_pDlgStatistics->ShowWindow(SW_HIDE);

	m_pDlgEnClosureAdd->DisplayDialog();
}


void CSmart_FMMSDlg::OnBnClickedCheckEnclosureMonitering() // 함체 모니터링
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


void CSmart_FMMSDlg::OnBnClickedCheckMcMonitering() // 장비 모니터링
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


void CSmart_FMMSDlg::OnBnClickedCheckMcCheck() // 장비 점검
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


void CSmart_FMMSDlg::OnBnClickedCheckStatistics() // 통계
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

