//
// Created by lixia on 2025/8/28.
//
#include <iostream>
using namespace std;

void swap(int *i1, int *i2);

int main(int argc, char *argv[]) {
    int i = 10, j = 20;
    cout << "Before swap: i = " << i << ", j = " << j << endl;
    swap(&i, &j);
    cout << " After swap: i = " << i << ", j = " << j << endl;
}

void swap(int *i1, int *i2) {
    int tmp = *i1;
    *i1 = *i2;
    *i2 = tmp;
}
