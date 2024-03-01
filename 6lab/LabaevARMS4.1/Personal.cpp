#include "Personal.h"

void Personal::printInfoAboutPersonal() const{
	cout << "Job title: " << PersonalPost::ToString(getPost()) << endl;
	cout << "FIO: " << _fio << endl;
	cout << "Age: " << _age << endl;
	cout << "Salary: " << calculateSalary() << endl;
	cout << endl;
}

Personal::~Personal(){
	cout << "Personal dtor" << endl;
}

float Personal::getBaseValue() const{
	return _BaseValue;
}

float Personal::calculateSalary() const{
	return getAverageKoef() * getBaseValue();
}

Personal::Personal(const string fio, int age, int BaseValue)
	:_age(age),_BaseValue(BaseValue){
	this-> _fio = fio;
}