#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Chromosome.h"

using namespace std;

void Chromosome::setGeneVector(Gene myGene)
{
	genes.push_back(myGene);
}
Gene Chromosome::findGene(int j)
{
	return genes.at(j);
}
void Chromosome::writeChromosomeToFile()
{
	string File;
	int y;
	y = genes.size();

	Gene currentGene;
	Allele Allele1;
	Allele Allele2;

	cout << "what file would you like to export to?" << endl;
	cin >> File;

	ofstream mystream;
	mystream.open(File, std::iostream::app);

	for (int i = 0; i < y; ++i)
	{
		currentGene = genes.at(i);

		Allele1 = currentGene.getAlleleA();
		Allele2 = currentGene.getAlleleB();

		mystream << currentGene.getGeneName() << "," << currentGene.getTraitType() << "," << Allele1.getVariantName() << "," << Allele1.getVariantTypeName() << "," << Allele1.getNucleotideSequence()
				 << "," << Allele2.getVariantName() << "," << Allele2.getVariantTypeName() << "," << Allele2.getNucleotideSequence() << "\n";
	}
}
Chromosome Chromosome::operator+(Chromosome rhs)
{
	Chromosome combinedChromosome;
	Gene currentGene;
	srand(time(0));
	int geneSize = genes.size();

	for (int i = 0; i < geneSize; ++i)
	{
		int l = (rand() % 4);

		currentGene.setGeneName(genes.at(i).getGeneName());
		currentGene.setTraitType(genes.at(i).getTraitType());

		if (l == 0)
		{
			currentGene.setAlleleA(genes.at(i).getAlleleA());
			currentGene.setAlleleB(rhs.findGene(i).getAlleleA());
		}
		if (l == 1)
		{
			currentGene.setAlleleA(genes.at(i).getAlleleB());
			currentGene.setAlleleB(rhs.findGene(i).getAlleleB());
		}
		if (l == 2)
		{
			currentGene.setAlleleA(genes.at(i).getAlleleA());
			currentGene.setAlleleB(rhs.findGene(i).getAlleleB());
		}
		if (l == 3)
		{
			currentGene.setAlleleA(genes.at(i).getAlleleB());
			currentGene.setAlleleB(rhs.findGene(i).getAlleleA());
		}
		combinedChromosome.setGeneVector(currentGene);
	}
	return combinedChromosome;
}
int Chromosome::vectorSize()
{
	return genes.size();
}
bool Chromosome::runAllUnitTests()
{
	Gene unitTest1;
	ExpressedGene unitTest2;
	Chromosome unitTest3;
	bool d = true;

	if (unitTest1.unitTest() == false)
	{
		d = false;
	}
	if (unitTest2.unitTest() == false)
	{
		d = false;
	}

	unitTest1.setGeneName("hello");
	unitTest3.setGeneVector(unitTest1);
	if (unitTest3.findGene(0).getGeneName() != "hello")
	{
		d = false;
	}
	if (unitTest3.vectorSize() != 1)
	{
		d = false;
	}
	return d;
}
