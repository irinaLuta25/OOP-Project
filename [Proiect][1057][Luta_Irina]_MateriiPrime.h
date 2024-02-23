#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class MateriiPrime {
	int cantitate;
	char* denumire;

public:
	MateriiPrime() {
		this->cantitate = 0;
		this->denumire = nullptr;
	}

	//constructor cu toti parametri
	MateriiPrime(const char* denumire, int cantitate) {
		if (denumire != nullptr) {
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else {
			this->denumire = nullptr;
		}

		if (cantitate > 0) {
			this->cantitate = cantitate;
		}
		else {
			this->cantitate = 0;
		}
	}

	//constructor cu un parametru
	MateriiPrime(int cantitate) {
		if (cantitate > 0) {
			this->cantitate = cantitate;
		}

	}

	//constructor copiere
	MateriiPrime(const MateriiPrime& mp) {
		if (mp.denumire != nullptr) {
			this->denumire = new char[strlen(mp.denumire) + 1];
			strcpy(this->denumire, mp.denumire);
		}
		else {
			this->denumire = nullptr;
		}

		if (mp.cantitate > 0) {
			this->cantitate = mp.cantitate;
		}
		else {
			this->cantitate = 0;
		}
	}

	//overload =
	MateriiPrime& operator=(const MateriiPrime& mp) {
		if (this != &mp) {
			delete[] this->denumire;
			this->denumire = nullptr;
			if (mp.denumire != nullptr) {
				this->denumire = new char[strlen(mp.denumire) + 1];
				strcpy(this->denumire, mp.denumire);
			}
			this->cantitate = mp.cantitate;
		}
		return*this;
	}

	//overload <<
	friend ostream& operator<<(ostream& out, const MateriiPrime& mp) {
		out << "\n`````````````````````````````````````````````````````````";
		if (mp.denumire != nullptr) {
			out << "\nDenumire: " << mp.denumire;
		}
		else {
			out << "\nDenumire: -";
		}
		out << "\nCantitate: " << mp.cantitate;
		out << "\n--------------------";
		return out;
	}

	//overload >>
	friend istream& operator>>(istream& in, MateriiPrime& mp) {
		delete[] mp.denumire;
		mp.denumire = nullptr;
		cout << "\nIntroduceti denumirea: ";
		char buffer[100];
		in >> buffer;
		mp.denumire = new char[strlen(buffer) + 1];
		strcpy(mp.denumire, buffer);
		cout << "\nIntroduceti cantitatea: ";
		in >> mp.cantitate;
		return in;
	}

	//citire fisier
	friend ifstream& operator>>(ifstream& in, MateriiPrime& mp) {
		delete[] mp.denumire;
		mp.denumire = nullptr;
		char buffer[100];
		in >> buffer;
		mp.denumire = new char[strlen(buffer) + 1];
		strcpy(mp.denumire, buffer);
		in >> mp.cantitate;
		return in;
	}

	//operator --
	MateriiPrime operator--(int) {
		MateriiPrime copie = *this;
		this->cantitate--;
		return copie;
	}

	char* getDenumire() {
		return this->denumire;
	}

	void setDenumire(const char* denumire) {
		if (denumire != nullptr && strlen(denumire) > 2) {
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else {
			this->denumire = nullptr;
		}
	}

	int getCantitate() {
		return this->cantitate;
	}

	void setCantitate(const int cantitate) {
		if (cantitate > 0) {
			this->cantitate = cantitate;
		}
		else {
			this->cantitate = 0;
		}
	}

	//se incearca ceva -- continua
	void scadeCantitateMp() {
		if (this->cantitate > 0) {
			(this->cantitate)--;
		}
	}

	//metoda1
	void dublareCantitate() {
		this->cantitate *= 2;
	}

	//metoda2
	void afisare() {
		cout << "\n*************************";
		cout << "\nDenumire: ";
		if (this->denumire != nullptr) {
			cout << this->denumire;
		}
		else {
			cout << "-";
		}
		cout << "\nCantitate: " << this->cantitate;
	}

	//destructor
	~MateriiPrime() {
		delete[] this->denumire;
		this->denumire = nullptr;
	}

	//friend class Preparat;
};
