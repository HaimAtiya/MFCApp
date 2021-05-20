#include "pch.h"
#include "Teacher.h"

IMPLEMENT_SERIAL(Teacher, CObject, 1);

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


Teacher::Teacher(int id, CString fName, CString lName, Sex gender, int dayOfBirth, int monthOfBirth, int yearOfBirth, CString street, CString city, int zipCode, int phoneNumber, double sallery, bool isMarried, int kids, int dayOfStart, int monthOfStart, int yearOfStart, bool isWorking, int dayOfEnd, int monthOfEnd, int yearOfEnd, CString proffesion, CString education, bool isEducator, CString association) : 
	Employee(id,  fName,  lName,  gender,  dayOfBirth,  monthOfBirth,  yearOfBirth,  street,  city,  zipCode,  phoneNumber,  sallery,  isMarried,  kids,  dayOfStart,  monthOfStart,  yearOfStart,  isWorking,  dayOfEnd,  monthOfEnd,  yearOfEnd) {
	this->proffesion = proffesion;
	this->education = education;
	this->isEducator = isEducator;
	this->association = association;
}
void Teacher::Serialize(CArchive& archive) {
	CObject::Serialize(archive);

	if (archive.IsStoring())
		archive << id << fName << lName << /*gender <<*/ dayOfBirth << monthOfBirth << yearOfBirth << street << city << zipCode << phoneNumber << sallery << isMarried << kids << dayOfStart
		<< monthOfStart << yearOfStart << isWorking << dayOfEnd << monthOfEnd << yearOfEnd << proffesion << education << isEducator << association;
	else
		archive >> id >> fName >> lName >> /*gender >>*/ dayOfBirth >> monthOfBirth >> yearOfBirth >> street >> city >> zipCode >> phoneNumber >> sallery >> isMarried >> kids >> dayOfStart
		>> monthOfStart >> yearOfStart >> isWorking >> dayOfEnd >> monthOfEnd >> yearOfEnd >> proffesion >> education >> isEducator >> association;
}
void Teacher::setProffesion(CString proffesion) {
	this->proffesion = proffesion;
}
void Teacher::setEducation(CString education) {
	this->education = education;
}
void Teacher::setEducatorStatus(bool isEducator) {
	this->isEducator = isEducator;
}
void Teacher::setAssociation(CString Association) {
	this->association = association;
}
CString Teacher::getProffesion() {
	return this->proffesion;
}
CString Teacher::getEducation() {
	return this->proffesion;
}
bool Teacher::getEducatorStatus() {
	return this->isEducator;
}
CString Teacher::getAssociation() {
	return this->association;
}