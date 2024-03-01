#include "Factory.h"
#include "Personal.h"
#include "Worker.h"
#include "Engineer.h"
#include "Manager.h"
#include "GeneralOfDepartment.h"

Factory::~Factory(){
	for (size_t i = 0; i < capacityOfPersonals; i++) {
		delete listOfPersonals[i];
	}
	delete[] listOfPersonals;

	cout << "Factory dtor" << endl;
}

void Factory::AddPerson(const string fio, int age, int BaseValue, PersonalPost::PersonalPost type){
	if (type == PersonalPost::DEFAULT)
		throw ("Position not defined");

	Personal** newListOfPersonals = new Personal * [capacityOfPersonals + 1];
	memcpy(newListOfPersonals, listOfPersonals, capacityOfPersonals * sizeof(void*));

	switch (type)
	{
	case PersonalPost::WORKER:
		newListOfPersonals[capacityOfPersonals] = new Worker(fio, age, BaseValue);
		break;
	case PersonalPost::ENGINEER:
		newListOfPersonals[capacityOfPersonals] = new Engineer(fio, age, BaseValue);
		break;
	case PersonalPost::FOREMAN:
		newListOfPersonals[capacityOfPersonals] = new Foreman(fio, age, BaseValue);
		break;
	case PersonalPost::MANAGER:
		newListOfPersonals[capacityOfPersonals] = new Manager(fio, age, BaseValue);
		break;
	}

	delete[] listOfPersonals;
	listOfPersonals = newListOfPersonals;
	capacityOfPersonals++;
}

Factory::Factory(const string name) {
	this->_name = name;
	capacityOfPersonals = 0;
}

float Factory::getPayouts(){
	float summPayout = 0.0f;

	for (int i = 0; i < capacityOfPersonals; i++) {
		summPayout += listOfPersonals[i]->calculateSalary();
	}
	return summPayout;
}

void Factory::printInfoAboutMinMaxSalary(){
	for (int i = 1; i < 5; i++) {
		cout << "For post " << PersonalPost::ToString(PersonalPost::PersonalPost(i)) << endl;

		float minSalary = 1000000;
		float maxSalary = 0;

		for (int j = 0; j < capacityOfPersonals; j++) {
			if (listOfPersonals[j]->getPost() == PersonalPost::PersonalPost(i)) {
				if (listOfPersonals[j]->calculateSalary() < minSalary) {
					minSalary = listOfPersonals[j]->calculateSalary();
				}
			}
		}

		if (minSalary == 1000000) {
			minSalary = 0;
		}
		cout << "Minimal salary: " << minSalary << endl;

		for (int j = 0; j < capacityOfPersonals; j++) {
			if (listOfPersonals[j]->getPost() == PersonalPost::PersonalPost(i)) {
				if (listOfPersonals[j]->calculateSalary() > maxSalary) {
					maxSalary = listOfPersonals[j]->calculateSalary();
				}
			}
		}

		cout << "Maximum salary: " << maxSalary << endl;
	}
}

void Factory::printInfoAboutPersonal(){
	for (int i = 0; i < capacityOfPersonals; i++) {
		listOfPersonals[i]->printInfoAboutPersonal();
	}
}

void Factory::printInfoAboutPersonalByPost(){
	for (int i = 1; i < 5; i++) {
		int totalCounter = 0;

		for (int j = 0; j < capacityOfPersonals; j++) {
			if (listOfPersonals[j]->getPost() == PersonalPost::PersonalPost(i)) {
				totalCounter++;
			}
		}
		cout << "Total number of personal on post " << PersonalPost::ToString(PersonalPost::PersonalPost(i)) << " : " << totalCounter << endl;
	}
}

void Factory::deleteById(int index, PersonalPost::PersonalPost type){
	if (type == PersonalPost::DEFAULT)
		throw ("Position not defined");
	
	int Counter = 0;
	int id;
		for (int i = 0; i < capacityOfPersonals; i++) {
			if (listOfPersonals[i]->getPost() == PersonalPost::PersonalPost(type)) {
				Counter++;
				if (Counter == index)
					id = i;
			}
		}

	delete listOfPersonals[id];

	Personal** newListOfPersonals = new Personal * [capacityOfPersonals - 1];
	for (int i = 0; i < id ; i++) {
		newListOfPersonals[i] = listOfPersonals[i];
	}
	for (int j = id + 1; j < capacityOfPersonals; j++) {
		newListOfPersonals[j-1] = listOfPersonals[j];
	}
	delete[] listOfPersonals;

	listOfPersonals = newListOfPersonals;
	capacityOfPersonals--;
}