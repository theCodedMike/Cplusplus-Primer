//
// Created by lixia on 2025/9/12.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
    map<string, int> info = {
        {"Zhang San", 25},
        {"Li Si", 30},
        {"Wang Wu", 35},
        {"Zhao Liu", 40}
    };

    auto iter = info.begin();
    while (iter != info.end()) {
        if (iter->first == "Zhang San")
            iter->second = 18;

        ++iter;
    }

    for (const auto & [name, age]: info) {
        cout << name << ": " << age << endl;
    }
}
