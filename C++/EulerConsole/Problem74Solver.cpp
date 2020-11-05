#include <vector>
#include <string>
#include <unordered_map>
#include <Combinatorics.h>
#include <iostream>
int Problem74Solver(int n)
{
	int NumberOfSixty = 0;
	for (int i = 69; i < n; i++)
	{
		if (i %1000 == 0)
		{
			std::cout << i << std::endl;
		}
		std::unordered_map<int,int> Kedjan = std::unordered_map<int,int>();
		Kedjan[i] = 1;
		std::string NuvarandeTaletString = std::to_string(i);
		int NextNumber = 0;
		for (int j = 0; j < NuvarandeTaletString.size(); j++)
		{
			NextNumber += Factorial((int)NuvarandeTaletString[j] - 48);
		}
 		while (Kedjan.find(NextNumber) == Kedjan.end())
		{
			Kedjan[NextNumber] = 1;
			std::string NuvarandeTaletString = std::to_string(NextNumber);
			NextNumber = 0;
			for (int j = 0; j < NuvarandeTaletString.size(); j++)
			{
				NextNumber += Factorial((int)NuvarandeTaletString[j] - 48);
			}
		}
		if (Kedjan.size() == 60)
		{
			NumberOfSixty += 1;
		}
		if (i == 69)
		{
			std::cout << Kedjan.size() << std::endl;
		}
		//
	}
	return(NumberOfSixty);
}