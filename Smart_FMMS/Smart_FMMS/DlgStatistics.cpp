// DlgStatistics.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Smart_FMMS.h"
#include "Smart_FMMSDlg.h"
#include "DlgStatistics.h"
#include "afxdialogex.h"


// CDlgStatistics 대화 상자입니다.

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


// CDlgStatistics 메시지 처리기입니다.


BOOL CDlgStatistics::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_cmbMCType.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
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
	// 현재 폴더 위치 가져오기...
	CString strCurPath;
	GetModuleFileName(nullptr, strCurPath.GetBuffer(_MAX_PATH + 1), _MAX_PATH);
	strCurPath.ReleaseBuffer();
	strCurPath = strCurPath.Left(strCurPath.ReverseFind(_T('\\'))) + _T("\\") + m_strFileName + _T(".JPG");

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

void CDlgStatistics::OnBnClickedButtonSearch()
{
	m_strFileName = _T("차트");

	DrawImage();
}
