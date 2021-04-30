#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Faculty.h"    
#include "IPrintable.h"
#include "Interfejs.h"
using namespace std;



int main(){

	int rozmiar = 1;

    Person **listOfPeople=new Person*[rozmiar];

	interfejs(listOfPeople,rozmiar);

    return 0;
}	