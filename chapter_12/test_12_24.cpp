//
// Created by lixia on 2025/9/16.
//

#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    const size_t sz = 10;
    const auto ca = new char[sz];
    string s;

    getline(cin, s);

    auto i = 0;
    bool reach_end = false;
    while (i < sz && s[i] != '\0') {
        ca[i] = s[i];
        ++i;
        if (i == sz)
            reach_end = true;
    }
    if (reach_end)
        --i;
    ca[i] = '\0';

    cout << ca << endl;

    delete [] ca;
}

