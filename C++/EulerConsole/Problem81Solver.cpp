#include <Problem81Solver.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <MinaStringOperations.h>
#include <GrafTeori.h>
long double Problem81Solver(std::string Path)
{
    std::ifstream DataSource(Path);
    std::vector<std::vector<int>> Datan = std::vector<std::vector<int>>(0);
    if (DataSource.is_open()) {
        std::string line;
        while (std::getline(DataSource, line)) 
        {
            //vi gör så att våran vina array av array blir rätt upplagd
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
    //nu är all data uppsettad
    //nu skapar vi en graf och lägger till vajre kant
    long double ReturVärdet = 0;
    int SideLength = Datan.size();
    std::cout << "Data.size() = " << SideLength << std::endl;
    WeightedGraph Grafen = WeightedGraph(SideLength * SideLength);
    for (size_t i = 0; i < Datan.size(); i++)
    {
        for (size_t j = 0; j < Datan[i].size(); j++)
        {
            //koppling höger
            if (j != Datan[i].size()-1)
            {
                Grafen.AddEdgeDirected(std::pair<int, int>(i * SideLength + j, i * SideLength + j + 1), Datan[i][j+1]);
            }
            //koppling ner
            if (i != Datan.size()-1)
            {
                Grafen.AddEdgeDirected(std::pair<int, int>(i * SideLength + j, (i+1) * SideLength + j), Datan[i+1][j]);
            }
        }
    }
    //grafen klar gjord, nu kör vi bara djikstra på den
    ReturVärdet = Grafen.ShortestPath(0,6399);
    return(ReturVärdet+Datan[0][0]);
}


/*
4445,2697,5115,718,2209,2212,654,4348,3079,6821,7668,3276,8874,4190,3785,2752,9473,7817,9137,496,7338,3434,7152,4355,4552,7917,7827,2460,2350,691,3514,5880,3145,7633,7199,3783,5066,7487,3285,1084,8985,760,872,8609,8051,1134,9536,5750,9716,9371,7619,5617,275,9721,2997,2698,1887,8825,6372,3014,2113,7122,7050,6775,5948,2758,1219,3539,348,7989,2735,9862,1263,8089,6401,9462,3168,2758,3748,5870
1096,20,1318,7586,5167,2642,1443,5741,7621,7030,5526,4244,2348,4641,9827,2448,6918,5883,3737,300,7116,6531,567,5997,3971,6623,820,6148,3287,1874,7981,8424,7672,7575,6797,6717,1078,5008,4051,8795,5820,346,1851,6463,2117,6058,3407,8211,117,4822,1317,4377,4434,5925,8341,4800,1175,4173,690,8978,7470,1295,3799,8724,3509,9849,618,3320,7068,9633,2384,7175,544,6583,1908,9983,481,4187,9353,9377
9607,7385,521,6084,1364,8983,7623,1585,6935,8551,2574,8267,4781,3834,2764,2084,2669,4656,9343,7709,2203,9328,8004,6192,5856,3555,2260,5118,6504,1839,9227,1259,9451,1388,7909,5733,6968,8519,9973,1663,5315,7571,3035,4325,4283,2304,6438,3815,9213,9806,9536,196,5542,6907,2475,1159,5820,9075,9470,2179,9248,1828,4592,9167,3713,4640,47,3637,309,7344,6955,346,378,9044,8635,7466,5036,9515,6385,9230
*/
// (0,161) borde vara 12 946 är = 22533 som att gå rakt ner sen höger. Den ser inte nej höger ner