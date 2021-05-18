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
END_MESSAGE_MAP()


// StudentDlgClass message handlers



void StudentDlgClass::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
}


//void StudentDlgClass::OnBnClickedListBtn()
//{
//	CMFCAppDlg baseDLG;
//	baseDLG.students;
//	Person p(1, _T("Haim"), _T("Atiya"), Male, 31, 8, 1997, _T("Tzliley Hanina"), _T("Tel Aviv"), 6753080, 506383618);
//}

void StudentDlgClass::OnBnClickedListBtn()
{
	MessageBox(_T("aaaa"));
}
