#include <TalTeori.h>
int Problem69Solver(int n) 
{
	double MaxKvot = 0;
	int ReturVärde = 0;
	for (int i = 2; i < n+1; i++)
	{
		double Kvot = i / (double)phi(i);
		if (Kvot > MaxKvot)
		{
			MaxKvot = Kvot;
			ReturVärde = i;
		}
	}
	return(ReturVärde);
}