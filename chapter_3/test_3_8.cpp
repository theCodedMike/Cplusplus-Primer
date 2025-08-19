//
// Created by lixia on 2025/8/19.
//

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

void while_style();
void for_style();

int main(int argc, char *argv[]) {
    while_style();
    //for_style();
}

void while_style() {
    string s = "What";
    cout << "Before replace: " << s << endl; // What

    auto idx = 0;
    while (idx < s.size()) {
        s[idx] = 'X';
        idx++;
    }

    cout << " After replace: " << s << endl; // XXXX
}

void for_style() {
    string s = "What";
    cout << "Before replace: " << s << endl; // What

    for (decltype(s.size()) idx = 0; idx < s.size(); idx++)
        s[idx] = 'X';

    cout << " After replace: " << s << endl; // XXXX
}
