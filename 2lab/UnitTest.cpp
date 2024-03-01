#include "UnitTest.h"

void FractionTest::run()
{
	startTest();
	
	updateTestResult(CommondenominatorTest1());
	updateTestResult(CommondenominatorTest2());
	updateTestResult(SumFractionsTest1());
	updateTestResult(SumFractionsTest2());
	updateTestResult(SubFractionsTest1());
	updateTestResult(SubFractionsTest2());
	updateTestResult(DivFractionsTest());
	updateTestResult(MultFractionsTest1());
	updateTestResult(MultFractionsTest2());
	updateTestResult(CompFractionsTest());
	
	printTestResults();
}

void FractionTest::printTestResults()
{
	cout << "Test results passed: " << testPassed << " of " << testTotal << endl;
}

void FractionTest::updateTestResult(bool passed)
{
	if(passed) 
		++testPassed, cout << "Success!" << endl; 
	else 
		cout << "Failure!" << endl;
}

bool FractionTest::assertValueVal(int actual, int expected)
{
	cout << "Expected Result: " << expected << endl;
	cout << "Actual result: " << actual << endl;
	return actual == expected;
}

bool FractionTest::assertValueFrac(Fraction actual, Fraction expected)
{
	cout << "Expected Result: ";
	expected.PrintFraction();
	cout << "Actual result: "; 
	actual.PrintFraction();
	return actual.Comparison(expected);
}

bool FractionTest::CommondenominatorTest1(){
	cout << "(1)Testing the Commondenominator: fractions must be reduced to a common denominator" << endl;
	
	int arrangeNumerator = 28;
	int arrangeDenominator = 12;
	bool arrangeIsNegative = true;
	
	int referenceNumerator1 = 7;
	int referenceDenominator1 = 3;
	bool referenceIsNegative1 = true;
	Fraction Fraction1 = Fraction(referenceNumerator1,referenceDenominator1,referenceIsNegative1);
	
	int referenceNumerator2 = 3;
	int referenceDenominator2 = 4;
	bool referenceIsNegative2 = false;
	Fraction Fraction2 = Fraction(referenceNumerator2,referenceDenominator2,referenceIsNegative2);
	
	//must be
	Fraction TestFraction = Fraction(arrangeNumerator,arrangeDenominator,arrangeIsNegative);
	
	//do
	Fraction ComFraction1 = Fraction1.Commondenominator(Fraction2);
	Fraction ComFraction2 = Fraction2.Commondenominator(Fraction1);
	
	//result
	return assertValueFrac(TestFraction,ComFraction1);
}

bool FractionTest::CommondenominatorTest2(){
	cout << "(2)Testing the Commondenominator: fractions must be reduced to a common denominator" << endl;
	
	int arrangeNumerator = 9;
	int arrangeDenominator = 12;
	bool arrangeIsNegative = false;
	
	int referenceNumerator1 = 7;
	int referenceDenominator1 = 3;
	bool referenceIsNegative1 = true;
	Fraction Fraction1 = Fraction(referenceNumerator1,referenceDenominator1,referenceIsNegative1);
	
	int referenceNumerator2 = 3;
	int referenceDenominator2 = 4;
	bool referenceIsNegative2 = false;
	Fraction Fraction2 = Fraction(referenceNumerator2,referenceDenominator2,referenceIsNegative2);
	
	//must be
	Fraction TestFraction = Fraction(arrangeNumerator,arrangeDenominator,arrangeIsNegative);
	
	//do
	Fraction ComFraction1 = Fraction1.Commondenominator(Fraction2);
	Fraction ComFraction2 = Fraction2.Commondenominator(Fraction1);
	
	//result
	return assertValueFrac(TestFraction,ComFraction2);
}

bool FractionTest::SumFractionsTest1(){
	cout << "(1) Sum Check: Calculations must be correct." << endl;
	
	int arrangeNumerator = 19;
	int arrangeDenominator = 12;
	bool arrangeIsNegative = true;
	
	int referenceNumerator1 = 7;
	int referenceDenominator1 = 3;
	bool referenceIsNegative1 = true;
	Fraction Fraction1 = Fraction(referenceNumerator1,referenceDenominator1,referenceIsNegative1);
	
	int referenceNumerator2 = 3;
	int referenceDenominator2 = 4;
	bool referenceIsNegative2 = false;
	Fraction Fraction2 = Fraction(referenceNumerator2,referenceDenominator2,referenceIsNegative2);
	
	Fraction ComFraction1 = Fraction1.Commondenominator(Fraction2);
	Fraction ComFraction2 = Fraction2.Commondenominator(Fraction1);
	
	//must be
	Fraction TestFraction = Fraction(arrangeNumerator,arrangeDenominator,arrangeIsNegative);
	
	//do
	Fraction resultFraction = ComFraction1.SumFractions(ComFraction2);

	
	//result
	return assertValueFrac(TestFraction,resultFraction);
}

bool FractionTest::SumFractionsTest2(){
	cout << "(2) Sum Check: Calculations must be correct." << endl;
	
	int arrangeNumerator = 37;
	int arrangeDenominator = 12;
	bool arrangeIsNegative = true;
	
	int referenceNumerator1 = 7;
	int referenceDenominator1 = 3;
	bool referenceIsNegative1 = true;
	Fraction Fraction1 = Fraction(referenceNumerator1,referenceDenominator1,referenceIsNegative1);
	
	int referenceNumerator2 = 3;
	int referenceDenominator2 = 4;
	bool referenceIsNegative2 = true;
	Fraction Fraction2 = Fraction(referenceNumerator2,referenceDenominator2,referenceIsNegative2);
	
	Fraction ComFraction1 = Fraction1.Commondenominator(Fraction2);
	Fraction ComFraction2 = Fraction2.Commondenominator(Fraction1);
	
	//must be
	Fraction TestFraction = Fraction(arrangeNumerator,arrangeDenominator,arrangeIsNegative);
	
	//do
	Fraction resultFraction = ComFraction1.SumFractions(ComFraction2);

	
	//result
	return assertValueFrac(TestFraction,resultFraction);
}

bool FractionTest::SubFractionsTest1(){
	cout << "(1) Subtraction check: Calculations must be correct." << endl;
	
	int arrangeNumerator = 19;
	int arrangeDenominator = 12;
	bool arrangeIsNegative = true;
	
	int referenceNumerator1 = 7;
	int referenceDenominator1 = 3;
	bool referenceIsNegative1 = true;
	Fraction Fraction1 = Fraction(referenceNumerator1,referenceDenominator1,referenceIsNegative1);
	
	int referenceNumerator2 = 3;
	int referenceDenominator2 = 4;
	bool referenceIsNegative2 = true;
	Fraction Fraction2 = Fraction(referenceNumerator2,referenceDenominator2,referenceIsNegative2);

	Fraction ComFraction1 = Fraction1.Commondenominator(Fraction2);
	Fraction ComFraction2 = Fraction2.Commondenominator(Fraction1);
	
	//must be
	Fraction TestFraction = Fraction(arrangeNumerator,arrangeDenominator,arrangeIsNegative);
	
	//do
	Fraction resultFraction = ComFraction1.SubFractions(ComFraction2);

	
	//result
	return assertValueFrac(TestFraction,resultFraction);
}

bool FractionTest::SubFractionsTest2(){
	cout << "(2) Subtraction check: Calculations must be correct." << endl;
	
	int arrangeNumerator = 37;
	int arrangeDenominator = 12;
	bool arrangeIsNegative = true;
	
	int referenceNumerator1 = 7;
	int referenceDenominator1 = 3;
	bool referenceIsNegative1 = true;
	Fraction Fraction1 = Fraction(referenceNumerator1,referenceDenominator1,referenceIsNegative1);
	
	int referenceNumerator2 = 3;
	int referenceDenominator2 = 4;
	bool referenceIsNegative2 = false;
	Fraction Fraction2 = Fraction(referenceNumerator2,referenceDenominator2,referenceIsNegative2);

	Fraction ComFraction1 = Fraction1.Commondenominator(Fraction2);
	Fraction ComFraction2 = Fraction2.Commondenominator(Fraction1);
	
	//must be
	Fraction TestFraction = Fraction(arrangeNumerator,arrangeDenominator,arrangeIsNegative);
	
	//do
	Fraction resultFraction = ComFraction1.SubFractions(ComFraction2);

	
	//result
	return assertValueFrac(TestFraction,resultFraction);
}

bool FractionTest::MultFractionsTest1(){
	cout << "(1) Multiplication check: Calculations must be correct." << endl;
	
	int arrangeNumerator = 21;
	int arrangeDenominator = 12;
	bool arrangeIsNegative = true;
	
	int referenceNumerator1 = 7;
	int referenceDenominator1 = 3;
	bool referenceIsNegative1 = true;
	Fraction Fraction1 = Fraction(referenceNumerator1,referenceDenominator1,referenceIsNegative1);
	
	int referenceNumerator2 = 3;
	int referenceDenominator2 = 4;
	bool referenceIsNegative2 = false;
	Fraction Fraction2 = Fraction(referenceNumerator2,referenceDenominator2,referenceIsNegative2);
	
	//must be
	Fraction TestFraction = Fraction(arrangeNumerator,arrangeDenominator,arrangeIsNegative);
	
	//do
	Fraction resultFraction = Fraction1.MultFractions(Fraction2);

	
	//result
	return assertValueFrac(TestFraction,resultFraction);
}

bool FractionTest::MultFractionsTest2(){
	cout << "(2) Multiplication check: Calculations must be correct." << endl;
	
	int arrangeNumerator = 21;
	int arrangeDenominator = 12;
	bool arrangeIsNegative = false;
	
	int referenceNumerator1 = 7;
	int referenceDenominator1 = 3;
	bool referenceIsNegative1 = true;
	Fraction Fraction1 = Fraction(referenceNumerator1,referenceDenominator1,referenceIsNegative1);
	
	int referenceNumerator2 = 3;
	int referenceDenominator2 = 4;
	bool referenceIsNegative2 = true;
	Fraction Fraction2 = Fraction(referenceNumerator2,referenceDenominator2,referenceIsNegative2);
	
	//must be
	Fraction TestFraction = Fraction(arrangeNumerator,arrangeDenominator,arrangeIsNegative);
	
	//do
	Fraction resultFraction = Fraction1.MultFractions(Fraction2);

	
	//result
	return assertValueFrac(TestFraction,resultFraction);
}

bool FractionTest::DivFractionsTest(){
	cout << "(1) Division check: Calculations must be correct." << endl;
	
	int arrangeNumerator = 9;
	int arrangeDenominator = 28;
	bool arrangeIsNegative = true;
	
	int referenceNumerator1 = 7;
	int referenceDenominator1 = 3;
	bool referenceIsNegative1 = false;
	Fraction Fraction1 = Fraction(referenceNumerator1,referenceDenominator1,referenceIsNegative1);
	
	int referenceNumerator2 = 3;
	int referenceDenominator2 = 4;
	bool referenceIsNegative2 = true;
	Fraction Fraction2 = Fraction(referenceNumerator2,referenceDenominator2,referenceIsNegative2);
	
	//must be
	Fraction TestFraction = Fraction(arrangeNumerator,arrangeDenominator,arrangeIsNegative);
	
	//do
	Fraction resultFraction = Fraction1.DivFractions(Fraction2);

	
	//result
	return assertValueFrac(TestFraction,resultFraction);
}

bool FractionTest::CompFractionsTest(){
	cout << "(1) Comparison check: should output 1." << endl;
	
	int referenceNumerator1 = 7;
	int referenceDenominator1 = 3;
	bool referenceIsNegative1 = false;
	Fraction Fraction1 = Fraction(referenceNumerator1,referenceDenominator1,referenceIsNegative1);
	
	int referenceNumerator2 = 3;
	int referenceDenominator2 = 4;
	bool referenceIsNegative2 = true;
	Fraction Fraction2 = Fraction(referenceNumerator2,referenceDenominator2,referenceIsNegative2);

	Fraction ComFraction1 = Fraction1.Commondenominator(Fraction2);
	Fraction ComFraction2 = Fraction2.Commondenominator(Fraction1);
	
	//must be
	int TestComparison = 1;
	
	//do
	int Comparison = ComFraction1.CompFractions(ComFraction2);

	//result
	return assertValueVal(TestComparison,Comparison);
}

