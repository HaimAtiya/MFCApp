#pragma once
#include "Student.h"
#include "editStudentClass.h"
// AllStudentsClass dialog

class AllStudentsClass : public CDialogEx
{
	DECLARE_DYNAMIC(AllStudentsClass)

public:
	AllStudentsClass(CWnd* pParent = nullptr);   // standard constructor
	CTypedPtrArray< CObArray, Student*>* students;
	virtual ~AllStudentsClass();
	void updateList();
	int* curr_id;
	CButton *DELETE_BTN;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ALL_STUDENTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EVENTSINK_MAP()
	CListCtrl sList;
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListCtrl(NMHDR* pNMHDR, LRESULT* pResult);

};
