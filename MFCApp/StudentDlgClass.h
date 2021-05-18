#pragma once

// StudentDlgClass dialog
class StudentDlgClass : public CDialogEx
{
	DECLARE_DYNAMIC(StudentDlgClass)

public:
	StudentDlgClass(CWnd* pParent = nullptr);   // standard constructor
	virtual ~StudentDlgClass();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Students_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
//	afx_msg void OnBnClickedListBtn();
	afx_msg void OnBnClickedListBtn();
};
