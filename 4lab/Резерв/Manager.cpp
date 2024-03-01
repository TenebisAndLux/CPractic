#include "Manager.h"
#include "GeneralOfDepartment.h"

Manager::~Manager(){
	delete[] listOfForemans;
	cout << "Manager dtor" << endl;
}

void Manager::extendListOfForemans(int capacity){
	if (capacity <= numberOfForemans) {
		return;
	}
	else {
		Foreman** newListOfForemans = new Foreman * [capacity];
		for (int i = 0; i < numberOfForemans; i++) {
			newListOfForemans[i] = listOfForemans[i];
		}
		delete[] listOfForemans;
		listOfForemans = newListOfForemans;
	}
}

void Manager::addNewForeman(Foreman& foreman){
	this->extendListOfForemans(numberOfForemans + 1);
	this->listOfForemans[numberOfForemans] = &foreman;
	numberOfForemans++;
}

void Manager::printInfoAboutPersonal() const {
	cout << "---------------------------------------------" << endl;
	Personal::printInfoAboutPersonal();

	for (int i = 0; i < numberOfForemans; i++) {
	listOfForemans[i]->Personal::printInfoAboutPersonal();
	}
	cout << "---------------------------------------------" << endl;
	cout << endl;
}

float Manager::getAverageKoef() const {
	return getAverageKoef();
}

float Manager::calculateSalary()  const {
	return 1.6f * getBaseValue();
}
