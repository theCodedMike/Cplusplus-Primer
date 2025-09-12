//
// Created by lixia on 2025/9/12.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "../include/Utils.h"

using namespace std;


int main(int argc, char *argv[]) {
    map<string, vector<string>> family;
    string family_name;
    string first_name;

    do {
        cout << "Enter your family name('quit' to quit): ";
        cin >> family_name;

        if (family_name != "quit") {
            cout << "Enter your children's first name('done' to quit):" << endl;

            while (cin >> first_name) {
                if (first_name == "done") {
                    if (family[family_name].empty())
                        family[family_name] = {};
                    break;
                }
                family[family_name].push_back(first_name);
            }
        }
    } while (family_name != "quit");

    for (auto &[fst, snd]: family) {
        cout << fst << ": "; print_collection(snd);
    }
}
