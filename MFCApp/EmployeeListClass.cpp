// EmployeeListClass.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "EmployeeListClass.h"
#include "afxdialogex.h"


// EmployeeListClass dialog

IMPLEMENT_DYNAMIC(EmployeeListClass, CDialogEx)

EmployeeListClass::EmployeeListClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(EMPLOYEE_LIST, pParent)
{

}

EmployeeListClass::~EmployeeListClass()
{
}
BOOL EmployeeListClass::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	eList.SetExtendedStyle(eList.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	eList.InsertColumn(0, L"תעודת זהות", LVCFMT_CENTER, 80);
	eList.InsertColumn(1, L"שם פרטי", LVCFMT_CENTER, 85);
	eList.InsertColumn(2, L"שם משפחה", LVCFMT_CENTER, 85);
	eList.InsertColumn(3, L"תאריך לידה", LVCFMT_CENTER, 80);
	eList.InsertColumn(4, L"סוג", LVCFMT_CENTER, 80);
	eList.InsertColumn(5, L"פעיל?", LVCFMT_CENTER, 80);
	eList.InsertColumn(6, L"כתובת", LVCFMT_CENTER, 200);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void EmployeeListClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, EMPLOYEE_LIST_CTRL, eList);
}


BEGIN_MESSAGE_MAP(EmployeeListClass, CDialogEx)
END_MESSAGE_MAP()


// EmployeeListClass message handlers
