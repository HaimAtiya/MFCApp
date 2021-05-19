#pragma once
#include "Student.h"
// editStudentClass dialog

class editStudentClass : public CDialogEx
{
	DECLARE_DYNAMIC(editStudentClass)

public:
	editStudentClass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~editStudentClass();
	int id;
	CTypedPtrArray< CObArray, Student*>* students;
	Student *student;
	CWnd* label;
	CString tmp;
	CListCtrl *sList;
	void updateList();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = EDIT_STUDENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();


	DECLARE_MESSAGE_MAP()
public:
	CEdit S_FNAME;
	CEdit S_LNAME;
	CEdit S_ID;
	CEdit S_PHONE;
	CComboBox S_GENDER;
	CComboBox S_DAY;
	CComboBox S_MONTH;
	CComboBox S_YEAR;
	CEdit S_STREET;
	CEdit S_CITY;
	CEdit S_ZIPCODE;
	CEdit M_FNAME;
	CEdit M_LNAME;
	CEdit M_ID;
	CEdit M_PHONE;
	CComboBox M_GENDER;
	CComboBox M_DAY;
	CComboBox M_MONTH;
	CComboBox M_YEAR;
	CEdit M_STREET;
	CEdit M_CITY;
	CEdit M_ZIPCODE;
	CEdit F_FNAME;
	CEdit F_LNAME;
	CEdit F_ID;
	CEdit F_PHONE;
	CComboBox F_GENDER;
	CComboBox F_DAY;
	CComboBox F_MONTH;
	CComboBox F_YEAR;
	CEdit F_STREET;
	CEdit F_CITY;
	CEdit F_ZIPCODE;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton1();
};

