
#include "contact.h"
// TODO: Add needed libraries! 


Email::Email(string type, string email_addr) {
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact() {
    cout << "Enter the type of email address: ";
    std::getline(std::cin, type);
    cout << "Enter email address: ";
    std::getline(std::cin, email_addr);
}

void Email::set_type() {
    std::getline(std::cin, type);
}

void Email::set_email() {
    std::getline(std::cin, email_addr);
}


string Email::get_contact(string style) {
    // Note: We have default argument in declaration and not in definition!
    if (style == "full")
        return "(" + type + "): " + email_addr;
    else
        return email_addr;
}


void Email::print() {
    // Note: get_contact is called with default argument
    cout << "Email ";
    cout << get_contact() << endl;    
}

bool Email::operator==(const Email& rhs) {
    if ((type == rhs.type) &&
        (email_addr == rhs.email_addr))
        return true;
    else
        return false;
}

bool Email::operator!=(const Email& rhs) {
    return !(*this == rhs);
}


Phone::Phone(string type, string num) {
    this->type = type;

    string temp = "000-000-0000", num_new;
    int size = num.length();
    int j = 0, invalid;    

    invalid = check_valid(num, size);

    if (invalid == 1) {
        cout << "Too many digits entered. Only first 10 digits will be kept.\n";
        for (int i = 0; i < 10; i++)
            num_new += num[i];
        num = num_new;
        size = num.length();
    }

    if (!invalid or (invalid == 1)) 
        this->phone_num = format(num, size);
    else {
        cout << "Invalid phone number entered. ";
        cout << "Setting phone number to 000-000-0000.\n";
        this->phone_num = temp;
    }
}


void Phone::set_contact() {
    string temp = "000-000-0000", num, num_new;
    int size, invalid;

    cout << "Enter the type of phone number: ";
    std::getline(std::cin, type);
    cout << "Enter the phone number: ";
    std::getline(std::cin, num);   

    size = num.length();
    invalid = check_valid(num, size);

    if (invalid == 1) {
        cout << "Too many digits entered. Only first 10 digits will be kept.\n";
        for (int i = 0; i < 10; i++)
            num_new += num[i];
        num = num_new;
        size = num.length();
    }

    if (!invalid or (invalid == 1)) 
        this->phone_num = format(num, size);
    else {
        cout << "Invalid phone number entered. ";
        cout << "Setting phone number to 000-000-0000.\n";
        this->phone_num = temp;
    }
}

string Phone::format(string num, int size) {
    string temp = "000-000-0000";

    // for loop to format phone_num based on user input:
    for (int i = 0, j = 0; i < size; i++, j++) {
        if (size == 10) { // size == 10 if phone number does not have dashes '-'
            if (((i == 3) || (i == 6)) && isalnum(num[i]))
                j++;
        }
        else { // else phone number does have dashes '-'
            if (((i == 3) || (i == 7)) && isalnum(num[i]))
                j++;
        }
        temp[j] = num[i];
    }
    return temp;
}

// method to check if a valid phone number was entered
int Phone::check_valid(string num, int size) {
    int digits = 0;

    for (int i = 0; i < size; i++) {
        if (isdigit(num[i]))
            digits++;
    }

    if (digits > 10)
        return 1;
    else if (digits < 10)
        return 2;
    else
        return 0;
        
}

void Phone::set_type() {
    std::getline(std::cin, type);
}

void Phone::set_phone() {
    std::getline(std::cin, phone_num);
}

string Phone::get_contact(string style) {
    if (style == "full")
        return "(" + type + "): " + phone_num;
    else
        return phone_num;
}


void Phone::print() {
    // Note: get_contact is called with default argument
    cout << "Phone ";
    cout << get_contact() << endl;
}

bool Phone::operator==(const Phone& rhs) {
    if ((type == rhs.type) &&
        (phone_num == rhs.phone_num))
        return true;
    else
        return false;
}

bool Phone::operator!=(const Phone& rhs) {
    return !(*this == rhs);
}