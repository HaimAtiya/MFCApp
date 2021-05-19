#pragma once


// DeleteStudentClass dialog

class DeleteStudentClass : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteStudentClass)

public:
	DeleteStudentClass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DeleteStudentClass();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = DELETE_STUDENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
