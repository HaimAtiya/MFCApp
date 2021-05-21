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

BOOL AddStudentClass::OnInitDialog()
{
	CString num;
	CDialogEx::OnInitDialog();


	gender_control.AddString(L"זכר");
	gender_control.AddString(L"נקבה");
	gender_control.SetCurSel(0);
	//INIT DAYS
	for (int i = 1; i <= 31; i++) {
		num.Format(L"%d", i);
		DAY_TXTBOX.AddString(num);
	}
	DAY_TXTBOX.SetCurSel(0);
	//INIT MONTH
	for (int i = 1; i <= 12; i++) {
		num.Format(L"%d", i);
		MONTH_TXTBOX.AddString(num);
	}
	MONTH_TXTBOX.SetCurSel(0);
	//INIT YEAR
	for (int i = 1900; i <= 2021; i++) {
		num.Format(L"%d", i);
		YEAR_TXTBOX.AddString(num);
	}
	YEAR_TXTBOX.SetCurSel(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void AddStudentClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, gender_control);
	DDX_Control(pDX, IDC_COMBO2, DAY_TXTBOX);
	DDX_Control(pDX, IDC_COMBO3, MONTH_TXTBOX);
	DDX_Control(pDX, IDC_COMBO4, YEAR_TXTBOX);
	DDX_Control(pDX, FIRST_NAME, PNAME_TXTBOX);
	DDX_Control(pDX, FIRST_NAME2, LNAME_TXTBOX);
	DDX_Control(pDX, FIRST_NAME4, ID_TXTBOX);
	DDX_Control(pDX, FIRST_NAME6, PHONE_TXTBOX);
	DDX_Control(pDX, FIRST_NAME3, STREET_TXTBOX);
	DDX_Control(pDX, FIRST_NAME5, CITY_TXTBOX);
	DDX_Control(pDX, FIRST_NAME7, ZIPCODE_TXTBOX);
}


BEGIN_MESSAGE_MAP(AddStudentClass, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &AddStudentClass::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(FIRST_NAME7, &AddStudentClass::OnEnChangeName7)
	ON_BN_CLICKED(IDC_BUTTON1, &AddStudentClass::OnBnClickedButton1)
END_MESSAGE_MAP()


// AddStudentClass message handlers

void AddStudentClass::setFormTitle(CString title)
{
	CWnd* label = GetDlgItem(ADD_STDNT_HEADER);
	label->SetWindowText(title);
}

void AddStudentClass::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void AddStudentClass::OnEnChangeName7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void AddStudentClass::OnBnClickedButton1()
{
	int id, dayOfBirth, monthOfBirth, yearOfBirth, phone, zipCode;
	CString tmp, fName, lName, street, city;
	Sex gender;
	PNAME_TXTBOX.GetWindowText(fName);
	LNAME_TXTBOX.GetWindowText(lName);
	STREET_TXTBOX.GetWindowText(street);
	CITY_TXTBOX.GetWindowText(city);
	ID_TXTBOX.GetWindowText(tmp);
	id = _ttoi(tmp);
	DAY_TXTBOX.GetWindowText(tmp);
	dayOfBirth = _ttoi(tmp);
	MONTH_TXTBOX.GetWindowText(tmp);
	monthOfBirth = _ttoi(tmp);
	YEAR_TXTBOX.GetWindowText(tmp);
	yearOfBirth = _ttoi(tmp);
	PHONE_TXTBOX.GetWindowText(tmp);
	phone = _ttoi(tmp);
	ZIPCODE_TXTBOX.GetWindowText(tmp);
	zipCode = _ttoi(tmp);
	gender_control.GetWindowText(tmp);
	gender = (tmp == "זכר") ? Male : Female;
	*pers = *(new Person(id, fName, lName, gender, dayOfBirth, monthOfBirth, yearOfBirth, street, city, zipCode, phone));
	EndDialog(0);
	resetControls();
}

void AddStudentClass::resetControls() {
	gender_control.SetCurSel(0);
	DAY_TXTBOX.SetCurSel(0);
	MONTH_TXTBOX.SetCurSel(0);
	YEAR_TXTBOX.SetCurSel(0);
	PNAME_TXTBOX.SetWindowText(L"");
	LNAME_TXTBOX.SetWindowText(L"");
	ID_TXTBOX.SetWindowText(L"");
	PHONE_TXTBOX.SetWindowText(L"");
	STREET_TXTBOX.SetWindowText(L"");
	CITY_TXTBOX.SetWindowText(L"");
	ZIPCODE_TXTBOX.SetWindowText(L"");
}