#include "Fraction.h"
#include "stdlib.h"

Fraction createFraction(int numerator,int denominator,bool isNegative)
{
	Fraction fraction;
	fraction.numerator = numerator;
	fraction.denominator = denominator;
	fraction.isNegative = isNegative;
	return fraction;
}

void Commondenominator( Fraction* frac1, Fraction* frac2)
{
	int CommonD = frac1->denominator * frac2->denominator;
	Fraction Result1 = createFraction(frac1->numerator*frac2->denominator, CommonD, frac1->isNegative);
	Fraction Result2 = createFraction(frac2->numerator*frac1->denominator, CommonD, frac2->isNegative);
	
	*(frac1) = Result1;
	*(frac2) = Result2;
}

Fraction SumFractions(const Fraction* frac1, const Fraction* frac2)
{
	Fraction FracNew1 = *frac1;
	Fraction FracNew2 = *frac2;
	Commondenominator(&FracNew1, &FracNew2);
	
	Fraction SumStart;
	
	int IntSign1, IntSign2;
	
    IntSign1 = FracNew1.isNegative ? -1 : 1;

	IntSign2 = FracNew2.isNegative ? -1 : 1;
	
	SumStart.numerator = (IntSign1*FracNew1.numerator +  IntSign2*FracNew2.numerator);
	
	if (SumStart.numerator<0){
		SumStart.isNegative = true;
		SumStart.numerator = SumStart.numerator*(-1);	
	}
	else{
		SumStart.isNegative = false;
	}
	
	SumStart = createFraction(SumStart.numerator, FracNew1.denominator, SumStart.isNegative);
	
	return SumStart;
}

Fraction SubFractions(const Fraction* frac1, const Fraction* frac2)
{
	Fraction FracNew1 = *frac1;
	Fraction FracNew2 = *frac2;
	Commondenominator(&FracNew1, &FracNew2);
	
	Fraction SubStart;
	
	int IntSign1, IntSign2;
	
    IntSign1 = FracNew1.isNegative ? -1 : 1;

	IntSign2 = FracNew2.isNegative ? -1 : 1;
	
	SubStart.numerator = (IntSign1*FracNew1.numerator -  IntSign2*FracNew2.numerator);
	
	if (SubStart.numerator<0){
		SubStart.isNegative = true;
		SubStart.numerator = SubStart.numerator*(-1);	
	}
	else{
		SubStart.isNegative = false;
	}
	
	SubStart = createFraction(SubStart.numerator, FracNew1.denominator, SubStart.isNegative);

	
	return SubStart;
}

Fraction MultFractions(const Fraction* frac1, const Fraction* frac2)
{	
	int IntSign1, IntSign2;
	
    IntSign1 = frac1->isNegative ? -1 : 1;

	IntSign2 = frac2->isNegative ? -1 : 1;
	
	Fraction MultStart = createFraction(frac1->numerator*frac2->numerator, frac1->denominator*frac2->denominator, IntSign1*IntSign2 < 0  ? true: false);

	return MultStart;
}

Fraction DivFractions(const Fraction* frac1, const Fraction* frac2)
{	
	int IntSign1, IntSign2;
	
    IntSign1 = frac1->isNegative ? -1 : 1;

	IntSign2 = frac2->isNegative ? -1 : 1;
	
	Fraction DivStart = createFraction(frac1->numerator*frac2->denominator, frac1->denominator*frac2->numerator, IntSign1*IntSign2 < 0  ? true: false);

	return DivStart;
}

int CompFractions(const Fraction* frac1, const Fraction* frac2)
{	
	Fraction FracNew1 = *frac1;
	Fraction FracNew2 = *frac2;
	Commondenominator(&FracNew1, &FracNew2);
	
	Fraction CompStart;
	int Comparison;
	int IntSign1, IntSign2;
	
    IntSign1 = FracNew1.isNegative ? -1 : 1;

	IntSign2 = FracNew2.isNegative ? -1 : 1;
	
	if (IntSign1*FracNew1.numerator >  IntSign2*FracNew2.numerator){
		Comparison = 1;
	}
	else if (IntSign1*FracNew1.numerator <  IntSign2*FracNew2.numerator){
		Comparison = -1;
	}
	else
		Comparison = 0;

	return Comparison;
}

void PrintFraction(const Fraction* frac)
{
	printf("(%c%d / %d)",frac->isNegative ? '-': '+', frac->numerator, frac->denominator);	
}
