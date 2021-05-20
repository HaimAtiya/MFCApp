#pragma once


// EmployeeMainDlg dialog

class EmployeeMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EmployeeMainDlg)

public:
	EmployeeMainDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~EmployeeMainDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = EMPLOYEE_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
