#pragma once
#include<iostream>
#include<fstream>
#include "MateriiPrime.h"
#include "Preparat.h"
#include "Comanda.h"
#include "Client.h"
#include "Meniu.h"

using namespace std;

class Gestiune {
	int nrMateriiPrime;
	MateriiPrime** listaMateriiPrime;

	int nrPreparate;
	Preparat** listaPreparate;

	int nrComenzi;
	Comanda** listaComenzi;

	int nrClienti;
	Client** listaClienti;

public:
	Gestiune() {
		nrMateriiPrime = 0;
		listaMateriiPrime = nullptr;
		nrPreparate = 0;
		listaPreparate = nullptr;
		nrComenzi = 0;
		listaComenzi = nullptr;
		nrClienti = 0;
		listaClienti = nullptr;
	}

	void adaugaMateriiPrime(MateriiPrime* materiePrima){
		if (nrMateriiPrime != 0) {
			MateriiPrime** aux = new MateriiPrime * [nrMateriiPrime];
			for (int i = 0; i < nrMateriiPrime; i++) {
				aux[i] = listaMateriiPrime[i];
			}
			delete[] listaMateriiPrime;

			nrMateriiPrime++;
			listaMateriiPrime = new MateriiPrime * [nrMateriiPrime];

			for (int i = 0; i < nrMateriiPrime; i++) {
				listaMateriiPrime[i] = aux[i];
			}
			listaMateriiPrime[nrMateriiPrime - 1] = materiePrima;
		}
		else {
			nrMateriiPrime++;
			listaMateriiPrime = new MateriiPrime * [nrMateriiPrime];
			listaMateriiPrime[0] = materiePrima;
		}
	}

	void adaugaProduse(Preparat* preparat) {
		if (nrPreparate != 0) {
			Preparat** aux = new Preparat * [nrPreparate];
			for (int i = 0; i < nrPreparate; i++) {
				aux[i] = listaPreparate[i];
			}
			delete[] listaPreparate;

			nrPreparate++;
			listaPreparate = new Preparat * [nrPreparate];

			for (int i = 0; i < nrPreparate; i++) {
				listaPreparate[i] = aux[i];
			}
			listaPreparate[nrPreparate - 1] = preparat;
		}
		else {
			nrPreparate++;
			listaPreparate = new Preparat * [nrPreparate];
			listaPreparate[0] = preparat;
		}
	}

	void adaugaComenzi(Comanda* comanda) {
		if (nrComenzi != 0) {
			Comanda** aux = new Comanda * [nrComenzi];
			for (int i = 0; i < nrComenzi; i++) {
				aux[i] = listaComenzi[i];
			}
			delete[] listaComenzi;

			nrComenzi++;
			listaComenzi = new Comanda * [nrComenzi];

			for (int i = 0; i < nrComenzi; i++) {
				listaComenzi[i] = aux[i];
			}
			listaComenzi[nrComenzi - 1] = comanda;
		}
		else {
			nrComenzi++;
			listaComenzi = new Comanda * [nrComenzi];
			listaComenzi[0] = comanda;
		}
	}

	void adaugaClienti(Client* client) {
		if (nrClienti != 0) {
			Client** aux = new Client * [nrClienti];
			for (int i = 0; i < nrClienti; i++) {
				aux[i] = listaClienti[i];
			}
			delete[] listaClienti;

			nrClienti++;
			listaClienti = new Client * [nrClienti];

			for (int i = 0; i < nrClienti; i++) {
				listaClienti[i] = aux[i];
			}
			listaClienti[nrClienti - 1] = client;
		}
		else {
			nrClienti++;
			listaClienti = new Client * [nrClienti];
			listaClienti[0] = client;
		}
	}

	void meniuNavigare(string MateriiPrimeFile, string PreparateFile, string MeniuFile) {

		cout << "llADLKEKF";
		ifstream MateriiPrimeIn(MateriiPrimeFile);
		ifstream PreparateIn(PreparateFile);
		ifstream MeniuIn(MeniuFile);

		if (!MateriiPrimeIn || !PreparateIn || !MeniuIn) {
			cout << "\nEroare la deschiderea fisierelor.";
		}
		else {

			cout << "\nBun venit la restaurantul Venus!";
			cout << "\nPentru a vizualiza meniul, foloseste comanda 'men'";
			cout << "\nPentru a genera un raport, foloseste comanda 'rap";
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

			char* key = new char[10];
			cin >> key;
			if (key != nullptr) {
				if (strcmp(key, "men") == 0) {
					cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$ MENIU $$$$$$$$$$$$$$$$$$$$$$$$$$$" << "\n\n";
					//citire si afisare meniu - fa mai nice
					Meniu m;
					MeniuIn >> m;
					cout << m;

					//cout << "\nPentru a comanda, foloseste 'cmd'" << endl;

					//cin >> key;
					//if (strcmp(key, "cmd") == 0) {
					//	Client* clientNou = new Client(1);
					//	string nume;
					//	cout << "Introduceti numele clientului: ";
					//	cin >> nume;
					//	clientNou->setNume(nume);

					//	int discount;
					//	cout << "Beneficiati de discount? Introduceti 1 pentru DA si 0 pentru NU: ";
					//	cin >> discount;
					//	clientNou->setHasDiscount(discount);

					//	int nrComenzi;
					//	cout << "Introduceti numarul de comenzi pe care doriti sa le plasati: ";
					//	cin >> nrComenzi;
					//	clientNou->setNrComenzi(nrComenzi);

					//	cout << "\nIntroduceti detaliile comenzilor. ";
					//	for (int i = 0; i < nrComenzi; i++) {
					//		cout << "\nComanda nr " << i + 1 << ": " << endl;
					//		Comanda* comandaNoua = new Comanda(i);

					//		int nrPreparate;
					//		cout << "\nIntroduceti nr de preparate pe care doriti sa le comandati: ";
					//		cin >> nrPreparate;

					//		for (int j = 0; j < nrPreparate; j++) {
					//			cout << "\nPreparatul nr " << j + 1 << ": " << endl;

					//			string denumire;
					//			cout << "\nIntroduceti denumirea produsului: ";
					//			cin >> denumire;

					//			//de continuat - sa parcurg cumva preparatele din meniu astfel incat sa verific daca denumirea produsului
					//			//introdus de la tastatura exista in meniu
					//			//daca exista, sa il adauge in listaPreparate din clasa Comanda (obiectul comandaNoua)
					//		}
					//	}
					//}
				}
				else if (strcmp(key, "rap") == 0) {
					cout << "jkfsjkn";
					cout << "Introduceti 1 pentru a afisa stocul de materiiPrime" << endl;
					cout << "Introduceti 2 pentru a afisa preparatele" << endl;
					cout << "Introduceti 3 pentru a afisa comenzile" << endl;
					cout << "Introduceti 4 pentru a afisa clientii" << endl;
					int key;
					cin >> key;

					if (key == 1) {
						cout << "Date referitoare la materiile prime: " << endl;
						
						//parcurgere date din fisier
						cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
						//macar cu date din main sa iasa asta
						for (int i = 0; i < nrMateriiPrime; i++) {
							cout << *listaMateriiPrime[i] << endl;
							
						}
						//eventual rasp la intrebarea mp care se afla in cantitatea cea mai mare ?

					}
					else if (key == 2) {
						cout << "Date referitoare la preparate: " << endl;
						for (int i = 0; i < nrPreparate; i++) {
							cout << *listaPreparate[i] << endl;
						}

					}
					else if (key == 3) {
						cout << "Date referitoare la comenzi: " << endl;
						for (int i = 0; i < nrComenzi; i++) {
							cout << *listaComenzi[i] << endl;
						}

					}
					else if (key == 4) {
						cout << "Date referitoare la clienti: " << endl;
						for (int i = 0; i < nrClienti; i++) {
							cout << *listaClienti[i] << endl;
						}

					}
					
				}
			}
		}
	}

		~Gestiune() {
			for (int i = 0; i < nrMateriiPrime; i++) {
				delete listaMateriiPrime[i];
			}
			delete[] listaMateriiPrime;

			for (int i = 0; i < nrPreparate; i++) {
				delete listaPreparate[i];
			}
			delete[] listaPreparate;

			for (int i = 0; i < nrComenzi; i++) {
				delete listaComenzi[i];
			}
			delete[] listaComenzi;

			for (int i = 0; i < nrClienti; i++) {
				delete listaClienti[i];
			}
			delete[] listaClienti;
		}

};