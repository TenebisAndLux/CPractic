#pragma once
#include <stdlib.h>
#include <string>
#include "Detail.h"

using namespace std;

const string arrayOfPosts[5] = { "Default", "Worker", "Engineer", "Foreman", "Manager" };

enum posts {
	DEFAULT,
	WORKER,
	ENGINEER,
	FOREMAN,
	MANAGER
};

class Personal
{
	string fio;
	string post;
	int age;
	int BaseValue;

public:
	virtual void printInfoAboutPersonal() = 0;

	virtual ~Personal();

	virtual float calculateSalary() = 0;

	void setPost(string post) {
		this->post = post;
	}
	
	string getPost() {
		return post;
	}

	Personal(){
	}

	Personal(string fio, int age, int BaseValue) {
		this->age = age;
		this->fio = fio;
		this->BaseValue = BaseValue;
		this->post = arrayOfPosts[DEFAULT];
	}

	int getBaseValue() {
		return BaseValue;
	}

	void setBaseValue(int BaseValue) {
		this->BaseValue = BaseValue;
	}
	
	string getFio() {
		return fio;
	}

	void setFio(string fio) {
		this->fio = fio;
	}

	int getAge() {
		return age;
	}

	void setAge(int age) {
		this->age = age;
	}
};

