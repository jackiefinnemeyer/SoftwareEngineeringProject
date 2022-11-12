
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

using namespace std;


class Contact {
private:
    friend class Email; // grant access to "type" member 
    friend class Phone; 
    string type;
public:
    virtual void print() = 0;
    virtual string get_contact(string style = "full") = 0;
    virtual void set_contact() = 0;
};


class Email : public Contact {
private:
    string email_addr;
public:
    Email() {};
    ~Email() {};
    Email(string type, string email_addr);
    //removed default arguments on virtual functions
    void print();
    string get_contact(string style = "full");
    void set_contact();
    void set_type();
    void set_email();
    bool operator==(const Email& rhs);
    bool operator!=(const Email& rhs);
};


class Phone : public Contact {
private:
    string phone_num;
public:
    Phone() {};
    ~Phone() {};
    Phone(string type, string phone_number);
    void print();
    string get_contact(string style = "full");
    void set_contact(); 
    void set_type();
    void set_phone();
    int check_valid(string num, int size);
    string format(string num, int size);
    bool operator==(const Phone& rhs);
    bool operator!=(const Phone& rhs);
};

#endif