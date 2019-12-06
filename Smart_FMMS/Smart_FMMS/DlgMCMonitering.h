#pragma once

class CSmart_FMMSDlg;

// CDlgMCMonitering ��ȭ �����Դϴ�.

class CDlgMCMonitering : public CDialog
{
	DECLARE_DYNAMIC(CDlgMCMonitering)

public:
	CDlgMCMonitering(CSmart_FMMSDlg* pParent);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMCMonitering();

	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_MC_MONITERING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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

