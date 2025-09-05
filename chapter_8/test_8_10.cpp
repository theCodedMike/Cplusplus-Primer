//
// Created by lixia on 2025/9/5.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin("./test_8_10.txt");
    if (!fin.is_open()) {
        cerr << "fin cannot open..." << endl;
        return -1;
    }

    vector<string> contents;
    string line;
    while (getline(fin, line)) {
        contents.push_back(line);
    }

    string word;
    istringstream sin;
    for (auto content: contents) {
        sin.str(content);
        while (sin >> word)
            cout << word << " ";

        sin.clear();
        cout << endl;
    }
}
