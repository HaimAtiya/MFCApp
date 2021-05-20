// EmployeeMainDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "EmployeeMainDlg.h"
#include "afxdialogex.h"


// EmployeeMainDlg dialog

IMPLEMENT_DYNAMIC(EmployeeMainDlg, CDialogEx)

EmployeeMainDlg::EmployeeMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(EMPLOYEE_MAIN, pParent)
{

}

EmployeeMainDlg::~EmployeeMainDlg()
{
}

BOOL EmployeeMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	listDlg.Create(EMPLOYEE_LIST, this);
	listDlg.ShowWindow(SW_SHOW);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void EmployeeMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EmployeeMainDlg, CDialogEx)
END_MESSAGE_MAP()


// EmployeeMainDlg message handlers
