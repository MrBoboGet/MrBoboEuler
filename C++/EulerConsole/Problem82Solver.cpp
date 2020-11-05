#include<string>
#include <fstream>
#include <vector>
#include <MinaStringOperations.h>
#include <GrafTeori.h>
#include <iostream>
int Problem82Solver(std::string Path)
{
    std::ifstream DataSource(Path);
    std::vector<std::vector<int>> Datan = std::vector<std::vector<int>>(0);
    if (DataSource.is_open()) {
        std::string line;
        while (std::getline(DataSource, line))
        {
            //vi g�r s� att v�ran vina array av array blir r�tt upplagd
            auto SplittadString = Split(line, ",");
            std::vector<int> SplittadStringInts = std::vector<int>(0);
            for (int j = 0; j < SplittadString.size(); j++)
            {
                SplittadStringInts.push_back(std::stoi(SplittadString[j]));
            }
            Datan.push_back(SplittadStringInts);
            // using printf() in all tests for consistency
            //printf("%s", line.c_str());
        }
        DataSource.close();
    }
    //nu �r all data uppsettad
    //nu skapar vi en graf och l�gger till vajre kant
    long double ReturV�rdet = 0;
    int SideLength = Datan.size();
    std::cout << "Data.size() = " << SideLength << std::endl;
    WeightedGraph Grafen = WeightedGraph(SideLength * SideLength);
    for (size_t i = 0; i < Datan.size(); i++)
    {
        for (size_t j = 0; j < Datan[i].size(); j++)
        {
            //koppling h�ger
            if (j != Datan[i].size() - 1)
            {
                Grafen.AddEdgeDirected(std::pair<int, int>(i * SideLength + j, i * SideLength + j + 1), Datan[i][j + 1]);
            }
            //koppling ner
            if (i != Datan.size() - 1)
            {
                Grafen.AddEdgeDirected(std::pair<int, int>(i * SideLength + j, (i + 1) * SideLength + j), Datan[i + 1][j]);
            }
            //koppling upp
            if (i != 0)
            {
                Grafen.AddEdgeDirected(std::pair<int, int>(i * SideLength + j, (i - 1) * SideLength + j), Datan[i - 1][j]);
            }
        }
    }
    ReturV�rdet = (double)9223372036854775807;
    for (int i = 0; i < Datan.size(); i++)
    {
        std::cout << i << std::endl;
        long double V�rdet = Grafen.MatrixShortestPathToRightColumn(i * Datan.size(), 80, 80)+Datan[i][0];
        if (V�rdet < ReturV�rdet)
        {
            ReturV�rdet = V�rdet;
        }
    }
    //grafen klar gjord, nu k�r vi bara djikstra p� den
    return(ReturV�rdet);
}