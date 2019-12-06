// DlgMap.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "DlgMap.h"
#include "afxdialogex.h"


// CDlgMap 대화 상자입니다.

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


// CDlgMap 메시지 처리기입니다.


BOOL CDlgMap::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CComVariant var(_T("https://www.google.com/maps/@37.4042068,126.9651878,17z?hl=ko"));
	m_webChat.Navigate2(&var,NULL,NULL,NULL,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
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
	// 현재 폴더 위치 가져오기...
	CString strCurPath;
	GetModuleFileName(nullptr, strCurPath.GetBuffer(_MAX_PATH + 1), _MAX_PATH);
	strCurPath.ReleaseBuffer();
	strCurPath = strCurPath.Left(strCurPath.ReverseFind(_T('\\'))) + _T("\\지도1.JPG");

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