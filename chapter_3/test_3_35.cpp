//
// Created by lixia on 2025/8/21.
//

#include "../include/Utils.h"

using std::cout;
using std::size;
using std::begin;
using std::end;

void set_array_to_zero_1();
void set_array_to_zero_2();
void set_array_to_zero_3();
void set_array_to_zero_4();

int main(int argc, char *argv[]) {
    //set_array_to_zero_1();
    //set_array_to_zero_2();
    //set_array_to_zero_3();
    set_array_to_zero_4();
}

void set_array_to_zero_1() {
    int nums1[] = {1, 1, 1, 1, 1};
    cout << "Before: "; print_collection(nums1);

    std::size_t len = size(nums1);
    for (int *start = nums1, *end = nums1 + len; start < end; start++)
        *start = 0;

    cout << " After: "; print_collection(nums1);
}

void set_array_to_zero_2() {
    int nums2[] = {2, 2, 2, 2, 2};
    cout << "Before: "; print_collection(nums2);

    std::size_t len = size(nums2);
    for (int *start = &nums2[0], *end = &nums2[len]; start < end; start++)
        *start = 0;

    cout << " After: "; print_collection(nums2);
}

void set_array_to_zero_3() {
    int nums3[] = {3, 3, 3, 3, 3};
    cout << "Before: "; print_collection(nums3);

    std::size_t len = size(nums3);
    for (int *start = nums3, i = 0; i < len; i++)
        *(start + i) = 0;

    cout << " After: "; print_collection(nums3);
}

void set_array_to_zero_4() {
    int nums4[] = {4, 4, 4, 4, 4};
    cout << "Before: "; print_collection(nums4);

    for (auto beg = begin(nums4), end = std::end(nums4); beg < end; ++beg)
        *beg = 0;

    cout << " After: "; print_collection(nums4);
}