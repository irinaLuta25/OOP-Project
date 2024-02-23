#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
#include "MateriiPrime.h"

using namespace std;

class Preparat {
	const int idPreparat;
	string denumire;
	MateriiPrime** listaMateriiPrime;
	int nrMateriiPrime;
	int timpPreparare;
	float pret;

public:

	/*MateriiPrime* operator[](int pozitie) {

	}*/

	//constructor default
	Preparat() :idPreparat(0) {
		this->denumire = "-";
		this->listaMateriiPrime = nullptr;
		this->nrMateriiPrime = 0;
		this->timpPreparare = 0;
		this->pret = 0;
	}

	//constructor cu un parametru
	Preparat(int idPreparat) :idPreparat(idPreparat) {
		this->denumire = "-";
		this->listaMateriiPrime = nullptr;
		this->nrMateriiPrime = 0;
		this->timpPreparare = 0;
		this->pret = 0;
	}

	//constructor cu toti parametri - CUM ADICA NU E INITIALIZAT
	Preparat(int idPreparat, string denumire, MateriiPrime** listaMateriiPrime, int nrMateriiPrime, int timpPreparare, float pret) :idPreparat(idPreparat) {
		if (denumire.length() > 0) {
			this->denumire = denumire;
		}
		if (nrMateriiPrime > 0 && listaMateriiPrime != nullptr) {
			this->nrMateriiPrime = nrMateriiPrime;
			this->listaMateriiPrime = new MateriiPrime * [this->nrMateriiPrime];
			for (int i = 0; i < this->nrMateriiPrime; i++) {
				this->listaMateriiPrime[i] = new MateriiPrime(*listaMateriiPrime[i]);
			}
		}
		if (timpPreparare > 0) {
			this->timpPreparare = timpPreparare;
		}
		if (pret > 0) {
			this->pret = pret;
		}
	}

	//constructor de copiere 
	Preparat(const Preparat& p) :idPreparat(p.idPreparat) {
		this->timpPreparare = p.timpPreparare;
		this->pret = p.pret;
		this->denumire = p.denumire;
		if (p.nrMateriiPrime > 0 && p.listaMateriiPrime != nullptr) {
			this->nrMateriiPrime = p.nrMateriiPrime;
			this->listaMateriiPrime = new MateriiPrime * [this->nrMateriiPrime];
			for (int i = 0; i < this->nrMateriiPrime; i++) {
				this->listaMateriiPrime[i] = new MateriiPrime(*p.listaMateriiPrime[i]);
			}
		}
	}

	//overload =
	Preparat& operator=(const Preparat& p) {
		if (this != &p) {
			for (int i = 0; i < nrMateriiPrime; i++) {
				delete this->listaMateriiPrime[i];
				this->listaMateriiPrime[i] = nullptr;
			}

			delete[] this->listaMateriiPrime;
			this->listaMateriiPrime = nullptr;

			this->timpPreparare = p.timpPreparare;
			this->pret = p.pret;
			this->denumire = p.denumire;
			if (p.nrMateriiPrime > 0 && p.listaMateriiPrime != nullptr) {
				this->nrMateriiPrime = p.nrMateriiPrime;
				this->listaMateriiPrime = new MateriiPrime * [this->nrMateriiPrime];
				for (int i = 0; i < this->nrMateriiPrime; i++) {
					this->listaMateriiPrime[i] = new MateriiPrime(*p.listaMateriiPrime[i]);
				}
			}
			else {
				this->nrMateriiPrime = 0;
				this->listaMateriiPrime = nullptr;
			}
		}
		return *this;
	}

	//overload <<
	friend ostream& operator<<(ostream& out, const Preparat& p) {
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nID: " << p.idPreparat;
		out << "\nDenumire: " << p.denumire;
		if (p.nrMateriiPrime > 0 && p.listaMateriiPrime != nullptr) {
			out << "\nNr materii prime: " << p.nrMateriiPrime;
			for (int i = 0; i < p.nrMateriiPrime; i++) {
				out << *p.listaMateriiPrime[i] << " "; //aici era fara spatiu in s8
			}
		}
		out << "\nTimp preparare: " << p.timpPreparare << " minute";
		out << "\nPret: " << p.pret << " lei";
		return out;
	}

	//overaload >>
	friend istream& operator>>(istream& in, Preparat& p) {
		for (int i = 0; i < p.nrMateriiPrime; i++) {
			delete p.listaMateriiPrime[i];
			p.listaMateriiPrime[i] = nullptr;
		}

		delete[] p.listaMateriiPrime;
		p.listaMateriiPrime = nullptr;

		cout << "\nIntroduceti denumirea: ";
		in >> p.denumire;
		cout << "\nIntroduceti timpul de preparare (min): ";
		in >> p.timpPreparare;
		cout << "\nIntroduceti nr de materii prime: ";
		in >> p.nrMateriiPrime;
		cout << "\nIntroduceti materiile prime: ";
		p.listaMateriiPrime = new MateriiPrime * [p.nrMateriiPrime];
		for (int i = 0; i < p.nrMateriiPrime; i++) {
			p.listaMateriiPrime[i] = new MateriiPrime();
			in >> *(p.listaMateriiPrime[i]);
		}
		cout << "\nIntroduceti pretul (lei): ";
		in >> p.pret;
		return in;
	}

	//citire fisier
	friend ifstream& operator>>(ifstream& in, Preparat& p) {
		for (int i = 0; i < p.nrMateriiPrime; i++) {
			delete p.listaMateriiPrime[i];
			p.listaMateriiPrime[i] = nullptr;
		}

		delete[] p.listaMateriiPrime;
		p.listaMateriiPrime = nullptr;

		in >> p.denumire;
		in >> p.timpPreparare;
		in >> p.nrMateriiPrime;
		p.listaMateriiPrime = new MateriiPrime * [p.nrMateriiPrime];
		for (int i = 0; i < p.nrMateriiPrime; i++) {
			p.listaMateriiPrime[i] = new MateriiPrime();
			in >> *(p.listaMateriiPrime[i]);
		}
		in >> p.pret;
		return in;
	}

	//operator >
	bool operator>(const Preparat& p) {
		return this->pret > p.pret;
	}

	//operator cast
	operator int() const {
		return this->pret;
	}

	string getDenumire() {
		return this->denumire;
	}

	void setDenumire(string denumire) {
		if (denumire.length() > 0) {
			this->denumire = denumire;
		}
	}

	int getTimpPreparare() {
		return this->timpPreparare;
	}

	void setTimpPreparare(int timpPreparare) {
		if (timpPreparare > 0) {
			this->timpPreparare = timpPreparare;
		}
	}

	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}

	int getNrMateriiPrime() {
		return this->nrMateriiPrime;
	}

	void setNrMateriiPrime() {
		if (nrMateriiPrime > 0) {
			this->nrMateriiPrime = nrMateriiPrime;
		}
	}

	MateriiPrime** getMateriiPrime() {
		return this->listaMateriiPrime;
	}

	void setMateriiPrime(MateriiPrime** listaMateriiPrime, int nrMateriiPrime) {
		if (nrMateriiPrime > 0 && listaMateriiPrime != nullptr) {
			this->nrMateriiPrime = nrMateriiPrime;
			this->listaMateriiPrime = new MateriiPrime * [this->nrMateriiPrime];
			for (int i = 0; i < this->nrMateriiPrime; i++) {
				this->listaMateriiPrime[i] = new MateriiPrime(*listaMateriiPrime[i]);
			}
		}
	}

	//metoda1 - afisare
	void afisare() {
		cout << "\n********AFISARE************";
		cout << "\nID preparat: " << this->idPreparat;
		cout << "\nDenumire preparat: " << this->denumire;
		cout << "\nNr materii prime: " << this->nrMateriiPrime;
		if (this->nrMateriiPrime > 0 && this->listaMateriiPrime != nullptr) {
			cout << "\nNr materii prime: " << this->nrMateriiPrime;
			for (int i = 0; i < this->nrMateriiPrime; i++) {
				cout << *this->listaMateriiPrime[i];
			}
		}
		cout << "\nTimp preparare: " << this->timpPreparare << " minute";
		cout << "\nPret: " << this->pret;
	}

	//metoda2 - reducere pret preparat
	void aplicaReducere(float reducere) {
		if (reducere > 0 && reducere < 1) {
			this->pret = this->pret * (1 - reducere);
		}
	}

	~Preparat() {
		for (int i = 0; i < nrMateriiPrime; i++) {
			delete this->listaMateriiPrime[i];
			this->listaMateriiPrime[i] = nullptr;
		}

		delete[] this->listaMateriiPrime;
		this->listaMateriiPrime = nullptr;
	}

	friend class Comanda;
};