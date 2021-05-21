#pragma once
#include "Teacher.h"
#include "Worker.h"

// EmployeeListClass dialog

class EmployeeListClass : public CDialogEx
{
	DECLARE_DYNAMIC(EmployeeListClass)

public:
	EmployeeListClass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~EmployeeListClass();
	CTypedPtrArray< CObArray, Teacher*> *Teachers;
	CTypedPtrArray< CObArray, Worker*> *Workers;
	void updateList();
	CButton *DELETE_BUTTON;
	int *curr_id;
	char* mode;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = EMPLOYEE_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl eList;
	afx_msg void OnLvnItemchangedListCtrl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMDblclkListCtrl(NMHDR* pNMHDR, LRESULT* pResult);
};
