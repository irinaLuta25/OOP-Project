#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
#include "Preparat.h"

using namespace std;

class Meniu {
	int nrPreparate;
	Preparat** listaPreparate;

public:

	Meniu() {
		this->nrPreparate = 0;
		this->listaPreparate = nullptr;
	}

	//constructor doar cu 1 param
	Meniu(int nrPreparate) {
		if (nrPreparate > 0)
			this->nrPreparate = nrPreparate;
		this->listaPreparate = nullptr;
	}

	//constructor cu toti param
	Meniu(int nrPreparate, Preparat** listaPreparate) {
		if (nrPreparate > 0 && listaPreparate != nullptr)
			this->nrPreparate = nrPreparate;

		this->listaPreparate = new Preparat * [this->nrPreparate];
		for (int i = 0; i < this->nrPreparate; i++) {
			this->listaPreparate[i] = new Preparat(*listaPreparate[i]);
		}

	}

	//constructor de copiere
	Meniu(const Meniu& m) {
		if (m.nrPreparate > 0 && m.listaPreparate != nullptr)
			this->nrPreparate = m.nrPreparate;

		this->listaPreparate = new Preparat * [this->nrPreparate];
		for (int i = 0; i < this->nrPreparate; i++) {
			this->listaPreparate[i] = new Preparat(*m.listaPreparate[i]);
		}
	}

	//overload operator=
	Meniu& operator=(const Meniu& m) {
		if (this != &m) {
			for (int i = 0; i < this->nrPreparate; i++) {
				delete this->listaPreparate[i];
				this->listaPreparate[i] = nullptr;
			}

			delete[] this->listaPreparate;
			this->listaPreparate = nullptr;

			if (m.nrPreparate > 0 && m.listaPreparate != nullptr)
				this->nrPreparate = m.nrPreparate;

			this->listaPreparate = new Preparat * [this->nrPreparate];
			for (int i = 0; i < this->nrPreparate; i++) {
				this->listaPreparate[i] = new Preparat(*m.listaPreparate[i]);
			}
		}
	}

	~Meniu() {
		for (int i = 0; i < this->nrPreparate; i++) {
			delete this->listaPreparate[i];
			this->listaPreparate[i] = nullptr;
		}

		delete[] this->listaPreparate;
		this->listaPreparate = nullptr;
	}

	//overload <<
	friend ostream& operator<<(ostream& out, const Meniu& m) {
		out << "\n--------<<---------";
		out << "\nNr preparate: " << m.nrPreparate;
		out << "\nLista de preparate:";
		for (int i = 0; i < m.nrPreparate; i++) {
			out << *m.listaPreparate[i];
		}
		out << "\n--------------------";
		return out;
	}

	friend istream& operator>>(istream& in, Meniu& m) {
		for (int i = 0; i < m.nrPreparate; i++) {
			delete m.listaPreparate[i];
			m.listaPreparate[i] = nullptr;
		}

		delete[] m.listaPreparate;
		m.listaPreparate = nullptr;

		cout << "\nIntroduceti nr de preparate din meniu: ";
		in >> m.nrPreparate;
		cout << "\nIntroduceti lista de preparate: ";
		m.listaPreparate = new Preparat * [m.nrPreparate];
		for (int i = 0; i < m.nrPreparate; i++) {
			m.listaPreparate[i] = new Preparat();
			in >> *(m.listaPreparate[i]);
		}
		return in;
	}

	//citire fisier
	friend ifstream& operator>>(ifstream& in, Meniu& m) {
		for (int i = 0; i < m.nrPreparate; i++) {
			delete m.listaPreparate[i];
			m.listaPreparate[i] = nullptr;
		}

		delete[] m.listaPreparate;
		m.listaPreparate = nullptr;
		
		in >> m.nrPreparate;
		m.listaPreparate = new Preparat * [m.nrPreparate];
		for (int i = 0; i < m.nrPreparate; i++) {
			m.listaPreparate[i] = new Preparat();
			in >> *(m.listaPreparate[i]);
		}
		return in;
	}

	void afisare() {
		for (int i = 0; i < this->nrPreparate; i++) {
			cout << listaPreparate[i]->getDenumire() << endl;
		}
	}
};