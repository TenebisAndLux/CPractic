#pragma once
#include "Engineer.h"

class Manager;

class Foreman: public Personal
{
private:
	Engineer** listOfEngineers = nullptr;
	Manager* manager = nullptr;
	int numberOfEngineers;

public:

	~Foreman() override;

	Foreman(const string fio, int age, int BaseValue);

	Engineer** getListOfEngineers() {
		return listOfEngineers;
	}

	PersonalPost::PersonalPost getPost() const override {
		return PersonalPost::FOREMAN;
	}

	int getNumberOfEngineers() {
		return numberOfEngineers;
	}

	void setManager(Manager* manager) {
		this->manager = manager;
	}

	void extendListOfEngineers(int capacity);
	void addNewEngineer(Engineer& engineer);

	float calculateSalary() const override;
	void printInfoAboutPersonal() const override;
	float getAverageKoef() const override;
};

