#pragma once
#include "afxcmn.h"

class CSmart_FMMSDlg;

// CDlgEnClosureMonitering 대화 상자입니다.

class CDlgEnClosureMonitering : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnClosureMonitering)

public:
	CDlgEnClosureMonitering(CSmart_FMMSDlg* pParent);   // 표준 생성자입니다.
	virtual ~CDlgEnClosureMonitering();

	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_ENCLOSURE_MONITERING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
