#include "Fraction.h"
#include <stdbool.h>
#include <iostream>
#include <cstdlib>

Fraction Fraction::Random(float min, float max, int seed){
	Fraction resultFraction;
		
	srand(seed);
	
	resultFraction.numerator = min + (float)rand() / RAND_MAX * (max - min);
	resultFraction.denominator = min + (float)rand() / RAND_MAX * (max - min);
	resultFraction.isNegative = rand() % 2 == 1 ? false : true;
	
	return resultFraction;
}

Fraction Fraction::Commondenominator(Fraction otherFraction){
	Fraction resultFraction;
			int CommonD = this->denominator * otherFraction.denominator;
			resultFraction.numerator = this->numerator*otherFraction.denominator;
			resultFraction.denominator = CommonD;
			resultFraction.isNegative = this->isNegative;
			
	return resultFraction;
}


Fraction Fraction::operator+(const Fraction& otherFraction){	
	AddOp(SUM);
	Fraction resultFraction;

	int IntSign1, IntSign2;
	
    IntSign1 = this->Translation();

	IntSign2 = otherFraction.Translation();
	
	resultFraction.numerator = IntSign1*this->numerator + IntSign2*otherFraction.numerator;
	resultFraction.denominator = this->denominator;

	if (resultFraction.numerator<0){
		resultFraction.isNegative = true;
		resultFraction.numerator = resultFraction.numerator*(-1);	
			}
	else{
		resultFraction.isNegative = false;
			}
	
	return resultFraction;
}

Fraction Fraction::operator-(const Fraction& otherFraction){
	AddOp(SUB);
	Fraction resultFraction;
	
			int IntSign1, IntSign2;
	
    		IntSign1 = this->Translation();

			IntSign2 = otherFraction.Translation();
	
			resultFraction.numerator = IntSign1*this->numerator -  IntSign2*otherFraction.numerator;
			resultFraction.denominator = this->denominator;
			
			if (resultFraction.numerator<0){
				resultFraction.isNegative = true;
				resultFraction.numerator = resultFraction.numerator*(-1);	
			}
			else{
				resultFraction.isNegative = false;
			}

	return resultFraction;
}

Fraction Fraction::operator*(const Fraction& otherFraction){
	AddOp(MULT);
	Fraction resultFraction;
	
		int IntSign1, IntSign2;
	
    		IntSign1 = this->Translation();

			IntSign2 = otherFraction.Translation();
	
			resultFraction.numerator = this->numerator*otherFraction.numerator;
			resultFraction.denominator = this->denominator*otherFraction.denominator;
			resultFraction.isNegative = IntSign1*IntSign2 < 0  ? true: false;
		
		return resultFraction;
}

Fraction Fraction::operator/(const Fraction& otherFraction){
	AddOp(DIV);
	Fraction resultFraction;	
	int IntSign1, IntSign2;
	
    		IntSign1 = this->Translation();

			IntSign2 = otherFraction.Translation();

			resultFraction.numerator = this->numerator*otherFraction.denominator;
			resultFraction.denominator = this->denominator*otherFraction.numerator;
			resultFraction.isNegative = IntSign1*IntSign2 < 0  ? true: false;
			
	return resultFraction;
}

int Fraction::operator==(const Fraction& otherFraction){
	AddOp(COMP);	
	int Comparison;
	int IntSign1, IntSign2;
	
    		IntSign1 = this->Translation();

			IntSign2 = otherFraction.Translation();
	
			if (IntSign1*this->numerator >  IntSign2*otherFraction.numerator){
				Comparison = 1;
			}
			else if (IntSign1*this->numerator <  IntSign2*otherFraction.numerator){
				Comparison = -1;
			}
			else
				Comparison = 0;

	return Comparison;
}
