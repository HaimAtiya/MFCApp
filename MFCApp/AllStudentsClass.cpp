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

void AllStudentsClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AllStudentsClass, CDialogEx)
END_MESSAGE_MAP()


// AllStudentsClass message handlers
