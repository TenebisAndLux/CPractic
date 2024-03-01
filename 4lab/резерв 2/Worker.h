#pragma once
#include "Detail.h"
#include "Personal.h"

class Worker:public Personal
{

	Detail** listOfDetails = nullptr;
	int numberOfDetails;

public:

	~Worker();

	Worker(const char* name, int age, int base){
		this->setFio(name);
		this->setAge(age);
		this->setBaseValue(base);
		this->setPost(arrayOfPosts[WORKER]);
		numberOfDetails = 0;
	}

	void extendListOfDetails(int capacity);

	void addNewDetail(Detail& detail);

	Detail** getListOfDetails() {
		return listOfDetails;
	};

	float getAverageKoef();

	void printInfoAboutPersonal() override;

	float calculateSalary() override;
};

