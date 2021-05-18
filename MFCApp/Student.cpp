#include "pch.h"
#include "Student.h"

IMPLEMENT_SERIAL(Student, CObject, 1);

Student::Student(Person student, Person motherDetails, Person fatherDetails) {
	this->student = student;
	this->motherDetails = motherDetails;
	this->fatherDetails = fatherDetails;
	this->avarage = 0;
	this->missingDays = 0;
	this->lates = 0;
}
void Student::Serialize(CArchive& archive) {
	CObject::Serialize(archive);

	if (archive.IsStoring())
		archive << student << motherDetails << fatherDetails << avarage << missingDays << lates;
	else
		archive >> student >> motherDetails >> fatherDetails >> avarage >> missingDays >> lates;
}
void setParentDetails(enum Parent, Person details);
int addNewGrade(int grade);
int addMissingDay();
int setMissingDays(int days);
int addLate();
int setLates;