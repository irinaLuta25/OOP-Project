#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
#include "Preparat.h"

using namespace std;

class Comanda {
	const int idComanda;
	int nrPreparate;
	Preparat** listaPreparate;
	unsigned int timpLivrare;

	static float pretMinimComanda;

public:

	Comanda() :idComanda(0) {
		this->nrPreparate = 0;
		this->listaPreparate = nullptr;
		this->timpLivrare = 0;
	}

	//constructorul cu un parametru
	Comanda(int idComanda) :idComanda(idComanda) {
		this->nrPreparate = 0;
		this->listaPreparate = nullptr;
		this->timpLivrare = 0;
	}

	//constructorul cu toti parametri
	Comanda(int idComanda, int nrPreparate, Preparat** listaPreparate, int timpLivrare) :idComanda(idComanda) {
		if (nrPreparate > 0 && listaPreparate != nullptr) {
			this->nrPreparate = nrPreparate;
			this->listaPreparate = new Preparat * [this->nrPreparate];
			for (int i = 0; i < this->nrPreparate; i++) {
				this->listaPreparate[i] = new Preparat(*listaPreparate[i]);
			}
		}
		this->timpLivrare = timpLivrare;
	}

	//constructor de copiere
	Comanda(const Comanda& c) :idComanda(c.idComanda) {
		if (c.nrPreparate > 0 && c.listaPreparate != nullptr) {
			this->nrPreparate = c.nrPreparate;
			this->listaPreparate = new Preparat * [this->nrPreparate];
			for (int i = 0; i < this->nrPreparate; i++) {
				this->listaPreparate[i] = new Preparat(*c.listaPreparate[i]);
			}
		}
		this->timpLivrare = c.timpLivrare;
	}

	~Comanda() {
		for (int i = 0; i < this->nrPreparate; i++) {
			delete[] this->listaPreparate[i];
			this->listaPreparate[i] = nullptr;
		}
		delete[] this->listaPreparate;
		this->listaPreparate = nullptr;
	}

	//Getter preparate 
	Preparat** getPreparate() {
		return this->listaPreparate;
	}

	//setter Preparate
	void setPreparate(Preparat** listaPreparate, int nrPreparate) {
		if (nrPreparate > 0 && listaPreparate != nullptr) {
			this->nrPreparate = nrPreparate;
			this->listaPreparate = new Preparat * [this->nrPreparate];
			for (int i = 0; i < this->nrPreparate; i++) {
				this->listaPreparate[i] = new Preparat(*listaPreparate[i]);
			}
		}
	}

	//getter timpLivrare
	int getTimpLivrare() {
		return this->timpLivrare;
	}

	//setter timpLivrare
	void setTimpLivrare(int timpLivrare) {
		if (timpLivrare > 0) {
			this->timpLivrare = timpLivrare;
		}
	}

	//metoda calculTimpLivrare pe baza timpului de preparare maxim al produselor comandate + 30
	void calculTimpLivrare() {
		if (this->nrPreparate > 0) {
			int timpMax = this->listaPreparate[0]->getTimpPreparare();

			for (int i = 0; i < this->nrPreparate; i++) {
				int timpPreparare = listaPreparate[i]->getTimpPreparare();
				if (timpPreparare > timpMax) {
					timpMax = timpPreparare;
				}
			}
			this->timpLivrare = timpMax + 30;
		}
	}

	static void setPretMinim(float pretMinimComanda) {
		if (pretMinimComanda > 0) {
			Comanda::pretMinimComanda = pretMinimComanda;
		}
	}

	void afisare() {
		cout << "\n********AFISARE COMANDA************";
		cout << "\nID comanda: " << this->idComanda;
		if (this->nrPreparate > 0 && this->listaPreparate != nullptr) {
			cout << "\nNr preparate: " << this->nrPreparate;
			for (int i = 0; i < this->nrPreparate; i++) {
				cout << *this->listaPreparate[i];
			}
		}
		cout << "\nTimp de livrare: " << this->timpLivrare;
	}

	//overload =
	Comanda& operator=(const Comanda& c) {
		if (this != &c) {
			for (int i = 0; i < this->nrPreparate; i++) {
				delete[] this->listaPreparate[i];
				this->listaPreparate[i] = nullptr;
			}
			delete[] this->listaPreparate;
			this->listaPreparate = nullptr;

			if (c.nrPreparate > 0 && c.listaPreparate != nullptr) {
				this->nrPreparate = c.nrPreparate;
				this->listaPreparate = new Preparat * [this->nrPreparate];
				for (int i = 0; i < this->nrPreparate; i++) {
					this->listaPreparate[i] = new Preparat(*c.listaPreparate[i]);
				}
			}
			else {
				this->nrPreparate = 0;
				this->listaPreparate = nullptr;
			}
			this->timpLivrare = c.timpLivrare;
		}
		return *this;
	}

	//overoad <<
	friend ostream& operator<<(ostream& out, Comanda& c) {
		out << "\n<<<<<<<<<<<COMANDA<<<<<<<<<<<<<<<<<<";
		out << "\nID: " << c.idComanda;
		out << "\nNr preparate: " << c.nrPreparate;
		out << "\nLista preparate: ";
		for (int i = 0; i < c.nrPreparate; i++) {
			out << *c.listaPreparate[i];
		}
		out << "\nTimp livrare: " << c.timpLivrare << " minute";
		return out;
	}

	//overload >>
	friend istream& operator>>(istream& in, Comanda& c) {
		for (int i = 0; i < c.nrPreparate; i++) {
			delete[] c.listaPreparate[i];
			c.listaPreparate[i] = nullptr;
		}

		delete[] c.listaPreparate;
		c.listaPreparate = nullptr;

		cout << "\nIntroduceti nr de preparate: ";
		in >> c.nrPreparate;
		cout << "\nIntroduceti preparatele: ";
		c.listaPreparate = new Preparat * [c.nrPreparate];
		for (int i = 0; i < c.nrPreparate; i++) {
			c.listaPreparate[i] = new Preparat();
			in >> *(c.listaPreparate[i]);
		}
		cout << "\nIntroduceti timpul de livrare (min): ";
		in >> c.timpLivrare;
		return in;
	}

	//citire fisier
	friend ifstream& operator>>(ifstream& in, Comanda& c) {
		for (int i = 0; i < c.nrPreparate; i++) {
			delete[] c.listaPreparate[i];
			c.listaPreparate[i] = nullptr;
		}

		delete[] c.listaPreparate;
		c.listaPreparate = nullptr;

		in >> c.nrPreparate;
		c.listaPreparate = new Preparat * [c.nrPreparate];
		for (int i = 0; i < c.nrPreparate; i++) {
			c.listaPreparate[i] = new Preparat();
			in >> *(c.listaPreparate[i]);
		}
		in >> c.timpLivrare;
		return in;
	}

	//operator !
	bool operator!() {
		return this->pretMinimComanda < 15;
	}

	//operator indexare
	Preparat* operator[](int poz) {
		if (poz > 0 && this->nrPreparate != 0) {
			if (this->listaPreparate != nullptr) {
				return this->listaPreparate[poz];
			}
		}
	}

	friend class Preparat;
	friend class Client;
};