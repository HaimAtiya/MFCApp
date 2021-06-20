#pragma once
#include "Person.h"
// AddStudentClass dialog

class AddStudentClass : public CDialogEx
{
	DECLARE_DYNAMIC(AddStudentClass)

public:
	AddStudentClass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddStudentClass();
	void setFormTitle(CString title);
	bool *complete;
	Person *pers;
	void resetControls();
	bool isAddDlgInAction;
	bool forceClose;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ADD_STUDENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox gender_control;
	CComboBox DAY_TXTBOX;
	CComboBox MONTH_TXTBOX;
	CComboBox YEAR_TXTBOX;
	CEdit PNAME_TXTBOX;
	CEdit LNAME_TXTBOX;
	CEdit ID_TXTBOX;
	CEdit PHONE_TXTBOX;
	CEdit STREET_TXTBOX;
	CEdit CITY_TXTBOX;
	afx_msg void OnEnChangeName7();
	CEdit ZIPCODE_TXTBOX;
	afx_msg void OnBnClickedButton1();
};
