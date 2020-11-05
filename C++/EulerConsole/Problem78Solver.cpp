#include <iostream>
#include <unordered_map>
#include <Vector2D.h>
#include <utility>
#include<ttmathint.h>
#include <TalTeori.h>
#include <assert.h>

#define IntSize 16
inline ttmath::Int<IntSize> RekursivSummationsKollare(int ValueToSum, int PreviousValue, std::unordered_map<long long, ttmath::Int<IntSize>>* TidigareV�rden)
{
	ttmath::Int<IntSize> Kombinationer = 0;
	if ((*TidigareV�rden).find(((long long)ValueToSum << 32) + PreviousValue) != (*TidigareV�rden).end())
	{
		return((*TidigareV�rden)[((long long)ValueToSum << 32) + PreviousValue]);
	}
	if (ValueToSum-PreviousValue < PreviousValue*2)
	{
		int AntalKombinationerKvar = 1;
		AntalKombinationerKvar += ((ValueToSum - PreviousValue) - PreviousValue) / 2;
		//Kombinationer += AntalKombinationerKvar+1;
		//return(Kombinationer);
	}
	
	if ((*TidigareV�rden).find(((long long)ValueToSum << 32) + PreviousValue - 1) != (*TidigareV�rden).end() && (ValueToSum - PreviousValue > 0 && (PreviousValue - 1 < ValueToSum - PreviousValue)))
	{
		//vi kan nu direkt avg�ra vad v'rdet blir utan att g� igenbom allt igen
		//
		ttmath::Int<IntSize> ReturV�rdet = (*TidigareV�rden)[((long long)ValueToSum << 32) + PreviousValue - 1] - RekursivSummationsKollare(ValueToSum - (PreviousValue - 1), PreviousValue - 1, TidigareV�rden);//(*TidigareV�rden)[(((long long)ValueToSum - (PreviousValue - 1)) << 32) + PreviousValue - 1];
		if (ReturV�rdet <= 0)
		{
			std::cout << (*TidigareV�rden)[((long long)ValueToSum << 32) + PreviousValue - 1].ToInt() << " " << -(*TidigareV�rden)[(((long long)ValueToSum - PreviousValue) << 32) + PreviousValue - 1] << std::endl;
			std::cout << ValueToSum << " " << PreviousValue << std::endl;
			assert(false);
		}
		return(ReturV�rdet);
		//
	}
	
	for (int i = PreviousValue; i <= ValueToSum; i++)
	{
		if (ValueToSum == i)
		{
			Kombinationer += 1;
		}
		if (ValueToSum > i)
		{
			if (!(i > ValueToSum - i))
			{
				if(ValueToSum-i < i*2)
				{
					//nu kan vi direkt r�kna ut hur m�nga kombinationer det kommer bli, s� ist�llet f�r att spara varje v�rde tar vi bara och l�gger till det och returnar
					int AntalKombinationerKvar = 1; //tar i h�nsyn till detta talls v�rde
					AntalKombinationerKvar += ((ValueToSum - i) - i) / 2;
					Kombinationer += AntalKombinationerKvar+1;
					break;
				}
				long long V�rdet = (((long long)ValueToSum - i) << 32) + i;
				if ((*TidigareV�rden).find(V�rdet) == (*TidigareV�rden).end())
				{
					ttmath::Int<IntSize> NyttV�rdet = RekursivSummationsKollare(ValueToSum - i, i, TidigareV�rden);
					Kombinationer += NyttV�rdet;
					(*TidigareV�rden)[V�rdet] = NyttV�rdet;
				}
				else
				{
					Kombinationer += (*TidigareV�rden)[V�rdet];
				}
			}
			else
			{
				i = ValueToSum - 1;
			}
		}
	}
	assert(Kombinationer > 0);
	return(Kombinationer);
}
inline ttmath::Int<IntSize> RekursivSummationsKollareBrute(int ValueToSum, int PreviousValue)
{
	ttmath::Int<IntSize> Kombinationer = 0;
	if (ValueToSum - PreviousValue < PreviousValue * 2)
	{
		int AntalKombinationerKvar = 1;
		AntalKombinationerKvar += ((ValueToSum - PreviousValue) - PreviousValue) / 2;
		Kombinationer += AntalKombinationerKvar+1;
		return(Kombinationer);
	}
	if (ValueToSum / PreviousValue > 10 && PreviousValue != 1)
	{
		///*
		Kombinationer += RekursivSummationsKollareBrute(ValueToSum / PreviousValue, 1);
		Kombinationer += RekursivSummationsKollareBrute(ValueToSum - (ValueToSum / PreviousValue) * PreviousValue, 1);
		return(Kombinationer);
		//*/
	}
	for (int i = PreviousValue; i <= ValueToSum; i++)
	{
		if (ValueToSum == i)
		{
			Kombinationer += 1;
		}
		if (ValueToSum > i)
		{
			if (!(i > ValueToSum - i))
			{
				if (ValueToSum - i < i * 2)
				{
					//nu kan vi direkt r�kna ut hur m�nga kombinationer det kommer bli, s� ist�llet f�r att spara varje v�rde tar vi bara och l�gger till det och returnar
					int AntalKombinationerKvar = 1; //tar i h�nsyn till detta talls v�rde
					AntalKombinationerKvar += ((ValueToSum - i) - i) / 2;
					Kombinationer += AntalKombinationerKvar + 1;
					break;
				}
				Kombinationer += RekursivSummationsKollareBrute(ValueToSum - i, i);
			}
			else
			{
				i = ValueToSum - 1;
			}
		}
	}
	assert(Kombinationer > 0);
	return(Kombinationer);
}
inline ttmath::Int<IntSize> MatteFormula(int n)
{
	ttmath::Int<IntSize> Kombinationer = 0;
	for (int k = 1; k <= n; k++)
	{
		ttmath::Int<IntSize> Delsumma = 0;
		for (int j = 0; j <= k; j++)
		{
			std::cout << pow(-1, k - j) << std::endl;
			std::cout << Factorial(j) << std::endl;
			std::cout << Factorial(k - j) << std::endl;
			if (Factorial(k-j) == 0)
			{
				std::cout<<k<<std::endl;
				std::cout<<j<<std::endl;
			}
			std::cout << pow(j, n) << std::endl;
			Delsumma += (long long)(pow(-1, k - j) * (Factorial(k) / (Factorial(j) * Factorial(k - j))) * pow(j, n));
		}
		Delsumma /= Factorial(k);
		Kombinationer += Delsumma;
	}
	return(Kombinationer);
}
int Problem78Solver(int Divisor)
{
	int i = 1;
	int Result = 0;
	std::unordered_map<long long, ttmath::Int<IntSize>> PreviousValues = std::unordered_map<long long, ttmath::Int<IntSize>>(0);
	std::cout << sizeof(ttmath::Int<IntSize>) << std::endl;
	std::cout << MatteFormula(100) << std::endl;
	while (true)
	{
		ttmath::Int<IntSize> Kombinationerna = RekursivSummationsKollareBrute(i, 1);
		if (Kombinationerna%Divisor == 0)
		{
			Result = i;
			break;
		}
		if (i%100 == 0)
		{
			std::cout << i << " " << Kombinationerna  << std::endl;
		}
		i += 1;
		/*
		ttmath::Int<IntSize> Kombinationerna = RekursivSummationsKollare(i, 1, &PreviousValues);
		PreviousValues[((long long)i << 32) + 1] = Kombinationerna;
		if (i % 100 == 0)
		{
			std::cout << i << " " << RekursivSummationsKollare(i, 1, &PreviousValues)<<" "<<PreviousValues.size() << std::endl;
			if (PreviousValues.size() >= 500000)
			{
				// Iterate over the map using iterator
				auto it = PreviousValues.begin();
				//std::cout << "Before " << PreviousValues.size() << std::endl;
				//std::cout << "Value Of first thing " << ((it->first)>>32) << std::endl;
				int LeastValue = 1000000;
				while (it != PreviousValues.end())
				{
					if (((it->first)>>32) < LeastValue && ((it->first)>>32 != 0	))
					{
						LeastValue = ((it->first)>>32);
						//std::cout << "It->first �r lika med " << ((it->first)>>32) << std::endl;
					}
					if (((it->first) >> 32) < (i / (float)2))
						it = PreviousValues.erase(it);
					else
						++it;
				}
			}
		}
		if (Kombinationerna % Divisor == 0)
		{
			Result = i;
			break;
		}
		i += 1;
		*/
	}
	return(Result);
}

/*
inline ttmath::Int<IntSize> RekursivSummationsKollare(int ValueToSum, int PreviousValue, std::unordered_map<long long, ttmath::Int<IntSize>>* TidigareV�rden)
{
	ttmath::Int<IntSize> Kombinationer = 0;
	if ( (*TidigareV�rden).find(((long long)ValueToSum<<32)+PreviousValue) != (*TidigareV�rden).end())
	{
		return((*TidigareV�rden)[((long long)ValueToSum << 32) + PreviousValue]);
	}
	if ((*TidigareV�rden).find(((long long)ValueToSum << 32) + PreviousValue-1) != (*TidigareV�rden).end() && (ValueToSum-PreviousValue > 0 && (PreviousValue-1 < ValueToSum-PreviousValue)))
	{
		//vi kan nu direkt avg�ra vad v'rdet blir utan att g� igenbom allt igen
		//
		ttmath::Int<IntSize> ReturV�rdet = (*TidigareV�rden)[((long long)ValueToSum << 32) + PreviousValue - 1] - (*TidigareV�rden)[(((long long)ValueToSum - (PreviousValue-1)) << 32) + PreviousValue - 1];
		if (ReturV�rdet <= 0)
		{
			std::cout << (*TidigareV�rden)[((long long)ValueToSum << 32) + PreviousValue - 1].ToInt() << " "<< -(*TidigareV�rden)[(((long long)ValueToSum - PreviousValue) << 32) + PreviousValue - 1] << std::endl;
			std::cout << ValueToSum << " "<< PreviousValue << std::endl;
			assert(false);
		}
		return(ReturV�rdet);
		//
	}
	for (int i = PreviousValue; i <= ValueToSum; i++)
	{
		if (ValueToSum == i)
		{
			Kombinationer += 1;
		}
		if (ValueToSum > i)
		{
			if (!(i > ValueToSum - i))
			{
				long long V�rdet = (((long long)ValueToSum - i) << 32) + i;
				if ((*TidigareV�rden).find(V�rdet) == (*TidigareV�rden).end())
				{
					ttmath::Int<64> NyttV�rdet = RekursivSummationsKollare(ValueToSum - i, i, TidigareV�rden);
					Kombinationer += NyttV�rdet;
					(*TidigareV�rden)[V�rdet] = NyttV�rdet;
				}
				else
				{
					Kombinationer += (*TidigareV�rden)[V�rdet];
				}
			}
			else
			{
				i = ValueToSum - 1;
			}
		}
	}
	assert(Kombinationer > 0);
	return(Kombinationer);
}
int Problem78Solver(int Divisor)
{
	int i = 1;
	int Result = 0;
	std::unordered_map<long long, ttmath::Int<IntSize>> PreviousValues = std::unordered_map<long long, ttmath::Int<IntSize>>(0);
	std::cout << RekursivSummationsKollare(4, 1, &PreviousValues).ToInt() << std::endl;
	while (true)
	{
		ttmath::Int<IntSize> Kombinationerna = RekursivSummationsKollare(i, 1, &PreviousValues);
		PreviousValues[((long long)i << 32) + 1] = Kombinationerna;
		if (i % 100 == 0)
		{
			std::cout << i << " " << RekursivSummationsKollare(i, 1, &PreviousValues) << std::endl;
		}
		if (Kombinationerna % Divisor == 0)
		{
			Result = i;
			break;
		}
		i += 1;
	}
	return(Result);
}
*/





/*
inline ttmath::Int<IntSize> RekursivSummationsKollare(int ValueToSum, int PreviousValue, std::unordered_map<long long, ttmath::Int<IntSize>*>* TidigareV�rden)
{
	ttmath::Int<IntSize> Kombinationer = 0;
	if ( (*TidigareV�rden).find(((long long)ValueToSum<<32)+PreviousValue) != (*TidigareV�rden).end())
	{
		return(*(*TidigareV�rden)[((long long)ValueToSum << 32) + PreviousValue]);
	}
	if ((*TidigareV�rden).find(((long long)ValueToSum << 32) + PreviousValue-1) != (*TidigareV�rden).end() && (ValueToSum-PreviousValue > 0 && (PreviousValue-1 < ValueToSum-PreviousValue)))
	{
		//vi kan nu direkt avg�ra vad v'rdet blir utan att g� igenbom allt igen
		
		ttmath::Int<IntSize> ReturV�rdet = *(*TidigareV�rden)[((long long)ValueToSum << 32) + PreviousValue - 1] - *(*TidigareV�rden)[(((long long)ValueToSum - (PreviousValue-1)) << 32) + PreviousValue - 1];
		if (ReturV�rdet <= 0)
		{
			std::cout << (*(*TidigareV�rden)[((long long)ValueToSum << 32) + PreviousValue - 1]).ToInt() << " "<< -(*(*TidigareV�rden)[(((long long)ValueToSum - PreviousValue) << 32) + PreviousValue - 1]) << std::endl;
			std::cout << ValueToSum << " "<< PreviousValue << std::endl;
			assert(false);
		}
		return(ReturV�rdet);
		
	}
	for (int i = PreviousValue; i <= ValueToSum; i++)
	{
		if (ValueToSum == i)
		{
			Kombinationer += 1;
		}
		if (ValueToSum > i)
		{
			if (!(i > ValueToSum - i))
			{
				long long V�rdet = (((long long)ValueToSum - i) << 32) + i;
				if ((*TidigareV�rden).find(V�rdet) == (*TidigareV�rden).end())
				{
					ttmath::Int<IntSize>* NyttV�rdet = new ttmath::Int<IntSize>(RekursivSummationsKollare(ValueToSum - i, i, TidigareV�rden));
					Kombinationer += *NyttV�rdet;
					(*TidigareV�rden)[V�rdet] = NyttV�rdet;
				}
				else
				{
					Kombinationer += *(*TidigareV�rden)[V�rdet];
				}
			}
			else
			{
				i = ValueToSum - 1;
			}
		}
	}
	assert(Kombinationer > 0);
	return(Kombinationer);
}
int Problem78Solver(int Divisor)
{
	int i = 1;
	int Result = 0;
	std::unordered_map<long long, ttmath::Int<IntSize>*> PreviousValues = std::unordered_map<long long, ttmath::Int<IntSize>*>(0);
	std::cout << sizeof(std::unordered_map<long long, ttmath::Int<IntSize>*>) << std::endl;
	while (true)
	{
		ttmath::Int<IntSize>* Kombinationerna = new ttmath::Int<IntSize>(RekursivSummationsKollare(i, 1, &PreviousValues));
		PreviousValues[((long long)i << 32) + 1] = Kombinationerna;
		if (i % 100 == 0)
		{
			std::cout << i << " " << RekursivSummationsKollare(i, 1, &PreviousValues) << " " << PreviousValues.size() << std::endl;
		}
		if (*Kombinationerna % Divisor == 0)
		{
			Result = i;
			break;
		}
		i += 1;
	}
	return(Result);
}
*/