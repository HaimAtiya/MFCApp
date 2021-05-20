// EmployeeMainDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCApp.h"
#include "EmployeeMainDlg.h"
#include "afxdialogex.h"


// EmployeeMainDlg dialog

IMPLEMENT_DYNAMIC(EmployeeMainDlg, CDialogEx)

EmployeeMainDlg::EmployeeMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(EMPLOYEE_MAIN, pParent)
{

}

EmployeeMainDlg::~EmployeeMainDlg()
{
}

BOOL EmployeeMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	listDlg.Teachers = &Teachers;
	listDlg.Workers = &Workers;
	listDlg.Create(EMPLOYEE_LIST, this);
	addEmployeeDlg.Create(ADD_EMPLOYEE, this);
	listDlg.ShowWindow(SW_SHOW);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void EmployeeMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EmployeeMainDlg, CDialogEx)
	ON_BN_CLICKED(IMPORT_TCHR_BTN, &EmployeeMainDlg::OnBnClickedTchrBtn)
	ON_BN_CLICKED(EXPORT_TCHR_BTN, &EmployeeMainDlg::OnExportTchrBnClicked)
	ON_BN_CLICKED(IMPORT_WRKR_BTN, &EmployeeMainDlg::OnImportWrkrBnClicked)
	ON_BN_CLICKED(EXPORT_WRKR_BTN, &EmployeeMainDlg::OnWrkrExportBnClicked)
	ON_BN_CLICKED(EMPLOYEE_LST_BTN, &EmployeeMainDlg::OnBnClickedLstBtn)
	ON_BN_CLICKED(ADD_WORKER_BTN, &EmployeeMainDlg::OnBnClickedWorkerBtn)
	ON_BN_CLICKED(ADD_TCHR_BTN, &EmployeeMainDlg::OnAddTchrBnClicked)
END_MESSAGE_MAP()


// EmployeeMainDlg message handlers



//IMPORT TEACHERS
void EmployeeMainDlg::OnBnClickedTchrBtn()
{
	CFileDialog dlg(TRUE, _T(".teachers"), NULL, 0, _T("Teachers (*.teachers)|*.teachers|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		Teachers.Serialize(ar);
		ar.Close();
		file.Close();
		MessageBox(L"רשימת המורים נטענה בהצלחה!");

		//Update list
		listDlg.updateList();
	}
}

//EXPORT TEACHERS
void EmployeeMainDlg::OnExportTchrBnClicked()
{
	CFileDialog dlg(FALSE, _T(".teachers"), NULL, 0, _T("Teachers (*.teachers)|*.teachers|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		Teachers.Serialize(ar);
		ar.Close();
		file.Close();
		MessageBox(L"רשימת המורים נשמרה בהצלחה!");
	}
}

//IMPORT WORKERS
void EmployeeMainDlg::OnImportWrkrBnClicked()
{
	CFileDialog dlg(TRUE, _T(".workers"), NULL, 0, _T("Workers (*.workers)|*.workers|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		Workers.Serialize(ar);
		ar.Close();
		file.Close();
		MessageBox(L"רשימת העובדים נטענה בהצלחה!");

		//Update list
		listDlg.updateList();
	}
}

//EXPORT WORKERS
void EmployeeMainDlg::OnWrkrExportBnClicked()
{
	CFileDialog dlg(FALSE, _T(".workers"), NULL, 0, _T("Workers (*.workers)|*.workers|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		Workers.Serialize(ar);
		ar.Close();
		file.Close();
		MessageBox(L"רשימת העובדים נשמרה בהצלחה!");
	}
}

//EMPLOYEE LIST BUTTON
void EmployeeMainDlg::OnBnClickedLstBtn()
{
	addEmployeeDlg.ShowWindow(SW_HIDE);
	listDlg.ShowWindow(SW_SHOW);
}


//ADD TEACHER BUTTON 
void EmployeeMainDlg::OnAddTchrBnClicked()
{
	listDlg.ShowWindow(SW_HIDE);
	addEmployeeDlg.setFormTitle(L"הוספת מורה חדש");
	addEmployeeDlg.ShowWindow(SW_SHOW);
}


//ADD WORKER BUTTON 
void EmployeeMainDlg::OnBnClickedWorkerBtn()
{
	listDlg.ShowWindow(SW_HIDE);
	addEmployeeDlg.setFormTitle(L"הוספת עובד חדש");
	addEmployeeDlg.ShowWindow(SW_SHOW);
	
}

