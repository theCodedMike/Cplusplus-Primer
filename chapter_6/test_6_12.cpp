//
// Created by lixia on 2025/8/27.
//
#include "./../include/Chapter6.h"

int main(int argc, char *argv[]) {
    int i = 11, j = 30;
    cout << "Before i = " << i << " j = " << j << endl;
    swap_with_ref(i, j);
    cout << " After i = " << i << " j = " << j << endl;
}

void swap_with_ref(int &i1, int &i2) {
    tie(i2, i1) = make_tuple(i1, i2);
}
