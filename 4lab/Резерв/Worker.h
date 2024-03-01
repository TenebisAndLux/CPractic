#pragma once
#include "Detail.h"
#include "Personal.h"

class Worker:public Personal
{private:
	Detail** listOfDetails;
	int numberOfDetails;

public:

	~Worker() override;

	Worker(string name, int age, int BaseValue);

	int getNumberOfDetails() {
		return numberOfDetails;
	}

	PersonalPost::PersonalPost getPost() const override {
		return PersonalPost::WORKER; 
	}

	void extendListOfDetails(int capacity);

	void AddDetail(string name, int normRate, float factRate);

	Detail** getListOfDetails() {
		return listOfDetails;
	};

	float getAverageKoef() const override;
	void printInfoAboutPersonal() const override;
};

