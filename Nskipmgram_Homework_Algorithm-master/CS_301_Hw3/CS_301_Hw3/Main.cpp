#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"

using namespace std;

void n_skip_m_grams(LinkedList& list, int skip, int grams, ofstream& outFile);

int main ()
{
	ifstream readFile;
	ofstream outFile;
	int skip, grams, again, temp;
	string endOfSentence;
	LinkedList list;
	char c;
	string infile = "quotes.txt", words;
	string outFileName = "nskipmgram_quotes.txt";
	
	readFile.open(infile);
	outFile.open(outFileName);
	if (!readFile.is_open())
	{
		cout << "Error: File could not be open..." << endl;
	}
	else // Insert each sentence of the paragraph on the linked list
	{
		while (!readFile.eof())
		{
			readFile >> words;
			list.insertLast(words);
		}
	}
	do
	{
		system("CLS");
		cout << "Please inset the number of words to skip: ";
		cin >> skip;
		cout << endl;
		cout << "Please enter the number of words to pick: ";
		cin >> grams;
		cout << endl;

		cout << skip << "-skip-" << grams << "-grams:" << endl;
		n_skip_m_grams(list, skip, grams, outFile);

		cout << "Would you like to try it again? [1]Try Again [2]Quit: ";
		cin >> again;
		cout << endl;
	} while (again == 1);

	system("pause");
	return 0;
}

void n_skip_m_grams(LinkedList& list, int skip, int grams, ofstream& outFile)
{
	for (int i = 0; i < list.getCount(); i++)
	{
		int remain = list.getCount() - i;
		if ((remain - 1) >= ((skip + 1) * (grams - 1)))
		{
			if (i != 0)
			{
				cout << ", ";
				outFile << ", ";
			}
			else
			{
				cout << "\n";
				outFile << "\n";
			}
			for (int j = i, k = 0; k < grams; j += skip, j++, k++)
			{
				cout << list.getData(j);
				outFile << list.getData(j);
				if (k != grams - 1)
				{
					cout << " ";
					outFile << " ";
				}
			}
		}
	}
	cout << endl << endl;
	system("pause");
	cout << endl;
	outFile << endl << endl;
}