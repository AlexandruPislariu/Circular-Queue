#pragma once
#include <vector>
using namespace std;

typedef int TElem;

class Coada
{
private:
	/* aici reprezentarea (abstractizarea cozii prin atribute) */
	int *valori; /* SD : vector alocat dinamic */
	int capacitate; /* capacitatea vectorului alocat dinamic */
	int dim; /* numarul de elemente */
	int start;
	int stop;
	void redimensionare();

public:
	/* constructorul implicit al cozii */
	Coada();

	//adauga un element in coada
	void adauga(TElem e);

	//acceseaza elementul cel mai devreme introdus in coada 
	//arunca exceptie daca coada e vida
	TElem element() const;

	//sterge elementul cel mai devreme introdus in coada si returneaza elementul sters (principiul FIFO)
	//arunca exceptie daca coada e vida
	TElem sterge();

	//verifica daca coada e vida;
	bool vida() const;

	//Elementul maxim din coada
	//Arunca exceptie in cazul in care coada este vida
	TElem maxim() const;

	// destructorul cozii
	~Coada();
};