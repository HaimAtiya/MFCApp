// AddStudentClass.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "AddStudentClass.h"
#include "afxdialogex.h"


// AddStudentClass dialog

IMPLEMENT_DYNAMIC(AddStudentClass, CDialogEx)

AddStudentClass::AddStudentClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ADD_STUDENT, pParent)
{

}

AddStudentClass::~AddStudentClass()
{
}

void AddStudentClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddStudentClass, CDialogEx)
END_MESSAGE_MAP()


// AddStudentClass message handlers
