#pragma once
#include "Employee.h"

class Worker : public Employee, public CObject
{
private:
	CString role;
public:
	DECLARE_SERIAL(Worker);
	Worker() {};
	Worker(CString role);
	void Serialize(CArchive& archive);
	void setRole(CString role);
	CString getRole();
};

