
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>
#include <vector>
#include <string>



class contact{
    private:
        std::string name;
        std::string phone_number;
    public:
        contact();
        contact(std::string, std::string);
        std::string getname();
        std::string getnumber();
        bool operator==(const contact);
};

class contact_book{
    
    std::vector<contact> saved_contacts;

    public:
        contact_book();
        contact_book(std::vector<contact>);

        void showcontacts();
        void addcontact(contact);
        void insertcontact(contact,unsigned int);
        void removecontact(unsigned int);
        void removecontact(contact);
};



#endif


