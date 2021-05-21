#pragma once
#include "Teacher.h"
#include "Worker.h"

// EditEmployeeClass dialog

class EditEmployeeClass : public CDialogEx
{
	DECLARE_DYNAMIC(EditEmployeeClass)

public:
	EditEmployeeClass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~EditEmployeeClass();
	CTypedPtrArray< CObArray, Teacher*>* Teachers;
	CTypedPtrArray< CObArray, Worker*>* Workers;
	CListCtrl* eList;
	int id;
	char mode;
	CWnd* label;
	void setFormMode(char mode);// 'T' - Teacher, 'W' - Worker
	void setFormTitle(CString title);
	Teacher *teacher;
	Worker *worker;
	template<class T>
	void initValues(T employee);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = EDIT_EMPLOYEE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeSmonthCbox();
	afx_msg void OnBnClickedEducatorChkbox();
	afx_msg void OnBnClickedIsworkingChkbox();
	CButton ISWORKING_CHKBOX;
	CComboBox EDAY_CBOX;
	CComboBox EMONTH_CBOX;
	CComboBox EYEAR_CBOX;
	CEdit PNAME_TXTBOX;
	CEdit LNAME_TXTBOX;
	CEdit ID_TXTBOX;
	CComboBox GENDER_CBOX;
	CComboBox BDAY_CBOX;
	CComboBox BMONTH_CBOX;
	CComboBox BYEAR_CBOX;
	CEdit STREET_TXTBOX;
	CEdit CITY_TXTBOX;
	CEdit ZIPCODE_TXTBOX;
	CEdit PHONE_TXTBOX;
	CComboBox SDAY_CBOX;
	CComboBox SMONTH_CBOX;
	CComboBox SYEAR_CBOX;
	CEdit SALLERY_TXTBOX;
	CEdit KIDS_TXTBOX;
	CEdit ROLE_TXTBOX;
	CButton MARRIGE_CHKBOX;
	CEdit PROFFESSION_TXTBOX;
	CComboBox ASSOCIATION_CBOX;
	CComboBox EDUCATION_CBOX;
	CButton EDUCATOR_CHKBOX;
};
