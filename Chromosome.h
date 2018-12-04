#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Gene.h"
#include "ExpressedGene.h"
#ifndef CHROMOSOME_H
#define CHROMOSOME_H

using namespace std;

class Chromosome
{
  private:
	vector<Gene> genes;

  public:
	void setGeneVector(Gene myGene);
	Gene findGene(int j);
	int vectorSize();
	void writeChromosomeToFile(); //add unit tests
	Chromosome operator+(Chromosome rhs);
	bool runAllUnitTests();
};
#endif