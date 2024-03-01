#pragma once
#include "Personal.h"
#include "Worker.h"
#include "Engineer.h"
#include "GeneralOfDepartment.h"
#include "Manager.h"
#include "PersonalPost.h"

class Factory{
private:
	Personal** listOfPersonals;
	string _name;
	int capacityOfPersonals = 0;

public:

	~Factory();

	Factory(const string name);

	Personal& GetPersonal(int index) const { 
		return *listOfPersonals[index];
	}

	Personal& GetPersonalByPost(PersonalPost::PersonalPost type, int index) const {
		if (type == PersonalPost::DEFAULT)
			throw ("Position not defined");
		int Counter = 0;
		for (int i = 0; i < capacityOfPersonals; i++) {
			if (listOfPersonals[i]->getPost() == PersonalPost::PersonalPost(type)) {
				Counter++;
				if (Counter == index)
					return *listOfPersonals[i];
			}
		}
	}

	float getPayouts();

	void printInfoAboutMinMaxSalary();

	void printInfoAboutPersonal();

	void printInfoAboutPersonalByPost();

	void deleteById(int id, PersonalPost::PersonalPost type);

	void AddPerson(const string fio, int age, int BaseValue, PersonalPost::PersonalPost type);

	const string getNameOfFactory() {
		return _name;
	}

	int getCapacityOfPersonals(){
		return capacityOfPersonals;
	}
};

