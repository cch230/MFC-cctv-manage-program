// DataRowset.h : CDataRowset 클래스의 구현입니다.



// CDataRowset 구현입니다.

// 코드 생성 위치 2018년 12월 11일 화요일, 오후 5:18

#include "stdafx.h"
#include "DataRowset.h"
IMPLEMENT_DYNAMIC(CDataRowset, CRecordset)

CDataRowset::CDataRowset(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Index = L"";
	m_LocationName = L"";
	m_EquipmentType = L"";
	m_State = L"";
	m_Manufacturer = L"";
	m_ModelName = L"";
	m_IPAddress = L"";
	m_Password = L"";
	m_Etc = L"";
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CDataRowset::GetDefaultConnect()
{
	return _T("DSN=DatabaseDesignEx;DBQ=C:\\PROGRAM FILES\\AHNLAB\\DatabaseDesignEx.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CDataRowset::GetDefaultSQL()
{
	return _T("[설치장비정보]");
}

void CDataRowset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Text(pFX, _T("[Index]"), m_Index);
	RFX_Text(pFX, _T("[LocationName]"), m_LocationName);
	RFX_Text(pFX, _T("[EquipmentType]"), m_EquipmentType);
	RFX_Text(pFX, _T("[State]"), m_State);
	RFX_Text(pFX, _T("[Manufacturer]"), m_Manufacturer);
	RFX_Text(pFX, _T("[ModelName]"), m_ModelName);
	RFX_Text(pFX, _T("[IPAddress]"), m_IPAddress);
	RFX_Text(pFX, _T("[Password]"), m_Password);
	RFX_Text(pFX, _T("[Etc]"), m_Etc);

}
/////////////////////////////////////////////////////////////////////////////
// CDataRowset 진단

#ifdef _DEBUG
void CDataRowset::AssertValid() const
{
	CRecordset::AssertValid();
}


void CDataRowset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


