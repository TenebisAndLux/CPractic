#pragma once
#include "Personal.h"
#include "Worker.h"

class Factory{
	Personal** listOfPersonals;

	string name;
	int capacityOfPersonals;

public:

	~Factory();

	Factory(string name) {
		this->name = name;
		capacityOfPersonals = 0;
	}

	void extendListOfPersonals(int capacity);

	void addNewPersonal(Personal& personal);

	float getPayouts();

	void printInfoAboutMinMaxSalary();

	void printInfoAboutPersonal();

	void printInfoAboutPersonalByPost();

	void deleteById(int id);

	string getNameOfFactory() {
		return name;
	}

	int getCapacityOfPersonals(){
		return capacityOfPersonals;
	}
};

