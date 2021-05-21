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
	CString tmp;
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
				else {
					tmp.Format(L"%d", teacher->getEndDay());
					EDAY_CBOX.AddString(tmp);
					EDAY_CBOX.SetCurSel(0);
					tmp.Format(L"%d", teacher->getEndMonth());
					EMONTH_CBOX.AddString(tmp);
					EMONTH_CBOX.SetCurSel(0);
					tmp.Format(L"%d", teacher->getEndYear());
					EYEAR_CBOX.AddString(tmp);
					EYEAR_CBOX.SetCurSel(0);
				}
					PNAME_TXTBOX.SetWindowText(teacher->getFName());
					LNAME_TXTBOX.SetWindowText(teacher->getLName());
					tmp.Format(L"%d", teacher->getID());
					ID_TXTBOX.SetWindowText(tmp);
					GENDER_CBOX.AddString(L"זכר");
					GENDER_CBOX.SetCurSel(0);
					tmp.Format(L"%d", teacher->getDayOfBirth());
					BDAY_CBOX.AddString(tmp);
					BDAY_CBOX.SetCurSel(0);
					tmp.Format(L"%d", teacher->getMonthOfBirth());
					BMONTH_CBOX.AddString(tmp);
					BMONTH_CBOX.SetCurSel(0);
					tmp.Format(L"%d", teacher->getYearOfBirth());
					BYEAR_CBOX.AddString(tmp);
					BYEAR_CBOX.SetCurSel(0);
					STREET_TXTBOX.SetWindowText(teacher->getStreet());
					CITY_TXTBOX.SetWindowText(teacher->getCity());
					tmp.Format(L"%d", teacher->getZipCode());
					ZIPCODE_TXTBOX.SetWindowText(tmp);
					tmp.Format(L"%d", teacher->getPhoneNumber());
					PHONE_TXTBOX.SetWindowText(tmp);
					tmp.Format(L"%d", teacher->getStartDay());
					SDAY_CBOX.AddString(tmp);
					SDAY_CBOX.SetCurSel(0);
					tmp.Format(L"%d", teacher->getStartMonth());
					SMONTH_CBOX.AddString(tmp);
					SMONTH_CBOX.SetCurSel(0);
					tmp.Format(L"%d", teacher->getStartYear());
					SYEAR_CBOX.AddString(tmp);
					SYEAR_CBOX.SetCurSel(0);
					tmp.Format(L"%lf", teacher->getSallery());
					SALLERY_TXTBOX.SetWindowText(tmp);
					tmp.Format(L"%d", teacher->getKids());
					KIDS_TXTBOX.SetWindowText(tmp);
					MARRIGE_CHKBOX.SetCheck(teacher->getMarrigeStatus());
					label = GetDlgItem(TCHR_PDAGOGI_TEXT);
					label->ShowWindow(SW_SHOW);
					label = GetDlgItem(EMP_PROFFESSION_TXT);
					label->ShowWindow(SW_SHOW);
					PROFFESSION_TXTBOX.ShowWindow(SW_SHOW);
					PROFFESSION_TXTBOX.SetWindowText(teacher->getProffesion());
					label = GetDlgItem(EMP_ASSOCIATION_TXT);
					label->ShowWindow(SW_SHOW);
					ASSOCIATION_CBOX.ShowWindow(SW_SHOW);
					label = GetDlgItem(EMP_EDUCATION_TXT);
					label->ShowWindow(SW_SHOW);
					EDUCATION_CBOX.ShowWindow(SW_SHOW);
					EDUCATOR_CHKBOX.ShowWindow(SW_SHOW);

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
	DDX_Control(pDX, EMP_LNAME_TXTBOX, LNAME_TXTBOX);
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
	DDX_Control(pDX, EMP_PROFFESSION_TXTBOX, PROFFESSION_TXTBOX);
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
