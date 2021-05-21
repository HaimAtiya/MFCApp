// EditEmployeeClass.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "EditEmployeeClass.h"
#include "afxdialogex.h"


// EditEmployeeClass dialog

IMPLEMENT_DYNAMIC(EditEmployeeClass, CDialogEx)

EditEmployeeClass::EditEmployeeClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(EDIT_EMPLOYEE, pParent)
{

}

EditEmployeeClass::~EditEmployeeClass()
{
}
BEGIN_MESSAGE_MAP(EditEmployeeClass, CDialogEx)
	ON_CBN_SELCHANGE(EMP_SMONTH_CBOX, &EditEmployeeClass::OnCbnSelchangeSmonthCbox)
	ON_BN_CLICKED(EMP_EDUCATOR_CHKBOX, &EditEmployeeClass::OnBnClickedEducatorChkbox)
	ON_BN_CLICKED(EMP_ISWORKING_CHKBOX, &EditEmployeeClass::OnBnClickedIsworkingChkbox)
END_MESSAGE_MAP()


BOOL EditEmployeeClass::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	setFormMode(mode);
	//find employee
	switch (mode)
	{
	case 'T':
		for (int i = 0; i < Teachers->GetSize(); i++) {
			if (Teachers->GetAt(i)->getID() == id)
			{
				teacher = Teachers->GetAt(i);
				if (teacher->getWorkingStatus()) {
					ISWORKING_CHKBOX.EnableWindow(true);
					ISWORKING_CHKBOX.SetCheck(true);
				}
				break;
			}
		}
		break;
	case 'W':
		for (int i = 0; i < Workers->GetSize(); i++) {
			if (Workers->GetAt(i)->getID() == id)
			{
				worker = Workers->GetAt(i);
				if (worker->getWorkingStatus()) {
					ISWORKING_CHKBOX.EnableWindow(true);
					ISWORKING_CHKBOX.SetCheck(true);
				}
				break;
			}
		}
		break;
	default:
		break;
	}
		
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void EditEmployeeClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, EMP_ISWORKING_CHKBOX, ISWORKING_CHKBOX);
	DDX_Control(pDX, EMP_EDAY_CBOX, EDAY_CBOX);
	DDX_Control(pDX, EMP_EMONTH_CBOX, EMONTH_CBOX);
	DDX_Control(pDX, EMP_EYEAR_CBOX, EYEAR_CBOX);
	DDX_Control(pDX, EMP_PNAME_TXTBOX, PNAME_TXTBOX);
	DDX_Control(pDX, EMP_LNAME_TXTBOX, ENAME_TXTBOX);
	DDX_Control(pDX, EMP_ID_TXTBOX, ID_TXTBOX);
	DDX_Control(pDX, EMP_GENDER_CBOX, GENDER_CBOX);
	DDX_Control(pDX, EMP_BDAY_CBOX, BDAY_CBOX);
	DDX_Control(pDX, EMP_BMONTH_CBOX, BMONTH_CBOX);
	DDX_Control(pDX, EMP_BYEAR_CBOX, BYEAR_CBOX);
	DDX_Control(pDX, EMP_STREET_TXTBOX, STREET_TXTBOX);
	DDX_Control(pDX, EMP_CITY_TXTBOX, CITY_TXTBOX);
	DDX_Control(pDX, EMP_ZIPCODE_TXTBOX, ZIPCODE_TXTBOX);
	DDX_Control(pDX, EMP_PHONE_TXTBOX, PHONE_TXTBOX);
	DDX_Control(pDX, EMP_SDAY_CBOX, SDAY_CBOX);
	DDX_Control(pDX, EMP_SMONTH_CBOX, SMONTH_CBOX);
	DDX_Control(pDX, EMP_SYEAR_CBOX, SYEAR_CBOX);
	DDX_Control(pDX, EMP_SALLERY_TXTBOX, SALLERY_TXTBOX);
	DDX_Control(pDX, EMP_KIDS_TXTBOX, KIDS_TXTBOX);
	DDX_Control(pDX, EMP_ROLE_TXTBOX, ROLE_TXTBOX);
	DDX_Control(pDX, EMP_MARRIGE_CHKBOX, MARRIGE_CHKBOX);
	DDX_Control(pDX, EMP_PROFFESSION_TXTBOX, PROGFFESSION_TXTBOX);
	DDX_Control(pDX, EMP_ASSOCIATION_CBOX, ASSOCIATION_CBOX);
	DDX_Control(pDX, EMP_EDUCATION_CBOX, EDUCATION_CBOX);
	DDX_Control(pDX, EMP_EDUCATOR_CHKBOX, EDUCATOR_CHKBOX);
}

void EditEmployeeClass::setFormTitle(CString title) {
	label = GetDlgItem(EDIT_EMPLOYEE_HEADER);
	label->SetWindowText(title);
}
void EditEmployeeClass::setFormMode(char mode) {
	this->mode = mode;
	switch (mode)
	{
	case 'T':
		setFormTitle(L"פרטי המורה");
		break;
	case 'W':
		setFormTitle(L"פרטי העובד");
		break;
	default:
		break;
	}
}



// EditEmployeeClass message handlers


void EditEmployeeClass::OnCbnSelchangeSmonthCbox()
{
	// TODO: Add your control notification handler code here
}


void EditEmployeeClass::OnBnClickedEducatorChkbox()
{
	// TODO: Add your control notification handler code here
}


void EditEmployeeClass::OnBnClickedIsworkingChkbox()
{
	if (!ISWORKING_CHKBOX.GetCheck()) {
		ISWORKING_CHKBOX.EnableWindow(false);
		EDAY_CBOX.EnableWindow(true);
		EMONTH_CBOX.EnableWindow(true);
		EYEAR_CBOX.EnableWindow(true);
		CString num;
		//INIT DAYS
		for (int i = 1; i <= 31; i++) {
			num.Format(L"%d", i);
			EDAY_CBOX.AddString(num);
		}
		EDAY_CBOX.SetCurSel(0);
		//INIT MONTH
		for (int i = 1; i <= 12; i++) {
			num.Format(L"%d", i);
			EMONTH_CBOX.AddString(num);
		}
		EMONTH_CBOX.SetCurSel(0);
		//INIT YEAR
		for (int i = 1900; i <= 2021; i++) {
			num.Format(L"%d", i);
			EYEAR_CBOX.AddString(num);
		}
		EYEAR_CBOX.SetCurSel(0);
	}
}
