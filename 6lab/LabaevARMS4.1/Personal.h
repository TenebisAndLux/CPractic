#pragma once
#include <stdlib.h>
#include <string>
#include "Detail.h"
#include "PersonalPost.h"

using namespace std;

class Personal
{
private:
	int _BaseValue;
	int _age;
	string _fio;

public:
	virtual void printInfoAboutPersonal() const;

	virtual ~Personal();
	virtual float getBaseValue() const;
	virtual float getAverageKoef() const = 0;
	
	virtual float calculateSalary() const;

	Personal(const string fio, int age, int BaseValue);
	
	string getFio() {
		return _fio;
	}

	void setBaseValue(int BaseValue) {
		this->_BaseValue = BaseValue;
	}

	int getAge() {
		return _age;
	}

	void setAge(int age) {
		this->_age = age;
	}

	virtual PersonalPost::PersonalPost getPost() const {
		return PersonalPost::PersonalPost::DEFAULT;
	}
};