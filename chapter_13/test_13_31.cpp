//
// Created by lixia on 2025/9/18.
//

#include <algorithm>
#include <vector>
#include "../include/HasPtr.h"
#include "../include/Utils.h"

using namespace std;
int main(int argc, char *argv[]) {
    HasPtrVal hp1("hello", 1);
    HasPtrVal hp2("java", 2);
    HasPtrVal hp3("hello", 2);
    HasPtrVal hp4("c++", 4);
    HasPtrVal hp5("java", 2);
    vector<HasPtrVal> v{hp1, hp2, hp3, hp4, hp5};

    std::sort(v.begin(), v.end());
    print_collection(v); // [(c++ 4), (hello 1), (hello 2), (java 2), (java 2)]
    const auto iter = ranges::unique(v).begin();
    v.erase(iter, v.end());
    print_collection(v); // [(c++ 4), (hello 1), (hello 2), (java 2)]

}