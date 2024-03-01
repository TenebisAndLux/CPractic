#pragma once
#include "GeneralOfDepartment.h"

class Manager :public Personal
{
	Foreman** listOfForemans;
	int numberOfForemans;

public:

	~Manager();

	Foreman** getListOfForemans() {
		return listOfForemans;
	}

	void extendListOfForemans(int capacity);

	void addNewForeman(Foreman& foreman);

	Manager(Worker& worker) {
		this->setAge(worker.getAge());
		this->setBaseValue(worker.calculateSalary());
		this->setFio(worker.getFio());
		worker.setPost(arrayOfPosts[MANAGER]);
		//this->setPost(arrayOfPosts[MANAGER]);
		numberOfForemans = 0;
	}
	
	void printInfoAboutPersonal() override;

	int getNumberOfForemans() {
		return numberOfForemans;
	}

	void printInfoAboutForemans();

	float calculateSalary() override {
		return 1.6 * getBaseValue();
	};
};

