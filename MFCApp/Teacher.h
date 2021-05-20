#pragma once
#include "Employee.h"
class Teacher : public Employee, public CObject
{
private:
	CString proffesion;
	CString education;
	bool isEducator;
	CString association;
public:
	DECLARE_SERIAL(Teacher);
	Teacher() {};
	Teacher(int id, CString fName, CString lName, Sex gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, CString street, CString city, int zipCode, int phoneNumber, double sallery, bool isMarried, int kids, int dayOfStart, int monthOfStart, int yearOfStart, bool isWorking, int dayOfEnd, int monthOfEnd, int yearOfEnd, CString proffesion, CString education, bool isEducator, CString association);
	void Serialize(CArchive& archive);
	void setProffesion(CString proffesion);
	void setEducation(CString education);
	void setEducatorStatus(bool isEducator);
	void setAssociation(CString Association);
	CString getProffesion();
	CString getEducation();
	bool getEducatorStatus();
	CString getAssociation();
};

