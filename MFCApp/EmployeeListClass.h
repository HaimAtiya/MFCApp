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
};
