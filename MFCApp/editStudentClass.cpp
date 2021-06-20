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
	label = GetDlgItem(LATES_COUNT);
	tmp.Format(L"%d", student->getLate());
	label->SetWindowText(tmp);
	label = GetDlgItem(MISSING_COUNT);
	tmp.Format(L"%d", student->getMissing());
	label->SetWindowText(tmp);
	

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
	ON_BN_CLICKED(IDC_BUTTON3, &editStudentClass::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &editStudentClass::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &editStudentClass::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &editStudentClass::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON1, &editStudentClass::OnBnClickedButton1)
END_MESSAGE_MAP()


// editStudentClass message handlers

//ADD ONE LATE
void editStudentClass::OnBnClickedButton3()
{
	label = GetDlgItem(LATES_COUNT);
	tmp.Format(L"%d", student->addLate());
	label->SetWindowText(tmp);
}


//REMOVE ONE LATE
void editStudentClass::OnBnClickedButton4()
{
	if (!(student->getLate())) {
		MessageBox(L"מספר האיחורים אינו יכול להיות שלילי.");
			return ;
	}
	label = GetDlgItem(LATES_COUNT);
	tmp.Format(L"%d", student->removeLate());
	label->SetWindowText(tmp);
}

//ADD ONE MISS
void editStudentClass::OnBnClickedButton8()
{
	label = GetDlgItem(MISSING_COUNT);
	tmp.Format(L"%d", student->addMissingDay());
	label->SetWindowText(tmp);
}

//REMOVE ONE MISS
void editStudentClass::OnBnClickedButton9()
{
	if (!(student->getMissing())) {
		MessageBox(L"מספר החיסורים אינו יכול להיות שלילי.");
		return;
	}
	label = GetDlgItem(MISSING_COUNT);
	tmp.Format(L"%d", student->removeMissingDay());
	label->SetWindowText(tmp);
}

//SAVE BUTTON
void editStudentClass::OnBnClickedButton1()
{
	/* STUDENT VALUES */
	S_FNAME.GetWindowText(tmp);
	student->setFirstName(tmp);
	S_LNAME.GetWindowText(tmp);
	student->setLastName(tmp);
	S_STREET.GetWindowText(tmp);
	student->setStreet(tmp);
	S_CITY.GetWindowText(tmp);
	student->setCity(tmp);
	S_PHONE.GetWindowText(tmp);
	student->setPhoneNumber(_ttoi(tmp));
	S_ZIPCODE.GetWindowText(tmp);
	student->setZipCode(_ttoi(tmp));

	/* MOTHER VALUES */
	M_FNAME.GetWindowText(tmp);
	student->getMother().setFirstName(tmp);
	M_LNAME.GetWindowText(tmp);
	student->getMother().setLastName(tmp);
	M_STREET.GetWindowText(tmp);
	student->getMother().setStreet(tmp);
	M_CITY.GetWindowText(tmp);
	student->getMother().setCity(tmp);
	M_PHONE.GetWindowText(tmp);
	student->getMother().setPhoneNumber(_ttoi(tmp));
	M_ZIPCODE.GetWindowText(tmp);
	student->getMother().setZipCode(_ttoi(tmp));

	/* FATHER VALUES */
	F_FNAME.GetWindowText(tmp);
	student->getFather().setFirstName(tmp);
	F_LNAME.GetWindowText(tmp);
	student->getFather().setLastName(tmp);
	F_STREET.GetWindowText(tmp);
	student->getFather().setStreet(tmp);
	F_CITY.GetWindowText(tmp);
	student->getFather().setCity(tmp);
	F_PHONE.GetWindowText(tmp);
	student->getFather().setPhoneNumber(_ttoi(tmp));
	F_ZIPCODE.GetWindowText(tmp);
	student->getFather().setZipCode(_ttoi(tmp));

	MessageBox(L"התלמיד עודכן בהצלחה!");
	updateList();
	EndDialog(0);

}

void editStudentClass::updateList() {
	sList->DeleteAllItems();
	int nItem;

	for (int i = 0; i < students->GetSize(); i++) {
		Student* stdnt = students->GetAt(i);
		CString tmp;
		tmp.Format(_T("%d"), stdnt->getID());
		nItem = sList->InsertItem(0, tmp);
		sList->SetItemText(nItem, 1, stdnt->getFName());
		sList->SetItemText(nItem, 2, stdnt->getLName());
		sList->SetItemText(nItem, 3, stdnt->getBirthDay());
		sList->SetItemText(nItem, 4, stdnt->getAddress());

	}
}