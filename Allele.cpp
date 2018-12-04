#include <iostream>
#include <string>
#include <fstream>
#include "Allele.h"

using namespace std;

void Allele::setNucleotideSequence(string sequence)
{
	nucleotideSequence = sequence;
}
string Allele::getNucleotideSequence()
{
	return nucleotideSequence;
}
void Allele::setVariantName(string vName)
{
	variantName = vName;
}
string Allele::getVariantName()
{
	return variantName;
}
void Allele::setVariantType(int vType)
{
	if (vType == 1)
	{
		variantTypeName = "Dominant";
	}
	else if (vType == 2)
	{
		variantTypeName = "Recessive";
	}
	else
	{
		variantTypeName = "Error, must choose 1 or 2";
	}
}
string Allele::getVariantTypeName()
{
	return variantTypeName;
}
bool Allele::unitTest()
{
	Allele testAllele;
	bool a = true;

	testAllele.setNucleotideSequence("hello");
	if (testAllele.getNucleotideSequence() != "hello")
	{
		a = false;
	}

	testAllele.setVariantName("hello");
	if (testAllele.getVariantName() != "hello")
	{
		a = false;
	}

	testAllele.setVariantType(1);
	if (testAllele.getVariantTypeName() != "Dominant")
	{
		a = false;
	}
	testAllele.setVariantType(2);
	if (testAllele.getVariantTypeName() != "Recessive")
	{
		a = false;
	}
	testAllele.setVariantType(13412);
	if (testAllele.getVariantTypeName() != "Error, must choose 1 or 2")
	{
		a = false;
	}

	return a;
}