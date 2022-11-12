#include <iostream>
#include "contact.h"
#include "person.h"
#include "date.h"
#include "network.h"	
int main() {

	// create & print Email & Phone objects using constructors
	cout << "----------------   Email object using constructor:   ------------------\n";
	Email e1("School", "email@usc.edu");
	e1.print();

	cout << "\n---------------   Phone object using constructor:   ------------------\n";
	Phone p1("Home", "1234567890");
	p1.print();

	cout << "\n-----------   Person object using default constructor:   -------------\n";
	Person person1;
	person1.print_person();

	cout << "\n---------   Phone object using parameterized constructor:   ----------\n";
	Person person2("John", "Smith", "1/2/2000", "Home a@b.com", "Work 9876543210");
	person2.print_person();

	cout << "\n-------   Phone object using person_template.txt constructor:  -------\n";
	Person person3("person_template.txt");
	person3.print_person();


	// create & print Email & Phone objects using set_contact() functions
	cout << "\n--------------   Email object using set_contact():   -----------------\n";
	Email e2;
	e2.set_contact();
	e2.print();

	cout << "\n-------------   Phone object using set_contact():   ------------------\n";
	Phone p2;
	p2.set_contact();
	p2.print();

	cout << "\n-------------------   Compare Email objects:   -----------------------\n";


	Email e3("Home", "abc@b.com");
	Email e4("Home", "def@b.com");
	//Email e4("Home", "abc@b.com");

	cout << "e3 and e4 are ";
	if (e3 == e4)
		cout << "the same.\n";
	else
		cout << "not the same.\n";

	cout << "\n-------------------   Compare Phone objects:   -----------------------\n";

	Phone p3("Work", "1234567890");
	Phone p4("Work", "1234567890");
	//Phone p4("Home", "1234567890");

	cout << "p3 and p4 are ";
	if (p3 == p4)
		cout << "the same.\n";
	else
		cout << "not the same.\n";

	cout << "\n-------------------   Compare Person objects:   -----------------------\n";

	Person person4("Jane", "Doe", "1/2/2000", "Home ghi@b.com", "Work 4567890123");
	Person person5("Jane", "Doe", "1/2/2000", "Home ghi@b.com", "Work 4567890123");
	//Person person5("Harry", "Potter", "1/2/2000", "Work jkl@b.com", "Home 7890123456");

	cout << "person 4 and person 5 are ";
	if (person4 == person5)
		cout << "the same.\n";
	else
		cout << "not the same.\n";




	return 0;
}