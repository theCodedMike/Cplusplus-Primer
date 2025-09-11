//
// Created by lixia on 2025/9/10.
//
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

#include "../include/Utils.h"
using namespace std;


int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    forward_list<int> flist;
    std::ranges::copy(nums, std::front_inserter(flist));
    print_collection(flist); // [9, 8, 7, 6, 5, 4, 3, 2, 1]

    list<int> list;
    std::ranges::copy(nums, std::back_inserter(list));
    print_collection(list); // [1, 2, 3, 4, 5, 6, 7, 8, 9]

    deque<int> deque1;
    std::ranges::copy(nums, std::inserter(deque1, deque1.begin()));
    print_collection(deque1); // [1, 2, 3, 4, 5, 6, 7, 8, 9]
}
