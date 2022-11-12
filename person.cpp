#include "person.h"
#include "misc.h"
#include <vector>

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    // TODO: complete the method!
    delete email;
    delete phone;
}

Person::Person(string f_name, string l_name, string bdate) {
    this->f_name = f_name;
    this->l_name = l_name;
    this->birthdate = new Date(bdate);
}


Person::Person(string f_name, string l_name, string bdate, string email, string phone){
    // TODO: Complete this method!
    // phone and email strings are in full version
    string type_email, type_phone, temp_email, temp_phone;

    this->f_name = f_name;
    this->l_name = l_name;
    this->birthdate = new Date(bdate);
    
    stringstream ss(email);
    string word;
    ss >> word;
    type_email = word;
    ss >> word;
    temp_email = word;

    this->email = new Email(type_email, temp_email);

    stringstream ss2(phone);
    ss2 >> word;
    type_phone = word;
    ss2 >> word;
    temp_phone = word;
    
    this->phone = new Phone(type_phone, temp_phone);
}



Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp, temp_email, temp_phone;
    string type_email;
    string type_phone;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    // code here
    std::getline(std::cin, type_email);

    cout << "Email address: ";
    // code
    std::getline(std::cin, temp_email);

    email = new Email(type_email, temp_email);

    cout << "Type of phone number: ";
    std::getline(std::cin, type_phone);

    cout << "Phone number: ";
    std::getline(std::cin, temp_phone);

    phone = new Phone(type_phone, temp_phone);

}


void Person::set_person(string filename) {
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!

    string type_email, type_phone;
    string temp_email, temp_phone;
    string temp_buf;
    string phone_final, email_final;

    int size_email, size_phone, space = 0;


    ifstream input(filename);
    if (!input) {
        cout << "Error opening file. Program will terminate.";
        exit(0);
    }

    getline(input, f_name);
    getline(input, l_name);

    getline(input, temp_buf);
    birthdate = new Date(temp_buf);

    getline(input, temp_phone);
    size_phone = temp_phone.length();

    for (int i = 0; i < size_phone; i++) {
        if (isalnum(temp_phone[i]) && !space) {
            type_phone += temp_phone[i];
        }
        if (space) {   
            phone_final += temp_phone[i];
        }
        if (temp_phone[i] == ' ') {
            space = 1;
        }
    }
    phone = new Phone(type_phone, phone_final);

    getline(input, temp_email);
    size_email = temp_email.length();
    space = 0;

    for (int i = 0; i < size_email; i++) {
        if (isalnum(temp_email[i]) && !space) {
            type_email += temp_email[i];
        }
        if (space) {
            email_final += temp_email[i];
        }
        if (temp_email[i] == ' ') {
            space = 1;
        }
    }
    email = new Email(type_email, email_final);

    input.close();
}



bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    if ( (f_name == rhs.f_name) && 
        (l_name == rhs.l_name) && 
        (*birthdate == *rhs.birthdate) &&
        (*email == *rhs.email) && 
        (*phone == *rhs.phone))
        return true;
    else
        return false;
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
    return !(*this == rhs);
}


//void Person::print_person(){
//    // Already implemented for you! Do not change!
//	cout << l_name <<", " << f_name << endl;
//	birthdate->print_date("Month D, YYYY");
//    email->print();
//    phone->print();
//}

void Person::print_person() {
    // Already implemented for you! Do not change!
    cout << l_name << ", " << f_name << endl;
    birthdate->print_date("Month D, YYYY");
    email->print();
    phone->print();    

    for (auto connect : myfriends) {
        cout << codeName(connect->f_name, connect->l_name) << endl;
    }
}

void Person::makeFriend(Person* newFriend){
    myfriends.push_back(newFriend); // adds newFriend to the vector myfriends
}