//
// Created by lixia on 2025/10/6.
//

#include <iostream>
#include <tuple>
#include <vector>

#include "../include/Utils.h"

using namespace std;


int main(int argc, char *argv[]) {
    const tuple<string, vector<string>, pair<string, int>> t1 = {
        "hello",
        {"c", "c++", "java", "rust", "mojo"},
        {"hello", 42}
    };

    cout << get<0>(t1) << endl;
    print_collection(get<1>(t1));
    print_pair(get<2>(t1));
    //cout << get<2>(t1).first << " " << get<2>(t1).second << endl;
}
