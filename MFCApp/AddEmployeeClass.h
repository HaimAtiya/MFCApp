#pragma once


// AddEmployeeClass dialog

class AddEmployeeClass : public CDialogEx
{
	DECLARE_DYNAMIC(AddEmployeeClass)

public:
	AddEmployeeClass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddEmployeeClass();
	void setFormTitle(CString title);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ADD_EMPLOYEE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic header_title;
	afx_msg void OnStnClickedEmployeeHeader();
};
