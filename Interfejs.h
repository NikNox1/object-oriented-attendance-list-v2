#ifndef INTERFEJS_H
#define INTERFEJS_H
#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Faculty.h"    
#include "IPrintable.h"

void sortowanie(Person **_osoba, int opcja_sortowanie, int rozmiar)
{
	if (opcja_sortowanie == 1)
	{
		cout << "SORTOWANIE..." << endl;
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar - 1; j++)
			{
				if (_osoba[j]->getFirstName() > _osoba[j + 1]->getFirstName())
				{
					swap(_osoba[j], _osoba[j + 1]);

				}
			}
		}
	}
	else if (opcja_sortowanie == 2)
	{
		cout << "SORTOWANIE..." << endl;
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar - 1; j++)
			{
				if (_osoba[j]->getLastName() > _osoba[j + 1]->getLastName())
				{
					swap(_osoba[j], _osoba[j + 1]);

				}
			}
		}
	}
	else if (opcja_sortowanie == 3)
	{
		cout << "SORTOWANIE..." << endl;
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar - 1; j++)
			{
				if (_osoba[j]->GetSex() > _osoba[j + 1]->GetSex())
				{
					swap(_osoba[j], _osoba[j + 1]);

				}
			}
		}
	}
	
	else if (opcja_sortowanie == 4)
	{
		cout << "SORTOWANIE..." << endl;
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar - 1; j++)
			{
				if (_osoba[j]->getAge() > _osoba[j + 1]->getAge())
				{
					swap(_osoba[j], _osoba[j + 1]);

				}
			}
		}
	}
	
	else if (opcja_sortowanie == 5)
	{
		cout << "SORTOWANIE..." << endl;
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar - 1; j++)
			{
				if (_osoba[j]->getTypeOfPerson() > _osoba[j + 1]->getTypeOfPerson())
				{
					swap(_osoba[j], _osoba[j + 1]);

				}
			}
		}
	}

	else
	{
		cout << "Miales podac liczbe z zakresu od 1 do 4!!!" << endl;
	}
};

void dodaj(Person *tablica) {
	int *_pesel = new int[11];
	string _imie, _nazwisko;
	cout << "Wpisz dane osoby" << endl << "Imie: " << endl;
	cin >> _imie;
	cout << endl << "Nazwisko: " << endl;
	cin >> _nazwisko;
	cout << endl << "Podaj cyfry PESELU kolejno po spacji: " << endl;
	for (int i = 0; i < 11; i++) {
		cin >> _pesel[i];
	}
	tablica->SetSex();
	tablica->setPerson(_imie, _nazwisko, _pesel);
}

Person ** zwieksz(Person ** usuwam, int &rozmiar)
{
	rozmiar = rozmiar + 1;
	Person **powiekszam = new Person*[rozmiar];


	for (int i = 0; i < rozmiar - 1; i++)
	{

		powiekszam[i] = usuwam[i];

	}

	delete[] usuwam;

	return powiekszam;
}


void printPerson(IPrintable *p) {
	cout << p->getForPrint() << endl;
}

void print(IPrintable *obj) {
	cout << obj->print();
}

void interfejs(Person **tab, int rozmiar) {
	int  opcja_menu;
	int i = 0, opcja_sortowanie;
	while (1)
	{
		cout << "MENU" << endl;
		cout << "----------------- " << endl;
		cout << "1. DODAJ STUDENTA" << endl;
		cout << "2. DODAJ PRACOWNIKA" << endl;
		cout << "3. DODAJ INNA OSOBE" << endl;
		cout << "4. WYSWIETL LISTE OBECNOSCI" << endl;
		cout << "5. USUN LISTE" << endl;
		cout << "6. SORTOWANIE" << endl;
		cout << "7. KONIEC PROGRAMU" << endl;
		cin >> opcja_menu;
		cout << endl;
		switch (opcja_menu)
		{
		case 1:
			cout << "DODAWANIE NOWEGO STUDENTA" << endl;
			cout << "----------------- " << endl;
			if (i < rozmiar)
			{
				tab[i] = new Student();
				dodaj(tab[i]);
				i++;
			}
			else
			{
				tab = zwieksz(tab, rozmiar);
				tab[rozmiar - 1] = new Student();
				dodaj(tab[rozmiar - 1]);
				i++;
			}
			break;
		case 2:
			cout << "DODAWANIE NOWEGO PRACOWNIKA" << endl;
			cout << "----------------- " << endl;
			if (i < rozmiar)
			{
				tab[i] = new Faculty();
				dodaj(tab[i]);
				i++;
			}
			else
			{
				tab = zwieksz(tab, rozmiar);
				tab[rozmiar - 1] = new Faculty();
				dodaj(tab[rozmiar - 1]);
				i++;
			}
			break;
		case 3:
			cout << "DODAWANIE NOWEJ OSOBY" << endl;
			cout << "----------------- " << endl;
			if (i < rozmiar)
			{
				tab[i] = new Person();
				dodaj(tab[i]);
				i++;
			}
			else
			{
				tab = zwieksz(tab, rozmiar);
				tab[rozmiar - 1] = new Person();
				dodaj(tab[rozmiar - 1]);
				i++;
			}
			break;

		case 4:
			cout << "WYSWIETLANIE LISTY OBECNOSCI" << endl;
			cout << "----------------- " << endl;
			system("cls");
			if (i > 0) {
				for (int i = 0; i < rozmiar; i++) {
					cout << "~~~~~~~~~~~~~~~~~~~ "<<endl;
					print(tab[i]);
					cout <<endl<< "Imie " << tab[i]->getFirstName() <<" Nazwisko "<<tab[i]->getLastName()<< " Wiek " << tab[i]->getAge();
					cout << endl;

				}
			}
			else {
				cout << "Na liscie nie ma zadnej osoby" << endl;

			}

			break;
		case 5:
			cout << "USUWANIE LISTY" << endl;
			cout << "----------------- " << endl;
			system("cls");
			for (int i = 0; i < rozmiar; i++) {
				tab[i] = NULL;
			}
			rozmiar = 0;
			i = 0;
			tab = zwieksz(tab, rozmiar); //tworze od nowa

			break;

		case 6:
			system("cls");
			cout << "JAK POSORTOWAC LISTE ?" << endl;
			cout << "WYBIERZ OBIEKT SORTOWANIA " << endl;
			cout << "WPISZ CYFRE OD 1 DO 5 " << endl;
			cout << "1.IMIE " << endl;
			cout << "2.NAZWISKO " << endl;
			cout << "3.PLEC " << endl;
			cout << "4.WIEK " << endl;
			cout << "5.RODZAJ OSOBY " << endl;
			
			
			int opcja;
			cin >> opcja;
			system("cls");
			
			sortowanie(tab,opcja,rozmiar);
			break;
		case 7:
			return;
			break;

		default:
			cout << "Nie znam takiej komendy!!!" << endl;
			break;

		}


	}
}

#endif