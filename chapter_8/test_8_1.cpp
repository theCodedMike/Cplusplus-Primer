//
// Created by lixia on 2025/9/4.
//

#include <iostream>

std::istream & input(std::istream &is) {
    auto state = is.rdstate();
    return is;
}


int main(int argc, char *argv[]) {
    input(std::cin);
}
