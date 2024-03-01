#include "Worker.h"

Worker::~Worker()
{
	cout << "Worker dtor" << endl;

	delete[] listOfDetails;
}

void Worker::extendListOfDetails(int capacity)
{
	if (capacity <= numberOfDetails) {
		return;
	}
	else {
		Detail** newListOfDetails = new Detail * [capacity];
		for (int i = 0; i < numberOfDetails; i++) {
			newListOfDetails[i] = listOfDetails[i];
		}
		delete[] listOfDetails;
		listOfDetails = newListOfDetails;
	}
}

void Worker::addNewDetail(Detail& detail)
{
	this->extendListOfDetails(numberOfDetails + 1);
	this->listOfDetails[numberOfDetails] = &detail;
	numberOfDetails++;
}

float Worker::getAverageKoef()
{
	float averageKoef = 0.0f;
	float summaryKoef = 0.0f;
	for (int i = 0; i < numberOfDetails; i++) {
		summaryKoef += listOfDetails[i]->getKoef();
	}

	averageKoef = summaryKoef / numberOfDetails;

	return averageKoef;
}

void Worker::printInfoAboutPersonal()
{
	cout << "Worker: "<< endl;
	cout << "FIO: " << this->getFio() << endl;
	cout << "Age: " << this->getAge() << endl;
	cout << "Slary: " << this->calculateSalary() << endl;
	cout << endl;

	cout << "Details for employee: " << endl;

	for (int i = 0; i < numberOfDetails; i++) {
		listOfDetails[i]->toString();
	}
	cout << endl;
}

float Worker::calculateSalary()
{
	float averageKoef = 0.0f;
	float summaryKoef = 0.0f;
	for (int i = 0; i < numberOfDetails; i++) {
		summaryKoef += listOfDetails[i]->getKoef();
	}

	averageKoef = summaryKoef / numberOfDetails;

	return averageKoef * getBaseValue();
}
