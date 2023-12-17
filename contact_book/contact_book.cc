#include "contact_book.hpp"
#include <assert.h>
#include <regex>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
int getindex(std::vector<T> v, T K){
    auto it = std::find(v.begin(),
                        v.end(), K);
  
    if (it != v.end()){
        int index = it - v.begin(); 
        return index; 
    } else { 
        return -1; 
    }
} 
contact::contact(){
    this->name = "name";
    this->phone_number = "+99 999 999";
}

contact::contact(std::string name, std::string phone_number){
    this->name = name;
    this->phone_number = phone_number;
}


std::string contact::getname(){
    return this->name;
}

std::string contact::getnumber(){
    return this->phone_number;
}

bool contact::operator==(const contact other){
    return  phone_number  == other.getnumber() &&
            name          == other.getname();
}


/*  ---- CONTACT_BOOK class methods ----
 *  contact_book()
 *  contact_book(std::vector<contact>)
 *  show_contacts()
 *  addcontact(contact)
 *
 * */
contact_book::contact_book(){
    this->saved_contacts = {};
};

contact_book::contact_book(std::vector<contact> cont){
    this->saved_contacts = cont;
};


void contact_book::showcontacts(){
    contact cont;
    std::cout << "id\tname\tphone number" << std::endl;
    for(int id = 0;id < this->saved_contacts.size();id++){
        cont = this->saved_contacts[id];
        std::cout << id << "\t" << cont.getname() << "\t" << cont.getnumber() << std::endl;
    }
    std::cout << std::endl;
};

void contact_book::addcontact(contact cont){
    this->saved_contacts.push_back(cont);
};

void contact_book::insertcontact(contact cont,unsigned int id){
    this->saved_contacts.insert(
            this->saved_contacts.begin() + id,
            cont);
}
void contact_book::removecontact(unsigned int id){
    this->saved_contacts.erase(
            this->saved_contacts.begin() + id);
}

void contact_book::removecontact(contact cont){
    int index = getindex(this->saved_contacts,cont);

    if (index!=-1){
        this->removecontact((unsigned int) index);
    } 
#ifdef __DEBUG
    else {
        std::cerr << "ERROR: removecontact: index not found." << std::endl;
    }
#endif
}




