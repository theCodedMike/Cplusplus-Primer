//
// Created by lixia on 2025/8/25.
//

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    string s1, s2, resp;

    do {
        cout << "Enter two strings: ";
        cin >> s1 >> s2;

        cout << "The shorter string is " << (s1.size() <= s2.size() ? s1 : s2) << endl;
        cout << "More? yes or no: ";
        cin >> resp;
    } while (!resp.empty() &&  resp[0] != 'n');
}