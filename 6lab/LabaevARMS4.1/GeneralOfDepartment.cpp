#include "GeneralOfDepartment.h"
#include "Manager.h"

Foreman::~Foreman(){
	cout << "Foreman dtor" << endl;
}

Foreman::Foreman(const string fio, int age, int BaseValue)
	:Personal(fio, age, BaseValue) {
}

void Foreman::printInfoAboutPersonal() const{
	cout << "---------------------------------------------" << endl;
	Personal::printInfoAboutPersonal();

	for (auto it = listOfEngineers.begin(); it != listOfEngineers.end(); ++it) {
		(*it)->Personal::printInfoAboutPersonal();
	}
	
	if (manager == nullptr) {
		throw "No manager, not enough data to process";
	}
	else {
		manager->Personal::printInfoAboutPersonal();
	}
	cout << "---------------------------------------------" << endl;
	cout << endl;
}

void Foreman::addEngineer(Engineer& engineer) {
	auto it = listOfEngineers.end();
	listOfEngineers.insert(it, &engineer);
}

float Foreman::getAverageKoef() const {
	float averageKoef = 0.0f;
	float summaryKoef = 0.0f;
	if (listOfEngineers.size() == 0) {
		throw Exception("A foreman without engineers is unacceptable.");
	}

	for (auto it = listOfEngineers.begin(); it != listOfEngineers.end(); ++it) {
		summaryKoef += (*it)->getAverageKoef();
	}

	averageKoef = summaryKoef / listOfEngineers.size();
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
