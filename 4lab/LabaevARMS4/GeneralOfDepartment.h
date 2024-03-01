#pragma once
#include "Engineer.h"

class Foreman: public Personal
{
	Engineer** listOfEngineers;
	int numberOfEngineers;

public:

	~Foreman();

	Foreman(string name, int age, int BaseValue);

	Engineer** getListOfEngineers() {
		return listOfEngineers;
	}

	int getNumberOfEngineers() {
		return numberOfEngineers;
	}

	void printInfoAboutPersonal() override;

	void extendListOfEngineers(int capacity);

	void addNewEngineer(Engineer& engineer);

	float calculateSalary() override;

};

