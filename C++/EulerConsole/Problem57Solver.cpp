#include <math.h>
#include <BigInteger.h>
#include<iostream>
struct Br�k
{
	BigInteger T�ljare;
	BigInteger N�mnare;
};
Br�k RekursivN�mnareUtr�knare(int Depth)
{
	if (Depth == 0)
	{
		Br�k ReturV�rdet;
		ReturV�rdet.T�ljare = 1;
		ReturV�rdet.N�mnare = 2;
		return(ReturV�rdet);
	}
	else
	{
		Br�k Br�ketH�geriN�mnaren = RekursivN�mnareUtr�knare(Depth - 1);
		Br�ketH�geriN�mnaren.T�ljare =Br�ketH�geriN�mnaren.T�ljare + (2 * Br�ketH�geriN�mnaren.N�mnare);
		//nu ska vi inverterade det
		Br�k ReturV�rdet;
		ReturV�rdet.T�ljare = Br�ketH�geriN�mnaren.N�mnare;
		ReturV�rdet.N�mnare = Br�ketH�geriN�mnaren.T�ljare;
		return(ReturV�rdet);
	}
}
int Problem57Solver(int NumberOfExpansions)
{
	//vi vill egentligen bara r�kna uit vad t�t�ljaren f�r 1/x termen �r
	//vi k�r rekursiv l�sning lets go
	int FractionsWithBiggerNumerator = 0;
	for (int i = 0; i < NumberOfExpansions; i++)
	{
		if (i % 100 == 0)
		{
			std::cout << i << std::endl;
		}
		//std::cout << i << std::endl;
		Br�k Br�ket = RekursivN�mnareUtr�knare(i);
		//eftersom vi adderar 1
		Br�ket.T�ljare =Br�ket.T�ljare+ Br�ket.N�mnare;
		//std::cout << Br�ket.T�ljare << "/" << Br�ket.N�mnare<<std::endl;
		//vi vill nu kolla huruvida talen �r lika delbara p� tio
		BigInteger TioPotens = BigInteger(1);
		TioPotens = 1;
		while (true)
		{
			TioPotens = TioPotens*10;
			//vi kollar om t�ljaren �r st�rre eller lika med dettta, och att t�ljaren inte �r det, st�mmer det adder4ar vi och breakar. Annars k�r vi tills b�da �r st�rra
			if (TioPotens <= Br�ket.T�ljare && Br�ket.N�mnare < TioPotens)
			{
				FractionsWithBiggerNumerator += 1;
				//debuggar och kollar att alla �r r�tt
				//std::cout << Br�ket.T�ljare.ToString() <<" T" << std::endl;
				//std::cout << TioPotens.ToString() << " TioPotens" <<std::endl;
				//std::cout << Br�ket.N�mnare.ToString() <<" N" << std::endl;
				break;
			}
			if (Br�ket.T�ljare < TioPotens && Br�ket.N�mnare < TioPotens)
			{
				break;
			}
		}
		//nu vill vi veta vad n�mnaren och t�ljaren blir om vi faktiskt skulle g�ra detta till ett rationellt tal
		/*
		if (((int)log10(Br�ket.T�ljare) > ((int)log10(Br�ket.N�mnare))))
		{
			FractionsWithBiggerNumerator+=1;
		*/
	}
	return(FractionsWithBiggerNumerator);
}