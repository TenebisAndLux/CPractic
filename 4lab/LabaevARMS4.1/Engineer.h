#pragma once
#include "Worker.h"

class Engineer:public Personal
{
private:
	vector<Worker*> listOfWorkers;

public:

	~Engineer() override;

	Engineer(const string fio, int age, int BaseValue);

	PersonalPost::PersonalPost getPost() const override {
		return PersonalPost::PersonalPost::ENGINEER;
	}

	void addWorker(Worker& worker);

	float calculateSalary() const override;
	void printInfoAboutPersonal() const override;
	float getAverageKoef() const override;
}