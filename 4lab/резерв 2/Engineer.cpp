#include "Engineer.h"

Engineer::~Engineer()
{
	cout << "Engineer dtor" << endl;

	delete[] listOfWorkers;
}

void Engineer::extendListOfWorkers(int capacity)
{
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

void Engineer::addNewWorker(Worker& worker)
{
	this->extendListOfWorkers(numberOfWorkers + 1);
	this->listOfWorkers[numberOfWorkers] = &worker;
	numberOfWorkers++;
}


void Engineer::printInfoAboutPersonal()
{
	cout << endl;

	cout << "Engineer: " << endl;
	cout << "FIO: " << this->getFio() << endl;
	cout << "Age: " << this->getAge() << endl;
	cout << "Slary: " << this->calculateSalary() << endl;
	cout << endl;

	cout << "Workers in command: " << endl;

	cout << endl;

	for (int i = 0; i < numberOfWorkers; i++) {

		cout << "Worker: " << endl;
		cout << "FIO: " << listOfWorkers[i]->getFio() << endl;;
		cout << "Age: " << listOfWorkers[i]->getAge() << endl;
		cout << "Slary: ";
		cout << listOfWorkers[i]->calculateSalary() << endl;
		cout << endl;
	}

	cout << endl;
}

float Engineer::getAverageKoef()
{
	float averageKoef = 0.0f;
	float summaryKoef = 0.0f;

	for (int i = 0; i < numberOfWorkers; i++) {
		summaryKoef += listOfWorkers[i]->getAverageKoef();
	}

	averageKoef = summaryKoef / numberOfWorkers;
	return averageKoef;
}

float Engineer::calculateSalary()
{
	float summaryKoef = 0.0f;
	float averageKoef = 0.0f;

	for (int i = 0; i < numberOfWorkers; i++) {
		summaryKoef += listOfWorkers[i]->getAverageKoef();
	}

	averageKoef = summaryKoef / numberOfWorkers;

	float surchargeMultiplier = 1.0f;

	if (averageKoef > 1){
		surchargeMultiplier = 1.1;
	}

	return getBaseValue() * surchargeMultiplier * averageKoef;

}


