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
	ON_BN_CLICKED(SAVE_EMP_BTN, &EditEmployeeClass::OnBnClickedEmpBtn)
END_MESSAGE_MAP()


BOOL EditEmployeeClass::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString tmp;
	setFormMode(mode);
	//find employee
	switch (mode)
	{
	case 'T': {


		for (int i = 0; i < Teachers->GetSize(); i++) {
			if (Teachers->GetAt(i)->getID() == id)
			{
				teacher = Teachers->GetAt(i);
				break;
			}
		}
		initValues(teacher, Teachers);
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
		ASSOCIATION_CBOX.AddString(L"הסתדרות המורים");
		ASSOCIATION_CBOX.AddString(L"ארגון המורים");
		int association_num = 1;
		if (teacher->getAssociation() == L"הסתדרות המורים")
			association_num = 0;
		ASSOCIATION_CBOX.SetCurSel(association_num);
		EDUCATION_CBOX.ShowWindow(SW_SHOW);
		EDUCATION_CBOX.AddString(L"תואר ראשון");
		EDUCATION_CBOX.AddString(L"תואר שני");
		EDUCATION_CBOX.AddString(L"דוקטורט");
		EDUCATION_CBOX.AddString(L"פרופסורה");
		int education_num;
		if (teacher->getEducation() == L"תואר ראשון")
			education_num = 0;
		else if (teacher->getEducation() == L"תואר שני")
			education_num = 1;
		else if (teacher->getEducation() == L"דוקטורט")
			education_num = 2;
		else if (teacher->getEducation() == L"פרופסורה")
			education_num = 3;
		EDUCATION_CBOX.SetCurSel(education_num);
		EDUCATOR_CHKBOX.ShowWindow(SW_SHOW);
		EDUCATOR_CHKBOX.SetCheck(teacher->getEducatorStatus());

	}
			break;
	case 'W':
		for (int i = 0; i < Workers->GetSize(); i++) {
			if (Workers->GetAt(i)->getID() == id)
			{
				worker = Workers->GetAt(i);
				break;
			}
		}
		initValues(worker, Workers);
		label = GetDlgItem(EMP_ROLE_TXT);
		label->ShowWindow(SW_SHOW);
		ROLE_TXTBOX.ShowWindow(SW_SHOW);
		ROLE_TXTBOX.SetWindowText(worker->getRole());
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

template<class T>
void EditEmployeeClass::initValues(T* employee, CTypedPtrArray< CObArray, T*>* Employees) {
	CString tmp;
	if (employee->getWorkingStatus()) {
		ISWORKING_CHKBOX.EnableWindow(true);
		ISWORKING_CHKBOX.SetCheck(true);
	}
	else {
		tmp.Format(L"%d", employee->getEndDay());
		EDAY_CBOX.AddString(tmp);
		EDAY_CBOX.SetCurSel(0);
		tmp.Format(L"%d", employee->getEndMonth());
		EMONTH_CBOX.AddString(tmp);
		EMONTH_CBOX.SetCurSel(0);
		tmp.Format(L"%d", employee->getEndYear());
		EYEAR_CBOX.AddString(tmp);
		EYEAR_CBOX.SetCurSel(0);
	}
	PNAME_TXTBOX.SetWindowText(employee->getFName());
	LNAME_TXTBOX.SetWindowText(employee->getLName());
	tmp.Format(L"%d", employee->getID());
	ID_TXTBOX.SetWindowText(tmp);
	GENDER_CBOX.AddString(L"זכר");
	GENDER_CBOX.SetCurSel(0);
	tmp.Format(L"%d", employee->getDayOfBirth());
	BDAY_CBOX.AddString(tmp);
	BDAY_CBOX.SetCurSel(0);
	tmp.Format(L"%d", employee->getMonthOfBirth());
	BMONTH_CBOX.AddString(tmp);
	BMONTH_CBOX.SetCurSel(0);
	tmp.Format(L"%d", employee->getYearOfBirth());
	BYEAR_CBOX.AddString(tmp);
	BYEAR_CBOX.SetCurSel(0);
	STREET_TXTBOX.SetWindowText(employee->getStreet());
	CITY_TXTBOX.SetWindowText(employee->getCity());
	tmp.Format(L"%d", employee->getZipCode());
	ZIPCODE_TXTBOX.SetWindowText(tmp);
	tmp.Format(L"%d", employee->getPhoneNumber());
	PHONE_TXTBOX.SetWindowText(tmp);
	tmp.Format(L"%d", employee->getStartDay());
	SDAY_CBOX.AddString(tmp);
	SDAY_CBOX.SetCurSel(0);
	tmp.Format(L"%d", employee->getStartMonth());
	SMONTH_CBOX.AddString(tmp);
	SMONTH_CBOX.SetCurSel(0);
	tmp.Format(L"%d", employee->getStartYear());
	SYEAR_CBOX.AddString(tmp);
	SYEAR_CBOX.SetCurSel(0);
	tmp.Format(L"%lf", employee->getSallery());
	SALLERY_TXTBOX.SetWindowText(tmp);
	tmp.Format(L"%d", employee->getKids());
	KIDS_TXTBOX.SetWindowText(tmp);
	MARRIGE_CHKBOX.SetCheck(employee->getMarrigeStatus());

}

template<class T>
void EditEmployeeClass::saveEmployee(T* employee, CTypedPtrArray< CObArray, T*>* Employees) {
	int dayOfEnd, monthOfEnd, yearOfEnd, phone, zipCode, kids;
	double sallery;
	bool isWorking, isMarried;
	CString tmp, fName, lName, street, city;

	PNAME_TXTBOX.GetWindowText(fName);
	LNAME_TXTBOX.GetWindowText(lName);
	STREET_TXTBOX.GetWindowText(street);
	CITY_TXTBOX.GetWindowText(city);
	EDAY_CBOX.GetWindowText(tmp);
	dayOfEnd = _ttoi(tmp);
	EMONTH_CBOX.GetWindowText(tmp);
	monthOfEnd = _ttoi(tmp);
	EYEAR_CBOX.GetWindowText(tmp);
	yearOfEnd = _ttoi(tmp);
	PHONE_TXTBOX.GetWindowText(tmp);
	phone = _ttoi(tmp);
	ZIPCODE_TXTBOX.GetWindowText(tmp);
	zipCode = _ttoi(tmp);
	KIDS_TXTBOX.GetWindowText(tmp);
	kids = _ttoi(tmp);
	SALLERY_TXTBOX.GetWindowText(tmp);
	sallery = _ttoi(tmp);
	isWorking = ISWORKING_CHKBOX.GetCheck();
	isMarried = MARRIGE_CHKBOX.GetCheck();
	employee->setFirstName(fName);
	employee->setLastName(lName);
	employee->setStreet(street);
	employee->setCity(city);
	employee->setPhoneNumber(phone);
	employee->setZipCode(zipCode);
	employee->setDateOfEnding(dayOfEnd, monthOfEnd, yearOfEnd);
	employee->setKids(kids);
	employee->setSallery(sallery);
	employee->setMarrigeStatus(isMarried);
	employee->setWorkingStatus(isWorking);

}

//SAVE BUTTON

void EditEmployeeClass::OnBnClickedEmpBtn()
{
	switch (mode)
	{
	case 'T': {
		saveEmployee(teacher, Teachers);
	}
	break;
	case 'W': {
		saveEmployee(worker, Workers);

	}
	break;
	default:
		break;
	}
	MessageBox(L"איש הצוות נשמר בהצלחה!");
	EndDialog(0);
}
