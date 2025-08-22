//
// Created by lixia on 2025/8/22.
//

#include <vector>
#include "../include/Utils.h"
using std::vector;
using std::size_t;

void copy(const vector<int> &, int *, size_t);

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 3, 4, 5};
    constexpr int N = 7;
    int dest[N];

    copy(nums, dest, N);
    print_collection(dest);
}

void copy(const vector<int> &source, int *dest, const size_t d_len) {
    const size_t s_len = source.size();
    const size_t len = s_len <= d_len ? s_len : d_len;
    for (size_t i = 0; i < len; i++) {
        *dest = source[i];
        dest++;
    }
}
