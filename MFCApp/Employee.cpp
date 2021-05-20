#include "pch.h"
#include "Employee.h"

Employee::Employee(double sallery, bool isMarried, int kids, int dayOfStart, int monthOfStart, int yearOfStart, bool isWorking, int dayOfEnd, int monthOfEnd, int yearOfEnd) : Person() {
	this->sallery = sallery;
	this->isMarried = isMarried;
	this->kids = kids;
	this->dayOfStart = dayOfStart;
	this->monthOfStart = monthOfStart;
	this->yearOfStart = yearOfStart;
	this->isWorking = isWorking;
	this->dayOfEnd = dayOfEnd;
	this->monthOfEnd = monthOfEnd;
	this->yearOfEnd;
}
void Employee::setEmployeeDetails(Person employee) {
	this->id = employee.getID();
	//Sex gender;
	this->dayOfBirth = employee.getDayOfBirth();
	this->monthOfBirth = employee.getMonthOfBirth();
	this->yearOfBirth = employee.getYearOfBirth();
	this->fName = employee.getFName();
	this->lName = employee.getLName();
	this->street = employee.getStreet();
	this->city = employee.getCity();
	this->zipCode = employee.getZipCode();
	this->phoneNumber = employee.getPhoneNumber();

}
void Employee::setSallery(double sallery) {
	this->sallery = sallery;
}
void Employee::setMarrigeStatus(bool status) {
	this->isMarried = status;
}
void Employee::setKids(int kids) {
	this->kids = kids;
}
void Employee::setWorkingStatus(bool status) {
	this->isWorking = status;
}
void Employee::setDateOfEnding(int day, int month, int year) {
	this->dayOfStart = day;
	this->monthOfStart = month;
	this->yearOfStart = year;
}
double Employee::getSallery() {
	return this->sallery;
}
bool Employee::getMarrigeStatus() {
	return this->isMarried;
}
int Employee::getKids() {
	return this->kids;
}
int Employee::getStartDay() {
	return this->dayOfStart;
}
int Employee::getStartMonth() {
	return this->monthOfStart;
}
int Employee::getStartYear() {
	return this->yearOfStart;
}
CString Employee::getStartDate() {
	CString tmp;
	tmp.Format(L"%d/%d/%d", this->dayOfStart, this->monthOfStart, this->yearOfStart);
	return tmp;
}
bool Employee::getWorkingStatus() {
	return this->isWorking;
}
int Employee::getEndDay() {
	return this->dayOfEnd;
}
int Employee::getEndMonth() {
	return this->monthOfEnd;
}
int Employee::getEndYear() {
	return this->yearOfEnd;
}
CString Employee::getEndDate() {
	CString tmp;
	tmp.Format(L"%d/%d/%d", this->dayOfEnd, this->monthOfEnd, this->yearOfEnd);
	return tmp;
}