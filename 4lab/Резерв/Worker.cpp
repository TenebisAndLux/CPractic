#include "Worker.h"

Worker::~Worker(){
	
	for(int i = 0; i < numberOfDetails; i++) {
		delete listOfDetails[i];
	}
	delete[] listOfDetails;

	cout << "Worker dtor" << endl;
}

Worker::Worker(const string fio, int age, int BaseValue)
	:Personal(fio, age, BaseValue){
	numberOfDetails = 0;
}

void Worker::extendListOfDetails(int capacity){
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

void Worker::AddDetail(const string name, int normRate, float factRate) {
	Detail** newListOfDetails = new Detail * [numberOfDetails + 1];
	memcpy(newListOfDetails, listOfDetails, numberOfDetails * sizeof(void*));
	newListOfDetails[numberOfDetails] = new Detail(name, normRate, factRate);

	delete[] listOfDetails;
	listOfDetails = newListOfDetails;
	numberOfDetails++;
}

float Worker::getAverageKoef() const {
	float averageKoef = 0.0f;
	float summaryKoef = 0.0f;
	for (int i = 0; i < numberOfDetails; i++) {
		summaryKoef += listOfDetails[i]->getKoef();
	}

	averageKoef = summaryKoef / numberOfDetails;

	return averageKoef;
}

void Worker::printInfoAboutPersonal() const{
	cout << "---------------------------------------------" << endl;

	Personal::printInfoAboutPersonal();

	for (int i = 0; i < numberOfDetails; i++) {
		listOfDetails[i]->toString();
	}

	cout << "---------------------------------------------" << endl;
	cout << endl;
}