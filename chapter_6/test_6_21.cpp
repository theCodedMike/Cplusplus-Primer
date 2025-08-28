//
// Created by lixia on 2025/8/28.
//

#include "./../include/Chapter6.h"

int main(int argc, char *argv[]) {
    int i = 10, j = 20;
    cout << my_max(i, &j) << endl;
}

int my_max(const int i1, const int *i2) {
    return i1 > *i2 ? i1 : *i2;
}