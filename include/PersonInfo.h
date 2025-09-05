//
// Created by lixia on 2025/9/5.
//

#ifndef PERSONINFO_H
#define PERSONINFO_H
#include <string>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};


std::ostream & operator<<(std::ostream &os, const PersonInfo &rhs);
std::ostream & operator<<(std::ostream &os, const PersonInfo &rhs) {
    os << rhs.name << ": ";
    for (auto phone: rhs.phones) {
        os << phone << " ";
    }

    return os;
}

#endif //PERSONINFO_H