#include <TalTeori.h>
#include <ttmathint.h>
ttmath::Int<64> Problem72Solver(int d)
{
	ttmath::Int<64> Sum = 0;
	for (int i = 2; i < d+1; i++)
	{
		Sum += phi(i);
	}
	return(Sum);
}