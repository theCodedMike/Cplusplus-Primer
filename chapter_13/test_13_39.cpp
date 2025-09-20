//
// Created by lixia on 2025/9/21.
//
#include <iostream>
#include "../include/StrVec.h"
#include "../include/Utils.h"

using namespace std;

int main(int argc, char *argv[]) {
    StrVec sv1;
    cout << sv1.size() << " " << sv1.capacity() << endl; // 0 0
    StrVec sv(sv1);
    cout << sv.size() << " " << sv.capacity() << endl; // 0 0

    sv1.push_back("1");
    sv1.push_back("2");
    cout << sv1.size() << " " << sv1.capacity() << endl; // 2 4
    sv1.push_back("3");
    sv1.push_back("4");
    cout << sv1.size() << " " << sv1.capacity() << endl; // 4 4
    sv1.push_back("5");
    cout << sv1.size() << " " << sv1.capacity() << endl; // 5 8
    cout << endl;

    sv1.reserve(6);
    cout << sv1.size() << " " << sv1.capacity() << endl; // 5 8
    sv1.reserve(10);
    cout << sv1.size() << " " << sv1.capacity() << endl; // 5 10
    cout << sv1.front() << " " << sv1.back() << endl; // 1 5
    cout << endl;

    sv1.push_back("6");
    sv1.push_back("7");
    sv1.push_back("8");
    sv1.push_back("9");
    sv1.push_back("10");
    cout << sv1.size() << " " << sv1.capacity() << endl; // 10 10
    sv1.push_back("11");
    cout << sv1.size() << " " << sv1.capacity() << endl; // 11 20
    cout << endl;

    sv1.resize(15, "15");
    print_collection(sv1); // [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 15, 15, 15]
    cout << sv1.size() << " " << sv1.capacity() << endl; // 15 20
    sv1.resize(25, "25");
    print_collection(sv1); // [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 15, 15, 15, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25]
    cout << sv1.size() << " " << sv1.capacity() << endl; // 25 40
    sv1.resize(5, "55");
    print_collection(sv1); // [1, 2, 3, 4, 5]
    cout << sv1.size() << " " << sv1.capacity() << endl; // 5 40
    cout << endl << endl;

    StrVec sv2(sv1);
    print_collection(sv2); // [1, 2, 3, 4, 5]
    cout << sv2.size() << " " << sv2.capacity() << endl; // 5 5
    cout << sv2.front() << " " << sv2.back() << endl; // 1 5
    cout << endl;

    sv2.push_back("6");
    print_collection(sv2); // [1, 2, 3, 4, 5, 6]
    cout << sv2.size() << " " << sv2.capacity() << endl; // 6 10
    sv2.pop_back();
    sv2.pop_back();
    print_collection(sv2); // [1, 2, 3, 4]
    cout << sv2.size() << " " << sv2.capacity() << endl; // 4 10
    cout << endl << endl;

    StrVec sv3 = sv2;
    print_collection(sv3); // [1, 2, 3, 4]
    cout << sv3.size() << " " << sv3.capacity() << endl; // 4 4
    cout << endl << endl;

    initializer_list<string> il = {"1", "2", "3", "4", "5"};
    StrVec sv4(il);
    print_collection(sv4); // [1, 2, 3, 4, 5]
    cout << sv4.size() << " " << sv4.capacity() << endl; // 5 5
}
