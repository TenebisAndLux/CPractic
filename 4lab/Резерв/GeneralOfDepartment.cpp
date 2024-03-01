#include "GeneralOfDepartment.h"
#include "Manager.h"

Foreman::~Foreman(){
	delete[] listOfEngineers;
	cout << "Foreman dtor" << endl;
}

Foreman::Foreman(const string fio, int age, int BaseValue)
	:Personal(fio, age, BaseValue) {
		numberOfEngineers = 0;
}

void Foreman::printInfoAboutPersonal() const{
	cout << "---------------------------------------------" << endl;
	Personal::printInfoAboutPersonal();

	for (int i = 0; i < numberOfEngineers; i++) {
	listOfEngineers[i]->Personal::printInfoAboutPersonal();
	}
	if (manager == nullptr) {
		//throw "No manager, not enough data";
	}
	else {
		manager->Personal::printInfoAboutPersonal();
	}
	cout << "---------------------------------------------" << endl;
	cout << endl;
}

void Foreman::extendListOfEngineers(int capacity){
	if (capacity <= numberOfEngineers) {
		return;
	}
	else {
		Engineer** newListOfEngineer = new Engineer * [capacity];
		for (int i = 0; i < numberOfEngineers; i++) {
			newListOfEngineer[i] = listOfEngineers[i];
		}
		delete[] listOfEngineers;
		listOfEngineers = newListOfEngineer;
	}
}

void Foreman::addNewEngineer(Engineer& engineer){
	this->extendListOfEngineers(numberOfEngineers + 1);
	this->listOfEngineers[numberOfEngineers] = &engineer;
	numberOfEngineers++;
}

float Foreman::getAverageKoef() const {
	float averageKoef = 0.0f;
	float summaryKoef = 0.0f;

	for (int i = 0; i < numberOfEngineers; i++) {
		summaryKoef += listOfEngineers[i]->getAverageKoef();
	}

	averageKoef = summaryKoef / numberOfEngineers;
	return averageKoef;
}

float Foreman::calculateSalary()  const{
	float averageKoef = 0.0f;

	averageKoef = this->getAverageKoef();

	float surchargeMultiplier = 1.0f;
	if (averageKoef > 1.3) {
		surchargeMultiplier = 1.5f;
	}
	else if (averageKoef > 1.1) {
		surchargeMultiplier = 1.25f;
	}
	
	return getBaseValue() * surchargeMultiplier;
}
