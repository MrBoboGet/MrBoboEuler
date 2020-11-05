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
		std::vector<ttmath::Int<CFINTSIZE>> Br�ket = std::vector<ttmath::Int<CFINTSIZE>>(2);
		Br�ket[0] = 0;
		Br�ket[1] = 0;
		std::vector<int> ContinuedFraction = ContinuedFractionOfIntegerRoot(D);
		int IterationDepth = 1;
		//intern Variabel
		ttmath::Int<CFINTSIZE> D2 = D;
		while (Br�ket[0]*Br�ket[0] -D2*Br�ket[1]*Br�ket[1] != 1)
		{
			assert(Br�ket[0] >= 0 && Br�ket[0] >= 0);
			if (D == 61)
			{
				std::cout << Br�ket[0] << std::endl;
			}
			Br�ket = ContinuedFactorEvaluatorBigInt(ContinuedFraction, IterationDepth);
			IterationDepth += 1;
		}
		if (Br�ket[0] > MaxXValue)
		{
			MaxXValue = Br�ket[0];
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
		Vector2D Br�ket = Vector2D(0,0);
		std::vector<int> ContinuedFraction = ContinuedFractionOfIntegerRoot(D);
		int IterationDepth = 1;
		while (Br�ket.x*Br�ket.x -D*Br�ket.y*Br�ket.y != 1)
		{
			assert(Br�ket.x >= 0 && Br�ket.y >= 0);
			if (D == 61)
			{
					std::cout << Br�ket.x << std::endl;
			}
			Br�ket = ContinuedFactorEvaluator(ContinuedFraction, IterationDepth);
			IterationDepth += 1;
		}
		if (Br�ket.x > MaxXValue)
		{
			MaxXValue = Br�ket.x;
			DValue = D;
		}
	}
	return(DValue);
}
*/