#include <iostream>
#include <string>
#include <fstream>
#include "ExpressedGene.h"

using namespace std;

void ExpressedGene::setGeneName(string name)
{
	geneName = name;
}
string ExpressedGene::getGeneName()
{
	return geneName;
}
void ExpressedGene::setGeneTrait(string type)
{
	geneTrait = type;
}
string ExpressedGene::getGeneTrait()
{
	return geneTrait;
}
void ExpressedGene::setAlleleName(string AName)
{
	expressedAlleleName = AName;
}
string ExpressedGene::getAlleleName()
{
	return expressedAlleleName;
}
void ExpressedGene::setAlleleType(string Atype)
{
	expressedAlleleType = Atype;
}
string ExpressedGene::getAlleleType()
{
	return expressedAlleleType;
}
void ExpressedGene::setAlleleSequence(string sequence)
{
	expressedAlleleSequence = sequence;
}
string ExpressedGene::getAlleleSequence()
{
	return expressedAlleleSequence;
}
bool ExpressedGene::unitTest()
{
	ExpressedGene test;
	bool c = true;

	test.setAlleleName("hello");
	if (test.getAlleleName() != "hello")
	{
		c = false;
	}

	test.setAlleleSequence("hello");
	if (test.getAlleleSequence() != "hello")
	{
		c = false;
	}

	test.setGeneName("hello");
	if (test.getGeneName() != "hello")
	{
		c = false;
	}

	test.setGeneTrait("hello");
	if (test.getGeneTrait() != "hello")
	{
		c = false;
	}

	test.setAlleleType("hello");
	if (test.getAlleleType() != "hello")
	{
		c = false;
	}
	return c;
}