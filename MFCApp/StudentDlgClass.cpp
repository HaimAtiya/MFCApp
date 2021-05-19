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

BOOL StudentDlgClass::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	allStudentDlg.Create(ALL_STUDENTS, this);
	addStudentDlg.Create(ADD_STUDENT, this);
	deleteStudentDlg.Create(DELETE_STUDENT, this);
	return TRUE;  // return TRUE  unless you set the focus to a control
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
	ON_BN_CLICKED(IDC_BUTTON5, &StudentDlgClass::OnBnClickedButton5)
END_MESSAGE_MAP()


// StudentDlgClass message handlers

//ALL STUDET LIST BTN
void StudentDlgClass::OnBnClickedListBtn()
{
	/*
		Person p1(1, L"Moshe", L"Moshe", Male, 11, 8, 1997, L"Tzliley Hanina", L"Tel Aviv", 6753080, 506383618);
		Student *s2 = new Student(p1, p1, p1);
		this->students->Add(s2);
		*/

	deleteStudentDlg.ShowWindow(SW_HIDE);
	addStudentDlg.ShowWindow(SW_HIDE);
	allStudentDlg.ShowWindow(SW_SHOW);

}
//ADD NEW STUDENT
void StudentDlgClass::OnBnClickedButton2()
{
	deleteStudentDlg.ShowWindow(SW_HIDE);
	allStudentDlg.ShowWindow(SW_HIDE);
	addStudentDlg.ShowWindow(SW_SHOW);

}

//DELTE STUDENT
void StudentDlgClass::OnBnClickedButton5()
{
	addStudentDlg.ShowWindow(SW_HIDE);
	allStudentDlg.ShowWindow(SW_HIDE);
	deleteStudentDlg.ShowWindow(SW_SHOW);
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

