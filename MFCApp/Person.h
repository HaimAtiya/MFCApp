#pragma once
#include "enums.h"
class Person
{
private:

protected:
	int id;
	//Sex gender;
	int dayOfBirth;
	int monthOfBirth;
	int yearOfBirth;
	CString fName;
	CString lName;
	CString street;
	CString city;
	int zipCode;
	int phoneNumber;
public:
	Person() {};
	Person(int id, CString fName, CString lName, Sex gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, CString street, CString city, int zipCode, int phoneNumber);
	friend CArchive& operator<<(CArchive& ar, Person p);
	friend CArchive& operator>>(CArchive& ar, Person &p);
	void setName(CString fName, CString lName);
	void setFirstName(CString fName);
	void setLastName(CString lName);
	void setAddress(CString street, CString city, int zipCode);
	void setStreet(CString street);
	void setCity(CString city);
	void setZipCode(int zipCode);
	void setPhoneNumber(int phoneNumber);
	const int getID();
	const CString getFullName();
	const CString getFName();
	const CString getLName();
	const Sex getGender();
	const CString getBirthDay();
	const int getDayOfBirth();
	const int getMonthOfBirth();
	const int getYearOfBirth();
	const CString getAddress();
	const CString getStreet();
	const CString getCity();
	const int getZipCode();
	const int getPhoneNumber();
};

