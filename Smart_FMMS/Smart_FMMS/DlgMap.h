#pragma once
#include "CWebBrowser2.h"


// CDlgMap 대화 상자입니다.

class CDlgMap : public CDialog
{
	DECLARE_DYNAMIC(CDlgMap)

public:
	CDlgMap(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMap();

	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_MAP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	void DrawImage();

	afx_msg void OnPaint();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CWebBrowser2 m_webChat;
};
