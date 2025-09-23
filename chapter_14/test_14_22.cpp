//
// Created by lixia on 2025/9/23.
//
#include <iostream>
#include "../include/Sales_data.h"

using namespace std;


int main(int argc, char *argv[]) {
    Sales_data sd("ISBN-911", 10, 13.2);

    sd = "ISBN-912";
    cout << sd << endl; // ISBN-912 10 132 13.2
}
