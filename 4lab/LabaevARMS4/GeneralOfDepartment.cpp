#include "GeneralOfDepartment.h"

Foreman::~Foreman()
{

	cout << "Foreman dtor" << endl;

	delete[] listOfEngineers;
}

Foreman::Foreman(string name, int age, int BaseValue){
	this->setFio(name);
	this->setAge(age);
	this->setBaseValue(BaseValue);
	this->setPost(arrayOfPosts[FOREMAN]);
}

void Foreman::printInfoAboutPersonal()
{
	for (int i = 0; i < numberOfEngineers; i++) {
		cout << endl;
		cout << "Engineer: " << endl;
		cout << "FIO: " << listOfEngineers[i]->getFio() << endl;
		cout << "Age: " << listOfEngineers[i]->getAge() << endl;
		cout << "Slary: ";
		cout << listOfEngineers[i]->calculateSalary() << endl;
		listOfEngineers[i]->printInfoAboutPersonal();
		cout << endl;
	}
}

void Foreman::extendListOfEngineers(int capacity)
{
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

void Foreman::addNewEngineer(Engineer& engineer)
{
	this->extendListOfEngineers(numberOfEngineers + 1);
	this->listOfEngineers[numberOfEngineers] = &engineer;
	numberOfEngineers++;
}

float Foreman::calculateSalary()
{
	float averageKoef = 0.0f;
	float summaryKoef = 0.0f;

	for (int i = 0; i < numberOfEngineers; i++) {
		summaryKoef += listOfEngineers[i]->getAverageKoef();
	}

	averageKoef = summaryKoef / numberOfEngineers;

	float surchargeMultiplier = 1.0f;
	if (averageKoef > 1.3) {
		surchargeMultiplier = 1.5f;
	}
	else if (averageKoef > 1.1) {
		surchargeMultiplier = 1.25f;
	}
	
	return getBaseValue() * surchargeMultiplier;
}
