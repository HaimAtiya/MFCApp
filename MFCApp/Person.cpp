#include "pch.h"
#include "Person.h"

Person::Person(int id, CString fName, CString lName, Sex gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, CString street, CString city, int zipCode, int phoneNumber) {
	this->id = id;
	this->fName = fName;
	this->lName = lName;
	this->gender = gender;
	this->dayOfBirth = dayOfBirth;
	this->monthOfBirth = monthOfBirth;
	this->yearOfBirth = yearOfBirth;
	this->street = street;
	this->city = city;
	this->zipCode = zipCode;
	this->phoneNumber = phoneNumber;
}
void Person::setName(CString fName, CString lName){
	this->fName = fName;
	this->lName = lName;
}
void Person::setFirstName(CString fName) {
	this->fName = fName;
}
void Person::setLastName(CString lName) {
	this->lName = lName;
}
void Person::setAddress(CString street, CString city, int zipCode) {
	this->street = street;
	this->city = city;
	this->zipCode = zipCode;
}
void Person::setStreet(CString street) {
	this->street = street;
}
void Person::setCity(CString city) {
	this->city = city;
}
void Person::setZipCode(int zipCode) {
	this->zipCode = zipCode;
}
void Person::setPhoneNumber(int phoneNumber) {
	this->phoneNumber = phoneNumber;
}
const int Person::getID() {
	return id;
}
const CString Person::getFullName() {
	CString fullName;
	fullName.Format(_T("%s %s"), fName, lName);
	return fullName;
}
const CString Person::getFName() {
	return fName;
}
const CString Person::getLName() {
	return lName;
}
const Sex Person::getGender() {
	return gender;
}
const CString Person::getBirthDay() {
	CString birthDay;
	birthDay.Format(_T("%d/%d/%d"), dayOfBirth, monthOfBirth, yearOfBirth);
	return birthDay;
}
const int Person::getDayOfBirth() {
	return dayOfBirth;
}
const int Person::getMonthOfBirth() {
	return monthOfBirth;
}
const int Person::getYearOfBirth() {
	return yearOfBirth;
}
const CString Person::getAddress() {
	CString address;
	address.Format(_T("%s, %s, %d"), street, city, zipCode);
	return address;
}
const CString Person::getStreet() {
	return street;
}
const CString Person::getCity() {
	return city;
}
const int Person::getZipCode() {
	return zipCode;
}
const int Person::getPhoneNumber() {
	return phoneNumber;
}