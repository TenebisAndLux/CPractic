#pragma once
#include "Worker.h"

class Foreman;

class Manager :public Worker
{
private:
	Foreman** listOfForemans = nullptr;
	int numberOfForemans;

public:


	~Manager() override;

	Manager(const string fio, int age, int BaseValue)
		:Worker(fio, age, BaseValue) {
		numberOfForemans = 0;
	}

	PersonalPost::PersonalPost getPost() const override {
		return PersonalPost::MANAGER;
	}

	Foreman** getListOfForemans() {
		return listOfForemans;
	}

	void extendListOfForemans(int capacity);

	void addNewForeman(Foreman& foreman);

	int getNumberOfForemans() {
		return numberOfForemans;
	}

	float calculateSalary() const override;
	void printInfoAboutPersonal() const override;
	float getAverageKoef()const override;
};