//
// Created by lixia on 2025/9/6.
//

#include <list>
#include <deque>
#include <iostream>

#include "../include/Utils.h"
using namespace std;


int main(int argc, char *argv[]) {
    const list<int> nums = {-5, 33, 44, 90, -100, 29, 15};
    deque<int> odds;
    deque<int> evens;

    for (const int num: nums) {
        if (num % 2 == 0)
            evens.push_back(num);
        else
            odds.push_back(num);
    }

    print_collection(odds);  // [-5, 33, 29, 15]
    print_collection(evens); // [44, 90, -100]
}
