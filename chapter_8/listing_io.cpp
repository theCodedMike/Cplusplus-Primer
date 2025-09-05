//
// Created by lixia on 2025/9/4.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "./../include/PersonInfo.h"
using namespace std;


int main(int argc, char *argv[]) {
    cout << "hi!" << endl;  // 输出hi和一个换行，然后刷新缓冲区
    cout << "hi!" << flush; // 输出hi，然后刷新缓冲区
    cout << "hi!" << ends;  // 输出hi和一个空字符，然后刷新缓冲区

    cout << unitbuf; // 所有输出都立即刷新，无缓冲
    cout << nounitbuf; // 回到正常缓冲模式


    // 使用istringstream

}

void tie() {
    cin.tie(&cout); // 标准库将cin和cout关联在一起
    ostream * old_tie = cin.tie(nullptr); // cin不再与其他流关联
    cin.tie(old_tie); // 重建cin和cout的正常关联
}

bool valid(const string &num) {
    return true;
}

string format(const string &num) {
    return num;
}
void use_sstream() {
    ifstream fin("./person_info.txt");
    string line, word;
    vector<PersonInfo> people;

    while (getline(fin, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);

        people.push_back(info);
    }

    for (const auto & entry: people) {
        ostringstream formatted, badNums;
        for (const auto & nums: entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else
                formatted << " " << format(nums);
        }

        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name << " invalid number(s)" << badNums.str() << endl;
    }
}