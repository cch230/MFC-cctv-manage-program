// DlgEnClosureAdd.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "Smart_FMMSDlg.h"
#include "DlgEnClosureAdd.h"
#include "afxdialogex.h"

#include "DlgMap.h"


// CDlgEnClosureAdd 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgEnClosureAdd, CDialog)

CDlgEnClosureAdd::CDlgEnClosureAdd(CSmart_FMMSDlg* pParent)
	: CDialog(CDlgEnClosureAdd::IDD, pParent)
	, m_pParent(pParent)
	, m_strGroup1(_T(""))
	, m_strGroup2(_T(""))
	, m_strQRCode(_T(""))
	, m_strLocationName(_T(""))
	, m_strID(_T(""))
	, m_strManageNumber(_T(""))
	, m_strInstallDivision(_T(""))
	, m_strInstallAddress(_T(""))
	, m_strLatitude(_T(""))
	, m_strLongitude(_T(""))
	, m_strIP(_T(""))
	, m_strPort(_T(""))
	, m_strCompleteDate(_T(""))
	, m_strInstallCompany(_T(""))
	, m_strMaintCompany(_T(""))
	, m_strCompanyNum1(_T(""))
	, m_strCompanyNum2(_T(""))
	, m_strCompanyNum3(_T(""))
{

}

CDlgEnClosureAdd::~CDlgEnClosureAdd()
{
}

void CDlgEnClosureAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DATA, m_listData);
	DDX_Text(pDX, IDC_EDIT_GROUP1, m_strGroup1);
	DDX_Text(pDX, IDC_EDIT_GROUP2, m_strGroup2);
	DDX_Text(pDX, IDC_EDIT_QRCode, m_strQRCode);
	DDX_Text(pDX, IDC_EDIT_LOCATION_NAME, m_strLocationName);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_MANAGE_NUMBER, m_strManageNumber);
	DDX_Text(pDX, IDC_EDIT_INSTALL_DIV, m_strInstallDivision);
	DDX_Text(pDX, IDC_EDIT_MANAGE_ADDRESS, m_strInstallAddress);
	DDX_Text(pDX, IDC_EDIT_LATITUDE, m_strLatitude);
	DDX_Text(pDX, IDC_EDIT_LONGITUDE, m_strLongitude);
	DDX_Text(pDX, IDC_EDIT_IP, m_strIP);
	DDX_Text(pDX, IDC_EDIT_PORT, m_strPort);
	DDX_Text(pDX, IDC_EDIT_COMPLETE_DATE, m_strCompleteDate);
	DDX_Text(pDX, IDC_EDIT_INSTALL_COMPANY, m_strInstallCompany);
	DDX_Text(pDX, IDC_EDIT_MAINT_COMPANY, m_strMaintCompany);
	DDX_Text(pDX, IDC_EDIT_COMPANY_NUM1, m_strCompanyNum1);
	DDX_Text(pDX, IDC_EDIT_COMPANY_NUM2, m_strCompanyNum2);
	DDX_Text(pDX, IDC_EDIT_COMPANY_NUM3, m_strCompanyNum3);
	DDX_Control(pDX, IDC_COMBO_USE, m_cmbUse);
}


BEGIN_MESSAGE_MAP(CDlgEnClosureAdd, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDlgEnClosureAdd::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &CDlgEnClosureAdd::OnBnClickedButtonSelect)
END_MESSAGE_MAP()


// CDlgEnClosureAdd 메시지 처리기입니다.

BOOL CDlgEnClosureAdd::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitListControl();

	m_cmbUse.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CDlgEnClosureAdd::PreTranslateMessage(MSG* pMsg)
{
	return ::AfxGetMainWnd()->PreTranslateMessage(pMsg);
}

void CDlgEnClosureAdd::DisplayDialog()
{
	
}

// List Control 초기화
void CDlgEnClosureAdd::InitListControl()
{
	m_listData.SetExtendedStyle(m_listData.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listData.InsertColumn(0, _T(""), LVCFMT_CENTER, 15);
	m_listData.InsertColumn(1, _T("그룹명1"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(2, _T("그룹명2"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(3, _T("QR코드"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(4, _T("함체위치명"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(5, _T("함체ID"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(6, _T("관리번호"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(7, _T("설치구분"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(8, _T("설치주소"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(9, _T("위도"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(10, _T("경도"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(11, _T("IP"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(12, _T("Port"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(13, _T("준공일"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(14, _T("설치업체"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(15, _T("유지보수업체"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(16, _T("업체연락처"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(17, _T("사용여부"), LVCFMT_CENTER, 100);

	SetListControl();
}

void CDlgEnClosureAdd::SetListControl()
{
	// List 에 있는 내용을 모두 지운다.
	m_listData.DeleteAllItems();

	// 함체 정보 리스트에 모두 출력
	for(long i = 0; i < (long)m_pParent->m_vecEnClosureInfo.size(); i++)
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
		m_listData.SetItemText(i, 11, m_pParent->m_vecEnClosureInfo[i].strIP);
		m_listData.SetItemText(i, 12, m_pParent->m_vecEnClosureInfo[i].strPort);
		m_listData.SetItemText(i, 13, m_pParent->m_vecEnClosureInfo[i].strCompDate);
		m_listData.SetItemText(i, 14, m_pParent->m_vecEnClosureInfo[i].strInstallCompany);
		m_listData.SetItemText(i, 15, m_pParent->m_vecEnClosureInfo[i].strMaintCompany);
		m_listData.SetItemText(i, 16, m_pParent->m_vecEnClosureInfo[i].strMaintCompanyNumber);
		m_listData.SetItemText(i, 17, m_pParent->m_vecEnClosureInfo[i].strUsable);
	}
}

void CDlgEnClosureAdd::OnBnClickedButtonAdd()
{
	UpdateData(TRUE);

	CString strTemp;

	SEnClosureInfo EnClosureInfoTemp;

	if(m_cmbUse.GetCurSel() == 0) // 사용여부 콤보박스 문자로 변환
	{
		strTemp.Format(_T("정상동작"));
	}
	else
	{
		strTemp.Format(_T("비정상동작"));
	}

	// 버퍼에 모든데이터 추가
	EnClosureInfoTemp.AddData(m_strGroup1, 
		m_strGroup2, 
		m_strQRCode, 
		m_strLocationName, 
		m_strID, 
		m_strManageNumber, 
		m_strInstallDivision, 
		m_strInstallAddress, 
		m_strLatitude, 
		m_strLongitude, 
		m_strIP, 
		m_strPort, 
		m_strCompleteDate, 
		m_strInstallCompany, 
		m_strMaintCompany, 
		m_strCompanyNum1 + _T("-") + m_strCompanyNum2 + _T("-") + m_strCompanyNum3,
		strTemp);

	// 버퍼를 벡터 변수에 추가
	m_pParent->m_vecEnClosureInfo.push_back(EnClosureInfoTemp);

	// 리스트컨트롤 업데이트
	SetListControl();

	UpdateData(FALSE);
}


void CDlgEnClosureAdd::OnBnClickedButtonSelect()
{
	// 지도 창 출력
	CDlgMap dlg;
	dlg.DoModal();
}
