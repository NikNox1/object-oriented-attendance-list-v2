#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "IPrintable.h"
#include <iostream>
#include <conio.h>
using namespace std;

class Person : public IPrintable {

    protected:
	string sex;
	int index;
    int yearOfBirth;
    int monthOfBirth;
    int dayOfBirth;
    int socialSecurityNumber;
    string firstName;
    string lastName;
    string typeOfPerson;
	int pesel[11];
    public:
    Person(){
        typeOfPerson = "Osoba";
    }
    int getAge();
	int getindex();
    string getFirstName();
    string getLastName();
	string getForPrint();
	string getTypeOfPerson();
    void setFirstName(string);
    void setLastName(string);
    void setYearOfBirth(int);
	string print();
	void setindex(int);
	void setPerson(string _imie, string _nazwisko, int _pesel[11]);
	void SetPesel(int _pesel[11]);
	void SetSex();
	string GetSex();
};

void Person::SetSex() {
	
	if (pesel[10] % 2 == 1) {
		sex = "Facet";
	}
	else {
		sex = "Kobieta";
	}
}
string Person::GetSex() {
	return sex;
	}

void Person::setPerson(string _imie,string _nazwisko,int _pesel[11]) {
	
	setFirstName(_imie);
	setLastName(_nazwisko);
	SetPesel(_pesel);
}

string Person::getForPrint(){
    if(typeOfPerson == "Osoba"){
        return "Osoba " + firstName;
    } else {
        return "SomethingElse " + firstName;
    }
}
	
int Person::getAge(){
    return 2019-yearOfBirth;
}

int Person::getindex() {
	return index;
}

string Person::getFirstName(){
    return firstName;
}

string Person::getLastName(){
    return lastName;
}

string Person::getTypeOfPerson(){
    return typeOfPerson;
}

void Person::setFirstName(string _firstName){
    firstName = _firstName;
}

void Person::setLastName(string _lastName) {
	lastName = _lastName;
}

void Person::setYearOfBirth(int _yearOfBirth){
    yearOfBirth = _yearOfBirth;
}

void Person::setindex(int _index) {
	index = _index;
}
string Person::print() {
	return typeOfPerson;
	
}
void Person::SetPesel(int _pesel[11])
{
	int Rok, Mies;
	for (int i = 0; i < 11; i++)
		pesel[i] = _pesel[i];

	Rok = (_pesel[0]) * 10;
	Rok += (_pesel[1]);
	Mies = (_pesel[2]) * 10;
	Mies += (_pesel[3]);
	if (Mies > 80 && Mies < 93)
	{
		Rok += 1800;
	}
	else if (Mies > 0 && Mies < 13)
	{
		Rok += 1900;
	}
	else if (Mies > 20 && Mies < 33)
	{
		Rok += 2000;
	}
	else if (Mies > 40 && Mies < 53)
	{
		Rok += 2100;
	}
	else if (Mies > 60 && Mies < 73)
	{
		Rok += 2200;
	}
	setYearOfBirth(Rok);
}

#endif