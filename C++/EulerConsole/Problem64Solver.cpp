#include <ContinuedFractions.h>
int Problem64Solver(int n)
{
	int AmountOfOddPeriods = 0;
	for (int i = 1; i < n+1; i++)
	{
		float a = floor(sqrt(i));
		if (a *a == i)
		{
			//std::cout << i <<" is i"<< std::endl;
			continue;
		}
		std::vector<int> Fractionen = ContinuedFractionOfIntegerRoot(i);
		//std::cout << Fractionen.size()-1 << " "<<i<<std::endl;
		if ((Fractionen.size() -1) % 2 != 0 || (Fractionen.size() == 3 && Fractionen[1]== Fractionen[2]))
		{
			AmountOfOddPeriods += 1;
		}
	}
	return(AmountOfOddPeriods);
}