// editStudentClass.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "editStudentClass.h"
#include "afxdialogex.h"


// editStudentClass dialog

IMPLEMENT_DYNAMIC(editStudentClass, CDialogEx)

editStudentClass::editStudentClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(EDIT_STUDENT, pParent)
{

}

editStudentClass::~editStudentClass()
{
}

BOOL editStudentClass::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//find student
	for (int i = 0; i < students->GetSize(); i++) {
		if (students->GetAt(i)->getID() == id)
		{
			student = students->GetAt(i);
			break;
		}
	}
	
	//inset values into controls:
	CString tmp;

	/* STUDENT VALUES*/
	S_FNAME.SetWindowText(student->getFName());
	S_LNAME.SetWindowText(student->getLName());
	S_STREET.SetWindowText(student->getStreet());
	S_CITY.SetWindowText(student->getCity());
	tmp.Format(L"%d", student->getID());
	S_ID.SetWindowText(tmp);
	tmp.Format(L"%d", student->getPhoneNumber());
	S_PHONE.SetWindowText(tmp);
	tmp.Format(L"%d", student->getZipCode());
	S_ZIPCODE.SetWindowText(tmp);
	S_GENDER.AddString(L"זכר");
	S_GENDER.SetCurSel(0);
	tmp.Format(L"%d", student->getDayOfBirth());
	S_DAY.AddString(tmp);
	S_DAY.SetCurSel(0);
	tmp.Format(L"%d", student->getMonthOfBirth());
	S_MONTH.AddString(tmp);
	S_MONTH.SetCurSel(0);
	tmp.Format(L"%d", student->getYearOfBirth());
	S_YEAR.AddString(tmp);
	S_YEAR.SetCurSel(0);

	/* MOTHER VALUES*/
	M_FNAME.SetWindowText(student->getMother().getFName());
	M_LNAME.SetWindowText(student->getMother().getLName());
	M_STREET.SetWindowText(student->getMother().getStreet());
	M_CITY.SetWindowText(student->getMother().getCity());
	tmp.Format(L"%d", student->getMother().getID());
	M_ID.SetWindowText(tmp);
	tmp.Format(L"%d", student->getMother().getPhoneNumber());
	M_PHONE.SetWindowText(tmp);
	tmp.Format(L"%d", student->getMother().getZipCode());
	M_ZIPCODE.SetWindowText(tmp);
	M_GENDER.AddString(L"נקבה");
	M_GENDER.SetCurSel(0);
	tmp.Format(L"%d", student->getMother().getDayOfBirth());
	M_DAY.AddString(tmp);
	M_DAY.SetCurSel(0);
	tmp.Format(L"%d", student->getMother().getMonthOfBirth());
	M_MONTH.AddString(tmp);
	M_MONTH.SetCurSel(0);
	tmp.Format(L"%d", student->getMother().getYearOfBirth());
	M_YEAR.AddString(tmp);
	M_YEAR.SetCurSel(0);

	/* FATHER VALUES*/
	F_FNAME.SetWindowText(student->getFather().getFName());
	F_LNAME.SetWindowText(student->getFather().getLName());
	F_STREET.SetWindowText(student->getFather().getStreet());
	F_CITY.SetWindowText(student->getFather().getCity());
	tmp.Format(L"%d", student->getFather().getID());
	F_ID.SetWindowText(tmp);
	tmp.Format(L"%d", student->getFather().getPhoneNumber());
	F_PHONE.SetWindowText(tmp);
	tmp.Format(L"%d", student->getFather().getZipCode());
	F_ZIPCODE.SetWindowText(tmp);
	F_GENDER.AddString(L"זכר");
	F_GENDER.SetCurSel(0);
	tmp.Format(L"%d", student->getFather().getDayOfBirth());
	F_DAY.AddString(tmp);
	F_DAY.SetCurSel(0);
	tmp.Format(L"%d", student->getFather().getMonthOfBirth());
	F_MONTH.AddString(tmp);
	F_MONTH.SetCurSel(0);
	tmp.Format(L"%d", student->getFather().getYearOfBirth());
	F_YEAR.AddString(tmp);
	F_YEAR.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void editStudentClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, FIRST_NAME, S_FNAME);
	DDX_Control(pDX, FIRST_NAME2, S_LNAME);
	DDX_Control(pDX, FIRST_NAME4, S_ID);
	DDX_Control(pDX, FIRST_NAME6, S_PHONE);
	DDX_Control(pDX, IDC_COMBO1, S_GENDER);
	DDX_Control(pDX, IDC_COMBO2, S_DAY);
	DDX_Control(pDX, IDC_COMBO3, S_MONTH);
	DDX_Control(pDX, IDC_COMBO4, S_YEAR);
	DDX_Control(pDX, FIRST_NAME3, S_STREET);
	DDX_Control(pDX, FIRST_NAME5, S_CITY);
	DDX_Control(pDX, FIRST_NAME7, S_ZIPCODE);
	DDX_Control(pDX, FIRST_NAME8, M_FNAME);
	DDX_Control(pDX, FIRST_NAME9, M_LNAME);
	DDX_Control(pDX, FIRST_NAME12, M_ID);
	DDX_Control(pDX, FIRST_NAME13, M_PHONE);
	DDX_Control(pDX, IDC_COMBO5, M_GENDER);
	DDX_Control(pDX, IDC_COMBO6, M_DAY);
	DDX_Control(pDX, IDC_COMBO7, M_MONTH);
	DDX_Control(pDX, IDC_COMBO8, M_YEAR);
	DDX_Control(pDX, FIRST_NAME10, M_STREET);
	DDX_Control(pDX, FIRST_NAME11, M_CITY);
	DDX_Control(pDX, FIRST_NAME14, M_ZIPCODE);
	DDX_Control(pDX, FIRST_NAME15, F_FNAME);
	DDX_Control(pDX, FIRST_NAME16, F_LNAME);
	DDX_Control(pDX, FIRST_NAME19, F_ID);
	DDX_Control(pDX, FIRST_NAME20, F_PHONE);
	DDX_Control(pDX, IDC_COMBO9, F_GENDER);
	DDX_Control(pDX, IDC_COMBO10, F_DAY);
	DDX_Control(pDX, IDC_COMBO11, F_MONTH);
	DDX_Control(pDX, IDC_COMBO12, F_YEAR);
	DDX_Control(pDX, FIRST_NAME17, F_STREET);
	DDX_Control(pDX, FIRST_NAME18, F_CITY);
	DDX_Control(pDX, FIRST_NAME21, F_ZIPCODE);
}


BEGIN_MESSAGE_MAP(editStudentClass, CDialogEx)
END_MESSAGE_MAP()


// editStudentClass message handlers
