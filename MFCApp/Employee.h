#pragma once
#include "Person.h"
class Employee : public Person
{
protected:
	double sallery;
	bool isMarried;
	int kids;
	int dayOfStart;
	int monthOfStart;
	int yearOfStart;
	bool isWorking;
	int dayOfEnd;
	int monthOfEnd;
	int yearOfEnd;
public:
	Employee() {};
	Employee(int id, CString fName, CString lName, Sex gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, CString street, CString city, int zipCode, int phoneNumber, double sallery, bool isMarried, int kids, int dayOfStart, int monthOfStart, int yearOfStart, bool isWorking, int dayOfEnd, int monthOfEnd, int yearOfEnd);
	void setEmployeeDetails(Person employee);
	void setSallery(double sallery);
	void setMarrigeStatus(bool status);
	void setKids(int kids);
	void setWorkingStatus(bool status);
	void setDateOfEnding(int day, int month, int year);
	double getSallery();
	bool getMarrigeStatus();
	int getKids();
	int getStartDay();
	int getStartMonth();
	int getStartYear();
	CString getStartDate();
	bool getWorkingStatus();
	int getEndDay();
	int getEndMonth();
	int getEndYear();
	CString getEndDate();

};

