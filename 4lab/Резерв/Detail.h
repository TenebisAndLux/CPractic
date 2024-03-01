#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Detail
{
private:
	string _name;
	int _numberOfDetails;

public:

	int normRate;
	float factRate;
	float koef;

	Detail(const string name, int normRate, float factRate);

	~Detail();

	string getName() {
		return _name;
	}

	void toString() {
		cout << endl;

		cout << "Name of detail: " << _name << endl;
		cout << "NormRate of detail: " << normRate << endl;
		cout << "FactRate of detail: " << factRate << endl;
		cout << "Koef of detail: " << koef << endl;

		cout << endl;
	}

	void setName(const string name) {
		this->_name = name;
	}

	int getNormRate() {
		return normRate;
	}

	void setNormRate(int normRate) {
		this->normRate = normRate;
	}

	float getFactRate() {
		return factRate;
	}

	void setFactRate(int factRate) {
		this->factRate = factRate;
	}

	float getKoef() {
		return koef;
	}
};

