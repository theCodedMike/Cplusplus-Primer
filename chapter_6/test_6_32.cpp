//
// Created by lixia on 2025/8/28.
//

#include "../include/Utils.h"

int &get(int *array, int index) {
    return array[index];
}

int main(int argc, char *argv[]) {
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;

    print_collection(ia); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
}
