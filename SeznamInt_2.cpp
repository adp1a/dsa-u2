#include <stdio.h>
#include <tchar.h>

#include <iostream>
using namespace std;
#include "SeznamInt_2.h"

int* SeznamInt_2::DEFAULT_VALUE = nullptr;


SeznamInt_2::SeznamInt_2() 
{ 
	Init();
}

SeznamInt_2::~SeznamInt_2() { }

void SeznamInt_2::Init()
{
	for (int i = 0; i < CAPACITY; i++) {
		p_hodnoty[i] = DEFAULT_VALUE;
	}
}

void SeznamInt_2::Add(int i, int value)
{
	if (i < 0 || i >= CAPACITY)
		return;

	if (p_hodnoty[i] != DEFAULT_VALUE)
		delete p_hodnoty[i];

	p_hodnoty[i] = new int(value);
}

void SeznamInt_2::Remove(int i)
{
	if (i < 0 || i >= CAPACITY)
		return;

	if (p_hodnoty[i] != DEFAULT_VALUE) {
		delete p_hodnoty[i];
		p_hodnoty[i] = DEFAULT_VALUE;
	}
}

// ----------------------------------

int SeznamInt_2::GetMin() const
{
	int* m = p_hodnoty[0];
	for (int i = 0; i < CAPACITY; i++)
		if ((p_hodnoty[i] != DEFAULT_VALUE) && (*m > *p_hodnoty[i]))
			m = p_hodnoty[i];
	return *m;
}

// Spocita prumernou hodnotu z hodnot zapsanych v poli na pozicich.
double SeznamInt_2::CalcAvg() const
{
	int s = 0;	// suma platnych hodnot
	int n = 0;	// pocet platnych hodnot
	for (int i = 0; i < CAPACITY; i++)
		if (p_hodnoty[i] != DEFAULT_VALUE)
		{
			s += *p_hodnoty[i];
			n++;
		}
	return (double)s / n;
}

// --------------------------------------

int SeznamInt_2::operator[](int id)
{
	if (id < 0 || id >= CAPACITY)
	{
		return -1; // id není v rozsahu
	}

	if (p_hodnoty[id] == nullptr)
	{
		return -1; // hodnota na id je prázdná
	}

	return *p_hodnoty[id];
}

// vytiskne pole hodnot na standardni vystup
/*friend*/ ostream &operator<<(ostream &os, SeznamInt_2 o)
{
	for (int i = 0; i < o.CAPACITY; i++)
		if (o.p_hodnoty[i] == o.DEFAULT_VALUE)
			os << "- x -";
		else
			os << "- " << *o.p_hodnoty[i] << " -";
	return os;
}

// --------------------------------------

/*static*/ int SeznamInt_2::CalcPosition(int *p_hodnoty, int n, int *p_prvek)
{
	for (int i = 0; i < n; ++i)
	{
		if (p_hodnoty[i] == *p_prvek)
		{
			return i;
		}
	}

	return -1; // nenalezeno
}