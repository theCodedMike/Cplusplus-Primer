//
// Created by lixia on 2025/8/21.
//

#include "../include/Utils.h"

int main(int argc, char *argv[]) {
    const size_t N = 10;
    int nums[N];

    for (int i = 0; i < N; ++i)
        nums[i] = i;

    print_collection(nums);
}
