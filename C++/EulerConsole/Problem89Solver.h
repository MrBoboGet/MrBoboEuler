#pragma once
#include <TextReader.h>
#include <unordered_map>
#include <MinaStringOperations.h>
int RomanNumeralEvaluator(std::string Numeral)
{
	std::unordered_map<char, int> NumeralValue = std::unordered_map<char, int>(0);
	NumeralValue['I'] = 1;
	NumeralValue['V'] = 5;
	NumeralValue['X'] = 10;
	NumeralValue['L'] = 50;
	NumeralValue['C'] = 100;
	NumeralValue['D'] = 500;
	NumeralValue['M'] = 1000;
	//räknar ut värdet av talet
	int Retuvärde = 0;
	for (int i = 0; i < Numeral.size(); i+=1)
	{
		if (i+1 < Numeral.size())
		{
			if (NumeralValue[Numeral[i]] < NumeralValue[Numeral[i+1]])
			{
				Retuvärde+= NumeralValue[Numeral[i + 1]] - NumeralValue[Numeral[i]];
				i += 1;
			}
			else
			{
				Retuvärde += NumeralValue[Numeral[i]];
			}
		}
		else
		{
			Retuvärde += NumeralValue[Numeral[i]];
		}
	}
	return(Retuvärde);
}
int Problem89Solver(std::string Path)
{
	TextReader Text(Path);
	std::vector<std::string> Datan = Text.GetAllLines();
	int TotalDifferenceInLength = 0;
	for (int i = 0; i < Datan.size(); i++)
	{
		if (i%10 == 0)
		{
			std::cout << i << std::endl;
		}
		int NumeralValue = RomanNumeralEvaluator(Datan[i]);
		std::string OptimalNumeral = "";
		int OptimalNumeralValue = 0;
		std::unordered_map<int, std::string> ValueToNumeral = std::unordered_map<int, std::string>(0);
		ValueToNumeral[4] = "IV";
		ValueToNumeral[9] = "IX";
		ValueToNumeral[40] = "XL";
		ValueToNumeral[90] = "XC";
		ValueToNumeral[400] = "CD";
		ValueToNumeral[900] = "CM";
		ValueToNumeral[1] = 'I';
		ValueToNumeral[5] = 'V',
		ValueToNumeral[10] = 'X';
		ValueToNumeral[50] = 'L';
		ValueToNumeral[100] = 'C';
		ValueToNumeral[500] = 'D';
		ValueToNumeral[1000] = 'M';
		std::vector<int> OrderOfNumbers = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		while(OptimalNumeralValue < NumeralValue)
		{
			for (int j = 0; j < OrderOfNumbers.size(); j++)
			{
				if (OrderOfNumbers[j] <= NumeralValue-OptimalNumeralValue)
				{
					OptimalNumeralValue += OrderOfNumbers[j];
					OptimalNumeral += ValueToNumeral[OrderOfNumbers[j]];
					break;
				}
			}
		}
		int OptimalNumeralActualValue = RomanNumeralEvaluator(OptimalNumeral);
		assert(Split(OptimalNumeral, "V").size() <= 2);
		assert(Split(OptimalNumeral, "D").size() <= 2);
		assert(Split(OptimalNumeral, "L").size() <= 2);
		assert(OptimalNumeralActualValue == NumeralValue);
		TotalDifferenceInLength += (Datan[i].size() - OptimalNumeral.size());
	}
	return(TotalDifferenceInLength);
}