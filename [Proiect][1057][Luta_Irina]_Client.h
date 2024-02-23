#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
#include "Comanda.h"

using namespace std;


class Client {
	const int idClient;
	string nume;
	bool hasDiscount;
	float totalPlata;
	int nrComenzi;
	Comanda** listaComenzi;

public:

	Client(int idClient) :idClient(idClient) {
		this->nume = "-";
		this->hasDiscount = 0;
		this->nrComenzi = 0;
		this->totalPlata = 0;
		this->listaComenzi = nullptr;
	}

	Client(int idClient, string nume, bool hasDiscount, int nrComenzi, float totalPlata, Comanda** listaComenzi) :idClient(idClient) {
		if (nume.length() > 0) {
			this->nume = nume;
		}
		this->hasDiscount = hasDiscount;
		if (nrComenzi > 0 && listaComenzi != nullptr) {
			this->nrComenzi = nrComenzi;
			this->listaComenzi = new Comanda * [this->nrComenzi];
			for (int i = 0; i < this->nrComenzi; i++) {
				this->listaComenzi[i] = new Comanda(*listaComenzi[i]);
			}
		}
		if (totalPlata > 0) {
			this->totalPlata = totalPlata;
		}
	}

	Client(const Client& c) :idClient(c.idClient) {
		if (c.nume.length() > 0) {
			this->nume = c.nume;
		}
		this->hasDiscount = c.hasDiscount;
		if (c.nrComenzi > 0 && c.listaComenzi != nullptr) {
			this->nrComenzi = c.nrComenzi;
			this->listaComenzi = new Comanda * [this->nrComenzi];
			for (int i = 0; i < this->nrComenzi; i++) {
				this->listaComenzi[i] = new Comanda(*c.listaComenzi[i]);
			}
		}
		if (totalPlata > 0) {
			this->totalPlata = totalPlata;
		}
	}

	Client& operator =(const Client& c) {
		if (this != &c) {
			for (int i = 0; i < this->nrComenzi; i++) {
				delete this->listaComenzi[i];
				this->listaComenzi[i] = nullptr;
			}
			delete[] this->listaComenzi;
			this->listaComenzi = nullptr;

			if (c.nume.length() > 0) {
				this->nume = c.nume;
			}
			this->hasDiscount = c.hasDiscount;
			if (c.nrComenzi > 0 && c.listaComenzi != nullptr) {
				this->nrComenzi = c.nrComenzi;
				this->listaComenzi = new Comanda * [this->nrComenzi];
				for (int i = 0; i < this->nrComenzi; i++) {
					this->listaComenzi[i] = new Comanda(*c.listaComenzi[i]);
				}
			}
			else {
				this->nrComenzi = 0;
				this->listaComenzi = nullptr;
			}
			if (totalPlata > 0) {
				this->totalPlata = totalPlata;
			}
		}
		return *this;
	}

	~Client() {
		for (int i = 0; i < this->nrComenzi; i++) {
			delete this->listaComenzi[i];
			this->listaComenzi[i] = nullptr;
		}
		delete[] this->listaComenzi;
		this->listaComenzi = nullptr;
	}

	friend ostream& operator<<(ostream& out, const Client& c) {
		out << "\n<<<<<<<<<<<<<<<ClIENT<<<<<<<<<<<<<<<";
		out << "\nID: " << c.idClient;
		out << "\nNume: " << c.nume;
		out << "\nAre discount? " << c.hasDiscount;
		out << "\nTotal de plata: " << c.totalPlata;
		out << "\nNr comenzi: " << c.nrComenzi;
		out << "\nLista comenzi: ";
		for (int i = 0; i < c.nrComenzi; i++) {
			out << *c.listaComenzi[i];
		}
		return out;
	}

	friend istream& operator>>(istream& in, Client& c) {
		for (int i = 0; i < c.nrComenzi; i++) {
			delete c.listaComenzi[i];
			c.listaComenzi[i] = nullptr;
		}

		delete[] c.listaComenzi;
		c.listaComenzi = nullptr;

		cout << "\nIntroduceti numele clientului: ";
		in >> c.nume;
		cout << "\nIntroduceti 1 daca clientul are discount si 0 daca nu are: ";
		in >> c.hasDiscount;
		cout << "\nIntroduceti totalul de plata: ";
		in >> c.totalPlata;
		cout << "\nIntroduceti nr de comenzi: ";
		in >> c.nrComenzi;
		cout << "\nIntroduceti comenzile: ";
		c.listaComenzi = new Comanda * [c.nrComenzi];
		for (int i = 0; i < c.nrComenzi; i++) {
			c.listaComenzi[i] = new Comanda();
			in >> *(c.listaComenzi[i]);
		}
		return in;
	}

	//citire fisier
	friend ifstream& operator>>(ifstream& in, Client& c) {
		for (int i = 0; i < c.nrComenzi; i++) {
			delete c.listaComenzi[i];
			c.listaComenzi[i] = nullptr;
		}

		delete[] c.listaComenzi;
		c.listaComenzi = nullptr;

		in >> c.nume;
		in >> c.hasDiscount;
		in >> c.totalPlata;
		in >> c.nrComenzi;
		c.listaComenzi = new Comanda * [c.nrComenzi];
		for (int i = 0; i < c.nrComenzi; i++) {
			c.listaComenzi[i] = new Comanda();
			in >> *(c.listaComenzi[i]);
		}
		return in;
	}

	//operator +
	Client operator+(int totalPlata) {
		Client copie = *this;
		copie.totalPlata = totalPlata;
		return copie;
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 0) {
			this->nume = nume;
		}
	}

	bool getHasDiscount() {
		return this->hasDiscount;
	}

	void setHasDiscount(bool hasDiscount) {
		if (hasDiscount == 0 || hasDiscount == 1) {
			this->hasDiscount = hasDiscount;
		}
	}

	float getTotalPLata() {
		return this->totalPlata;
	}

	void setTotalPlata(float totalPlata) {
		if (totalPlata > 0) {
			this->totalPlata = totalPlata;
		}
	}

	int getNrComenzi() {
		return this->nrComenzi;
	}

	void setNrComenzi(int nrComenzi) {
		if (nrComenzi > 0) {
			this->nrComenzi = nrComenzi;
		}
	}

	Comanda** getComenzi() {
		return this->listaComenzi;
	}

	void setComenzi(Comanda** listaComenzi, int nrComenzi) {
		if (nrComenzi > 0 && listaComenzi != nullptr) {
			this->nrComenzi = nrComenzi;
			this->listaComenzi = new Comanda * [this->nrComenzi];
			for (int i = 0; i < this->nrComenzi; i++) {
				this->listaComenzi[i] = new Comanda(*listaComenzi[i]);
			}
		}
	}

	//metoda 1 - aplicare discount dupa caz
	float stabilireDiscount() {
		if (this->totalPlata > 300) {
			this->hasDiscount = 1;
			this->totalPlata = this->totalPlata * 0.7;
		}
		else if (this->totalPlata > 200) {
			this->hasDiscount = 1;
			this->totalPlata = this->totalPlata * 0.8;
		}
		else if (this->totalPlata > 100) {
			this->hasDiscount = 1;
			this->totalPlata = this->totalPlata * 0.9;
		}
		else {
			this->hasDiscount = 0;
		}
	}

	//metoda 2 - afisare
	void afisare() {
		cout << "\n********AFISARE************";
		cout << "\nID client: " << this->idClient;
		cout << "\nNume client: " << this->nume;
		cout << "\nAre discount? (0=DA/1=NU) " << this->hasDiscount;
		cout << "\nTotal plata: " << this->totalPlata;
		if (this->nrComenzi > 0 && this->listaComenzi != nullptr) {
			cout << "\nNr comenzi: " << this->nrComenzi;
			for (int i = 0; i < this->nrComenzi; i++) {
				cout << *this->listaComenzi[i];
			}
		}
	}

};