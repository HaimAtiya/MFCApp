#pragma once


// AllStudentsClass dialog

class AllStudentsClass : public CDialogEx
{
	DECLARE_DYNAMIC(AllStudentsClass)

public:
	AllStudentsClass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AllStudentsClass();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ALL_STUDENTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
