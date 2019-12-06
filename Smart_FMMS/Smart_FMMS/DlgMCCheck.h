#pragma once
#include "afxwin.h"

class CSmart_FMMSDlg;

// CDlgMCCheck ��ȭ �����Դϴ�.

class CDlgMCCheck : public CDialog
{
	DECLARE_DYNAMIC(CDlgMCCheck)

public:
	CDlgMCCheck(CSmart_FMMSDlg* pParent);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMCCheck();

	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_MC_CHECK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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

