#pragma once
#include "Worker.h"
class Engineer:public Personal
{
	int numberOfWorkers;
	Worker** listOfWorkers;

public:

	~Engineer();

	Engineer(const char* name, int age, int BaseValue) {
		this->setAge(age);
		this->setBaseValue(BaseValue);
		this->setFio(name);
		this->setPost(arrayOfPosts[ENGINEER]);
		this->numberOfWorkers = 0;
	}

	Worker** getListOfWorkers() {
		return listOfWorkers;
	};

	void extendListOfWorkers(int capacity);

	void addNewWorker(Worker& worker);

	int getNumberOfWorkers() {
		return numberOfWorkers;
	}

	void printInfoAboutPersonal() override;

	float getAverageKoef();

	float calculateSalary() override;
	
};

