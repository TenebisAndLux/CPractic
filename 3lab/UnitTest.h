#pragma once

#include "Fraction.h"
#include <stdbool.h>
#include <iostream>

class FractionTest{
	const int testTotal = 15;
	int testPassed = 0;
	
	void startTest() { testPassed = 0; }
	bool assertValueFrac(Fraction actual, Fraction expected);
	bool assertValueVal(int actual, int expected);
	void updateTestResult(bool passed);
	void printTestResults();
	
	bool CommondenominatorTest1();
	bool CommondenominatorTest2();
	bool SumFractionsTest1();
	bool SumFractionsTest2();
	bool SubFractionsTest1();
	bool SubFractionsTest2();
	bool MultFractionsTest1();
	bool MultFractionsTest2();
	bool DivFractionsTest();
	bool CompFractionsTest();
	
	bool RandomFractionsTest1();
	bool RandomFractionsTest2();
	bool PrintTotalInfoTestA();
	bool PrintTotalInfoTestT();
	bool PrintOpTest();

	 
	public:
	
	
	void run();	
};
