//
// Created by lixia on 2025/9/4.
//

#include <string>
#include <vector>
#include <fstream>

#include "../include/Utils.h"
using namespace std;


int main(int argc, char *argv[]) {
    ifstream fin("./test_8_5.txt");
    if (!fin) {
        cerr << "cannot open file test_8_5.txt" << endl;
        return -1;
    }

    vector<string> contents;
    string word;
    while (fin >> word) {
        contents.push_back(word);
    }
    fin.close();

    print_collection(contents);
}
