#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fraction.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Fraction fractions[4];
	Fraction Frac1;
	fractions[0] = Frac1;
	Fraction Frac2;
	fractions[1] = Frac2;
	
	printf("Enter the first fraction. \n");
	printf("Fraction isNegative? (1 or 0): ");
	scanf("%d", &fractions[0].isNegative);
	printf("Fraction numerator: ");
	scanf("%d", &fractions[0].numerator);
	printf("Fraction numerator: ");
	scanf("%d", &fractions[0].denominator);
	
	cout << "1st Fraction: " << endl;
	PrintFraction(&fractions[0]);
	printf("\n");
	
	printf("Enter a fraction for joint operations. \n");
	printf("Fraction isNegative? (1 or 0): ");
	scanf("%d", &fractions[1].isNegative);
	printf("Fraction numerator: ");
	scanf("%d", &fractions[1].numerator);
	printf("Fraction numerator: ");
	scanf("%d", &fractions[1].denominator);
	
	printf("2ed Fraction:");
	PrintFraction(&fractions[1]);
	printf("\n");
	
	fractions[2] = fractions[0];
	fractions[3] = fractions[1];
	
	Commondenominator(&fractions[2],&fractions[3]);

	
	printf("Available features: \n");
	printf("1 - Addition of two fractions. \n");
	printf("2 - Subtraction of two fractions. \n");
	printf("3 - Multiplication of two fractions. \n");
	printf("4 - Division of two fractions. \n");
	printf("5 - Bringing two transmitted fractions to a common denominator. \n");
	printf("6 - Comparing two fractions, as a result an integer value is returned: -1 (less than), 1(greater than), 0 (equal). \n");

	int choice;
	printf("Choose a function with a number from 1 to 6: \n");
	scanf("%d", &choice);
	
		if (choice == 1){
			Fraction Sum = SumFractions(&fractions[0],&fractions[1]);
			printf("Sum:");
			PrintFraction(&fractions[0]);
			printf("+");
			PrintFraction(&fractions[1]);
			printf("=");
			PrintFraction(&Sum);
			printf("\n");
		}
		else if(choice == 2){
			Fraction Sub = SubFractions(&fractions[0],&fractions[1]);
			printf("Subtraction:");
			PrintFraction(&fractions[0]);
			printf("-");
			PrintFraction(&fractions[1]);
			printf("=");
			PrintFraction(&Sub);
			printf("\n");
		}
		else if(choice == 3){
			Fraction Mult = MultFractions(&fractions[0],&fractions[1]);
			printf("Multiplication:");
			PrintFraction(&fractions[0]);
			printf("*");
			PrintFraction(&fractions[1]);
			printf("=");
			PrintFraction(&Mult);
			printf("\n");
		}
		else if(choice == 4){
			Fraction Div = DivFractions(&fractions[0],&fractions[1]);
			printf("Division:");
			PrintFraction(&fractions[0]);
			printf("/");
			PrintFraction(&fractions[1]);
			printf("=");
			PrintFraction(&Div);
			printf("\n");
		}
		else if(choice == 5){
			printf("Commondenominator 1:");
			PrintFraction(&fractions[2]);
			printf("\n");
			printf("Commondenominator 2:");
			PrintFraction(&fractions[3]);
			printf("\n");
		}
		else if(choice == 6){
			int Comp = CompFractions(&fractions[0],&fractions[1]);
			printf("Comparison: ");
			PrintFraction(&fractions[0]);
			printf("<=>");
			PrintFraction(&fractions[1]);
			printf("=%d \n", Comp);
		}
		else {
			printf("There is no such choice! Start over. \n");
		}
	return 0;
}
