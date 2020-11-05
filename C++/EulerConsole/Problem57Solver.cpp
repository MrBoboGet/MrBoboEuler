#include <math.h>
#include <BigInteger.h>
#include<iostream>
struct Bråk
{
	BigInteger Täljare;
	BigInteger Nämnare;
};
Bråk RekursivNämnareUträknare(int Depth)
{
	if (Depth == 0)
	{
		Bråk ReturVärdet;
		ReturVärdet.Täljare = 1;
		ReturVärdet.Nämnare = 2;
		return(ReturVärdet);
	}
	else
	{
		Bråk BråketHögeriNämnaren = RekursivNämnareUträknare(Depth - 1);
		BråketHögeriNämnaren.Täljare =BråketHögeriNämnaren.Täljare + (2 * BråketHögeriNämnaren.Nämnare);
		//nu ska vi inverterade det
		Bråk ReturVärdet;
		ReturVärdet.Täljare = BråketHögeriNämnaren.Nämnare;
		ReturVärdet.Nämnare = BråketHögeriNämnaren.Täljare;
		return(ReturVärdet);
	}
}
int Problem57Solver(int NumberOfExpansions)
{
	//vi vill egentligen bara räkna uit vad tätäljaren fär 1/x termen är
	//vi kör rekursiv lösning lets go
	int FractionsWithBiggerNumerator = 0;
	for (int i = 0; i < NumberOfExpansions; i++)
	{
		if (i % 100 == 0)
		{
			std::cout << i << std::endl;
		}
		//std::cout << i << std::endl;
		Bråk Bråket = RekursivNämnareUträknare(i);
		//eftersom vi adderar 1
		Bråket.Täljare =Bråket.Täljare+ Bråket.Nämnare;
		//std::cout << Bråket.Täljare << "/" << Bråket.Nämnare<<std::endl;
		//vi vill nu kolla huruvida talen är lika delbara på tio
		BigInteger TioPotens = BigInteger(1);
		TioPotens = 1;
		while (true)
		{
			TioPotens = TioPotens*10;
			//vi kollar om täljaren är större eller lika med dettta, och att täljaren inte är det, stämmer det adder4ar vi och breakar. Annars kör vi tills båda är störra
			if (TioPotens <= Bråket.Täljare && Bråket.Nämnare < TioPotens)
			{
				FractionsWithBiggerNumerator += 1;
				//debuggar och kollar att alla är rätt
				//std::cout << Bråket.Täljare.ToString() <<" T" << std::endl;
				//std::cout << TioPotens.ToString() << " TioPotens" <<std::endl;
				//std::cout << Bråket.Nämnare.ToString() <<" N" << std::endl;
				break;
			}
			if (Bråket.Täljare < TioPotens && Bråket.Nämnare < TioPotens)
			{
				break;
			}
		}
		//nu vill vi veta vad nämnaren och täljaren blir om vi faktiskt skulle göra detta till ett rationellt tal
		/*
		if (((int)log10(Bråket.Täljare) > ((int)log10(Bråket.Nämnare))))
		{
			FractionsWithBiggerNumerator+=1;
		*/
	}
	return(FractionsWithBiggerNumerator);
}