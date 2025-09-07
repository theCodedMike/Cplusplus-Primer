//
// Created by lixia on 2025/9/7.
//

#include <vector>
#include "../include/Utils.h"
using namespace std;


int main(int argc, char *argv[]) {
    // 将下面的数列变成 [1, 42, 1, 42, 1, 42, 1, 42, 1, 42, 1, 42]
    vector<int> v = {1, 1, 1, 1, 1, 1};
    auto begin = v.begin();

    while (begin != v.end()) {
        ++begin;
        begin = v.insert(begin, 42);
        //v.insert(begin, 42); // 程序会异常终止
        ++begin;
    }

    print_collection(v);
}
