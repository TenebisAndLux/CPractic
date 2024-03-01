#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Detail
{
	const char* name;
	int normRate;
	float factRate;
	int numberOfDetails;
	float koef;

public:

	~Detail();

	Detail(const char* name, int normRate, float factRate) {
		this->name = name;
		this->normRate = normRate;
		this->factRate = factRate;
		this->koef = factRate / normRate;
	}

	const char* getName() {
		return name;
	}

	void toString() {
		cout << endl;

		cout << "Name of detail: " << name << endl;
		cout << "NormRate of detail: " << normRate << endl;
		cout << "FactRate of detail: " << factRate << endl;
		cout << "Koef of detail: " << koef << endl;

		cout << endl;
	}

	void setName(const char* name) {
		this->name = name;
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

