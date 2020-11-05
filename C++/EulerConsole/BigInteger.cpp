#include <BigInteger.h>
#include <math.h>
#include <iostream>
#include <string>

BigInteger::BigInteger(int NumberOf32BitInts)
{
	IntParts = std::vector<unsigned long int>(NumberOf32BitInts);
}
BigInteger::BigInteger()
{
	IntParts = std::vector<unsigned long int>(0);

}
BigInteger BigInteger::operator+(const BigInteger& OtherInt)
{
	//vi skapar en temporär vector<long int> som sparar våra värden
	int MaxInterations = (OtherInt.IntParts.size() > this->IntParts.size()) ? OtherInt.IntParts.size() : this->IntParts.size();
	BigInteger Result = BigInteger(MaxInterations);
	//std::cout << Result.IntParts[0] << std::endl;
	//nu går adderar vi våra ints en och en, men ser till att vi håller koll på remaindern
	int NumberOfIterations = MaxInterations;
	//nu avgör vi viklken som är mindre än den andrfa
	bool DifferentSize = false;
	bool IsLess = false;
	int MinIterations = 0;
	if(OtherInt.IntParts.size() != this->IntParts.size())
	{
		DifferentSize = true;
		if (OtherInt.IntParts.size() > this->IntParts.size())
		{
			IsLess = true;
			MinIterations = this->IntParts.size();
		}
		else
		{
			IsLess = false;
			MinIterations = OtherInt.IntParts.size();
		}
	}

	unsigned long int Remainder = 0;
	for (int i = 0; i < NumberOfIterations; i++)
	{
		//vi vet att en unsigend long int alltid kommer kunna lagra resultatet av en adition av long int värdet
		//vi kollar huruvida dett är störra än 2^31 -1, är det det så har vi fått en overflow
		if (!DifferentSize || i < MinIterations)
		{
			unsigned long int Summan = OtherInt.IntParts[i] + this->IntParts[i] + Remainder;
			long double SummanUtanOverflow = (long double)OtherInt.IntParts[i] + (long double)this->IntParts[i] + (long double)Remainder;
			//condition för om det blir remainder
			if(SummanUtanOverflow > pow(2,32))
			{
				Result.IntParts[i] = Summan;
				Remainder = 1;
				if (i == NumberOfIterations - 1)
				{
					//sista summan, fast vi har fortfarande en remainder
					Result.IntParts.push_back(1);
				}
			}
			else
			{
				Result.IntParts[i] = Summan;
				Remainder = 0;
			}
		}
		else
		{
			if (IsLess)
			{
				long double TotalaSumma = OtherInt.IntParts[i] + (long double)Remainder;
				unsigned long int Summan = OtherInt.IntParts[i] + Remainder;
				if (TotalaSumma > pow(2,32))
				{
					IntParts[i] = Summan;
					Remainder = 1;
					//är vi sist appendar vi istället remaindern
					if (i == NumberOfIterations-1)
					{
						Result.IntParts.push_back(1);
					}
				}
				else
				{
					//ingen overflow
					Result.IntParts[i] = Summan;
					Remainder = 0;
				}
			}
			else
			{
				long double TotalaSumma = this->IntParts[i] + (long double)Remainder;
				unsigned long int Summan = this->IntParts[i] + Remainder;
				if (TotalaSumma > pow(2, 32))
				{
					IntParts[i] = Summan;
					Remainder = 1;
					//är vi sist appendar vi istället remaindern
					if (i == NumberOfIterations - 1)
					{
						Result.IntParts.push_back(1);
					}
				}
				else
				{
					//ingen overflow
					Result.IntParts[i] = Summan;
					Remainder = 0;
				}
			}
		}
	}
	return(Result);
}

bool operator<(const BigInteger& Big1, const BigInteger& Big2) 
{
	//vi går igenom varje tal, från största till minst, och kollar huruvida varje del inte är störra
	if (Big1.IntParts.size() != Big2.IntParts.size())
	{
		return(Big1.IntParts.size() < Big2.IntParts.size());
	}
	else
	{
		for(int i = Big2.IntParts.size()-1; i >= 0; i--)
		{
			if (Big2.IntParts[i] != Big1.IntParts[i])
			{
				return(Big1.IntParts[i] < Big2.IntParts[i]);
			}
		}
		//om vi kommer hit så är dem lika med varandra, då returnar vi false
		return(false);
	}
}
bool operator>=(const BigInteger& Big1, const BigInteger& Big2)
{
	return(!(Big1 < Big2));
}
bool operator>(const BigInteger& Big1, const BigInteger& Big2)
{
	return(!(Big2 >= Big1));
}
bool operator<=(const BigInteger& Big1, const BigInteger& Big2)
{
	return(!(Big1 > Big2));
}

BigInteger operator*(const BigInteger& Big, int Konstant)
{
	//omega trash lösning, men vad ska man göra
	BigInteger Resultat = BigInteger(1);
	Resultat = Big;
	for (int i = 1; i < Konstant; i++)
	{
		Resultat = Resultat+Big;
	}
	return(Resultat);
}
BigInteger operator*(int Konstant, const BigInteger& Big)
{
	return(Big * Konstant);
}


BigInteger BigInteger::operator=(int OtherInt)
{
	//IntParts = std::vector<long int>(1, OtherInt);
	IntParts.resize(1);
	IntParts[0] = OtherInt;
	return(*this);
}
std::string BigInteger::ToString()
{
	std::string ReturVärde = "";
	for (int i = IntParts.size()-1; i >=0; i--)
	{
		ReturVärde += std::to_string(IntParts[i]);
	}
	return(ReturVärde);
}