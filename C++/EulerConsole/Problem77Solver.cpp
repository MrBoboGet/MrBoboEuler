#include <vector>
#include <TalTeori.h>
inline int RekursivKombinationKollare(std::vector<long long>* PrimtalsLista, int Tal,int LastPrimeIndex)
{
	int AntalKombinationer = 0;
	for (int i = LastPrimeIndex; i < PrimtalsLista->size(); i++)
	{
		if (Tal - (*PrimtalsLista)[i] > 0)
		{
			AntalKombinationer += RekursivKombinationKollare(PrimtalsLista, Tal - (*PrimtalsLista)[i],i);
		}
		if (Tal - (*PrimtalsLista)[i] == 0)
		{
			AntalKombinationer += 1;
		}
		if (Tal - (*PrimtalsLista)[i] < 0)
		{
			break;
		}
	}
	return(AntalKombinationer);
}


int Problem77Solver(int MinimunCombinations) 
{
	int i = 1;
	int Talet = 0;
	//att vi bara tar dem första 1000 000 primtalen är helt godtyckligt, borde tänka igenom hur många som egentligen behövs, vet inte om det går
	std::vector<long long> Primtalen = PrimeGenerator(1000000);
	while (true)
	{
		//kollar hur många kombinationer i kan aderas som ett primtal
		int Kombinationer = RekursivKombinationKollare(&Primtalen, i,0);
		if (Kombinationer >= MinimunCombinations)
		{
			Talet = i;
			break;
		}
		i += 1;
	}
	return(Talet);
}