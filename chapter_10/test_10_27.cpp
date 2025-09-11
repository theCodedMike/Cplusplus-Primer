//
// Created by lixia on 2025/9/10.
//

#include <algorithm>
#include <vector>
#include <list>
#include "../include/Utils.h"
using namespace std;

int main(int argc, char *argv[]) {
    vector<int> v1 = {1, 2, 2, 3, 4, 4, 4, 4, 5, 5};
    list<int> l1;
    std::ranges::unique_copy(v1, back_inserter(l1));
    print_collection(l1); // [1, 2, 3, 4, 5]

    vector<int> v2 = {4, 5, 1, 2, 3, 4, 5, 4, 4, 2};
    list<int> l2;
    std::ranges::unique_copy(v2, back_inserter(l2));
    print_collection(l2); // [4, 5, 1, 2, 3, 4, 5, 4, 2]
}
