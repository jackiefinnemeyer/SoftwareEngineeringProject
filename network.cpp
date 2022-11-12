#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}

 
Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
}

Network::~Network(){ 
}


void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL){
        head->prev = newEntry;
        }
    else{
        tail = newEntry;
	}
    
    head = newEntry;
    count++;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    newEntry->prev = tail;
    newEntry->next = NULL;
    
    if(tail != NULL){
	tail->next = newEntry;
	}
    else{
    	head = newEntry;
    	}
    tail = newEntry;
    count++;	
}


Person* Network::search(Person* searchEntry) {
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL    

    Person* compare = head;

    while (compare != NULL) {
        if (*compare == *searchEntry) 
            return compare;
        else
            compare = compare->next;
    }
    return compare;
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly. 
    Person* find = head;
    
    while (find != NULL) {
        if ((find->f_name == fname) && (find->l_name == lname)) 
            return find;
        else
            find = find->next;
    }
    return find;    
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of connections: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}




bool Network::remove(string fname, string lname){
    // We modified the definition of == for Person in Person definition itself, 
    // So we should not be worried about changes we made in Person to modify this method!
    Person* find = head;

    while (find != NULL) {
        if ((find->f_name == fname) && (find->l_name == lname))
            break;
        else
            find = find->next;
    }

    if (find == NULL)
        return false;

    if (head == find)
        head = find->next;

    if (find->next != NULL)
        find->next->prev = find->prev;

    if (find->prev != NULL)
        find->prev->next = find->next;

    free(find);
    return true;
}


//void Network::sendEmail(string addr, string subject, string content, string attachment=""){
//    // Sending a command looks like:
//    // echo "content" | mailx -s "subject" -a "attachment" addr;
//    // TODO: Search how you can run a unix command in C++
//    // TODO: You need to add double quotation character (") to both sides of strings for this command. Adding other characters (like ? in code below) should be easy, but double quotation says: I'm a character but not a typical character! 
//    // string new_str = '?' + old_str + '?'
//    // TODO: Complete this method
//}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt = 0;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new connection \n";
        cout << "4. Remove a connection \n";
        cout << "5. Search \n";
        cout << "6. Connect \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        Person* ptr;
        Person* ptr1;
        Person* ptr2;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cin>>fileName;
            
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have ".db" format
            // Take a look into sample_files.cpp 
            cout << "Enter the name of the load file: "; 
            // If file with name FILENAME does not exist: 
            cout << "File FILENAME does not exist!" << endl;
            // If file is loaded successfully, also print the count of connections in it: 
            cout << "Network loaded from " << fileName << " with " << count << " connections \n";
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Connection ONLY if it does not exists! 
            cout << "Enter new connection details:\n";
            ptr = new Person();

            if (search(ptr) == NULL) {
                cout << "Adding a new connection... \n";
                push_front(ptr);
                cout << "Connection added!";
            }
            else
                cout << "Connection already exists.\n";
        }
        else if (opt == 4){
            // TODO: Complete me!
            cout << "Removing a connection \n";
            cout << "First Name: ";
            std::getline(std::cin, fname);
            cout << "Last Name: ";
            std::getline(std::cin, lname);


            if (remove(fname, lname)) {
                cout << "Remove Successful! \n";
            }
            else
                cout << "Connection not found! \n";
        }
        else if (opt==5){
            // TODO: Complete me!
            cout << "Searching: \n";
            cout << "First Name: ";
            std::getline(std::cin, fname);
            cout << "Last Name: ";
            std::getline(std::cin, lname);

            ptr = search(fname, lname);

            if (ptr == NULL) {
                cout << "Not found! \n";
            }
            else
                ptr->print_person();
        }
        else if (opt == 6){ // Connect option
            cout << "Make friends: \n";
            cout << "Person 1 \n";
            cout << "First Name: ";
            std::getline(std::cin, fname);
            cout << "Last Name: ";
            std::getline(std::cin, lname);
    
            ptr1 = search(fname, lname);
            
            if (ptr1 == NULL) {
                cout << "Connection not found! \n";
            }
            
            if(ptr1 != NULL){
                cout << "Connection 2 \n";
                cout << "First Name: ";
                std::getline(std::cin, fname);
                cout << "Last Name: ";
                std::getline(std::cin, lname);
                
                ptr2 = search(fname, lname);
                
                if (ptr2 == NULL) {
                    cout << "Connection not found! \n";
                }
                
                else{
                    //ptr1->print_person(); part 1
                    //ptr2->print_person(); part 1
                    ptr1->makeFriend(ptr2); // making the two Persons friends with eachother
                    ptr2->makeFriend(ptr1);
                    cout << "Friends" << endl;
                }
            }
        }
            
        else{ 
            cout << "Nothing matched!\n";
        }
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    } 
}