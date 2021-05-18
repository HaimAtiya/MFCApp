// StudentDlgClass.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "StudentDlgClass.h"
#include "afxdialogex.h"
#include "MFCAppDlg.h"


// StudentDlgClass dialog

IMPLEMENT_DYNAMIC(StudentDlgClass, CDialogEx)

StudentDlgClass::StudentDlgClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Students_Dlg, pParent)
{
}

StudentDlgClass::~StudentDlgClass()
{

}

void StudentDlgClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StudentDlgClass, CDialogEx)
//	ON_BN_CLICKED(STUDENTS_LIST_BTN, &StudentDlgClass::OnBnClickedListBtn)
	ON_BN_CLICKED(IDC_BUTTON2, &StudentDlgClass::OnBnClickedButton2)
	ON_BN_CLICKED(STUDENTS_LIST_BTN, &StudentDlgClass::OnBnClickedListBtn)
	ON_BN_CLICKED(IDC_BUTTON7, &StudentDlgClass::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON6, &StudentDlgClass::OnBnClickedButton6)
END_MESSAGE_MAP()


// StudentDlgClass message handlers



void StudentDlgClass::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
}

void StudentDlgClass::OnBnClickedListBtn()
{

	Person p1(1, L"Moshe", L"Moshe", Male, 11, 8, 1997, L"Tzliley Hanina", L"Tel Aviv", 6753080, 506383618);
	Student *s2 = new Student(p1, p1, p1);
	this->students->Add(s2);
}



//Save
void StudentDlgClass::OnBnClickedButton7()
{
	CFileDialog dlg(FALSE, _T(".students"), NULL, 0, _T("Students (*.students)|*.students|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		students->Serialize(ar);
		ar.Close();
		file.Close();
		MessageBox(L"רשימת התלמידים נשמרה בהצלחה!");
	}
}


//Open
void StudentDlgClass::OnBnClickedButton6()
{
	CFileDialog dlg(TRUE, _T(".students"), NULL, 0, _T("Students (*.students)|*.students|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		students->Serialize(ar);
		ar.Close();
		file.Close();
		MessageBox(L"רשימת התלמידים נטענה בהצלחה!");
	}
}
