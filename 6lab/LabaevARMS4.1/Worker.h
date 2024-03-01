#pragma once
#include "Detail.h"
#include "Personal.h"
#include "Except.h"
#include <vector>

class Worker:public Personal
{private:
	vector<Detail*> listOfDetails;

public:

	~Worker() override;

	Worker(string name, int age, int BaseValue);

	PersonalPost::PersonalPost getPost() const override {
		return PersonalPost::PersonalPost::WORKER;
	}

	void AddDetail(string name, int normRate, float factRate);

	float getAverageKoef() const override;
	void printInfoAboutPersonal() const override;
};