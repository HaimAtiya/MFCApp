#pragma once


// AddStudentClass dialog

class AddStudentClass : public CDialogEx
{
	DECLARE_DYNAMIC(AddStudentClass)

public:
	AddStudentClass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddStudentClass();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ADD_STUDENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
