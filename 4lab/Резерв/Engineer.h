#pragma once
#include "Worker.h"
class Engineer:public Personal
{
private:
	Worker** listOfWorkers = nullptr;
	int numberOfWorkers;

public:

	~Engineer() override;

	Engineer(const string fio, int age, int BaseValue);

	Worker** getListOfWorkers() {
		return listOfWorkers;
	};

	PersonalPost::PersonalPost getPost() const override {
		return PersonalPost::ENGINEER;
	}

	void extendListOfWorkers(int capacity);

	void addNewWorker(Worker& worker);

	int getNumberOfWorkers() {
		return numberOfWorkers;
	}

	float calculateSalary() const override;
	void printInfoAboutPersonal() const override;
	float getAverageKoef() const override;
};

