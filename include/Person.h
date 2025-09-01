//
// Created by lixia on 2025/8/31.
//

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

struct Person {
    std::string name;
    std::string address;

    Person() => default;
    Person(const std::string &name, const std::string address &address)
        : name(name), address(address) {}
    Person(std::istream &is);

    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
};


std::istream &read(std::istream &is, Person &person);
std::ostream &print(std::ostream &os, const Person &person);

std::istream &read(std::istream &is, Person &person) {
    std::cout << "Enter name: ";
    is >> person.name;
    std::cout << "Enter address: ";
    is >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person) {
    os << "Name: " << person.name << ", Address: " << person.address;
    return os;
}

Person::Person(std::istream &is) {
    read(is, *this);
}
#endif //PERSON_H