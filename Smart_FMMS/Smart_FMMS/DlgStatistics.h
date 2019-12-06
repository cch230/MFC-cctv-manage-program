#pragma once
#include "afxwin.h"

class CSmart_FMMSDlg;

// CDlgStatistics ��ȭ �����Դϴ�.

class CDlgStatistics : public CDialog
{
	DECLARE_DYNAMIC(CDlgStatistics)

public:
	CDlgStatistics(CSmart_FMMSDlg* pParent);   // ǥ�� �������Դϴ�.
	virtual ~CDlgStatistics();

	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_STATISTICS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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

