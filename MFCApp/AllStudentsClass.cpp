// AllStudentsClass.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "AllStudentsClass.h"
#include "afxdialogex.h"


// AllStudentsClass dialog

IMPLEMENT_DYNAMIC(AllStudentsClass, CDialogEx)

AllStudentsClass::AllStudentsClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ALL_STUDENTS, pParent)
{

}

AllStudentsClass::~AllStudentsClass()
{
}


BOOL AllStudentsClass::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	sList.SetExtendedStyle(sList.GetExtendedStyle() |LVS_EX_FULLROWSELECT);
	sList.InsertColumn(0, L"תעודת זהות", LVCFMT_CENTER, 100);
	sList.InsertColumn(1, L"שם פרטי", LVCFMT_CENTER, 80);
	sList.InsertColumn(2, L"שם משפחה", LVCFMT_CENTER, 80);
	sList.InsertColumn(3, L"תאריך לידה", LVCFMT_CENTER, 100);
	sList.InsertColumn(4, L"כתובת", LVCFMT_CENTER, 80);
	updateList();


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void AllStudentsClass::updateList() {
	sList.DeleteAllItems();
	int nItem;

	for (int i = 0; i < students->GetSize(); i++) {
		Student* stdnt = students->GetAt(i);
		CString tmp;
		tmp.Format(_T("%d"), stdnt->getStudentPersonDetails().getID());
		nItem = sList.InsertItem(0, tmp);
		sList.SetItemText(nItem, 1, stdnt->getStudentPersonDetails().getFName());
		sList.SetItemText(nItem, 2, stdnt->getStudentPersonDetails().getLName());
		sList.SetItemText(nItem, 3, stdnt->getStudentPersonDetails().getBirthDay());
		sList.SetItemText(nItem, 4, stdnt->getStudentPersonDetails().getAddress());

	}
}

void AllStudentsClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, sList);
}


BEGIN_MESSAGE_MAP(AllStudentsClass, CDialogEx)
END_MESSAGE_MAP()


// AllStudentsClass message handlers
BEGIN_EVENTSINK_MAP(AllStudentsClass, CDialogEx)
END_EVENTSINK_MAP()



