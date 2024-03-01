#include "Factory.h"
#include "Personal.h"
#include "Worker.h"
#include "Engineer.h"
#include "Manager.h"
#include "GeneralOfDepartment.h"

Factory::~Factory(){
	for (auto it = listOfPersonals.begin(); it != listOfPersonals.end(); ++it) {
		delete *it;
	}
	cout << "Factory dtor" << endl;
}

void Factory::AddPerson(const string fio, int age, int BaseValue, PersonalPost::PersonalPost type){
	if (type == PersonalPost::PersonalPost::DEFAULT) {
		throw ("Position not defined");
	}
	auto it = listOfPersonals.end();

	switch (type)
	{
	case PersonalPost::PersonalPost::WORKER:
		listOfPersonals.insert(it, new Worker(fio, age, BaseValue));
		break;
	case PersonalPost::PersonalPost::ENGINEER:
		listOfPersonals.insert(it, new Engineer(fio, age, BaseValue));
		break;
	case PersonalPost::PersonalPost::FOREMAN:
		listOfPersonals.insert(it, new Foreman(fio, age, BaseValue));
		break;
	case PersonalPost::PersonalPost::MANAGER:
		listOfPersonals.insert(it, new Manager(fio, age, BaseValue));
		break;
	}
}

Factory::Factory(const string name) {
	this->_name = name;
}

float Factory::getPayouts(){
	float summPayout = 0.0f;

	for (auto it = listOfPersonals.begin(); it != listOfPersonals.end(); ++it) {
		summPayout += (*it)->calculateSalary();
	}
	return summPayout;
}

void Factory::printInfoAboutMinMaxSalary(){
	for (int i = 1; i < 5; i++) {
		cout << "For post " << PersonalPost::ToString(PersonalPost::PersonalPost(i)) << endl;

		float minSalary = 1000000;
		float maxSalary = 0;

		for (auto it = listOfPersonals.begin(); it != listOfPersonals.end(); ++it) {
			if ((*it)->getPost() == PersonalPost::PersonalPost(i)) {
				if ((*it)->calculateSalary() < minSalary) {
					minSalary = (*it)->calculateSalary();
				}
			}
		}

		if (minSalary == 1000000) {
			minSalary = 0;
		}
		cout << "Minimal salary: " << minSalary << endl;

		for (auto it = listOfPersonals.begin(); it != listOfPersonals.end(); ++it) {
			if ((*it)->getPost() == PersonalPost::PersonalPost(i)) {
				if ((*it)->calculateSalary() > maxSalary) {
					maxSalary = (*it)->calculateSalary();
				}
			}
		}
		cout << "Maximum salary: " << maxSalary << endl;
	}
}

void Factory::printInfoAboutPersonal(){
	for (auto it = listOfPersonals.begin(); it != listOfPersonals.end(); ++it) {
		(*it)->printInfoAboutPersonal();
	}
}

void Factory::printInfoAboutPersonalByPost(){
	for (int i = 1; i < 5; i++) {
		int totalCounter = 0;
		
		for (auto it = listOfPersonals.begin(); it != listOfPersonals.end(); ++it) {
			if ((*it)->getPost() == PersonalPost::PersonalPost(i)) {
				totalCounter++;
			}
		}
		cout << "Total number of personal on post " << PersonalPost::ToString(PersonalPost::PersonalPost(i)) << " : " << totalCounter << endl;
	}
}

void Factory::deleteById(int index, PersonalPost::PersonalPost type){
	if (type == PersonalPost::PersonalPost::DEFAULT) {
		throw ("Position not defined");
	}
	
	int Counter = 0;
	
	for (auto it = listOfPersonals.begin(); it != listOfPersonals.end(); ++it) {
		if ((*it)->getPost() == PersonalPost::PersonalPost(type)) {
			Counter++;
			if (Counter == index) {
				delete (*it);
				listOfPersonals.erase(it);
				return;
			}
		}
	}
	throw("wrong index");
}