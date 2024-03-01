#pragma once
#include <stdbool.h>

typedef struct
{
	int numerator;
	int denominator;
	bool isNegative;
} Fraction;


Fraction createFraction(int numerator,int denominator,bool isNegative);

void Commondenominator(Fraction* frac1,Fraction* frac2);

Fraction SumFractions(const Fraction* frac1, const Fraction* frac2);

Fraction SubFractions(const Fraction* frac1, const Fraction* frac2);

Fraction MultFractions(const Fraction* frac1, const Fraction* frac2);

Fraction DivFractions(const Fraction* frac1, const Fraction* frac2);

int CompFractions(const Fraction* frac1, const Fraction* frac2);

void PrintFraction(const Fraction* frac);

