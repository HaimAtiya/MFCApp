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
	eList.InsertColumn(6, L"כתובת", LVCFMT_CENTER, 174);
	updateList();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void EmployeeListClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, EMPLOYEE_LIST_CTRL, eList);
}


BEGIN_MESSAGE_MAP(EmployeeListClass, CDialogEx)
END_MESSAGE_MAP()


void EmployeeListClass::updateList() {
	eList.DeleteAllItems();
	int nItem;
	CString tmp;
	//Teachers
	for (int i = 0; i < Teachers->GetSize(); i++) {
		Teacher* t = Teachers->GetAt(i);
		tmp.Format(_T("%d"), t->getID());
		nItem = eList.InsertItem(0, tmp);
		eList.SetItemText(nItem, 1, t->getFName());
		eList.SetItemText(nItem, 2, t->getLName());
		eList.SetItemText(nItem, 3, L"מורה");
		tmp.Format(_T("%s"), t->getWorkingStatus() ? "כן" : "לא");
		eList.SetItemText(nItem, 4, tmp);
		eList.SetItemText(nItem, 5, t->getAddress());
	}
	//Workers
	for (int i = 0; i < Workers->GetSize(); i++) {
		Worker* w = Workers->GetAt(i);
		tmp.Format(_T("%d"), w->getID());
		nItem = eList.InsertItem(0, tmp);
		eList.SetItemText(nItem, 1, w->getFName());
		eList.SetItemText(nItem, 2, w->getLName());
		eList.SetItemText(nItem, 3, L"איש צוות");
		tmp.Format(_T("%s"), w->getWorkingStatus() ? "כן" : "לא");
		eList.SetItemText(nItem, 4, tmp);
		eList.SetItemText(nItem, 5, w->getAddress());
	}
}
