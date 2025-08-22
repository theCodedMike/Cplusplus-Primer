//
// Created by lixia on 2025/8/22.
//

#include <vector>
#include "../include/Utils.h"
using std::vector;

int main(int argc, char *argv[]) {
    const int nums[] = {-9, 3, 10, 34, 89};
    vector<int> new_nums(std::begin(nums), std::end(nums));
    print_collection(new_nums);
}
