#pragma once
#include <stdbool.h>
#include <iostream>

using namespace std;


class Fraction
{
	private:
			int numerator;
			int denominator;
			bool isNegative;
	public:
			int Translation (){
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
			
			int GetNum(){
				return numerator;
			}
			int GetDen(){
				return denominator;
			}
			bool GetisNeg(){
				return isNegative;
			}
			
			void SetNum( int numerator){
				_numerator = numerator;
			}
			
			void SetDen(int denominator){
				_denominator = denominator;
			}
			
			void SetisNeg(bool isNegative){
				_isNegative = isNegative;
			}
			
			int Comparison(Fraction otherFraction){
				return (this->numerator == otherFraction.numerator) == (this->denominator == otherFraction.denominator) == (this->isNegative == otherFraction.isNegative);
			}
			
			void PrintFraction(){
			this->isNegative ? cout << '-': cout << '+';
			cout << '(' << this->numerator << '/' << this->denominator << ')' << endl;
			}
			
			Fraction Commondenominator(Fraction otherFraction);
			Fraction SumFractions(Fraction otherFraction);
			Fraction SubFractions(Fraction otherFraction);
			Fraction MultFractions(Fraction otherFraction);
			Fraction DivFractions(Fraction otherFraction);
			int CompFractions(Fraction otherFraction);
};
