//
// Created by lixia on 2025/9/9.
//

#include <vector>
#include "../include/Utils.h"
using namespace std;


int main(int argc, char *argv[]) {
    vector<int> nums = {1, 3, 5, 7, 9};
    std::fill_n(nums.begin(), nums.size(), 0);
    print_collection(nums);
}
