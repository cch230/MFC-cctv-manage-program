#pragma once
#include "afxcmn.h"
#include "afxwin.h"

class CSmart_FMMSDlg;

// CDlgEnClosureAdd ��ȭ �����Դϴ�.

class CDlgEnClosureAdd : public CDialog
{
	DECLARE_DYNAMIC(CDlgEnClosureAdd)

public:
	CDlgEnClosureAdd(CSmart_FMMSDlg* pParent);   // ǥ�� �������Դϴ�.
	virtual ~CDlgEnClosureAdd();

	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_ENCLOSURE_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	CSmart_FMMSDlg* m_pParent;
	CListCtrl m_listData;

	void DisplayDialog();
	void InitListControl();
	void SetListControl();

	CString m_strGroup1;
	CString m_strGroup2;
	CString m_strQRCode;
	CString m_strLocationName;
	CString m_strID;
	CString m_strManageNumber;
	CString m_strInstallDivision;
	CString m_strInstallAddress;
	CString m_strLatitude;
	CString m_strLongitude;
	CString m_strIP;
	CString m_strPort;
	CString m_strCompleteDate;
	CString m_strInstallCompany;
	CString m_strMaintCompany;
	CString m_strCompanyNum1;
	CString m_strCompanyNum2;
	CString m_strCompanyNum3;
	CComboBox m_cmbUse;
	
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSelect();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
