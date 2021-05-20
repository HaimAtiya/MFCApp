#include "pch.h"
#include "Worker.h"

IMPLEMENT_SERIAL(Worker, CObject, 1);

Worker::Worker(CString role) : Employee() {
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