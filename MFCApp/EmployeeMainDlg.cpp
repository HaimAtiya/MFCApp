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

void EmployeeMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EmployeeMainDlg, CDialogEx)
END_MESSAGE_MAP()


// EmployeeMainDlg message handlers
