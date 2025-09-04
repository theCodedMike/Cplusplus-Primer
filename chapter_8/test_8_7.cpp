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
 * 1 编译    g++ ./chapter_8/test_8_7.cpp
 * 2 执行    ./a.exe ./chapter_8/test_8_6.txt ./chapter_8/test_8_7_out.txt
 */

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2], ofstream::out | ofstream::app);
    if (!fin.is_open()) {
        cerr << "fin is not open" << endl;
        return -1;
    }
    if (!fout.is_open()) {
        cerr << "fout is not open" << endl;
        return -2;
    }

    Sales_data total;
    if (read(fin, total)) {
        Sales_data trans;
        while (read(fin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(fout, total) << endl;
                total = trans;
            }
        }

        print(fout, total) << endl;
    } else
        cerr << "No data?!" << endl;

    fin.close();
    fout.close();
}
