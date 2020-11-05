#include <vector>
#include <ContinuedFractions.h>
int Problem65Solver(int n)
{
	//bråket som vi vår eftern den n:te convergeten
	int k = 1;
	std::vector<int> Konvergenten = std::vector<int>(2);
	Konvergenten[0] = 2;
	Konvergenten[1] = 1;
	for (int i = 0; i < n-2; i++)
	{
		if (i%3 == 0)
		{
			Konvergenten.push_back(k * 2);
			k += 1;
		}
		else
		{
			Konvergenten.push_back(1);
		}
	}
	//nu ska vi fkatiskt få talet
	auto Bråkat = ContinuedFactorEvaluatorBigInt(Konvergenten, n-1)[0];
	//vi vill se vad talet är summerat
	std::string NominatorString = Bråkat.ToString();
	int Sum = 0;
	for (int i = 0; i < NominatorString.size(); i++)
	{
		Sum+= (int)NominatorString[i] - 48;
	}
	return(Sum);
}