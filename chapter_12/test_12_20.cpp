//
// Created by lixia on 2025/9/15.
//

#include <iostream>
#include <vector>
#include <fstream>

#include "../include/StrBlob.h"

using namespace std;

int main(int argc, char *argv[]) {
    const string file_path = "./test_12_20.txt";
    ifstream fin(file_path);
    if (!fin.is_open())
        throw runtime_error("cannot open file" + file_path);

    string line;
    StrBlob sb;
    while (getline(fin, line)) {
        if (line.empty())
            continue;
        sb.push_back(line);
    }

    auto sbp = sb.begin();
    for (auto i = 0; i < sb.size(); ++i) {
        cout << sbp.deref() << endl;
        sbp.incr();
    }

    // cout << sbp.deref() << endl; // throwing an instance of 'std::out_of_range'
}
