#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty : public Person {

    public:
    
    Faculty(){
        typeOfPerson = "Pracownik";
    }
	string getForPrint();
	string print();
};

string Faculty::getForPrint(){
        return "Pracownik " + firstName;
}

string Faculty::print() {
	return typeOfPerson;
}


#endif