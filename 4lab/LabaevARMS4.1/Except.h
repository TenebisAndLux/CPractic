#pragma once
#include<iostream>
#include<stdlib.h>
#include <string>

using namespace std;

class Exception{
	const string info;
public:
	Exception(const string info) : info(info){
	}
	const string getInfo() {
		return info;
	}
};