//
// Created by lixia on 2025/8/20.
//

#include <iostream>
#include <vector>

#include "../include/Utils.h"
using std::vector;
using std::cout;

int main(int argc, char *argv[]) {
    vector<int> scores = {3, 9, 10, 22, 10, 33, -2};
    cout << "Before: ";
    print_collection(scores);

    for (auto iter = scores.begin(); iter != scores.end(); ++iter)
        *iter *= 2;

    cout << " After: ";
    print_collection(scores);
}
