#pragma once
#include "Student.h"
#include "AllStudentsClass.h"
#include "AddStudentClass.h"

// StudentDlgClass dialog
class StudentDlgClass : public CDialogEx
{
	DECLARE_DYNAMIC(StudentDlgClass)

public:
	StudentDlgClass(CWnd* pParent = nullptr);   // standard constructor
	CTypedPtrArray< CObArray, Student*> *students;
	virtual ~StudentDlgClass();
	AllStudentsClass allStudentDlg;
	AddStudentClass addStudentDlg;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Students_Dlg };
#endif

protected:
	int current_id;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedListBtn();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();

	CButton DELETE_BTN;
};
