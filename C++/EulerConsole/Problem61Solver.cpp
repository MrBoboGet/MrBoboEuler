#include <Problem61Solver.h>
#include <FigurativeNumbers.h>
#include <Combinatorics.h>
#include <string>
#include <assert.h>
#include <iostream>
struct PolygonType
{
	int (*Converterare)(int n);
	bool (*Checkare)(int n);
};
void RekursivCyliskGenerator(std::vector<PolygonType> OrderOfFigurativeNumbers,int* Sum,std::vector<int>* Result,int CurrentDepth)
{
	if (*Sum == 0)
	{
		if (CurrentDepth == 0)
		{
			//settar upp resultat pointern och börjar loopen
			Result = new std::vector<int>(6, 0);
			int i = 1;
			int PolygonTal = 0;
			while (PolygonTal < 10000)
			{
				PolygonTal = OrderOfFigurativeNumbers[CurrentDepth].Converterare(i);
				if (PolygonTal > 999 && PolygonTal < 10000)
				{
					(*Result)[CurrentDepth] = PolygonTal;
					RekursivCyliskGenerator(OrderOfFigurativeNumbers, Sum, Result, CurrentDepth + 1);
				}
				i += 1;
			}
		}
		/*
		std::cout << "Hej" << std::endl;
		if ((*Result).size() != 6 || OrderOfFigurativeNumbers.size() != 6)
		{
			std::cout << OrderOfFigurativeNumbers.size() << std::endl;
			std::cout << (*Result).size() << std::endl;
		}
		*/
		if (CurrentDepth != OrderOfFigurativeNumbers.size() - 1 && CurrentDepth != 0)
		{
			int i = 1;
			int PolygonTal = 0;
			while (PolygonTal < 10000)
			{
				PolygonTal = OrderOfFigurativeNumbers[CurrentDepth].Converterare(i);
				if (PolygonTal > 999 && PolygonTal < 10000)
				{
					//nu koller om den uppfyller kraven för cykliskhet, dvs om det förra talet 2 sista siffror är detta tals 2 första
					std::string TaletInnan = std::to_string((*Result)[CurrentDepth - 1]);
					std::string NuvarandeTalet = std::to_string(PolygonTal);
					if (TaletInnan.substr(2, 2) == NuvarandeTalet.substr(0, 2))
					{
						//cykliskheten stämmer, det innebär att vi vill fortsätta
						(*Result)[CurrentDepth] = PolygonTal;
						RekursivCyliskGenerator(OrderOfFigurativeNumbers, Sum, Result, CurrentDepth + 1);
					}
				}
				i += 1;
			}
			//kommer vi hit innebär det att det inte fanns något tal som uppfyllde våra krav, vilket bara innbär att vi inte gör mer
		}
		if (CurrentDepth == OrderOfFigurativeNumbers.size() - 1)
		{
			//alla tall innan fungerade, sista som behövs
			int i = 1;
			int PolygonTal = 0;
			while (PolygonTal < 10000)
			{
				PolygonTal = OrderOfFigurativeNumbers[CurrentDepth].Converterare(i);
				if (PolygonTal > 999 && PolygonTal < 10000)
				{
					//nu koller om den uppfyller kraven för cykliskhet, dvs om det förra talet 2 sista siffror är detta tals 2 första
					std::string TaletInnan = std::to_string((*Result)[CurrentDepth - 1]);
					std::string NuvarandeTalet = std::to_string(PolygonTal);
					if (TaletInnan.substr(2, 2) == NuvarandeTalet.substr(0, 2))
					{
						//nu kollar vi också huruvida detta stämmer med cyklisk heten för första talet
						std::string FörstaTalet = std::to_string((*Result)[0]);
						if (FörstaTalet.substr(0, 2) == NuvarandeTalet.substr(2, 2))
						{
							//nu vet vi att allt stämmer och är bra, då ändrar vi inte variabeln till suimman av allt
							(*Result)[CurrentDepth] = PolygonTal;
							for (int j = 0; j < OrderOfFigurativeNumbers.size(); j++)
							{
								*Sum += (*Result)[j];
							}
						}
					}
				}
				i += 1;
			}
		}
	}
}
int Problem61Solver()
{
	//försöker lösa detta med functions pointers, aningen vad man brukar kalla spicy
	PolygonType Triangel;
	Triangel.Converterare = Triangle;
	Triangel.Checkare = IsTriangle;
	PolygonType Kvadrat;
	Kvadrat.Converterare = Square;
	Kvadrat.Checkare = IsSquare;
	PolygonType Pentagon;
	Pentagon.Converterare = Pentagonal;
	Pentagon.Checkare = IsPentagonal;
	PolygonType Hexagon;
	Hexagon.Converterare = Hexagonal;
	Hexagon.Checkare = IsHexagonal;
	PolygonType Heptagon;
	Heptagon.Converterare = Heptagonal;
	Heptagon.Checkare = IsHeptagonal;
	PolygonType Octagon;
	Octagon.Converterare = Octagonal;
	Octagon.Checkare = IsOctagonal;
	std::vector<PolygonType> Typerna = std::vector<PolygonType>(0);
	Typerna.push_back(Triangel);
	Typerna.push_back(Kvadrat);
	Typerna.push_back(Pentagon);
	Typerna.push_back(Hexagon);
	Typerna.push_back(Heptagon);
	Typerna.push_back(Octagon);

	//vi gör permutationerna av dessa
	Permutations<PolygonType> Permutationerna = Permutations<PolygonType>(Typerna);

	//nu går vi igenom alla permutationer i listen
	int Sum = 0;
	for (int i = 0; i < Permutationerna.Permutationerna.size(); i++)
	{
		//nu går vi igenom varje exempelvis triangel tal, kollar om det finns ett tal som uppfyller kravet sen, osv
		//vi gör detta rekursivt
		if (Sum == 0)
		{
			RekursivCyliskGenerator(Permutationerna[i], &Sum, nullptr, 0);
		}
		else
		{
			break;
		}
		std::cout << i << std::endl;
	}
	return(Sum);
}