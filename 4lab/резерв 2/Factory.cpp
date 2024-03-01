#include "Factory.h"
#include "Worker.h"

Factory::~Factory(){

	cout << "Factory dtor" << endl;

	delete[] listOfPersonals;
}

float Factory::getPayouts(){
	float summPayout = 0;

	for (int i = 0; i < capacityOfPersonals; i++) {
		summPayout += listOfPersonals[i]->calculateSalary();
	}
	return summPayout;
}

void Factory::printInfoAboutMinMaxSalary()
{
	for (int i = 1; i < 5; i++) {
		cout << "For post " << arrayOfPosts[i] << endl;

		float minSalary = 10000000;

		for (int j = 0; j < capacityOfPersonals; j++) {
			if (listOfPersonals[j]->getPost() == arrayOfPosts[i]) {
				if (listOfPersonals[j]->calculateSalary() < minSalary) {
					minSalary = listOfPersonals[j]->calculateSalary();
				}
			}
		}
		if (minSalary == 10000000){
			minSalary = 0;
		}

		cout << "Minimal salary: " << minSalary << endl;

		float maxSalary = 0;

		for (int j = 0; j < capacityOfPersonals; j++) {
			if (listOfPersonals[j]->getPost() == arrayOfPosts[i]) {
				if (listOfPersonals[j]->calculateSalary() > maxSalary) {
					maxSalary = listOfPersonals[j]->calculateSalary();
				}
			}
		}

		cout << "Maximum salary: " << maxSalary << endl;
	}
}

void Factory::printInfoAboutPersonal()
{
	for (int i = 0; i < capacityOfPersonals; i++) {
		listOfPersonals[i]->printInfoAboutPersonal();
}
}

void Factory::printInfoAboutPersonalByPost()
{
	for (int i = 1; i < 5; i++) {
		int totalCounter = 0;

		for (int j = 0; j < capacityOfPersonals; j++) {
			if (arrayOfPosts[i] == listOfPersonals[j]->getPost()) {
				totalCounter++;
			}
		}
		cout << "Total number of personal on post " << arrayOfPosts[i] << " : " << totalCounter << endl;
	}
}

void Factory::deleteById(int id)
{
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

void Factory::extendListOfPersonals(int capacity)
{
	if (capacity <= capacityOfPersonals) {
		return;
	}
	else {
		Personal** newListOfPersonals = new Personal * [capacity];
		for (int i = 0; i < capacityOfPersonals; i++) {
			newListOfPersonals[i] = listOfPersonals[i];
		}
		delete[] listOfPersonals;
		listOfPersonals = newListOfPersonals;
	}
}

void Factory::addNewPersonal(Personal& personal)
{
	this->extendListOfPersonals(capacityOfPersonals + 1);
	this->listOfPersonals[capacityOfPersonals] = &personal;
	capacityOfPersonals++;
}
