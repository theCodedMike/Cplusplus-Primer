//
// Created by lixia on 2025/8/20.
//

#include <vector>
#include "../include/Utils.h"
using std::vector;

int main(int argc, char *argv[]) {
    vector<int> v1(10, 42);
    print_collection(v1);

    vector<int> v2(10);
    for (int & val: v2) {
        val = 42;
    }
    print_collection(v2);

    vector<int> v3 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    print_collection(v3);
}
