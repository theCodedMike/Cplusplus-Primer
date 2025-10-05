//
// Created by lixia on 2025/10/6.
//
#include <iostream>
#include <tuple>

#include "../include/Utils.h"

using namespace std;


int main(int argc, char *argv[]) {
    const tuple<int, int, int> t1(10, 20, 30);
    print_tuple(t1);

    const tuple<int, int, int> t2 = {10, 20, 30};
    print_tuple(t2);

    constexpr tuple<int, int, int> t3 = make_tuple(10, 20, 30);
    print_tuple(t3);
}
