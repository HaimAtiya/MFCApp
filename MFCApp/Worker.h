#pragma once
#include "Employee.h"

class Worker : public Employee, public CObject
{
private:
	CString role;
public:
	DECLARE_SERIAL(Worker);
	Worker() {};
	Worker(int id, CString fName, CString lName, Sex gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, CString street, CString city, int zipCode, int phoneNumber, double sallery, bool isMarried, int kids, int dayOfStart, int monthOfStart, int yearOfStart, bool isWorking, int dayOfEnd, int monthOfEnd, int yearOfEnd, CString role);
	void Serialize(CArchive& archive);
	void setRole(CString role);
	CString getRole();
};

