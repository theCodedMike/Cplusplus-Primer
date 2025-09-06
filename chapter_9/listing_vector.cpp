//
// Created by lixia on 2025/9/6.
//

#include <vector>
#include "../include/Utils.h"
using namespace std;

void container_type_member();
void init();
void assign_and_swap();
void size_operation();
void relation_operation();

int main(int argc, char *argv[]) {
    //container_type_member();
    //init();
    //assign_and_swap();
    //size_operation();
    relation_operation();
}

// 容器类型成员
void container_type_member() {
    int val = 42;
    vector<int>::iterator iter;
    vector<int>::const_iterator citer;
    vector<int>::reverse_iterator riter;
    vector<int>::const_reverse_iterator criter;
    vector<int>::size_type sz;
    vector<int>::value_type vt;
    vector<int>::difference_type diff;

    vector<int>::allocator_type alloc;
    vector<int>::pointer p;
    vector<int>::const_pointer ptr;
    vector<int>::reference ref = val;
    vector<int>::const_reference cref = 0;
}

void init() {
    const vector<int> v1 = {1, 3, 5, 7, 9};
    print_collection(v1); // [1, 3, 5, 7, 9]

    const vector<int> v2{2, 4, 6, 8, 10};
    print_collection(v2); // [2, 4, 6, 8, 10]

    const vector<int> v3;
    print_collection(v3); // []

    const vector<int> v4(v1);
    print_collection(v4); // [1, 3, 5, 7, 9]

    const vector<int> v5 = v2;
    print_collection(v5); // [2, 4, 6, 8, 10]

    const vector<int> v6(v1.cbegin(), v1.cend());
    print_collection(v6); // [1, 3, 5, 7, 9]

    const vector<int> v7(5);
    print_collection(v7); // [0, 0, 0, 0, 0]

    const vector<int> v8(5, 1);
    print_collection(v8); // [1, 1, 1, 1, 1]
}


void assign_and_swap() {
    vector<string> v1 = {"1", "2", "3"};
    vector<string> v2 = {"4", "5"};

    std::swap(v1, v2);
    print_collection(v1); // [4, 5]
    print_collection(v2); // [1, 2, 3]

    v1.swap(v2);
    print_collection(v1); // [1, 2, 3]
    print_collection(v2); // [4, 5]

    vector<string> v3;
    v3.assign(v1.cbegin(), v1.cend());
    print_collection(v3); // [1, 2, 3]

    vector<string> v4;
    initializer_list<string> ilist = {"Allen", "Bob", "Tomas"};
    v4.assign(ilist);
    print_collection(v4); // [Allen, Bob, Tomas]

    vector<string> v5;
    v5.assign(7, "Tom");
    print_collection(v5); // [Tom, Tom, Tom, Tom, Tom, Tom, Tom]
}

void size_operation() {
    vector<int> v = {9, 3, 5, 2, 8};
    cout << "size: " << v.size() << endl;         // 5
    cout << "capacity: " << v.capacity() << endl; // 5
    cout << "max_size: " << v.max_size() << endl; // 2305843009213693951
    cout << "empty: " << v.empty() << endl;       // 0 false
}

void relation_operation() {
    const vector<int> v1 = { 1, 3, 5, 7, 9, 12};
    const vector<int> v2 = { 1, 3, 9};
    const vector<int> v3 = { 1, 3, 5, 7};
    const vector<int> v4 = { 1, 3, 5, 7, 9, 12};
    cout << "v1 < v2: " << (v1 < v2) << endl; // true
    cout << "v1 < v3: " << (v1 < v3) << endl; // false
    cout << "v1 == v4: " << (v1 == v4) << endl; // true
    cout << "v1 == v2: " << (v1 == v2) << endl; // false
}