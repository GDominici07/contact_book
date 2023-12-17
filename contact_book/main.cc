#include "contact_book.hpp"
#include "contact_book.cc"
#include <stdlib.h>
#include <iostream>

inline void clear(){
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}


constexpr unsigned int hash(const char *s, int off = 0) {                        
    return !s[off] ? 5381 : (hash(s, off+1)*33) ^ s[off];                           
} 

int main(){
    contact_book cont;
    contact cont_act("Giacomo","+91 707 700 7620");

    bool isdone = false;
    std::string op;
    std::string name ;
    std::string phone ;
    contact contact_tmp;
    std::string ws; //whitespace for replace
    int id;


    do {
        clear();
        cont.showcontacts();

        std::cout << ":";
        std::getline(std::cin, op);
        
        if (op == "exit" ||
            op == "q"    ||
            op == "quit" ){
            break;
        }

        switch(hash(op.c_str())){
            case hash("add"):
                std::cout << "-- ADDING CONTACT --" << std::endl;
                std::cout << "\t* Name :" ; std::getline(std::cin,name);
                std::cout << "\t* Number:"; std::getline(std::cin,phone);
                contact_tmp = contact(name,phone);
                cont.addcontact(contact_tmp);
                break;
            case hash("+"):
                std::cout << "-- ADDING CONTACT --" << std::endl;
                std::cout << "\t* Name :" ; std::getline(std::cin,name);
                std::cout << "\t* Number:"; std::getline(std::cin,phone);
                contact_tmp = contact(name,phone);
                cont.addcontact(contact_tmp);
                break;


            case hash("remove"):
                std::cout << "-- REMOVING CONTACT --" << std::endl;
                std::cout << "\t* id of the contact: "; std::cin >> id;
                cont.removecontact((unsigned int)id);
                break;
            case hash("-"):
                std::cout << "-- REMOVING CONTACT --" << std::endl;
                std::cout << "\t* id of the contact: "; std::cin >> id;
                cont.removecontact((unsigned int)id);
                break;

            case hash("modify"):
                std::cout << "-- MODIFYING CONTACT --" << std::endl;
                std::cout << "\t* id of the contact: "; std::cin >> id;

                std::cin.ignore(256, '\n');
                // remaining input characters up to the next newline character
                // are ignored

                std::cout << "\t* New Name :" ; std::getline(std::cin,name);
                std::cout << "\t* New Number:"; std::getline(std::cin,phone);

                cont.removecontact((unsigned int)id);
                contact_tmp = contact(name,phone);
                cont.insertcontact(contact_tmp,(unsigned int)id);
                break;

            case hash("replace"):
                
                std::cout << "-- MODIFYING CONTACT --" << std::endl;
                std::cout << "\t* id of the contact: "; std::cin >> id;

                std::cin.ignore(256, '\n');
                // remaining input characters up to the next newline character
                // are ignored

                std::cout << "\t* New Name :" ; std::getline(std::cin,name);
                std::cout << "\t* New Number:"; std::getline(std::cin,phone);

                cont.removecontact((unsigned int)id);
                contact_tmp = contact(name,phone);
                cont.insertcontact(contact_tmp,(unsigned int)id);
                break;

            case hash("->"):
                std::cout << "-- MODIFYING CONTACT --" << std::endl;
                std::cout << "\t* id of the contact: "; std::cin >> id;

                std::cin.ignore(256, '\n');
                // remaining input characters up to the next newline character
                // are ignored

                std::cout << "\t* New Name :" ; std::getline(std::cin,name);
                std::cout << "\t* New Number:"; std::getline(std::cin,phone);

                cont.removecontact((unsigned int)id);
                contact_tmp = contact(name,phone);
                cont.insertcontact(contact_tmp,(unsigned int)id);
                break;

            default:
                std::cout << op << "not in options" << std::endl;
                break;
        }

    } while(!isdone);
    return 0;
}

