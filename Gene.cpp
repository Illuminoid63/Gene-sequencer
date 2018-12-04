#include <iostream>
#include <string>
#include <fstream>
#include "Gene.h"

using namespace std;

void Gene::setGeneName(string name)
{
	geneName = name;
}
string Gene::getGeneName()
{
	return geneName;
}
void Gene::setTraitType(string type)
{
	traitType = type;
}
string Gene::getTraitType()
{
	return traitType;
}
void Gene::setAlleleA(Allele Allele1)
{
	AlleleA = Allele1;
}
void Gene::setAlleleB(Allele Allele2)
{
	AlleleB = Allele2;
}
Allele Gene::getAlleleA()
{
	return AlleleA;
}
Allele Gene::getAlleleB()
{
	return AlleleB;
}
bool Gene::unitTest()
{
	Allele test;
	Gene testGene;
	bool b = true;

	if (test.unitTest() == false)
	{
		b = false;
	}

	testGene.setGeneName("hello");
	if (testGene.getGeneName() != "hello")
	{
		b = false;
	}

	testGene.setTraitType("hello");
	if (testGene.getTraitType() != "hello")
	{
		b = false;
	}
	return b;
}