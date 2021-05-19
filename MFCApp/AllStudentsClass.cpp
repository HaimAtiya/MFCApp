// AllStudentsClass.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "AllStudentsClass.h"
#include "afxdialogex.h"
#include "stdlib.h"

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
	sList.InsertColumn(0, L"����� ����", LVCFMT_CENTER, 100);
	sList.InsertColumn(1, L"�� ����", LVCFMT_CENTER, 80);
	sList.InsertColumn(2, L"�� �����", LVCFMT_CENTER, 80);
	sList.InsertColumn(3, L"����� ����", LVCFMT_CENTER, 100);
	sList.InsertColumn(4, L"�����", LVCFMT_CENTER, 80);
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
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &AllStudentsClass::OnLvnItemchangedList2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, OnClickListCtrl)

END_MESSAGE_MAP()


// AllStudentsClass message handlers
BEGIN_EVENTSINK_MAP(AllStudentsClass, CDialogEx)
END_EVENTSINK_MAP()



// WHEN CHOOSING ROW

void AllStudentsClass::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here

	CPoint pt;
	GetCursorPos(&pt);
	sList.ScreenToClient(&pt);
	UINT Flags;
	int hItem = sList.HitTest(pt, &Flags);

	if (Flags & LVHT_ONITEMLABEL)
	{
		*curr_id = _ttoi(sList.GetItemText(hItem, 0));
		DELETE_BTN->EnableWindow(true);
	}
	else {
		if (Flags) {
			*curr_id = NULL;
			DELETE_BTN->EnableWindow(false);
		}
	}
	*pResult = 0;
}

//WHEN DOUBLE CLICKING ROW
void AllStudentsClass::OnClickListCtrl(NMHDR* pNMHDR, LRESULT* pResult)
{
	CPoint pt;
	GetCursorPos(&pt);
	sList.ScreenToClient(&pt);
	UINT Flags;
	int hItem = sList.HitTest(pt, &Flags);
	
	if (Flags & LVHT_ONITEMLABEL)
	{
		MessageBox(sList.GetItemText(hItem, 1));
	}
	*pResult = 0;
}