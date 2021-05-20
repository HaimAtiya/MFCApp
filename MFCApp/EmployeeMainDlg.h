#pragma once
#include "Teacher.h"
#include "Worker.h"
#include "EmployeeListClass.h"
#include "AddEmployeeClass.h"
// EmployeeMainDlg dialog

class EmployeeMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EmployeeMainDlg)

public:
	EmployeeMainDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~EmployeeMainDlg();
	EmployeeListClass listDlg;
	AddEmployeeClass addEmployeeDlg;
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
public:
	afx_msg void OnBnClickedTchrBtn();
	afx_msg void OnExportTchrBnClicked();
	afx_msg void OnImportWrkrBnClicked();
	afx_msg void OnWrkrExportBnClicked();
	afx_msg void OnBnClickedLstBtn();
	afx_msg void OnBnClickedWorkerBtn();
	afx_msg void OnAddTchrBnClicked();
};
