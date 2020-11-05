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
		//f�rst kollar vi att det faktiskt �r det inte �r ett kvadrat tal
		float a = round(sqrt(i));
		if (a*a == i)
		{
			continue;
		}
		std::vector<int> ContinuedFractionen = ContinuedFractionOfIntegerRoot(i);
		auto Br�ket = ContinuedFactorEvaluatorBigInt(ContinuedFractionen, NumberOfExpansions);
		ttmath::Big<ExpSize, MantSize> T�ljare, N�mnare, Br�kV�rdet;
		T�ljare = Br�ket[0];
		N�mnare = Br�ket[1];
		Br�kV�rdet = T�ljare / N�mnare;
		std::string Br�kStringen = Br�kV�rdet.ToString();
		//std::cout << Br�kStringen << std::endl;
		int Br�kSumman = 0;
		assert(Br�kStringen.length() > 102);
		assert(T�ljare > 0);
		assert(N�mnare > 0);
		for (int j = 0; j < Br�kStringen.length(); j++)
		{
			if (!(j < 101))
			{
				break;
			}
			if (Br�kStringen[j] != '.')
			{
				Br�kSumman += ((int)Br�kStringen[j]) - 48;
			}
		}
		TotalSumma += Br�kSumman;
	}
	return(TotalSumma);
}