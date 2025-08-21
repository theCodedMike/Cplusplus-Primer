//
// Created by lixia on 2025/8/21.
//
#include <string>

#include "../include/Utils.h"
using std::string;

string sa[10];
int ia[10];

int main(int argc, char *argv[]) {
    string sa2[10];
    int ia2[10];

    print_collection(sa); // [, , , , , , , , , ]
    print_collection(sa2);// [, , , , , , , , , ]
    print_collection(ia); // [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    print_collection(ia2);// [0, 0, 0, 0, 2007435088, 420, 256, 0, 2007435104, 420] 无规律
}
