#include "Manager.h"

Manager::~Manager(){

	cout << "Manager dtor" << endl;

	delete[] listOfForemans;
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

void Manager::printInfoAboutPersonal() {
	
	cout << endl;
	cout << "Foreman: " << endl;
	cout << "FIO: " << this->getFio() << endl;
	cout << "Age: " << this->getAge() << endl;
	cout << "Slary: ";
	cout << this->calculateSalary() << endl;
	cout << endl;
}

void Manager::printInfoAboutForemans()
{
	for (int i = 0; i < numberOfForemans; i++) {
		cout << endl;
		cout << "Foreman: " << endl;
		cout << "FIO: " << listOfForemans[i]->getFio() << endl;
		cout << "Age: " << listOfForemans[i]->getAge() << endl;
		cout << "Slary: ";
		cout << listOfForemans[i]->calculateSalary() << endl;
		listOfForemans[i]->printInfoAboutPersonal();
		cout << endl;
	}
}
