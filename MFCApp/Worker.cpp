#include "pch.h"
#include "Worker.h"

IMPLEMENT_SERIAL(Worker, CObject, 1);

Worker::Worker(int id, CString fName, CString lName, Sex gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, CString street, CString city, int zipCode, int phoneNumber, double sallery, bool isMarried, int kids, int dayOfStart, int monthOfStart, int yearOfStart, bool isWorking, int dayOfEnd, int monthOfEnd, int yearOfEnd, CString role) : 
	Employee(id, fName, lName, gender, dayOfBirth, monthOfBirth, yearOfBirth, street, city, zipCode, phoneNumber, sallery, isMarried, kids, dayOfStart, monthOfStart, yearOfStart, isWorking, dayOfEnd, monthOfEnd, yearOfEnd) {
	this->role = role;
}
void Worker::Serialize(CArchive& archive) {
	CObject::Serialize(archive);
	if (archive.IsStoring())
		archive << id << fName << lName << /*gender <<*/ dayOfBirth << monthOfBirth << yearOfBirth << street << city << zipCode << phoneNumber << sallery << isMarried << kids << dayOfStart
		<< monthOfStart << yearOfStart << isWorking << dayOfEnd << monthOfEnd << yearOfEnd << role;
	else
		archive >> id >> fName >> lName >> /*gender >>*/ dayOfBirth >> monthOfBirth >> yearOfBirth >> street >> city >> zipCode >> phoneNumber >> sallery >> isMarried >> kids >> dayOfStart
		>> monthOfStart >> yearOfStart >> isWorking >> dayOfEnd >> monthOfEnd >> yearOfEnd >> role;
}
void Worker::setRole(CString role) {
	this->role = role;
}
CString Worker::getRole() {
	return this->role;
}