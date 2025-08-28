//
// Created by lixia on 2025/8/28.
//

#include <iostream>
using namespace std;

void print_ptr(const int *ip, size_t size);
void print_arr(const int arr[], size_t size);
void print_iterator(const int *beg, const int *end);


int main(int argc, char *argv[]) {
    int i = 0, j[2] = {0, 1};

    print_ptr(j, size(j));
    print_arr(j, size(j));
    print_iterator(begin(j), end(j));
}

void print_ptr(const int *ip, const size_t size) {
    for (size_t i = 0; i < size; ++i, ++ip)
        cout << *ip << ' ';
    cout << endl;
}

void print_arr(const int arr[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

void print_iterator(const int *beg, const int *end) {
    do {
        cout << *beg << ' ';
    } while (++beg != end);
    cout << endl;
}