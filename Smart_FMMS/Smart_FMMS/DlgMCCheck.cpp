// DlgMCCheck.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "Smart_FMMSDlg.h"
#include "DlgMCCheck.h"
#include "afxdialogex.h"
#include "DataRowset.h"


// CDlgMCCheck 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMCCheck, CDialog)

CDlgMCCheck::CDlgMCCheck(CSmart_FMMSDlg* pParent)
	: CDialog(CDlgMCCheck::IDD, pParent)
	, m_pParent(pParent)
{

}

CDlgMCCheck::~CDlgMCCheck()
{
}

void CDlgMCCheck::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DATA, m_listData);
	DDX_Control(pDX, IDC_LIST_ENCLOSURE_DATA, m_listEnclosureData);
	DDX_Control(pDX, IDC_COMBO_CHECK, m_cmbCheck);
}


BEGIN_MESSAGE_MAP(CDlgMCCheck, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_REQUEST, &CDlgMCCheck::OnBnClickedButtonRequest)
	ON_CBN_SELCHANGE(IDC_COMBO_CHECK, &CDlgMCCheck::OnCbnSelchangeComboCheck)
END_MESSAGE_MAP()


// CDlgMCCheck 메시지 처리기입니다.


BOOL CDlgMCCheck::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InitListControl();

	m_cmbCheck.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

BOOL CDlgMCCheck::PreTranslateMessage(MSG* pMsg)
{
	return ::AfxGetMainWnd()->PreTranslateMessage(pMsg);
}

void CDlgMCCheck::DisplayDialog()
{
	InitListControl();
}

// List Control 초기화
void CDlgMCCheck::InitListControl()
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

	m_listEnclosureData.SetExtendedStyle(m_listEnclosureData.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listEnclosureData.InsertColumn(0, _T(""), LVCFMT_CENTER, 15);
	m_listEnclosureData.InsertColumn(1, _T("함체위치명"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(2, _T("설치주소"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(3, _T("IP"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(4, _T("장애여부"), LVCFMT_CENTER, 100);
	/*m_listEnclosureData.InsertColumn(5, _T("함체ID"), LVCFMT_CENTER, 100);
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
	m_listEnclosureData.InsertColumn(17, _T("사용여부"), LVCFMT_CENTER, 100);*/

	SetListDataControl();
	SetListSelectedDataControl();
}

void CDlgMCCheck::SetListDataControl()
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

void CDlgMCCheck::SetListSelectedDataControl()
{
	// List 에 있는 내용을 모두 지운다.
	m_listEnclosureData.DeleteAllItems();

	// 함체 정보 리스트에 모두 출력
	for(long i = 0; i < (long)m_pParent->m_vecEnClosureInfo_Checked.size(); i++)
	{
		m_listEnclosureData.InsertItem(i, _T(""));

		/*m_listEnclosureData.SetItemText(i, 1, m_pParent->m_vecEnClosureInfo_Checked[i].strGroup1);
		m_listEnclosureData.SetItemText(i, 2, m_pParent->m_vecEnClosureInfo_Checked[i].strGroup2);
		m_listEnclosureData.SetItemText(i, 3, m_pParent->m_vecEnClosureInfo_Checked[i].strQRCode);*/
		m_listEnclosureData.SetItemText(i, 1, m_pParent->m_vecEnClosureInfo_Checked[i].strLocateName);
		/*m_listEnclosureData.SetItemText(i, 5, m_pParent->m_vecEnClosureInfo_Checked[i].strID);
		m_listEnclosureData.SetItemText(i, 6, m_pParent->m_vecEnClosureInfo_Checked[i].strManageNumber);
		m_listEnclosureData.SetItemText(i, 7, m_pParent->m_vecEnClosureInfo_Checked[i].strInstallDivision);*/
		m_listEnclosureData.SetItemText(i, 2, m_pParent->m_vecEnClosureInfo_Checked[i].strInstallAddress);
		/*m_listEnclosureData.SetItemText(i, 9, m_pParent->m_vecEnClosureInfo_Checked[i].strLatitude);
		m_listEnclosureData.SetItemText(i, 10, m_pParent->m_vecEnClosureInfo_Checked[i].strLongitude);*/
		m_listEnclosureData.SetItemText(i, 3, m_pParent->m_vecEnClosureInfo_Checked[i].strIP);
		/*m_listEnclosureData.SetItemText(i, 12, m_pParent->m_vecEnClosureInfo_Checked[i].strPort);
		m_listEnclosureData.SetItemText(i, 13, m_pParent->m_vecEnClosureInfo_Checked[i].strCompDate);
		m_listEnclosureData.SetItemText(i, 14, m_pParent->m_vecEnClosureInfo_Checked[i].strInstallCompany);
		m_listEnclosureData.SetItemText(i, 15, m_pParent->m_vecEnClosureInfo_Checked[i].strMaintCompany);
		m_listEnclosureData.SetItemText(i, 16, m_pParent->m_vecEnClosureInfo_Checked[i].strMaintCompanyNumber);*/
		m_listEnclosureData.SetItemText(i, 4, m_pParent->m_vecEnClosureInfo_Checked[i].strUsable);
		
		


	}
}

// 함체 정보 추가 버튼
void CDlgMCCheck::OnBnClickedButtonRequest()
{
	for(long i = 0; i < m_listData.GetItemCount(); i++)
	{
		if(m_listData.GetItemState(i, LVIS_SELECTED) != 0)
		{
			// 함체 점검 변수에 선택된 함체 정보 입력
			m_pParent->m_vecEnClosureInfo_Checked.push_back(m_pParent->m_vecEnClosureInfo[i]);

			// 함체 점검 변수 리스트 업데이트
			SetListSelectedDataControl();
		}
	}
}


void CDlgMCCheck::OnCbnSelchangeComboCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
