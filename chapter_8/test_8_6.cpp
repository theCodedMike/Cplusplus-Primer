//
// Created by lixia on 2025/9/4.
//
#include <string>
#include <iostream>
#include <fstream>
#include "../include/Sales_data.h"

using namespace std;

/*
 * 以下在终端执行：
 * 1 编译    g++ ./chapter_8/test_8_6.cpp
 * 2 执行    ./a.exe ./chapter_8/test_8_6.txt
 */

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    if (!fin.is_open()) {
        cerr << "fin is not open" << endl;
        return -1;
    }

    Sales_data total;
    if (read(fin, total)) {
        Sales_data trans;
        while (read(fin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }

        print(cout, total) << endl;
    } else
        cerr << "No data?!" << endl;

    fin.close();
}
