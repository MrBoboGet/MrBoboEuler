#include <math.h>
#include <iostream>
#include <vector>
#include <TalTeori.h>
int Problem75Solver(int L)
{
	/* Tar inte hänsyn till andra kombinationer än att den har en primitiv tripplet
		int LengthWithOneCombination = 0;
	for (double i = 1; i < L+1; i++)
	{
		if (fmod(i,1000) == 0)
		{
			std::cout << i << std::endl;
		}	
		int Combinations = 0;
		for (double n = 1; n <= i/2 ; n++)
		{
			//vi kollar om svaret vi får blir  ett heltal
			float RotKomponent = sqrt((n * n / 4) + i / 2);
			float m = round(-n / 2 + RotKomponent);
			if (n >= m)
			{
				break;
			}
			if ((2*m*m +2*m*n == i))
			{
				//heltalsvärde
				Combinations += 1;
				//std::cout << m<<" "<<n << " "<< i<< std::endl;
				if (Combinations > 1)
				{
					break;
				}
			}
		}
		if (Combinations == 1)
		{
			LengthWithOneCombination += 1;
		}
	}
	return(LengthWithOneCombination);
	*/
	int LengthWithOneCombination = 0;
	std::vector<int> LengthArray = std::vector<int>(L, 0);
	for (int m = 1; m <= L; m++)
	{
		if (2*m*m + 2*m > L)
		{
			break;
		}
		for (int n = 1; n < m; n++)
		{
			//ser till att trippel vi anvånder är primitv
			if ((gcd(n,m) != 1) || (n % 2 == 1 && m % 2== 1))
			{
				continue;
			}
			int Length = 2 *m*m + 2*m*n;
			if (Length > L)
			{
				break;
			}
			//nu går vi igenom litan för varje tal och
			int i = 1;
			while (i*Length <= L)
			{
				LengthArray[i * Length - 1] += 1;
				if (Length*i == 120)
				{
					std::cout << (m*m-n*n)*i << " " << (2*m*n)*i << std::endl;
					std::cout << (m*m-n*n)*i << " " << (2*m*n)*i << std::endl;
				}
				i += 1;
			}
		}
	}
	for (int i = 0; i < LengthArray.size(); i++)
	{
		if (LengthArray[i] == 1)
		{
			LengthWithOneCombination += 1;
		}
	}
	std::cout << LengthArray[119] << std::endl;
	return(LengthWithOneCombination);
}