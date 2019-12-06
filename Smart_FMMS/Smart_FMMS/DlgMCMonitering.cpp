// DlgMCMonitering.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "Smart_FMMSDlg.h"
#include "DlgMCMonitering.h"
#include "afxdialogex.h"
#include "DataRowset.h"

// CDlgMCMonitering 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMCMonitering, CDialog)

CDlgMCMonitering::CDlgMCMonitering(CSmart_FMMSDlg* pParent)
	: CDialog(CDlgMCMonitering::IDD, pParent)
	, m_pParent(pParent)
{

}

CDlgMCMonitering::~CDlgMCMonitering()
{
}

void CDlgMCMonitering::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DATA, m_listData);
	DDX_Control(pDX, IDC_LIST_MC_DATA, m_listMCData);
}


BEGIN_MESSAGE_MAP(CDlgMCMonitering, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgMCMonitering 메시지 처리기입니다.


BOOL CDlgMCMonitering::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitListControl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CDlgMCMonitering::PreTranslateMessage(MSG* pMsg)
{
	return ::AfxGetMainWnd()->PreTranslateMessage(pMsg);
}

void CDlgMCMonitering::OnPaint()
{
	DrawImage();

	CDialog::OnPaint();
}

void CDlgMCMonitering::DisplayDialog()
{
	
}

void CDlgMCMonitering::DrawImage()
{
	// 현재 폴더 위치 가져오기...
	CString strCurPath;
	GetModuleFileName(nullptr, strCurPath.GetBuffer(_MAX_PATH + 1), _MAX_PATH);
	strCurPath.ReleaseBuffer();
	strCurPath = strCurPath.Left(strCurPath.ReverseFind(_T('\\'))) + _T("\\지도3.JPG");

	CImage image;
	image.Destroy();

	// 지도 사진 불러오기
	HRESULT hResult = image.Load(strCurPath);

	CPaintDC dc(this);
	CRect rect;

	dc.SelectStockObject(NULL_BRUSH);
		
	GetDlgItem(IDC_STATIC_MAP)->GetWindowRect(rect);
	ScreenToClient(&rect);
	
	dc.Rectangle(rect);
	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);

	// 사진 출력
	image.Draw(dc.m_hDC, rect);

	Invalidate(false);
}

// List Control 초기화
void CDlgMCMonitering::InitListControl()
{
	m_listData.SetExtendedStyle(m_listData.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listData.InsertColumn(0, _T("INDEX"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(1, _T("Location Name"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(2, _T("Equipment Type"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(3, _T("State"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(4, _T("Manufacture"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(5, _T("ModelName"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(6, _T("IPAddress"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(7, _T("Password"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(8, _T("etc"), LVCFMT_CENTER, 100);
	/*m_listData.InsertColumn(9, _T("위도"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(10, _T("경도"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(11, _T("IP"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(12, _T("Port"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(13, _T("준공일"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(14, _T("설치업체"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(15, _T("유지보수업체"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(16, _T("업체연락처"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(17, _T("사용여부"), LVCFMT_CENTER, 100);*/

	m_listMCData.SetExtendedStyle(m_listMCData.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listMCData.InsertColumn(0, _T("장비타입"), LVCFMT_CENTER, 100);
	m_listMCData.InsertColumn(1, _T("설치장소명"), LVCFMT_CENTER, 180);
	m_listMCData.InsertColumn(2, _T("제조사"), LVCFMT_CENTER, 120);
	m_listMCData.InsertColumn(3, _T("모델명"), LVCFMT_CENTER, 150);
	m_listMCData.InsertColumn(4, _T("IP주소"), LVCFMT_CENTER, 100);
	m_listMCData.InsertColumn(5, _T("Etc."), LVCFMT_CENTER, 100);
	
	
	CDataRowset DataRowset;
	if (!DataRowset.Open()) {
		AfxMessageBox(_T("데이터 소스와 연결 못함"));
	}
	
	int data = 0;
	int num;
	CString str;
	while (!DataRowset.IsEOF()) {
		
		
		m_listData.InsertItem(data,DataRowset.m_Index);
		
		m_listData.SetItemText(data, 1, DataRowset.m_LocationName);
		m_listData.SetItemText(data, 2, DataRowset.m_EquipmentType);
		m_listData.SetItemText(data, 3, DataRowset.m_State);
		m_listData.SetItemText(data, 4, DataRowset.m_Manufacturer);
		m_listData.SetItemText(data, 5, DataRowset.m_ModelName);
		m_listData.SetItemText(data, 6, DataRowset.m_IPAddress);
		m_listData.SetItemText(data, 7, DataRowset.m_Password);
		m_listData.SetItemText(data, 8, DataRowset.m_Etc);
		
		

		DataRowset.MoveNext();
		data++;
	}
	DataRowset.Close();
	SetListMCDataControl();
}

void CDlgMCMonitering::SetListDataControl()
{
	
}

void CDlgMCMonitering::SetListMCDataControl()
{
	// List 에 있는 내용을 모두 지운다.
	//m_listMCData.DeleteAllItems();
	CDataRowset DataRowset;
	if (!DataRowset.Open()) {
		AfxMessageBox(_T("데이터 소스와 연결 못함"));
	}
	// 장비 정보 리스트에 모두 출력
	int data = 0;
	int num;
	CString str;
	
	DataRowset.MoveFirst();
	while (!DataRowset.IsEOF()) {
	
	
		m_listMCData.InsertItem(data, DataRowset.m_EquipmentType);

		m_listMCData.SetItemText(data, 1, DataRowset.m_LocationName);
		m_listMCData.SetItemText(data, 2, DataRowset.m_Manufacturer);
		m_listMCData.SetItemText(data, 3, DataRowset.m_ModelName);
		m_listMCData.SetItemText(data, 4, DataRowset.m_IPAddress);
		m_listMCData.SetItemText(data, 5, DataRowset.m_Etc);
		
		
		
		
		
		/*m_listMCData.SetItemText(i, 1, m_pParent->m_vecInstallMCInfo[i].strType);
		m_listMCData.SetItemText(i, 2, m_pParent->m_vecInstallMCInfo[i].strLocation);
		m_listMCData.SetItemText(i, 3, m_pParent->m_vecInstallMCInfo[i].strInstallCompany);
		m_listMCData.SetItemText(i, 4, m_pParent->m_vecInstallMCInfo[i].strModelName);
		m_listMCData.SetItemText(i, 5, m_pParent->m_vecInstallMCInfo[i].strIPAddress);
		m_listMCData.SetItemText(i, 6, m_pParent->m_vecInstallMCInfo[i].strEtc);*/
		DataRowset.MoveNext();
		data++;
	}
	DataRowset.Close();
	
	
}