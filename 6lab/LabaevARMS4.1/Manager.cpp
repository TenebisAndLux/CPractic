#include "Manager.h"
#include "GeneralOfDepartment.h"

Manager::~Manager(){
	cout << "Manager dtor" << endl;
}

void Manager::addForeman(Foreman& foreman) {
	auto it = listOfForemans.end();
	listOfForemans.insert(it, &foreman);
}

void Manager::printInfoAboutPersonal() const {
	cout << "---------------------------------------------" << endl;
	Personal::printInfoAboutPersonal();

	for (auto it = listOfForemans.begin(); it != listOfForemans.end(); ++it) {
		(*it)->Personal::printInfoAboutPersonal();
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
