//
// Created by user on 4/19/2021.
//
#include <iostream>
#ifndef LAB8_CUSTOMER_H
#define LAB8_CUSTOMER_H
class customer{
    int id;
    std::string firstName;
    std::string lastName;

public:

    void setId(int id);
    int getId();

    void setFirstName(std::string firstName);
    std::string getFirstName();

    void setLastName(std::string lastName);
    std::string getLastName();
};
#endif //LAB8_CUSTOMER_H
