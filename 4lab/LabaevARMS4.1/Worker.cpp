#include "Worker.h"

Worker::~Worker(){
for (auto it = listOfDetails.begin(); it != listOfDetails.end(); ++it) {
	delete* it;
}
cout << "Worker dtor" << endl;
}

Worker::Worker(const string fio, int age, int BaseValue)
	:Personal(fio, age, BaseValue){
}

void Worker::AddDetail(const string name, int normRate, float factRate) {
	auto it = listOfDetails.end();
	listOfDetails.insert(it, new Detail(name, normRate, factRate));
}

float Worker::getAverageKoef() const {
	float averageKoef = 0.0f;
	float summaryKoef = 0.0f;
	if (listOfDetails.size() == 0) {
		throw Exception("A worker without parts is unacceptable.");
	}

	for (auto it = listOfDetails.begin(); it != listOfDetails.end(); ++it) {
		summaryKoef += (*it)->getKoef();
	}
	averageKoef = summaryKoef / listOfDetails.size();
	return averageKoef;
}

void Worker::printInfoAboutPersonal() const{
	cout << "---------------------------------------------" << endl;
	Personal::printInfoAboutPersonal();

	for (auto it = listOfDetails.begin(); it != listOfDetails.end(); ++it) {
		(*it)->toString();
	}
	cout << "---------------------------------------------" << endl;
	cout << endl;
}