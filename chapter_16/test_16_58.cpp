//
// Created by lixia on 2025/10/5.
//
#include <iostream>

#include "../include/StrVec.h"

using namespace std;

int main(int argc, char *argv[]) {
    StrVec sv;
    sv.emplace_back(10, 'S');

    cout << sv[0] << endl;
}
