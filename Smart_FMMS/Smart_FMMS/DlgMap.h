#pragma once
#include "CWebBrowser2.h"


// CDlgMap ��ȭ �����Դϴ�.

class CDlgMap : public CDialog
{
	DECLARE_DYNAMIC(CDlgMap)

public:
	CDlgMap(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMap();

	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_MAP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	void DrawImage();

	afx_msg void OnPaint();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CWebBrowser2 m_webChat;
};
