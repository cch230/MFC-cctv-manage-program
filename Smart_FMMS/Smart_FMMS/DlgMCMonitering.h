#pragma once

class CSmart_FMMSDlg;

// CDlgMCMonitering 대화 상자입니다.

class CDlgMCMonitering : public CDialog
{
	DECLARE_DYNAMIC(CDlgMCMonitering)

public:
	CDlgMCMonitering(CSmart_FMMSDlg* pParent);   // 표준 생성자입니다.
	virtual ~CDlgMCMonitering();

	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_MC_MONITERING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CSmart_FMMSDlg* m_pParent;

	CListCtrl m_listData;
	CListCtrl m_listMCData;

	void DisplayDialog();
	void InitListControl();
	void SetListDataControl();
	void SetListMCDataControl();
	void DrawImage();
	
	afx_msg void OnPaint();
	
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

