#pragma once
#include "afxcmn.h"

class CSmart_FMMSDlg;

// CDlgEnClosureMonitering ��ȭ �����Դϴ�.

class CDlgEnClosureMonitering : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnClosureMonitering)

public:
	CDlgEnClosureMonitering(CSmart_FMMSDlg* pParent);   // ǥ�� �������Դϴ�.
	virtual ~CDlgEnClosureMonitering();

	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_ENCLOSURE_MONITERING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CSmart_FMMSDlg* m_pParent;
	
	CListCtrl m_listData;
	CListCtrl m_listEnclosureData;

	void DisplayDialog();
	void InitListControl();
	void SetListDataControl();
	void SetListSelectedDataControl();
	void DrawImage();
	
	afx_msg void OnPaint();
	afx_msg void OnNMDblclkListData(NMHDR *pNMHDR, LRESULT *pResult);

	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
