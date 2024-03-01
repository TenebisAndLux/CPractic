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
	
	updateTestResult(RandomFractionsTest1());
	updateTestResult(RandomFractionsTest2());
	updateTestResult(PrintTotalInfoTestA());
	updateTestResult(PrintTotalInfoTestT());
	updateTestResult(PrintOpTest());
	
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
	cout << endl;
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
	Fraction resultFraction = ComFraction1+(ComFraction2);

	
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
	Fraction resultFraction = ComFraction1+(ComFraction2);

	
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
	Fraction resultFraction = ComFraction1-(ComFraction2);

	
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
	Fraction resultFraction = ComFraction1-(ComFraction2);

	
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
	Fraction resultFraction = Fraction1*(Fraction2);

	
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
	Fraction resultFraction = Fraction1*(Fraction2);

	
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
	Fraction resultFraction = Fraction1/(Fraction2);

	
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
	int Comparison = ComFraction1==ComFraction2;

	//result
	return assertValueVal(TestComparison,Comparison);
}

bool FractionTest::RandomFractionsTest1(){
	cout << "(1)Random check:" << endl;
	
	int RightNumerator = 5;
	int RightDenominator = 1;
	bool RightIsNegative = false;
	Fraction RightFraction = Fraction(RightNumerator,RightDenominator,RightIsNegative);
	
	int LeftNumerator = 5;
	int LeftDenominator = 1;
	bool LeftIsNegative = true;
	Fraction LeftFraction = Fraction(LeftNumerator,LeftDenominator,LeftIsNegative);
	
	//must be
	int TestComparison = 0;
	
	//do
	Fraction RanFraction = RanFraction.Random(1, 5, 1);
	
	Fraction ComRanFraction = RanFraction.Commondenominator(RightFraction);
	Fraction ComRightFraction = RightFraction.Commondenominator(RanFraction);
	Fraction ComLeftFraction = LeftFraction.Commondenominator(RanFraction);
	
	int RightComparison = ComRanFraction==ComRightFraction;
	int LeftComparison = ComRanFraction==ComLeftFraction;
	
	int Comparison = RightComparison+LeftComparison;
	
	//result
	return assertValueVal(TestComparison,Comparison);
}

bool FractionTest::RandomFractionsTest2(){
	cout << "(2)Random check:" << endl;
	
	int RightNumerator = 17;
	int RightDenominator = 5;
	bool RightIsNegative = false;
	Fraction RightFraction = Fraction(RightNumerator,RightDenominator,RightIsNegative);
	
	int LeftNumerator = 17;
	int LeftDenominator = 5;
	bool LeftIsNegative = true;
	Fraction LeftFraction = Fraction(LeftNumerator,LeftDenominator,LeftIsNegative);
	
	//must be
	int TestComparison = 0;
	
	//do
	Fraction RanFraction = RanFraction.Random(5, 17, 1);
	
	Fraction ComRanFraction = RanFraction.Commondenominator(RightFraction);
	Fraction ComRightFraction = RightFraction.Commondenominator(RanFraction);
	Fraction ComLeftFraction = LeftFraction.Commondenominator(RanFraction);
	
	int RightComparison = ComRanFraction==ComRightFraction;
	int LeftComparison = ComRanFraction==ComLeftFraction;
	
	int Comparison = RightComparison+LeftComparison;
	
	//result
	return assertValueVal(TestComparison,Comparison);
}

bool FractionTest::PrintTotalInfoTestA(){
	cout << "(Active Objects)Checking the output of all information:" << endl;
	
	Fraction SFraction;
	SFraction.PrintTotalInfo();
	Fraction Test1 = Test1.Random(1, 100, 1);
	Fraction Test2 = Test2.Random(1, 100, 1);
	Fraction Test3 = Test3.Random(1, 100, 1);
	Fraction Test4 = Test4.Random(1, 100, 1);
	Fraction Test5 = Test5.Random(1, 100, 1);
	//must be
	int TestAObj = 6;
	cout<< "there was 1 object and 5 objects were added"<<endl;
	//do
	int EndAC = SFraction.GetAObj();
	SFraction.PrintTotalInfo();
	
	return assertValueVal(TestAObj,EndAC);
}

bool FractionTest::PrintTotalInfoTestT(){
	cout << "(Total Objects)Checking the output of all information:" << endl;
	
	Fraction SFraction;
	int StarTC = SFraction.GetTObj();
	SFraction.PrintTotalInfo();
	Fraction Test1 = Test1.Random(1, 100, 1);
	Fraction Test2 = Test2.Random(1, 100, 1);
	Fraction Test3 = Test3.Random(1, 100, 1);
	Fraction Test4 = Test4.Random(1, 100, 1);
	Fraction Test5 = Test5.Random(1, 100, 1);
	
	//must be
	int TesCTObj = 5;
	cout<< "Added 5 objects"<<endl;
	
	//do
	int EndTC = SFraction.GetTObj();
	int ResCTObj = EndTC - StarTC;
	SFraction.PrintTotalInfo();
	
	return assertValueVal(TesCTObj,ResCTObj);
}

bool FractionTest::PrintOpTest(){
	cout << "Checking the output of information about operators:" << endl;
	
	//must be
	int TestCOp = 4;
	
	//do
	Fraction RanFraction1 = RanFraction1.Random(5, 17, 0);
	
	Fraction RanFraction2 = RanFraction2.Random(1, 15, 0);
	
	Fraction ResultFrac = RanFraction1+RanFraction2;
	ResultFrac = RanFraction1-RanFraction2;
	ResultFrac = RanFraction1*RanFraction2;
	ResultFrac = RanFraction1/RanFraction2;
	
	const char* Mass[]={"SUM","SUB","MULT","DIV","COMP"};
	RanFraction1.PrintOp(Mass);
	int COp = RanFraction1.GetCOp();
	
	return assertValueVal(TestCOp,COp);
}
