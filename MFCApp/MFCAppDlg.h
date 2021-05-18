
// MFCAppDlg.h : header file
//

#pragma once
#include "Student.h"

// CMFCAppDlg dialog
class CMFCAppDlg : public CDialogEx
{
// Construction
public:
	CMFCAppDlg(CWnd* pParent = nullptr);	// standard constructor
	CTypedPtrArray< CObArray, Student*> students;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
};
