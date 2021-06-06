//
// Created by user on 4/19/2021.
//

#include "customer.h"
void customer::setId(int ID) {
    id=std::move(ID);
}

int customer::getId() {
    return (id);
}

void customer::setFirstName(std::string fn) {
    firstName=std::move(fn);
}

std::string customer::getFirstName() {
    return (firstName);
}

void customer::setLastName(std::string ln) {
    lastName=std::move(ln);
}

std::string customer::getLastName() {
    return (lastName);
}