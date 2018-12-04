/*	Project:    Gene Analyzer
	Name:       Kai Kuebler
    Partner:    N/A
    Class:      example: CSC 1810 - Section 1
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Allele.h"
#include "Gene.h"
#include "Chromosome.h"
#include "ExpressedGene.h"

using namespace std;

void Menu()
{
	int menuChoice;
	int loop = 0;
	string geneName;
	string traitType;
	string allele1Variant;
	int allele1Type;
	string allele1Sequence;
	string allele2Variant;
	int allele2Type;
	string allele2Sequence;
	char inputNewGene = 'y';

	Gene myGene;
	Allele firstAllele;
	Allele secondAllele;
	Chromosome myChromosome;
	ExpressedGene EGene;

	vector<ExpressedGene> expressedGenes;

	while (loop == 0)
	{
		cout << "1- create chromosome" << endl;
		cout << "2- analyze chromosome" << endl;
		cout << "3- Output chromosome to file" << endl;
		cout << "4- input chromosome from file" << endl;
		cout << "5- combine chromosomes" << endl;
		cout << "6- exit" << endl;
		cout << "7- run unit tests" << endl;

		cin >> menuChoice;

		if (menuChoice == 1)
		{
			while (inputNewGene == 'y')
			{
				cout << "What is the Name of the new gene?" << endl;
				cin >> geneName;
				myGene.setGeneName(geneName);

				cin.ignore();

				cout << "What is the gene trait?" << endl;
				getline(cin, traitType);
				myGene.setTraitType(traitType);

				cout << "What is the allele 1 variant?" << endl;
				cin >> allele1Variant;
				firstAllele.setVariantName(allele1Variant);

				cout << "Input 1 if the allele is Dominant or input 2 if the allele is Recessive" << endl;
				cin >> allele1Type;
				firstAllele.setVariantType(allele1Type);

				if ((allele1Type != 1) && (allele1Type != 2))
				{
					cout << "Error: input must be either 1 or 2" << endl;
					break;
				}

				cout << "What is the Allele 1 nucleotide sequence?" << endl;
				cin >> allele1Sequence;
				firstAllele.setNucleotideSequence(allele1Sequence);

				cout << "What is the allele 2 variant?" << endl;
				cin >> allele2Variant;
				secondAllele.setVariantName(allele2Variant);

				cout << "Input 1 if the allele is Dominant or input 2 if the allele is Recessive" << endl;
				cin >> allele2Type;
				secondAllele.setVariantType(allele2Type);

				if ((allele2Type != 1) && (allele2Type != 2))
				{
					cout << "Error: input must be either 1 or 2" << endl;
					break;
				}

				cout << "What is the Allele 2 nucleotide sequence?" << endl;
				cin >> allele2Sequence;
				secondAllele.setNucleotideSequence(allele2Sequence);

				if ((allele1Type == 1) && (allele2Type == 1))
				{
					cout << "Error: only one allele can be dominant" << endl;
					break;
				}
				if ((allele1Type == 2) && (allele2Type == 2))
				{
					cout << "Error: only one allele can be recessive" << endl;
					break;
				}

				myGene.setAlleleA(firstAllele);
				myGene.setAlleleB(secondAllele);

				myChromosome.setGeneVector(myGene);

				cout << "Would you like to input another Gene? (y/n)" << endl;
				cin >> inputNewGene;
			}
		}
		if (menuChoice == 2)
		{
			int h = (expressedGenes.size() - 1);

			ExpressedGene currentGene;

			for (int i = 0; i < h; ++i)
			{
				currentGene = expressedGenes.at(i);

				cout << "Gene " << (i + 1) << endl;
				cout << "Name: " << currentGene.getGeneName() << endl;
				cout << "Genetic trait: " << currentGene.getGeneTrait() << endl;
				cout << "Expressed Allele: " << currentGene.getAlleleName() << " - " << currentGene.getAlleleType() << endl;
				cout << "Nucleotide Sequence: " << currentGene.getAlleleSequence() << endl;
			}
		}
		if (menuChoice == 3)
		{
			myChromosome.writeChromosomeToFile();
		}
		if (menuChoice == 4)
		{
			expressedGenes.clear();

			ifstream readChromosome;

			string textFile;
			string nameOfGene;
			string trait;
			string firstAlleleVariant;
			string firstAlleleType;
			string firstAlleleSequence;
			string secondAlleleVariant;
			string secondAlleleType;
			string secondAlleleSequence;

			cout << "What file do you want to import from?" << endl;
			cin >> textFile;

			readChromosome.open(textFile);

			while (readChromosome.good())
			{
				getline(readChromosome, nameOfGene, ',');
				getline(readChromosome, trait, ',');
				getline(readChromosome, firstAlleleVariant, ',');
				getline(readChromosome, firstAlleleType, ',');
				getline(readChromosome, firstAlleleSequence, ',');
				getline(readChromosome, secondAlleleVariant, ',');
				getline(readChromosome, secondAlleleType, ',');
				getline(readChromosome, secondAlleleSequence, '\n');

				if (firstAlleleType == "Dominant")
				{
					EGene.setGeneName(nameOfGene);
					EGene.setGeneTrait(trait);
					EGene.setAlleleName(firstAlleleVariant);
					EGene.setAlleleType(firstAlleleType);
					EGene.setAlleleSequence(firstAlleleSequence);
				}
				if (secondAlleleType == "Dominant")
				{
					EGene.setGeneName(nameOfGene);
					EGene.setGeneTrait(trait);
					EGene.setAlleleName(secondAlleleVariant);
					EGene.setAlleleType(secondAlleleType);
					EGene.setAlleleSequence(secondAlleleSequence);
				}
				expressedGenes.push_back(EGene);
			}

			readChromosome.close();
		}
		if (menuChoice == 5)
		{
			Chromosome a;
			Chromosome b;
			Chromosome c;
			Gene current1Gene;
			Allele curr1allele;
			Allele curr2allele;

			ifstream read1Chromosome;

			string textFile;
			string textFile2;
			string nameOfGene;
			string trait;
			string firstAlleleVariant;
			string firstAlleleType;
			string firstAlleleSequence;
			string secondAlleleVariant;
			string secondAlleleType;
			string secondAlleleSequence;

			cout << "What is the first file do you want to import from?" << endl;
			cin >> textFile;

			read1Chromosome.open(textFile);
			while (!read1Chromosome.eof())
			{
				getline(read1Chromosome, nameOfGene, ',');
				getline(read1Chromosome, trait, ',');
				getline(read1Chromosome, firstAlleleVariant, ',');
				getline(read1Chromosome, firstAlleleType, ',');
				getline(read1Chromosome, firstAlleleSequence, ',');
				getline(read1Chromosome, secondAlleleVariant, ',');
				getline(read1Chromosome, secondAlleleType, ',');
				getline(read1Chromosome, secondAlleleSequence, '\n');

				current1Gene.setGeneName(nameOfGene);
				current1Gene.setTraitType(trait);

				curr1allele.setVariantName(firstAlleleVariant);
				curr1allele.setNucleotideSequence(firstAlleleSequence);
				if (firstAlleleType == "Dominant")
				{
					curr1allele.setVariantType(1);
				}
				if (firstAlleleType == "Recessive")
				{
					curr1allele.setVariantType(2);
				}
				if (secondAlleleType == "Dominant")
				{
					curr2allele.setVariantType(1);
				}
				if (secondAlleleType == "Recessive")
				{
					curr2allele.setVariantType(2);
				}
				curr2allele.setVariantName(secondAlleleVariant);
				curr2allele.setNucleotideSequence(secondAlleleSequence);

				current1Gene.setAlleleA(curr1allele);
				current1Gene.setAlleleB(curr2allele);

				a.setGeneVector(current1Gene);
			}
			read1Chromosome.close();

			ifstream read2Chromosome;

			cout << "What is the second file do you want to import from?" << endl;
			cin >> textFile2;

			read2Chromosome.open(textFile2);
			while (!read2Chromosome.eof())
			{
				getline(read2Chromosome, nameOfGene, ',');
				getline(read2Chromosome, trait, ',');
				getline(read2Chromosome, firstAlleleVariant, ',');
				getline(read2Chromosome, firstAlleleType, ',');
				getline(read2Chromosome, firstAlleleSequence, ',');
				getline(read2Chromosome, secondAlleleVariant, ',');
				getline(read2Chromosome, secondAlleleType, ',');
				getline(read2Chromosome, secondAlleleSequence, '\n');

				current1Gene.setGeneName(nameOfGene);
				current1Gene.setTraitType(trait);

				curr1allele.setVariantName(firstAlleleVariant);
				curr1allele.setNucleotideSequence(firstAlleleSequence);
				if (firstAlleleType == "Dominant")
				{
					curr1allele.setVariantType(1);
				}
				if (firstAlleleType == "Recessive")
				{
					curr1allele.setVariantType(2);
				}
				if (secondAlleleType == "Dominant")
				{
					curr2allele.setVariantType(1);
				}
				if (secondAlleleType == "Recessive")
				{
					curr2allele.setVariantType(2);
				}
				curr2allele.setVariantName(secondAlleleVariant);
				curr2allele.setNucleotideSequence(secondAlleleSequence);

				current1Gene.setAlleleA(curr1allele);
				current1Gene.setAlleleB(curr2allele);

				b.setGeneVector(current1Gene);
			}
			read2Chromosome.close();

			c = a.operator+(b);

			cout << "What file would you like to output the new chromosome to?" << endl;
			string File;
			cin >> File;

			Gene myCurrentGene;
			Allele Allele1;
			Allele Allele2;

			ofstream mystream;
			mystream.open(File, std::iostream::app);

			for (int i = 0; i < (c.vectorSize() - 1); ++i) //the files end on a newline so it add an extra element to the vector that isn't a gene so i have -1 to get rid of that last element
			{
				myCurrentGene = c.findGene(i);

				Allele1 = myCurrentGene.getAlleleA();
				Allele2 = myCurrentGene.getAlleleB();

				mystream << myCurrentGene.getGeneName() << "," << myCurrentGene.getTraitType() << "," << Allele1.getVariantName() << "," << Allele1.getVariantTypeName() << "," << Allele1.getNucleotideSequence()
						 << "," << Allele2.getVariantName() << "," << Allele2.getVariantTypeName() << "," << Allele2.getNucleotideSequence() << "\n";
			}
		}
		if (menuChoice == 6)
		{
			break;
		}
		if (menuChoice == 7)
		{
			Chromosome test;

			if (test.runAllUnitTests() == false)
			{
				cout << "fail" << endl;
			}
			else
			{
				cout << "pass" << endl;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	Menu();
	{
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}