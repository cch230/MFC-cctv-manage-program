// DlgEnClosureMonitering.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "Smart_FMMSDlg.h"
#include "DlgEnClosureMonitering.h"
#include "afxdialogex.h"
#include "DataRowset.h"

// CDlgEnClosureMonitering 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgEnClosureMonitering, CDialog)

CDlgEnClosureMonitering::CDlgEnClosureMonitering(CSmart_FMMSDlg* DataRowset)
	: CDialog(CDlgEnClosureMonitering::IDD, DataRowset)
	, m_pParent(DataRowset)
{

}

CDlgEnClosureMonitering::~CDlgEnClosureMonitering()
{
}

void CDlgEnClosureMonitering::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DATA, m_listData);
		DDX_Control(pDX, IDC_LIST_ENCLOSURE_DATA, m_listEnclosureData);

}


BEGIN_MESSAGE_MAP(CDlgEnClosureMonitering, CDialog)
	ON_WM_PAINT()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_DATA, &CDlgEnClosureMonitering::OnNMDblclkListData)
END_MESSAGE_MAP()


// CDlgEnClosureMonitering 메시지 처리기입니다.


BOOL CDlgEnClosureMonitering::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitListControl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CDlgEnClosureMonitering::PreTranslateMessage(MSG* pMsg)
{
	return ::AfxGetMainWnd()->PreTranslateMessage(pMsg);
}

void CDlgEnClosureMonitering::OnPaint()
{
	DrawImage();

	CDialog::OnPaint();
}

void CDlgEnClosureMonitering::DisplayDialog()
{
	/*InitListControl();*/
}

void CDlgEnClosureMonitering::DrawImage()
{
	// 현재 폴더 위치 가져오기...
	CString strCurPath;
	GetModuleFileName(nullptr, strCurPath.GetBuffer(_MAX_PATH + 1), _MAX_PATH);
	strCurPath.ReleaseBuffer();
	strCurPath = strCurPath.Left(strCurPath.ReverseFind(_T('\\'))) + _T("\\지도2.JPG");

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
void CDlgEnClosureMonitering::InitListControl()
{
	m_listData.SetExtendedStyle(m_listData.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listData.InsertColumn(0, _T("Index"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(1, _T("Location Name"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(2, _T("EquipmentType"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(3, _T("State"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(4, _T("Manufacture"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(5, _T("ModelName"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(6, _T("IdAddress"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(7, _T("Password"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(8, _T("ETC."), LVCFMT_CENTER, 100);
	/*m_listData.InsertColumn(9, _T("위도"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(10, _T("경도"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(11, _T("IP"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(12, _T("Port"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(13, _T("준공일"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(14, _T("설치업체"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(15, _T("유지보수업체"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(16, _T("업체연락처"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(17, _T("사용여부"), LVCFMT_CENTER, 100);*/

	m_listEnclosureData.SetExtendedStyle(m_listEnclosureData.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listEnclosureData.InsertColumn(0, _T(""), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(1, _T("그룹명1"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(2, _T("그룹명2"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(3, _T("QR코드"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(4, _T("함체위치명"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(5, _T("함체ID"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(6, _T("관리번호"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(7, _T("설치구분"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(8, _T("설치주소"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(9, _T("위도"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(10, _T("경도"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(11, _T("IP"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(12, _T("Port"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(13, _T("준공일"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(14, _T("설치업체"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(15, _T("유지보수업체"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(16, _T("업체연락처"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(17, _T("사용여부"), LVCFMT_CENTER, 100);
	

	SetListDataControl();
}

void CDlgEnClosureMonitering::SetListDataControl()
{
	// List 에 있는 내용을 모두 지운다.
	/*m_listData.DeleteAllItems();*/
	CDataRowset DataRowset;
	if (!DataRowset.Open()) {
		AfxMessageBox(_T("데이터 소스와 연결 못함"));
	}

	int data = 0;
	int num;
	CString str;
	while (!DataRowset.IsEOF()) {


		m_listData.InsertItem(data, DataRowset.m_Index);

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

	// 함체 정보 리스트에 모두 출력
	/*for(long i = 0; i < (long)m_pParent->m_vecEnClosureInfo.size(); i++)
	{
		m_listData.InsertItem(i, _T(""));

		m_listData.SetItemText(i, 1, m_pParent->m_vecEnClosureInfo[i].strGroup1);
		m_listData.SetItemText(i, 2, m_pParent->m_vecEnClosureInfo[i].strGroup2);
		m_listData.SetItemText(i, 3, m_pParent->m_vecEnClosureInfo[i].strQRCode);
		m_listData.SetItemText(i, 4, m_pParent->m_vecEnClosureInfo[i].strLocateName);
		m_listData.SetItemText(i, 5, m_pParent->m_vecEnClosureInfo[i].strID);
		m_listData.SetItemText(i, 6, m_pParent->m_vecEnClosureInfo[i].strManageNumber);
		m_listData.SetItemText(i, 7, m_pParent->m_vecEnClosureInfo[i].strInstallDivision);
		m_listData.SetItemText(i, 8, m_pParent->m_vecEnClosureInfo[i].strInstallAddress);
		m_listData.SetItemText(i, 9, m_pParent->m_vecEnClosureInfo[i].strLatitude);
		m_listData.SetItemText(i, 10, m_pParent->m_vecEnClosureInfo[i].strLongitude);
		m_listData.SetItemText(i, 12, m_pParent->m_vecEnClosureInfo[i].strIP);
		m_listData.SetItemText(i, 12, m_pParent->m_vecEnClosureInfo[i].strPort);
		m_listData.SetItemText(i, 13, m_pParent->m_vecEnClosureInfo[i].strCompDate);
		m_listData.SetItemText(i, 14, m_pParent->m_vecEnClosureInfo[i].strInstallCompany);
		m_listData.SetItemText(i, 15, m_pParent->m_vecEnClosureInfo[i].strMaintCompany);
		m_listData.SetItemText(i, 16, m_pParent->m_vecEnClosureInfo[i].strMaintCompanyNumber);
		m_listData.SetItemText(i, 17, m_pParent->m_vecEnClosureInfo[i].strUsable);
	}*/
}

void CDlgEnClosureMonitering::SetListSelectedDataControl()
{
	// List 에 있는 내용을 모두 지운다.
	m_listEnclosureData.DeleteAllItems();
	/*CDataRowset DataRowset;
	if (!DataRowset.Open()) {
		AfxMessageBox(_T("데이터 소스와 연결 못함"));
	}
	int data = 0;
	int num;
	CString str;
	while (!DataRowset.IsEOF()) {
	m_listData.InsertItem(data, DataRowset.m_Index);

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
	SetListDataControl();*/

	// 함체 정보 리스트에 모두 출력
	for(int i = 0; i < (int)m_pParent->m_vecEnClosureInfo_Selected.size(); i++)
	{
		CDataRowset DataRowset;
		m_listEnclosureData.InsertItem(i, _T(""));

		m_listEnclosureData.SetItemText(i, 1, m_pParent->m_vecEnClosureInfo_Selected[i].strGroup1);
		m_listEnclosureData.SetItemText(i, 2, m_pParent->m_vecEnClosureInfo_Selected[i].strGroup2);
		m_listEnclosureData.SetItemText(i, 3, m_pParent->m_vecEnClosureInfo_Selected[i].strQRCode);
		m_listEnclosureData.SetItemText(i, 4, m_pParent->m_vecEnClosureInfo_Selected[i].strLocateName);
		m_listEnclosureData.SetItemText(i, 5, m_pParent->m_vecEnClosureInfo_Selected[i].strID);
		m_listEnclosureData.SetItemText(i, 6, m_pParent->m_vecEnClosureInfo_Selected[i].strManageNumber);
		m_listEnclosureData.SetItemText(i, 7, m_pParent->m_vecEnClosureInfo_Selected[i].strInstallDivision);
		m_listEnclosureData.SetItemText(i, 8, m_pParent->m_vecEnClosureInfo_Selected[i].strInstallAddress);
		m_listEnclosureData.SetItemText(i, 9, m_pParent->m_vecEnClosureInfo_Selected[i].strLatitude);
		m_listEnclosureData.SetItemText(i, 10, m_pParent->m_vecEnClosureInfo_Selected[i].strLongitude);
		m_listEnclosureData.SetItemText(i, 12, m_pParent->m_vecEnClosureInfo_Selected[i].strIP);
		m_listEnclosureData.SetItemText(i, 12, m_pParent->m_vecEnClosureInfo_Selected[i].strPort);
		m_listEnclosureData.SetItemText(i, 13, m_pParent->m_vecEnClosureInfo_Selected[i].strCompDate);
		m_listEnclosureData.SetItemText(i, 14, m_pParent->m_vecEnClosureInfo_Selected[i].strInstallCompany);
		m_listEnclosureData.SetItemText(i, 15, m_pParent->m_vecEnClosureInfo_Selected[i].strMaintCompany);
		m_listEnclosureData.SetItemText(i, 16, m_pParent->m_vecEnClosureInfo_Selected[i].strMaintCompanyNumber);
		m_listEnclosureData.SetItemText(i, 17, m_pParent->m_vecEnClosureInfo_Selected[i].strUsable);
	}
}

// 함체 정보 리스트 더블 클릭시
void CDlgEnClosureMonitering::OnNMDblclkListData(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	if(pNMItemActivate)
	{
		int nItem = pNMItemActivate->iItem;

		// 함체 선택 변수에 선택된 함체 정보 입력
		m_pParent->m_vecEnClosureInfo_Selected.push_back(m_pParent->m_vecEnClosureInfo[nItem]);

		// 함체 선택 변수 리스트 업데이트
		SetListSelectedDataControl();
	}

	*pResult = 0;
}
