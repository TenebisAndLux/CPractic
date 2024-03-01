#include "Detail.h"

Detail::Detail(const string name, int normRate, float factRate) {
	this->_name = name;
	this->normRate = normRate;
	this->factRate = factRate;
	this->koef = factRate / normRate;
}

Detail::~Detail(){
	cout << "Detail dtor" << endl;
}
