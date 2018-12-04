#include <iostream>
#include <string>
#include <fstream>
#ifndef ALLELE_H
#define ALLELE_H

using namespace std;

class Allele
{
  private:
	string nucleotideSequence;
	string variantName;
	string variantTypeName;

  public:
	void setNucleotideSequence(string sequence);
	string getNucleotideSequence();

	void setVariantName(string vName);
	string getVariantName();

	void setVariantType(int vType);
	string getVariantTypeName();

	bool unitTest();
};
#endif