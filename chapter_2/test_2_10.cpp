//
// Created by lixia on 2025/8/15.
//

#include <iostream>
#include <ostream>
#include <string>

std::string global_str;
int global_int;

int main(int argc, char *argv[]) {
    int local_int;
    std::string local_str;

    std::cout << global_str << "|" << global_int << std::endl; // |0
    std::cout << local_str << "|" << local_int << std::endl;   // |1
}
