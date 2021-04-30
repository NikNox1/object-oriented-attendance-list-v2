#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {

    public:
    
    Student(){
        typeOfPerson = "Student";
    }
	string getForPrint();
	string print();
};
string Student::getForPrint(){
        return "Student " + firstName;
}
string Student::print() {
	return typeOfPerson;
}




#endif