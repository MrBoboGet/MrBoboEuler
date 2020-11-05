#include <TalTeori.h>
#include <iostream>
int Problem73Solver(int d) 
{
	int Antal = 0;
	for (int i = 2; i < d+1; i++)
	{
		if (i%100 == 0)
		{
			std::cout << i << std::endl;
		}
		for (int j = 0; j < i; j++)
		{
			//om dem är prim kollar vi huruvida dem är mellan 1/3 och 1/2
			if (gcd(j,i) == 1)
			{
				if ((float)j/i > 1/(float)3 && j/(float)i < 1/(float)2)
				{
					Antal += 1;
				}
			}
		}
	}
	return(Antal);
}