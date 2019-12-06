#pragma once
#include "afxwin.h"

class CSmart_FMMSDlg;

// CDlgMCCheck 대화 상자입니다.

class CDlgMCCheck : public CDialog
{
	DECLARE_DYNAMIC(CDlgMCCheck)

public:
	CDlgMCCheck(CSmart_FMMSDlg* pParent);   // 표준 생성자입니다.
	virtual ~CDlgMCCheck();

	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_MC_CHECK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CSmart_FMMSDlg* m_pParent;

	CListCtrl m_listData;
	CListCtrl m_listEnclosureData;
	CComboBox m_cmbCheck;

	void DisplayDialog();
	void InitListControl();
	void SetListDataControl();
	void SetListSelectedDataControl();
	
	afx_msg void OnBnClickedButtonRequest();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnCbnSelchangeComboCheck();
};

