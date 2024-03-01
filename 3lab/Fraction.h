#pragma once
#include "Object.h"
#include <stdbool.h>
#include <iostream>

using namespace std;

class Fraction: public Object
{
	private:
			int numerator;
			int denominator;
			bool isNegative;
	public:
			int Translation () const{
					int IntSign;
    				IntSign = this->isNegative ? -1 : 1;
			return IntSign;
			}	
			
			Fraction(int numerator,int denominator, bool isNegative){
					this->numerator = numerator;
					this->denominator = denominator;
					this->isNegative = isNegative;					
			}	
		
			Fraction() {
			}
			
			static Fraction Random(float min, float max, int seed = 0);
			
			int GetNum() const {
				return numerator;
			}
			int GetDen() const {
				return denominator;
			}
			bool GetisNeg() const {
				return isNegative;
			}
			
			void SetNum( int _numerator){
				numerator = _numerator;
			}
			
			void SetDen(int _denominator){
				denominator = _denominator;
			}
			
			void SetisNeg(bool _isNegative){
				isNegative = _isNegative;
			}
			
			int Comparison(Fraction otherFraction){
				return (this->numerator == otherFraction.numerator) == (this->denominator == otherFraction.denominator) == (this->isNegative == otherFraction.isNegative);
			}
			
			Fraction operator+(const Fraction& otherFraction);
			Fraction operator-(const Fraction& otherFraction);
			Fraction operator*(const Fraction& otherFraction);
			Fraction operator/(const Fraction& otherFraction);
			int operator==(const Fraction& otherFraction);
			
			void PrintFraction() const{
			this->isNegative ? cout << '-': cout << '+';
			cout << '(' << this->numerator << '/' << this->denominator << ')' << endl;
			}
			
			Fraction Commondenominator(Fraction otherFraction);
};
