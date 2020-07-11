
#include "Coada.h"
#include <exception>
#include <iostream>

using namespace std;


Coada::Coada() {
	/* Constructor */
	valori = new TElem[5]; /* SD: vector alocat dinamic */
	capacitate = 5;
	dim = 0;
	start = 0;
	stop = 0;
	/* post: s-a creat o coada vida */
}

void Coada::redimensionare() {
/*Functia primeste o coada caruia ii realoca un spatiu suficient de memorie
	pre: c este coada 
	post: c` este coada, capacitate = capacitate*2

	Complexitate timp: teta(n)
*/

	capacitate = capacitate * 2;
/* copiez valorile intr-un nou tablu alocat dinamic*/
	int *valori_copie = new TElem[capacitate];
	for (int i = start; i <= stop; i++)
		valori_copie[i] = valori[i];

/* sterg vechiul tablou alocat dinamic */
	Coada::~Coada();

	valori = valori_copie;	
}

void Coada::adauga(TElem elem) {
	/* Functia adauga un element la finalul cozii
	pre: c este o coada, elem este de tipul TElem
	post: c` este o coada, c` = c + elem
	
	Complexitate timp: teta(1) amortizata
	*/

	valori[stop] = elem;
	stop++;
	dim++;
	if (dim==capacitate)
		redimensionare();
}

//arunca exceptie daca coada e vida
TElem Coada::element() const {
	/* primul element introdus in coada 
	pre: c este o coada nevida

	Complexitate timp: teta(1)
	*/
	if (vida())
		throw exception("Coada este vida!");

	return valori[start];
}

TElem Coada::sterge() {
	/* sterge primul element introdus in coada 
	pre: c este o coada nevida

	Complexitate timp: teta(1)
	*/
	if (vida())
		throw exception("Coada este vida!");

	TElem first = valori[start]; /* primul element introdus */
	
	start++;

/* micsorez capacitatea cozii*/
	dim--;
	
	return first;
}

bool Coada::vida() const {
	/* verifica daca coada este vida 
	pre: c este o coada
	vida(c) = true daca dim = 0 , false in caz contrar
	
	Complexitate timp: teta(1)
	*/
	if (dim == 0)
		return true;

	return false;
}

TElem Coada::maxim() const
{
	if (vida())
		throw exception("Coada este vida!");

	int index = start;
	TElem maxim = valori[start];

	index++;
	while (index < stop)
	{
		if (maxim < valori[index])
			maxim = valori[index];

		index++;
	}

	return maxim;

/*
	Best Case,Worst Case,Average Case sunt identice
	Complexitate de timp O(n)
*/
}
Coada::~Coada() {
	/* Destructor */
	delete []valori;
}
