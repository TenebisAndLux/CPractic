#include "Engineer.h"

Engineer::~Engineer(){
	delete[] listOfWorkers;
	cout << "Engineer dtor" << endl;
}

Engineer::Engineer(const string fio, int age, int BaseValue)
	:Personal(fio, age, BaseValue) {
	numberOfWorkers = 0;
}

void Engineer::extendListOfWorkers(int capacity){
	if (capacity <= numberOfWorkers) {
		return;
	}
	else {
		Worker** newListOfWorkers = new Worker * [capacity];

		for (int i = 0; i < numberOfWorkers; i++) {
			newListOfWorkers[i] = listOfWorkers[i];
		}
		delete[] listOfWorkers;
		listOfWorkers = newListOfWorkers;
	}
}

void Engineer::addNewWorker(Worker& worker){
	this->extendListOfWorkers(numberOfWorkers + 1);
	this->listOfWorkers[numberOfWorkers] = &worker;
	numberOfWorkers++;
}


void Engineer::printInfoAboutPersonal() const{
	cout << "---------------------------------------------" << endl;
	Personal::printInfoAboutPersonal();

	for (int i = 0; i < numberOfWorkers; i++) {
	listOfWorkers[i]->Personal::printInfoAboutPersonal();
	}

	cout << "---------------------------------------------" << endl;
	cout << endl;
}

float Engineer::getAverageKoef() const{
	float averageKoef = 0.0f;
	float summaryKoef = 0.0f;

	for (int i = 0; i < numberOfWorkers; i++) {
		summaryKoef += listOfWorkers[i]->getAverageKoef();
	}

	averageKoef = summaryKoef / numberOfWorkers;
	return averageKoef;
}

float Engineer::calculateSalary() const{
	float averageKoef = 0.0f;

	averageKoef = this->getAverageKoef();

	float surchargeMultiplier = 1.0f;

	if (averageKoef > 1){
		surchargeMultiplier = 1.1;
	}

	return getBaseValue() * surchargeMultiplier * averageKoef;
}


