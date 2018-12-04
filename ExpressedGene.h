#include <iostream>
#include <string>
#include <fstream>
#ifndef EXPRESSEDGENE_H
#define EXPRESSEDGENE_H

using namespace std;

class ExpressedGene
{
  private:
	string geneName;
	string geneTrait;
	string expressedAlleleName;
	string expressedAlleleType;
	string expressedAlleleSequence;

  public:
	void setGeneName(string name);
	string getGeneName();

	void setGeneTrait(string type);
	string getGeneTrait();

	void setAlleleName(string AName);
	string getAlleleName();

	void setAlleleType(string Atype);
	string getAlleleType();

	void setAlleleSequence(string sequence);
	string getAlleleSequence();

	bool unitTest();
};
#endif