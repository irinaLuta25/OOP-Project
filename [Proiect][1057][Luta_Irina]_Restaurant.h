#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
#include "MateriiPrime.h"

using namespace std;

class Restaurant {
	int nrMateriiPrimeStoc;
	MateriiPrime** listaStoc;

public:

	Restaurant() {
		this->nrMateriiPrimeStoc = 0;
		this->listaStoc = nullptr;
	}

	//constructor cu un param
	Restaurant(int nrMateriiPrimeStoc) {
		if (nrMateriiPrimeStoc > 0) {
			this->nrMateriiPrimeStoc = nrMateriiPrimeStoc;
		}
	}

	//constructor cu toti param
	Restaurant(int nrMateriiPrimeStoc, MateriiPrime** listaStoc) {
		if (nrMateriiPrimeStoc > 0 && listaStoc != nullptr) {
			this->nrMateriiPrimeStoc = nrMateriiPrimeStoc;
			this->listaStoc = new MateriiPrime * [this->nrMateriiPrimeStoc];

			for (int i = 0; i < this->nrMateriiPrimeStoc; i++) {
				this->listaStoc[i] = new MateriiPrime(*listaStoc[i]);
			}
		}
	}

	//constructor copiere
	Restaurant(const Restaurant& r) {
		if (r.nrMateriiPrimeStoc > 0 && r.listaStoc != nullptr) {
			this->nrMateriiPrimeStoc = r.nrMateriiPrimeStoc;
			this->listaStoc = new MateriiPrime * [this->nrMateriiPrimeStoc];

			for (int i = 0; i < this->nrMateriiPrimeStoc; i++) {
				this->listaStoc[i] = new MateriiPrime(*r.listaStoc[i]);
			}
		}
	}

	//overload =
	Restaurant& operator=(const Restaurant& r) {
		if (this != &r) {
			for (int i = 0; i < this->nrMateriiPrimeStoc; i++) {
				delete this->listaStoc[i];
				this->listaStoc[i] = nullptr;
			}

			delete[] this->listaStoc;
			this->listaStoc = nullptr;

			if (r.nrMateriiPrimeStoc > 0 && r.listaStoc != nullptr) {
				this->nrMateriiPrimeStoc = r.nrMateriiPrimeStoc;
				this->listaStoc = new MateriiPrime * [this->nrMateriiPrimeStoc];

				for (int i = 0; i < this->nrMateriiPrimeStoc; i++) {
					this->listaStoc[i] = new MateriiPrime(*r.listaStoc[i]);
				}
			}
		}
		return *this;
	}

	~Restaurant() {
		for (int i = 0; i < this->nrMateriiPrimeStoc; i++) {
			delete this->listaStoc[i];
			this->listaStoc[i] = nullptr;
		}

		delete[] this->listaStoc;
		this->listaStoc = nullptr;
	}

	//overload <<
	friend ostream& operator<<(ostream& out, const Restaurant& r) {
		out << "\nNr materii prime din stoc: " << r.nrMateriiPrimeStoc;
		out << "\nLista de materii prime din stoc: ";
		for (int i = 0; i < r.nrMateriiPrimeStoc; i++) {
			out << *r.listaStoc[i];
		}
		return out;
	}

	//overload >>
	friend istream& operator>>(istream& in, Restaurant& r) {
		for (int i = 0; i < r.nrMateriiPrimeStoc; i++) {
			delete r.listaStoc[i];
			r.listaStoc[i] = nullptr;
		}

		delete[] r.listaStoc;
		r.listaStoc = nullptr;

		cout << "\n: Introduceti numarul de materii prime din stoc: ";
		in >> r.nrMateriiPrimeStoc;
		cout << "\nIntroduceti materiile prime din stoc: ";
		r.listaStoc = new MateriiPrime * [r.nrMateriiPrimeStoc];
		for (int i = 0; i < r.nrMateriiPrimeStoc; i++) {
			r.listaStoc[i] = new MateriiPrime();
			in >> *(r.listaStoc[i]);
		}
		return in;
	}

	int getNrMateriiPrimeStoc() {
		return this->nrMateriiPrimeStoc;
	}

	void setNrMateriiPrimeStoc(int nrMateriiPrimeStoc) {
		if (nrMateriiPrimeStoc > 0) {
			this->nrMateriiPrimeStoc = nrMateriiPrimeStoc;
		}
	}

	MateriiPrime** getListaStoc() {
		return this->listaStoc;
	}

	void setStoc(MateriiPrime** listaStoc, int nrMateriiPrimeStoc) {
		if (nrMateriiPrimeStoc > 0 && listaStoc != nullptr) {
			this->nrMateriiPrimeStoc = nrMateriiPrimeStoc;
			this->listaStoc = new MateriiPrime * [this->nrMateriiPrimeStoc];
			for (int i = 0; i < this->nrMateriiPrimeStoc; i++) {
				this->listaStoc[i] = new MateriiPrime(*listaStoc[i]);
			}
		}
	}

	//metoda 1 - afisare
	void afisare() {
		cout << "\n********AFISARE************";
		if (this->nrMateriiPrimeStoc > 0 && this->listaStoc != nullptr) {
			cout << "\nNr de materii prime aflate in stoc: " << this->nrMateriiPrimeStoc;
			cout << "\nLista materiilor prime din stoc: ";
			for (int i = 0; i < this->nrMateriiPrimeStoc; i++) {
				cout << *this->listaStoc[i];
			}
		}
	}

	//metoda 2

	bool verificaStoc(const Comanda& c) {

	}

	void proceseazaComanda(const Comanda& c) {

	}
};