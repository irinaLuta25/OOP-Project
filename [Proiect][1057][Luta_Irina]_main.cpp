#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <fstream>
#include "MateriiPrime.h"
#include "Preparat.h"
#include "Comanda.h"
#include "Client.h"
#include "Meniu.h"
#include "Restaurant.h"
#include "Gestiune.h"
using namespace std;

int main(int argc, char* argv[]) {
	if (argc == 4) { 
		MateriiPrime mp1("pui", 2);
		MateriiPrime mp2("fulgi-de-porumb", 5);
		MateriiPrime mp3("oua", 2);
		MateriiPrime mp4("lapte", 5);
		MateriiPrime mp5("unt", 3);
		MateriiPrime mp6("cartofi", 4);
		MateriiPrime mp7("rosii", 3);
		MateriiPrime mp8("ceapa", 5);
		MateriiPrime mp9("castraveti", 2);
		MateriiPrime mp10("dressing", 3);
		MateriiPrime mp11("penne", 4);
		MateriiPrime mp12("aluat-pizza", 3);
		MateriiPrime mp13("ciuperci", 4);
		MateriiPrime mp14("cascaval", 3);
		MateriiPrime mp15("boabe-cafea", 1);
		MateriiPrime* listaMateriiPrime1[] = { &mp1,&mp2, &mp3 };
		MateriiPrime* listaMateriiPrime2[] = { &mp4, &mp5, &mp6 };
		MateriiPrime* listaMateriiPrime3[] = { &mp7,&mp8,&mp9,&mp10 };
		MateriiPrime* listaMateriiPrime4[] = { &mp11,&mp13,&mp14, &mp7 };
		MateriiPrime* listaMateriiPrime5[] = { &mp15,&mp4 };
		MateriiPrime* listaMateriiPrime6[] = { &mp12,&mp7,&mp8,&mp13,&mp14 };
		Preparat p1(1, "aripioare", listaMateriiPrime1, 3, 40, 18);
		Preparat p2(2, "piure", listaMateriiPrime2, 3, 30, 12);
		Preparat p3(3, "salata", listaMateriiPrime3, 4, 5, 10);
		Preparat p4(4, "paste", listaMateriiPrime4, 4, 30, 26);
		Preparat p5(5, "latte", listaMateriiPrime5, 2, 5, 13);
		Preparat p6(6, "pizza", listaMateriiPrime6, 5, 20, 28);
		Preparat* listaPreparate[] = { &p1,&p2,&p3,&p4,&p5,&p6 };
		Meniu m(6, listaPreparate);

		cout << m;

		Gestiune gestiune;
		gestiune.meniuNavigare(argv[1],argv[2],argv[3]);

	}
	else {
		cout << "Nu ati introdus fisierele necesare ca si parametru in linia de comanda\n";
	}
}

//int main() {
	//testari citire fisiere - merg!
	/*ifstream f1("MateriiPrime.txt");
	MateriiPrime mp1,mp2,mp3;
	f1 >> mp1>>mp2>>mp3;
	cout << mp1<<endl<<mp2<<endl<<mp3;
	f1.close();

	ifstream f2("Preparat.txt");
	Preparat p;
	f2 >> p;
	cout << p;
	f2.close();

	ifstream f3("Comanda.txt");
	Comanda c;
	f3 >> c;
	cout << c;
	f3.close();

	ifstream f4("Client.txt");
	Client cl(1);
	f4 >> cl;
	cout << cl;
	f4.close();

	ifstream f5("Meniu.txt");
	Meniu m;
	f5 >> m;
	cout << m;
	f5.close();*/

	///////////////	MODUL DE GESTIUNE ////////////////

	/*MateriiPrime mp1("pui", 2);
	MateriiPrime mp2("fulgi-de-porumb", 5);
	MateriiPrime mp3("oua", 2);
	MateriiPrime mp4("lapte", 5);
	MateriiPrime mp5("unt", 3);
	MateriiPrime mp6("cartofi", 4);
	MateriiPrime mp7("rosii", 3);
	MateriiPrime mp8("ceapa", 5);
	MateriiPrime mp9("castraveti", 2);
	MateriiPrime mp10("dressing", 3);
	MateriiPrime mp11("penne", 4);
	MateriiPrime mp12("aluat-pizza", 3);
	MateriiPrime mp13("ciuperci", 4);
	MateriiPrime mp14("cascaval", 3);
	MateriiPrime mp15("boabe-cafea", 1);
	MateriiPrime* listaMateriiPrime1[] = { &mp1,&mp2, &mp3 };
	MateriiPrime* listaMateriiPrime2[] = { &mp4, &mp5, &mp6 };
	MateriiPrime* listaMateriiPrime3[] = { &mp7,&mp8,&mp9,&mp10 };
	MateriiPrime* listaMateriiPrime4[] = { &mp11,&mp13,&mp14, &mp7 };
	MateriiPrime* listaMateriiPrime5[] = { &mp15,&mp4 };
	MateriiPrime* listaMateriiPrime6[] = { &mp12,&mp7,&mp8,&mp13,&mp14 };
	Preparat p1(1, "aripioare", listaMateriiPrime1, 3, 40, 18);
	Preparat p2(2, "piure", listaMateriiPrime2, 3, 30, 12);
	Preparat p3(3, "salata", listaMateriiPrime3, 4, 5, 10);
	Preparat p4(4, "paste", listaMateriiPrime4, 4, 30, 26);
	Preparat p5(5, "latte", listaMateriiPrime5, 2, 5, 13);
	Preparat p6(6, "pizza", listaMateriiPrime6, 5, 20, 28);

	Restaurant r;
	Preparat* listaPreparate[] = { &p1,&p2,&p3,&p4,&p5,&p6 };
	Meniu m(6, listaPreparate);

	cout << "\nBun venit la restaurantul Venus!";
	cout << "\nPentru a vizualiza meniul, foloseste comanda 'men'";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	char* comanda = new char[10];
	cin >> comanda;
	if (comanda != nullptr) {
		if (strcmp(comanda, "men") == 0) {
			cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$ MENIU $$$$$$$$$$$$$$$$$$$$$$$$$$$" << "\n\n";
			cout << p1 << endl << p2 << endl << p3 << endl << p4 << endl << p5 << endl << p6;
			cout << "\nPentru a comanda, foloseste 'cmd'" << endl;

			cin >> comanda;
			if (strcmp(comanda, "cmd") == 0) {
				Client* clientNou = new Client(1);
				string nume;
				cout << "Introduceti numele clientului: ";
				cin >> nume;
				clientNou->setNume(nume);

				int discount;
				cout << "Beneficiati de discount? Introduceti 1 pentru DA si 0 pentru NU: ";
				cin >> discount;
				clientNou->setHasDiscount(discount);

				int nrComenzi;
				cout << "Introduceti numarul de comenzi pe care doriti sa le plasati: ";
				cin >> nrComenzi;
				clientNou->setNrComenzi(nrComenzi);

				cout << "\nIntroduceti detaliile comenzilor. ";
				for (int i = 0; i < nrComenzi; i++) {
					cout << "\nComanda nr " << i + 1 << ": " << endl;
					Comanda* comandaNoua = new Comanda(i);

					int nrPreparate;
					cout << "\nIntroduceti nr de preparate pe care doriti sa le comandati: ";
					cin >> nrPreparate;

					for (int j = 0; j < nrPreparate; j++) {
						cout << "\nPreparatul nr " << j + 1 << ": " << endl;
						Preparat* preparatNou = new Preparat(j + 7);

						string denumire;
						bool ok = false;

						while (!ok) {
							cout << "\nIntroduceti numele preparatului: ";
							cin >> denumire;

							for (int k = 0; k < nrPreparate; k++) {
								if (listaPreparate[k]->getDenumire() == denumire) {
									preparatNou->setDenumire(denumire);
									ok = true;
									break;
								}
							}

							if (!ok) {
								cout << "\nNe pare rau, dar preparatul selectat nu exista in meniul nostru. Incercati din nou." << endl;
							}
							else {
								int nrBuc;
								cout << "Cate bucati din acest preparat doriti sa comandati? ";
								cin >> nrBuc;

							}
						}
					}
				}
			}
		}
	}*/
//}