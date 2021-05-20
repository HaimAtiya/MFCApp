#pragma once
#include "Teacher.h"
#include "Worker.h"
#include "EmployeeListClass.h"

// EmployeeMainDlg dialog

class EmployeeMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EmployeeMainDlg)

public:
	EmployeeMainDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~EmployeeMainDlg();
	EmployeeListClass listDlg;
	CTypedPtrArray< CObArray, Teacher*> Teachers;
	CTypedPtrArray< CObArray, Worker*> Workers;


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = EMPLOYEE_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
