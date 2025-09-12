//
// Created by lixia on 2025/9/12.
//

#include <vector>
#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
    vector<pair<string, int>> data;
    string name;
    int age;

    while (true) {
        cout << "Enter name and age: ";
        cin >> name;
        if (name == "quit")
            break;
        cin >> age;

        data.emplace_back(name, age);
        //data.push_back({name, age});
        //data.push_back(make_pair(name, age));
        //data.push_back(pair(name, age));
    }

    for (const auto &[fst, snd]: data) {
        cout << fst << " " << snd << endl;
    }
}
