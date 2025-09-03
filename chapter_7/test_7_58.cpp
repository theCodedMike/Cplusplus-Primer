//
// Created by lixia on 2025/9/3.
//

#include <iostream>
#include <vector>
#include "../include/Utils.h"
using namespace std;

class Example {
    static std::vector<double> init_many_nums();
public:
    static constexpr double rate = 6.5;
    static constexpr int vecSize = 20;
    static std::vector<double> many_nums;
};

std::vector<double> Example::many_nums = init_many_nums();
std::vector<double> Example::init_many_nums() {
    return std::vector<double>(vecSize, rate);
}


int main(int argc, char *argv[]) {
    print_collection(Example::many_nums);
    cout << Example::rate << endl;
    cout << Example::vecSize << endl;
}
