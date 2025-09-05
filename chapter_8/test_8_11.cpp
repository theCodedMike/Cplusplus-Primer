//
// Created by lixia on 2025/9/5.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "./../include/PersonInfo.h"

using namespace std;


int main(int argc, char *argv[]) {
    ifstream fin("./person_info.txt");
    if (!fin) {
        cerr << "fin not open..." << endl;
        return -1;
    }

    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(fin, line)) {
        PersonInfo info;
        record.str(line);

        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);

        record.clear();
        people.push_back(info);
    }

    for (auto &info: people) {
        cout << info << endl;
    }
}
