// DlgStatistics.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "Smart_FMMSDlg.h"
#include "DlgStatistics.h"
#include "afxdialogex.h"


// CDlgStatistics ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgStatistics, CDialog)

CDlgStatistics::CDlgStatistics(CSmart_FMMSDlg* pParent)
	: CDialog(CDlgStatistics::IDD, pParent)
	, m_pParent(pParent)
	, m_strFileName(_T("blank"))
{

}

CDlgStatistics::~CDlgStatistics()
{
}

void CDlgStatistics::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_MC_TYPE, m_cmbMCType);
}


BEGIN_MESSAGE_MAP(CDlgStatistics, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CDlgStatistics::OnBnClickedButtonSearch)
END_MESSAGE_MAP()


// CDlgStatistics �޽��� ó�����Դϴ�.


BOOL CDlgStatistics::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_cmbMCType.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BOOL CDlgStatistics::PreTranslateMessage(MSG* pMsg)
{
	return ::AfxGetMainWnd()->PreTranslateMessage(pMsg);
}


void CDlgStatistics::OnPaint()
{
	DrawImage();

	CDialog::OnPaint();
}

void CDlgStatistics::DisplayDialog()
{
	DrawImage();
}

void CDlgStatistics::DrawImage()
{
	// ���� ���� ��ġ ��������...
	CString strCurPath;
	GetModuleFileName(nullptr, strCurPath.GetBuffer(_MAX_PATH + 1), _MAX_PATH);
	strCurPath.ReleaseBuffer();
	strCurPath = strCurPath.Left(strCurPath.ReverseFind(_T('\\'))) + _T("\\") + m_strFileName + _T(".JPG");

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

void CDlgStatistics::OnBnClickedButtonSearch()
{
	m_strFileName = _T("��Ʈ");

	DrawImage();
}
