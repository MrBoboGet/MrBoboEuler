#include <TalTeori.h>
#include <unordered_map>
#include <iostream>
int Problem87Solver(int BelowWhichNumber)
{
	auto Primtalen = PrimeGenerator(sqrt(BelowWhichNumber));
	int PrimtalSize = Primtalen.size();
	std::unordered_map<int, int> UnikaTal = std::unordered_map<int, int>(0);
	int Termer[] = { 0,0,0 };
	for (int i = 0; i < PrimtalSize; i++)
	{
		Termer[0] = pow(Primtalen[i], 2);
		if (Termer[0] > BelowWhichNumber)
		{
			break;
		}
		for (int j = 0; j < PrimtalSize; j++)
		{
			Termer[1] = pow(Primtalen[j], 3);
			if (Termer[0]+Termer[1] > BelowWhichNumber)
			{
				break;
			}
			for (int k = 0; k < PrimtalSize; k++)
			{
				Termer[2] = pow(Primtalen[k], 4);
				int Sum = Termer[0] + Termer[1] + Termer[2];
				if (Sum > BelowWhichNumber)
				{
					break;
				}
				else
				{
					UnikaTal[Sum] = Sum;
				}
			}
		}
	}
	return(UnikaTal.size());
}
/*
	for (int i = 0; i < BelowWhichNumber; i++)
	{
		//för varje tal checkar vi huruvida talet kan skrivas som summan av tre tal
		if (i%10000 == 0)
		{
			std::cout << i << "\n";
		}
		bool BreakKLoop = false;
		bool BreakJLoop = false;
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < i; k++)
			{
				for (int l = 0; l < i; l++)
				{
					int Termer[] = { 0,0,0 };
					Termer[0] = pow(Primtalen[j], 2);
					Termer[1] = pow(Primtalen[k], 3);
					Termer[2] = pow(Primtalen[l], 4);
					int Sum = Termer[0] + Termer[1] + Termer[2];
					if (Sum == i)
					{
						UnikaTal[i] = i;
						BreakJLoop = true;
						BreakKLoop = true;
						break;
					}
					if(Termer[0]+Termer[1] > i)
					{
						BreakKLoop = true;
						if (Termer[0] > i)
						{
							BreakJLoop = true;
						}
						break;
					}
					if (Sum > i)
					{
						break;
					}
				}
				if (BreakKLoop)
				{
					BreakKLoop = false;
					break;
				}
			}
			if (BreakJLoop)
			{
				BreakJLoop = false;
				break;
			}
		}
*/