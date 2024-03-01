#include "Object.h"
#include <iostream>

int Object::totalObj = 0;
int Object::activeObj = 0;

Object::Object()
{
	++totalObj;
	++activeObj;
}

Object::~Object()
{
	--activeObj;
	ClearOp();
}

void Object::ClearOp()
{
	delete[] operations;
	operations = nullptr;
	operationsCount = 0;
}

void Object::PrintTotalInfo()
{
	cout << endl;
	cout << "Total objects: " << totalObj << endl;
	cout << "Active objects: " << activeObj << endl;
	cout << endl;
}

void Object::PrintOp(const char** Present) const
{
	cout << "Operations: ";
	for (int i = 0; i < operationsCount; ++i)
	{
		cout << Present[operations[i]]<< " ";
	}
	cout << endl;
}

Object::Object(const Object& otherFraction)
	: operationsCount(otherFraction.operationsCount)
{
	++totalObj;
	++activeObj;

	operations = new int[operationsCount];
	memcpy(operations, otherFraction.operations,sizeof(int)*operationsCount);
}

Object& Object::operator=(const Object& otherFraction)
{
	if (this == &otherFraction)
	{
		return *this;
	}

	ClearOp();

	operationsCount = otherFraction.operationsCount;

	operations = new int[operationsCount];
	memcpy(operations, otherFraction.operations, operationsCount);

	return *this;
}

void Object::AddOp(int Operations)
{
	++operationsCount;

	int* newOperations = new int[operationsCount];
	memcpy(newOperations,operations, sizeof(int) * (operationsCount - 1));
	newOperations[operationsCount - 1] = Operations;

	delete[] operations;
	operations = newOperations;
}
