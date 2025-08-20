//
// Created by lixia on 2025/8/20.
//

#include <iostream>
#include <vector>
#include <string>
#include "../include/Utils.h"

using std::vector;
using std::cout;
using std::endl;
using std::string;


int main(int argc, char *argv[]) {
    vector<int> v1;
    cout << "v1: " << v1.capacity() << " "; // v1: 0 []
    print_collection(v1);

    vector<int> v2(10);
    cout << "v2: " << v2.capacity() << " "; // v2: 10 [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    print_collection(v2);

    vector<int> v3(10, 52);
    cout << "v3: " << v3.capacity() << " "; // v3: 10 [52, 52, 52, 52, 52, 52, 52, 52, 52, 52]
    print_collection(v3);

    vector<int> v4{10};
    cout << "v4: " << v4.capacity() << " "; // v4: 1 [10]
    print_collection(v4);

    vector<int> v5{10, 42};
    cout << "v5: " << v5.capacity() << " "; // v5: 2 [10, 42]
    print_collection(v5);

    vector<string> v6{10};
    cout << "v6: " << v6.capacity() << " "; // v6: 10 [, , , , , , , , , ]
    print_collection(v6);

    vector<string> v7{10, "hi"};
    cout << "v7: " << v7.capacity() << " "; // v7: 10 [hi, hi, hi, hi, hi, hi, hi, hi, hi, hi]
    print_collection(v7);
}


