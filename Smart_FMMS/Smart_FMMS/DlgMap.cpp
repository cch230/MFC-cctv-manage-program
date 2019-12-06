// DlgMap.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "DlgMap.h"
#include "afxdialogex.h"


// CDlgMap ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgMap, CDialog)

CDlgMap::CDlgMap(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMap::IDD, pParent)
{

}

CDlgMap::~CDlgMap()
{
}

void CDlgMap::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_webChat);
}


BEGIN_MESSAGE_MAP(CDlgMap, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgMap �޽��� ó�����Դϴ�.


BOOL CDlgMap::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CComVariant var(_T("https://www.google.com/maps/@37.4042068,126.9651878,17z?hl=ko"));
	m_webChat.Navigate2(&var,NULL,NULL,NULL,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

BOOL CDlgMap::PreTranslateMessage(MSG* pMsg)
{
	return ::AfxGetMainWnd()->PreTranslateMessage(pMsg);
}

void CDlgMap::OnPaint()
{
	DrawImage();

	CDialog::OnPaint();
}

void CDlgMap::DrawImage()
{
	// ���� ���� ��ġ ��������...
	CString strCurPath;
	GetModuleFileName(nullptr, strCurPath.GetBuffer(_MAX_PATH + 1), _MAX_PATH);
	strCurPath.ReleaseBuffer();
	strCurPath = strCurPath.Left(strCurPath.ReverseFind(_T('\\'))) + _T("\\����1.JPG");

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