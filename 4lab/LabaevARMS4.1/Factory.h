#pragma once
#include "Personal.h"
#include "Worker.h"
#include "Engineer.h"
#include "GeneralOfDepartment.h"
#include "Manager.h"
#include "PersonalPost.h"

class Factory{
private:
	vector<Personal*> listOfPersonals;
	string _name;

public:

	~Factory();

	Factory(const string name);

	Personal& GetPersonal(int index) const {
		if (index < 0 || index >= listOfPersonals.size()) {
			throw("invalid index");
		}
		return *listOfPersonals[index];
	}

	Personal& GetPersonalByPost(PersonalPost::PersonalPost type, int index) const {
		if (type == PersonalPost::PersonalPost::DEFAULT) {
			throw ("Position not defined");
		}
		int Counter = 0;

		for (auto it = listOfPersonals.begin(); it != listOfPersonals.end(); ++it) {
			if ((*it)->getPost() == PersonalPost::PersonalPost(type)) {
				Counter++;
				if (Counter == index)
					return (**it);
			}
		}
		throw("wrong index");
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
		return listOfPersonals.size();
	}
};

