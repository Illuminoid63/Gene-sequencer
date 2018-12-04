#include <iostream>
#include <string>
#include <fstream>
#include "Allele.h"
#ifndef GENE_H
#define GENE_H

using namespace std;

class Gene
{
  private:
	string geneName;
	string traitType;
	Allele AlleleA;
	Allele AlleleB;

  public:
	void setGeneName(string name);
	string getGeneName();

	void setTraitType(string type);
	string getTraitType();

	void setAlleleA(Allele Allele1);
	Allele getAlleleA();
	void setAlleleB(Allele Allele2);
	Allele getAlleleB();

	bool unitTest();
};
#endif