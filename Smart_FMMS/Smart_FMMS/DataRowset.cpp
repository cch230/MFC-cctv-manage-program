// DataRowset.h : CDataRowset Ŭ������ �����Դϴ�.



// CDataRowset �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 11�� ȭ����, ���� 5:18

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
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CDataRowset::GetDefaultConnect()
{
	return _T("DSN=DatabaseDesignEx;DBQ=C:\\PROGRAM FILES\\AHNLAB\\DatabaseDesignEx.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CDataRowset::GetDefaultSQL()
{
	return _T("[��ġ�������]");
}

void CDataRowset::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
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
// CDataRowset ����

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


