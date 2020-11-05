// EulerConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>
#include <thread>
#include <TalTeori.h>
#include <math.h>
#include <FigurativeNumbers.h>
#include <Combinatorics.h>
#include <vector>
#include <ContinuedFractions.h>
#include <GrafTeori.h>
#include<Vector2D.h>
#include <ttmathint.h>
#include <MinaStringOperations.h>
#include <TextReader.h>
#include <IntrinsicGrejer.h>
#include <Problem57Solver.h>
#include <Problem61Solver.h>
#include <Problem66Solver.h>
#include <Problem64Solver.h>
#include <Problem65Solver.h>
#include <Problem69Solver.h>
#include <Problem72Solver.h>
#include <Problem73Solver.h>
#include <Problem74Solver.h>
#include <Problem71Solver.h>
#include <Problem75Solver.h>
#include <Problem77Solver.h>
#include <Problem78Solver.h>
#include <Problem80Solver.h>
#include <Problem81Solver.h>
#include <Problem82Solver.h>
#include <Problem87Solver.h>
#include <Problem89Solver.h>

int main()
{
	//std::cout << Problem77Solver(5000) << std::endl;
	/*
	WeightedGraph TestGraf = WeightedGraph(5);
	TestGraf.AddEdge(std::pair<int, int>(0, 1), 6);
	TestGraf.AddEdge(std::pair<int, int>(0, 3), 1);
	TestGraf.AddEdge(std::pair<int, int>(1, 2), 5);
	TestGraf.AddEdge(std::pair<int, int>(1, 3), 2);
	TestGraf.AddEdge(std::pair<int, int>(1, 4), 2);
	TestGraf.AddEdge(std::pair<int, int>(2, 4), 5);
	TestGraf.AddEdge(std::pair<int, int>(3, 4), 1);
	std::cout << TestGraf.ShortestPath(2, 0) << std::endl;
	//*/
	std::cout << Problem89Solver("Problem89Data.txt")<<std::endl;
}
//vi har 16 cores

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
