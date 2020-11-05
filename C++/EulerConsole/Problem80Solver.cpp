#include <ContinuedFractions.h>
#include <ttmathbig.h>
#include <assert.h>
#define ExpSize 128
#define MantSize 128
int Problem80Solver(int NumberOfNaturalNumbers, int NumberOfExpansions)
{
	int TotalSumma = 0;
	for (int i = 1; i <= NumberOfNaturalNumbers; i++)
	{	
		//först kollar vi att det faktiskt är det inte är ett kvadrat tal
		float a = round(sqrt(i));
		if (a*a == i)
		{
			continue;
		}
		std::vector<int> ContinuedFractionen = ContinuedFractionOfIntegerRoot(i);
		auto Bråket = ContinuedFactorEvaluatorBigInt(ContinuedFractionen, NumberOfExpansions);
		ttmath::Big<ExpSize, MantSize> Täljare, Nämnare, BråkVärdet;
		Täljare = Bråket[0];
		Nämnare = Bråket[1];
		BråkVärdet = Täljare / Nämnare;
		std::string BråkStringen = BråkVärdet.ToString();
		//std::cout << BråkStringen << std::endl;
		int BråkSumman = 0;
		assert(BråkStringen.length() > 102);
		assert(Täljare > 0);
		assert(Nämnare > 0);
		for (int j = 0; j < BråkStringen.length(); j++)
		{
			if (!(j < 101))
			{
				break;
			}
			if (BråkStringen[j] != '.')
			{
				BråkSumman += ((int)BråkStringen[j]) - 48;
			}
		}
		TotalSumma += BråkSumman;
	}
	return(TotalSumma);
}