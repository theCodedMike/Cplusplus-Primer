//
// Created by lixia on 2025/9/18.
//

#include <iostream>
#include "../include/HasPtr.h"

using namespace std;


int main(int argc, char *argv[]) {
    HasPtrVal hp1("hello", 1);
    HasPtrVal hp2("java", 2);

    cout << "hp1: " << hp1 << endl;
    cout << "hp2: " << hp2 << endl;
    ::swap(hp1, hp2);
    cout << "hp1: " << hp1 << endl;
    cout << "hp2: " << hp2 << endl;
}
