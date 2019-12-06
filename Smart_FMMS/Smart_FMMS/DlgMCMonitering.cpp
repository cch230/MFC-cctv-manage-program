// DlgMCMonitering.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "Smart_FMMSDlg.h"
#include "DlgMCMonitering.h"
#include "afxdialogex.h"
#include "DataRowset.h"

// CDlgMCMonitering ��ȭ �����Դϴ�.

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


// CDlgMCMonitering �޽��� ó�����Դϴ�.


BOOL CDlgMCMonitering::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	InitListControl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	// ���� ���� ��ġ ��������...
	CString strCurPath;
	GetModuleFileName(nullptr, strCurPath.GetBuffer(_MAX_PATH + 1), _MAX_PATH);
	strCurPath.ReleaseBuffer();
	strCurPath = strCurPath.Left(strCurPath.ReverseFind(_T('\\'))) + _T("\\����3.JPG");

	CImage image;
	image.Destroy();

	// ���� ���� �ҷ�����
	HRESULT hResult = image.Load(strCurPath);

	CPaintDC dc(this);
	CRect rect;

	dc.SelectStockObject(NULL_BRUSH);
		
	GetDlgItem(IDC_STATIC_MAP)->GetWindowRect(rect);
	ScreenToClient(&rect);
	
	dc.Rectangle(rect);
	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);

	// ���� ���
	image.Draw(dc.m_hDC, rect);

	Invalidate(false);
}

// List Control �ʱ�ȭ
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
	/*m_listData.InsertColumn(9, _T("����"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(10, _T("�浵"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(11, _T("IP"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(12, _T("Port"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(13, _T("�ذ���"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(14, _T("��ġ��ü"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(15, _T("����������ü"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(16, _T("��ü����ó"), LVCFMT_CENTER, 100);
	m_listData.InsertColumn(17, _T("��뿩��"), LVCFMT_CENTER, 100);*/

	m_listMCData.SetExtendedStyle(m_listMCData.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listMCData.InsertColumn(0, _T("���Ÿ��"), LVCFMT_CENTER, 100);
	m_listMCData.InsertColumn(1, _T("��ġ��Ҹ�"), LVCFMT_CENTER, 180);
	m_listMCData.InsertColumn(2, _T("������"), LVCFMT_CENTER, 120);
	m_listMCData.InsertColumn(3, _T("�𵨸�"), LVCFMT_CENTER, 150);
	m_listMCData.InsertColumn(4, _T("IP�ּ�"), LVCFMT_CENTER, 100);
	m_listMCData.InsertColumn(5, _T("Etc."), LVCFMT_CENTER, 100);
	
	
	CDataRowset DataRowset;
	if (!DataRowset.Open()) {
		AfxMessageBox(_T("������ �ҽ��� ���� ����"));
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
	// List �� �ִ� ������ ��� �����.
	//m_listMCData.DeleteAllItems();
	CDataRowset DataRowset;
	if (!DataRowset.Open()) {
		AfxMessageBox(_T("������ �ҽ��� ���� ����"));
	}
	// ��� ���� ����Ʈ�� ��� ���
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