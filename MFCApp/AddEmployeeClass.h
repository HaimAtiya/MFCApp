#pragma once
#include "enums.h"

// AddEmployeeClass dialog

class AddEmployeeClass : public CDialogEx
{
	DECLARE_DYNAMIC(AddEmployeeClass)

public:
	AddEmployeeClass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddEmployeeClass();
	void setFormMode(char mode);// 'T' - Teacher, 'W' - Worker
	void setFormTitle(CString title);
	CWnd* label;
	char mode;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ADD_EMPLOYEE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CStatic header_title;
	afx_msg void OnStnClickedEmployeeHeader();
	afx_msg void OnBnClickedEmployeeBtn();
	CComboBox gender_control;
	CComboBox BDAY_CBOX;
	CComboBox BMONTH_CBOX;
	CComboBox BYEAR_CBOX;
	CComboBox SDAY_CBOX;
	CComboBox SMONTH_CBOX;
	CComboBox SYEAR_CBOX;
	CComboBox EDUCATION_CBOX;
	CComboBox ASSOCIATION_CBOX;
	CEdit PNAME_TXTBOX;
	CEdit LNAME_TXTBOX;
	CEdit ID_TXTBOX;
	CEdit STREET_TXTBOX;
	CEdit PHONE_TXTBOX;
	CEdit CITY_TXTBOX;
	CEdit ZIPCODE_TXTBOX;
	CEdit SALLERY_TXTBOX;
	CButton MARRIGE_CHKBOX;
	CEdit KIDS_TXTBOX;
	CButton ISWORKING_CHKBOX;
	CEdit ROLE_TXTBOX;
	CEdit PROFFESSION_TXTBOX;
	CButton EDUCATOR_CHKBOX;
};
