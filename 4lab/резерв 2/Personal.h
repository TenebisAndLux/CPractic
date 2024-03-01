#pragma once
#include <stdlib.h>
#include "Detail.h"

using namespace std;

static const char* arrayOfPosts[5] = { "Default", "Worker", "Engineer", "Foreman", "Manager" };

enum posts {
	DEFAULT,
	WORKER,
	ENGINEER,
	FOREMAN,
	MANAGER
};

class Personal
{
	const char* fio;
	const char* post;
	int age;
	int BaseValue;

public:
	virtual void printInfoAboutPersonal() = 0;

	virtual ~Personal();

	virtual float calculateSalary() = 0;

	void setPost(const char* post) {
		this->post = post;
	}
	
	const char* getPost() {
		return post;
	}

	Personal(){
	}

	Personal(const char* fio, int age, int BaseValue) {
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
	
	const char* getFio() {
		return fio;
	}

	void setFio(const char* fio) {
		this->fio = fio;
	}

	int getAge() {
		return age;
	}

	void setAge(int age) {
		this->age = age;
	}
};

