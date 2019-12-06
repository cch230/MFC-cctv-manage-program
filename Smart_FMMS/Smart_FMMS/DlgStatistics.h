#pragma once
#include "afxwin.h"

class CSmart_FMMSDlg;

// CDlgStatistics 대화 상자입니다.

class CDlgStatistics : public CDialog
{
	DECLARE_DYNAMIC(CDlgStatistics)

public:
	CDlgStatistics(CSmart_FMMSDlg* pParent);   // 표준 생성자입니다.
	virtual ~CDlgStatistics();

	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_STATISTICS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CSmart_FMMSDlg* m_pParent;

	CComboBox m_cmbMCType;
	CString m_strFileName;

	void DisplayDialog();
	void DrawImage();
	
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonSearch();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

