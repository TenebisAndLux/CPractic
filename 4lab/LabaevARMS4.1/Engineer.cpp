#include "Engineer.h"

Engineer::~Engineer(){
	cout << "Engineer dtor" << endl;
}

Engineer::Engineer(const string fio, int age, int BaseValue)
	:Personal(fio, age, BaseValue) {
}

void Engineer::addWorker(Worker& worker) {
	auto it = listOfWorkers.end();
	listOfWorkers.insert(it, &worker);
}

void Engineer::printInfoAboutPersonal() const{
	cout << "---------------------------------------------" << endl;
	Personal::printInfoAboutPersonal();

	for (auto it = listOfWorkers.begin(); it != listOfWorkers.end(); ++it) {
		(*it)->Personal::printInfoAboutPersonal();
	}
	cout << "---------------------------------------------" << endl;
	cout << endl;
}

float Engineer::getAverageKoef() const{
	float averageKoef = 0.0f;
	float summaryKoef = 0.0f;
	if (listOfWorkers.size() == 0) {
		throw Exception("An engineer without workers is unacceptable.");
	}

	for (auto it = listOfWorkers.begin(); it != listOfWorkers.end(); ++it) {
		summaryKoef += (*it) -> getAverageKoef();
	}

	averageKoef = summaryKoef / listOfWorkers.size();
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