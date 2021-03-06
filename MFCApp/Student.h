#pragma once
#include "Person.h"
class Student : public Person, public CObject
{
private:
	Person motherDetails;
	Person fatherDetails;
	double avarage;
	int missingDays;
	int lates;
public:
	DECLARE_SERIAL(Student);
	Student() {};
	Student(Person motherDetails, Person fatherDetails);
	void Serialize(CArchive& archive);
	void setParentDetails(enum Parent, Person details);
	int addNewGrade(int grade);
	int addMissingDay();
	int addLate();
	int removeMissingDay();
	int removeLate();
	void setStudentDetails(Person student);
	Person& getMother();
	Person& getFather();
	int getLate();
	int getMissing();
};

