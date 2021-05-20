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
	Employee(double sallery, bool isMarried, int kids, int dayOfStart, int monthOfStart, int yearOfStart, bool isWorking, int dayOfEnd, int monthOfEnd, int yearOfEnd);
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

