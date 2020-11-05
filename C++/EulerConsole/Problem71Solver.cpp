#include <TalTeori.h>
#include <iostream>
#include <math.h>
#include <Vector2D.h>
int Problem71Solver(int d)
{
	Vector2D Fraction = Vector2D(3, 7);
	double FractionToCompare = Fraction.x / Fraction.y;
	double ClosestFraction = 0;
	int Numerator = 0;
	for (int i = 2; i < d+1; i++)
	{
		if (i % 1000 == 0)
		{
			std::cout << i << std::endl;
		}
		//går igenom  varje bråk som består av relativt prima tal, kollar om den är störra än den som är närmast
		for (double j = floor(i*(FractionToCompare)); j < i; j++)
		{
			if(j/i >= FractionToCompare)
			{
				break;
			}
			if (j/(double)i < FractionToCompare && j/(double)i > ClosestFraction)
			{
				if (gcd(j,i) == 1)
				{
					ClosestFraction = j / (double)i;
					Numerator = j;
				}
			}
		}
	}
	return(Numerator);
}