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
	//vi skapar en tempor�r vector<long int> som sparar v�ra v�rden
	int MaxInterations = (OtherInt.IntParts.size() > this->IntParts.size()) ? OtherInt.IntParts.size() : this->IntParts.size();
	BigInteger Result = BigInteger(MaxInterations);
	//std::cout << Result.IntParts[0] << std::endl;
	//nu g�r adderar vi v�ra ints en och en, men ser till att vi h�ller koll p� remaindern
	int NumberOfIterations = MaxInterations;
	//nu avg�r vi viklken som �r mindre �n den andrfa
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
		//vi vet att en unsigend long int alltid kommer kunna lagra resultatet av en adition av long int v�rdet
		//vi kollar huruvida dett �r st�rra �n 2^31 -1, �r det det s� har vi f�tt en overflow
		if (!DifferentSize || i < MinIterations)
		{
			unsigned long int Summan = OtherInt.IntParts[i] + this->IntParts[i] + Remainder;
			long double SummanUtanOverflow = (long double)OtherInt.IntParts[i] + (long double)this->IntParts[i] + (long double)Remainder;
			//condition f�r om det blir remainder
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
					//�r vi sist appendar vi ist�llet remaindern
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
					//�r vi sist appendar vi ist�llet remaindern
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
	//vi g�r igenom varje tal, fr�n st�rsta till minst, och kollar huruvida varje del inte �r st�rra
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
		//om vi kommer hit s� �r dem lika med varandra, d� returnar vi false
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
	//omega trash l�sning, men vad ska man g�ra
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
	std::string ReturV�rde = "";
	for (int i = IntParts.size()-1; i >=0; i--)
	{
		ReturV�rde += std::to_string(IntParts[i]);
	}
	return(ReturV�rde);
}