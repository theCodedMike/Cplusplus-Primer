//
// Created by lixia on 2025/9/23.
//
#include <iostream>
#include "../include/StrVec.h"

using namespace std;


int main(int argc, char *argv[]) {
    StrVec sv1;
    sv1.push_back("1");
    sv1.push_back("2");
    sv1.push_back("3");

    const initializer_list<string> il = {"1", "2", "3"};
    const StrVec sv2(il);

    const StrVec sv3 = {"1", "2", "4"};

    cout << (sv1 == sv2) << endl; // 1
    cout << (sv1 != sv3) << endl; // 1
}
