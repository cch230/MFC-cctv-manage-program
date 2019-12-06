// DlgMCCheck.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "Smart_FMMSDlg.h"
#include "DlgMCCheck.h"
#include "afxdialogex.h"
#include "DataRowset.h"


// CDlgMCCheck ��ȭ �����Դϴ�.

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


// CDlgMCCheck �޽��� ó�����Դϴ�.


BOOL CDlgMCCheck::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	InitListControl();

	m_cmbCheck.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BOOL CDlgMCCheck::PreTranslateMessage(MSG* pMsg)
{
	return ::AfxGetMainWnd()->PreTranslateMessage(pMsg);
}

void CDlgMCCheck::DisplayDialog()
{
	InitListControl();
}

// List Control �ʱ�ȭ
void CDlgMCCheck::InitListControl()
{
	m_listData.SetExtendedStyle(m_listData.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listData.InsertColumn(0, _T(""), LVCFMT_CENTER, 15);
	m_listData.InsertColumn(1, _T("�׷��1"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(2, _T("�׷��2"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(3, _T("QR�ڵ�"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(4, _T("��ü��ġ��"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(5, _T("��üID"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(6, _T("������ȣ"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(7, _T("��ġ����"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(8, _T("��ġ�ּ�"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(9, _T("����"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(10, _T("�浵"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(11, _T("IP"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(12, _T("Port"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(13, _T("�ذ���"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(14, _T("��ġ��ü"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(15, _T("����������ü"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(16, _T("��ü����ó"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(17, _T("��뿩��"), LVCFMT_CENTER, 100);

	m_listEnclosureData.SetExtendedStyle(m_listEnclosureData.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listEnclosureData.InsertColumn(0, _T(""), LVCFMT_CENTER, 15);
	m_listEnclosureData.InsertColumn(1, _T("��ü��ġ��"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(2, _T("��ġ�ּ�"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(3, _T("IP"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(4, _T("��ֿ���"), LVCFMT_CENTER, 100);
	/*m_listEnclosureData.InsertColumn(5, _T("��üID"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(6, _T("������ȣ"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(7, _T("��ġ����"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(8, _T("��ġ�ּ�"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(9, _T("����"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(10, _T("�浵"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(11, _T("IP"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(12, _T("Port"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(13, _T("�ذ���"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(14, _T("��ġ��ü"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(15, _T("����������ü"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(16, _T("��ü����ó"), LVCFMT_CENTER, 100);
	m_listEnclosureData.InsertColumn(17, _T("��뿩��"), LVCFMT_CENTER, 100);*/

	SetListDataControl();
	SetListSelectedDataControl();
}

void CDlgMCCheck::SetListDataControl()
{
	// List �� �ִ� ������ ��� �����.
	m_listData.DeleteAllItems();

	// ��ü ���� ����Ʈ�� ��� ���
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
	// List �� �ִ� ������ ��� �����.
	m_listEnclosureData.DeleteAllItems();

	// ��ü ���� ����Ʈ�� ��� ���
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

// ��ü ���� �߰� ��ư
void CDlgMCCheck::OnBnClickedButtonRequest()
{
	for(long i = 0; i < m_listData.GetItemCount(); i++)
	{
		if(m_listData.GetItemState(i, LVIS_SELECTED) != 0)
		{
			// ��ü ���� ������ ���õ� ��ü ���� �Է�
			m_pParent->m_vecEnClosureInfo_Checked.push_back(m_pParent->m_vecEnClosureInfo[i]);

			// ��ü ���� ���� ����Ʈ ������Ʈ
			SetListSelectedDataControl();
		}
	}
}


void CDlgMCCheck::OnCbnSelchangeComboCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
