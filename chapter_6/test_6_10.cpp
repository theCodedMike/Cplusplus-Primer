//
// Created by lixia on 2025/8/27.
//
#include "./../include/Chapter6.h"

int main(int argc, char *argv[]) {
    int a = 40, b = 23;
    cout << "Before a = " << a << " b = " << b << endl;
    swap(&a, &b);
    cout << " After a = " << a << " b = " << b << endl;
}

void swap(int *ip1, int *ip2) {
    tie(*ip2, *ip1) = make_pair(*ip1, *ip2);
}