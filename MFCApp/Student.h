#pragma once
#include "Person.h"
class Student : Person, public CObject
{
private:
	Person student;
	Person motherDetails;
	Person fatherDetails;
	double avarage;
	int missingDays;
	int lates;
public:
	DECLARE_SERIAL(Student);
	Student() {};
	Student(Person student, Person motherDetails, Person fatherDetails);
	void Serialize(CArchive& archive);
	Person getStudentPersonDetails();
	void setParentDetails(enum Parent, Person details);
	int addNewGrade(int grade);
	int addMissingDay();
	int setMissingDays(int days);
	int addLate();
	int setLates;
};

