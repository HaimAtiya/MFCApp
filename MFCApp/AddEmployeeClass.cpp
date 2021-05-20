// AddEmployeeClass.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "AddEmployeeClass.h"
#include "afxdialogex.h"


// AddEmployeeClass dialog

IMPLEMENT_DYNAMIC(AddEmployeeClass, CDialogEx)

AddEmployeeClass::AddEmployeeClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ADD_EMPLOYEE, pParent)
{

}

AddEmployeeClass::~AddEmployeeClass()
{
}

BOOL AddEmployeeClass::OnInitDialog()
{
	CString num;
	CDialogEx::OnInitDialog();


	gender_control.AddString(L"זכר");
	gender_control.AddString(L"נקבה");
	gender_control.SetCurSel(0);
	//INIT DAYS
	for (int i = 1; i <= 31; i++) {
		num.Format(L"%d", i);
		BDAY_CBOX.AddString(num);
		SDAY_CBOX.AddString(num);
	}
	BDAY_CBOX.SetCurSel(0);
	SDAY_CBOX.SetCurSel(0);
	//INIT MONTH
	for (int i = 1; i <= 12; i++) {
		num.Format(L"%d", i);
		BMONTH_CBOX.AddString(num);
		SMONTH_CBOX.AddString(num);
	}
	BMONTH_CBOX.SetCurSel(0);
	SMONTH_CBOX.SetCurSel(0);
	//INIT YEAR
	for (int i = 1900; i <= 2021; i++) {
		num.Format(L"%d", i);
		BYEAR_CBOX.AddString(num);
		SYEAR_CBOX.AddString(num);

	}
	BYEAR_CBOX.SetCurSel(0);
	SYEAR_CBOX.SetCurSel(0);
	EDUCATION_CBOX.AddString(L"תואר ראשון");
	EDUCATION_CBOX.AddString(L"תואר שני");
	EDUCATION_CBOX.AddString(L"דוקטורט");
	EDUCATION_CBOX.AddString(L"פרופסורה");
	EDUCATION_CBOX.SetCurSel(0);
	ASSOCIATION_CBOX.AddString(L"הסתדרות המורים");
	ASSOCIATION_CBOX.AddString(L"ארגון המורים");
	ASSOCIATION_CBOX.SetCurSel(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void AddEmployeeClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ADD_EMPLOYEE_HEADER, header_title);
	DDX_Control(pDX, EMP_GENDER_CBOX, gender_control);
	DDX_Control(pDX, EMP_BDAY_CBOX, BDAY_CBOX);
	DDX_Control(pDX, EMP_BMONTH_CBOX, BMONTH_CBOX);
	DDX_Control(pDX, EMP_BYEAR_CBOX, BYEAR_CBOX);
	DDX_Control(pDX, EMP_SDAY_CBOX, SDAY_CBOX);
	DDX_Control(pDX, EMP_SMONTH_CBOX, SMONTH_CBOX);
	DDX_Control(pDX, EMP_SYEAR_CBOX, SYEAR_CBOX);
	DDX_Control(pDX, EMP_EDUCATION_CBOX, EDUCATION_CBOX);
	DDX_Control(pDX, EMP_ASSOCIATION_CBOX, ASSOCIATION_CBOX);
}


BEGIN_MESSAGE_MAP(AddEmployeeClass, CDialogEx)
	ON_STN_CLICKED(ADD_EMPLOYEE_HEADER, &AddEmployeeClass::OnStnClickedEmployeeHeader)
	ON_BN_CLICKED(ADD_EMPLOYEE_BTN, &AddEmployeeClass::OnBnClickedEmployeeBtn)
END_MESSAGE_MAP()


// AddEmployeeClass message handlers


void AddEmployeeClass::OnStnClickedEmployeeHeader()
{
	// TODO: Add your control notification handler code here
}

void AddEmployeeClass::setFormTitle(CString title) {
	label = GetDlgItem(ADD_EMPLOYEE_HEADER);
	label->SetWindowText(title);
}
void AddEmployeeClass::setFormMode(char mode) {
	this->mode = mode;
	switch (mode)
	{
	case 'T':
		setFormTitle(L"הוספת מורה חדש");
		GetDlgItem(EMP_ROLE_TXT)->ShowWindow(SW_HIDE);
		GetDlgItem(EMP_ROLE_TXTBOX)->ShowWindow(SW_HIDE);
		GetDlgItem(EMP_PROFFESSION_TXT)->ShowWindow(SW_SHOW);
		GetDlgItem(EMP_PROFFESSION_TXTBOX)->ShowWindow(SW_SHOW);
		GetDlgItem(EMP_EDUCATION_TXT)->ShowWindow(SW_SHOW);
		GetDlgItem(EMP_EDUCATION_CBOX)->ShowWindow(SW_SHOW);
		GetDlgItem(EMP_EDUCATOR_CHKBOX)->ShowWindow(SW_SHOW);
		GetDlgItem(EMP_ASSOCIATION_TXT)->ShowWindow(SW_SHOW);
		GetDlgItem(EMP_ASSOCIATION_CBOX)->ShowWindow(SW_SHOW);
		break;
	case 'W':
		setFormTitle(L"הוספת עובד חדש");
		GetDlgItem(EMP_PROFFESSION_TXT)->ShowWindow(SW_HIDE);
		GetDlgItem(EMP_PROFFESSION_TXTBOX)->ShowWindow(SW_HIDE);
		GetDlgItem(EMP_EDUCATION_TXT)->ShowWindow(SW_HIDE);
		GetDlgItem(EMP_EDUCATION_CBOX)->ShowWindow(SW_HIDE);
		GetDlgItem(EMP_EDUCATOR_CHKBOX)->ShowWindow(SW_HIDE);
		GetDlgItem(EMP_ASSOCIATION_TXT)->ShowWindow(SW_HIDE);
		GetDlgItem(EMP_ASSOCIATION_CBOX)->ShowWindow(SW_HIDE);
		GetDlgItem(EMP_ROLE_TXT)->ShowWindow(SW_SHOW);
		GetDlgItem(EMP_ROLE_TXTBOX)->ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}
}

//ADD NEW EMPLOYEE
void AddEmployeeClass::OnBnClickedEmployeeBtn()
{
	int id, dayOfBirth, monthOfBirth, yearOfBirth, dayOfStart, monthOfStart, yearOfStart, phone, zipCode, kids;
	double sallery;
	bool isWorking, isMarried, isEducator;
	CString tmp, fName, lName, street, city, role, proffession, education, association;
	Sex gender;
}
