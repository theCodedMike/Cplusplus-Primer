//
// Created by lixia on 2025/8/25.
//

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    string input;
    getline(cin, input);

    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    for (size_t i = 0, size = input.size(); i < size - 1; ++i) {
        if (input[i] == 'f') {
            if (input[i + 1] == 'f')
                ++ffCnt;
            else if (input[i + 1] == 'l')
                ++flCnt;
            else if (input[i + 1] == 'i')
                ++fiCnt;
        }
    }
    cout << "ff: " << ffCnt << endl
         << "fl: " << flCnt << endl
         << "fi: " << fiCnt << endl;
}
