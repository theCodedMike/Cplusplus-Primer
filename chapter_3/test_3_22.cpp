//
// Created by lixia on 2025/8/20.
//

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::islower;
using std::toupper;

int main(int argc, char *argv[]) {
    vector<string> manySen;
    string line;

    while (std::getline(cin, line)) {
        if ("quit" == line)
            break;
        manySen.push_back(line);
    }

    for (auto outer = manySen.begin(); outer != manySen.end(); ++outer) {
        for (auto inner = outer->begin(); inner != outer->end(); ++inner) {
            if (islower(*inner))
                *inner = toupper(*inner);
        }
    }

    for (auto iter = manySen.cbegin(); iter != manySen.cend(); ++iter)
        cout << *iter << endl;
}
