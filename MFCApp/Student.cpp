#include "pch.h"
#include "Student.h"

IMPLEMENT_SERIAL(Student, CObject, 1);

Student::Student(Person motherDetails, Person fatherDetails) :
	Person() {
	this->motherDetails = motherDetails;
	this->fatherDetails = fatherDetails;
	this->avarage = 0;
	this->missingDays = 0;
	this->lates = 0;
}
void Student::Serialize(CArchive& archive) {
	CObject::Serialize(archive);

	if (archive.IsStoring())
		archive << id << fName << lName << /*p.gender <<*/ dayOfBirth << monthOfBirth << yearOfBirth << street << city << zipCode << phoneNumber << motherDetails << fatherDetails << avarage << missingDays << lates;
	else
		archive >> id >> fName >> lName >> /*p.gender >>*/ dayOfBirth >> monthOfBirth >> yearOfBirth >> street >> city >> zipCode >> phoneNumber >> motherDetails >> fatherDetails >> avarage >> missingDays >> lates;
}

void Student::setStudentDetails(Person student) {
	id = student.getID();
	//Sex gender;
	dayOfBirth = student.getDayOfBirth();
	monthOfBirth = student.getMonthOfBirth();
	yearOfBirth = student.getYearOfBirth();
	fName = student.getFName();
	lName = student.getLName();
	street = student.getStreet();
	city = student.getCity();
	zipCode = student.getZipCode();
	phoneNumber = student.getPhoneNumber();

}
Person& Student::getMother() {
	return motherDetails;
}
Person& Student::getFather() {
	return fatherDetails;
}
int Student::getLate() {
	return lates;
}
int Student::getMissing() {
	return missingDays;
}
int Student::addMissingDay() {
	return ++missingDays;
}
int Student::addLate() {
	return ++lates;
}
int Student::removeMissingDay() {
	return !missingDays ? 0: --missingDays;
}
int Student::removeLate() {
	return !lates ? 0 : --lates;
}