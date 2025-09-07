//
// Created by lixia on 2025/9/7.
//

#include <vector>
#include "../include/Utils.h"
using namespace std;


int main(int argc, char *argv[]) {
    vector<int> iv = {-9, 32, 8, 0, 100, 234, -10, 50};
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;

    while (iter != mid) {
        if (constexpr int some_val = 8; *iter == some_val)
            iv.insert(iter, 2 * some_val);

        ++iter;
    }

    print_collection(iv); // [-9, 32, 16, 8, 0, 100, 234, -10, 50]
}