//
// Created by lixia on 2025/8/28.
//

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char *argv[]) {
    string s;

    for (int i = 1; i < argc; ++i) {
        s += argv[i];
        s += " ";
    }

    cout << s << endl;
}
