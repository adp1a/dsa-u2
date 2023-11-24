#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <sstream>
using namespace std;

#include "SeznamInt_1.h"
#include "SeznamInt_2.h"


int main()
{
	int pos;
	bool exist, comp;
	const int CISLA_1_CAPACITY = 5;
	SeznamInt_1 cisla_1(CISLA_1_CAPACITY);
	SeznamInt_1* cisla_1_b;

	cisla_1.Add(5);
	cisla_1.Add(4);
	cisla_1.Add(7);
	cout << cisla_1;
	cisla_1.Remove(1);
	cout << cisla_1;

	pos = cisla_1.IndexOf(7);
	printf("%d ", pos);
	pos = cisla_1.IndexOf(4);
	printf("%d ", pos);

	exist = cisla_1.Contains(7);
	printf("%d ", exist);
	exist = cisla_1.Contains(4);
	printf("%d ", exist);

	cisla_1_b = new SeznamInt_1(cisla_1);
	comp = cisla_1 == *cisla_1_b;
	printf("%d ", comp);

	printf("\n");

	delete cisla_1_b;
	cisla_1_b = NULL;

	// -----------------------
	SeznamInt_2 cisla_2;

	cisla_2.Add(0, 15);
	cisla_2.Add(2, 10);
	cisla_2.Add(5, 25);

	cout << cisla_2;
	cout << '\n';

	// Nacteni dat ze streamu
	SeznamInt_1 seznamZeStreamu(5);
	std::string inputString = "1 2 3 4 5";
	std::istringstream input(inputString);
	input >> seznamZeStreamu;
	std::cout << "TEST NACTENI DAT ZE STREAMU: " << seznamZeStreamu;

	// UKOL (1. BOD)
	int* kopiePole = cisla_1.Copy();
	std::cout << "\n\n--- TEST HODNOT POLE ---" << std::endl;
	std::cout << "Puvodni pole: " << cisla_1;
	std::cout << "Nakopirovane pole: [";
	for (int i = 0; i < cisla_1.Count(); i++) {
		std::cout << kopiePole[i];
		if (i < cisla_1.Count() - 1)
			std::cout << ";";
	}
	std::cout << "]" << std::endl;

	// UKOL (2. BOD) REALOKACE POLE
	std::cout << "\n\n--- TEST REALOKACE POLE ---" << std::endl;
	SeznamInt_1 poleRealokace(2);
	poleRealokace.Add(0);
	poleRealokace.Add(1);
	std::cout << "Pole PRED realokaci: " << poleRealokace;
	poleRealokace.Add(2);
	std::cout << "Pole PO realokaci: " << poleRealokace;

	// UKOL (3. BOD) SeznamInt_2.cpp
	std::cout << "\n\n--- TEST SeznamInt_2 ---" << std::endl;
	SeznamInt_2 seznam2;
	seznam2.Add(0, 0);
	seznam2.Add(1, 1);
	seznam2.Add(2, 2);
	seznam2.Add(3, 3);
	seznam2.Add(4, 4);
	seznam2.Add(5, 5);

	int min = seznam2.GetMin();
	std::cout << (min == 0) << std::endl;

	int h  = seznam2[10];   // -1
	int h2 = seznam2[110];  // -1
	int h3 = seznam2[1];    //  1

	std::cout << h << std::endl;
	std::cout << h2 << std::endl;
	std::cout << h3 << std::endl;

	// ODSTRANENI HODNOTY
	seznam2.Remove(5);
	std::cout << seznam2;

	return 0;
}