//
// Created by lixia on 2025/8/21.
//


#include <vector>
#include "../include/Utils.h"
using std::vector;


int main(int argc, char *argv[]) {
    const unsigned N = 5;
    int nums1[N] = {39, 5, 7, 2, 1};
    int nums2[N];
    for (int i = 0; i < N; i++) {
        nums2[i] = nums1[i];
    }
    print_collection(nums2); // [39, 5, 7, 2, 1]

    vector<int> vec1 = {7, 99, -3, 28, 2};
    vector<int> vec2(vec1);
    print_collection(vec2); // [7, 99, -3, 28, 2]
}
