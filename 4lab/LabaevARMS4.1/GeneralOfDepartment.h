#pragma once
#include "Engineer.h"

class Manager;

class Foreman: public Personal
{
private:
	vector<Engineer*> listOfEngineers;
	Manager* manager = nullptr;

public:

	~Foreman() override;

	Foreman(const string fio, int age, int BaseValue);

	PersonalPost::PersonalPost getPost() const override {
		return PersonalPost::PersonalPost::FOREMAN;
	}

	void setManager(Manager* manager) {
		this->manager = manager;
	}

	void addEngineer(Engineer& engineer);

	float calculateSalary() const override;
	void printInfoAboutPersonal() const override;
	float getAverageKoef() const override;
};