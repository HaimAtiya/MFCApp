// StudentDlgClass.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "StudentDlgClass.h"
#include "afxdialogex.h"
#include "MFCAppDlg.h"

// StudentDlgClass dialog

IMPLEMENT_DYNAMIC(StudentDlgClass, CDialogEx)
StudentDlgClass::StudentDlgClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Students_Dlg, pParent)
{
}

StudentDlgClass::~StudentDlgClass()
{

}

BOOL StudentDlgClass::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	StudentDlgClass::current_id = NULL;
	allStudentDlg.students = students;
	allStudentDlg.curr_id = &current_id;
	allStudentDlg.DELETE_BTN = &DELETE_BTN;
	allStudentDlg.Create(ALL_STUDENTS, this);
	addStudentDlg.Create(ADD_STUDENT, this);
	allStudentDlg.ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void StudentDlgClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON5, DELETE_BTN);
}


BEGIN_MESSAGE_MAP(StudentDlgClass, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &StudentDlgClass::OnBnClickedButton2)
	ON_BN_CLICKED(STUDENTS_LIST_BTN, &StudentDlgClass::OnBnClickedListBtn)
	ON_BN_CLICKED(IDC_BUTTON7, &StudentDlgClass::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON6, &StudentDlgClass::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &StudentDlgClass::OnBnClickedButton5)
END_MESSAGE_MAP()


// StudentDlgClass message handlers

//ALL STUDET LIST BTN
void StudentDlgClass::OnBnClickedListBtn()
{


	addStudentDlg.ShowWindow(SW_HIDE);
	allStudentDlg.ShowWindow(SW_SHOW);

}
//ADD NEW STUDENT
void StudentDlgClass::OnBnClickedButton2()
{
	Person student, mother, father;
	HANDLE t1;
	DWORD t1ID;
	allStudentDlg.ShowWindow(SW_HIDE);
	addStudentDlg.setFormTitle(L"פרטי התלמיד");
	addStudentDlg.pers = &student;
	addStudentDlg.RunModalLoop(SW_SHOW);
	addStudentDlg.setFormTitle(L"פרטי האמא");
	addStudentDlg.pers = &mother;
	addStudentDlg.RunModalLoop(SW_SHOW);
	addStudentDlg.setFormTitle(L"פרטי האבא");
	addStudentDlg.pers = &father;
	addStudentDlg.RunModalLoop(SW_SHOW);
	Student* s = new Student(mother, father);
	s->setStudentDetails(student);
	students->Add(s);
	MessageBox(L"התלמיד נוסף בהצלחה!");
	allStudentDlg.updateList();
	allStudentDlg.ShowWindow(SW_SHOW);
}

//DELTE STUDENT
void StudentDlgClass::OnBnClickedButton5()
{
	Student* stdnt;
	//fint student index in array
	for (int i = 0; i < students->GetSize(); i++) {
		if (students->GetAt(i)->getID() == current_id)
		{
			stdnt = students->GetAt(i);
			CString confirm_txt;
			confirm_txt.Format(L"האם אתה בטוח שברצונך למחוק את התלמיד %s?", stdnt->getFullName());
			const int result = MessageBox(confirm_txt, L"מחיקת תלמיד", MB_YESNO);
			if (result == IDYES) {
				MessageBox(L"התלמיד נמחק בהצלחה!");
				students->RemoveAt(i);
				//Update list
				allStudentDlg.updateList();
			}
			return;
		}
	}
}





//Save
void StudentDlgClass::OnBnClickedButton7()
{
	CFileDialog dlg(FALSE, _T(".students"), NULL, 0, _T("Students (*.students)|*.students|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		students->Serialize(ar);
		ar.Close();
		file.Close();
		MessageBox(L"רשימת התלמידים נשמרה בהצלחה!");
	}
}


//Open
void StudentDlgClass::OnBnClickedButton6()
{
	CFileDialog dlg(TRUE, _T(".students"), NULL, 0, _T("Students (*.students)|*.students|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		students->Serialize(ar);
		ar.Close();
		file.Close();
		MessageBox(L"רשימת התלמידים נטענה בהצלחה!");

		//Update list
		allStudentDlg.updateList();
	}
}

