
// Smart_FMMSDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

#include <vector>
#include "DataRowset.h"

class CDlgEnClosureAdd;
class CDlgEnClosureMonitering;
class CDlgMCCheck;
class CDlgMCMonitering;
class CDlgStatistics;

struct SEnClosureInfo
{
	
	CString strGroup1;
	CString strGroup2;
	CString strQRCode;
	CString strLocateName;
	CString strID;
	CString strManageNumber;
	CString strInstallDivision;
	CString strInstallAddress;
	CString strLatitude;
	CString strLongitude;
	CString strIP;
	CString strPort;
	CString strCompDate;
	CString strInstallCompany;
	CString strMaintCompany;
	CString strMaintCompanyNumber;
	CString strUsable;

	void AddData(
		
		CString Group1, 
		CString Group2, 
		CString QRCode, 
		CString LocateName, 
		CString ID, 
		CString ManageNumber, 
		CString InstallDivision, 
		CString InstallAddress, 
		CString Latitude, 
		CString Longitude, 
		CString IP, 
		CString Port, 
		CString CompDate, 
		CString InstallCompany, 
		CString MaintCompany, 
		CString MaintCompanyNumber, 
		CString Usable)
	{
		strGroup1 = Group1;
		strGroup2 = Group2;
		strQRCode = QRCode;
		strLocateName = LocateName;
		strID = ID;
		strManageNumber = ManageNumber;
		strInstallDivision = InstallDivision;
		strInstallAddress = InstallAddress;
		strLatitude = Latitude;
		strLongitude = Longitude;
		strIP = IP;
		strPort = Port;
		strCompDate = CompDate;
		strInstallCompany = InstallCompany;
		strMaintCompany = MaintCompany;
		strMaintCompanyNumber = MaintCompanyNumber;
		strUsable = Usable;
	}
	

};

struct SInstallMCInfo
{
	CString strType;
	CString strLocation;
	CString strInstallCompany;
	CString strModelName;
	CString strIPAddress;
	CString strEtc;

	void AddData(CString Type, 
		CString Location, 
		CString InstallCompany, 
		CString ModelName, 
		CString IPAddress, 
		CString Etc)
	{
		strType = Type;
		strLocation = Location;
		strInstallCompany = InstallCompany;
		strModelName = ModelName;
		strIPAddress = IPAddress;
		strEtc = Etc;
	}
};


// CSmart_FMMSDlg ��ȭ ����
class CSmart_FMMSDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSmart_FMMSDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	~CSmart_FMMSDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SMART_FMMS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CDlgEnClosureAdd* m_pDlgEnClosureAdd;
	CDlgEnClosureMonitering* m_pDlgEnClosureMonitering;
	CDlgMCCheck* m_pDlgMCCheck;
	CDlgMCMonitering* m_pDlgMCMonitering;
	CDlgStatistics* m_pDlgStatistics;

	CButton m_checkEnclosureAdd;
	CButton m_checkEnclosureMonitering;
	CButton m_checkMCMonitering;
	CButton m_checkMCCheck;
	CButton m_checkStatistics;

	long m_nButtonSelect;
	std::vector<SEnClosureInfo> m_vecEnClosureInfo;
	std::vector<SEnClosureInfo> m_vecEnClosureInfo_Selected;
	std::vector<SEnClosureInfo> m_vecEnClosureInfo_Checked;
	std::vector<SInstallMCInfo> m_vecInstallMCInfo;

	void LoadEnClosureMCInfo();

	afx_msg void OnBnClickedCheckEnclosureAdd();
	afx_msg void OnBnClickedCheckEnclosureMonitering();
	afx_msg void OnBnClickedCheckMcMonitering();
	afx_msg void OnBnClickedCheckMcCheck();
	afx_msg void OnBnClickedCheckStatistics();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
