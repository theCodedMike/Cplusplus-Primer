//
// Created by lixia on 2025/9/18.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
    inline static unsigned long id_generator = 10000; // C++17以后开始支持

    std::string name;
    unsigned long id = 0;
public:
    Employee() : Employee("") {}
    explicit Employee(const std::string &name) {
        this->name = name;
        this->id = id_generator++;
    }

};

//unsigned long Employee::id_generator = 10000;

#endif //EMPLOYEE_H