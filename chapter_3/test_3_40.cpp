//
// Created by lixia on 2025/8/22.
//
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;


int main(int argc, char *argv[]) {
    char ca1[] = "first";
    const char ca2[] = "second";
    char result[] = "";

    strcat(ca1, ca2);
    strcpy(result, ca1);

    /*
    // 这样为什么不行呢？？？
    strcat(result, ca1);
    strcat(result, ca2);
    */

    cout << result << endl;
}
