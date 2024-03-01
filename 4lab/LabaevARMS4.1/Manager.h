#pragma once
#include "Worker.h"

class Foreman;

class Manager :public Worker
{
private:
	vector<Foreman*> listOfForemans;

public:
	~Manager() override;

	Manager(const string fio, int age, int BaseValue)
		:Worker(fio, age, BaseValue) {
	}

	PersonalPost::PersonalPost getPost() const override {
		return PersonalPost::PersonalPost::MANAGER;
	}

	void addForeman(Foreman& foreman);

	float calculateSalary() const override;
	void printInfoAboutPersonal() const override;
	float getAverageKoef()const override;
};