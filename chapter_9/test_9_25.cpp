//
// Created by lixia on 2025/9/7.
//

#include <vector>

#include "../include/Utils.h"
using namespace std;


int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 3, 4, 5};

    nums.erase(nums.cbegin(), nums.cbegin());
    print_collection(nums); // [1, 2, 3, 4, 5]

    nums.erase(nums.cend(), nums.cend());
    print_collection(nums); // [1, 2, 3, 4, 5]
}
