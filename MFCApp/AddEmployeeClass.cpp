// AddEmployeeClass.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "AddEmployeeClass.h"
#include "afxdialogex.h"


// AddEmployeeClass dialog

IMPLEMENT_DYNAMIC(AddEmployeeClass, CDialogEx)

AddEmployeeClass::AddEmployeeClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ADD_EMPLOYEE, pParent)
{

}

AddEmployeeClass::~AddEmployeeClass()
{
}

void AddEmployeeClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ADD_EMPLOYEE_HEADER, header_title);
}


BEGIN_MESSAGE_MAP(AddEmployeeClass, CDialogEx)
	ON_STN_CLICKED(ADD_EMPLOYEE_HEADER, &AddEmployeeClass::OnStnClickedEmployeeHeader)
END_MESSAGE_MAP()


// AddEmployeeClass message handlers


void AddEmployeeClass::OnStnClickedEmployeeHeader()
{
	// TODO: Add your control notification handler code here
}

void AddEmployeeClass::setFormTitle(CString title) {
	CWnd* label = GetDlgItem(ADD_EMPLOYEE_HEADER);
	label->SetWindowText(title);
}
void AddEmployeeClass::setFormMode(char mode) {
	switch (mode)
	{
	case 'T':
		setFormTitle(L"הוספת מורה חדש");
		break;
	case 'W':
		setFormTitle(L"הוספת עובד חדש");
		break;
	default:
		break;
	}
}