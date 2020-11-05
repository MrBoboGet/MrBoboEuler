#include <ContinuedFractions.h>
#include<iostream>
#include <assert.h>
int Problem66Solver()
{
	ttmath::Int<CFINTSIZE> MaxXValue = 0;
	int DValue = 0;
	for (int D = 2; D <= 1000; D++)
	{
		if (D == floor(sqrt(D))* floor(sqrt(D)))
		{
			continue;
		}
		std::cout << D << std::endl;
		std::vector<ttmath::Int<CFINTSIZE>> Bråket = std::vector<ttmath::Int<CFINTSIZE>>(2);
		Bråket[0] = 0;
		Bråket[1] = 0;
		std::vector<int> ContinuedFraction = ContinuedFractionOfIntegerRoot(D);
		int IterationDepth = 1;
		//intern Variabel
		ttmath::Int<CFINTSIZE> D2 = D;
		while (Bråket[0]*Bråket[0] -D2*Bråket[1]*Bråket[1] != 1)
		{
			assert(Bråket[0] >= 0 && Bråket[0] >= 0);
			if (D == 61)
			{
				std::cout << Bråket[0] << std::endl;
			}
			Bråket = ContinuedFactorEvaluatorBigInt(ContinuedFraction, IterationDepth);
			IterationDepth += 1;
		}
		if (Bråket[0] > MaxXValue)
		{
			MaxXValue = Bråket[0];
			DValue = D;
		}
	}
	return(DValue);
}
/*
int Problem66Solver()
{
	int MaxXValue = 0;
	int DValue = 0;
	for (int D = 2; D <= 1000; D++)
	{
		if (D == floor(sqrt(D))* floor(sqrt(D)))
		{
			continue;
		}
		std::cout << D << std::endl;
		Vector2D Bråket = Vector2D(0,0);
		std::vector<int> ContinuedFraction = ContinuedFractionOfIntegerRoot(D);
		int IterationDepth = 1;
		while (Bråket.x*Bråket.x -D*Bråket.y*Bråket.y != 1)
		{
			assert(Bråket.x >= 0 && Bråket.y >= 0);
			if (D == 61)
			{
					std::cout << Bråket.x << std::endl;
			}
			Bråket = ContinuedFactorEvaluator(ContinuedFraction, IterationDepth);
			IterationDepth += 1;
		}
		if (Bråket.x > MaxXValue)
		{
			MaxXValue = Bråket.x;
			DValue = D;
		}
	}
	return(DValue);
}
*/